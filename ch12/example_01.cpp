#include "../_add_libs/PPP2Code/Graph.h"
#include "../_add_libs/PPP2Code/Simple_window.h"

namespace ch12
{
	namespace example
	{
		void _01()
		{
			using namespace Graph_lib;

			Point
				tl {100, 100};
			Simple_window
				win {tl, 600, 400, "Canvas"};
			Graph_lib::Polygon
				poly;
			Point
				a {300, 200},
				b {350, 100},
				c {400, 200};
			poly.add(a);
			poly.add(b);
			poly.add(c);

			Color 
				red {Color::Color_type::red};
			poly.set_color(red);
			win.attach(poly);
			win.wait_for_button();
		}
	}
}