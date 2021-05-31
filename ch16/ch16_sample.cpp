
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

			void next(){}

		}
	}
}