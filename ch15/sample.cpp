#include "ch15.h"

namespace ch15
{
	namespace sample
	{
	namespace s01
		{			
			double one (double)
			{
				return 1.;
			};

			void main()
			{
				//constexpr Point				/// can't declare orig a constexpr - input data aint constant values 
				Point
					orig	{x_orig, y_orig};
			 
				Simple_window
					window	{{1000, 500}, xmax, ymax, ""};
				Function 
					s	{one, double(r_min), double(r_max), orig, int(n_points), double(x_scale), double(y_scale)};
				window.attach (s);
				window.wait_for_button();
			}			
		}

		namespace s02
		{
			double slope (double x)
			{
				return x / 2;
			}			
			void main()
			{
				Point
					orig {x_orig, y_orig};
				Simple_window
					window {{1000, 500}, xmax, ymax, ""};
				Function 
					s {slope, double(r_min), double(r_max), orig, int(n_points), double(x_scale), double(y_scale)};
				window.attach (s);
				window.wait_for_button();
			}
		}

		namespace s03
		{
			double square (double x)
			{
				return x * x;
			}
			void main()
			{
				Point
					orig {x_orig, y_orig};
				Simple_window
					window {{1000, 500}, xmax, ymax, ""};
				Function 
					s {square, double(r_min), double(r_max), orig, int(n_points), double(x_scale), double(y_scale)};
				window.attach (s);
				window.wait_for_button();
			}
		}

		namespace s04
		{
			double sine (double x)
			{
				return sin(x);
			}
			void main()
			{
				Point
					orig {x_orig, y_orig};
				Simple_window
					window {{1000, 500}, xmax, ymax, ""};
				Function 
					s {sine, double(r_min), double(r_max), orig, int(n_points), double(x_scale), double(y_scale)};
				window.attach (s);
				window.wait_for_button();
			}
		}

	}
}