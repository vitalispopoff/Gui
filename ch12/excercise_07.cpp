#include "../_add_libs/PPP2Code/Graph.h"
#include "../_add_libs/PPP2Code/Simple_window.h"

using namespace Graph_lib;

namespace ch12
{
	namespace excercise
	{
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
	}
}