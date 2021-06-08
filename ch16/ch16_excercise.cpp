
#include "ch16.h"
#include <fstream>

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
				s_hand {center, {center.x + int (round (s_hand_loc.x)), center.y + int (round (s_hand_loc.y))}},
				m_hand_loc {0., double(dimensions.y >> 2) - double(dimensions.y)},
				m_hand {center, {center.x + int (round (m_hand_loc.x)), center.y + int (round (m_hand_loc.y))}},
				h_hand_loc {0., double(dimensions.y >> 1) - double(dimensions.y)},
				h_hand {center, {center.x + int (round (h_hand_loc.x)), center.y + int (round (h_hand_loc.y))}}	
			{
				attach (b_quit);
				attach (border);
				set_scale(center, (h >> 1) - 40);
				s_hand.set_style({Line_style::Line_style_type::solid, 2});
				m_hand.set_style({Line_style::Line_style_type::solid, 4});
				h_hand.set_style({Line_style::Line_style_type::solid, 8});
				adjust_hands();
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
				hide();
			}
			void Clock_window::adjust_hands()
			{
				int
					crumbs = (time(NULL)- 27) % 43200;
				double
					seconds = double (crumbs % 60),
					s_angle	= seconds * angle,
					s_cos = cos(s_angle),
					s_sin = sin(s_angle),
					s_in_x = (double(dimensions.y >> 3) - double(dimensions.y)) * s_sin,
					s_in_y = (double(dimensions.y >> 3) - double(dimensions.y)) * s_cos;
				s_hand_loc.x = s_in_x;
				s_hand_loc.y = s_in_y;
				s_hand.set_point (1, {center.x + int (round (s_in_x)),center.y + int (round (s_in_y))});
				double
					minutes = double (crumbs / 60),
					m_angle = minutes * angle,
					m_cos = cos(m_angle),
					m_sin = sin (m_angle),
					m_in_x = (double(dimensions.y >> 2) - double(dimensions.y)) * m_sin,
					m_in_y = (double(dimensions.y >> 2) - double(dimensions.y)) * m_cos;
				m_hand_loc.x = m_in_x;
				m_hand_loc.y = m_in_y;
				m_hand.set_point (1, {center.x + int (round (m_in_x)), center.y + int (round (m_in_y))});
				double
					hours = double (crumbs),
					h_angle = (hours + 2. * 3600.) * -3.14159265358979323 / 21600.,
					h_cos = cos (h_angle),
					h_sin = sin (h_angle),
					h_in_x = (double(dimensions.y >> 1) - double(dimensions.y)) * h_sin,
					h_in_y = (double(dimensions.y >> 1) - double(dimensions.y)) * h_cos;
				h_hand_loc.x = h_in_x;
				h_hand_loc.y = h_in_y;
				h_hand.set_point (1, {center.x + int (round (h_in_x)), center.y + int (round (h_in_y))});				
			}
			void Clock_window::tick_tock()
			{
				Fl::flush();
				int 
					epoch_time = int(time(NULL)),
					crumbs = (epoch_time - 27) % 43200,
					seconds = crumbs % 60,
					minutes = (crumbs / 60),
					hours = (crumbs / 3600) + 2;
				while(keep_ticking)
				{					
					Fl::wait (0.03333333333333333);				/// 30fps
					int
						lateness = clock() - counter;
					if (lateness >= 33)
					{	
						if (lateness > 2000)
							adjust_hands();
						else
							move_hands();

						counter = clock();
						Fl::redraw();
					}
				}
			}
			void Clock_window::move_hands()
			{
				double
					s_hand_angle = angle * 0.03333333333333333,
					s_hand_cos = cos (s_hand_angle),
					s_hand_sin = sin (s_hand_angle),
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
					m_hand_angle = s_hand_angle * 0.01666666666666667,
					m_hand_cos = cos (m_hand_angle),
					m_hand_sin = sin (m_hand_angle),
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
					h_hand_angle = m_hand_angle * 0.01666666666666667,
					h_hand_cos = cos (h_hand_angle),
					h_hand_sin = sin (h_hand_angle),
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

		namespace e07
		{
			Animation_window::Animation_window (Point a, int w, int h, string & t) :
				Window {a, w, h, t},
				b_quit	{b_quit_anc, 50, 20, "X", [] (Address, Address pw){reference_to <Animation_window> (pw).quit();}},
				b_stop	{b_stop_anc, 50, 20, "Stop", [] (Address, Address pw){reference_to <Animation_window> (pw).stop();}},
				b_start {b_start_anc, 50, 20, "Start", [] (Address, Address pw) {reference_to <Animation_window> (pw).start();}},
				sky {{0, 0}, {600, 400}}
			{
				set_bcg();
				set_buttons();
				attach (plane);
			}
			void Animation_window::set_bcg()
			{
				sky.set_color (Color::Transparency::invisible);
				sky.set_fill_color (Color::Color_type::cyan);
				attach (sky);
				attach (ground);
			}
			void Animation_window::set_buttons()
			{
			attach (b_quit);
				attach (b_quit_img);
				attach (b_stop);
				attach (b_stop_img);
				attach (b_start);
				attach (b_start_img);
			}
			
			void Animation_window::quit()
			{
				b_start.hide();
				detach(b_start_img);
				b_stop.hide();
				detach(b_stop_img);
				b_quit.hide();
				detach(b_quit_img);
				if (flying)
				{
					flying = false;
					land();
				}
				open = false;
				hide();	
			}
			void Animation_window::stop()
			{
				b_stop.hide();
				detach(b_stop_img);
				b_start.show();
				attach(b_start_img);
				flying = false;
				land();
				open = true;
				run_it();
			}		
			void Animation_window::start()
			{
				b_start.hide();
				detach(b_start_img);
				b_stop.show();
				attach(b_stop_img);
				open = false;
				flying = true;
				take_off();
			}
			
			void Animation_window::run_it()
			{
				b_stop.hide();
				detach(b_stop_img);
				Fl::redraw();
				while (open)
				{
					Fl::wait();
				}
			}

			void Animation_window::take_off()
			{
				while(flying && plane.point(0).y > 150)
				{
					Fl::wait(0.001);
					if (counter + 40 <= clock())
					{
						plane.move(-2, -1);
						Fl::redraw();
						counter = clock();
					}
					if (plane.point(0).x == -123)
						plane.move(123 + 600, 0);
				}
				fly();
			}
			void Animation_window::fly()
			{
				while (flying)
				{
					Fl::wait(0.001);
					if (counter + 40 <= clock())
					{
						plane.move(-2, 0);
						Fl::redraw();
						counter = clock();
					}
					if (plane.point(0).x < -121)
						plane.move(123 + 600, 0);
				}
			}
			void Animation_window::land()
			{
				while (plane.point(0).x != 300 - 61 && plane.point(0).y != 275)
				{
					Fl::wait(0.001);				
					if (counter + 40 <= clock())
					{
						if (plane.point(0).y < 275)
						{
							plane.move (-2, 1);
							Fl::redraw();
							counter = clock();
						}
						else 
							if (plane.point(0).x != 300 - 61)
							{
								plane.move (-2, 0);
								Fl::redraw();
								counter = clock();
							}
					}
					if (plane.point(0).x < -121)
						plane.move(123 + 600, 0);
				}
			}

			int main()
			{
				string 
					t {""};
				Animation_window
					window {{2000, 500}, 600, 400, t};
				window.run_it();
				return 0;
			}
		}

		namespace e08
		{
			void Stock_data::load_data()
			{
				ifstream
					ifs {filename};
				if (!ifs)
					cerr << "can't read the file";
				string
					symbol;
				double
					rate {0};
				while (ifs >> symbol >> rate)
				{
					rates.push_back (rate);
					symbols.push_back (symbol);
				}
				ifs.close();
			}

			void Stock_data::load_rate(string s)
			{
				int 
					i {0};
				for (string symbol : symbols)
				{
					if (s == symbol)
					{
						selected_rates.push_back(rates[i]);
						selected_rates.pop_front();
						break;
					}
					i++;
				}
			}
				
			double Stock_data::operate()
			{
				return in_value * selected_rates.front() / selected_rates.back();
			}

			using namespace Graph_lib;
			using Graph_lib::Window;

			Stock_window ::Stock_window (Point p, int w, int h, string & t, Stock_data & sd) :
				Window {p, w, h, t},
				curr_menu {{10, 10}, 30, 20, Menu::Kind::horizontal, ""},
				in_value_box {{100, curr_menu.loc.y + 35},70, 20, "In"},				
				out_value_box{{100, in_value_box.loc.y + 35}, 70, 20, "Out"},
				b_quit {{x_max() - 15, 3}, 12, 12, "x", [] (Address, Address pw) {reference_to <Stock_window>(pw).exit();}},
				stock_data {sd}
			{
				curr_menu.attach(new Button{{0, 0}, 0, 0, "CHF",
					[] (Address, Address pw) {reference_to<Stock_window>(pw).act("CHF");}
				});
				curr_menu.attach(new Button{{0, 0}, 0, 0, "EUR",
					[] (Address, Address pw) {reference_to<Stock_window>(pw).act("EUR");}
				});
				curr_menu.attach(new Button{{0, 0}, 0, 0, "GBP",
					[] (Address, Address pw) {reference_to<Stock_window>(pw).act("GBP");}
				});
				curr_menu.attach(new Button{{0, 0}, 0, 0, "JPY",
					[] (Address, Address pw) {reference_to<Stock_window>(pw).act("JPY");}
				});
				curr_menu.attach(new Button{{0, 0}, 0, 0, "PLN",
					[] (Address, Address pw) {reference_to<Stock_window>(pw).act("PLN");}
				});
				curr_menu.attach(new Button{{0, 0}, 0, 0, "USD",
					[] (Address, Address pw) {reference_to<Stock_window>(pw).act("USD");}
				});
				attach (curr_menu);
				attach (in_value_box);
				attach (out_value_box);
				attach (b_quit);
			}

			void Stock_window::load_input()
			{
				stringstream
					ss;
				ss.str(in_value_box.get_string());
				double
					in_value;
				ss 
					>> in_value;
			}
			void Stock_window::exit()
			{
				keep_open = false;
				Fl::wait(1);
				hide();
			}

			void Stock_window::act(string s)
			{				
				stock_data.load_rate(s);
				out_value_box.put (to_string (stock_data.operate()));
				/// update in/out box descriptions :
				stock_data.selected_symbols.push_back("(" + s + ")");
				stock_data.selected_symbols.pop_front();
				detach(in_value_box);
				in_value_box.label = stock_data.selected_symbols.front() + " In";
				attach(in_value_box);
				out_value_box.label = stock_data.selected_symbols.back() + " Out";
			}

			int main()
			{
				string
					filename {"E:/_LAB/_C/Gui/_other/stock_exchange.txt"},
					title;
				Stock_data
					sd {filename},
					& sd_ref = sd ;
				Stock_window
					window {{2000, 500}, 320, 120, title, sd_ref};

				string
					tmp;
				while (window.keep_open)
				{		
					Fl::wait();
					/// would rather have it triggered by a callback, but In_box ain't eager to work this way...
					if (window.in_value_box.get_string() != tmp)
					{
						tmp = window.in_value_box.get_string();
						stringstream
							ss (window.in_value_box.get_string());
						ss 
							>> sd.in_value;
						if (sd.in_value * sd.selected_rates.front() * sd.selected_rates.back() > 0)
						{
							double
								result = sd.operate();
							window.out_value_box.put(to_string(result));
						}
					}
				}	
				return 0;			
			}
		}

		namespace e09
		{
			double SymbolTable::get(string s)
			{
				for (const Variable & var : varTable)
					if (var.name == s)
						return var.value;
				throw runtime_error("undefined name for a variable: " + s);
			}

			void SymbolTable::set(string s, double d, bool b)
			{
				for(Variable & var : varTable)
				{
					if (var.readOnly)
					{
						cout << "\n\tThis variable is read-only.\n";
						return;
					}
					var.value = d;
					var.readOnly = b;
					return;
				}
				throw runtime_error("Undefined name for a variable to set: " + s);
			}

			bool SymbolTable::isDeclared(string s)
			{
				for (const Variable & var : varTable)
					if (var.name == s)
						return true;
				return false;
			}

			void SymbolTable::declare(Variable v)
			{
				varTable.push_back(v);
			}

			const char 
				let			{'L'},
				name		{'a'},
				number		{'8'},
				print		{';'},
				power		{'P'},
				quit		{'Q'},
				remember	{'#'},
				root		{'R'};

			istream & Token_stream::getInputStream()
			{
				return inputStream;
			}

			void Token_stream::unget(Token t)
			{
				buffer = t;
				full = true;
			}

			Token Token_stream::get()
			{
				if(full)
				{
					full = false;
					return buffer;
				}
				char 
					c ;//(inputStream.get());
				inputStream 
					>> c;
				switch (c)
				{
					case '(':	case '+':	case '*':
					case ')':	case '-':	case '/':
					case '=':	case ';':	case '%':
					case '#':
						return Token(c);

					default:
					{
						if(c == '.' || isdigit(c))
						{
							inputStream.unget();
							double 
								d;
							inputStream 
								>> d;
							return Token(number,d);
						};

						if (c == '_' || isalpha(c))
						{
							string 
								s;
							s += c;
							while (inputStream.get(c) && (isalpha(c) || isdigit(c) || c == '_'))
								s += c;

							inputStream.unget();
							if (s == "let")
								return Token(let);

							if (s == "quit" || s == "exit")
								return Token(quit);

							if (s == "sqrt")
								return Token(root);

							if (s == "pow")
								return Token(power);

							return Token(name,s);
						};
						throw runtime_error("Bad token: ");
					}
				}
			}

			void Token_stream::ignore(char c)
			{
				full = false;
				if (c == buffer.kind)
					return;
				char 
					input;
				while (inputStream >> input)
					if (input == c)
						return;
			}

			double primary(Token_stream & ts, SymbolTable & table)
			{
				Token 
					t = ts.get();
				switch (t.kind)
				{
					case '(':
					{
						double 
							d = expression(ts, table);
						t = ts.get();
						if (t.kind != ')')
							throw runtime_error("')' expected");
						else
							return d;
					}

					case power:
					{
						t = ts.get();
						if (t.kind != '(')
							throw runtime_error("'(' expected");

						double 
							d1 = expression(ts, table);
						t = ts.get();
						if (t.kind != ';')
							throw runtime_error("';' expected");
						double 
							d2 = expression(ts, table);
						t = ts.get();
						if (t.kind != ')')
							throw runtime_error("')' expected");
						return pow(d1,d2);
					}

					case root:
					{
						double d = primary(ts, table);
						if(d < 0)
							throw runtime_error("positive number for the root expected (imaginary numbers are not supported).");
						return sqrt(d);
					}

					case '-':
						return -primary(ts, table);

					case number:
						return t.value;

					case name:
						return table.get(t.tokenName);

					default:
						throw runtime_error("primary expected");
				}
			}

			double term(Token_stream & ts,SymbolTable & table)
			{
				double 
					d = primary(ts, table);
				while (true)
				{
					Token 
						t = ts.get();
					switch (t.kind)
					{
					
					case '/':
					{
						double 
							denominator = primary(ts, table);
						if (denominator == 0)
							throw runtime_error("divide by zero");
						d /= denominator;
						break;
					}

					case '*':
						d *= primary(ts, table); 
						break;

					default:					
						ts.unget(t);
						return d;					
					}
				}
			}

			double expression(Token_stream & ts,SymbolTable & table)
			{
				double 
					d = term(ts, table);
				while (true)
				{
					Token 
						t = ts.get();
					switch (t.kind)
					{
					case '+':
						d += term(ts, table); 
						break;

					case '-':
						d -= term(ts, table); 
						break;

					default:
						ts.unget(t);
						return d;
					}
				}
			}

			double declaration(Token_stream & ts, SymbolTable & table)
			{
				vector <string>
					messages {
					"name expected in declaration",
					" declared twice",
					"= missing in declaration of ",
				};
				Token 
					t1 = ts.get();
				if (t1.kind != 'a')
					throw runtime_error(messages[0]);
				string 
					name = t1.tokenName;
				if (table.isDeclared(name))
					throw runtime_error(name + " " + messages[1]);
				Token 
					t2 = ts.get();
				if (t2.kind != '=')
					throw runtime_error(messages[2] + " " + name);
				double 
					d = expression(ts, table);
				Variable 
					v = Variable(name,d);
				table.declare(v);
				return d;
			}

			double statement(Token_stream & ts, SymbolTable & table)
			{
				Token 
					t = ts.get();
				bool 
					b {false};
				while (true)
				{
					switch (t.kind)
					{
					case let:
						return declaration(ts,table);

					case remember:
						t = ts.get();
						b = true;

					case name:
						char 
							c;
						if (cin >> c && c == '=' && table.isDeclared(t.tokenName))
						{
							double 
								d = expression(ts, table);
							table.set(t.tokenName,d,b);
							return table.get(t.tokenName);
						}
						ts.getInputStream().unget();

					default:
						ts.unget(t);
						return expression(ts, table);
					};
				}
			}

			const string 
				prompt = "> ",
				result = "= ";

			void setConstants(SymbolTable & table)
			{
				table.declare(Variable("pi", 3.141592628, true));
			}

			double /*void */calculate(Token_stream & ts, SymbolTable & table)
			{
				while (true)
				{
					try
					{
						cout 
							<< prompt;
						Token 
							t = ts.get();
						while (t.kind == print)
							t = ts.get();
						if (t.kind == quit)
							return NAN;
						ts.unget(t);
						return statement (ts, table);
					}
					catch (runtime_error & e)
					{
						cerr 
							<< "caught by calculate(): "
							<< e.what() 
							<< endl;
						ts.ignore(print);
						throw e;
					}
				}
			}

			int main()
			{
				//streambuf 
				//	* cin_buff = cin.rdbuf();
				//stringstream 
				//	ss;
				//cin.rdbuf(ss.rdbuf());
				//Token_stream 
				//	ts;
				//SymbolTable 
				//	table;
				//setConstants(table);
				//bool 
				//	keep_open {true};
				//Graph_lib::Window
				//	w {{2000, 500}, 320, 120, t};
				//Graph_lib::In_box
				//	inbox {{10, 50}, 300, 20, ""};
				//w.attach(inbox);
				//Graph_lib::Out_box
				//	outbox {{10, 80}, 300, 20, ""};
				//w.attach(outbox);
				string 
					t, s;
				Calc_window 
					w {{2000, 500}, 320, 120, t};
				w.run_window();


				/*while (w.keep_open)
				{
					Fl::wait();
					if (s != w.inbox.get_string())
					{
						s = w.inbox.get_string();
						ss.put(s.back());
						if (s.back() == '=')
						{ 
							double 
								d  = calculate (ts, table);
							cout 
								<< "delivered " 
								<< d;
							ss.ignore(s.size());
						}
					}
				}*/

				return 0;
			}
			
			int main_3()
			{
				stringstream
					ss {"a01234"};
				cout << char(ss.get()) << endl;
				ss.unget();
				string s;
				ss >> s;
				cout << s;


				return 0;

			}

			int main_2()
			{
				using namespace Graph_lib;
				string
					t;
				struct a_window : Graph_lib::Window
				{
					a_window (Point p, int w, int h, string & t) :
						Window {p, w, h, t},
						inbox {{10, 50}, 300, 20, ""},
						outbox{{10, 90}, 300, 20, ""},
						calculate {
							{10, 10}, 20, 20, "=", 
							[] (Address, Address pw) {reference_to<a_window>(pw).do_math();}
						},
						close {
							{305, 3}, 12, 12, "x", 
							[] (Address, Address pw) {reference_to<a_window>(pw).quit();}
						}
					{
						attach(inbox);
						attach(outbox);
						attach(close);
						attach(calculate);
					}
					void quit()
					{
						keep_open = false;
						hide();
					}
					void do_math()
					{
						outbox.put (inbox.get_string() + " =");
						string s {inbox.get_string() + " ="};
					}
					bool
						keep_open {true};
					In_box
						inbox;
					Out_box
						outbox;
					Button
						calculate,
						close;
				};

				a_window
					w {{2000, 500}, 320, 120, t};
				while (w.keep_open)
					Fl::wait();
				return 0;
			}

			int main_()
			{
				try
				{
					Token_stream 
						ts;
					SymbolTable 
						table;
					setConstants(table);
					calculate(ts, table);
					return 0;
				}
				catch (exception & e)
				{
					cerr
						<< "exception: " 
						<< e.what() 
						<< endl;
					char 
						c;
					while (cin >> c && c != ';') 
					{};
					return 1;
				}
				catch(...)
				{
					cerr
						<< "exception\n";
					char 
						c;
					while (cin >> c && c != ';') 
					{};
					return 2;
				}
			}
		}
	}
}