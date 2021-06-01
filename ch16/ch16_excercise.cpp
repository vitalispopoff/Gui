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
				but_next {{x_max () - 100, 0}, 50, 20, "Next", [] (Address, Address pw) {reference_to <My_window> (pw).next();}},
				but_quit {{x_max () - 50, 0}, 50, 20, "Quit", [] (Address, Address pw) {reference_to <My_window> (pw).hide();}}
			{
				attach (but_next);
				attach (but_quit);
				wait_for_next();
			}

			int main()
			{
				string
					title;
				My_window
					window {{2200, 500}, 600, 400, title};
				return gui_main();
			}
		}
	}
}