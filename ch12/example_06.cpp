#include "../_add_libs/PPP2Code/Simple_window.h"


namespace ch12
{
	namespace example
	{
		void _06()
		{
			Point
				tl			{100, 100},
				anc			{200, 200};		
			Simple_window
				win			{tl, 600, 400, ""};
			Color
				darkGreen	{Color::Color_type::dark_green},
				green		{Color::Color_type::green};
			Graph_lib::Rectangle
				rect		{anc, 100, 50};

			rect.set_color	(darkGreen);
			rect.set_fill_color(green);
			win.attach		(rect);

			Closed_polyline 
				poly;
			Point
				p1			{100, 100},
				p2			{200, 100},
				p3			{200, 50},
				p4			{100, 50};
			Line_style
				lStyle		{Line_style::Line_style_type::dash, 2};

			poly.add		(p1);
			poly.add		(p2);
			poly.add		(p3);
			poly.add		(p4);
			poly.add		(Point {150, 75});
			poly.set_color	(darkGreen);
			poly.set_fill_color(green);
			poly.set_style	(lStyle);

			win.attach		(poly);

			win.wait_for_button	();
		}
	}
}