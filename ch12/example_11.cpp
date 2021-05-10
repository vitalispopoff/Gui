#include <sstream>

#include "../_add_libs/PPP2Code/Graph.h"
#include "../_add_libs/PPP2Code/Simple_window.h"

using namespace std;
using namespace Graph_lib;

namespace ch12
{
	namespace example
	{
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
	}
}