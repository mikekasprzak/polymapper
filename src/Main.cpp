
#include <iostream>

#include <allegro.h>

#include <PolyMap/PolyMap.h>
#include <AdvancedGeometry/PointVsSphere2D.h>
#include <AdvancedGeometry/PointVsPairRect2D.h>
#include <AdvancedGeometry/PointVsShapeRect2D.h>
#include <AdvancedGeometry/PointVsRadiusRect2D.h>

#include <AdvancedGeometry/PointVsPolygon2D.h>
#include <AdvancedGeometry/PointVsEdgedPolygon2D.h>

#include <AllegroDraw/MatrixDraw.h>

using namespace std;

BITMAP* Buffer;

int main( int argc, char* argv[] ) {
//	if ( argc == 1 ) {
//		cout << "No Args" << endl;
//		return -1;
//	}
	
//	cout << "Args" << endl;
	
//	cPolyMap Map( argv[1] );
//	Map.Save( "Wheater.txt" );


	allegro_init();
	install_keyboard();
	install_mouse();
	
	set_color_depth( 16 );
	set_gfx_mode( GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0 );
	Buffer = create_bitmap( 800, 600 );
	
	// Sphere //
	Vector2D DummySphere( 100, 100 );
	Real DummySphereRadius = 32;
	
	// Pair Rectangle //
	Vector2D PairP1( 200, 200 );
	Vector2D PairP2( 400, 300 );
	
	// Shape Rectangle //
	Vector2D ShapeP1( 200, 400 );
	Vector2D ShapeShape( 100, 100 );
	
	// Radius Rectangle //
	Vector2D RadiusCenter( 500, 400 );
	Vector2D RadiusRadius( 20, 30 );
	
	// Polygon //
	Vector2D Poly[5];
	Poly[0] = Vector2D( 400, 100 );
	Poly[1] = Vector2D( 600, 120 );
	Poly[2] = Vector2D( 700, 200 );
	Poly[3] = Vector2D( 650, 300 );
	Poly[4] = Vector2D( 300, 200 );
	
	size_t PolyCount = 5;

	// Edged Polygon //
	Vector2D Poy[5];
	Poy[0] = Vector2D( 400, 300 );
	Poy[1] = Vector2D( 600, 320 );
	Poy[2] = Vector2D( 700, 400 );
	Poy[3] = Vector2D( 650, 500 );
	Poy[4] = Vector2D( 300, 400 );
	
	bool PoyOn[5];
	PoyOn[0] = true;
	PoyOn[1] = false;
	PoyOn[2] = true;
	PoyOn[3] = true;
	PoyOn[4] = true;
	
	size_t PoyCount = 5;
	
	Matrix3x3 Transform;
	Transform(0,0) = 1;
	Transform(1,1) = 1;
	Transform(2,2) = 1;
	
//	Transform(2,0) = 400;
//	Transform(2,1) = 300;
	
	
	while( !key[KEY_ESC] ) {
		clear_to_color( Buffer, makecol(35,0,0) );
		
		Vector2D Mouse(mouse_x, mouse_y);
		circle( Buffer, mouse_x, mouse_y, 2, makecol( 255, 255, 255 ) );
		
		MatrixArrow2( Buffer, Transform, Vector2D(400,300), Mouse, makecol( 255, 255, 0 ) );
		
		// Circle Tests //
		{
			int Color = makecol( 255, 0, 0 );
			
			// If inside the sphere //
			if ( TestPointVsSphere2D( Mouse, DummySphere, DummySphereRadius ) ) {
				Color = makecol( 255, 255, 0 );
			}

			// Draw the Circle //
			circle( Buffer, (int)DummySphere.x, (int)DummySphere.y, (int)DummySphereRadius, Color );
			
			// Nearest point on Circle //
			Vector2D Point = NearestPointOnSphere2D( Mouse, DummySphere, DummySphereRadius );
			circle( Buffer, (int)Point.x, (int)Point.y, 3, makecol( 0, 255, 0 ) );
			
			
			// Nearest point on the edge of the circle //
			Vector2D EdgePoint = NearestPointOnEdgeOfSphere2D( Mouse, DummySphere, DummySphereRadius );
			circle( Buffer, (int)EdgePoint.x, (int)EdgePoint.y, 5, makecol( 0, 255, 0 ) );
		}
		
		// PairRect Tests //
		{
			int Color = makecol( 255, 0, 0 );
			
			// If inside the Rect //
			if ( TestPointVsPairRect2D( Mouse, PairP1, PairP2 ) ) {
				Color = makecol( 255, 255, 0 );
			}
			
			// Draw the Rect //
			//rect( Buffer, (int)PairP1.x, (int)PairP1.y, (int)PairP2.x, (int)PairP2.y, Color );
			MatrixRectWithNormals( Buffer, Transform, Rect2D::Pair( PairP1, PairP2 ), Color );
			
			
			// Nearest point on Rect //
			Vector2D Point = NearestPointOnPairRect2D( Mouse, PairP1, PairP2 );
			circle( Buffer, (int)Point.x, (int)Point.y, 3, makecol( 0, 255, 0 ) );
			
			// Nearest point on the edge of the Rect //
			Vector2D EdgePoint = NearestPointOnEdgeOfPairRect2D( Mouse, PairP1, PairP2 );
			circle( Buffer, (int)EdgePoint.x, (int)EdgePoint.y, 5, makecol( 0, 255, 0 ) );

			// Nearest point on the edge of the Rect //
			Vector2D CornerPoint = NearestCornerPointOnEdgeOfPairRect2D( Mouse, PairP1, PairP2 );
			RadiusBox( Buffer, CornerPoint, 7, makecol( 255, 255, 0 ) );
		}
		
		// ShapeRect Tests //
		{
			int Color = makecol( 255, 0, 0 );
			
			// If inside the Rect //
			if ( TestPointVsShapeRect2D( Mouse, ShapeP1, ShapeShape ) ) {
				Color = makecol( 255, 255, 0 );
			}
			
			// Draw the Rect //
			rect( Buffer, (int)ShapeP1.x, (int)ShapeP1.y, (int)ShapeP1.x + ShapeShape.x, (int)ShapeP1.y + ShapeShape.y, Color );
			
			
			// Nearest point on Rect //
			Vector2D Point = NearestPointOnShapeRect2D( Mouse, ShapeP1, ShapeShape );
			circle( Buffer, (int)Point.x, (int)Point.y, 3, makecol( 0, 255, 0 ) );
			
			// Nearest point on the edge of the Rect //
			Vector2D EdgePoint = NearestPointOnEdgeOfShapeRect2D( Mouse, ShapeP1, ShapeShape );
			circle( Buffer, (int)EdgePoint.x, (int)EdgePoint.y, 5, makecol( 0, 255, 0 ) );

			// Nearest point on the edge of the Rect //
			Vector2D CornerPoint = NearestCornerPointOnEdgeOfShapeRect2D( Mouse, ShapeP1, ShapeShape );
			RadiusBox( Buffer, CornerPoint, 7, makecol( 255, 255, 0 ) );
		}
		
		// RadiusRect Tests //
		{
			int Color = makecol( 255, 0, 0 );
			
			// If inside the Rect //
			if ( TestPointVsRadiusRect2D( Mouse, RadiusCenter, RadiusRadius ) ) {
				Color = makecol( 255, 255, 0 );
			}
			
			// Draw the Rect //
			rect( Buffer, (int)RadiusCenter.x - RadiusRadius.x, (int)RadiusCenter.y - RadiusRadius.y, (int)RadiusCenter.x + RadiusRadius.x, (int)RadiusCenter.y + RadiusRadius.y, Color );
			
			
			// Nearest point on Rect //
			Vector2D Point = NearestPointOnRadiusRect2D( Mouse, RadiusCenter, RadiusRadius );
			circle( Buffer, (int)Point.x, (int)Point.y, 3, makecol( 0, 255, 0 ) );
			
			// Nearest point on the edge of the Rect //
			Vector2D EdgePoint = NearestPointOnEdgeOfRadiusRect2D( Mouse, RadiusCenter, RadiusRadius );
			circle( Buffer, (int)EdgePoint.x, (int)EdgePoint.y, 5, makecol( 0, 255, 0 ) );

			// Nearest point on the edge of the Rect //
			Vector2D CornerPoint = NearestCornerPointOnEdgeOfRadiusRect2D( Mouse, RadiusCenter, RadiusRadius );
			RadiusBox( Buffer, CornerPoint, 7, makecol( 255, 255, 0 ) );
		}

		// Polygon Tests //
		{
			// Draw the Polygon //
			int Color = makecol( 255, 0, 0 );
			
			// If inside the Polygon //
			if ( TestPointVsPolygon2D( Mouse, Poly, PolyCount ) ) {
				Color = makecol( 255, 255, 0 );
			}
			
			// Draw the Polygon //
			MatrixClosedPolygonWithNormals( Buffer, Transform, Poly, PolyCount, Color );
			MatrixPolygonEdge( 
				Buffer,
				Transform,
				NearestEdgeIndexOfPolygon2D( Mouse, Poly, PolyCount ),
				Poly,
				PolyCount,
				makecol(255, 255, 255 )
				);
			
			// Nearest point on Polygon //
			Vector2D Point = NearestPointOnPolygon2D( Mouse, Poly, PolyCount );
			circle( Buffer, (int)Point.x, (int)Point.y, 3, makecol( 0, 255, 0 ) );
			
			// Nearest point on the edge of the Polygon //
			Vector2D EdgePoint = NearestPointOnEdgeOfPolygon2D( Mouse, Poly, PolyCount );
			circle( Buffer, (int)EdgePoint.x, (int)EdgePoint.y, 5, makecol( 0, 255, 0 ) );

			// Nearest point on the edge of the Polygon //
			Vector2D CornerPoint = NearestCornerPointOnEdgeOfPolygon2D( Mouse, Poly, PolyCount );
			RadiusBox( Buffer, CornerPoint, 7, makecol( 255, 255, 0 ) );
		}

		// Edged Polygon Tests //
		{
			// Draw the Polygon //
			int Color = makecol( 255, 0, 0 );
			
			// If inside the Polygon //
			if ( TestPointVsEdgedPolygon2D( Mouse, Poy, PoyOn, PoyCount ) ) {
				Color = makecol( 255, 255, 0 );
			}
			
			// Draw the Polygon //
			MatrixEdgedPolygonWithNormals( Buffer, Transform, Poy, PoyOn, PoyCount, Color );
			
			int Edge = NearestEdgeIndexOfEdgedPolygon2D( Mouse, Poy, PoyOn, PoyCount );
			if ( Edge != -1 ) {
				if ( PoyOn[Edge] ) {
					MatrixPolygonEdge( 
						Buffer,
						Transform,
						Edge,
						Poy,
						PoyCount,
						makecol( 255, 255, 255 )
						);
				}
			}
			
			// Nearest point on Polygon //
			Vector2D Point = NearestPointOnEdgedPolygon2D( Mouse, Poy, PoyOn, PoyCount );
			circle( Buffer, (int)Point.x, (int)Point.y, 3, makecol( 0, 255, 0 ) );
			
			// Nearest point on the edge of the Polygon //
			Vector2D EdgePoint = NearestPointOnEdgeOfEdgedPolygon2D( Mouse, Poy, PoyOn, PoyCount );
			circle( Buffer, (int)EdgePoint.x, (int)EdgePoint.y, 5, makecol( 0, 255, 0 ) );

			// Nearest point on the edge of the Polygon //
			Vector2D CornerPoint = NearestCornerPointOnEdgeOfEdgedPolygon2D( Mouse, Poy, PoyOn, PoyCount );
			RadiusBox( Buffer, CornerPoint, 7, makecol( 255, 255, 0 ) );
		}

		
		vsync();
		rest(0);
		
		blit( Buffer, screen, 0, 0, 0, 0, Buffer->w, Buffer->h );
	}
	
	allegro_exit();
	return 0;
}
END_OF_MAIN();
