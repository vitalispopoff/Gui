#pragma once
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
					Button 
						menu_button;
					Menu
						color_menu;
					
					static	void	cb_red		(Address, Address);
					static	void	cb_blue		(Address, Address);
					static	void	cb_black	(Address, Address);
					static	void	cb_menu		(Address, Address);
					void	red_pressed		() 
					{
						change (Color::Color_type::red);
						hide_menu();
					}
					void	blue_pressed	()
					{
						change (Color::Color_type::blue);
						hide_menu();
					}
					void	black_pressed	()
					{
						change (Color::Color_type::black);
						hide_menu();
					}
					void	menu_pressed	()
					{
						menu_button.hide();
						color_menu.show();
					}
					void	change	(Color c)
					{
						lines.set_color(c);
					}
					void	hide_menu	()
					{
						color_menu.hide();
						menu_button.show();
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
}