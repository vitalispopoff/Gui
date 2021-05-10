#include "../_add_libs/PPP2Code/Graph.h"
#include "../_add_libs/PPP2Code/Simple_window.h"

using namespace Graph_lib;

namespace ch12
{
	namespace drill
	{
		void _02()
		{
		
		///		window		--------------------------------------------------------------------

			int
				dispW		{x_max()},
				dispH		{y_max()},
				winW		{600},
				winH		{400},
				winAnchW	{(dispW - winW) >> 1},
				winAnchH	{(dispH - winH) >> 1};
			Point
				winAnch		{winAnchW, winAnchH};
			Simple_window
				window		{winAnch, winW, winH, "Drill #2 Canvas"};

		///		Axis X		--------------------------------------------------------------------

			int
				axisXAnchW	{winW >> 2},
				axisXAnchH	{(winH >> 2) * 3};
			Point
				axisXAnch	{axisXAnchW, axisXAnchH};
			Axis
				axisX		{Axis::Orientation::x, axisXAnch, winW >> 1, 6, "x axis"};			
			Color
				black		{Color::Color_type::black};
			axisX.set_color	(black);
			window.attach	(axisX);

		///		Axis Y		--------------------------------------------------------------------	

			int
				axisYAnchW	{winW >> 1},
				axisYAnchH	{axisXAnchH};
			Point
				axisYAnch	{axisYAnchW, axisYAnchH};
			Axis
				axisY		{Axis::Orientation::y, axisYAnch, winH >> 1, 6, "y axis"};
			axisY.set_color	(black);
			window.attach	(axisY);

		///		sine		--------------------------------------------------------------------

			int
				sinAnchW	{1},
				sinAnchH	{winH >> 1};
			Point
				sinStart	{sinAnchW, sinAnchH};
			double
				scaleX		{50.},
				scaleY		{50.};
			Function
				sine		{sin, 0., double(winW), sinStart, winW << 2, 1., 50.};
			Color
				blue		{Color::Color_type::blue};
			sine.set_color	(blue);
			window.attach	(sine);

		///		polygon		--------------------------------------------------------------------

			Graph_lib::Polygon
				poly;
			Point
				p1			{300, 200},
				p2			{350, 100},
				p3			{400, 200};
			poly.add		(p1);
			poly.add		(p2);
			poly.add		(p3);
			Color
				darkGreen	{Color::Color_type::dark_green};
			poly.set_color	(darkGreen);
			Line_style
				lStyle		{Line_style::Line_style_type::dot, 6};
			poly.set_style	(lStyle);
			poly.set_fill_color(Color::Color_type::yellow);
			window.attach	(poly);

		///		text		--------------------------------------------------------------------

			string
				content		{"That's like enough already"};
			Point
				txtAnch		{100, 100};
			Text
				txt			{txtAnch, content};
			Color
				red			{Color::Color_type::red};
			txt.set_color	(red);
			Font
				font		{Font::Font_type::courier_bold};
			txt.set_font		(font);
			txt.set_font_size	(22);
			window.attach	(txt);

			window.wait_for_button();			
		}
	}
}