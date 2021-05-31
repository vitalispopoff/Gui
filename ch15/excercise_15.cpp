#include <iostream>
#include <sstream>
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

		namespace e06
		{
					Bar_chart::Bar_chart	(Point top_left, int width, int height, vector<double> vs) :
				anchor {top_left}, w {width}, h {height}
			{
				values = vs;
				for (double val : values)
					max_bar_value = max (max_bar_value, val);
			}		
			void	Bar_chart::add_bar		(double b)
			{
				values.push_back(b);
				max_bar_value = max(max_bar_value, b);
			}
			void	Bar_chart::draw_lines	() const
			{
				if (values.size () > 0)
				{
					int
						bar_width = int (round (double (w) / double (values.size())));
					for (int i = 0; i < values.size(); ++i)
					{
						int
							bar_height = int (round (double (h) * values[i] / max_bar_value)) - 1;
						draw_bar (
							anchor.x + i * bar_width,
							anchor.y  + h - bar_height,
							bar_width,
							bar_height
						);
					}
				}
			}
			void Bar_chart::draw_bar (int x1, int y1, int width, int height) const
			{
				fl_rectf (x1, y1, width, height);
				fl_rect (x1, y1, width, height);
			}
		}

		namespace e07
		{
					Bar_chart::Bar_chart	(Point top_left, int width, int height, vector<double> vs) :
				a {top_left}, w {width}, h {height}
			{
				values = vs;
				for (double val : values)
				{	
					max_bar_value = max (max_bar_value, val);
					stringstream
						ss;
					ss << val;
					string
						s;
					ss >> s;
					labels.push_back(s);
				}
			}		
			void	Bar_chart::draw_lines	() const
			{
				if (values.size () > 0)
				{
					int
						bar_width = int (round (double (w) / double (values.size())));
					for (int i = 0; i < values.size(); ++i)
					{
						int
							bar_height = int (round (double (h) * values[i] / max_bar_value)) - 1;
						draw_bar (
							a.x + i * bar_width,
							a.y  + h - bar_height,
							bar_width,
							bar_height,
							labels[i]
						);
					}
				}
			}
			void Bar_chart::draw_bar (int x1, int y1, int width, int height, string lab) const
			{
				fl_color(fill_color().as_int());
				fl_rectf (x1, y1, width, height);
				fl_color(color().as_int());
				fl_rect (x1, y1, width, height);
				int 
					ofnt = fl_font(),
					osz = fl_size();
				fl_font(ofnt, osz);
				fl_draw(lab.c_str(), x1, y1);
			}	
		}
		
		namespace e08
		{
			Bar_chart::Bar_chart (Point anchor, Point sizes) :
				anch {anchor}, size {sizes}
			{}

			void Bar_chart::add_bar(string s, double d)
			{
				labels.push_back (s);
				values.push_back (d);
				max_bar_value = max (max_bar_value, d);				
			}

			void	Bar_chart::draw_lines	() const
			{
				if (values.size () > 0)
				{
					int
						bar_width = int (round (double (size.x) / double (values.size())));
					for (int i = 0; i < values.size(); ++i)
					{
						int
							bar_height = int (round (double (size.y) * values[i] / max_bar_value)) - 1,
							x1 = anch.x + i * bar_width,
							y1 = anch.y  + size.y - bar_height,
							x2 = bar_width,
							y2 = bar_height;

						fl_color(fill_color().as_int());
						fl_rectf (x1, y1, x2, y2);
						
						fl_color(color().as_int());
						fl_rect (x1, y1, x2, y2);

						int 
							ofnt = fl_font(),
							osz = fl_size();
						fl_font(ofnt, osz);
						fl_draw(labels[i].c_str(), x1, y1);
					}
				}
			}
		}
	}
}