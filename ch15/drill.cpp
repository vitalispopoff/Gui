#include <iostream>
#include "ch15_drill.h"

namespace ch15
{
	namespace drill
	{
		namespace d01
		{
			void main()
			{
				const Point
					win_anchor	{1000, 500},
					win_size	{600, 600};

				Graph_lib::Window
					win {win_anchor, win_size.x, win_size.y, "Function graphs"};
				const int
					axis_len	{400};
				Axis
					ax_x {
						Axis::Orientation::x,
						{(win_size.x - axis_len) >> 1, win_size.y >> 1},						
						axis_len,
						20,
						"1 == 20 px"
					},
					ax_y {
						Axis::Orientation::y,
						{win_size.y >> 1, win_size.y - ((win_size.y - axis_len) >> 1)},
						axis_len,
						20,
						"1 == 20px"
					};
				Color
					ax_col {Color::Color_type::red};
				ax_x.set_color	(ax_col);
				ax_y.set_color	(ax_col);

				win.attach	(ax_x);
				win.attach	(ax_y);
				
				Function
					f1 {
						[] (double) { return 1.;},
						-10.,
						11.,
						{300, 300},
						20 + 11, 
						//1, 1	// drills, part 2: drill 1
						20,
						20
					};
				win.attach (f1);

				for (char c {0};  c != 'x'; std::cin >> c)
					Fl::wait();
			}
		}

	}
}