#ifndef POINT_GUARD
#define POINT_GUARD // no '1' ?

//typedef void (*Callback)(void*,void*);

namespace Graph_lib 
{
	/// adding location to solve the incrememntal misplacement errors due to rounding and back-and-forth casting between 'int' and 'double'
	struct Location			
	{
		Location () {}
		Location (double d1, double d2) :
			x {d1}, y {d2}
		{}
		Location (int i1, int i2) :
			x {double (i1)}, y {double (i2)}
		{}
		int get_x()
		{
			return int (round (x));
		}
		int get_y()
		{
			return int (round (y));
		}
		double
			x {0.},
			y {0.};
	};

	struct Point 
	{	
		Point() : 
			x {0}, 
			y {0}
		{}
		Point(int i1, int i2) : 
			x {i1}, 
			y {i2},
			l {x, y}
		{}
		int 
			x,
			y;
		Location
			l;
		void update()
		{
			x = l.get_x();
			y = l.get_y();
		}

		//Point & operator += (Point d) 
		//{ 
		//	x += d.x; 
		//	y += d.y;
		//	return *this; 
		//}
	};

	inline bool operator == (Point a, Point b)					//v/ inline calls for overwriting the function call with the implementation at compile time (the same stuff as direct implementation in the class header declaration i guess
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