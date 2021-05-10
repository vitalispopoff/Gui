#include "../_add_libs/PPP2Code/Graph.h"
#include "../_add_libs/PPP2Code/Simple_window.h"

using namespace Graph_lib;

namespace ch12
{
	namespace excercise
	{
		void _01()
		{
			Simple_window
				window		{Point {100, 100}, 800, 600, "exc 01"};

			Graph_lib::Rectangle
				rect		{Point {100, 100}, Point {300, 200}};
			Color
				rectColor	{Color::Color_type::blue};
			rect.set_color	(rectColor);
			window.attach	(rect);

			Graph_lib::Polygon
				poly;
			poly.add		(Point {100, 400});
			poly.add		(Point {100, 500});
			poly.add		(Point {300, 500});
			poly.add		(Point {300, 400});
			Color
				polyColor	{Color::Color_type::red};
			poly.set_color	(polyColor);
			window.attach	(poly);

			window.wait_for_button();
		}
	}
}