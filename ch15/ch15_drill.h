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
				ax_len	{400},
				ax_unit_len	{20};
			const Point
				ax_x_anch	{(win_size.x - ax_len) >> 1, win_size.y >> 1},
				ax_y_anch	{win_size.y >> 1, win_size.y - ((win_size.y - ax_len) >> 1)};
			const Color
				ax_col {Color::Color_type::red};
			const string
				win_lab	{"Function graphs"},
				ax_lab	{"1 == 20 px"};
			const double
				f_min			{-10},
				f_max			{11},
				f_x_unit_len	{20.},
				f_y_unit_len	{20.};
			const int
				f_count			{int(f_max) - int(f_min)};

			struct Axis : Graph_lib::Axis
			{
				Axis (
					Orientation orient,
					Point anchor = win_size,
					int ax_len = ax_len,
					int ax_unit_len = ax_unit_len,
					string ax_lab = ax_lab
					) : Graph_lib::Axis {orient, func(orient), ax_len, ax_unit_len, ax_lab} 
				{
					set_color (ax_col);
				}

				Point func (Orientation o)
				{	
					switch (o)
					{
						case Orientation::x :
							return {(win_size.x - ax_len) >> 1, win_size.y >> 1};
						case Orientation::y :
							return {win_size.y >> 1, win_size.y - ((win_size.y - ax_len) >> 1)};
						default:
							error ("no z allowed");
					}
				}
			};		
			
			struct Function : Graph_lib::Function
			{
				Function (
					Fct f,
					double f_min = f_min,
					double f_max = f_max,
					Point f_orig = {win_size.x >> 1, win_size.y >> 1},
					int f_count = int(f_max) - int(f_min), 
					double f_x_unit_len = f_x_unit_len,
					double f_y_unit_len = f_y_unit_len
					) : Graph_lib::Function {f, f_min, f_max, f_orig, f_count, f_x_unit_len, f_y_unit_len}
				{}
			};
		}
		
		namespace d01
		{
			void main();
		}

		namespace d03
		{
			void main();
		}

		namespace d04
		{
			void main();
		}
	}

}