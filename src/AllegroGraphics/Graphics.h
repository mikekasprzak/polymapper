// - ------------------------------------------------------------------------------------------ - //
#ifndef __AllegroGraphics_Graphics_H__
#define __AllegroGraphics_Graphics_H__
// - ------------------------------------------------------------------------------------------ - //
#include <Allegro.h>
#include <vector>
// - ------------------------------------------------------------------------------------------ - //
#include <Math/Matrix.h>
#include <Geometry/Rect.h>
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
extern BITMAP* Buffer;

extern Matrix3x3 Matrix;
extern std::vector<Matrix3x3>* MatrixStack;
// - ------------------------------------------------------------------------------------------ - //
namespace Screen {
	extern int Width;
	extern int Height;
	extern int Scalar;
	
	extern Vector2D Shape;
	extern Vector2D HalfShape;

//	extern ColorType Color;
//	extern ColorType NormalColor;
//	extern Real NormalLength;
	
	extern volatile bool CloseButtonPressed;
	void CloseButtonHandler();
};
// - ------------------------------------------------------------------------------------------ - //
class cMouse {
public:
	Vector2D Pos;
	Vector2D Old;
	
	int Wheel;
	int WheelOld;
	
public:
	cMouse() :
		Wheel(mouse_z),
		WheelOld(mouse_z)
	{
	}
	
	inline void Update() {
		Old = Pos;
		Pos = Vector2D(mouse_x, mouse_y) / (Screen::Scalar);
		Pos -= Screen::HalfShape;
			
		WheelOld = Wheel;
		Wheel = mouse_z;
	}
	
	inline const Vector2D Diff() const {
		return Old - Pos;
	}
	
	inline const int WheelDiff() const {
		return WheelOld - Wheel;
	}
};
// - ------------------------------------------------------------------------------------------ - //
extern cMouse Mouse;
// - ------------------------------------------------------------------------------------------ - //
class cCamera {
public:
	Vector2D Pos;
	Real Scale;

	Vector2D ViewShape;
	Vector2D ViewHalfShape;
	
	Vector2D Mouse;
	
	// TODO: Something to do with clipping //
public:
	cCamera( const Vector2D& _Pos = Vector2D::Zero, const Real& _Scale = Real::One ) :
		Pos( _Pos ),
		Scale( _Scale ),
		ViewShape( Screen::Shape * Scale ),
		ViewHalfShape( ViewShape * Real::Half )
	{
	}
	
public:
	inline void Update() {
		Mouse.x = (::Mouse.Pos.x * ViewShape.x) / Screen::Shape.x;
		Mouse.y = (::Mouse.Pos.y * ViewShape.y) / Screen::Shape.y;
		Mouse -= Pos;
	}

	inline const Matrix3x3 GetMatrix() const {
		Matrix3x3 Matrix = Matrix3x3::Scaling( Real::One / Scale );
		Matrix *= Matrix3x3::Translating( Pos );
		Matrix *= Matrix3x3::Translating( Screen::HalfShape * Scale );
		return Matrix;
	}	
};
// - ------------------------------------------------------------------------------------------ - //
extern cCamera Camera;
extern cCamera* CurrentCamera;
// - ------------------------------------------------------------------------------------------ - //
extern ColorType CurrentColor;
extern ColorType CurrentNormalColor;
extern Real CurrentNormalLength;
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxSetCameraMatrix( const cCamera& _Camera = *CurrentCamera ) {
	Matrix = _Camera.GetMatrix();
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxSetScreenMatrix( ) {
	Matrix = Matrix3x3::Translating( Screen::HalfShape );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxSetScreenAspectMatrix( ) {
	// This is a function for setting an aspect ratio constrained Matrix. //
	//   All screen co-ordinates fall in to at least a -1 to +1 range. //
	// TODO: Make it do what the above suggests.  //
	//   Perhaps horizontal is always -1 to 1, and vertical is some aspect ratio refined one. //
	Matrix = Matrix3x3::Translating( Screen::HalfShape );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxSetCamera( cCamera& _Camera = Camera ) {
	CurrentCamera = &_Camera;
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxSetCameraPos( const Vector2D& v ) {
	CurrentCamera->Pos = v;
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxAddCameraPos( const Vector2D& v ) {
	CurrentCamera->Pos += v;
}
// - ------------------------------------------------------------------------------------------ - //
inline const Vector2D& gfxGetCameraPos() {
	return CurrentCamera->Pos;
}
// - ------------------------------------------------------------------------------------------ - //
inline const Vector2D gfxGetCameraCenter() {
	return Vector2D::Zero - gfxGetCameraPos();
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxSetCameraPos( const Real _x, const Real _y, const Real _z = Real::Zero ) {
	CurrentCamera->Pos = Vector2D( _x, _y );	
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxAddCameraPos( const Real _x, const Real _y, const Real _z = Real::Zero ) {
	CurrentCamera->Pos += Vector2D( _x, _y );	
}
// - ------------------------------------------------------------------------------------------ - //
inline const Real& gfxGetCameraScale() {
	return CurrentCamera->Scale;
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxSetCameraScale( const Real _CameraScale ) {
	CurrentCamera->Scale = _CameraScale;	
	
	CurrentCamera->ViewShape = Screen::Shape * CurrentCamera->Scale;
	CurrentCamera->ViewHalfShape = CurrentCamera->ViewShape * Real::Half;
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxAddCameraScale( const Real _CameraScale ) {
	gfxSetCameraScale( gfxGetCameraScale() + _CameraScale );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxConstrainCamera( const Vector2D& P1, const Vector2D& P2 ) {
	// Create a rectangle, contracting it's shape by the current size of the zoomed view //
	Rect2D InnerViewRect = Rect2D::Pair(
		P1 + CurrentCamera->ViewHalfShape,
		P2 - CurrentCamera->ViewHalfShape
		);
	
	// Restrict Camera to Zone //
	CurrentCamera->Pos = InnerViewRect.ClosestPoint( CurrentCamera->Pos );	
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxConstrainCameraScale( const Real Min, const Real Max ) {
	if ( gfxGetCameraScale() < Min )
		gfxSetCameraScale( Min );

	if ( gfxGetCameraScale() > Max )
		gfxSetCameraScale( Max );	
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxInit( const int _Width, const int _Height, const bool _FullScreen = false, const int _ScreenScalar = 1 ) {
	// Install Common Allegro Features //
	allegro_init();
	install_keyboard();
	install_mouse();
	
	// Store the requested screen dimensions //
	Screen::Width = _Width;
	Screen::Height = _Height;
	
	Screen::Scalar = _ScreenScalar;

	Screen::Shape = Vector2D( Screen::Width, Screen::Height );
	Screen::HalfShape = Screen::Shape * Real::Half;

	// Set our close button function //
	Screen::CloseButtonPressed = false;
	LOCK_FUNCTION( Screen::CloseButtonHandler );
	set_close_button_callback( Screen::CloseButtonHandler );
	
	// Set the color depth to something efficent //
	set_color_depth( 16 );
	
	// Windowed or fullscreen //
	if ( _FullScreen )
		set_gfx_mode( GFX_AUTODETECT_FULLSCREEN, Screen::Width * Screen::Scalar, Screen::Height * Screen::Scalar, 0, 0 );
	else
		set_gfx_mode( GFX_AUTODETECT_WINDOWED, Screen::Width * Screen::Scalar, Screen::Height * Screen::Scalar, 0, 0 );
	
	// Create our drawing buffer //
	Buffer = create_bitmap( Screen::Width, Screen::Height );
	
	// Set the initial current color defaulting to white //
	// (Note, makecol only works after set_gfx_mode) //
	CurrentColor = RGB_WHITE;
	CurrentNormalColor = RGB_WHITE;
	
	CurrentNormalLength = 8;
	
	// Make sure we have a freshly initialized mouse //
	Mouse = cMouse();
	
	// Set the camera //
	Camera = cCamera();
	CurrentCamera = &Camera;
	
	// Initalize Matrix //
	gfxSetScreenMatrix();

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
inline bool gfxShutdown() {
	if ( key[KEY_ESC] )
		return true;
	
	if ( key[KEY_F10] )
		return true;
	
	if ( Screen::CloseButtonPressed )
		return true;
}
// - ------------------------------------------------------------------------------------------ - //


// - ------------------------------------------------------------------------------------------ - //
inline void gfxClearBuffer( const ColorType Color = RGB_BLACK ) {
	// Clear the buffer to blackness //
	clear_to_color( Buffer, Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxSwapBuffer( ) {
	// Sync // 
	rest(0);
	vsync();
	
	// Copy the buffer to the screen //
	if ( Screen::Scalar == 1 )
		blit( Buffer, screen, 0, 0, 0, 0, Buffer->w, Buffer->h );
	else
		stretch_blit( Buffer, screen, 0, 0, Buffer->w, Buffer->h, 0, 0, Screen::Width * Screen::Scalar, Screen::Height * Screen::Scalar );
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
inline void gfxInitMatrix() {
	Matrix = Matrix3x3::Identity;	
}
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
inline void gfxFlipX() {
	Matrix(0,0) = -Matrix(0,0);
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxFlipY() {
	Matrix(1,1) = -Matrix(1,1);
}
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
inline void gfxRotate( const Vector2D& v ) {
	Matrix *= Matrix3x3::Rotating( v );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxRotate( const Real& Angle ) {
	Matrix *= Matrix3x3::Rotating( Angle );
}
// - ------------------------------------------------------------------------------------------ - //


// - ------------------------------------------------------------------------------------------ - //
#endif // __AllegroGraphics_Graphics_H__ //
// - ------------------------------------------------------------------------------------------ - //
