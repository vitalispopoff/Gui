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

			void Rectangle::draw_lines() const					/// added to clean the error list
			{}
		}

		namespace s09
		{
			
			void s09_main()
			{
				/// these need to be inside the function, as they were outside, the verby red error report window appeared.
				Simple_window
					window	{Point {2200, 500}, 600, 400, ""};
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
			}

		}
	}
}