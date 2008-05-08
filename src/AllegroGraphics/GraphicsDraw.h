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
inline void gfxDrawClosedPolygon( const Vector2D* Poly, const size_t PolyCount, const ColorType Color ) {
	MatrixClosedPolygon( Buffer, Matrix, Poly, PolyCount, Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawOpenPolygon( const Vector2D* Poly, const size_t PolyCount, const ColorType Color ) {
	MatrixOpenPolygon( Buffer, Matrix, Poly, PolyCount, Color );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawClosedPolygonWithNormals( const Vector2D* Poly, const size_t PolyCount, const ColorType Color, const Real NormalLength = 8, const ColorType NormalColor = RGB_WHITE ) {
	MatrixClosedPolygonWithNormals( Buffer, Matrix, Poly, PolyCount, Color, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawOpenPolygonWithNormals( const Vector2D* Poly, const size_t PolyCount, const ColorType Color, const Real NormalLength = 8, const ColorType NormalColor = RGB_WHITE ) {
	MatrixOpenPolygonWithNormals( Buffer, Matrix, Poly, PolyCount, Color, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawClosedPolygonWithInvNormals( const Vector2D* Poly, const size_t PolyCount, const ColorType Color, const Real NormalLength = 8, const ColorType NormalColor = RGB_WHITE ) {
	MatrixClosedPolygonWithInvNormals( Buffer, Matrix, Poly, PolyCount, Color, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawOpenPolygonWithInvNormals( const Vector2D* Poly, const size_t PolyCount, const ColorType Color, const Real NormalLength = 8, const ColorType NormalColor = RGB_WHITE ) {
	MatrixOpenPolygonWithInvNormals( Buffer, Matrix, Poly, PolyCount, Color, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawPolygonEdge( const int Index, const Vector2D* Poly, const size_t PolyCount, const ColorType Color ) {
	MatrixPolygonEdge( Buffer, Matrix, Index, Poly, PolyCount, Color );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawEdgedPolygon( const Vector2D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const ColorType Color ) {
	MatrixEdgedPolygon( Buffer, Matrix, Poly, PolygonEnabled, PolyCount, Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawEdgedPolygonWithNormals( const Vector2D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const ColorType Color, const Real NormalLength = 8, const ColorType NormalColor = RGB_WHITE ) {
	MatrixEdgedPolygonWithNormals( Buffer, Matrix, Poly, PolygonEnabled, PolyCount, Color, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawEdgedPolygonWithInvNormals( const Vector2D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const ColorType Color, const Real NormalLength = 8, const ColorType NormalColor = RGB_WHITE ) {
	MatrixEdgedPolygonWithInvNormals( Buffer, Matrix, Poly, PolygonEnabled, PolyCount, Color, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
#endif // __AllegroGraphics_GraphicsDraw_H__ //
// - ------------------------------------------------------------------------------------------ - //
