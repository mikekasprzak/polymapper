// - ------------------------------------------------------------------------------------------ - //
#ifndef __AllegroGraphics_GraphicsDraw3D_H__
#define __AllegroGraphics_GraphicsDraw3D_H__
// - ------------------------------------------------------------------------------------------ - //
#include "Graphics.h"
#include "MatrixDraw.h"
#include "MatrixDraw3D.h"
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawCircle( const Vector3D& Center, const Real& Radius, const ColorType Color = CurrentColor ) {
	MatrixCircle( Buffer, Matrix, Center.ToVector2D(), Radius, Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawRadiusBox( const Vector3D& Center, const Real& Radius, const ColorType Color = CurrentColor ) {
	MatrixRadiusBox( Buffer, Matrix, Center.ToVector2D(), Radius, Color );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawLine( const Vector3D& P1, const Vector3D& P2, const ColorType Color = CurrentColor) {
	MatrixLine( Buffer, Matrix, P1.ToVector2D(), P2.ToVector2D(), Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawArrow( const Vector3D& P1, const Vector3D& P2, const ColorType Color = CurrentColor, const Real HeadLength = CurrentNormalLength ) {
	MatrixArrow( Buffer, Matrix, P1.ToVector2D(), P2.ToVector2D(), Color, HeadLength );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawArrow2( const Vector3D& P1, const Vector3D& P2, const ColorType Color = CurrentColor, const Real HeadLength = CurrentNormalLength ) {
	MatrixArrow2( Buffer, Matrix, P1.ToVector2D(), P2.ToVector2D(), Color, HeadLength );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawRect( const Vector3D& P1, const Vector3D& P2, const ColorType Color = CurrentColor ) {
	MatrixRect( Buffer, Matrix, Rect2D::Pair( P1.ToVector2D(), P2.ToVector2D() ), Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawRectWithNormals( const Vector3D& P1, const Vector3D& P2, const ColorType Color = CurrentColor, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixRectWithNormals( Buffer, Matrix, Rect2D::Pair( P1.ToVector2D(), P2.ToVector2D() ), Color, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawRectNormals( const Vector3D& P1, const Vector3D& P2, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixRectNormals( Buffer, Matrix, Rect2D::Pair( P1.ToVector2D(), P2.ToVector2D() ), NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawClosedPolygon( const Vector3D* Poly, const size_t PolyCount, const ColorType Color = CurrentColor ) {
	MatrixClosedPolygon( Buffer, Matrix, Poly, PolyCount, Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawOpenPolygon( const Vector3D* Poly, const size_t PolyCount, const ColorType Color = CurrentColor ) {
	MatrixOpenPolygon( Buffer, Matrix, Poly, PolyCount, Color );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawClosedPolygonWithNormals( const Vector3D* Poly, const size_t PolyCount, const ColorType Color = CurrentColor, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixClosedPolygonWithNormals( Buffer, Matrix, Poly, PolyCount, Color, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawOpenPolygonWithNormals( const Vector3D* Poly, const size_t PolyCount, const ColorType Color = CurrentColor, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixOpenPolygonWithNormals( Buffer, Matrix, Poly, PolyCount, Color, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawClosedPolygonWithInvNormals( const Vector3D* Poly, const size_t PolyCount, const ColorType Color = CurrentColor, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixClosedPolygonWithInvNormals( Buffer, Matrix, Poly, PolyCount, Color, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawOpenPolygonWithInvNormals( const Vector3D* Poly, const size_t PolyCount, const ColorType Color = CurrentColor, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixOpenPolygonWithInvNormals( Buffer, Matrix, Poly, PolyCount, Color, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawClosedPolygonNormals( const Vector3D* Poly, const size_t PolyCount, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixClosedPolygonNormals( Buffer, Matrix, Poly, PolyCount, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawOpenPolygonNormals( const Vector3D* Poly, const size_t PolyCount, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixOpenPolygonNormals( Buffer, Matrix, Poly, PolyCount, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawClosedPolygonInvNormals( const Vector3D* Poly, const size_t PolyCount, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixClosedPolygonInvNormals( Buffer, Matrix, Poly, PolyCount, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawOpenPolygonInvNormals( const Vector3D* Poly, const size_t PolyCount, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixOpenPolygonInvNormals( Buffer, Matrix, Poly, PolyCount, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawPolygonEdge( const int Index, const Vector3D* Poly, const size_t PolyCount, const ColorType Color = CurrentColor ) {
	MatrixPolygonEdge( Buffer, Matrix, Index, Poly, PolyCount, Color );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawEdgedPolygon( const Vector3D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const ColorType Color = CurrentColor ) {
	MatrixEdgedPolygon( Buffer, Matrix, Poly, PolygonEnabled, PolyCount, Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawEdgedPolygonWithNormals( const Vector3D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const ColorType Color = CurrentColor, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixEdgedPolygonWithNormals( Buffer, Matrix, Poly, PolygonEnabled, PolyCount, Color, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawEdgedPolygonWithInvNormals( const Vector3D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const ColorType Color = CurrentColor, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixEdgedPolygonWithInvNormals( Buffer, Matrix, Poly, PolygonEnabled, PolyCount, Color, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawEdgedPolygonNormals( const Vector3D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixEdgedPolygonNormals( Buffer, Matrix, Poly, PolygonEnabled, PolyCount, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void gfxDrawEdgedPolygonInvNormals( const Vector3D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const Real NormalLength = CurrentNormalLength, const ColorType NormalColor = CurrentNormalColor ) {
	MatrixEdgedPolygonInvNormals( Buffer, Matrix, Poly, PolygonEnabled, PolyCount, NormalLength, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
#endif // __AllegroGraphics_GraphicsDraw3D_H__ //
// - ------------------------------------------------------------------------------------------ - //
