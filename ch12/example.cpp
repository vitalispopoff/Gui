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

		void _02()
		{
			Point
				tl {100, 100};
			Simple_window
				win {tl, 600, 400, "Canvas"};
			win.wait_for_button();
		}

		void _03()
		{
			Point
				center	{20, 300},
				tl		{100, 100};
			Simple_window
				win		{tl, 600, 400, "Canvas"};
			int
				length	{280},
				scale	{10};
			Axis
				xa		{Axis::Orientation::x, center, length, scale, "x axis"},
				ya		{Axis::Orientation::y, center, length, scale, "y axis"};
			Color
				black	{Color::Color_type::black};

			xa.set_color (black);
			ya.set_color (black);
			win.attach (xa);
			win.attach (ya);

			win.set_label ("Canvas #2");
			win.wait_for_button ();
		}

		void _04()
		{
			Point
				tl		{100, 100},
				center	{20, 300},
				sin0	{20, 150};
			Simple_window
				win		{tl, 600, 400, ""};
			int
				length	{280},
				scale	{10},
				sinRes	{1000};
			double
				sinFrq	{25},									//v/ x axis scale
				sinAmp	{50};									//v/ y axis scale

			Axis
				xa		{Axis::Orientation::x, center, length, scale, "x axis"},
				ya		{Axis::Orientation::y, center, length, scale, "y axys"};
			Color
				black	{Color::Color_type::black},
				blue	{Color::Color_type::blue};
			Function 
				sine	{sin, 0, 100, sin0, sinRes,sinFrq, sinAmp};

			xa.set_color	(black);
			ya.set_color	(black);
			sine.set_color	(blue);
			win.attach (xa);
			win.attach (ya);
			win.attach (sine);
			win.wait_for_button();
		}

		void _05()
		{
			/// please, do enjoy your piece-of-turd-splattered-against-the-wall code formatting.		
			Graph_lib::Polygon poly;
			poly.add(Point{300,200});
			poly.add(Point{350,100});
			poly.add(Point{400,200});
			poly.set_color(Color::Color_type::red);
			poly.set_style(Line_style::Line_style_type::dash);
			Simple_window win{Point{100,100},600,400,""};
			win.attach(poly);
			win.wait_for_button();					
		}

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

		void _07()
		{
			int
				height	{400},
				width	{600};		
			Point
				tl		{100, 100},
				anch	{width >> 2, height >> 1};
			Simple_window
				win		{tl, width, height, ""};
			string
				content	{"Would use 'cin' but wait_for_button will prevent... Sorry."};
			Text
				txt		{anch, content};
			Color
				dY		{Color::Color_type::dark_yellow};
			txt.set_color(dY);
			win.attach	(txt);

			win.wait_for_button();
		}

		void _08()
		{
			string
				content		{"Would use 'cin', but 'wait_for_button' would prevent. Sorry"};
			int
				height		{400},
				width		{600},
				txtSize		{16},
				txtLen		{int(sizeof(content)) * txtSize},
				txtAnchX	{(width - txtLen) >> 1},
				txtAnchY	{(height - txtSize) >> 1};
			Point
				tl			{100, 100},
				txtAnch		{txtAnchX, txtAnchY};
			Simple_window
				win			{tl, width, height, ""};
			Text
				txt			{txtAnch, content};
			Color
				color		{Color::Color_type::black};
			Font
				f			{Font::Font_type::helvetica};
			txt.set_color	(color);
			txt.set_font	(f);
			txt.set_font_size(txtSize);

			win.attach		(txt);
			win.wait_for_button();
		}

		void _09()
		{
			string
				imgAdd	{"E:\\_LAB\\_C\\Gui\\_other\\"},
				imgName	{"kuvaton-kuka_jatti_ikkunan_auki2.jpg"};
				//imgName	{"dog_9.gif"};
			Point
				tl		{100, 100};
			int
				width	{600},
				height	{400};
			Simple_window
				win		{tl, width, height, ""};
			Image
				img		{Point {0, 0}, string(imgAdd + imgName)};
			win.attach	(img);
			win.set_label(imgName);
			win.wait_for_button();
		}

		void _10()
		{
			int
				width	{600},
				height	{400};
			Point
				tl		{100, 100};
			Simple_window
				win		{tl, width, height, ""};

			Point
				center	{width >> 1, height >> 1};
			int
				rad		{100};
			double
				dist	{2.};
			Circle
				c		{center, rad};
			Graph_lib::Ellipse
				e		{center, int(dist * rad), int(rad / dist)};

			Color
				white	{Color::Color_type::white};
			c.set_color	(white);
			e.set_color	(white);

			win.attach	(c);
			win.attach	(e);

			win.wait_for_button();
		}

		void _11()
		{
			int
				width	{600},
				height	{400};
			Point
				tl		{100, 100};
			Simple_window
				win		{tl, width, height, ""};

			Point
				center	{width >> 1, height >> 1};
			Mark
				m		{center, 'x'};
		
			ostringstream
				oss;
			oss
				<< "screan size: "
				<< x_max()
				<< '*'
				<< y_max()
				<< "; window size: "
				<< win.x_max()
				<< '*'
				<< win.y_max();
			Text
				sizes	{tl, oss.str()};
			Color
				color	{Color::Color_type::black};

			sizes.set_color(color);

			win.attach	(m);
			win.attach	(sizes);

			win.wait_for_button();
		}

		void _12()
		{
			int
				dispX	{x_max()},
				dispY	{y_max()},
				winX	{dispX >> 1},
				winY	{dispY >> 1},
				anchX	{dispX >> 2},
				anchY	{dispY >> 2};
			Point
				winAnch	{anchX, anchY};
			Simple_window
				win		{winAnch, winX, winY, ""};

			int
				imgX	{320},
				imgY	{240};
			Point
				imgAnch	{(winX - imgX) >> 1,(winY - imgY) >> 1},
				crop	{120, 60};
			string
				imgAdd	{"E:\\_LAB\\_C\\Gui\\_other\\"},
				imgName	{"kuvaton-kuka_jatti_ikkunan_auki2.jpg"};
			Image
				img		{imgAnch, imgAdd + imgName};

			img.set_mask(crop, imgX, imgY);
		
			win.attach	(img);
			win.wait_for_button();
		}
	}
}