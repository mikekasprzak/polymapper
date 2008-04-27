// - ------------------------------------------------------------------------------------------ - //
#ifndef __AdvancedGeometry_PointVsPairRect2D_H__
#define __AdvancedGeometry_PointVsPairRect2D_H__
// - ------------------------------------------------------------------------------------------ - //
#include <Math/Vector/Vector2D.h>
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
// NOTE: P2's components must be larger than P1's. //
bool TestPointVsPairRect2D( const Vector2D& v, const Vector2D& P1, const Vector2D& P2 ) {
	if ( v.x >= P1.x )
		if ( v.x < P2.x )
			if ( v.y >= P1.y )
				return ( v.y < P2.y );
	return false;
}
// - ------------------------------------------------------------------------------------------ - //
// NOTE: P2's components must be larger than P1's. //
inline const Vector2D NearestPointOnPairRect2D( const Vector2D& v, const Vector2D& P1, const Vector2D& P2 ) {
	Vector2D Point;

	if ( v.x < P1.x )
		Point.x = P1.x;
	else if ( v.x > P2.x )
		Point.x = P2.x;
	else
		Point.x = v.x;

	if ( v.y < P1.y )
		Point.y = P1.y;
	else if ( v.y > P2.y )
		Point.y = P2.y;
	else
		Point.y = v.y;

	return Point;
}
// - ------------------------------------------------------------------------------------------ - //
// NOTE: Does not require that P2 be larger than P2. //
inline const Vector2D NearestCornerPointOnEdgeOfPairRect2D( const Vector2D& v, const Vector2D& P1, const Vector2D& P2 ) {
	Vector2D Point;

	if ( (v.x - P1.x).Abs() < (v.x - P2.x).Abs() )
		Point.x = P1.x;
	else
		Point.x = P2.x;

	if ( (v.y - P1.y).Abs() < (v.y - P2.y).Abs() )
		Point.y = P1.y;
	else
		Point.y = P2.y;

	return Point;
}
// - ------------------------------------------------------------------------------------------ - //
// NOTE: Does not require that P2 be larger than P2. //
inline const size_t NearestCornerPointIndexOnEdgeOfPairRect2D( const Vector2D& v, const Vector2D& P1, const Vector2D& P2 ) {
	size_t Index = 0;

	if ( (v.x - P1.x).Abs() < (v.x - P2.x).Abs() )
		Index |= 0;
	else
		Index |= 1;

	if ( (v.y - P1.y).Abs() < (v.y - P2.y).Abs() )
		Index |= 0;
	else
		Index |= 2;

	return Index;
}
// - ------------------------------------------------------------------------------------------ - //
// NOTE: Does not require that P2 be larger than P2. //
inline const Vector2D NearestPointOnEdgeOfPairRect2D( const Vector2D& v, const Vector2D& P1, const Vector2D& P2 ) {
	Vector2D Point = NearestPointOnPairRect2D( v, P1, P2 );
	
	// If we're inside //
	if ( Point == v ) {
		Vector2D Corner;
		Vector2D Length;
		
		// Note the best edge, and distance to it //
		if ( (v.x - P1.x).Abs() < (v.x - P2.x).Abs() ) {
			Corner.x = P1.x;
			Length.x = (v.x - P1.x).Abs();
		}
		else {
			Corner.x = P2.x;
			Length.x = (v.x - P2.x).Abs();
		}
	
		if ( (v.y - P1.y).Abs() < (v.y - P2.y).Abs() ) {
			Corner.y = P1.y;
			Length.y = (v.y - P1.y).Abs();
		}
		else {
			Corner.y = P2.y;
			Length.y = (v.y - P2.y).Abs();
		}
	
		// Depending which length is longer, align that axis //
		if ( Length.x > Length.y ) {
			Point.y = Corner.y;
		}
		else {
			Point.x = Corner.x;
		}
	}

	return Point;
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
#endif // __AdvancedGeometry_PointVsPairRect2D_H__ //
// - ------------------------------------------------------------------------------------------ - //
