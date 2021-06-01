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
	}
}