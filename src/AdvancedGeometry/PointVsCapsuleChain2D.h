// - ------------------------------------------------------------------------------------------ - //
#ifndef __AdvancedGeometry_PointVsCapsuleChain2D_H__
#define __AdvancedGeometry_PointVsCapsuleChain2D_H__
// - ------------------------------------------------------------------------------------------ - //
#include <Math/Vector/Vector2D.h>
#include "PointVsChain2D.h"
#include "PointVsSphere2D.h"
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline const bool Test_Point_Vs_CapsuleChain2D( const Vector2D& Pos, const Vector2D* VsPoints, const size_t VsCount, const Real VsRadius ) {
	Vector2D VsPoint = Nearest_Point_On_Chain2D( Pos, VsPoints, VsCount );
	return Test_Point_Vs_Sphere2D( Pos, VsPoint, VsRadius );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
// Get the nearest Inner Edge Point //
inline const Vector2D Nearest_InnerEdgePoint_On_CapsuleChain2D( const Vector2D& Pos, const Vector2D* VsPoint, const size_t VsCount, const Real VsRadius ) {
	cNearest_PointInfo_On_Chain2D Info = Nearest_PointInfo_On_Chain2D( Pos, VsPoint, VsCount );
	return Info.Point + (Info.Normal * VsRadius);
}
// - ------------------------------------------------------------------------------------------ - //
// Get the nearest Outer Edge Point //
inline const Vector2D Nearest_OuterEdgePoint_On_CapsuleChain2D( const Vector2D& Pos, const Vector2D* VsPoint, const size_t VsCount, const Real VsRadius ) {
	cNearest_PointInfo_On_Chain2D Info = Nearest_PointInfo_On_Chain2D( Pos, VsPoint, VsCount );
	return Info.Point + (-Info.Normal * VsRadius);
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
#endif // __AdvancedGeometry_PointVsCapsuleChain2D_H__ //
// - ------------------------------------------------------------------------------------------ - //
