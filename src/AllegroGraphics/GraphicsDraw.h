// - ------------------------------------------------------------------------------------------ - //
#ifndef __AllegroGraphics_GraphicsDraw_H__
#define __AllegroGraphics_GraphicsDraw_H__
// - ------------------------------------------------------------------------------------------ - //
#include "Graphics.h"
#include "MatrixDraw.h"
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawCircle( const Vector2D& Center, const Real& Radius, const ColorType Color = CurrentColor ) {
	MatrixCircle( Buffer, Matrix, Center, Radius, Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawRadiusBox( const Vector2D& Center, const Real& Radius, const ColorType Color = CurrentColor ) {
	MatrixRadiusBox( Buffer, Matrix, Center, Radius, Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawCircleFill( const Vector2D& Center, const Real& Radius, const ColorType Color = CurrentColor ) {
	MatrixCircleFill( Buffer, Matrix, Center, Radius, Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawRadiusBoxFill( const Vector2D& Center, const Real& Radius, const ColorType Color = CurrentColor ) {
	MatrixRadiusBoxFill( Buffer, Matrix, Center, Radius, Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawCross( const Vector2D& Center, const Real& Radius, const ColorType Color = CurrentColor ) {
	MatrixCross( Buffer, Matrix, Center, Radius, Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawX( const Vector2D& Center, const Real& Radius, const ColorType Color = CurrentColor ) {
	MatrixRadiusX( Buffer, Matrix, Center, Radius, Color );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawLine( const Vector2D& P1, const Vector2D& P2, const ColorType Color = CurrentColor) {
	MatrixLine( Buffer, Matrix, P1, P2, Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawArrow( const Vector2D& P1, const Vector2D& P2, const ColorType Color = CurrentColor, const Real HeadLength = CurrentNormalLength ) {
	MatrixArrow( Buffer, Matrix, P1, P2, Color, HeadLength );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawArrow2( const Vector2D& P1, const Vector2D& P2, const ColorType Color = CurrentColor, const Real HeadLength = CurrentNormalLength ) {
	MatrixArrow2( Buffer, Matrix, P1, P2, Color, HeadLength );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawRect( const Vector2D& P1, const Vector2D& P2, const ColorType Color = CurrentColor ) {
	MatrixRect( Buffer, Matrix, Rect2D::Pair( P1, P2 ), Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawRectWithNormals( const Vector2D& P1, const Vector2D& P2, const ColorType Color = CurrentColor, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixRectWithNormals( Buffer, Matrix, Rect2D::Pair( P1, P2 ), Color, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawRectNormals( const Vector2D& P1, const Vector2D& P2, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixRectNormals( Buffer, Matrix, Rect2D::Pair( P1, P2 ), NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawClosedPolygon( const Vector2D* Poly, const size_t PolyCount, const ColorType Color = CurrentColor ) {
	MatrixClosedPolygon( Buffer, Matrix, Poly, PolyCount, Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawOpenPolygon( const Vector2D* Poly, const size_t PolyCount, const ColorType Color = CurrentColor ) {
	MatrixOpenPolygon( Buffer, Matrix, Poly, PolyCount, Color );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawClosedPolygonWithNormals( const Vector2D* Poly, const size_t PolyCount, const ColorType Color = CurrentColor, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixClosedPolygonWithNormals( Buffer, Matrix, Poly, PolyCount, Color, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawOpenPolygonWithNormals( const Vector2D* Poly, const size_t PolyCount, const ColorType Color = CurrentColor, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixOpenPolygonWithNormals( Buffer, Matrix, Poly, PolyCount, Color, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawClosedPolygonWithInvNormals( const Vector2D* Poly, const size_t PolyCount, const ColorType Color = CurrentColor, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixClosedPolygonWithInvNormals( Buffer, Matrix, Poly, PolyCount, Color, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawOpenPolygonWithInvNormals( const Vector2D* Poly, const size_t PolyCount, const ColorType Color = CurrentColor, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixOpenPolygonWithInvNormals( Buffer, Matrix, Poly, PolyCount, Color, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawClosedPolygonNormals( const Vector2D* Poly, const size_t PolyCount, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixClosedPolygonNormals( Buffer, Matrix, Poly, PolyCount, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawOpenPolygonNormals( const Vector2D* Poly, const size_t PolyCount, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixOpenPolygonNormals( Buffer, Matrix, Poly, PolyCount, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawClosedPolygonInvNormals( const Vector2D* Poly, const size_t PolyCount, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixClosedPolygonInvNormals( Buffer, Matrix, Poly, PolyCount, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawOpenPolygonInvNormals( const Vector2D* Poly, const size_t PolyCount, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixOpenPolygonInvNormals( Buffer, Matrix, Poly, PolyCount, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawPolygonEdge( const int Index, const Vector2D* Poly, const size_t PolyCount, const ColorType Color = CurrentColor ) {
	MatrixPolygonEdge( Buffer, Matrix, Index, Poly, PolyCount, Color );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawEdgedPolygon( const Vector2D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const ColorType Color = CurrentColor ) {
	MatrixEdgedPolygon( Buffer, Matrix, Poly, PolygonEnabled, PolyCount, Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawEdgedPolygonWithNormals( const Vector2D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const ColorType Color = CurrentColor, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixEdgedPolygonWithNormals( Buffer, Matrix, Poly, PolygonEnabled, PolyCount, Color, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawEdgedPolygonWithInvNormals( const Vector2D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const ColorType Color = CurrentColor, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixEdgedPolygonWithInvNormals( Buffer, Matrix, Poly, PolygonEnabled, PolyCount, Color, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawEdgedPolygonNormals( const Vector2D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixEdgedPolygonNormals( Buffer, Matrix, Poly, PolygonEnabled, PolyCount, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawEdgedPolygonInvNormals( const Vector2D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixEdgedPolygonInvNormals( Buffer, Matrix, Poly, PolygonEnabled, PolyCount, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
#endif // __AllegroGraphics_GraphicsDraw_H__ //
// - ------------------------------------------------------------------------------------------ - //
