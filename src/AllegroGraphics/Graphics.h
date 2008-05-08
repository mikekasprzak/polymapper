// - ------------------------------------------------------------------------------------------ - //
#ifndef __AllegroGraphics_Graphics_H__
#define __AllegroGraphics_Graphics_H__
// - ------------------------------------------------------------------------------------------ - //
#include "MatrixDraw.h"
// - ------------------------------------------------------------------------------------------ - //
//#include <Math/Vector.h>
//#include <Math/Matrix.h>
//#include <Geometry/Rect.h>
// - ------------------------------------------------------------------------------------------ - //
extern int ScreenWidth;
extern int ScreenHeight;

extern BITMAP* Buffer;

extern Matrix3x3 ViewMatrix;
// - ------------------------------------------------------------------------------------------ - //
inline void gfxInit( const int _Width, const int _Height, const bool FullScreen = false ) {
	// Install Common Allegro Features //
	allegro_init();
	install_keyboard();
	install_mouse();
	
	// Store the requested screen dimensions //
	ScreenWidth = _Width;
	ScreenHeight = _Height;
	
	// Set the color depth to something efficent //
	set_color_depth( 16 );
	
	// Windowed or fullscreen //
	if ( FullScreen )
		set_gfx_mode( GFX_AUTODETECT_FULLSCREEN, ScreenWidth, ScreenHeight, 0, 0 );
	else
		set_gfx_mode( GFX_AUTODETECT_WINDOWED, ScreenWidth, ScreenHeight, 0, 0 );
	
	// Create our drawing buffer //
	Buffer = create_bitmap( ScreenWidth, ScreenHeight );	
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxExit( ) {
	// Kill our drawing buffer //
	destroy_bitmap( Buffer );

	// Uninstall all allegro function //
	allegro_exit();
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxClearBuffer( ) {
	// Clear the buffer to blackness //
	clear_to_color( Buffer, makecol(0,0,0) );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxSwapBuffer( ) {
	// Sync and copy the buffer to the screen //
	vsync();
	rest(0);
	blit( Buffer, screen, 0, 0, 0, 0, Buffer->w, Buffer->h );
}
// - ------------------------------------------------------------------------------------------ - //


// - ------------------------------------------------------------------------------------------ - //
#endif // __AllegroGraphics_Graphics_H__ //
// - ------------------------------------------------------------------------------------------ - //
