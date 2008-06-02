// - ------------------------------------------------------------------------------------------ - //
#ifndef __AdvancedGeometry_PointVsPolygon2D_H__
#define __AdvancedGeometry_PointVsPolygon2D_H__
// - ------------------------------------------------------------------------------------------ - //
#include <Math/Vector/Vector2D.h>
#include "PointVsLine2D.h"
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
// Function by Darel Rex Finley - http://alienryderflex.com/polygon/
bool TestPointVsPolygon2D( const Vector2D& Pos, const Vector2D* VsPoint, const size_t VsCount ) {
	// Odd number of nodes //
	bool OddNodes = false;
	
	// Previous Node //	
	size_t j = VsCount - 1;

	// For every side //
	for ( size_t i = 0; i < VsCount; i++ ) {
		// Test if a side crosses the y axis //
		if ( ((VsPoint[i].y < Pos.y) && (VsPoint[j].y >= Pos.y )) || ((VsPoint[j].y < Pos.y) && (VsPoint[i].y >= Pos.y)) ) {
			// TODO: Uhh... I'm not sure. //
			if (VsPoint[i].x + (Pos.y-VsPoint[i].y) / (VsPoint[j].y-VsPoint[i].y) * (VsPoint[j].x-VsPoint[i].x) < Pos.x) {
				OddNodes = !OddNodes;
			}
        }
        // Make j the current point, since i is about it become the next one //
    	j = i;
	}

	// The algorithm says
	return OddNodes;
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline const Vector2D NearestPointOnEdgeOfPolygon2D( const Vector2D& Pos, const Vector2D* VsPoint, const size_t VsCount ) {
	Vector2D Point;
	Real DistanceSquared;
	
	if ( VsCount >= 1 ) {
		Point = NearestPointOnLine2D( Pos, VsPoint[ VsCount - 1 ], VsPoint[ 0 ] );
		DistanceSquared = (Point - Pos).MagnitudeSquared();
		
		for ( size_t idx = 0; idx < VsCount - 1; idx++ ) {
			Vector2D NewPoint = NearestPointOnLine2D( Pos, VsPoint[ idx ], VsPoint[ idx + 1 ] );
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
inline const Vector2D NearestPointOnPolygon2D( const Vector2D& Pos, const Vector2D* VsPoint, const size_t VsCount ) {
	if ( TestPointVsPolygon2D( Pos, VsPoint, VsCount ) ) {
		return Pos;
	}
	else {
		return NearestPointOnEdgeOfPolygon2D( Pos, VsPoint, VsCount );
	}
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
// Get the position of the nearest corner point //
inline const Vector2D NearestCornerPointOnEdgeOfPolygon2D( const Vector2D& Pos, const Vector2D* VsPoint, const size_t VsCount ) {
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
// Get the index of the nearest corner point //
inline const size_t NearestCornerPointIndexOnEdgeOfPolygon2D( const Vector2D& Pos, const Vector2D* VsPoint, const size_t VsCount ) {
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

// - ------------------------------------------------------------------------------------------ - //
// Get the index of the nearest corner point //
inline const int NearestEdgeIndexOfPolygon2D( const Vector2D& Pos, const Vector2D* VsPoint, const size_t VsCount ) {
	size_t Index = -1;
	Vector2D Point;
	Real DistanceSquared;
	
	if ( VsCount >= 1 ) {
		Index = VsCount - 1;
		Point = NearestPointOnLine2D( Pos, VsPoint[ VsCount - 1 ], VsPoint[ 0 ] );
		DistanceSquared = (Point - Pos).MagnitudeSquared();
		
		for ( size_t idx = 0; idx < VsCount - 1; idx++ ) {
			Vector2D NewPoint = NearestPointOnLine2D( Pos, VsPoint[ idx ], VsPoint[ idx + 1 ] );
			Real NewDistanceSquared = (NewPoint - Pos).MagnitudeSquared();
			
			if ( DistanceSquared > NewDistanceSquared ) {
				Index = idx;
				Point = NewPoint;
				DistanceSquared = NewDistanceSquared;
			}
		}
	}
	
	return Index;
}
// - ------------------------------------------------------------------------------------------ - //

inline const Vector2D NearestEdgeNormalOfPolygon2D( const Vector2D& Pos, const Vector2D* VsPoint, const size_t VsCount ) {
	Vector2D Point;
	Real DistanceSquared;
	Vector2D Normal;
	
	if ( VsCount >= 1 ) {
		Point = NearestPointOnLine2D( Pos, VsPoint[ VsCount - 1 ], VsPoint[ 0 ] );
		DistanceSquared = (Point - Pos).MagnitudeSquared();
		Normal = (VsPoint[ VsCount - 1 ] - VsPoint[ 0 ]);
		
		for ( size_t idx = 0; idx < VsCount - 1; idx++ ) {
			Vector2D NewPoint = NearestPointOnLine2D( Pos, VsPoint[ idx ], VsPoint[ idx + 1 ] );
			Real NewDistanceSquared = (NewPoint - Pos).MagnitudeSquared();
			Vector2D NewNormal = (VsPoint[ idx ] - VsPoint[ idx + 1 ]);
			
			if ( DistanceSquared > NewDistanceSquared ) {
				Point = NewPoint;
				DistanceSquared = NewDistanceSquared;
				Normal = NewNormal;
			}
		}
	}
	
	return Normal.Tangent().Normal();	
}


//// - ------------------------------------------------------------------------------------------ - //
//struct cPointVsPolygon2D {
//};
//// - ------------------------------------------------------------------------------------------ - //
//
//// - ------------------------------------------------------------------------------------------ - //
//cPointVsPolygon2D StartPointVsPolygon2D( const Vector2D& Pos, const Vector2D* VsPoint, const size_t VsCount ) {
//	return cPointVsPolygon2D();
//}
//// - ------------------------------------------------------------------------------------------ - //
//bool TestPointVsPolygon2D( const cPointVsPolygon2D& Info ) {
//	return true;
//}
//// - ------------------------------------------------------------------------------------------ - //
//cPointVsPolygon2D SolvePointVsPolygon2D( const cPointVsPolygon2D& Info ) {
//	return cPointVsPolygon2D();
//}
//// - ------------------------------------------------------------------------------------------ - //
//cPointVsPolygon2D SolvePointVsPolygon2D( const Vector2D& Pos, const Vector2D* VsPoint, const size_t VsCount ) {
//	return cPointVsPolygon2D();
//}
//// - ------------------------------------------------------------------------------------------ - //


// - ------------------------------------------------------------------------------------------ - //
// TODO: possibly use http://alienryderflex.com/polygon_fill/
////  public-domain code by Darel Rex Finley, 2007
//
//int  nodes, nodeX[MAX_POLY_CORNERS], pixelX, pixelY, i, j, swap ;
//
////  Loop through the rows of the image.
//for (pixelY=IMAGE_TOP; pixelY<IMAGE_BOT; pixelY++) {
//
//  //  Build a list of nodes.
//  nodes=0; j=polyCorners-1;
//  for (i=0; i<polyCorners; i++) {
//    if (polyY[i]<(double) pixelY && polyY[j]>=(double) pixelY
//    ||  polyY[j]<(double) pixelY && polyY[i]>=(double) pixelY) {
//      nodeX[nodes++]=(int) (polyX[i]+(y-polyY[i])/(polyY[j]-polyY[i])
//      *(polyX[j]-polyX[i])); }
//    j=i; }
//
//  //  Sort the nodes, via a simple �Bubble� sort.
//  i=0;
//  while (i<nodes-1) {
//    if (nodeX[i]>nodeX[i+1]) {
//      swap=nodeX[i]; nodeX[i]=nodeX[i+1]; nodeX[i+1]=swap; if (i) i--; }
//    else {
//      i++; }}
//
//  //  Fill the pixels between node pairs.
//  for (i=0; i<nodes; i+=2) {
//    if   (nodeX[i  ]>=IMAGE_RIGHT) break;
//    if   (nodeX[i+1]> IMAGE_LEFT ) {
//      if (nodeX[i  ]< IMAGE_LEFT ) nodeX[i  ]=IMAGE_LEFT ;
//      if (nodeX[i+1]> IMAGE_RIGHT) nodeX[i+1]=IMAGE_RIGHT;
//      for (j=nodeX[i]; j<nodeX[i+1]; j++) fillPixel(j,pixelY); }}}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
#endif // __AdvancedGeometry_PointVsPolygon2D_H__ //
// - ------------------------------------------------------------------------------------------ - //
