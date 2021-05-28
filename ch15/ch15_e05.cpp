#include "ch15_excercise.h"
#include "ch15_sample.h"

namespace ch15
{
	namespace excercise
	{
		namespace e05
		{
			void main()
			{
				int
					win_size {600},
					margin {100},
					ax_len {win_size - (margin << 1)};
				Point
					orig	{win_size >> 1, win_size >> 1},
					ax_x_anchor	{margin, orig.y},
					ax_y_anchor {orig.x, win_size - margin};
					
				Simple_window
					window	{{1100, 400}, 600, 600, ""};
				Axis
					ax_x	{Axis::Orientation::x, ax_x_anchor, ax_len},
					ax_y	{Axis::Orientation::y, ax_y_anchor, ax_len};
				window.attach (ax_x);
				window.attach (ax_y);
				window.wait_for_button();

			}
		}
	}
}