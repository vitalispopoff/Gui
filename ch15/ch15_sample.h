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
					Fct f,				/// function to be translated into sections (like mulitiline)
					double r1,			/// section min val in scaled units
					double r2,			/// section max val in scaled units
					Point orig,			/// 0,0 point location
					int count = 100,	/// number of sections
					double xscale = 25,	/// x scale of section
					double yscale = 25	/// y scale of section
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
			void main();
		}

		namespace s08
		{
			void main();
		}

		namespace s09
		{
			struct Distribution
			{
				int
					year,
					young,
					middle,
					old;
			};
			istream & operator >> (istream &, Distribution &);
		}

		namespace s10
		{
			using s09::Distribution;
			using s09::operator >>;	/// watch it closely !


			class Scale 
			{
					int 
						cbase,
						vbase;
					double scale;
				public :
					Scale (int b, int vb, double s) :
						cbase {b}, vbase {vb}, scale {s}
					{}
					int operator () (int v) const 
					{
						return int(round(double(cbase) + (double(v) - double(vbase)) * scale));
					}
			};

			void main();
		}
		
	}
}