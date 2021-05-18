#include <iostream>
#include <algorithm>

//#include "../_add_libs/PPP2Code/fltk.h"
//#include "../_add_libs/PPP2Code/Simple_window.h"
#include "../_add_libs/PPP2Code/Graph.h"
#include "ch13.h"

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
				add ({x2 - r, y2 - r});
				add ({x2 - r, y1 - r});
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
					box {Point {100, 100}, 200, 100, 30};
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

		namespace e03
		{
			Arrow::Arrow (Point start, Point end, double s = 0.125)
			{
				add (end);
				add (start);
				double
					x1	{double(start.x)},
					y1	{double(start.y)},
					x2	{double(end.x)},
					y2	{double(end.y)},
					dart_size {s},
					delta_x	{x2 - x1},
					delta_y	{y2 - y1},
					mid_x	{x2 - delta_x * dart_size},
					mid_y	{y2 -delta_y * dart_size};
				add (Point {
						int(mid_x - delta_y * dart_size * 0.5),
						int(mid_y + delta_x * dart_size * 0.5)
				});
				add (Point {
						int(mid_x + delta_y * dart_size * 0.5),
						int(mid_y - delta_x * dart_size * 0.5)
				});
			}

			void Arrow::draw_lines() const
			{
				if (color().visibility())
					for (int i = 1; i < 4; ++i)
						fl_line (
							point(i).x,
							point(i).y,
							point(0).x,
							point(0).y
						);
			}

			void main()
			{				
				Simple_window
					window {Point {2200, 500}, 600, 400, ""};
				Arrow
					arrow {{100, 380}, {540, 76}};
				window.attach(arrow);
				window.wait_for_button();
			}

			
			void sketch01()
			{
				double					
					x1		{200},
					x2		{400},
					y1		{200},
					y2		{300},
					
					dart_size {0.125},
					delta_x	{x2 - x1},
					delta_y	{y2 - y1},
					mid_x	{x2 - delta_x * dart_size},
					mid_y	{y2 -delta_y * dart_size},
					x3		{mid_x - delta_y * dart_size * 0.5},
					y3		{mid_y + delta_x * dart_size * 0.5},
					x4		{mid_x + delta_y * dart_size * 0.5},
					y4		{mid_y - delta_x * dart_size * 0.5}
					;

				Simple_window
					window {Point {2200, 500}, 600, 400, ""};

				Line
					l1	{{int(x1), int(y1)}, {int(x2), int(y2)}},
					l2	{{int(x3), int(y3)}, {int(x2), int(y2)}},
					l3	{{int(x4), int(y4)}, {int(x2), int(y2)}};

				window.attach (l1);
				window.attach (l2);
				window.attach (l3);

				window.wait_for_button();		
			}
		}

		namespace e04
		{
			using namespace Graph_lib;
			Point & n	(Graph_lib::Rectangle & r)
			{
				Point
					p  {r.point(0).x + (r.width() >> 1), r.point(0).y},
					& result = p;
				return result;
			}
			Point & s (Graph_lib::Rectangle & r)
			{
				Point 
					p {r.point(0).x + (r.width() >> 1),r.point(0).y + r.height()},
					& result = p;
				return result;
			}
			Point & e (Graph_lib::Rectangle & r)
			{
				Point 
					p	{r.point(0).x + r.width(),r.point(0).y + (r.height() >> 1)},
					& result = p;
				return result;
			}
			Point & w (Graph_lib::Rectangle & r)
			{
				Point
					p	{r.point(0).x,r.point(0).y + (r.height() >> 1)},
					& result = p;
				return result;
			}			
			Point & nw (Graph_lib::Rectangle & r)
			{
				Point 
					p = r.point(0),
					& result = p;
				return result;
			}
			Point & ne (Graph_lib::Rectangle & r)
			{
				Point
					p	{r.point(0).x + r.width(), r.point(0).y},
					& result = p;
				return result;
			}
			Point & se (Graph_lib::Rectangle & r)
			{
				Point
					p	{r.point(0).x + r.height(), r.point(0).y + r.width()},
					& result = p;
				return result;
			}
			Point & sw (Graph_lib::Rectangle & r)
			{
				Point
					p	{r.point(0).x, r.point(0).y + r.height()},
					& result = p;
				return result;
			}
			
			void main()
			{
				Simple_window
					window {{2200, 500}, 600, 400, ""};
				Graph_lib::Rectangle
					rect {{100, 100}, 250, 250};
				Graph_lib::Polygon
					poly1;
				poly1.add(n(rect));
				poly1.add(e(rect));
				poly1.add(s(rect));
				poly1.add(w(rect));
				poly1.set_color(Color::Color_type::cyan);
				window.attach(rect);
				window.attach(poly1);
				window.wait_for_button();		
			}
		}

		namespace e05
		{
			int arc_dist (int r)
			{
				double
					result =  double(r);
					result -= (result * 1.41421356 * 0.5);
				return int(result);				
			}
			// 1.41421356
					using namespace Graph_lib;
			Point & n	(Graph_lib::Circle & r)
			{
				Point
					p  {r.point(0).x + (r.radius() >> 1), r.point(0).y},
					& result = p;
				return result;
			}
			Point & s (Graph_lib::Circle & r)
			{
				Point 
					p {r.point(0).x + (r.radius() >> 1),r.point(0).y + r.radius()},
					& result = p;
				return result;
			}
			Point & e (Graph_lib::Circle & r)
			{
				Point 
					p	{r.point(0).x + r.radius(),r.point(0).y + (r.radius() >> 1)},
					& result = p;
				return result;
			}
			Point & w (Graph_lib::Circle & r)
			{
				Point
					p	{r.point(0).x,r.point(0).y + (r.radius() >> 1)},
					& result = p;
				return result;
			}			
			Point & nw (Graph_lib::Circle & r)
			{
				int
					dist {arc_dist(r.radius())};
				Point 
					p	{r.point(0).x + dist, r.point(0).y + dist},
					& result = p;
				return result;
			}
			Point & ne (Graph_lib::Circle & r)
			{
				int
					dist {arc_dist(r.radius())};
				Point
					p	{r.point(0).x + 2 * r.radius() - dist, r.point(0).y + dist},
					& result = p;
				return result;
			}
			Point & se (Graph_lib::Circle & r)
			{
				int
					dist {2 * r.radius() - arc_dist(r.radius())};
				Point
					p	{r.point(0).x + dist, r.point(0).y + dist},
					& result = p;
				return result;
			}
			Point & sw (Graph_lib::Circle & r)
			{
				int
					dist {arc_dist(r.radius())};
				Point
					p	{r.point(0).x + dist, r.point(0).y + 2 * r.radius() - dist},
					& result = p;
				return result;
			}

			void main()
			{
				Circle
					circle {Point{300, 300}, 150};
				Graph_lib::Polygon
					poly1;
				poly1.add(nw(circle));
				poly1.add(ne(circle));
				poly1.add(se(circle));
				poly1.add(sw(circle));
				poly1.set_color (Color::Color_type::blue);
				Simple_window
					window {{2200, 500}, 800, 600, ""};
				window.attach(circle);
				window.attach(poly1);
				window.wait_for_button();
			}
		}

		namespace e06
		{
			void main()
			{
				Vector_ref<Shape>
					shapes;
				shapes.push_back (new Box {{100, 100}, 100, 30, 10});	//b_win	
				shapes.push_back (new Box {{250, 100}, 100, 30, 10});	//b_ls	
				shapes.push_back (new Box {{400, 100}, 100, 30, 10});	//b_col	
				shapes.push_back (new Box {{80, 200}, 140, 30, 10});	//b_s_w	
				shapes.push_back (new Box {{250, 200}, 100, 30, 10});	//b_shape
				shapes.push_back (new Box {{400, 200}, 100, 30, 10});	//b_p		
				shapes.push_back (new Box {{20, 300}, 60, 30, 10});		// b_line
				shapes.push_back (new Box {{100, 300}, 60, 30, 10});	// b_lines
				shapes.push_back (new Box {{180, 300}, 60, 30, 10});	// b_polygon
				shapes.push_back (new Box {{260, 300}, 60, 30, 10});	// b_axis
				shapes.push_back (new Box {{340, 300}, 60, 30, 10});	// b_rect
				shapes.push_back (new Box {{420, 300}, 60, 30, 10});	// b_text
				shapes.push_back (new Box {{500, 300}, 60, 30, 10});	// b_image
				shapes.push_back (new Arrow {Point {80 + 70, 200}, {100 + 50, 100 + 30}});
				
				shapes.push_back (new Arrow{Point {20 + 30, 300}, {250 + int(100 * 0.16), 200 + 30}, 0.0625});
				shapes.push_back (new Arrow{Point {100 + 30, 300}, {250 + int(100 * 0.28), 200 + 30}, 0.0625});
				shapes.push_back (new Arrow{Point {180 + 30, 300}, {250 + int(100 * 0.40), 200 + 30}, 0.0625});
				shapes.push_back (new Arrow{Point {260 + 30, 300}, {250 + int(100 * 0.52), 200 + 30}, 0.0625});
				shapes.push_back (new Arrow{Point {340 + 30, 300}, {250 + int(100 * 0.64), 200 + 30}, 0.0625});
				shapes.push_back (new Arrow{Point {420 + 30, 300}, {250 + int(100 * 0.76), 200 + 30}, 0.0625});
				shapes.push_back (new Arrow{Point {500 + 30, 300}, {250 + int(100 * 0.88), 200 + 30}, 0.0625});
					

				Simple_window
					window	{{2200, 500}, 600, 400, ""};
				for (int i = 0; i < shapes.size() ; ++i)
					window.attach (shapes[i]);
				window.wait_for_button();
			}
		}

		namespace e08
		{
			Regular_hexagon::Regular_hexagon (Point p, int r) :
				center{p}, radius {r}
			{
				int
					distance {int(double(r) * 0.5 * 1.73205081)},	// height of a r-sided equilateral triangle: 0.5*r*sqrt(3)
					half_r {int(double(r) * 0.5)};
				add ({p.x, p.y - r});
				add ({p.x + distance, p.y - half_r});
				add ({p.x + distance, p.y + half_r});
				add ({p.x, p.y + r});
				add ({p.x - distance, p.y + half_r});
				add ({p.x - distance, p.y - half_r});
			}

			void main()
			{
				Simple_window
					window {{2200, 500}, 800, 600, ""};
				Regular_hexagon 
					reg_hex	{{300, 300}, 200};
				window.attach (reg_hex);
				Circle
					circle	{{300, 300}, 200};
				window.attach (circle);
				window.wait_for_button();
			}
		}

		namespace e09
		{
			void main()
			{				
				using e08::Regular_hexagon;
				Vector_ref<Regular_hexagon>
					shapes;
				int 
					coords	{20},
					radius	{100};
				for (int i = 0; i < 256; ++i)
				{
					//shapes.add (new Regular_Hexagon
					int						
						row {i >> 4},
						column {i & 15},
						horizontal {column * 2 + (row & 1)}, 	// shapes move horizontally by 2r, but every other row is moved by add. r						
						vertical {(row << 1)};
					shapes.push_back (
						new Regular_hexagon {
							{
								int(round(
									double(horizontal) * 0.5 * 1.73205081 * double(radius)	// moves by heignt of an equilateral triangle of radius sizes side
								)) + coords, 
								int(round(
									double(vertical) * 0.75 * double(radius)
								)) + coords
							}, 
							radius
						}
					);
				}
				Simple_window
					window {{2200, 500}, 600, 400, ""};
				for (int i = 0; i < shapes.size(); ++i)
					window.attach (shapes[i]);
				window.wait_for_button();
			}
		}

		namespace e10
		{
			Regular_polygon::Regular_polygon (Point p, int s, int r) :
				sides {s}, radius {r}
			{
				if (s < 3)
					error("make it at least a triangle...");

				double 
					center_x	{double(p.x)},
					center_y	{double(p.y)},
					angle	{2 * 3.14159265 / double(s)},
					sine	{sin(angle)},
					cosine	{cos(angle)};
				add ({p.x, p.y - r});
				for (int i = 1 ; i < s ; ++i)
				{
					double
						cache_x {double (point(i - 1).x) - center_x},
						cache_y {double (point(i - 1).y) - center_y},
						x		{center_x + cache_x * cosine + cache_y * sine},
						y		{center_y + cache_y * cosine - cache_x * sine};
					add	({int(x), int(y)});
				}
			}

			void main()
			{
				Regular_polygon
					poly	{Point {300, 200}, 7, 150};
				Simple_window
					window	{{2200, 500}, 600, 400, ""};

				window.attach(poly);
				window.wait_for_button();
			}
		}

		namespace e11
		{
			void main()
			{
				Simple_window
					window	{{2200, 500}, 600, 400 ,""};
				Axis
					ax_x	{Axis::Orientation::x, {100, 200}, 400},
					ax_y	{Axis::Orientation::y, {300, 350}, 300};
				window.attach(ax_x);
				window.attach(ax_y);
				int
					center_x	{300},
					center_y	{200},
					vert_rad	{150},
					hori_rad	{100};
				Graph_lib::Ellipse
					e	{{center_x, center_y}, vert_rad, hori_rad};
				window.attach(e);
				double
					segment	{10. * 2.},								/// sqrt(100 * 100 / 25) = sqrt *(100 * 4)
					f_x		{(4 * segment) * 1.5},
					f_y		{3 * segment};				
				Point
					p1	{e.focus1()},
					p2	{e.focus2()},
					p3	{300 - int(f_x), 200 - int (f_y)};				
				Line
					l1	{p1, p3},
					l2	{p2, p3};
				window.attach(l1);
				window.attach(l2);
				Mark
					f1	{p2, '+'},
					f2	{p2, '+'},
					f3	{p3, '+'};		
				window.attach(f1);
				window.attach(f2);
				window.attach(f3);
				window.wait_for_button();
			}
		}

		namespace e12
		{
			void main()
			{
				int
					s {12},
					center_x {300},
					center_y {200},
					radius	{100};
				double
					angle	{2 * 3.14159265 / double (s)},
					sine	{sin(angle)},
					cosine	{cos(angle)};
				Simple_window
					window		{{2200, 500}, 600, 400, ""};
				Circle
					circle {{center_x, center_y}, radius};
				window.attach(circle);
				Mark
					mark	{{center_x + 100, center_y}, '+'};
				window.attach(mark);
				while (true)
				{
					window.wait_for_button();
					double
						in_x	{double (mark.point(0).x) - double (center_x)},
						in_y	{double (mark.point(0).y) - double (center_y)},
						out_x	{in_x * cosine + in_y * sine},
						out_y	{in_y * cosine - in_x * sine},
						dx		{in_x - out_x},
						dy		{in_y - out_y};
						cout 
							<< in_x << '\t' << in_y << endl;
					//mark.move	(int (dx), int (dy));
					mark.move	(int(round(-dx)), int(round(-dy)));		// without rounding the mark spirals in towards the circle center
				};			
			}
		}
	}
}