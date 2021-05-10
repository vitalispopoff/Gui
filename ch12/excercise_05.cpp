#include "../_add_libs/PPP2Code/Graph.h"
#include "../_add_libs/PPP2Code/Simple_window.h"

using namespace std;
using namespace Graph_lib;

namespace ch12
{
	namespace excercise
	{
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
	}
}