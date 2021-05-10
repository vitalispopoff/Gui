#include "../_add_libs/PPP2Code/Graph.h"
#include "../_add_libs/PPP2Code/Simple_window.h"

using namespace Graph_lib;

namespace ch12
{
	namespace excercise
	{
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
	}
}