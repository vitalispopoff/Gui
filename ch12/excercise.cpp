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

		void _02()
		{
			Simple_window
				window		{Point {100, 100}, 600, 400, "exc 02"};

			Graph_lib::Rectangle
				rect		{Point {100, 100}, Point {200, 130}};
			Color
				rectFill	{Color::Color_type::white},
				rectMarg	{Color::Color_type::black};
			rect.set_color (rectMarg);
			rect.set_fill_color(rectFill);
			Text
				txt			{Point {120, 122}, "Howdy!"};
			Color
				txtColor	{Color::Color_type::black};
			txt.set_color	(txtColor);
			txt.set_font_size(20);

			window.attach	(rect);
			window.attach	(txt);
			 
			window.wait_for_button();
		}

		void _03()
		{
			Simple_window
				window		{Point {100, 100}, 600, 400, "exc 03"};
			Text
				v			{Point {100, 250}, "V"},
				p			{Point {350, 250}, "P"};
			Color
				vColor		{Color::Color_type::cyan},
				pColor		{Color::Color_type::magenta};
			v.set_font_size	(150);
			p.set_font_size	(150);
			v.set_color		(vColor);
			p.set_color		(pColor);

			window.attach	(v);
			window.attach	(p);

			window.wait_for_button();
		}

		void __04()
		{					
			Color 
				red		{Color::Color_type::red},
				white	{Color::Color_type::white};			

			Simple_window
				window		{Point {100, 100}, 301, 301, "exc 04"};		

			Graph_lib::Rectangle
				r1{Point {1, 1}, 99, 99},
				r2{Point {1, 100}, 99, 99},
				r3{Point {1, 200}, 99, 99},
				r4{Point {101, 1}, 99, 99},
				r5{Point {101, 100}, 99, 99},
				r6{Point {101, 200}, 99, 99},
				r7{Point {201, 1}, 99, 99},
				r8{Point {201, 100}, 99, 99},
				r9{Point {201, 200}, 99, 99};

			r1.set_fill_color	(red);
			r2.set_fill_color	(white);
			r3.set_fill_color	(red);
			r4.set_fill_color	(white);
			r5.set_fill_color	(red);
			r6.set_fill_color	(white);
			r7.set_fill_color	(red);
			r8.set_fill_color	(white);
			r9.set_fill_color	(red);

			window.attach	( r1);
			window.attach	(r2);
			window.attach	(r3);
			window.attach	(r4);
			window.attach	(r5);
			window.attach	(r6);
			window.attach	(r7);
			window.attach	(r8);
			window.attach	(r9);

			window.wait_for_button();
		}

		void _05()
		{
			int
				dispX	{x_max()},
				dispY	{y_max()},
				winW	{int (round(dispX * 0.66))},
				winH	{int (round(dispY * 0.75))};

			Simple_window
				window	{Point {100, 100}, winW + 2, winH + 2, "exc 05"};

			Graph_lib::Rectangle
				rect	{Point {1, 1}, winW - 1, winH - 1};
			rect.set_color (Color::Color_type::red);
			window.attach (rect);

			window.wait_for_button();
		}

		void _06()	{}

		void _07()
		{
			Simple_window
				window	{Point {2200, 500}, 800, 600, "exc 07"};

			Graph_lib::Rectangle
				grass	{Point {0, 500}, 800, 100};
			grass.set_color	(Color::Color_type::green);
			window.attach	(grass);
			
			window.wait_for_button();
		}

		void _08()	{}

		void _09()	{}

		void _10()	{}

		void _11()	{}

		void _12()	{}

		void _13()	{}
	}
}