// - ------------------------------------------------------------------------------------------ - //
#ifndef __AllegroGraphics_MatrixDraw3D_H__
#define __AllegroGraphics_MatrixDraw3D_H__
// - ------------------------------------------------------------------------------------------ - //
#include <Allegro.h>
// - ------------------------------------------------------------------------------------------ - //
#include <Math/Vector.h>
#include <Math/Matrix.h>
#include <Geometry/Rect.h>
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline void MatrixClosedPolygon( BITMAP* Target, const Matrix3x3& Matrix, const Vector3D* Poly, const size_t PolyCount, const int Color ) {
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
inline void MatrixOpenPolygon( BITMAP* Target, const Matrix3x3& Matrix, const Vector3D* Poly, const size_t PolyCount, const int Color ) {
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
inline void MatrixPolygonEdge( BITMAP* Target, const Matrix3x3& Matrix, const int Index, const Vector3D* Poly, const size_t PolyCount, const int Color ) {
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
inline void MatrixClosedPolygonWithNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector3D* Poly, const size_t PolyCount, const int Color, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
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
inline void MatrixClosedPolygonWithInvNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector3D* Poly, const size_t PolyCount, const int Color, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
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
inline void MatrixOpenPolygonWithNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector3D* Poly, const size_t PolyCount, const int Color, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
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
inline void MatrixOpenPolygonWithInvNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector3D* Poly, const size_t PolyCount, const int Color, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
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
inline void MatrixClosedPolygonNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector3D* Poly, const size_t PolyCount, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
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
inline void MatrixClosedPolygonInvNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector3D* Poly, const size_t PolyCount, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
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
inline void MatrixOpenPolygonNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector3D* Poly, const size_t PolyCount, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
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
inline void MatrixOpenPolygonInvNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector3D* Poly, const size_t PolyCount, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
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
inline void MatrixEdgedPolygon( BITMAP* Target, const Matrix3x3& Matrix, const Vector3D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const int Color ) {
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
inline void MatrixEdgedPolygonWithNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector3D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const int Color, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
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
inline void MatrixEdgedPolygonWithInvNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector3D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const int Color, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
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
inline void MatrixEdgedPolygonNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector3D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
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
inline void MatrixEdgedPolygonInvNormals( BITMAP* Target, const Matrix3x3& Matrix, const Vector3D* Poly, const bool* PolygonEnabled, const size_t PolyCount, const Real NormalLength = 8, const int NormalColor = makecol(255,255,255) ) {
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
