#ifndef POINT_GUARD
#define POINT_GUARD // no '1' ?

//typedef void (*Callback)(void*,void*);

namespace Graph_lib 
{
	struct Point 
	{	
		Point() : 
			x {0}, 
			y {0}
		{}
		Point(int i1, int i2) : 
			x {i1}, 
			y{i2} 
		{}

		int 
			x,
			y;

		//Point & operator += (Point d) 
		//{ 
		//	x += d.x; 
		//	y += d.y;
		//	return *this; 
		//}
	};

	inline bool operator == (Point a, Point b)
	{ 
		return a.x == b.x && a.y == b.y; 
	}

	inline bool operator != (Point & a, Point & b) 
	{ 
		//return !(a==b); 
		return a.x != b.x || a.y != b.y;	//v/ probably a bit faster than !(==)
	}
}
#endif