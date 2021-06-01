#include <sstream>
#include "ch16.h"

namespace ch16
{
	namespace sample
	{
		namespace s01
		{
			Simple_window::Simple_window (Point xy, int w, int h, const string & title) :
				Window {xy, w, h, title},
				next_button{Point {x_max() - 70, 0}, 70, 20, "Next", cb_next}, /// standard graphical variables, name, and (!) an assigned function 
				button_pushed {false}
			{
				attach(next_button);
			}
			void Simple_window::cb_next (Address, Address pw)	/// when pushed, calls next()
			{
				reference_to <Simple_window> (pw).next(); /// this calls for deeper investigation: what the'pw" is?
			}

			void Simple_window::wait_for_button()
			{
				while (!button_pushed)	/// not pushed
					Fl::wait();			/// waiting for the button push

				button_pushed = false;	/// resets the button_pushed status and calls the redraw
				Fl::redraw();			/// is redraw() enough to set the button to the initial state and wait for action ?
			}

			void Simple_window::next()		/// when called, switch button_pushed effectively breaking the while loop in the wait_for_button
			{
				button_pushed = true;
			}
		}

		namespace s02
		{			
			Simple_window::Simple_window (Point xy, int w, int h, const string & title) :
				Window {xy, w, h, title},
				next_button {
					Point {x_max() - 70, 0}, 
					70, 
					20, 
					"Next",
					[] (Address, Address pw) 
					{
						reference_to <Simple_window> (pw).next();	/// cb_next() may be turned into a lambda...
					}
				},
				button_pushed {false}
			{
				attach (next_button);	
			}			
		}

		namespace s04
		{
			//Widget::Widget (
			//	Point xy, 
			//	int w, 
			//	int h, 
			//	const string & s, 
			//	Callback cb
			//) {}
			//void Widget::move (int dx, int dy) {}
			//void Widget::hide () {}
			//void Widget::show () {}
		}

		namespace s08
		{
			Lines_window::Lines_window (Point xy, int w, int h, const string & title) :
				Window {xy, w, h, title},
				next_button {
					Point {x_max () - 150, 0}, 
					70, 
					20, 
					"Next point",
					[] (Address, Address pw) {reference_to <Lines_window> (pw).next ();},
				},
				quit_button {
					Point {x_max () - 70, 0}, 
					70, 
					20, 
					"Quit",
					[] (Address, Address pw) {reference_to <Lines_window> (pw).quit ();},
				},
				next_x { 
					Point {x_max () - 310, 0},
					50,
					20,
					"next x: "
				},
				next_y {
					Point {x_max () - 210, 0},
					50,
					20,
					"next y: "
				},
				xy_out {
					Point {100, 0},
					100,
					20,
					"current (x, y): "
				}
			{
				attach (next_button);
				attach (quit_button);
				attach (next_x);
				attach (next_y);
				attach (xy_out);
				attach (lines);
			}
			void Lines_window::quit ()
			{
				hide();
			}
			void Lines_window::next()
			{
				int
					x = next_x.get_int(),	//readings from the In_boxes
					y = next_y.get_int();
				lines.add (Point {x, y});	// combining them int Point and shoving it into polyline
				ostringstream
					ss;
				ss							// building a string from the read coordinates
					<< '('
					<< x
					<< ','
					<< y
					<< ')';
				xy_out.put (ss.str());		// sending it to the Out_box
				redraw();					// refresh display
			}

			int main()
			{
				Lines_window
					win {Point {100, 100}, 600, 400, "lines"};
				return gui_main();
			}
		}

		namespace s09
		{
			Lines_window::Lines_window (Point xy, int w, int h, const string & title) :
				s08::Lines_window (xy, w, h, title),
				color_menu {
					Point {x_max( ) - 70, 30}, 70, 20, Menu::Kind::vertical, "color"
				}
			{
				color_menu.attach (new Button {Point {0, 0}, 0, 0, "red", cb_red});
				color_menu.attach (new Button {Point {0, 0}, 0, 0, "blue", cb_blue});
				color_menu.attach (new Button {Point {0, 0}, 0, 0, "black", cb_black});
				attach (color_menu);
			}
			void Lines_window::cb_red (Address, Address pw)
			{
				reference_to <Lines_window> (pw).red_pressed();
			}
			void Lines_window::cb_blue (Address, Address pw)
			{
				reference_to <Lines_window> (pw).blue_pressed();
			}
			void Lines_window::cb_black (Address, Address pw)
			{
				reference_to <Lines_window> (pw).black_pressed();
			}

			int main()
			{
				Lines_window
					win {Point {100, 100}, 600, 400, "lines"};
				return gui_main();
			}
		}
		
		namespace s10
		{
			Lines_window::Lines_window (Point xy, int w, int h, const string & title) :
				s08::Lines_window (xy, w, h, title),
				color_menu {
					Point {x_max( ) - 70, 30}, 70, 20, Menu::Kind::vertical, "color"
				},
				menu_button {
					Point {x_max () - 80, 30}, 80, 20, "color menu", cb_menu}
			{
				color_menu.attach (new Button {Point {0, 0}, 0, 0, "red", cb_red});
				color_menu.attach (new Button {Point {0, 0}, 0, 0, "blue", cb_blue});
				color_menu.attach (new Button {Point {0, 0}, 0, 0, "black", cb_black});
				attach (color_menu);
				color_menu.hide();
				attach(menu_button);
			}
			void Lines_window::cb_red (Address, Address pw)
			{
				reference_to <Lines_window> (pw).red_pressed();
			}
			void Lines_window::cb_blue (Address, Address pw)
			{
				reference_to <Lines_window> (pw).blue_pressed();
			}
			void Lines_window::cb_black (Address, Address pw)
			{
				reference_to <Lines_window> (pw).black_pressed();
			}
			void Lines_window::cb_menu (Address, Address pw)
			{
				reference_to <Lines_window> (pw).menu_pressed();
			}
			int main()
			{
				Lines_window
					win {Point {100, 100}, 600, 400, "lines"};
				return gui_main();
			}
		}

		namespace s11
		{
			int main()
			{
				//Lines_window {Point {100, 100}, 600, 400, "lines"}; /// local variable w/o name. warn C26444
				return gui_main();
			}
		}
	}
}