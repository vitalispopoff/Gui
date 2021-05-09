#include "_add_libs/PPP2Code/Simple_window.h"

using namespace Graph_lib;

namespace ch12
{
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
			rad		{50};
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
}