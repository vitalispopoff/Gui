//#include <cmath>
#include <sstream>
#include "ch15.h"

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
	}
}