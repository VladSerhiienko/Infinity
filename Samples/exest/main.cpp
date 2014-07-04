#define _CRT_SECURE_NO_WARNINGS

#include <framework.h>
#include <glm\glmext.h>
#include <ResourceHelpers.h>
#include <SOIL.h>
#include <SpectatorCamera.h>
#include <CameraDirector.h>
#include <utils.h>

#include "CDLODTerrain.h"

class Exest: public ui::Stage
{
private:
    SpectatorCamera camera;

    v128 mProj[4];

    bool      fixedMode;
    ml::vec3  VPpp;
    v128      VP[4];

    CDLODTerrain terrain;

    CameraDirector camDirector;

    bool drawWireframe;

public:
    Exest(): fixedMode(false), loc(0)
    {
        terrain.initialize();

        glm::mat4 proj = glm::perspectiveGTX(30.0f, mWidth/mHeight, 0.1f, 10000.0f);

        mProj[0] = vi_loadu_v4(proj[0]);
        mProj[1] = vi_loadu_v4(proj[1]);
        mProj[2] = vi_loadu_v4(proj[2]);
        mProj[3] = vi_loadu_v4(proj[3]);

        camera.acceleration.x = camera.acceleration.y = camera.acceleration.z = 150;
        camera.maxVelocity.x = camera.maxVelocity.y = camera.maxVelocity.z = 60;

        PHYSFS_File*    src = PHYSFS_openRead("hm.raw");
        //explicit conversion to avoid warning on 32-bit system
        //assert(src.size()<SIZE_MAX);
        ///size_t fileSize = (size_t)src.size();

        //src.read(data, fileSize, 1);

        //int	imgWidth, imgHeight, imgChannels;
        //unsigned char*	pixelsPtr = SOIL_load_image_from_memory(data, fileSize,
        //	&imgWidth, &imgHeight, &imgChannels, SOIL_LOAD_L);
        //assert(imgChannels==1);

        //uint32_t blockCount, vertCount;
        //src.seek(4+4+4);
        //src.read(&blockCount, sizeof(blockCount), 1);
        //vertCount = blockCount*16+1;
        uint32_t w = 3073;
        uint32_t h = 4097;

        uint16_t* data = new uint16_t[w*h];
        
        PHYSFS_read(src, data, w*h*sizeof(uint16_t), 1);
        PHYSFS_close(src);

        terrain.setHeightmap(data, w, h);
        
        drawWireframe = false;
        
        //SOIL_free_image_data(pixelsPtr);
        delete [] data;

        addPrograms(1, &terrain.prgTerrain);
    }

    ~Exest()
    {
        terrain.cleanup();
    }

    void drawFrustum(v128 frustum[4])
    {
        glm::mat4 inverted = glm::inverseGTX(*(glm::mat4*)frustum);

        static const glm::vec4 points[8] = {
            glm::vec4(-1, -1, -1, 1), 
            glm::vec4( 1, -1, -1, 1), 
            glm::vec4( 1,  1, -1, 1), 
            glm::vec4(-1,  1, -1, 1), 
            glm::vec4(-1, -1,  1, 1), 
            glm::vec4( 1, -1,  1, 1), 
            glm::vec4( 1,  1,  1, 1), 
            glm::vec4(-1,  1,  1, 1), 
        };

        static const int indices[30] = 
        {
            0, 1, 3, 1, 2, 3,
            1, 0, 4, 1, 4, 5,
            3, 2, 7, 2, 6, 7,
            4, 0, 7, 0, 3, 7,
            1, 5, 2, 2, 5, 6,
        };

        glm::vec4 wpoints[8];

        for (size_t i=0; i<8; ++i)
            wpoints[i] = inverted*points[i];

        glUseProgram(0);
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        glBegin(GL_LINES);
        glVertex4fv(wpoints[0]); glVertex4fv(wpoints[1]);
        glVertex4fv(wpoints[1]); glVertex4fv(wpoints[2]);
        glVertex4fv(wpoints[2]); glVertex4fv(wpoints[3]);
        glVertex4fv(wpoints[3]); glVertex4fv(wpoints[0]);

        glVertex4fv(wpoints[4]); glVertex4fv(wpoints[5]);
        glVertex4fv(wpoints[5]); glVertex4fv(wpoints[6]);
        glVertex4fv(wpoints[6]); glVertex4fv(wpoints[7]);
        glVertex4fv(wpoints[7]); glVertex4fv(wpoints[4]);

        glVertex4fv(wpoints[0]); glVertex4fv(wpoints[4]);
        glVertex4fv(wpoints[1]); glVertex4fv(wpoints[5]);
        glVertex4fv(wpoints[2]); glVertex4fv(wpoints[6]);
        glVertex4fv(wpoints[3]); glVertex4fv(wpoints[7]);
        glEnd();

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBlendEquation(GL_FUNC_ADD);
        glEnable(GL_CULL_FACE);
        glDisable(GL_TEXTURE_2D);

        //Simple sorting for convex alpha object rendering
        //First render back faces
        //Then render front faces
        glColor4f(1.0f, 0.5f, 0.0f, 0.8f);
        glCullFace(GL_FRONT);
        glBegin(GL_TRIANGLES);
        for (int i=0; i<30; ++i)
        {
            glVertex4fv(wpoints[indices[i]]);
        }
        glEnd();

        glCullFace(GL_BACK);
        glBegin(GL_TRIANGLES);
        for (int i=0; i<30; ++i)
        {
            glVertex4fv(wpoints[indices[i]]);
        }
        glEnd();

        glDisable(GL_BLEND);
        glDisable(GL_CULL_FACE);
    }

protected:
    void onShaderRecompile()
    {
        terrain.reset();
    }

    std::vector<glm::__quatGTX> savedCamOrient;
    std::vector<glm::vec3>      savedCamPos;
    int                         loc;

    void onPaint()
    {
        glClearDepth(1.0);

        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadMatrixf((float*)mProj);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();

        v128 vm[4];
        camera.getViewMatrix(vm);
        glLoadMatrixf((float*)vm);

        v128 MVP[4];
        ml::mul_mat4(MVP, mProj, vm);
        memcpy(&graphics::autoVars.matMVP, MVP, sizeof(v128)*4);

        glDisable(GL_CULL_FACE);

        glUseProgram(0);
        glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);
        glVertex3f(-3, -1, -10);
        glColor3f(0, 1, 0);
        glVertex3f( 3, -1, -10);
        glColor3f(0, 0, 1);
        glVertex3f( 0, 4, -10);
        glEnd();

        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        if (drawWireframe)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glEnable(GL_DEPTH_TEST);

        if (!fixedMode)
        {
            vi_store_v3(&terrain.viewPoint, camera.getPosition());
            terrain.setSelectMatrix(MVP);
        }
        else
        {
            terrain.viewPoint = VPpp;
            terrain.setSelectMatrix(VP);
        }

        terrain.drawTerrain();

        if (drawWireframe)
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        if (fixedMode)
        {
            drawFrustum(MVP);
        }

        glDisable(GL_CULL_FACE);

        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        glPopMatrix();

        glDisable(GL_BLEND);

        //Draw ui
        ui::displayStats(10.0f, 10.0f, 300.0f, 120.0f, terrain.getCPUTime(), terrain.getGPUTime());

        char str[256];
        
        _snprintf(str, 256, "CPU select time - %f ms", terrain.getCPUSelectTime());
        vg::drawString(ui::defaultFont, 25.0f, 83.0f, str, strlen(str));
        
        _snprintf(str, 256, "CPU draw time - %f ms", terrain.getCPUDrawTime());
        vg::drawString(ui::defaultFont, 25.0f, 101.0f, str, strlen(str));
        
        int patches = terrain.patchCount;
        int vtx = patches*terrain.patchDim*terrain.patchDim;
        _snprintf(str, 256, "Patches: %d, Vtx: %d", patches, vtx);
        vg::drawString(ui::defaultFont, 25.0f, 119.0f, str, strlen(str));

        CHECK_GL_ERROR();
    }

    void onUpdate(float dt)
    {
        ui::processCameraInput(&camera, dt);
        ui::processCameraDirectorInput(&camDirector, &camera);

        if (ui::keyWasReleased(SDLK_BACKSLASH))
        {
            terrain.maxPatchCount = (terrain.maxPatchCount)?0:CDLODTerrain::MAX_PATCH_COUNT;
        }

        if (ui::keyWasReleased(SDLK_LEFTBRACKET))
        {
            terrain.maxPatchCount -= (terrain.maxPatchCount>0)?1:0;
        }

        if (ui::keyWasReleased(SDLK_RIGHTBRACKET))
        {
            terrain.maxPatchCount += (terrain.maxPatchCount<CDLODTerrain::MAX_PATCH_COUNT)?1:0;
        }

        if (ui::keyWasReleased(SDL_SCANCODE_L))
        {
            fixedMode = !fixedMode;
            if (fixedMode)
            {
                v128 vm[4];
                camera.getViewMatrix(vm);
                ml::mul_mat4(VP, mProj, vm);
                vi_store_v3(&VPpp, camera.getPosition());
            }
        }

        if (ui::keyWasReleased(SDL_SCANCODE_F))
        {
            drawWireframe = !drawWireframe;
        }
    }
};

int main(int argc, char** argv)
{
    fwk::init(argv[0]);

    {
        Exest app;
        app.run();
    }

    fwk::fini();

    return 0;
}