#pragma once
#include <sstream>
#include <random>
#include "../_add_libs/PPP2Code/Gui.h"

namespace ch16
{
	namespace sample
	{
		namespace s01
		{
			using namespace Graph_lib;
			struct Simple_window : Window
			{
					Simple_window (Point xy, int w, int h, const string & title);

					void wait_for_button();
				private:
					Button 
						next_button;
					bool 
						button_pushed;

				/// Widget interface requires two functions for a proper callback communication
				/// one to connect with the system lower levels
				/// the other to deliver action on our level on the callback
					static void cb_next (Address, Address);
					void next();
			};
		}

		namespace s02
		{
			using namespace Graph_lib;
			struct Simple_window : Window /// wished for inherit from s01::Simple_window, but the implementation wouldn't allow
			{
				Simple_window (Point xy, int w, int h, const string & title);
				Button 
					next_button;
				bool
					button_pushed;
				void next(){}
			};
		}

		namespace s03
		{
			using namespace Graph_lib;

			struct Button : Widget
			{
				Button (
					Point xy, 
					int w, 
					int h, 
					const string & label, 
					Callback cb
				);

			};
		}

		namespace s04
		{
			using namespace Graph_lib;
			using Graph_lib::Window;
			class Widget
			{
				//public :
				//	Widget (
				//		Point xy, 
				//		int w, 
				//		int h, 
				//		const string & s, 
				//		Callback cb
				//	);
				// 
				//	virtual	void	move	(int dx, int dy);
				//	virtual	void	hide	();
				//	virtual	void	show	();
				//	virtual	void	attach	(Window &) = 0;
				// 
				//	Point
				//		loc;
				//	int
				//		width,
				//		height;
				//	string
				//		label;
				//	Callback
				//		do_it;
				//protected :
				//	Window * own;
				//	Fl_Widget * pw;
			};
		}

		namespace s05
		{
			using namespace Graph_lib;
			using Graph_lib::Window;
			class Button : public Widget	/// what is this public thing?
			{
				public :
					Button (
						Point xy, 
						int ww, 
						int hh, 
						const string & s, 
						Callback cb
					) :
						Widget {xy, ww, hh, s, cb}
					{}
					void attach (Window & win);
			};
		}

		namespace s06
		{
			using namespace Graph_lib;
			using Graph_lib::Window;
			struct In_box : Widget
			{
				In_box (Point xy, int w, int h, const string & s) :
					Widget {xy, w, h, s, 0}
				{}
				int get_int ();
				string get_string();
				void attach (Window & win);					
			};

			struct Out_box : Widget 
			{
				Out_box (Point xy, int w, int h, const string & s) :
					Widget {xy, w, h, s, 0}
				{}
				void put (int);
				void put (const string &);
				void attach (Window & win);
			};
		}

		namespace s07
		{
			using namespace Graph_lib;
			using Graph_lib::Window;
			struct Menu : Widget
			{
				enum Kind {
					horizontal,
					vertical
				};
				Menu (Point xy, int w, int h, Kind kk, const string & label);
				Vector_ref <Button> 
					selection;
				Kind
					k;
				int
					offset;
				int attach (Button & p);
				int attach (Button * p);
				void show()
				{
					//for (Button & b : selection)				/// non suitable 'begin()' was found for 'seleection'
						//b.show();
					for (int i = 0; i < selection.size(); ++i)
						selection[i].show();
				}
				void hide();
				void move (int dx, int dy);
				void attach (Window & win);
			};
		}

		namespace s08
		{
			using namespace Graph_lib;
			struct Lines_window : Window 
			{
					Lines_window (Point xy, int w, int h, const string & title);
					Open_polyline
						lines;
				//private :
				protected :					/// changing from private to allow reuse in the next examples
					Button
						next_button,
						quit_button;
					In_box
						next_x,
						next_y;
					Out_box 
						xy_out;

					void next();
					void quit();
			};
			int main();
		}

		namespace s09
		{
			using namespace Graph_lib;
			struct Lines_window : s08::Lines_window
			{
				Lines_window (Point xy, int w, int h, const string & title);

				//Open_polyline lines;	// this is inherited, right?
				Menu
					color_menu;

				static void cb_red (Address, Address);
				static void cb_blue (Address, Address);
				static void cb_black (Address, Address);
				static void cb_menu	(Address, Address);

				void red_pressed() 
				{
					change (Color::Color_type::red);
				}
				void blue_pressed()
				{
					change (Color::Color_type::blue);
				}
				void black_pressed()
				{
					change (Color::Color_type::black);
				}

				void change (Color c)
				{
					lines.set_color(c);
				}

				
			};
			int main();
		}

		namespace s10
		{
			using namespace Graph_lib;

			struct Lines_window : s08::Lines_window
			{
					Lines_window (
						Point xy,
						int w, 
						int h,
						const string & title
					);
				protected :
					Menu
						color_menu;
					Button 
						color_menu_button;
					
					void change_color (Color c)
					{
						lines.set_color(c);
						hide_color_menu();
					}
					virtual void color_menu_pressed ()
					{
						color_menu_button.hide();
						color_menu.show();
					}
					virtual void hide_color_menu	()
					{
						color_menu.hide();
						color_menu_button.show();
					}					
			};

			int main();
		}

		namespace s11
		{
			using namespace Graph_lib;
			using s10::Lines_window;
			int main();
		}
	}

	namespace drill
	{
		namespace d04
		{
			using namespace Graph_lib;
			using sample::s10::Lines_window;

			struct Lines_window1 : sample::s10::Lines_window
			{
					Lines_window1 (
						Point xy, 
						int w, 
						int h, 
						const string & title
					);
				protected :
					Menu
						style_menu;
					Button
						style_menu_button;

					virtual void color_menu_pressed () override
					{
						color_menu_button.hide();
						style_menu_button.hide();
						color_menu.show();
					}
					virtual void hide_color_menu () override
					{
						color_menu.hide();
						color_menu_button.show();
						style_menu_button.show();
					}	
					void change_style(Line_style ls)
					{
						lines.set_style(ls);
						hide_style_menu();
					}
					void style_menu_pressed()
					{
						style_menu_button.hide();
						color_menu_button.hide();
						style_menu.show();
					}
					void hide_style_menu ()
					{
						style_menu.hide();
						color_menu_button.show();
						style_menu_button.show();
					}
			};
			int main();
		}	
	}

	namespace excercise
	{
		namespace e01
		{

			using namespace Graph_lib;
			struct My_window : Window
			{
				My_window (Point xy, int w, int h, string & title);
				void wait_for_next()
				{
					while (waiting_for_next)
						Fl::wait();
					waiting_for_next = true;
					Fl::redraw();
				}
			protected :
				Button
					but_next,
					but_quit;
				bool
					waiting_for_next {true};

				virtual void next()
				{
					waiting_for_next = false;
				}
				void quit()
				{
					hide();
				}
			};

			struct Derived_window : My_window
			{
				Derived_window (
					Point xy,
					int w, 
					int h,
					string & title
				);
			protected :
				int
					index {0};
				Out_box
					iter;
				virtual void next()
				{
					My_window::next();
					index++;
					ostringstream
						oss;
					oss 
						<< index;
					iter.put(oss.str());
				}
			};
			int main();
		}

		namespace e02
		{
			using namespace Graph_lib;
			struct Checker_window : e01::My_window
			{
				Checker_window (Point xy, int w, int h, string & title);
			protected :
				Button
					b0, b1, b2, b3;
				void action0()
				{
					detach(b0);
				}
				void action1()
				{
					detach(b1);
				}
				void action2()
				{
					detach(b2);
				}
				void action3()
				{
					detach(b3);
				}
			};
			int main();
		}

		namespace e03
		{
			using namespace Graph_lib;

			inline int rand_int (int min, int max)
			{
				static default_random_engine 
					ran;
				return uniform_int_distribution <> {min, max} (ran);
			}

			struct Rand_button_window : e01::My_window
			{
			protected :
				string
					filename {"E:\\_LAB\\_C\\Gui\\_other\\kuvaton-kuka_jatti_ikkunan_auki2.jpg"};
			public : 
				Rand_button_window (Point xy, int w, int h, string & title);
			protected :
				Button
					button;
				Image
					cover;
				void relocate();
			};				
			int main();
		}
	}
}