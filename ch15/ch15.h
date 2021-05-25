#pragma once

#include "../_add_libs/PPP2Code/Simple_window.h"

namespace ch15
{
	namespace sample
	{
		namespace constants
		{
			constexpr int
				xmax	= 600,
				ymax	= 400,
				x_orig	= xmax / 2,
				y_orig	= ymax / 2,
				r_min	= -10,
				r_max	= 11,
				n_points	= 400,
				x_scale	= 30,
				y_scale = 30;
		}
		namespace s01
		{
			using namespace constants;
			void main();
		}

		namespace s02
		{
			using namespace constants;
			void main();
		}

		namespace s03
		{
			using namespace constants;
			void main();
		}	

		namespace s04
		{
			using namespace constants;
			void main();
		}	
	}

	namespace drill
	{

	}
	
	namespace excercise
	{

	}
}