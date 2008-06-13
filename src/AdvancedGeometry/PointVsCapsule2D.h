// - ------------------------------------------------------------------------------------------ - //
#ifndef __AdvancedGeometry_PointVsCapsule2D_H__
#define __AdvancedGeometry_PointVsCapsule2D_H__
// - ------------------------------------------------------------------------------------------ - //
#include <Math/Vector/Vector2D.h>
#include "PointVsLine2D.h"
#include "PointVsSphere2D.h"
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
inline const bool TestPointVsCapsule2D( const Vector2D& Pos, const Vector2D& VsA, const Vector2D& VsB, const Real VsRadius ) {
	Vector2D VsPoint = NearestPointOnLine2D( Pos, VsA, VsB );
	return TestPointVsSphere2D( Pos, VsPoint, VsRadius );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
#endif // __AdvancedGeometry_PointVsCapsule2D_H__ //
// - ------------------------------------------------------------------------------------------ - //
