// - ------------------------------------------------------------------------------------------ - //
#ifndef __AdvancedGeometry_PointVsLine2D_H__
#define __AdvancedGeometry_PointVsLine2D_H__
// - ------------------------------------------------------------------------------------------ - //
#include <Math/Vector/Vector2D.h>
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
//inline const Vector2D NearestPointOnLine2D( const Vector2D& p, const Vector2D& a, const Vector2D& b ) {
//	Vector2D ab = b - a;
//	Vector2D pa = a - p;
//	
//	Vector2D abNormal = ab;
//	Real Width = abNormal.NormalizeRet();
//	
//	Real pdLength = pa * abNormal.Tangent();
//	
//	Vector2D d = p - (abNormal.Tangent() * pdLength);
//	
//	Vector2D ad = d - a;
//	
//	Real Offset = ad * abNormal;
//	
//	if ( Offset < Real::Zero ) {
//		return a;
//	}
//	else if ( Offset > Width ) {
//		return b;
//	}
//	else {
//		return a + (abNormal * Offset);
//	}
//}
// - ------------------------------------------------------------------------------------------ - //


// - ------------------------------------------------------------------------------------------ - //
struct cNearest_PointInfo_On_Line2D {
	Vector2D Point;
	
	Vector2D Line;
	Vector2D LineNormal;
	Real LineLength;
	
	Vector2D CornerToPoint;
	Real DistanceOnLine;
};
// - ------------------------------------------------------------------------------------------ - //
inline const cNearest_PointInfo_On_Line2D Nearest_PointInfo_On_Line2D( const Vector2D& p, const Vector2D& a, const Vector2D& b ) {
	cNearest_PointInfo_On_Line2D Info;
	
	// Calculate our notable rays //
	Info.Line = b - a; // ab //
	Info.CornerToPoint = p - a; // ap //

	// Normalize and Store the Line Normal and Length //
	Info.LineNormal = Info.Line;
	Info.LineLength = Info.LineNormal.NormalizeRet();

	// Calculate how far 
	Info.DistanceOnLine = Info.CornerToPoint * Info.LineNormal;
	
	// Set Point to a position on the line //
	if ( Info.DistanceOnLine < Real::Zero ) {
		Info.Point = a;
	}
	else if ( Info.DistanceOnLine > Info.LineLength ) {
		Info.Point = b;
	}
	else {
		Info.Point = a + (Info.LineNormal * Info.DistanceOnLine);
	}
	
	// Return the Info Structure //
	return Info;
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline const Vector2D Nearest_Point_On_Line2D( const Vector2D& p, const Vector2D& a, const Vector2D& b ) {
	cNearest_PointInfo_On_Line2D Info = Nearest_PointInfo_On_Line2D( p, a, b );
	return Info.Point;
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
#endif // __AdvancedGeometry_PointVsLine2D_H__ //
// - ------------------------------------------------------------------------------------------ - //
