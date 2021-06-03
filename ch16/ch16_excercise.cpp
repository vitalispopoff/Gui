
#include "ch16.h"

namespace ch16
{
	namespace excercise
	{
		namespace e01
		{
			My_window::My_window (
				Point xy,
				int w,
				int h,
				string & title
				) :
				Window {xy, w, h, title},
				//iter {{((w - 50)>> 1), ((h - 20) >> 1)}, 50, 20, ""},
				but_next {{x_max () - 100, 0}, 50, 20, "Next", [] (Address, Address pw) {reference_to <My_window> (pw).next();}},
				but_quit {{x_max () - 50, 0}, 50, 20, "Quit", [] (Address, Address pw) {reference_to <My_window> (pw).quit();}}
			{
				//attach (iter);
				attach (but_next);
				attach (but_quit);
			}
			
			Derived_window::Derived_window (Point xy, int w, int h, string & title) :
				My_window {xy, w, h, title},
				iter {{((w - 20)>> 1), ((h - 20) >> 1)}, 20, 20, ""}
			{
				attach (iter);
			}
			int main()
			{
				string
					title;
				Derived_window
					window {{2200, 500}, 600, 400, title};
				window.wait_for_next();
				return gui_main();			
			}
		}

		namespace e02
		{
			Checker_window::Checker_window (Point xy, int w, int h, string & title) :
				My_window {xy, w, h, title},
				b0 {
					{0, 20},
					w >> 1, 
					(h - 20) >> 1, 
					"", 
					[] (Address, Address pw) {reference_to <Checker_window> (pw).action0();}
				},
				b1 {
					{1 + (w >> 1), 20},
					(w >> 1),
					((h - 20) >> 1),
					"", 
					[] (Address, Address pw) {reference_to <Checker_window> (pw).action1();}
				},
				b2 {
					{0, 21 + ((h - 20) >> 1)},
					w >> 1, 
					(h - 20) >> 1, 
					"", 
					[] (Address, Address pw) {reference_to <Checker_window> (pw).action2();}
				},
				b3 {
					{1 + (w >> 1), 21 + ((h - 20) >> 1)},
					w >> 1, 
					(h - 20) >> 1, 
					"", 
					[] (Address, Address pw) {reference_to <Checker_window> (pw).action3();}
				}
			{
				attach (b0);
				attach (b1);
				attach (b2);
				attach (b3);
				wait_for_next();
			}
			int main()
			{				
				string
					title;
				Checker_window
					window {{2200, 500}, 600, 400, title};
					return gui_main();
			}
		}

		namespace e03
		{							
			Rand_button_window::Rand_button_window (Point xy, int w, int h, string & title) :
				My_window {xy, w, h, title},
				button {
					{(w - 60) >> 1, (h - 40) >> 1},
					60,
					40,
					"",
					[] (Address, Address pw) { reference_to <Rand_button_window> (pw).relocate();}
				},
				cover {{0, 0}, filename, Suffix::Encoding::jpg}
			{
				attach (button);
				cover.set_mask (
					//button.loc, 
					{(w - 60) >> 1, (h - 40) >> 1},
					button.width, 
					button.height
				);
				cover.move (button.loc.x, button.loc.y);
				attach (cover);
			}

			void Rand_button_window::relocate()
			{
				int
					dx_min	{-button.loc.x},
					dx_max	{x_max () - button.width + dx_min},
					dy_min	{- button.loc.y},
					dy_max	{y_max () - button.height + dy_min},
					
					dx	= rand_int (dx_min, dx_max),
					dy = rand_int (dy_min, dy_max);

				button.move (dx, dy);
				cover.set_mask(button.loc, button.width, button.height);
				cover.move (dx, dy);
			}

			int main()
			{
				string
					t;
				Rand_button_window
					win {{2200, 500}, 600, 400, t};
				win.wait_for_next();
				return gui_main();
			}
		}

		namespace e04
		{
			Regular_polygon::Regular_polygon (Point center, int apothem, int sides) 
			{
				double
					angle	{2 * 3.14159265 / double (sides)},
					sine	{sin(angle)},
					cosine	{cos(angle)};
				add ({0, -apothem});
				for (int i = 0; i < sides - 1; ++i)
				{
					double
						x	{double (point(i).x) * cosine + double (point(i).y) * sine},
						y	{double (point(i).y) * cosine - double (point(i).x) * sine};
					add ({int (round (x)), int (round (y))});
				}
				move (center.x, center.y);
			}

			Polygon_window::Polygon_window (Point xy, int w, int h, string & title) :
				Window {xy, w, h, title},
				b_quit {{x_max () - 50, 0}, 50, 20, "Quit", [] (Address, Address pw) {reference_to <Polygon_window> (pw).hide();}},
				menu {{b_quit.loc.x - 5 * 20, 0}, 20, 20, Menu::Kind::horizontal, ""},
				in_a {{menu.loc.x - 20 - 40, 0}, 40, 20, "A"},
				in_y {{in_a.loc.x - 20 - 40, 0}, 40, 20, "Y"},
				in_x {{in_y.loc.x - 20 - 40, 0}, 40, 20, "X"}
			{
				attach (b_quit);					
				menu.attach (new Button {{0, 0}, 0, 0, "T", [] (Address, Address pw) {reference_to <Polygon_window> (pw).pgn(3);}});
				menu.attach (new Button {{0, 0}, 0, 0, "S", [] (Address, Address pw) {reference_to <Polygon_window> (pw).sqr();}});
				menu.attach (new Button {{0, 0}, 0, 0, "H", [] (Address, Address pw) {reference_to <Polygon_window> (pw).pgn(6);}});
				menu.attach (new Button {{0, 0}, 0, 0, "C", [] (Address, Address pw) {reference_to <Polygon_window> (pw).cir();}});
				attach (menu);
				attach (in_a);
				attach (in_y);
				attach (in_x);
			}

			void Polygon_window::pgn(int sides)
			{
				double
					cosine = cos (3.14159265 / double (sides)); /// based on apothem, we calculate a circumradius, so need half of the inner angle
				int 
					x = get_x(),
					y = get_y(),
					a = get_a(),
					cr = int (round (double (a) / cosine));				 
				if (a <= 0 
					|| cr > (x_max() << 1) 
					|| x < cr
					|| x > x_max() - cr 
					|| y < cr 
					|| y > y_max() - cr
				)
					return;			
				shapes.push_back (new Regular_polygon {{x, y}, cr, sides});
				attach (shapes [shapes.size() - 1]);
				redraw();
			}

			void Polygon_window::cir()
			{
				int
					x = get_x(),
					y = get_y(),
					a = get_a();
				if (a <= 0 
					|| a > (x_max() << 1) 
					|| x < a 
					|| x > x_max() - a 
					|| y < a 
					|| y > y_max() - a
				)
					return;
				shapes.push_back (new Circle {{x, y}, a});
				attach (shapes [shapes.size() - 1]);
				redraw();
			}

			void Polygon_window::sqr()
			{
				int 
					x = get_x(),
					y = get_y(),
					a = get_a();
				if (a <= 0 
					|| a > (x_max() << 1) 
					|| x < a 
					|| x > x_max() - a 
					|| y < a 
					|| y > y_max() - a
				)
					return;
				shapes.push_back (
					new Graph_lib::Rectangle {
						{x - a, y - a}, 
						{x + a, y + a}
					}
				);
				attach (shapes [shapes.size() - 1]);
				redraw();
			}

			int main()
			{
				string
					title {""};
				Polygon_window
					sufring_on_sinewaves {{2200, 500}, 600, 400, title};
				return gui_main();
			}
		}

		namespace e05{}

		namespace e06
		{
			Clock_window::Clock_window (Point xy, int w, int h, string & title) :
				Window {xy, w, h, title},
				center {300, 300},
				dimensions {w >> 1, (h >> 1) - 40},
				b_quit {{x_max() - 20, 0}, 20, 20, "X", [] (Address, Address pw) {reference_to <Clock_window> (pw).quit();}},
				border	{center, min (dimensions.x, dimensions.y)},
				s_hand_loc {0., double(dimensions.y >> 3) - double(dimensions.y)},
				s_hand {
					center, 
					{
						center.x + int (round (s_hand_loc.x)), 
						center.y + int (round (s_hand_loc.y))
					}
				},
				m_hand_loc {0., double(dimensions.y >> 2) - double(dimensions.y)},
				m_hand {
					center, 
					{
						center.x + int (round (m_hand_loc.x)), 
						center.y + int (round (m_hand_loc.y))
					}
				},
				h_hand_loc {0., double(dimensions.y >> 1) - double(dimensions.y)},
				h_hand {
					center, 
					{
						center.x + int (round (h_hand_loc.x)), 
						center.y + int (round (h_hand_loc.y))
					}
				}	
			{
				attach (b_quit);
				attach (border);
				set_scale(center, (h >> 1) - 40);
				s_hand.set_style({Line_style::Line_style_type::solid, 2});
				m_hand.set_style({Line_style::Line_style_type::solid, 4});
				h_hand.set_style({Line_style::Line_style_type::solid, 8});
				attach (s_hand);
				attach (m_hand);
				attach (h_hand);
			}

			int
				rad = 4;
			double 
				angle {-3.14159265358979323 / 30.},
				cosine = cos (angle),
				sine = sin (angle);

			void Clock_window::set_scale(Point center, int radius)
			{
				scale.push_back (new Circle{{0, -(radius - (radius >> 4))}, rad << 1});
				double
					in_x = double (scale[0].center().x),
					in_y = double (scale[0].center().y);

				for (int i = 1; i < 60; ++i)
				{
					double
						out_x = in_x * cosine + in_y * sine,
						out_y = in_y * cosine - in_x * sine;									
					scale.push_back (
						new Circle {
							{
							int (round (out_x)), 
							int (round (out_y))
							},
							rad * (1 + (i % 5 == 0))
						}
					);
					in_x = out_x;
					in_y = out_y;
				}
				for (int i = 0; i < 60; ++i)
				{
					scale[i].move(center.x, center.y);
					attach (scale[i]);
				}
			}

			void Clock_window::quit()
			{
				keep_ticking = false;
				cout 
					<< (clock() - counter >= 1000 
						? sounds[int (sound)] 
						: "")
					<< "...\n";
				hide();
			}

			void Clock_window::tick_tock()
			{
				Fl::flush();
				while(keep_ticking)
				{					
					//Fl::wait(0.0625);
					Fl::wait (0.0333333);
					if (clock() - counter >= 34)
					{	
						//cout << sounds[int (sound)] << ", ";
						move_hands();
						counter = clock();
						//sound = !sound;
					}
				}
			}


			void Clock_window::move_hands()
			{
				double 
					s_hand_angle = angle * 0.03333333333333333,
					s_hand_cos = cos (s_hand_angle),
					s_hand_sin = sin (s_hand_angle),
					m_hand_angle = s_hand_angle * 0.01666666666666667,
					m_hand_cos = cos (m_hand_angle),
					m_hand_sin = sin (m_hand_angle),
					h_hand_angle = m_hand_angle * 0.01666666666666667,
					h_hand_cos = cos (h_hand_angle),
					h_hand_sin = sin (h_hand_angle);
				//double 
				//	in_x = double(s_hand.point(1).x) - double (center.x),
				//	in_y = double(s_hand.point(1).y) - double (center.y);
				//s_hand.set_point (
				//	1,
				//	{
				//		center.x + int (round (in_x * s_hand_cos + in_y * s_hand_sin)),
				//		center.y + int (round (in_y * s_hand_cos - in_x * s_hand_sin))
				//	}
				//);
				double
					s_in_x = s_hand_loc.x * s_hand_cos + s_hand_loc.y * s_hand_sin,
					s_in_y = s_hand_loc.y * s_hand_cos - s_hand_loc.x * s_hand_sin;
				s_hand_loc.x = s_in_x;
				s_hand_loc.y = s_in_y;
				s_hand.set_point (
					1,
					{
						center.x + int (round (s_in_x)),
						center.y + int (round (s_in_y))
					}
				);
				double
					m_in_x = m_hand_loc.x * m_hand_cos + m_hand_loc.y * m_hand_sin,
					m_in_y = m_hand_loc.y * m_hand_cos - m_hand_loc.x * m_hand_sin;
				m_hand_loc.x = m_in_x;
				m_hand_loc.y = m_in_y;
				m_hand.set_point (
					1,
					{
						center.x + int (round (m_in_x)),
						center.y + int (round (m_in_y))
					}
				);
				double
					h_in_x = h_hand_loc.x * h_hand_cos + h_hand_loc.y * h_hand_sin,
					h_in_y = h_hand_loc.y * h_hand_cos - h_hand_loc.x * h_hand_sin;
				h_hand_loc.x = h_in_x;
				h_hand_loc.y = h_in_y;
				h_hand.set_point (
					1,
					{
						center.x + int (round (h_in_x)),
						center.y + int (round (h_in_y))
					}
				);
				Fl::redraw();
			}

			int main()
			{
				string
					title {""};
				Clock_window
					window	 {{2000, 500}, 600, 600, title};
				window.tick_tock();

				return 0;
			}
		}
	}
}