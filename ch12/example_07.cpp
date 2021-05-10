#include "../_add_libs/PPP2Code/Graph.h"
#include "../_add_libs/PPP2Code/Simple_window.h"

using namespace Graph_lib;

namespace ch12
{
	namespace example
	{
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
	}
}