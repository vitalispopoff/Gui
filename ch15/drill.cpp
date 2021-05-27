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
						{(win_size.x - ax_len) >> 1, win_size.y >> 1},						
						ax_len,
						ax_unit_len,
						ax_lab
					},
					ax_y {
						Axis::Orientation::y,
						{win_size.y >> 1, win_size.y - ((win_size.y - ax_len) >> 1)},
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
				constants::Axis
					ax_x {Axis::Orientation::x},
					ax_y {Axis::Orientation::y};
				win.attach	(ax_x);
				win.attach	(ax_y);			
				constants::Function
					f1 {[] (double) {return 1.;}};
				win.attach (f1);
				for (char c {0};  c != 'x'; std::cin >> c)
					Fl::wait();
			}
		}

		namespace d04
		{
			void main()
			{
				Graph_lib::Window
					win {win_anchor, win_size.x, win_size.y, win_lab};
				constants::Axis
					ax_x {Axis::Orientation::x},
					ax_y {Axis::Orientation::y};
				win.attach	(ax_x);
				win.attach	(ax_y);			
				constants::Function
					f1 {[] (double) {return 1.;}},
					f2 {[] (double x) {return x * 0.5;}};
				win.attach (f1);
				win.attach (f2);
				for (char c {0};  c != 'x'; std::cin >> c)
					Fl::wait();
			}
		}

		namespace d05
		{
			double slope (double x) 
			{
				return x * 0.5;
			}
			void main()
			{
				Graph_lib::Window
					win {win_anchor, win_size.x, win_size.y, win_lab};
				constants::Axis
					ax_x {Axis::Orientation::x},
					ax_y {Axis::Orientation::y};
				win.attach	(ax_x);
				win.attach	(ax_y);			
				constants::Function
					f1 {[] (double) {return 1.;}},
					f2 {[] (double x) {return x * 0.5;}};
				win.attach (f1);
				win.attach (f2);
				Text
					f2_lab { 
						{f_orig.x + int(f_min * f_x_unit_len), f_orig.y - 10 - int(slope(f_min) * f_y_unit_len)}, // '- 10' at .y coord should be derived from font size
						"x/2"
					};
				win.attach (f2_lab);

				for (char c {0};  c != 'x'; std::cin >> c)
					Fl::wait();
			}
		}

		namespace d06
		{
			double	slope	(double x) 
			{
				return x * 0.5;
			}
			double	square	(double x)
			{
				return x * x;
			}
			void main()
			{
				Graph_lib::Window
					win {win_anchor, win_size.x, win_size.y, win_lab};
				constants::Axis
					ax_x {Axis::Orientation::x},
					ax_y {Axis::Orientation::y};
				win.attach	(ax_x);
				win.attach	(ax_y);			
				constants::Function
					f1	{[] (double) {return 1.;}},
					f2	{slope},
					f3	{square, f_min, f_max, f_orig, f_count * ax_unit_len};
				win.attach (f1);
				win.attach (f2);
				win.attach (f3);
				Text
					f2_lab { 
						{f_orig.x + int(f_min * f_x_unit_len), f_orig.y - 10 - int(slope(f_min) * f_y_unit_len)}, // '- 10' at .y coord should be derived from font size
						"x/2"
					};
				win.attach (f2_lab);

				for (char c {0};  c != 'x'; std::cin >> c)
					Fl::wait();
			}
		}
	}
}