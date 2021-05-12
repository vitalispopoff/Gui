#pragma once
#include "../_add_libs/PPP2Code/Simple_window.h"

namespace ch13
{
	namespace sample
	{
		void s01();

		namespace s02
		{			
			/// Lines inherits after Shape
			struct Lines : Shape
			{
				Lines() {} 

				/// use of initializer_list will need an explanation
				Lines(initializer_list<Point> lst);

				/// there seems to be mental shortcut in the cours, 
				/// as this thing is implemented not the one above
				Lines(initializer_list<pair<Point, Point>> lst);

				void draw_lines() const;
				

				void add(Point p1, Point p2);

				/// this is required yet not mentioned
				Color	color {Color::Color_type::black};
			};
		}

		namespace s03
		{
			struct Color
			{
					/// this will beg for being enum class eventually.
					enum Color_type
					{
						black	= FL_BLACK,
						red		= FL_RED
					};

					enum Transparency
					{
						invisible	= 0,
						visible		= 255
					};

					Color(Color_type cc) :
						c  {Fl_Color(cc)}, v {visible}
					{}
					Color (Color_type cc, Transparency vv) :
						c {Fl_Color(cc)}, v {vv} 
					{}
					Color (int cc) :
						c {Fl_Color(cc)}, v {visible}
					{}
					Color(Transparency vv) :
						c {Fl_Color()}, v {vv}
					{}

					int as_int() const
					{
						return c;
					}
					char visibility() const
					{
						return v;
					}
					void set_visibility(Transparency vv)
					{
						v = vv;
					}
				
				private:
					char v;										/// char is unsigned by default?
					Fl_Color c;
			};



		}
	}

	namespace drill
	{

	}

	namespace excercise
	{

	}
}
