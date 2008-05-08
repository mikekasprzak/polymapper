// - ------------------------------------------------------------------------------------------ - //
#ifndef __AllegroGraphics_Graphics_H__
#define __AllegroGraphics_Graphics_H__
// - ------------------------------------------------------------------------------------------ - //
#include <Allegro.h>
// - ------------------------------------------------------------------------------------------ - //
#include <Math/Matrix.h>
// - ------------------------------------------------------------------------------------------ - //
extern int ScreenWidth;
extern int ScreenHeight;

extern BITMAP* Buffer;

extern Matrix3x3 Matrix;
// - ------------------------------------------------------------------------------------------ - //
typedef int ColorType;

#define RGB(_r, _g, _b) makecol(_r,_g,_b)
#define RGBA(_r, _g, _b, _a) makecol(_r,_g,_b)

#define RGB_BLACK   makecol(0,0,0)
#define RGB_WHITE   makecol(255,255,255)

#define RGB_RED     makecol(255,0,0)
#define RGB_GREEN   makecol(0,255,0)
#define RGB_BLUE    makecol(0,0,255)

#define RGB_MAGENTA makecol(255,0,255)
#define RGB_YELLOW  makecol(255,255,0)
#define RGB_CYAN    makecol(0,255,255)

#define RGB_ORANGE  makecol(255,127,0)
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
	
	// Initalize Matrix //
	Matrix(0,0) = 1;
	Matrix(1,1) = 1;
	Matrix(2,2) = 1;
	
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
inline void gfxClearBuffer( const ColorType Color = RGB_BLACK ) {
	// Clear the buffer to blackness //
	clear_to_color( Buffer, Color );
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
