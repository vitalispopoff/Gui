#pragma once

#include "../_add_libs/PPP2Code/Gui.h"

namespace ch15
{
	namespace drill
	{
		using namespace Graph_lib;

		namespace constants
		{
			const Point
				win_anchor	{1000, 500},
				win_size	{600, 600},
				f_orig		{win_size.x >> 1, win_size.y >> 1};
			const int
				axis_len	{400};
			const Color
				ax_col {Color::Color_type::red};
			const double
				f_min			{-10},
				f_max			{11},
				f_x_unit_len	{20.},
				f_y_unit_len	{20.};
			const int
				f_count			{int(f_max) - int(f_min)};
		}

		namespace d01
		{
			void main();
		}

	}

}