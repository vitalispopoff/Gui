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

		namespace s03
		{



		}
	}
}