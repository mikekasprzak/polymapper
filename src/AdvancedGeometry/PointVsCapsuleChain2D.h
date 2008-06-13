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
//	Vector2D Point;
//	Real DistanceSquared;
//	Vector2D Normal;
//	
//	if ( VsCount >= 1 ) {
//		Point = NearestPointOnLine2D( Pos, VsPoint[ VsCount - 1 ], VsPoint[ 0 ] );
//		DistanceSquared = (Point - Pos).MagnitudeSquared();
//		Normal = (VsPoint[ VsCount - 1 ] - VsPoint[ 0 ]);
//		
//		for ( size_t idx = 0; idx < VsCount - 1; idx++ ) {
//			Vector2D NewPoint = NearestPointOnLine2D( Pos, VsPoint[ idx ], VsPoint[ idx + 1 ] );
//			Real NewDistanceSquared = (NewPoint - Pos).MagnitudeSquared();
//			Vector2D NewNormal = (VsPoint[ idx ] - VsPoint[ idx + 1 ]);
//			
//			if ( DistanceSquared > NewDistanceSquared ) {
//				Point = NewPoint;
//				DistanceSquared = NewDistanceSquared;
//				Normal = NewNormal;
//			}
//		}
//	}
//	
//	return Point + (Normal.Tangent().Normal() * VsRadius);
	cNearestEdgePointOnChain2DInfo Info = NearestEdgePointInfoOnChain2D( Pos, VsPoint, VsCount );
	return Info.Point + (Info.Normal * VsRadius);
}
// - ------------------------------------------------------------------------------------------ - //
// Get the nearest Outer Edge Point //
inline const Vector2D NearestOuterEdgePointOnCapsuleChain2D( const Vector2D& Pos, const Vector2D* VsPoint, const size_t VsCount, const Real VsRadius ) {
//	Vector2D Point;
//	Real DistanceSquared;
//	Vector2D Normal;
//	
//	if ( VsCount >= 1 ) {
//		Point = NearestPointOnLine2D( Pos, VsPoint[ VsCount - 1 ], VsPoint[ 0 ] );
//		DistanceSquared = (Point - Pos).MagnitudeSquared();
//		Normal = (VsPoint[ VsCount - 1 ] - VsPoint[ 0 ]);
//		
//		for ( size_t idx = 0; idx < VsCount - 1; idx++ ) {
//			Vector2D NewPoint = NearestPointOnLine2D( Pos, VsPoint[ idx ], VsPoint[ idx + 1 ] );
//			Real NewDistanceSquared = (NewPoint - Pos).MagnitudeSquared();
//			Vector2D NewNormal = (VsPoint[ idx ] - VsPoint[ idx + 1 ]);
//			
//			if ( DistanceSquared > NewDistanceSquared ) {
//				Point = NewPoint;
//				DistanceSquared = NewDistanceSquared;
//				Normal = NewNormal;
//			}
//		}
//	}
//	
//	return Point + ((-Normal.Tangent().Normal()) * VsRadius);
	cNearestEdgePointOnChain2DInfo Info = NearestEdgePointInfoOnChain2D( Pos, VsPoint, VsCount );
	return Info.Point + (-Info.Normal * VsRadius);
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
#endif // __AdvancedGeometry_PointVsCapsuleChain2D_H__ //
// - ------------------------------------------------------------------------------------------ - //
