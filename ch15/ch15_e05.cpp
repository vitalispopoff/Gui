#include "ch15_excercise.h"
#include "ch15_sample.h"

#include <sstream>

namespace ch15
{
	namespace excercise
	{
		namespace e05
		{
			int
				n {1};
			double
				leibniz_prev {1};
			double leibniz (double x)
			{
				int
					denominator	{1 + (n << 1)},
					sign		{((n & 1) << 1) - 1};
				return leibniz_prev + 1. / double(denominator) * double(sign);
			}
			void main()
			{
				int
					win_size {600};
				Point
					win_anchor {1100, 400};
				Simple_window
					window	{win_anchor, win_size, win_size, ""};

				int
					margin {100},
					ax_len {win_size - (margin << 1)};
				Point
					orig	{win_size >> 1, win_size >> 1},
					ax_x_anchor	{margin, orig.y},
					ax_y_anchor {orig.x, win_size - margin};
				Axis
					ax_x	{Axis::Orientation::x, ax_x_anchor, ax_len},
					ax_y	{Axis::Orientation::y, ax_y_anchor, ax_len};					
				window.attach (ax_x);
				window.attach (ax_y);
				for ( ; n < 50; ++n)
				{
					std::ostringstream
						ss;
					ss 
						<< n;
					window.set_label (ss.str().c_str());				
					Function
						f_leibniz {
							[] (double x) {return leibniz(x);},
							-10,
							11,
							orig,
						};
					window.attach(f_leibniz);
					window.wait_for_button();
					window.detach(f_leibniz);
				}
			}
		}
	}
}