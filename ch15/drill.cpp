#include <iostream>
#include "ch15_drill.h"

namespace ch15
{
	namespace drill
	{
		using namespace constants;

		namespace d01
		{			
			void main()
			{
				Graph_lib::Window
					win {win_anchor, win_size.x, win_size.y, win_lab};
				Axis
					ax_x {
						Axis::Orientation::x,
						ax_x_anch,						
						ax_len,
						ax_unit_len,
						ax_lab
					},
					ax_y {
						Axis::Orientation::y,
						ax_y_anch,
						ax_len,
						ax_unit_len,
						ax_lab
					};
				ax_x.set_color	(ax_col);
				ax_y.set_color	(ax_col);
				win.attach	(ax_x);
				win.attach	(ax_y);			
				Function
					f1 {
						[] (double) { return 1.;},
						f_min,
						f_max,
						f_orig,
						f_count, 
						f_x_unit_len,
						f_y_unit_len,
					};
				win.attach (f1);

				for (char c {0};  c != 'x'; std::cin >> c)
					Fl::wait();
			}
		}

		namespace d03
		{			
			void main()
			{

				Graph_lib::Window
					win {win_anchor, win_size.x, win_size.y, win_lab};

				Axis
					ax_x {
						Axis::Orientation::x,
						ax_x_anch,						
						ax_len,
						ax_unit_len,
						ax_lab
					},
					ax_y {
						Axis::Orientation::y,
						ax_y_anch,
						ax_len,
						ax_unit_len,
						ax_lab
					};

				ax_x.set_color	(ax_col);
				ax_y.set_color	(ax_col);

				win.attach	(ax_x);
				win.attach	(ax_y);
			
				Function
					f1 {
						[] (double) { return 1.;},
						f_min,
						f_max,
						f_orig,
						f_count, 
						f_x_unit_len,
						f_y_unit_len,
					};
				win.attach (f1);

				for (char c {0};  c != 'x'; std::cin >> c)
					Fl::wait();
			}
		}



	}
}