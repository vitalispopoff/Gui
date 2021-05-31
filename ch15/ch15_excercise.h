#pragma once
#include "../_add_libs/PPP2Code/Gui.h"
//#include "../_add_libs/PPP2Code/Simple_window.h"

namespace ch15
{	
	namespace excercise
	{
		void keep_open();

		namespace e01
		{
			void main();
		}	

		/// needs a function pointer - have learned it yet?
		namespace e02
		{
			struct  Fct : Graph_lib::Function
			{
					Fct (
							Graph_lib::Fct f,
							double r1,
							double r2,
							Graph_lib::Point orig,
							int count = 100,
							double xscale = 25.,
							double yscale = 25.
						) :
						Function {f, r1, r2, orig, count, xscale, yscale}
					{
						r1_ = r1;
						r2_ = r2;
						orig_ = orig;
						count_ = count;
						xscale_ = xscale;
						yscale_ = yscale;
					}
					void reset();
				protected :
					double r1_, r2_, xscale_, yscale_;
					Graph_lib::Point orig_;
					int count_;
			};

			void main();
		}

		namespace e04
		{
		 void main();
		}

		namespace e05
		{
			void main();
		}

		namespace e06
		{
			using namespace Graph_lib;

			/// doesn't support negative values
			struct Bar_chart : Shape
			{
					Bar_chart () {}
					Bar_chart (Point, int, int, vector<double>);

					void add_bar(double);
					virtual void draw_lines() const;
					virtual void draw_bar (int, int, int, int) const;
					Point
						anchor		{0, 0};
					int
						w	{0}, 
						h	{0};
					double
						max_bar_value {-DBL_MAX};
				private :
					vector<double>
						values;
			};

			void main();
		}

		namespace e07
		{
			using namespace Graph_lib;

			struct Bar_chart : Shape
			{
					Bar_chart () {}
					Bar_chart (Point anchor, int width, int height) :
						a{anchor}, w {width}, h {height}
					{}
					Bar_chart (Point, int, int, vector<double>);


					virtual void draw_lines() const;
					virtual void draw_bar (int, int, int, int, string) const;
					Point
						a	{0, 0};
					int
						w	{0}, 
						h	{0};
					double
						max_bar_value {-DBL_MAX};
				private :
					vector<double>
						values;
					vector<string>
						labels;
			};
			void main();
		}

		namespace e08
		{
			using namespace Graph_lib;

			struct Bar_chart : Shape
			{
				Bar_chart () {}
				Bar_chart (Point, Point);

				void add_bar(string, double);
				virtual void draw_lines() const;

				Point
					anch	{0, 0},
					size	{0, 0};
				vector<double>
					values;
				vector<string>
					labels;
				double
					max_bar_value {-DBL_MAX};
			};

			vector <pair <int, int>> load_data();
			void main();
		}

	}
}