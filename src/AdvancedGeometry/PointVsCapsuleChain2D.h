// - ------------------------------------------------------------------------------------------ - //
#ifndef __AdvancedGeometry_PointVsCapsuleChain2D_H__
#define __AdvancedGeometry_PointVsCapsuleChain2D_H__
// - ------------------------------------------------------------------------------------------ - //
#include <Math/Vector/Vector2D.h>
#include "PointVsChain2D.h"
#include "PointVsSphere2D.h"
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline const bool TestPointVsCapsuleChain2D( const Vector2D& Pos, const Vector2D* VsPoints, const size_t VsCount, const Real VsRadius ) {
	Vector2D VsPoint = NearestPointOnChain2D( Pos, VsPoints, VsCount );
	return TestPointVsSphere2D( Pos, VsPoint, VsRadius );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
// Get the nearest Inner Edge Point //
inline const Vector2D NearestInnerEdgePointOnCapsuleChain2D( const Vector2D& Pos, const Vector2D* VsPoint, const size_t VsCount, const Real VsRadius ) {
	cNearestEdgePointOnChain2DInfo Info = NearestEdgePointInfoOnChain2D( Pos, VsPoint, VsCount );
	return Info.Point + (Info.Normal * VsRadius);
}
// - ------------------------------------------------------------------------------------------ - //
// Get the nearest Outer Edge Point //
inline const Vector2D NearestOuterEdgePointOnCapsuleChain2D( const Vector2D& Pos, const Vector2D* VsPoint, const size_t VsCount, const Real VsRadius ) {
	cNearestEdgePointOnChain2DInfo Info = NearestEdgePointInfoOnChain2D( Pos, VsPoint, VsCount );
	return Info.Point + (-Info.Normal * VsRadius);
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
#endif // __AdvancedGeometry_PointVsCapsuleChain2D_H__ //
// - ------------------------------------------------------------------------------------------ - //
