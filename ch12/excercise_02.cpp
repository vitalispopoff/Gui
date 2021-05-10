#include "../_add_libs/PPP2Code/Graph.h"
#include "../_add_libs/PPP2Code/Simple_window.h"

using namespace Graph_lib;

namespace ch12
{
	namespace excercise
	{
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
	}
}