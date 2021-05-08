#include "../_add_libs/PPP2Code/Simple_window.h"
//#include "../_add_libs/PPP2Code/Graph.h"
#include "../_add_libs/PPP2Code/Point.h"

void exc01()
{
	using namespace Graph_lib;

	Point
		tl {100, 100};
	Simple_window
		win {tl, 600, 400, "Canvas"};
	Graph_lib::Polygon
		poly;
	poly.add(Point{300, 200});
	poly.add(Point{350, 100});
	poly.add(Point{400, 200});

	Color 
		c {Color::Color_type::red};
	poly.set_color(c);
	win.attach(poly);
	win.wait_for_button();

	//return 0;
}