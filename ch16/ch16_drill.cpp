#include "ch16.h"

namespace ch16
{
	namespace drill
	{
		namespace d04
		{
			Graph_lib::Line_style
				solid {Line_style::Line_style_type::solid},
				dot {Line_style::Line_style_type::dot},
				dash {Line_style::Line_style_type::dash};

			Lines_window1::Lines_window1 (Point xy, int w, int h, const string & title) :
				sample::s10::Lines_window (xy, w, h, title),
				style_menu {
					Point {x_max () - 70, 30}, 70, 20, Menu::Kind::vertical, "style"
				},
				style_menu_button {
					Point {x_max () - 70, 51}, 70, 20, "Styles", [] (Address, Address pw) 
					{
						reference_to <Lines_window1> (pw).style_menu_pressed();
					}
				}
			{
				style_menu.attach (new Button {{0, 0}, 0, 0, "solid", [] (Address, Address pw) {reference_to <Lines_window1> (pw).change_style ({solid});}});
				style_menu.attach (new Button {{0, 0}, 0, 0, "dot", [] (Address, Address pw) {reference_to <Lines_window1> (pw).change_style ({dot});}});
				style_menu.attach (new Button {{0, 0}, 0, 0, "dash", [] (Address, Address pw) {reference_to <Lines_window1> (pw).change_style ({dash});}});
				attach (style_menu);
				style_menu.hide();
				attach (style_menu_button);
			}

			void Lines_window1::change_style(Line_style ls)
			{
				lines.set_style(ls);
				style_menu.hide();
				style_menu_button.show();
			}
			int main()
			{
				Lines_window1
					win {Point {100, 100}, 600, 400, "lines"};
				return gui_main();
			}
		}
	}
}
