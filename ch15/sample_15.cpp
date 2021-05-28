//#include <cmath>
#include <sstream>
#include <fstream>
#include <iostream>
#include "ch15_sample.h"

namespace ch15
{
	namespace sample
	{
		namespace s01
		{			
			double	one		(double)
			{
				return 1.;
			};
			double	slope	(double x)
			{
				return x / 2;
			}			
			double	square	(double x)
			{
				return x * x;
			}
			double	sine	(double x)
			{
				return sin(x);
			}

			void	main	()
			{
				//constexpr Point				/// can't declare orig a constexpr - input data aint constant values 
				Point
					orig {x_orig, y_orig};
				Simple_window
					window {{1000, 500}, xmax, ymax, ""};
				Function 							
					s1 {one, double(r_min), double(r_max), orig, int(n_points), double(x_scale), double(y_scale)},
					s2 {slope, double(r_min), double(r_max), orig, int(n_points), double(x_scale), double(y_scale)},
					s3 {square, double(r_min), double(r_max), orig, int(n_points), double(x_scale), double(y_scale)};
				window.attach	(s1);
				window.attach	(s2);
				window.attach	(s3);
				Text
					ts1	{{100, y_orig - 40}, "one"},
					ts2	{{100, y_orig + y_orig / 2 - 20}, "x/2"},
					ts3	{{x_orig - 100, 20}, "x^2"};
				window.attach	(ts1);
				window.attach	(ts2);
				window.attach	(ts3);
				window.wait_for_button();
			}
		}

		namespace s02
		{			
			void main ()
			{
				Point
					orig {x_orig, y_orig};
				Simple_window
					window {{1000, 500}, xmax, ymax, ""};
				Function 							
					s1 {one, double(r_min), double(r_max), orig, int(n_points), double(x_scale), double(y_scale)},
					s2 {slope, double(r_min), double(r_max), orig, int(n_points), double(x_scale), double(y_scale)},
					s3 {square, double(r_min), double(r_max), orig, int(n_points), double(x_scale), double(y_scale)};
				window.attach	(s1);
				window.attach	(s2);
				window.attach	(s3);
				Text
					ts1	{{100, y_orig - 40}, "one"},
					ts2	{{100, y_orig + y_orig / 2 - 20}, "x/2"},
					ts3	{{x_orig - 100, 20}, "x*x"};
				window.attach	(ts1);
				window.attach	(ts2);
				window.attach	(ts3);
				Axis
					x	{Axis::Orientation::x, {20, y_orig}, xlength, xlength / x_scale, "notch==1"},
					y	{Axis::Orientation::y, {x_orig, ylength + 20}, ylength, ylength / y_scale, "notch==1"};
				x.set_color	(Color::Color_type::blue);
				y.set_color	(Color::Color_type::blue);
				window.attach	(x);
				window.attach	(y);
				window.wait_for_button();
			}
		}

		namespace s03
		{
			Function::Function (
				Fct f, 
				double r1, double r2, 
				Point xy, 
				int count, 
				double xscale, double yscale)
			{
				if (r2 - r1 <= 0)
					error	("bad graphics range");
				if (count <= 0)
					error	("non-positive graphic count");
				double
					dist = (r2 - r1) / count,
					r = r1;
				for (int i = 0; i < count; ++i)
				{
					add (
						Point {
							xy.x + int (r * xscale),
							xy.y = int (f (r) * yscale)
					});
					r += dist;
				}
			}
		}

		namespace s04
		{
			double fm (double x)
			{
				return 4 * sin(4 * x * cos(x));
			}
			void main ()
			{
				Point
					orig {x_orig, y_orig};
				Simple_window
					window {{1000, 500}, xmax, ymax, ""};
				Function 							
					s4 {fm, double(r_min), double(r_max), orig, int(n_points), double(x_scale), double(y_scale)};
				window.attach	(s4);
				//Text
				Axis
					x	{Axis::Orientation::x, {20, y_orig}, xlength, xlength / x_scale, "notch==1"},
					y	{Axis::Orientation::y, {x_orig, ylength + 20}, ylength, ylength / y_scale, "notch==1"};
				x.set_color	(Color::Color_type::blue);
				y.set_color	(Color::Color_type::blue);
				window.attach	(x);
				window.attach	(y);
				window.wait_for_button();
			}
		}

		namespace s05
		{
			void main ()
			{
				Point
					orig {x_orig, y_orig};
				Simple_window
					window {{1000, 500}, xmax, ymax, ""};
				Function 							
					s4 {
						[] (double x) {return 4 * sin((2 * x) + (cos(5 * 3.14159265 * x)));},		/// lambda 
						double(r_min), 
						double(r_max), 
						orig, 
						int(n_points), 
						double(x_scale), 
						double(y_scale)
					};
				window.attach	(s4);
				window.wait_for_button();
			}
		}

		namespace s06
		{
			Axis::Axis (Orientation d, Point xy, int length, int n, string lab)	:
				label {{0,0}, lab}
			{
				if (length < 0)
					error ("bad axis length");
				switch (d)
				{
					case Axis::Orientation::x :
					{
						Shape::add (xy);
						Shape::add ({xy.x + length, xy.y});
						if (0 < n)
						{
							int 
								dist = length / n,
								x = xy.x + dist;
							for (int i = 0; i < n; ++i)
							{
								notches.add ({x, xy.y}, {x, xy.y - 5});
								x += dist;
							}
						}
						label.move (length / 3, xy.y + 20);
						break;
					}
					case Axis::Orientation::y :
					{
						Shape::add (xy);
						Shape::add ( {xy.x, xy.y - length});
						if (0 < n)
						{
							int
								dist = length / n,
								y = xy.y - dist;
							for (int i = 0; i < n; ++i)
							{
								notches.add ({xy.x,y}, {xy.x + 5, y});
								y -= dist;
							}
						}
						label.move (xy.x - 10, xy.y - length - 10);
						break;
					}
					case Axis::Orientation::z :
						error ("z axis not implemented");
				}
			}

			void Axis::draw_lines () const
			{
				Shape::draw_lines();
				notches.draw();
				label.draw();
			}
			void Axis::move (int dx, int dy)
			{
				Shape::move (dx, dy);
				notches.move (dx, dy);
				label.move (dx, dy);
			}
			void Axis::set_color (Color c)
			{
				Shape::set_color (c);
				notches.set_color (c);
				label.set_color (c);
			}
		}

		namespace s07
		{
			int 
				n {0};			/// set as a scope global to get it removed from 'expe' input list
			int fac (int n)
			{
				int
					r {1};
				while (1 < n)
					r *= n--;	/// hopefully precedence of the operators is stable enough to make it work fine
				return r;
			}
			double term (double x, int i)
			{
				return pow (x, i) / fac (i);
			}
			double expe (double x)	// 'int n' removed from input
			{
				double
					sum {0};
				for (int i = 0; i < n; ++i)
					sum += term (x, i);
				return sum;
			}
			void main()
			{
				using namespace constants;
				Simple_window
					window {{2200, 500}, xmax, ymax, ""};
				Axis
					x	{Axis::Orientation::x, {20, y_orig}, xlength, xlength / x_scale,},
					y	{Axis::Orientation::y, {x_orig, ylength + 20}, ylength, ylength / y_scale,};
				Color
					ax_col {Color::Color_type::black, Color::Transparency::translucent};
				x.set_color (ax_col);
				y.set_color (ax_col);
				window.attach	(x);
				window.attach	(y);
				Function 
					real_exp {exp, double(r_min), double(r_max), {x_orig, y_orig}, 200, double(x_scale), double(y_scale)};
				real_exp.set_color(Color::Color_type::blue);
				window.attach(real_exp);
				window.wait_for_button();
				for (; n < 50; ++n)
				{
					ostringstream
						ss;
					ss 
						<< "exp approximation; n ==" 
						<< n;
					window.set_label (ss.str().c_str());
					Function 
						e {
					/// originally expe input included n, 
					///	and lambda was intercepting it, 
					///	but turns out Function doesn't allow this behaviour,
					/// so for loop got its 'int n' moved atop the namespace, 
					///	and shared with other functions, 'expe()' among them 
						//[n] (double x) {return expe (x, n);}, 
						[] (double x) {return expe (x);},	
						double(r_min),
						double(r_max),
						{x_orig, y_orig},
						200,
						double(x_scale),
						double(y_scale)
					};
					e.set_color({Color::Color_type::yellow, Color::Transparency::translucent}); /// well - 'translucent' doesn't work anyway :(
					window.attach (e);
					window.wait_for_button();
					/// p.534
					/// "Note the final detach(e) in that loop. (...)
					/// The window must not remember the old 'e' because it will have been destroyed. 
					/// Thus, 'detach(e)' ensures that the window does not try to draw a de-stroyed object."
					///  - yet commenting out the line doesn't seem to change anything, or does it?
					window.detach (e);
				}
			}
		}

		namespace s08
		{
		/// apparently can declare scope global variables from other namespaces...
			using s07::n;		
			double fac (double n)
			{
				double
					r {1};
				while (1 < n)
					r *= n--;
				return r;
			}		
			double term (double x, int i)
			{
				return pow (x, i) / fac (double(i));
			}
			double expe (double x)
			{
				double
					sum {0};
				for (int i = 0; i < n; ++i)
					sum += term (x, i);
				return sum;
			}
			void main()
			{
				using namespace constants;
				Simple_window
					window {{2200, 500}, xmax, ymax, ""};
				Axis
					x	{Axis::Orientation::x, {20, y_orig}, xlength, xlength / x_scale,},
					y	{Axis::Orientation::y, {x_orig, ylength + 20}, ylength, ylength / y_scale,};
				Color
					ax_col {Color::Color_type::black, Color::Transparency::translucent};
				x.set_color (ax_col);
				y.set_color (ax_col);
				window.attach	(x);
				window.attach	(y);
				Function 
					real_exp {exp, double(r_min), double(r_max), {x_orig, y_orig}, 200, double(x_scale), double(y_scale)};
				real_exp.set_color(Color::Color_type::blue);
				window.attach(real_exp);
				window.wait_for_button();
				for (; n < 50; ++n)
				{
					ostringstream
						ss;
					ss 
						<< "exp approx. : n == " 
						<< n;
					window.set_label (ss.str().c_str());
					Function 
						e {[] (double x) {return expe (x);}, double(r_min), double(r_max), {x_orig, y_orig}, 200, double(x_scale), double(y_scale)};
					e.set_color({Color::Color_type::yellow});
					window.attach (e);
					window.wait_for_button();				
					window.detach (e);
				}
			}
		}

		namespace s09
		{
			istream & operator >> (istream & is, Distribution & d)
			{
				char
					ch1 {0},	// like '('
					ch2 {0},	// like ':'
					ch3 {0};	// like ')'
				Distribution
					dd;
				if (is >> ch1 >> dd.year >> ch2 >> dd.young >> dd.middle >> dd.old >> ch3)
				{
					if (ch1 != '(' || ch2 != ':' || ch3 != ')')
					{
						is.clear (ios_base::failbit);
						return is;
					}
				}
				else
					return is;
				d = dd;
				return is;
			}

			string 
				file_name {"japanese-age-data.txt"};
			ifstream 
				ifs {file_name};

			void sketch ()
			{
				if (!ifs)
					error ("can't open " + file_name);	///commit: e8424b144f0cab65cb0dfa1828c1f8b9957ce9d0 :: std_lib_facilities.h :: 141 sqq
				/// ...
				int
					base_year {0},
					end_year {0};
				/// ...
				for (Distribution d; ifs >> d; )
				{
					if (d.year < base_year || end_year < d.year)
						error ("year out of range");
					if (d.young + d.middle + d.old != 100)
						error ("percentages don't add up");
				}
				/// ...
			}
		}

		namespace s10
		{
			constexpr int
				xanchor	= 1000,
				yanchor	= 500,
				
				xmax	= 600,
				ymax	= 400,

				xoffset	= 100,
				yoffset	= 60,

				xspace	= 40,
				yspace	= 40,

				xlength	= xmax - xoffset - xspace,
				ylength	= ymax - yoffset - yspace,

				base_year	= 1960,
				end_year	= 2040;
			constexpr double
				xscale = double (xlength) / (end_year - base_year),
				yscale = double (ylength) * 0.01;	/// it's better to multiply, than divide

			Scale
				xs	{xoffset, base_year, xscale},
				ys	{ymax - yoffset, 0 , -yscale};

			using s09::file_name;
			using s09::ifs;

			void main()
			{
				Graph_lib::Window 
					win {{xanchor, yanchor}, xmax, ymax, "Aging Japan"};
				string
					lab_years	{"year	1960	1970	1980	1990	2000	2010	2020	2030	2040"};
				Graph_lib::Axis
					x {
						Axis::Orientation::x, 
						{xoffset, ymax - yoffset}, 
						xlength, 
						(end_year - base_year) / 10,
						lab_years
						//"year	1960	1970	1980	1990	"	these two strings would be concatenated by the compiler
						//"2000	2010	2020	2030	2040"
					};
				x.label.move (-100, 0);
				Axis
					y {
						Axis::Orientation::y, 
						{xoffset, ymax - yoffset}, 
						ylength, 10, 
						"% of population"
					};
				Line
					current_year {
						{xs (2008), ys (0)}, 
						{xs (2008), ys (100)}
					};
				current_year.set_style (Line_style::Line_style_type::dash);

				if (!ifs)
					error ("can't open " + file_name);
				Open_polyline 
					children,
					adults,
					aged;
				for (Distribution d; ifs >> d; )
				{
					if (d.year < base_year || end_year < d.year)
						error ("year out of range");
					if (d.young + d.middle + d.old != 100)
						error ("percentages don't add up");
					const int
						x = xs (d.year);
						//x = xs {d.year};		// doesn't work anymore
					children.add ({x, ys (d.young)});
					adults.add ({x, ys(d.middle)});
					aged.add ({x, ys(d.old)});
				}

				Color
					children_col	{Color::Color_type::red},
					adults_col		{Color::Color_type::blue},
					aged_col		{Color::Color_type::green};
				Text
					children_label	{{20, children.point(0).y}, "age 0-14"},
					adults_label	{{20, adults.point(0).y}, "age 15-64"},
					aged_label		{{20, aged.point(0).y}, "age 65+"};
				children.set_color	(children_col);
				adults.set_color	(adults_col);
				aged.set_color		(aged_col);
				children_label.set_color(children_col);
				adults_label.set_color	(adults_col);
				aged_label.set_color	(aged_col);

				win.attach	(children);
				win.attach	(adults);
				win.attach	(aged);
				win.attach	(children_label);
				win.attach	(adults_label);
				win.attach	(aged_label);
				win.attach	(x);
				win.attach	(y);
				win.attach	(current_year);

				gui_main();
			}
		}
	}
}