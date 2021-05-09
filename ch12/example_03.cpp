//#include "../_add_libs/PPP2Code/Graph.h"
#include "../_add_libs/PPP2Code/Simple_window.h"

using namespace Graph_lib;

namespace ch12
{
	namespace example
	{
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
	}
}