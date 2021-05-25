#pragma once
#include <sstream>
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

		namespace e08
		{
			Octagon::Octagon	(Point p, int r)
			{
				double
					sin_pi_4th {0.707106781186548},
					in_x	{0.},
					in_y	{- double(r)};
				for (int i = 0; i < 8; ++i)
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

		namespace e11a
		{			
			void Binary_tree::set_points (int tiers)
			{
				add	(anchor_);
				for (int i = 1; i < (2 << tiers); ++i)
				{
					
					int
						pre_index {i >> 1};
					double
						angle	{angle_factors[i] * slope_};
					add ({
						point (pre_index).x + int (round (sin (angle) * length_)),
						point (pre_index).y - int (round (cos (angle) * length_))
					});
				};										
//			/* 0 */			
//				add	(anchor_);
//			/* 1 */			
//				add ({
//					point (0).x + int (round (sin (0. * slope_) * double (length_))), 
//					point (0).y - int (round (cos (0. * slope_) * double (length_)))
//				});
/////////////////////
//			/* 2 */				
//				add ({
//					point (1).x + int (round (sin (-1. * slope_) * double (length_))),
//					point (1).y - int (round (cos (1. * slope_) * double (length_)))
//				});
//			/* 3 */			
//				add ({
//					point (1).x + int (round (sin (1. * slope_) * double (length_))),
//					point (1).y - int (round (cos (1. * slope_) * double (length_)))
//				});
/////////////////////
//			/* 4 */		
//				add ({
//					point (2).x + int (round (sin (-2. * slope_) * double (length_))),
//					point (2).y - int (round (cos (2. * slope_) * double (length_)))
//				});
//			/* 5 */			
//				add ({
//					point (2).x + int (round (sin (0. * slope_) * double (length_))),
//					point (2).y - int (round (cos (0. * slope_) * double (length_)))
//				});
//			/* 6 */
//				add ({
//					point (3).x + int (round (sin (0. * slope_) * double (length_))),
//					point (3).y - int (round (cos (0. * slope_) * double (length_)))
//				});
//			/* 7 */		
//				add ({
//					point (3).x + int (round (sin (2. * slope_) * double (length_))),
//					point (3).y - int (round (cos (2. * slope_) * double (length_)))
//				});
/////////////////////
//			/* 8 */			
//				add ({
//					point (4).x + int (round (sin (-3. * slope_) * double (length_))),
//					point (4).y - int (round (cos (-3. * slope_) * double (length_)))
//				});
//			/* 9 */			
//				add ({
//					point (4).x + int (round (sin (-1. * slope_) * double (length_))),
//					point (4).y - int (round (cos (-1. * slope_) * double (length_)))
//				});
//			/* 10 */				
//				add ({
//					point (5).x + int (round (sin (-1. * slope_) * double (length_))),
//					point (5).y - int (round (cos (-1. * slope_) * double (length_)))
//				});
//			/* 11 */			
//				add ({
//					point (5).x + int (round (sin (1. * slope_) * double (length_))),
//					point (5).y - int (round (cos (1. * slope_) * double (length_)))
//				});
//			/* 12 */				
//				add ({
//					point (6).x + int (round (sin (-1. * slope_) * double (length_))),
//					point (6).y - int (round (cos (-1. * slope_) * double (length_)))
//				});
//			/* 13 */			
//				add ({
//					point (6).x + int (round (sin (1. * slope_) * double (length_))),
//					point (6).y - int (round (cos (1. * slope_) * double (length_)))
//				});
//			/* 14 */			
//				add ({
//					point (7).x + int (round (sin (1. * slope_) * double (length_))),
//					point (7).y - int (round (cos (1. * slope_) * double (length_)))
//				});
//			/* 8 */			
//				add ({
//					point (7).x + int (round (sin (3. * slope_) * double (length_))),
//					point (7).y - int (round (cos (3. * slope_) * double (length_)))
//				});
			}

			void Binary_tree::set_angle_factors(int tiers)
			{
				for (int i = angle_factors.size(); i < (2 << tiers); ++i)
				{
					int
						sign {((i & 1) << 1) - 1};
					angle_factors.push_back (angle_factors [i >> 1] + double(sign));
				}
			}

			void Binary_tree::draw_lines () const
			{
				if (color ().visibility () && number_of_points () > 0)
				{					
					fl_color (color ().as_int ());
					for (int i = 1; i < number_of_points (); ++i)
					{
						fl_line (
							point (i >> 1).x,
							point (i >> 1).y,
							point (i).x,
							point (i).y
						);
					}
				}
			}

			void main ()
			{
				Simple_window
					window	{ {1200, 500}, 600, 400, ""};
				Binary_tree
					tree { {300,350}, 20, 0.5, 6};
				window.attach (tree);		
				window.wait_for_button ();
			}
		}

		namespace e11
		{			
			void Binary_tree::set_points (int tiers)
			{
				int
					up_side_down {false ? 1 : -1};
				add	(anchor_);
				for (int i = 1; i < (2 << tiers); ++i)
				{					
					int
						pre_index {i >> 1};
					double
						angle	{angle_factors[i] * slope_};
					add ({
						point (pre_index).x + int (round (sin (angle) * length_)),
						point (pre_index).y + int (round (cos (angle) * length_) * up_side_down)
					});
				};										
			}

			void Binary_tree::set_angle_factors(int tiers)
			{
				for (int i = angle_factors.size(); i < (2 << tiers); ++i)
				{
					int
						sign {((i & 1) << 1) - 1};
					angle_factors.push_back (angle_factors [i >> 1] + double(sign));
				}
			}

			void Binary_tree::draw_lines () const
			{
				if (color ().visibility () && number_of_points () > 0)
				{					
					fl_color (color ().as_int ());
					for (int i = 1; i < number_of_points (); ++i)
					{
						fl_line (
							point (i >> 1).x,
							point (i >> 1).y,
							point (i).x,
							point (i).y
						);
						int
							radius {int(round((length_ * 0.25)))};
						fl_arc (
							point (i).x - (radius >> 1),
							point (i).y - (radius >> 1),
							radius,
							radius,
							0.,
							360.
						);
						fl_pie (
							point (i).x - (radius >> 1),
							point (i).y - (radius >> 1),
							radius,
							radius,
							0.,
							360.
						);
					}
				}
			}

			void main ()
			{
				Simple_window
					window	{{1000, 500}, 600, 400, ""};
				Binary_tree
					tree { {300,300}, 16, 0.25, 12};
				window.attach (tree);		
				window.wait_for_button ();
			}
		}

		namespace e12
		{	
			void Binary_tree::draw_lines () const
			{
				if (color ().visibility () && number_of_points () > 0)
				{					
					fl_color (color ().as_int ());
					for (int i = 1; i < number_of_points (); ++i)
						draw_drawing(point(i), point(i >> 1));
				}
			}

			void Binary_tree::draw_drawing(Point p, Point pre) const
			{
				fl_pie (p.x - (3), p.y - (3), 3, 3, 0., 360.);
			}

			void main()
			{
				Simple_window
					window	{{1000, 500}, 800, 600, ""};
				Binary_tree
					tree {{400, 400}, 20, 0.125 * 3.14159265, 16};
				window.attach (tree);
				window.wait_for_button();
			}
		}

		namespace e13
		{
			void Binary_tree::draw_drawing	(Point p, Point pre) const
			{
				draw_branches(p, pre);
				draw_nodes(p);
			}
			void Binary_tree::draw_branches (Point p, Point pre) const
			{				
				fl_line (pre.x, pre.y, p.x, p.y);
			}
			void Binary_tree::draw_nodes	(Point p) const
			{				
				//fl_pie(p.x - 1, p.y - 1, 2, 2, 0., 360.);
			}

			void Arrow_tree::draw_branches(Point p, Point pre) const
			{
				double
					x1	{double(pre.x)},
					y1	{double(pre.y)},
					x2	{double(p.x)},
					y2	{double(p.y)},
					dart_size {0.125},
					delta_x	{x2 - x1},
					delta_y	{y2 - y1},
					mid_x	{x2 - delta_x * dart_size},
					mid_y	{y2 -delta_y * dart_size},
					x3	{mid_x - delta_y * dart_size * 0.5},
					y3	{mid_y + delta_x * dart_size * 0.5},
					x4	{mid_x + delta_y * dart_size * 0.5},
					y4	{mid_y - delta_x * dart_size * 0.5};
				fl_line (int(x1), int(y1), int(x2), int(y2));
				fl_line	(int(x3), int(y3), int(x2), int(y2));
				fl_line	(int(x4), int(y4), int(x2), int(y2));
			}

			void main()
			{
				Simple_window
					window	{{2200, 500}, 600, 400, ""};
				Arrow_tree
					tree	{{300, 300}, 50, 0.4, 4};
				tree.set_color	(Color::Color_type::dark_red);
				/*tree.set_style(Line_style::Line_style_type::dot);*/
				window.attach(tree);
				window.wait_for_button();
			}
		}

		namespace e14
		{
			Binary_tree::Binary_tree (Point anchor, double length, double slope , int tiers = 0) :
				anchor_ {anchor}, length_ {length}, slope_ {slope}
			{						
				if (tiers > 0)
				{
					set_angle_factors(tiers);
					set_points(tiers);
				}
			}
			void Binary_tree::set_angle_factors(int tiers)
			{
				for (int i = angle_factors.size(); i < (2 << tiers); ++i)
				{
					int
						sign {((i & 1) << 1) - 1};
					angle_factors.push_back (angle_factors [i >> 1] + double(sign));
				}
			}
			void Binary_tree::set_points (int tiers)
			{
				int
					up_side_down {false ? 1 : -1};
				add	(anchor_);
				for (int i = 1; i < (2 << tiers); ++i)
				{					
					int
						pre_index {i >> 1};
					double
						angle	{angle_factors[i] * slope_};
					add ({
						point (pre_index).x + int (round (sin (angle) * length_)),
						point (pre_index).y + int (round (cos (angle) * length_) * up_side_down)
					});
				};										
			}
			void Binary_tree::draw_lines () const
			{
				if (color ().visibility () && number_of_points () > 0)
				{					
					fl_color (color ().as_int ());
					for (int i = 1; i < number_of_points (); ++i)
					{
						draw_branches (point_ref(), i);
						draw_nodes (point_ref(), i);
					}
				}
			}

			void Binary_tree::draw_branches (vector<Point> & pr, int i) const
			{
				fl_line (
					pr[i >> 1].x,
					pr[i >> 1].y,
					pr[i].x,
					pr[i].y
				);
			}
			void Binary_tree::draw_nodes	(vector<Point> & pr, int i) const
			{
				static const int
					dx	{4},
					dy	{4};
				stringstream
					ss;
				ss << i;
				string
					str;
				ss >> str;
				fl_draw (
					str.c_str(),
					pr[i].x,
					pr[i].y
				);
			}

			void main()
			{
				Simple_window
					window	{{1000,500}, 600, 400, ""};
				Binary_tree
					tree	{{300, 250}, 100, 0.75 * 3.14, 6};
				window.attach(tree);
				window.wait_for_button();
			}
		}
	}
}