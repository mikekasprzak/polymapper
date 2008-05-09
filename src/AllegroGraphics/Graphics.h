// - ------------------------------------------------------------------------------------------ - //
#ifndef __AllegroGraphics_Graphics_H__
#define __AllegroGraphics_Graphics_H__
// - ------------------------------------------------------------------------------------------ - //
#include <Allegro.h>
#include <vector>
// - ------------------------------------------------------------------------------------------ - //
#include <Math/Matrix.h>
// - ------------------------------------------------------------------------------------------ - //
typedef int ColorType;

#define RGB(_r,_g,_b)		makecol(_r,_g,_b)
#define RGBA(_r,_g,_b,_a)	makecol(_r,_g,_b)

#define RGB_BLACK	makecol(0,0,0)
#define RGB_GREY	makecol(127,127,127)
#define RGB_WHITE	makecol(255,255,255)

#define RGB_RED		makecol(255,0,0)
#define RGB_GREEN	makecol(0,255,0)
#define RGB_BLUE	makecol(0,0,255)

#define RGB_MAGENTA	makecol(255,0,255)
#define RGB_YELLOW	makecol(255,255,0)
#define RGB_CYAN	makecol(0,255,255)

#define RGB_ORANGE	makecol(255,127,0)
#define RGB_PINK	makecol(255,0,127)
#define RGB_PURPLE	makecol(127,0,255)
#define RGB_PUKE	makecol(127,255,0)
#define RGB_MINT	makecol(0,255,127)
#define RGB_SKY		makecol(0,127,255)
// - ------------------------------------------------------------------------------------------ - //
extern int ScreenWidth;
extern int ScreenHeight;

extern BITMAP* Buffer;

extern Matrix3x3 Matrix;

extern std::vector<Matrix3x3>* MatrixStack;

extern ColorType CurrentColor;
extern ColorType CurrentNormalColor;
extern Real CurrentNormalLength;
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
	
	// Set the initial current color defaulting to white //
	// (Note, makecol only works after set_gfx_mode) //
	CurrentColor = RGB_WHITE;
	CurrentNormalColor = RGB_WHITE;
	
	CurrentNormalLength = 8;
	
	// Initalize Matrix //
	Matrix(0,0) = 1;
	Matrix(1,1) = 1;
	Matrix(2,2) = 1;
	
//	Matrix(0,2) = ScreenWidth >> 1;
//	Matrix(1,2) = ScreenHeight >> 1;

	// Initalize Matrix Stack //
	MatrixStack = new std::vector<Matrix3x3>();
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxExit( ) {
	// Kill the matrix stack //
	delete MatrixStack;
	
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
inline void gfxSetColor( const ColorType Color ) {
	CurrentColor = Color;
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxSetColor( const int r, const int g, const int b, const int a = 255 ) {
	CurrentColor = RGBA(r,g,b,a);
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxSetNormalColor( const ColorType Color ) {
	CurrentNormalColor = Color;
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxSetNormalColor( const int r, const int g, const int b, const int a = 255 ) {
	CurrentNormalColor = RGBA(r,g,b,a);
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxSetNormalLength( const Real NormalLength ) {
	CurrentNormalLength = NormalLength;
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxPushMatrix() {
	MatrixStack->push_back( Matrix );	
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxPeepMatrix() {
	Matrix = MatrixStack->back();	
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxPopMatrix() {
	// TODO: Log an error if too many pops //
	
	gfxPeepMatrix();
	MatrixStack->pop_back();	
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxTranslate( const Vector2D& v ) {
	Matrix *= Matrix3x3::Translating( v );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxTranslate( const Real _x, const Real _y, const Real _z = Real::Zero ) {
	Matrix *= Matrix3x3::Translating( Vector2D( _x, _y ) );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxScale( const Real Scalar ) {
	Matrix *= Matrix3x3::Scaling( Scalar );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
#endif // __AllegroGraphics_Graphics_H__ //
// - ------------------------------------------------------------------------------------------ - //
