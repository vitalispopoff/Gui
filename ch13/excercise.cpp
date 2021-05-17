//#include "../_add_libs/PPP2Code/fltk.h"
//#include "../_add_libs/PPP2Code/Simple_window.h"
#include "../_add_libs/PPP2Code/Graph.h"
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

			Box::Box (Point p, int w, int h, int r) :
				width {w},
				height {h},
				radius {r}
			{
				/// ruling out points, lines, squares and circles.
				if (w <= (r + r) || h <= (r + r) || w <= 0 || h <= 0 || r <= 0)
					error("dimensions can must be positive, and the radius smaller than each: height, and width");
				int
				// horizontal coord
					x0	= p.x,
					x1	= p.x + r,
					x2	= p.x + w - r,
					x3	= p.x + w,
				// vertical coords
					y0	= p.y,
					y1	= p.y + r,
					y2	= p.y + h - r,
					y3	= p.y + h;
				// sides
				add ({x1, y0});
				add ({x2, y0});
				add ({x1, y3});
				add ({x2, y3});
				add ({x0, y1});
				add ({x0, y2});
				add ({x3, y1});
				add ({x3, y2});
				//arcs
				add ({x0, y0});
				add ({x0, y2 - r});
				add ({x1 + r, y2 - r});
				add ({x1 + r, y1 - r});
				//add ({p.x + r, p.y});
				//add ({p.x + w - r, p.y});
				//
				//add ({p.x + r, p.y + h});
				//add ({p.x + w - r, p.y + h});
				//
				//add ({p.x, p.y + r});
				//add ({p.x, p.y + h - r});
				//
				//add ({p.x + w, p.y + r});
				//add ({p.x + w, p.y + h - r});
				//
				//// and arcs
				//add ({p.x + r, p.y + r});
				//add ({p.x + r, p.y + h - r});
				//add ({p.x + w - r, p.y + h - r});
				//add ({p.x + w - r, p.y + r});
			}

			void Box::draw_lines() const
			{
				if (color().visibility())
				{
					for (int i = 0; i < 8; i += 2)
						fl_line (
							point(i).x,
							point(i).y,
							point(i + 1).x,
							point(i + 1).y
						);
					for (int i = 8; i < 12; ++i)
						fl_arc (
							point(i).x,
							point(i).y,
							radius + radius,
							radius + radius,
							((double(i) - 7) * 90),
							((double(i) - 7) * 90) + 90
						);
				}
			}

			void main()
			{
				Simple_window
					window {Point {2200, 500}, 600, 400, ""};
				Box
					box {Point {100, 100}, 200, 200, 50};
				window.attach (box);			
				window.wait_for_button();
			}

			void sketch01()
			{
				Vector_ref<Line>
					lines;
				int
					x {100},
					y {100},
					w {200},
					h {200},
					r {50};
				lines.push_back(
					new Line { 
						Point {x + r, y},
						Point {x + w - r, y}
					}
				);
				lines.push_back(
					new Line { 
						Point {x + r, y + h},
						Point {x + w - r, y + h}
					}
				);
				lines.push_back(
					new Line { 
						Point {x, y + r},
						Point {x, y + h - r}
					}
				);
				lines.push_back(
					new Line { 
						Point {x + w, y + r},
						Point {x + w, y + h - r}
					}
				);

				Vector_ref<e02::Arc>
					arcs;
				arcs.push_back(
					new e02::Arc { 
						Point {x + w - r, y + r},
						r,
						0				
					}
				);
				arcs.push_back(
					new e02::Arc { 
						Point {x + r, y + r},
						r,
						1				
					}
				);
				arcs.push_back(
					new e02::Arc { 
						Point {x + r, y + h - r},
						r,
						2				
					}
				);
				arcs.push_back(
					new e02::Arc { 
						Point {x + w - r, y + h - r},
						r,
						3				
					}
				);

				Simple_window
					window	{Point {2200, 500}, 600, 400, ""};
				for (int i = 0; i < lines.size(); ++i)
					window.attach (lines[i]);
				for (int i = 0; i < arcs.size(); ++i)
					window.attach (arcs[i]);
				window.wait_for_button();
			}
		}
	}
}