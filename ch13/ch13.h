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
					enum class Color_type
					{
						black	= FL_BLACK,
						red		= FL_RED
					};

					/// also this enum wants to be an enum class
					/// and once it becomes, the calls of its members require full path: 'Transparency::member'
					enum class Transparency
					{
						invisible	= 0,
						visible		= 255
					};

					Color(Color_type cc) :
						c{Fl_Color(cc)}, v {char(Transparency::visible)}	///err c2397 - Transparency to char conversion
					{}
					Color (Color_type cc, Transparency vv) :
						c {Fl_Color(cc)}, v {char(vv)} 
					{}
					Color (int cc) :
						c {Fl_Color(cc)}, v {char(Transparency::visible)}					
					{}
					Color(Transparency vv) :
						c {Fl_Color()}, v {char(vv)}
					{}

					int		as_int		() const	{return c;}
					char	visibility	() const	{return v;}
					void	set_visibility(Transparency vv){v = int(vv);}
				
				private:
					char v;										/// char is unsigned by default?
					Fl_Color c;
			};
		}

		namespace s04
		{
			struct Line_style
			{
					/// it will be called to be set into an enum class eventually
					enum class Line_style_type
					{
						solid		= FL_SOLID,
						dash		= FL_DASH,
						dot			= FL_DOT
					};

					Line_style(Line_style_type ss) :			/// Line_style_type recast to int 
						s {int(ss)}, w {0}
					{}
					Line_style(Line_style_type lst, int ww) :
						s {int(lst)}, w {ww}
					{}
					Line_style(int ss = 0) :					/// added default input value for the constructor empty override
						s {ss}, w {0}							/// width is said to be 1 by default, why it is 0 then?
					{}

					int	width	()	const	{return w;}
					int	style	()	const	{return s;}

				private:
					int
						s,										/// style
						w;										/// width
			};
		}

		namespace s05
		{
			struct Open_poly_line : Shape
			{
				using Shape :: Shape;							///this one's called a "using declaration"
				
				void add(Point p) {Shape::add(p);}				/// interesting, that add function needs a rewriting, but all the rest is smoothly inherited from Shape
			};
		}

		namespace s06
		{
			struct Closed_polyline : Open_polyline
			{
				using Open_polyline::Open_polyline;

				void draw_lines() const;

			};
		}

		namespace s07
		{
			struct Polygon : Closed_polyline
			{
				using Closed_polyline::Closed_polyline;

				void add(Point p);
				void draw_lines() const;
			};
		}

		namespace s08
		{
			struct Rectangle : Shape
			{
					Rectangle(Point xy, int ww, int hh);
					Rectangle(Point x, Point y);

					void draw_lines() const;

					int	height	() const { return h;}
					int	width	() const { return w;}

				private:
					int
						w,
						h;
			};

		}

		namespace s09
		{
			void s09_main();
		}

		namespace s10
		{
			//template<class T> class Vector_ref
			//{
			//	public:
			//		
			//		void push_back (T &);
			//		void push_back (T *);
			//
			//		T & operator [] (int i);
			//		const T & operator [] (int i) const;
			//
			//		int size () const;
			//};
		}

		namespace s11
		{
			void s11_main();
		}
	}

	namespace drill
	{

	}

	namespace excercise
	{

	}
}
