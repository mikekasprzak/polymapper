// - ------------------------------------------------------------------------------------------ - //
// Generic game geometry info file //
// - ------------------------------------------------------------------------------------------ - //
#ifndef __PolyMap_H__
#define __PolyMap_H__
// - ------------------------------------------------------------------------------------------ - //
#include <vector>
#include <map>
#include <string>

#include <Math/Vector/Vector2D.h>
// - ------------------------------------------------------------------------------------------ - //
// Enumerations for Element Type //
enum {
	PME_NODE = 1,
	PME_SPHERE,
	PME_RECT,
	PME_POLY,
//	PME_ORECT,
//	PME_CURVE,
//	PME_BONE,
	
	PME_END
};
// - ------------------------------------------------------------------------------------------ - //
class cPolyMapElement {
public:
	// What type of element it is (Node, Sphere, Rectangle, Polygon, etc...)
	size_t Type;
	
	// Center position //
	Vector2D Center;
	
	// All vertices found in the element (Node - unused) //
	std::vector< Vector2D > Vertex;
	
	// A type for the arbitrary data section, Data //	
	union PMEData {
		float f;
		int i;
		unsigned int u;
		unsigned char b[4];
		char c[4];
		short s[2];
		unsigned short w[2];
	};
	
	// The arbitrary data section //
	std::vector< PMEData > Data;
	
	// The type of our strings table (optional) //
	class StringEntry {
	public:
		std::string Name;
		size_t Offset;
	};
	
	// The strings table.  The new "nice" way to note additional properties. //
	std::vector< StringEntry > String;
	
	// The type of the type.  Is it a collision polygon, or a safe zone polygon? //
	size_t Id;
	
	// Additional information/subcategorization of the element (argument) //
	//int Info;

public:
	cPolyMapElement() :
		Type( 0 ),
		Id( 0 )
	{
	}
	
	cPolyMapElement( const size_t _Type ) :
		Type( _Type ),
		Id( 0 )
	{
	}
	
public:
	void UpdateCenter() {
		switch (Type) {
			case PME_RECT: {
				if ( Vertex.size() ) {
					Center = Vertex[0] + ((Vertex[1] - Vertex[0]) * Real::Half);
				}
				break;
			}
			case PME_POLY: {
				if ( Vertex.size() ) {
					// TODO: Make this an algorithm somewhere //
					Vector2D P1 = Vertex[0];
					Vector2D P2 = Vertex[0];
					
					for ( size_t idx = 1; idx < Vertex.size(); idx++ ) {
						if ( Vertex[idx].x < P1.x )
							P1.x = Vertex[idx].x;
						if ( Vertex[idx].y < P1.y )
							P1.y = Vertex[idx].y;
							
						if ( Vertex[idx].x > P2.x )
							P2.x = Vertex[idx].x;
						if ( Vertex[idx].y > P2.y )
							P2.y = Vertex[idx].y;
					}
					
					Center = P1 + ((P2 - P1) * Real::Half);
				}
				break;
			}
		};
	}
};
// - ------------------------------------------------------------------------------------------ - //
class cPolyMapLink {
public:
	// The type or classification of the Link.  Paths, Branches, Springs, etc. //
	size_t Type;
	
	// The associated elements //
	size_t a;
	size_t b;

	// The Id of the Link. //
	size_t Id;
	
	// Additional information of the Link (argument) //
	//int Info;

public:
	cPolyMapLink() :
		Type( 0 ),
		Id( 0 )
	{
	}

	cPolyMapLink( const size_t _Type ) :
		Type( _Type ),
		Id( 0 )
	{
	}
};
// - ------------------------------------------------------------------------------------------ - //
class cPolyMap {
public:
	// Array of Elements //
	std::vector< cPolyMapElement > Element;
	// Array of Links //
	std::vector< cPolyMapLink > Link;
	
	// Map of information keys //
	typedef std::map< const std::string, std::string > cPolyMapKey;
	typedef cPolyMapKey::const_iterator cKeyIterator;
	cPolyMapKey Key;
	
public:
	cPolyMap() {
	}
	
	cPolyMap( const char* FileName ) {
		Load( FileName );
	}
	
	void Load( const char* FileName );
	void Save( const char* FileName ) const;

public:
	// Helper functions for accessing the key as other types //
	inline const std::string GetStringKey( const std::string _Key ) {
		return Key[ _Key ];
	}
	inline const int GetIntegerKey( const std::string _Key ) {
		return atoi( Key[ _Key ].c_str() );
	}
	inline const float GetFloatKey( const std::string _Key ) {
		return atof( Key[ _Key ].c_str() );
	}	
};
// - ------------------------------------------------------------------------------------------ - //
#endif // __PolyMap_H__ //
// - ------------------------------------------------------------------------------------------ - //
