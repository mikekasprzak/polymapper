// - ------------------------------------------------------------------------------------------ - //
#ifndef __AdvancedGeometry_PointVsChain2D_H__
#define __AdvancedGeometry_PointVsChain2D_H__
// - ------------------------------------------------------------------------------------------ - //
#include <Math/Vector/Vector2D.h>
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline const Vector2D NearestPointOnChain2D( const Vector2D& Pos, const Vector2D* VsPoint, const size_t VsCount ) {
	Vector2D Point;
	Real DistanceSquared;
	
	if ( VsCount >= 1 ) {
		Point = Nearest_Point_On_Line2D( Pos, VsPoint[ VsCount - 1 ], VsPoint[ 0 ] );
		DistanceSquared = (Point - Pos).MagnitudeSquared();
		
		for ( size_t idx = 0; idx < VsCount - 1; idx++ ) {
			Vector2D NewPoint = Nearest_Point_On_Line2D( Pos, VsPoint[ idx ], VsPoint[ idx + 1 ] );
			Real NewDistanceSquared = (NewPoint - Pos).MagnitudeSquared();
			
			if ( DistanceSquared > NewDistanceSquared ) {
				Point = NewPoint;
				DistanceSquared = NewDistanceSquared;
			}
		}
	}
	
	return Point;
}
// - ------------------------------------------------------------------------------------------ - //
// Get the position of the nearest corner point //
inline const Vector2D NearestCornerPointOnChain2D( const Vector2D& Pos, const Vector2D* VsPoint, const size_t VsCount ) {
	Vector2D Point;
	Real DistanceSquared;
	
	if ( VsCount >= 1 ) {
		Point = VsPoint[ 0 ];
		DistanceSquared = (Point - Pos).MagnitudeSquared();
		
		for ( size_t idx = 1; idx < VsCount; idx++ ) {
			Real NewDistanceSquared = (VsPoint[ idx ] - Pos).MagnitudeSquared();
			if ( DistanceSquared > NewDistanceSquared ) {
				Point = VsPoint[ idx ];
				DistanceSquared = NewDistanceSquared;
			}
		}
	}
	
	return Point;
}
// - ------------------------------------------------------------------------------------------ - //


// - ------------------------------------------------------------------------------------------ - //
struct cNearestEdgePointInfoOnChain2D {
	Vector2D Point;
	Vector2D Normal;
	
	Real EdgeDistanceSquared;
	int EdgeIndex;
	
	inline const Real EdgeDistance() const {
		return EdgeDistanceSquared.Sqrt();
	}
};
// - ------------------------------------------------------------------------------------------ - //
// Get the nearest Inner Edge Point //
inline const cNearestEdgePointInfoOnChain2D NearestEdgePointInfoOnChain2D( const Vector2D& Pos, const Vector2D* VsPoint, const size_t VsCount ) {
	cNearestEdgePointInfoOnChain2D Info;
	
	if ( VsCount >= 1 ) {
		Info.Point = Nearest_Point_On_Line2D( Pos, VsPoint[ VsCount - 1 ], VsPoint[ 0 ] );
		Info.Normal = (VsPoint[ VsCount - 1 ] - VsPoint[ 0 ]);
		Info.EdgeDistanceSquared = (Info.Point - Pos).MagnitudeSquared();
		Info.EdgeIndex = VsCount - 1;
		
		for ( size_t idx = 0; idx < VsCount - 1; idx++ ) {
			Vector2D NewPoint = Nearest_Point_On_Line2D( Pos, VsPoint[ idx ], VsPoint[ idx + 1 ] );
			Real NewDistanceSquared = (NewPoint - Pos).MagnitudeSquared();
			
			if ( Info.EdgeDistanceSquared > NewDistanceSquared ) {
				Info.Point = NewPoint;
				Info.Normal = (VsPoint[ idx ] - VsPoint[ idx + 1 ]);
				Info.EdgeDistanceSquared = NewDistanceSquared;
				Info.EdgeIndex = idx;
			}
		}
	}
	
	// Actually calculate the Normal //
	Info.Normal = Info.Normal.Tangent().Normal();
	
	return Info;
}
// - ------------------------------------------------------------------------------------------ - //



// - ------------------------------------------------------------------------------------------ - //
// Get the index of the nearest corner point //
inline const size_t NearestCornerPointIndexOnChain2D( const Vector2D& Pos, const Vector2D* VsPoint, const size_t VsCount ) {
	size_t Index;
	Real DistanceSquared;
	
	if ( VsCount >= 1 ) {
		Index = 0;
		DistanceSquared = (VsPoint[ 0 ] - Pos).MagnitudeSquared();
		
		for ( size_t idx = 1; idx < VsCount; idx++ ) {
			Real NewDistanceSquared = (VsPoint[ idx ] - Pos).MagnitudeSquared();
			if ( DistanceSquared > NewDistanceSquared ) {
				Index = idx;
				DistanceSquared = NewDistanceSquared;
			}
		}
	}
	
	return Index;
}
// - ------------------------------------------------------------------------------------------ - //
// Get the index of the nearest edge //
inline const int NearestEdgeIndexOfChain2D( const Vector2D& Pos, const Vector2D* VsPoint, const size_t VsCount ) {
	cNearestEdgePointInfoOnChain2D Info = NearestEdgePointInfoOnChain2D( Pos, VsPoint, VsCount );
	return Info.EdgeIndex;
}
// - ------------------------------------------------------------------------------------------ - //


// - ------------------------------------------------------------------------------------------ - //
// Get the nearest Edge Normal //
inline const Vector2D NearestEdgeNormalOfChain2D( const Vector2D& Pos, const Vector2D* VsPoint, const size_t VsCount ) {
	cNearestEdgePointInfoOnChain2D Info = NearestEdgePointInfoOnChain2D( Pos, VsPoint, VsCount );
	return Info.Normal;
}
// - ------------------------------------------------------------------------------------------ - //


// - ------------------------------------------------------------------------------------------ - //
#endif // __AdvancedGeometry_PointVsChain2D_H__ //
// - ------------------------------------------------------------------------------------------ - //
