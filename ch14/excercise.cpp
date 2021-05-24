#pragma once
#include "ch14.h"

namespace ch14
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
				if (color().visibility())
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

			void Face::draw_lines() const
			{

				Circle::draw_lines();
				double
					center_x	{double(point(0).x)},
					center_y	{double(point(0).y)},
					eye_dist	{double(radius()) * 0.25};
				Graph_lib::Ellipse
					left {
						{radius() + int (center_x - eye_dist), radius() + int (center_y - eye_dist)},
						int(eye_dist * 0.25),
						int(eye_dist * 0.5)
					},
					right {
						{radius() + int (center_x + eye_dist), radius() + int (center_y - eye_dist)},
						int(eye_dist * 0.25),
						int(eye_dist * 0.5)
					};
				Color
					black {Color::Color_type::black};
				left.set_fill_color (black);
				right.set_fill_color (black);
				left.draw_lines();
				right.draw_lines();
			}

			void Smiley::draw_lines() const
			{
				Face::draw_lines();
				int
					smile_rad {int(double(radius())* 0.66)};
				Arc
					smile {{radius() + point(0).x, radius() + point(0).y}, smile_rad, smile_rad, 210, 330};
				smile.draw_lines();
			}

			void Frowny::draw_lines() const
			{
				Face::draw_lines();
				int
					smile_rad {int(double(radius())* 0.66)},
					smile_dist {int(double(radius() * 2))};
				Arc
					smile {
						Point {
							radius() + point(0).x, 
							smile_dist + point(0).y
						}, 
						smile_rad, 
						smile_rad, 
						60, 
						120
					};

				smile.draw_lines();
			}

			void main()
			{
				Simple_window
					window	{{2200, 500}, 600, 400, ""};
				Smiley
					smiley {{300, 200}, 150};
				Frowny 
					frowny {{300, 200}, 150};

				window.attach(frowny);

				window.wait_for_button();
			}
		}

		namespace e02
		{
			void main()
			{
				//Graph_lib::Shape
				//	shape	{};			// err C2248 cannot access protected member declared int class
			}
		}

		namespace e04
		{
			void main()
			{
				Simple_window
					window	{{2200, 500}, 600, 400, ""};
				Immobile_Circle
					i_c	{{300, 200}, 100};
				window.attach(i_c);
				Circle
					c
						{{300, 200}, 100};
				window.attach(c);
				while(true)
				{
					window.wait_for_button();
					c.move(1, 1);
					i_c.move(1,1);
				}
			}
		}

		namespace e05
		{
			void Striped_rectangle::draw_lines () const
			{
				if (color().visibility()) 									/// edge on top of fill
				{
					fl_color(color().as_int());
					fl_rect (
						point(0).x,
						point(0).y,
						width(),
						height()
					);
				}
				if (fill_color().visibility())
				{
					fl_color(fill_color().as_int());
					int
						x {point(0).x + 1};
					for (double i = 1.; int(i) < height() - 1; i *= 1.2)
					{
						int
							y {int(round(i)) + point(0).y};
						fl_line	(
							x,
							y,
							x + width() - 3,
							y
						);							
					}
				}
			}

			void main()
			{
				Simple_window
					window	{{2200, 500}, 600, 400, ""};
				Striped_rectangle
					rect {{100, 100}, 400, 200};
				rect.set_fill_color (Color::Color_type::black);
	
				window.attach(rect);
				window.wait_for_button();
			}
		}

		namespace e06a
		{
			void Striped_circle::draw_lines () const
			{
				Circle::draw_lines();
				if (color().visibility())
				{
					fl_color(color().as_int());
					int rad {radius()};
					for (double move = 2.; move <= radius(); move *= 1.5)
						fl_arc (
							point(0).x + rad - int(round(move)),
							point(0).y + rad - int(round(move)),
							int(round(2. * move)),
							int(round(2. * move)),
							0.,
							360
						);
				}
			}

			void main()
			{
				Simple_window
					window	{{880, 500}, 600, 400, ""};
				Striped_circle
					c	{{300, 200}, 150};
				c.set_color			(Color::Color_type::blue);
				c.set_fill_color	(Color::Color_type::cyan);
				window.attach(c);
				window.wait_for_button();
			}
		}	

		namespace e06b
		{
			void Striped_circle::draw_lines() const
			{
				//Circle::draw_lines();
				double
					in_x	{double(radius())},
					in_y	{0},
					angle	{1 * 3.14159265 / 180};
				for(int i = 0; i < 360; ++i)
				{
					double
						x		{in_y  * sin(angle) + in_x * cos(angle)},
						y		{-in_x  * sin(angle) + in_y * cos(angle)};
					in_x = x;
					in_y = y;
					fl_line	(
						point(0).x + radius() + int(round(x)),
						point(0).y + radius() + int(round(y)),
						point(0).x + radius() - int(round(x)),
						point(0).y + radius() + int(round(y)) 
					);
				}
			}
	
			void main()
			{
				Simple_window
					window	{{1100, 500}, 600, 400, ""};
				Striped_circle
					circle	{{300, 200}, 144};
				window.attach	(circle);
				window.wait_for_button();

			}
		}

		namespace e06
		{
			void Striped_circle::draw_lines() const
			{
				for(int i = -radius(); i < radius(); i+= 2)
				{
					double
						rad		{double(radius())},
						y		{double(i)},
						x		{sqrt(rad * rad - y * y)};

					fl_line	(
						point(0).x + radius() + int(round(x)),
						point(0).y + radius() + int(round(y)),
						point(0).x + radius() - int(round(x)),
						point(0).y + radius() + int(round(y)) 
					);
				};
			}
			void main()
			{
				Simple_window
					window	{{1000, 500},600, 400, ""};
				Striped_circle
					circle	{{300, 200}, 150};
				window.attach	(circle);
				window.wait_for_button();
			}
		}

		namespace e08a
		{
			void Octagon::draw_lines() const
			{
				Circle::draw_lines();
				double
					in_x	{double(radius())},
					in_y	{0},
					sin_pi_4th {0.707106781186548};
				for (int i = 0; i < 8; ++i)
				{
					double
						x	{(in_y + in_x) * sin_pi_4th},
						y	{(in_y - in_x) * sin_pi_4th};
					in_x = x;
					in_y = y;
					fl_line	(
						point(0).x + radius() + int(round(x)),
						point(0).y + radius() + int(round(y)),
						point(0).x + radius() - int(round(x)),
						point(0).y + radius() + int(round(y)) 
					);
				}

			}
			void main()
			{
				Simple_window
					window	{{1200, 620}, 600, 400,""};
				Octagon
					o	{{300, 200}, 150};
				window.attach	(o);
				window.wait_for_button();
			}
		}

		namespace e08b
		{
			Octagon::Octagon	(Point p, int r)
			{
				add ({p.x - r, p.y - r});
				double
					sin_pi_4th {0.707106781186548},
					in_x	{- double(r)},
					in_y	{- double(r)};
				for (int i = 0; i < 7; ++i)
				{
					double
						x	{(in_x + in_y) * sin_pi_4th},
						y	{(in_y - in_x) * sin_pi_4th};
					in_x = x;
					in_y = y;
					add ({p.x + int(x), p.y + int(y)});
				}						
			}
			void main()
			{
				Simple_window
					window	{{1200, 620}, 600, 400,""};
				Octagon
					o	{{300, 200}, 150};
				window.attach	(o);
				window.wait_for_button();
			}
		}
	}
}