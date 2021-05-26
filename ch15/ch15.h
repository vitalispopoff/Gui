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
			/// for the namespace s02
			constexpr int
				xlength	= xmax - 40,
				ylength = ymax - 40;
		}

		namespace s01
		{
			using namespace constants;
			void main();
		}

		namespace s02
		{
			using namespace constants;
			using namespace s01;
			void main();
		}

		namespace s03
		{
			struct Function : Shape
			{
				Function (
					Fct f, 
					double r1, 
					double r2, 
					Point orig, 
					int count = 100, 
					double xscale = 25, 
					double yscale = 25
				);


			};
		}

		namespace s04
		{
			using namespace constants;
			void main();
		}

		namespace s05
		{
			using namespace constants;
			void main();
		}

		namespace s06
		{
			struct Axis : Shape
			{
				enum class Orientation
				{
					x, y, z
				};
				Axis (
					Orientation d, 
					Point xy, 
					int length, 
					int number_of_notches = 0, 
					string label = ""
				);
				void draw_lines() const override;
				void move (int dx, int dy) override;
				void set_color(Color c);

				Text
					label;
				Lines
					notches;
			};
		}

		namespace s07
		{
			//int fac (int);
			//double term (double, int);
			//double expe  (double, int);
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