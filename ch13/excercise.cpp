//#include "../_add_libs/PPP2Code/fltk.h"
//#include "../_add_libs/PPP2Code/Simple_window.h"
#include "ch13.h"
#include <algorithm>

using namespace std;

namespace ch13
{
	namespace excercise
	{
		namespace e01
		{
			void Arc::draw_lines() const
			{
				if (fill_color().visibility())
				{
					fl_color(fill_color().as_int());
					fl_pie 
					(
						point(0).x,
						point(0).y,
						major() + major() - 1,
						minor() + minor() - 1,
						start,
						end
					);
					fl_color(color().as_int());
				}
				if (fill_color().visibility())
				{
					fl_color(color().as_int());
					fl_arc 
					(
						point(0).x,
						point(0).y,
						major() + major() - 1,
						minor() + minor() - 1,
						start,
						end
					);
				}
			}

			void main()
			{
				Graph_lib::Vector_ref<Shape>
					arcs;				
				arcs.push_back (new Arc {Point {400, 300}, 100, 200, 0, 60});				
				arcs[0].set_fill_color (Color::Color_type::red);
				arcs.push_back (new Arc {Point {400, 300}, 100, 200, 60, 120});
				arcs[1].set_fill_color (Color::Color_type::yellow);
				arcs.push_back (new Arc {Point {400, 300}, 100, 200, 120, 180});
				arcs[2].set_fill_color (Color::Color_type::green);
				Simple_window
					window	{Point {2200, 500}, 800, 600, ""};
				for (int i = 0 ; i < arcs.size(); ++i)
					window.attach (arcs[i]);
				window.wait_for_button();
			}
		}

		namespace e02
		{
			void Arc::draw_lines() const
			{
				if (color().visibility()) 
				{
					int 
						r {radius()};
					fl_color(color().as_int());
					fl_arc
					(
						point(0).x,
						point(0).y,
						r + r, 
						r + r,
						start,
						start + 90
					);
				}
			}

			void main()
			{
				Vector_ref<Shape>
					shapes;
				int
					x {100},
					y {100},
					w {100},
					h {100},
					r {50};

				shapes.push_back(
					new Line { 
						Point {x + r, y},
						Point {x + w + r, y}
					}
				);

				Simple_window
					window	{Point {2200, 500}, 600, 400, ""};
				for (int i = 0 ; i < shapes.size(); ++i)
					window.attach (shapes[i]);
				window.wait_for_button();
			}
		}
	}
}