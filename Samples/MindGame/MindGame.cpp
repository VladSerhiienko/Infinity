#include <fwk/fwk.h>
#include <time.h>

void drawFrame(float x0, float y0, float x1, float y1, uint32_t color)
{
    GLuint baseVertex;
    vf::p2cu4_vertex_t* v = gfx::frameAllocVertices<vf::p2cu4_vertex_t>(10, &baseVertex);

    vf::set(v++, x0,      y0,      color);
    vf::set(v++, x0+1.0f, y0+1.0f, color);
    vf::set(v++, x1,      y0,      color);
    vf::set(v++, x1-1.0f, y0+1.0f, color);
    vf::set(v++, x1,      y1,      color);
    vf::set(v++, x1-1.0f, y1-1.0f, color);
    vf::set(v++, x0,      y1,      color);
    vf::set(v++, x0+1.0f, y1-1.0f, color);
    vf::set(v++, x0,      y0,      color);
    vf::set(v++, x0+1.0f, y0+1.0f, color);

    glDrawArrays(GL_TRIANGLE_STRIP, baseVertex, 10);
}

enum ArrowDir
{
    AD_UP,
    AD_DOWN,
    AD_RIGHT,
    AD_LEFT,
    AD_COUNT
};

enum GameState
{
    GS_GAME_IN_PROGRESS,
    GS_GAME_COMPLETED
};

void drawArrowTri(float x0, float y0, float R, int dir, uint32_t color)
{
    float dx0, dy0;
    float dx1, dy1;
    float dx2, dy2;

    switch (dir)
    {
    case AD_DOWN:
        dx0 =  0.0f,   dy0 =  1.0f-0.25f;
        dx1 = -0.866f, dy1 = -0.5f-0.25f;
        dx2 =  0.866f, dy2 = -0.5f-0.25f;
        break;
    case AD_UP:
        dx0 =  0.0f,   dy0 = -1.0f+0.25f;
        dx1 =  0.866f, dy1 =  0.5f+0.25f;
        dx2 = -0.866f, dy2 =  0.5f+0.25f;
        break;
    case AD_RIGHT:
        dx0 =  1.0f-0.25f, dy0 =  0.0f;
        dx1 = -0.5f-0.25f, dy1 =  0.866f;
        dx2 = -0.5f-0.25f, dy2 = -0.866f;
        break;
    case AD_LEFT:
        dx0 = -1.0f+0.25f, dy0 =  0.0f;
        dx1 =  0.5f+0.25f, dy1 = -0.866f;
        dx2 =  0.5f+0.25f, dy2 =  0.866f;
        break;
    default:
        assert(0);
    }

    GLuint baseVertex;
    vf::p2cu4_vertex_t* v = gfx::frameAllocVertices<vf::p2cu4_vertex_t>(8, &baseVertex);

    float R0 = R;
    float R1 = R - 2.0f;

    vf::set(v++, x0+dx0*R0, y0+dy0*R0, color);
    vf::set(v++, x0+dx0*R1, y0+dy0*R1, color);
    vf::set(v++, x0+dx1*R0, y0+dy1*R0, color);
    vf::set(v++, x0+dx1*R1, y0+dy1*R1, color);
    vf::set(v++, x0+dx2*R0, y0+dy2*R0, color);
    vf::set(v++, x0+dx2*R1, y0+dy2*R1, color);
    vf::set(v++, x0+dx0*R0, y0+dy0*R0, color);
    vf::set(v++, x0+dx0*R1, y0+dy0*R1, color);

    glDrawArrays(GL_TRIANGLE_STRIP, baseVertex, 8);
}

namespace app
{
    static const int ALLOCATED_ELEMENTS = 32;

    int state;
    int maxElements;
    int guessed;
    int seq[ALLOCATED_ELEMENTS];

    void startGame();
    void gameComplete();

    void init()
    {
        startGame();
    }

    void fini()
    {
    }

    void startGame()
    {
        srand((unsigned int)timerAbsoluteTime());

        state   = GS_GAME_IN_PROGRESS;
        guessed = 0;

        maxElements = 8;

        assert(maxElements<=ALLOCATED_ELEMENTS);

        for (int i=0; i < maxElements; ++i)
        {
            seq[i] = rand() % AD_COUNT;
            assert(seq[i]>=0 && seq[i]<maxElements);
        }
    }

    void gameComplete()
    {
        state = GS_GAME_COMPLETED;
    }

    void update(float dt)
    {
        if (state == GS_GAME_IN_PROGRESS)
        {
            assert(guessed<maxElements && guessed>=0);

            if (ui::keyWasPressed(SDL_SCANCODE_UP))
            {
                if (seq[guessed] == AD_UP)
                {
                    ++guessed;
                }
                else
                {
                    guessed = 0;
                }
            }

            if (ui::keyWasPressed(SDL_SCANCODE_DOWN))
            {
                if (seq[guessed] == AD_DOWN)
                {
                    ++guessed;
                }
                else
                {
                    guessed = 0;
                }
            }

            if (ui::keyWasPressed(SDL_SCANCODE_RIGHT))
            {
                if (seq[guessed] == AD_RIGHT)
                {
                    ++guessed;
                }
                else
                {
                    guessed = 0;
                }
            }

            if (ui::keyWasPressed(SDL_SCANCODE_LEFT))
            {
                if (seq[guessed] == AD_LEFT)
                {
                    ++guessed;
                }
                else
                {
                    guessed = 0;
                }
            }

            if (guessed==maxElements)
            {
                gameComplete();
            }
        }
        else if (state == GS_GAME_COMPLETED)
        {
            assert(guessed==maxElements);
            if (ui::keyWasReleased(SDL_SCANCODE_SPACE))
            {
                startGame();
            }
        }

        assert(guessed<=maxElements);
    }

    void render()
    {
        float size    = 30.0f;
        float padding = 2.0f;
        float margin  = 2.0f;

        float bx = 100.0f;
        float by = 100.0f;

        float x;

        gfx::set2DStates();
        gfx::setUIMatrices();

        gfx::setStdProgram(gfx::STD_FEATURE_COLOR);
        gfx::setMVP();

        glBindVertexArray(vf::p2cu4_vertex_t::vao);
        glBindVertexBuffer(0, gfx::dynBuffer, 0, sizeof(vf::p2cu4_vertex_t));

        x= bx;
        for (int i=0; i < maxElements; ++i)
        {
            drawFrame(x, by, x+size, by+size, 0xFF0000FF);
            x += size+margin*2.0f;
        }

        assert(guessed<=maxElements);

        x= bx;
        for (int i=0; i < guessed; ++i)
        {
            assert(seq[i]<AD_COUNT);
            drawArrowTri(x+0.5f*size, by+0.5f*size, 0.5f*size-padding, seq[i], 0xFF00FF00);
            x += size+margin*2.0f;
        }

        if (state == GS_GAME_COMPLETED)
        {
            drawFrame(bx-padding, by-padding, bx+size*maxElements+margin*2*(maxElements-1)+padding, by+size+padding, 0xFF00FF00);
        }
    }

    void recompilePrograms() {}

    void resize(int, int) {}
}
