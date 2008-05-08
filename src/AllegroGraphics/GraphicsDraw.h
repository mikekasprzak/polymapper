// - ------------------------------------------------------------------------------------------ - //
#ifndef __AllegroGraphics_GraphicsDraw_H__
#define __AllegroGraphics_GraphicsDraw_H__
// - ------------------------------------------------------------------------------------------ - //
#include "Graphics.h"
#include "MatrixDraw.h"
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawCircle( const Vector2D& Center, const Real& Radius, const ColorType Color ) {
	MatrixCircle( Buffer, Matrix, Center, Radius, Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawRadiusBox( const Vector2D& Center, const Real& Radius, const ColorType Color ) {
	MatrixRadiusBox( Buffer, Matrix, Center, Radius, Color );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawLine( const Vector2D& P1, const Vector2D& P2, const ColorType Color ) {
	MatrixLine( Buffer, Matrix, P1, P2, Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawArrow( const Vector2D& P1, const Vector2D& P2, const ColorType Color, const Real HeadLength = 8 ) {
	MatrixArrow( Buffer, Matrix, P1, P2, Color, HeadLength );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawArrow2( const Vector2D& P1, const Vector2D& P2, const ColorType Color, const Real HeadLength = 8 ) {
	MatrixArrow2( Buffer, Matrix, P1, P2, Color, HeadLength );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawRect( const Vector2D& P1, const Vector2D& P2, const ColorType Color ) {
	MatrixRect( Buffer, Matrix, Rect2D::Pair( P1, P2 ), Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawRectWithNormals( const Vector2D& P1, const Vector2D& P2, const ColorType Color, const Real NormalLength = 8 ) {
	MatrixRectWithNormals( Buffer, Matrix, Rect2D::Pair( P1, P2 ), Color, NormalLength );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
#endif // __AllegroGraphics_GraphicsDraw_H__ //
// - ------------------------------------------------------------------------------------------ - //
