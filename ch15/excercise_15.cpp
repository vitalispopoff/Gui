#include <iostream>

#include "ch15_excercise.h"
#include "ch15_drill.h"

namespace ch15
{
	namespace excercise
	{
		void keep_open()
		{
			char c;
			cin >> c;
		}
		
		namespace e01
		{
			int fac_recursive (int n)
			{
				return 
					n > 1 
					? n * fac_recursive(n - 1) 
					: 1;
			}
			int fac_iterative (int n)
			{
				int
					result {1};
				while (n > 1)
					result *= n--;
				return result;
			}

			void main()
			{
				int
					rec {fac_recursive(20)},
					itr {fac_iterative(20)};
				bool
					equals {rec == itr};
				if (equals)
					cout << "yap" << endl;
				else
					cout << "recursive is: " << rec << ", and iterative is " << itr << endl;
				

				keep_open();
			}
		}

		namespace e02
		{
			void Fct::reset()
			{
				count_ = 100;
				xscale_ = 25.;
				yscale_ = 25.;
			}
			

			using namespace ch15::drill::constants;
			void main()
			{
				Graph_lib::Window
						win {win_anchor, win_size.x, win_size.y, win_lab};
					ch15::drill::constants::Axis
						ax_x {Axis::Orientation::x},
						ax_y {Axis::Orientation::y};
					win.attach	(ax_x);
					win.attach	(ax_y);			
					Fct
						f1 {
						[](double x) {return sin ( x + cos(x));},
						f_min,
						f_max,
						f_orig,
						int (f_max) - int (f_min),
						f_x_unit_len,
						f_y_unit_len
						};
					f1.reset();
					win.attach (f1);

			
				for (char c {0};  c != 'x'; std::cin >> c)
				{	
					//if (c == 'r')
					//{
					//	win.detach(f1);
					//	f1.reset();
					//	win.attach(f1);
					//	Fl::redraw();
					//}
					Fl::wait();
				}

			}
		}

		namespace e04
		{
			using namespace ch15::drill::constants;

			double sine (double x)
			{ 
				return sin (x);
			}
			double cosine (double x)
			{ 
				return cos (x);
			}
			double sum (double x)
			{
				return sin (x) + cos (x);
			}
			double sqr_sum (double x)
			{ 
				double 
					s {sin (x)},
					c {cos (x)};
				return s * s + c * c;
			}
			void main()
			{
				Graph_lib::Window
					win {win_anchor, win_size.x, win_size.y, win_lab};
				ch15::drill::constants::Axis
					ax_x {Axis::Orientation::x, win_size, ax_len, int(f_x_unit_len), ""},
					ax_y {Axis::Orientation::y, win_size, ax_len, 1, ""};
				win.attach	(ax_x);
				win.attach	(ax_y);			
				double
					y_unit_len {double(ax_len) * 0.25};
				ch15::drill::constants::Function
					f1	{sine,		f_min, f_max, f_orig, ax_len >> 1,	f_x_unit_len , y_unit_len},
					f2	{cosine,	f_min, f_max, f_orig, ax_len >> 1,	f_x_unit_len, y_unit_len},
					f3	{sum,		f_min, f_max, f_orig, ax_len >> 1,	f_x_unit_len, y_unit_len},
					f4	{sqr_sum,	f_min, f_max, f_orig, ax_len >> 1,	f_x_unit_len, y_unit_len};
				win.attach (f1);
				win.attach (f2);
				win.attach (f3);
				win.attach (f4);
				Graph_lib::Text
					f1_lab { {f_orig.x + int(f_min * f_x_unit_len) - 30, f_orig.y - int (round (sine	(f_min) * y_unit_len))}, "sin"},
					f2_lab { {f_orig.x + int(f_min * f_x_unit_len) - 30, f_orig.y - int (round (cosine	(f_min) * y_unit_len))}, "cos"},
					f3_lab { {f_orig.x + int(f_min * f_x_unit_len) - 60, f_orig.y - int (round (sum		(f_min) * y_unit_len))}, "sin + cos"},
					f4_lab { {f_orig.x + int(f_min * f_x_unit_len) - 90, f_orig.y - int (round (sqr_sum	(f_min) * y_unit_len))}, "sin^2 + cos^2"};
				win.attach (f1_lab);
				win.attach (f2_lab);
				win.attach (f3_lab);
				win.attach (f4_lab);

				for (char c {0};  c != 'x'; std::cin >> c)
					Fl::wait()
				;
			}

		}
	}
}