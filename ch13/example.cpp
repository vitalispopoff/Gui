//#include "../_add_libs/PPP2Code/Simple_window.h" /// including ch13.h which already includes this one.
#include "ch13.h"

namespace ch13
{
	namespace sample
	{
		void s01()
		{
			int
				x_size = 600,
				y_size = 400,
				x_grid = 80,
				y_grid = 40;
			Simple_window
				window	{Point {2200, 500}, x_size, y_size, ""};
			Lines
				grid;
			
			for (int x = x_grid; x < x_size; x += x_grid)
				grid.add(Point {x, 0}, Point{x, y_size});
			for (int y = y_grid; y < y_size; y += y_grid)
				grid.add(Point {0, y}, Point {x_size, y});

			Color
				color {Color::Color_type::black};

			grid.set_color (color);
			
			window.attach (grid);
			window.wait_for_button();
		}

		namespace s02
		{
			void Lines::add(Point p1, Point p2)
			{
				Shape::add(p1);									/// points are added independently, without any additional info on their relation
				Shape::add(p2);
			}
																/// this is unclear: a constructor with an empty return declared, 
																/// as a implementation of a constructor with slightly different input declaration...
			//void 
			Lines::Lines(initializer_list<pair<Point, Point>> lst)
			{
				for (auto p : lst)
					add (p.first, p.second);
			}


			void Lines::draw_lines() const
			{
				if (
					color.visibility()				///parametrized [0, 255]
					){
					for (
						int i = 1;					/// starting on 2nd point (the line ending one)
						i < number_of_points(); 
						i += 2						/// iterating by those line ending points
					){
						fl_line (					/// so the drawing is proceeded by fl_line
							point (i - 1).x,		/// calling the preceeding (the starting point) x
							point(i - 1).y,			///	and y
							point(i).x,				/// calling the actually iterated point x
							point(i).y				/// and y
						);
					}
				}
			}
		}

		//

		namespace s06
		{
			void Closed_polyline::draw_lines() const
			{
				Open_polyline::draw_lines();
				if (number_of_points() > 2 && color().visibility())
				{	
					int													/// reformated to make it a bit more readable
						lastIndex	{number_of_points() - 1},
						lastX		{point(lastIndex).x},
						lastY		{point(lastIndex).y};
					fl_line (lastX, lastY, point(0).x, point(0).y);
				}
			}
		}

		namespace s07
		{
			void Polygon::add(Point p)
			{
				Closed_polyline::add(p);
			}
		}

		namespace s08
		{
			Rectangle::Rectangle(Point xy, int ww, int hh) :
				w {ww}, h{hh}
			{
				if (h <= 0 || w <= 0)
					error ("Bad rectangle: non-positive side");
				add(xy);										/// this adds anchor to the object
			}
			Rectangle::Rectangle(Point x, Point y) :
				w {y.x - x.x}, h {y.y - x.y}
			{
				if (h <= 0 || w <= 0)
					error("Bad rectangle: first point is not tope left");
				add(x);
			}

			void Rectangle::draw_lines() const
			{
				if (fill_color().visibility())
				{
					fl_color(fill_color().as_int());
					fl_rectf(point(0).x, point(0).y, w, h);
				}
				if (color().visibility())
				{
					fl_color(color().as_int());
					fl_rect(point(0).x, point(0).y, w, h);
				}
			}
		}

		namespace s09
		{
			void s09_main()
			{
				/// these need to be inside the function, as they were outside, the verby red error report window appeared.
				Simple_window
					window	{Point {2200, 500}, 500, 300, ""};
				Graph_lib::Rectangle
					rect00	{Point {150, 100}, 200, 100},
					rect11	{Point {50, 50}, Point {250, 150}},
					rect12	{Point {50, 150}, Point {250, 250}},
					rect21	{Point {250, 50}, 200, 100},
					rect22	{Point {250, 150}, 200, 100};

				rect00.set_color (Color::Color_type::yellow);
				rect11.set_color (Color::Color_type::blue);
				rect12.set_color (Color::Color_type::red);
				rect21.set_color (Color::Color_type::green);

				rect22.set_color (Color(Color::Color_type::white));

				rect00.set_fill_color (Color::Color_type::yellow);
				rect11.set_fill_color (Color::Color_type::blue);
				rect12.set_fill_color (Color::Color_type::red);
				rect21.set_fill_color (Color::Color_type::green);

				window.attach (rect00);
				window.attach (rect11);
				window.attach (rect12);
				window.attach (rect21);
				window.attach (rect22);
				
				window.wait_for_button();
				window.resize (700, 300);						/// that's out of curiosity
				rect11.move(400, 0);
				rect11.set_fill_color(Color::Color_type::cyan);

				window.wait_for_button();
				window.put_on_top(rect00);


				window.wait_for_button();
				Line_style
					style {Line_style::Line_style_type::solid, 3};

				rect00.set_fill_color (Color::Transparency::invisible);
				rect11.set_fill_color (Color::Transparency::invisible);
				rect12.set_fill_color (Color::Transparency::invisible);
				rect21.set_fill_color (Color::Transparency::invisible);
								
				rect00.set_style (style);
				rect11.set_style (style);
				rect12.set_style (style);
				rect21.set_style (style);

				window.wait_for_button();
			}
		}

		namespace s11
		{
			void s11_main()
			{
				using Graph_lib::Rectangle;

				Simple_window
					window {Point {2200, 500}, 800, 600, ""};
				Vector_ref<Rectangle> 
					vr;
				int
					size {20};
				Color
					none {Color::Transparency::invisible};

				if (false)
					for (int i = 0; i < 16; ++i)
						for (int j = 0; j < 16; ++j)
						{
							vr.push_back (new Rectangle {Point {i * 20, j * 20}, 20, 20});
							vr [vr.size() - 1].set_fill_color(Color {i * 16 + j});
							window.attach (vr [vr.size() - 1]);
						}				
				else
					for (int i = 0; i < 256; ++i)
					{
						int
							index1	{i >> 4},					/// increases by 1 every 16 ticks
							index2	{i & 15};					/// increases from 0 to 15 every tick
						Point
							anchor	{index1 * size, index2 * size};

						vr.push_back (new Rectangle {anchor, size, size});					
						Rectangle
							& rect = vr [vr.size() - 1];
						Color
							//color {(index1 << 4) + index2};		/// index1 now grows by 16 every 16 ticks
							//color {(i & (255 - 15)) + index2};	/// i (2-255) gets last 4 digits cleared to 0 - XANDing by fixed value (12 1s and 4 zeroes)
							color {(i & 0xF0) + index2};			/// as above but using hexadecimal
							//color {(i ^ index2) + index2};		/// as above, but we change only the 1s : XORing the last 4 bits by themselves
							//color {(i ^ index1) + index2};		/// this is mad.

						rect.set_fill_color (color);
						rect.set_color (none);
						window.attach (rect);
					}
				window.wait_for_button();
			}
		}

		namespace s12
		{
			void Text::draw_lines() const
			{
				fl_draw (
					lab.c_str(),								///provides a 'char[] * ' ended with a null char
					point(0).x,									/// anchor x coord
					point(0).y									/// anchor y coord
				);
			}
		}

		namespace s13
		{
			Circle::Circle (Point p, int rr) :
				r {rr}
			{
				add (Point { p.x - r, p.y - r});
			}

			Point Circle::center() const
			{
				return {point(0).x + r, point(0).y + r};
			}

			void Circle::draw_lines() const
			{
				if (color().visibility())
					fl_arc (
						point (0).x, 
						point (0).y, 
						r + r, 
						r + r, 
						0, 
						360
					);
			}
		}

		namespace s14
		{
			Point Ellipse::focus1() const						/// rewritten to branchless and cut into smaller steps
			{
				int
					centerX			{center().x},
					centerY			{center().y};
				double	
					cache1			{abs(w * w - h * h)},		/// long semi-axis (w) is equal to focal-periphery line, which is a hypotenuse for a square triangle: focal-center-periphery.
					eccentricity	{sqrt (cache1)};			/// center-focal distance, taken from the pithagorean above
				int
					focalDistX		{(h <= w) * int (eccentricity)},	/// zeroes out for a vertically oriented ellipse
					focalDistY		{(h > w) * int (eccentricity)};		/// zeroes out for a horizontally oriented ellipse
				
				return {centerX + focalDistX, centerY + focalDistY};

				//if (h <= w)
				//	return
				//		{centerX + int (sqrt (double (w * w - h * h))), center().y};
				//else
				//	return
				//		{centerX, center().y + int (sqrt (double (h * h - w * w)))};
			}

		}

		namespace s15
		{

		}
			


	}
}