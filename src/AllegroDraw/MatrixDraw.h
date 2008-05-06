// - ------------------------------------------------------------------------------------------ - //
#ifndef __AllegroDraw_MatrixDraw_H__
#define __AllegroDraw_MatrixDraw_H__
// - ------------------------------------------------------------------------------------------ - //
#include <Math/Vector/Vector2D.h>
#include <Math/Matrix.h>
#include <Geometry/Rect.h>
// - ------------------------------------------------------------------------------------------ - //
void MatrixRect( BITMAP* Target, const Matrix3x3& Matrix, const Rect2D& Rect, const int Color ) {
	// Get our points //
	Vector2D Point[4];
	Point[0] = Rect.P1();
	Point[1] = Vector2D( Rect.P2().x, Rect.P1().y );
	Point[2] = Rect.P2();
	Point[3] = Vector2D( Rect.P1().x, Rect.P2().y );
	
	// Transform them by the matrix //
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
void MatrixLine( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D& P1, const Vector2D& P2, const int Color ) {
	// Get our points //
	Vector2D Point[2];
	
	// Transform them by the matrix //
	Point[0] = P1.ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	Point[1] = P2.ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	// Draw our line //
	line( Target, (int)(Point[0].x), (int)(Point[0].y), (int)(Point[1].x), (int)(Point[1].y), Color );
}
// - ------------------------------------------------------------------------------------------ - //
void MatrixArrow( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D& P1, const Vector2D& P2, const int Color, const Real HeadSize = 8 ) {
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
	HeadPoint *= HeadSize;
	
	// Draw the Arrowhead on P2 //
	line( Target, (int)((HeadPoint.Rotate45() + Point[1]).x), (int)((HeadPoint.Rotate45() + Point[1]).y), (int)(Point[1].x), (int)(Point[1].y), Color );
	line( Target, (int)((HeadPoint.RotateNegative45() + Point[1]).x), (int)((HeadPoint.RotateNegative45() + Point[1]).y), (int)(Point[1].x), (int)(Point[1].y), Color );
}
// - ------------------------------------------------------------------------------------------ - //
void MatrixArrow2( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D& P1, const Vector2D& P2, const int Color, const Real HeadSize = 8 ) {
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
	HeadPoint *= HeadSize;
	
	// Draw the Arrowheads //
	line( Target, (int)((HeadPoint.Rotate45() + Point[1]).x), (int)((HeadPoint.Rotate45() + Point[1]).y), (int)(Point[1].x), (int)(Point[1].y), Color );
	line( Target, (int)((HeadPoint.RotateNegative45() + Point[1]).x), (int)((HeadPoint.RotateNegative45() + Point[1]).y), (int)(Point[1].x), (int)(Point[1].y), Color );

	line( Target, (int)((-HeadPoint.Rotate45() + Point[0]).x), (int)((-HeadPoint.Rotate45() + Point[0]).y), (int)(Point[0].x), (int)(Point[0].y), Color );
	line( Target, (int)((-HeadPoint.RotateNegative45() + Point[0]).x), (int)((-HeadPoint.RotateNegative45() + Point[0]).y), (int)(Point[0].x), (int)(Point[0].y), Color );
}
// - ------------------------------------------------------------------------------------------ - //
void MatrixCircle( BITMAP* Target, const Matrix3x3& Matrix, const Vector2D& Pos, const Real& Radius, const int Color ) {
	// Transform our point by the matrix //
	Vector2D Point = Pos.ToHomoVector3D().ApplyMatrix( Matrix ).ToVector2D();
	
	// Draw our circle //
	circle( Target, (int)Point.x, (int)Point.y, (int)Radius, Color );
	
	// TODO: use the matrix somehow to calculate the scale, and scale up/down the radius
}
// - ------------------------------------------------------------------------------------------ - //
#endif // __AllegroDraw_MatrixDraw_H__ //
// - ------------------------------------------------------------------------------------------ - //
