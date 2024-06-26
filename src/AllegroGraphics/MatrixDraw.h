// - ------------------------------------------------------------------------------------------ - //
#ifndef __AllegroGraphics_MatrixDraw_H__
#define __AllegroGraphics_MatrixDraw_H__
// - ------------------------------------------------------------------------------------------ - //
#include <Allegro.h>
// - ------------------------------------------------------------------------------------------ - //
#include <Math/Vector.h>
#include <Math/Matrix.h>
#include <Geometry/Rect.h>
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixCircle( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D& Pos, const Real& Radius, const int Color ) {
	// Transform our point by the matrix //
	Vector2D Point = Pos.ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	// Transform our Radius by the Matrix //
	// TODO: This isn't perfect.  Make it perfect. //
	Real TrRadius = Matrix(0,0) * Radius;
	
	// Draw our circle //
	circle( Target, (int)Point.x, (int)Point.y, (int)TrRadius, Color );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void RadiusBox( BITMAP* Target, const Vector2D& Pos, const Real& Radius, const int Color ) {
	rect( Target, (int)(Pos.x - Radius), (int)(Pos.y - Radius), (int)(Pos.x + Radius), (int)(Pos.y + Radius), Color );	
}
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixRadiusBox( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D& Pos, const Real& Radius, const int Color ) {
	// Transform our point by the matrix //
	Vector2D Point = Pos.ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();

	// Transform our Radius by the Matrix //
	// TODO: This isn't perfect.  Make it perfect. //
	Real TrRadius = Matrix(0,0) * Radius;
	
	// Draw our box //
	RadiusBox( Target, Point, TrRadius, Color );
	//rect( Target, (int)(Point.x - TrRadius), (int)(Point.y - TrRadius), (int)(Point.x + TrRadius), (int)(Point.y + TrRadius), Color );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void MatrixCircleFill( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D& Pos, const Real& Radius, const int Color ) {
	// Transform our point by the matrix //
	Vector2D Point = Pos.ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	// Transform our Radius by the Matrix //
	// TODO: This isn't perfect.  Make it perfect. //
	Real TrRadius = Matrix(0,0) * Radius;
	
	// Draw our circle //
	circlefill( Target, (int)Point.x, (int)Point.y, (int)TrRadius, Color );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void RadiusBoxFill( BITMAP* Target, const Vector2D& Pos, const Real& Radius, const int Color ) {
	rectfill( Target, (int)(Pos.x - Radius), (int)(Pos.y - Radius), (int)(Pos.x + Radius), (int)(Pos.y + Radius), Color );	
}
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixRadiusBoxFill( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D& Pos, const Real& Radius, const int Color ) {
	// Transform our point by the matrix //
	Vector2D Point = Pos.ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();

	// Transform our Radius by the Matrix //
	// TODO: This isn't perfect.  Make it perfect. //
	Real TrRadius = Matrix(0,0) * Radius;
	
	// Draw our box //
	RadiusBoxFill( Target, Point, TrRadius, Color );
	//rect( Target, (int)(Point.x - TrRadius), (int)(Point.y - TrRadius), (int)(Point.x + TrRadius), (int)(Point.y + TrRadius), Color );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void Cross( BITMAP* Target, const Vector2D& Pos, const Real& Radius, const int Color ) {
	rect( Target, (int)(Pos.x - Radius), (int)(Pos.y), (int)(Pos.x + Radius), (int)(Pos.y), Color );	
	rect( Target, (int)(Pos.x), (int)(Pos.y - Radius), (int)(Pos.x), (int)(Pos.y + Radius), Color );	
}
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixCross( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D& Pos, const Real& Radius, const int Color ) {
	// Transform our point by the matrix //
	Vector2D Point = Pos.ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();

	// Transform our Radius by the Matrix //
	// TODO: This isn't perfect.  Make it perfect. //
	Real TrRadius = Matrix(0,0) * Radius;
	
	// Draw our cross //
	Cross( Target, Point, TrRadius, Color );
	//rect( Target, (int)(Point.x - TrRadius), (int)(Point.y - TrRadius), (int)(Point.x + TrRadius), (int)(Point.y + TrRadius), Color );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void RadiusX( BITMAP* Target, const Vector2D& Pos, const Real& Radius, const int Color ) {
	line( Target, (int)(Pos.x - Radius), (int)(Pos.y - Radius), (int)(Pos.x + Radius), (int)(Pos.y + Radius), Color );
	line( Target, (int)(Pos.x + Radius), (int)(Pos.y - Radius), (int)(Pos.x - Radius), (int)(Pos.y + Radius), Color );	
}
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixRadiusX( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D& Pos, const Real& Radius, const int Color ) {
	// Transform our point by the matrix //
	Vector2D Point = Pos.ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();

	// Transform our Radius by the Matrix //
	// TODO: This isn't perfect.  Make it perfect. //
	Real TrRadius = Matrix(0,0) * Radius;
	
	// Draw our box //
	RadiusX( Target, Point, TrRadius, Color );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
#define MatrixPrintfCenterCenter(t,m,p,c,_Format,_Args...) \
{ \
	char StrBuff[1024]; \
	sprintf( StrBuff, _Format, ## _Args ); \
	Vector2D Offset( text_length(font,StrBuff) >> 1, text_height(font) >> 1 ); \
	MatrixPrint(t,m,(p)-Offset,c,StrBuff); \
}
// - ------------------------------------------------------------------------------------------ - //
#define MatrixPrintfRightCenter(t,m,p,c,_Format,_Args...) \
{ \
	char StrBuff[1024]; \
	sprintf( StrBuff, _Format, ## _Args ); \
	Vector2D Offset( text_length(font,StrBuff), text_height(font) >> 1 ); \
	MatrixPrint(t,m,(p)-Offset,c,StrBuff); \
}
// - ------------------------------------------------------------------------------------------ - //
#define MatrixPrintfLeftCenter(t,m,p,c,_Format,_Args...) \
{ \
	char StrBuff[1024]; \
	sprintf( StrBuff, _Format, ## _Args ); \
	Vector2D Offset( 0, text_height(font) >> 1 ); \
	MatrixPrint(t,m,(p)-Offset,c,StrBuff); \
}
// - ------------------------------------------------------------------------------------------ - //
#define MatrixPrintfCenter(t,m,p,c,_Format,_Args...) \
{ \
	char StrBuff[1024]; \
	sprintf( StrBuff, _Format, ## _Args ); \
	Vector2D Offset( text_length(font,StrBuff) >> 1, 0 ); \
	MatrixPrint(t,m,(p)-Offset,c,StrBuff); \
}
// - ------------------------------------------------------------------------------------------ - //
#define MatrixPrintfRight(t,m,p,c,_Format,_Args...) \
{ \
	char StrBuff[1024]; \
	sprintf( StrBuff, _Format, ## _Args ); \
	Vector2D Offset( text_length(font,StrBuff), 0 ); \
	MatrixPrint(t,m,(p)-Offset,c,StrBuff); \
}
// - ------------------------------------------------------------------------------------------ - //
#define MatrixPrintfLeft(t,m,p,c,_Format,_Args...) \
{ \
	char StrBuff[1024]; \
	sprintf( StrBuff, _Format, ## _Args ); \
	MatrixPrint(t,m,p,c,StrBuff); \
}
// - ------------------------------------------------------------------------------------------ - //
#define MatrixPrintf(t,m,p,c,_Format,_Args...) \
	MatrixPrintfLeft(t,m,p,c,_Format, ## _Args)
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixPrint( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D& Pos, const int Color, const char* Msg) {
	// Transform our point by the matrix //
	Vector2D Point = Pos.ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();

	// Draw our text //
	textout_ex( Target, font, Msg, (int)Point.x, (int)Point.y, Color, -1 );
}
// - ------------------------------------------------------------------------------------------ - //



// - ------------------------------------------------------------------------------------------ - //
inline void MatrixLine( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D& P1, const Vector2D& P2, const int Color ) {
	// Get our points //
	Vector2D Point[2];
	
	// Transform them by the matrix //
	Point[0] = P1.ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[1] = P2.ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	// Draw our line //
	line( Target, (int)(Point[0].x), (int)(Point[0].y), (int)(Point[1].x), (int)(Point[1].y), Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixArrow( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D& P1, const Vector2D& P2, const int Color, const Real HeadLength = 8 ) {
	// Get our points //
	Vector2D Point[2];
	
	// Transform them by the matrix //
	Point[0] = P1.ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[1] = P2.ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	// Draw our line //
	line( Target, (int)(Point[0].x), (int)(Point[0].y), (int)(Point[1].x), (int)(Point[1].y), Color );
	
	// Calculate Arrowhead angle //
	Vector2D HeadPoint = Point[0] - Point[1];
	HeadPoint.Normalize();
	HeadPoint *= HeadLength;
	
	// Draw the Arrowhead on P2 //
	// TODO: Scale the arrowheads //
	line( Target, (int)((HeadPoint.Rotate45() + Point[1]).x), (int)((HeadPoint.Rotate45() + Point[1]).y), (int)(Point[1].x), (int)(Point[1].y), Color );
	line( Target, (int)((HeadPoint.RotateNegative45() + Point[1]).x), (int)((HeadPoint.RotateNegative45() + Point[1]).y), (int)(Point[1].x), (int)(Point[1].y), Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixArrow2( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D& P1, const Vector2D& P2, const int Color, const Real HeadLength = 8 ) {
	// Get our points //
	Vector2D Point[2];
	
	// Transform them by the matrix //
	Point[0] = P1.ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[1] = P2.ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	// Draw our line //
	line( Target, (int)(Point[0].x), (int)(Point[0].y), (int)(Point[1].x), (int)(Point[1].y), Color );
	
	// Calculate Arrowhead angles //
	Vector2D HeadPoint = Point[0] - Point[1];
	HeadPoint.Normalize();
	HeadPoint *= HeadLength;
	
	// Draw the Arrowheads //
	// TODO: Scale the arrowheads //
	line( Target, (int)((HeadPoint.Rotate45() + Point[1]).x), (int)((HeadPoint.Rotate45() + Point[1]).y), (int)(Point[1].x), (int)(Point[1].y), Color );
	line( Target, (int)((HeadPoint.RotateNegative45() + Point[1]).x), (int)((HeadPoint.RotateNegative45() + Point[1]).y), (int)(Point[1].x), (int)(Point[1].y), Color );

	line( Target, (int)((-HeadPoint.Rotate45() + Point[0]).x), (int)((-HeadPoint.Rotate45() + Point[0]).y), (int)(Point[0].x), (int)(Point[0].y), Color );
	line( Target, (int)((-HeadPoint.RotateNegative45() + Point[0]).x), (int)((-HeadPoint.RotateNegative45() + Point[0]).y), (int)(Point[0].x), (int)(Point[0].y), Color );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void MatrixRect( BITMAP* Target, const Matrix3x3& Matrix, const Rect2D& Rect, const int Color ) {
	// Get our points //
	Vector2D Point[4];
	Point[0] = Rect.P1();
	Point[1] = Vector2D( Rect.P2().x, Rect.P1().y );
	Point[2] = Rect.P2();
	Point[3] = Vector2D( Rect.P1().x, Rect.P2().y );
	
	// Transform them by the matrix //
	// TODO: Can be optimized to one transformation (because it's 2D, and Tangent) //
	Point[0] = Point[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[1] = Point[1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[2] = Point[2].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[3] = Point[3].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	// Draw our 4 lines to make the rectangle //
	line( Target, (int)(Point[0].x), (int)(Point[0].y), (int)(Point[1].x), (int)(Point[1].y), Color );
	line( Target, (int)(Point[1].x), (int)(Point[1].y), (int)(Point[2].x), (int)(Point[2].y), Color );
	line( Target, (int)(Point[2].x), (int)(Point[2].y), (int)(Point[3].x), (int)(Point[3].y), Color );
	line( Target, (int)(Point[3].x), (int)(Point[3].y), (int)(Point[0].x), (int)(Point[0].y), Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixRectFill( BITMAP* Target, const Matrix3x3& Matrix, const Rect2D& Rect, const int Color ) {
	// Get our points //
	Vector2D Point[4];
	Point[0] = Rect.P1();
	Point[1] = Vector2D( Rect.P2().x, Rect.P1().y );
	Point[2] = Rect.P2();
	Point[3] = Vector2D( Rect.P1().x, Rect.P2().y );
	
	// Transform them by the matrix //
	// TODO: Can be optimized to one transformation (because it's 2D, and Tangent) //
	Point[0] = Point[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[1] = Point[1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[2] = Point[2].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[3] = Point[3].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	// Draw 2 triangles to make the rectangle //
	triangle( Target, (int)(Point[0].x), (int)(Point[0].y), (int)(Point[1].x), (int)(Point[1].y), (int)(Point[2].x), (int)(Point[2].y), Color );
	triangle( Target, (int)(Point[2].x), (int)(Point[2].y), (int)(Point[3].x), (int)(Point[3].y), (int)(Point[0].x), (int)(Point[0].y), Color );
//	line( Target, (int)(Point[2].x), (int)(Point[2].y), (int)(Point[3].x), (int)(Point[3].y), Color );
//	line( Target, (int)(Point[3].x), (int)(Point[3].y), (int)(Point[0].x), (int)(Point[0].y), Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixRectWithNormals( BITMAP* Target, const Matrix3x3& Matrix, const Rect2D& Rect, const int Color, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255)  ) {
	// Get our points //
	Vector2D Point[4];
	Point[0] = Rect.P1();
	Point[1] = Vector2D( Rect.P2().x, Rect.P1().y );
	Point[2] = Rect.P2();
	Point[3] = Vector2D( Rect.P1().x, Rect.P2().y );
	
	// Transform them by the matrix //
	// TODO: Can be optimized to one transformation (because it's 2D, and Tangent) //
	Point[0] = Point[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[1] = Point[1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[2] = Point[2].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[3] = Point[3].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	// Draw our 4 lines to make the rectangle //
	line( Target, (int)(Point[0].x), (int)(Point[0].y), (int)(Point[1].x), (int)(Point[1].y), Color );
	line( Target, (int)(Point[1].x), (int)(Point[1].y), (int)(Point[2].x), (int)(Point[2].y), Color );
	line( Target, (int)(Point[2].x), (int)(Point[2].y), (int)(Point[3].x), (int)(Point[3].y), Color );
	line( Target, (int)(Point[3].x), (int)(Point[3].y), (int)(Point[0].x), (int)(Point[0].y), Color );
	
	// TODO: Can be optimized to use same general transformation information as the center //
	//   plus "one transformation" method theorized above. //
	// TODO: Scale the normals by Matrix //
	
	{
		// Take Point A to B //
		Vector2D AB = Point[1] - Point[0];
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = Point[0] + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (AB.Tangent() * NormalLength );

		// Draw the Normal //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}
	
	{
		// Take Point A to B //
		Vector2D AB = Point[2] - Point[1];
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = Point[1] + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (AB.Tangent() * NormalLength );

		// Draw the Normal //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}
	
	{
		// Take Point A to B //
		Vector2D AB = Point[3] - Point[2];
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = Point[2] + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (AB.Tangent() * NormalLength );

		// Draw the Normal //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}
	
	{
		// Take Point A to B //
		Vector2D AB = Point[0] - Point[3];
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = Point[3] + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (AB.Tangent() * NormalLength );

		// Draw the Normal //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}

}
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixRectNormals( BITMAP* Target, const Matrix3x3& Matrix, const Rect2D& Rect, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255)  ) {
	// Get our points //
	Vector2D Point[4];
	Point[0] = Rect.P1();
	Point[1] = Vector2D( Rect.P2().x, Rect.P1().y );
	Point[2] = Rect.P2();
	Point[3] = Vector2D( Rect.P1().x, Rect.P2().y );
	
	// Transform them by the matrix //
	// TODO: Can be optimized to one transformation (because it's 2D, and Tangent) //
	Point[0] = Point[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[1] = Point[1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[2] = Point[2].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[3] = Point[3].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	// TODO: Can be optimized to use same general transformation information as the center //
	//   plus "one transformation" method theorized above. //
	// TODO: Scale the normals by Matrix //
	
	{
		// Take Point A to B //
		Vector2D AB = Point[1] - Point[0];
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = Point[0] + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (AB.Tangent() * NormalLength );

		// Draw the Normal //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}
	
	{
		// Take Point A to B //
		Vector2D AB = Point[2] - Point[1];
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = Point[1] + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (AB.Tangent() * NormalLength );

		// Draw the Normal //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}
	
	{
		// Take Point A to B //
		Vector2D AB = Point[3] - Point[2];
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = Point[2] + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (AB.Tangent() * NormalLength );

		// Draw the Normal //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}
	
	{
		// Take Point A to B //
		Vector2D AB = Point[0] - Point[3];
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = Point[3] + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (AB.Tangent() * NormalLength );

		// Draw the Normal //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}

}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void MatrixRectEdge( BITMAP* Target, const Matrix3x3& Matrix, const int Index, const Rect2D& Rect, const int Color ) {
	// Get our points //
	Vector2D Point[4];
	Point[0] = Rect.P1();
	Point[1] = Vector2D( Rect.P2().x, Rect.P1().y );
	Point[2] = Rect.P2();
	Point[3] = Vector2D( Rect.P1().x, Rect.P2().y );
	
	// Transform them by the matrix //
	// TODO: Can be optimized to one transformation (because it's 2D, and Tangent) //
	Point[0] = Point[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[1] = Point[1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[2] = Point[2].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[3] = Point[3].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	// Draw the line associated with the edge //
	if ( Index == 0 )
		line( Target, (int)(Point[0].x), (int)(Point[0].y), (int)(Point[1].x), (int)(Point[1].y), Color );
	else if ( Index == 1 )
		line( Target, (int)(Point[1].x), (int)(Point[1].y), (int)(Point[2].x), (int)(Point[2].y), Color );
	else if ( Index == 2 )
		line( Target, (int)(Point[2].x), (int)(Point[2].y), (int)(Point[3].x), (int)(Point[3].y), Color );
	else if ( Index == 3 )
		line( Target, (int)(Point[3].x), (int)(Point[3].y), (int)(Point[0].x), (int)(Point[0].y), Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixRectEdgeNormal( BITMAP* Target, const Matrix3x3& Matrix, const int Index, const Rect2D& Rect, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
	// Get our points //
	Vector2D Point[4];
	Point[0] = Rect.P1();
	Point[1] = Vector2D( Rect.P2().x, Rect.P1().y );
	Point[2] = Rect.P2();
	Point[3] = Vector2D( Rect.P1().x, Rect.P2().y );
	
	// Transform them by the matrix //
	// TODO: Can be optimized to one transformation (because it's 2D, and Tangent) //
	Point[0] = Point[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[1] = Point[1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[2] = Point[2].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[3] = Point[3].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	// TODO: Can be optimized to use same general transformation information as the center //
	//   plus "one transformation" method theorized above. //
	// TODO: Scale the normals by Matrix //
	if ( Index == 0 )
	{
		// Take Point A to B //
		Vector2D AB = Point[1] - Point[0];
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = Point[0] + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (AB.Tangent() * NormalLength );

		// Draw the Normal //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}
	else if ( Index == 1 )	
	{
		// Take Point A to B //
		Vector2D AB = Point[2] - Point[1];
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = Point[1] + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (AB.Tangent() * NormalLength );

		// Draw the Normal //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}
	else if ( Index == 2 )	
	{
		// Take Point A to B //
		Vector2D AB = Point[3] - Point[2];
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = Point[2] + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (AB.Tangent() * NormalLength );

		// Draw the Normal //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}
	else if ( Index == 3 )	
	{
		// Take Point A to B //
		Vector2D AB = Point[0] - Point[3];
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = Point[3] + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (AB.Tangent() * NormalLength );

		// Draw the Normal //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void MatrixClosedPolygon( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D* Poly, const size_t PolyCount, const int Color ) {
	// Bail if less than 2 points //
	if ( PolyCount < 2 )
		return;
	
	// Transform the first point //
	Vector2D StartPoint = Poly[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	Vector2D LastPoint;
	Vector2D NextPoint = StartPoint;
	
	// For every point in the Polygon //
	for ( size_t idx = 0; idx < PolyCount-1; idx++ ) {
		// Last becomes Next, and transform a new Next //
		LastPoint = NextPoint;
		NextPoint = Poly[idx+1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
		
		line( Target, (int)LastPoint.x, (int)LastPoint.y, (int)NextPoint.x, (int)NextPoint.y, Color );
	}

	// Close the polygon //
	line( Target, (int)NextPoint.x, (int)NextPoint.y, (int)StartPoint.x, (int)StartPoint.y, Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixOpenPolygon( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D* Poly, const size_t PolyCount, const int Color ) {
	// Bail if less than 2 points //
	if ( PolyCount < 2 )
		return;
	
	// Transform the point //
	Vector2D LastPoint;
	Vector2D NextPoint = Poly[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	// For every point in the Polygon //
	for ( size_t idx = 0; idx < PolyCount-1; idx++ ) {
		// Last becomes Next, and transform a new Next //
		LastPoint = NextPoint;
		NextPoint = Poly[idx+1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
		
		line( Target, (int)LastPoint.x, (int)LastPoint.y, (int)NextPoint.x, (int)NextPoint.y, Color );
	}
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void MatrixPolygonEdge( BITMAP* Target, const Matrix3x3& Matrix, const int Index, const Vector2D* Poly, const size_t PolyCount, const int Color ) {
	// Immediately bail if index is less than zero //
	if ( Index < 0 )
		return;
	
	// Bail if less than 2 points //
	if ( PolyCount < 2 )
		return;

	// For every point in the Polygon //
	size_t idx = Index;
	if (idx < PolyCount-1 ) {
		// Last becomes Next, and transform a new Next //
		Vector2D LastPoint = Poly[idx].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();;
		Vector2D NextPoint = Poly[idx+1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
		
		line( Target, (int)LastPoint.x, (int)LastPoint.y, (int)NextPoint.x, (int)NextPoint.y, Color );
	}
	else if (idx == PolyCount-1 ) {
		// Last becomes Next, and transform a new Next //
		Vector2D LastPoint = Poly[PolyCount-1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();;
		Vector2D NextPoint = Poly[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
		
		line( Target, (int)LastPoint.x, (int)LastPoint.y, (int)NextPoint.x, (int)NextPoint.y, Color );
	}
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void MatrixClosedPolygonWithNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D* Poly, const size_t PolyCount, const int Color, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
	// Bail if less than 2 points //
	if ( PolyCount < 2 )
		return;
	
	// Transform the first point //
	Vector2D StartPoint = Poly[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	Vector2D LastPoint;
	Vector2D NextPoint = StartPoint;
	
	// For every point in the Polygon //
	for ( size_t idx = 0; idx < PolyCount-1; idx++ ) {
		// Last becomes Next, and transform a new Next //
		LastPoint = NextPoint;
		NextPoint = Poly[idx+1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
		
		// Draw the Line //
		line( Target, (int)LastPoint.x, (int)LastPoint.y, (int)NextPoint.x, (int)NextPoint.y, Color );
		
		
		// Take Point A to B //
		Vector2D AB = NextPoint - LastPoint;
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = LastPoint + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (AB.Tangent() * NormalLength );
		
		// Draw the Normal //
		// TODO: Scale the normals by Matrix //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}

	// Draw the closing line //
	line( Target, (int)NextPoint.x, (int)NextPoint.y, (int)StartPoint.x, (int)StartPoint.y, Color );

	// Take Point A to B //
	Vector2D AB = StartPoint - NextPoint;
	Real Length = AB.NormalizeRet();
	
	// Calculate Center //
	Vector2D Center = NextPoint + (AB * (Length * Real::Half));

	// Calculate Normal's position //
	Vector2D Normal = Center + (AB.Tangent() * NormalLength );
	
	// Draw the Normal //
	// TODO: Scale the normals by Matrix //
	line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixClosedPolygonWithInvNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D* Poly, const size_t PolyCount, const int Color, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
	// Bail if less than 2 points //
	if ( PolyCount < 2 )
		return;
	
	// Transform the first point //
	Vector2D StartPoint = Poly[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	Vector2D LastPoint;
	Vector2D NextPoint = StartPoint;
	
	// For every point in the Polygon //
	for ( size_t idx = 0; idx < PolyCount-1; idx++ ) {
		// Last becomes Next, and transform a new Next //
		LastPoint = NextPoint;
		NextPoint = Poly[idx+1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
		
		// Draw the Line //
		line( Target, (int)LastPoint.x, (int)LastPoint.y, (int)NextPoint.x, (int)NextPoint.y, Color );
		
		
		// Take Point A to B //
		Vector2D AB = NextPoint - LastPoint;
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = LastPoint + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (-AB.Tangent() * NormalLength );
		
		// Draw the Normal //
		// TODO: Scale the normals by Matrix //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}

	// Draw the closing line //
	line( Target, (int)NextPoint.x, (int)NextPoint.y, (int)StartPoint.x, (int)StartPoint.y, Color );

	// Take Point A to B //
	Vector2D AB = StartPoint - NextPoint;
	Real Length = AB.NormalizeRet();
	
	// Calculate Center //
	Vector2D Center = NextPoint + (AB * (Length * Real::Half));

	// Calculate Normal's position //
	Vector2D Normal = Center + (-AB.Tangent() * NormalLength );
	
	// Draw the Normal //
	// TODO: Scale the normals by Matrix //
	line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixOpenPolygonWithNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D* Poly, const size_t PolyCount, const int Color, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
	// Bail if less than 2 points //
	if ( PolyCount < 2 )
		return;
	
	// Transform the first point //
	Vector2D StartPoint = Poly[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	Vector2D LastPoint;
	Vector2D NextPoint = StartPoint;
	
	// For every point in the Polygon //
	for ( size_t idx = 0; idx < PolyCount-1; idx++ ) {
		// Last becomes Next, and transform a new Next //
		LastPoint = NextPoint;
		NextPoint = Poly[idx+1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
		
		// Draw the Line //
		line( Target, (int)LastPoint.x, (int)LastPoint.y, (int)NextPoint.x, (int)NextPoint.y, Color );
		
		
		// Take Point A to B //
		Vector2D AB = NextPoint - LastPoint;
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = LastPoint + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (AB.Tangent() * NormalLength );
		
		// Draw the Normal //
		// TODO: Scale the normals by Matrix //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}
}
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixOpenPolygonWithInvNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D* Poly, const size_t PolyCount, const int Color, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
	// Bail if less than 2 points //
	if ( PolyCount < 2 )
		return;
	
	// Transform the first point //
	Vector2D StartPoint = Poly[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	Vector2D LastPoint;
	Vector2D NextPoint = StartPoint;
	
	// For every point in the Polygon //
	for ( size_t idx = 0; idx < PolyCount-1; idx++ ) {
		// Last becomes Next, and transform a new Next //
		LastPoint = NextPoint;
		NextPoint = Poly[idx+1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
		
		// Draw the Line //
		line( Target, (int)LastPoint.x, (int)LastPoint.y, (int)NextPoint.x, (int)NextPoint.y, Color );
		
		
		// Take Point A to B //
		Vector2D AB = NextPoint - LastPoint;
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = LastPoint + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (-AB.Tangent() * NormalLength );
		
		// Draw the Normal //
		// TODO: Scale the normals by Matrix //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void MatrixClosedPolygonNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D* Poly, const size_t PolyCount, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
	// Bail if less than 2 points //
	if ( PolyCount < 2 )
		return;
	
	// Transform the first point //
	Vector2D StartPoint = Poly[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	Vector2D LastPoint;
	Vector2D NextPoint = StartPoint;
	
	// For every point in the Polygon //
	for ( size_t idx = 0; idx < PolyCount-1; idx++ ) {
		// Last becomes Next, and transform a new Next //
		LastPoint = NextPoint;
		NextPoint = Poly[idx+1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
		
		// Take Point A to B //
		Vector2D AB = NextPoint - LastPoint;
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = LastPoint + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (AB.Tangent() * NormalLength );
		
		// Draw the Normal //
		// TODO: Scale the normals by Matrix //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}

	// Take Point A to B //
	Vector2D AB = StartPoint - NextPoint;
	Real Length = AB.NormalizeRet();
	
	// Calculate Center //
	Vector2D Center = NextPoint + (AB * (Length * Real::Half));

	// Calculate Normal's position //
	Vector2D Normal = Center + (AB.Tangent() * NormalLength );
	
	// Draw the Normal //
	// TODO: Scale the normals by Matrix //
	line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixClosedPolygonInvNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D* Poly, const size_t PolyCount, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
	// Bail if less than 2 points //
	if ( PolyCount < 2 )
		return;
	
	// Transform the first point //
	Vector2D StartPoint = Poly[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	Vector2D LastPoint;
	Vector2D NextPoint = StartPoint;
	
	// For every point in the Polygon //
	for ( size_t idx = 0; idx < PolyCount-1; idx++ ) {
		// Last becomes Next, and transform a new Next //
		LastPoint = NextPoint;
		NextPoint = Poly[idx+1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
		
		// Take Point A to B //
		Vector2D AB = NextPoint - LastPoint;
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = LastPoint + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (-AB.Tangent() * NormalLength );
		
		// Draw the Normal //
		// TODO: Scale the normals by Matrix //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}

	// Take Point A to B //
	Vector2D AB = StartPoint - NextPoint;
	Real Length = AB.NormalizeRet();
	
	// Calculate Center //
	Vector2D Center = NextPoint + (AB * (Length * Real::Half));

	// Calculate Normal's position //
	Vector2D Normal = Center + (-AB.Tangent() * NormalLength );
	
	// Draw the Normal //
	// TODO: Scale the normals by Matrix //
	line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
}
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixOpenPolygonNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D* Poly, const size_t PolyCount, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
	// Bail if less than 2 points //
	if ( PolyCount < 2 )
		return;
	
	// Transform the first point //
	Vector2D StartPoint = Poly[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	Vector2D LastPoint;
	Vector2D NextPoint = StartPoint;
	
	// For every point in the Polygon //
	for ( size_t idx = 0; idx < PolyCount-1; idx++ ) {
		// Last becomes Next, and transform a new Next //
		LastPoint = NextPoint;
		NextPoint = Poly[idx+1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
		
		// Take Point A to B //
		Vector2D AB = NextPoint - LastPoint;
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = LastPoint + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (AB.Tangent() * NormalLength );
		
		// Draw the Normal //
		// TODO: Scale the normals by Matrix //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}
}
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixOpenPolygonInvNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D* Poly, const size_t PolyCount, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
	// Bail if less than 2 points //
	if ( PolyCount < 2 )
		return;
	
	// Transform the first point //
	Vector2D StartPoint = Poly[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	Vector2D LastPoint;
	Vector2D NextPoint = StartPoint;
	
	// For every point in the Polygon //
	for ( size_t idx = 0; idx < PolyCount-1; idx++ ) {
		// Last becomes Next, and transform a new Next //
		LastPoint = NextPoint;
		NextPoint = Poly[idx+1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
		
		// Take Point A to B //
		Vector2D AB = NextPoint - LastPoint;
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = LastPoint + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (-AB.Tangent() * NormalLength );
		
		// Draw the Normal //
		// TODO: Scale the normals by Matrix //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}
}
// - ------------------------------------------------------------------------------------------ - //


// - ------------------------------------------------------------------------------------------ - //
inline void MatrixEdgedPolygon( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const int Color ) {
	// Bail if less than 2 points //
	if ( PolyCount < 2 )
		return;
	
	// Transform the first point //
	Vector2D StartPoint = Poly[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	Vector2D LastPoint;
	Vector2D NextPoint = StartPoint;
	
	// For every point in the Polygon //
	for ( size_t idx = 0; idx < PolyCount-1; idx++ ) {
		// Last becomes Next, and transform a new Next //
		LastPoint = NextPoint;
		NextPoint = Poly[idx+1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
		
		if ( PolygonEnabled[ idx ] )
			line( Target, (int)LastPoint.x, (int)LastPoint.y, (int)NextPoint.x, (int)NextPoint.y, Color );
	}

	// Close the polygon //
	if ( PolygonEnabled[ PolyCount-1 ] )
		line( Target, (int)NextPoint.x, (int)NextPoint.y, (int)StartPoint.x, (int)StartPoint.y, Color );
}
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixEdgedPolygonWithNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const int Color, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
	// Bail if less than 2 points //
	if ( PolyCount < 2 )
		return;
	
	// Transform the first point //
	Vector2D StartPoint = Poly[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	Vector2D LastPoint;
	Vector2D NextPoint = StartPoint;
	
	// For every point in the Polygon //
	for ( size_t idx = 0; idx < PolyCount-1; idx++ ) {
		// Last becomes Next, and transform a new Next //
		LastPoint = NextPoint;
		NextPoint = Poly[idx+1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
		
		// Test if this particular edge is enabled //
		if ( PolygonEnabled[ idx ] ) {
			// Draw the Line //
			line( Target, (int)LastPoint.x, (int)LastPoint.y, (int)NextPoint.x, (int)NextPoint.y, Color );
			
			
			// Take Point A to B //
			Vector2D AB = NextPoint - LastPoint;
			Real Length = AB.NormalizeRet();
			
			// Calculate Center //
			Vector2D Center = LastPoint + (AB * (Length * Real::Half));
		
			// Calculate Normal's position //
			Vector2D Normal = Center + (AB.Tangent() * NormalLength );
			
			// Draw the Normal //
			// TODO: Scale the normals by Matrix //
			line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
		}
	}

	// Draw only if this edge is enabled //
	if ( PolygonEnabled[ PolyCount-1 ] ) {
		// Draw the closing line //
		line( Target, (int)NextPoint.x, (int)NextPoint.y, (int)StartPoint.x, (int)StartPoint.y, Color );
	
		// Take Point A to B //
		Vector2D AB = StartPoint - NextPoint;
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = NextPoint + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (AB.Tangent() * NormalLength );
		
		// Draw the Normal //
		// TODO: Scale the normals by Matrix //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}
}
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixEdgedPolygonWithInvNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const int Color, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
	// Bail if less than 2 points //
	if ( PolyCount < 2 )
		return;
	
	// Transform the first point //
	Vector2D StartPoint = Poly[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	Vector2D LastPoint;
	Vector2D NextPoint = StartPoint;
	
	// For every point in the Polygon //
	for ( size_t idx = 0; idx < PolyCount-1; idx++ ) {
		// Last becomes Next, and transform a new Next //
		LastPoint = NextPoint;
		NextPoint = Poly[idx+1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
		
		// Test if this particular edge is enabled //
		if ( PolygonEnabled[ idx ] ) {
			// Draw the Line //
			line( Target, (int)LastPoint.x, (int)LastPoint.y, (int)NextPoint.x, (int)NextPoint.y, Color );
			
			
			// Take Point A to B //
			Vector2D AB = NextPoint - LastPoint;
			Real Length = AB.NormalizeRet();
			
			// Calculate Center //
			Vector2D Center = LastPoint + (AB * (Length * Real::Half));
		
			// Calculate Normal's position //
			Vector2D Normal = Center + (-AB.Tangent() * NormalLength );
			
			// Draw the Normal //
			// TODO: Scale the normals by Matrix //
			line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
		}
	}

	// Draw only if this edge is enabled //
	if ( PolygonEnabled[ PolyCount-1 ] ) {
		// Draw the closing line //
		line( Target, (int)NextPoint.x, (int)NextPoint.y, (int)StartPoint.x, (int)StartPoint.y, Color );
	
		// Take Point A to B //
		Vector2D AB = StartPoint - NextPoint;
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = NextPoint + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (-AB.Tangent() * NormalLength );
		
		// Draw the Normal //
		// TODO: Scale the normals by Matrix //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void MatrixEdgedPolygonNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
	// Bail if less than 2 points //
	if ( PolyCount < 2 )
		return;
	
	// Transform the first point //
	Vector2D StartPoint = Poly[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	Vector2D LastPoint;
	Vector2D NextPoint = StartPoint;
	
	// For every point in the Polygon //
	for ( size_t idx = 0; idx < PolyCount-1; idx++ ) {
		// Last becomes Next, and transform a new Next //
		LastPoint = NextPoint;
		NextPoint = Poly[idx+1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
		
		// Test if this particular edge is enabled //
		if ( PolygonEnabled[ idx ] ) {
			// Take Point A to B //
			Vector2D AB = NextPoint - LastPoint;
			Real Length = AB.NormalizeRet();
			
			// Calculate Center //
			Vector2D Center = LastPoint + (AB * (Length * Real::Half));
		
			// Calculate Normal's position //
			Vector2D Normal = Center + (AB.Tangent() * NormalLength );
			
			// Draw the Normal //
			// TODO: Scale the normals by Matrix //
			line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
		}
	}

	// Draw only if this edge is enabled //
	if ( PolygonEnabled[ PolyCount-1 ] ) {
		// Take Point A to B //
		Vector2D AB = StartPoint - NextPoint;
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = NextPoint + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (AB.Tangent() * NormalLength );
		
		// Draw the Normal //
		// TODO: Scale the normals by Matrix //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}
}
// - ------------------------------------------------------------------------------------------ - //
inline void MatrixEdgedPolygonInvNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
	// Bail if less than 2 points //
	if ( PolyCount < 2 )
		return;
	
	// Transform the first point //
	Vector2D StartPoint = Poly[0].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	Vector2D LastPoint;
	Vector2D NextPoint = StartPoint;
	
	// For every point in the Polygon //
	for ( size_t idx = 0; idx < PolyCount-1; idx++ ) {
		// Last becomes Next, and transform a new Next //
		LastPoint = NextPoint;
		NextPoint = Poly[idx+1].ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
		
		// Test if this particular edge is enabled //
		if ( PolygonEnabled[ idx ] ) {
			// Take Point A to B //
			Vector2D AB = NextPoint - LastPoint;
			Real Length = AB.NormalizeRet();
			
			// Calculate Center //
			Vector2D Center = LastPoint + (AB * (Length * Real::Half));
		
			// Calculate Normal's position //
			Vector2D Normal = Center + (-AB.Tangent() * NormalLength );
			
			// Draw the Normal //
			// TODO: Scale the normals by Matrix //
			line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
		}
	}

	// Draw only if this edge is enabled //
	if ( PolygonEnabled[ PolyCount-1 ] ) {
		// Take Point A to B //
		Vector2D AB = StartPoint - NextPoint;
		Real Length = AB.NormalizeRet();
		
		// Calculate Center //
		Vector2D Center = NextPoint + (AB * (Length * Real::Half));
	
		// Calculate Normal's position //
		Vector2D Normal = Center + (-AB.Tangent() * NormalLength );
		
		// Draw the Normal //
		// TODO: Scale the normals by Matrix //
		line( Target, (int)Center.x, (int)Center.y, (int)Normal.x, (int)Normal.y, NormalColor );
	}
}
// - ------------------------------------------------------------------------------------------ - //



// - ------------------------------------------------------------------------------------------ - //
#endif // __AllegroGraphics_MatrixDraw_H__ //
// - ------------------------------------------------------------------------------------------ - //
