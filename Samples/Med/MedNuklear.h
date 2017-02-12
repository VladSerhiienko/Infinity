#pragma once

// nuklear config goes here

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT

// nuklear

#include <nuklear.h>

//
// wrappers
//

NK_API struct nk_context* nk_fwk_init(SDL_Window* win);
NK_API void nk_fwk_font_stash_begin(struct nk_font_atlas** atlas);
NK_API void nk_fwk_font_stash_end(void);
NK_API int nk_fwk_handle_event(SDL_Event* evt);
NK_API void nk_fwk_render(enum nk_anti_aliasing);
NK_API void nk_fwk_shutdown(void);
NK_API void nk_fwk_device_destroy(void);
NK_API void nk_fwk_device_create(void);

enum nk_theme { NK_THEME_BLACK,
    NK_THEME_WHITE,
    NK_THEME_RED,
    NK_THEME_BLUE,
    NK_THEME_DARK };

NK_API void nk_fwk_set_style(struct nk_context* ctx, enum nk_theme theme);