#pragma once
#include "../_add_libs/PPP2Code/Simple_window.h"
#include <algorithm>
#include <fstream>

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
			struct Open_polyline : Shape
			{
				using Shape::Shape;								///this one's called a "using declaration"				
				void dd(Point p)
				{
					Shape::add(p);								/// interesting, that add function needs a rewriting, but all the rest is smoothly inherited from Shape
				}
			};
		}

		namespace s06
		{
			struct Closed_polyline : s05::Open_polyline
			{
				using Open_polyline::Open_polyline;		
				void draw_lines() const;		
			};
		}

		namespace s07
		{
			struct Polygon : s06::Closed_polyline
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
					Rectangle			(Point xy, int ww, int hh);
					Rectangle			(Point x, Point y);		
					void	draw_lines	() const;		
					int		height		() const
					{
						return h;
					}
					int		width		() const
					{
						return w;
					}		
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
			template<class T> class Vector_ref
			{
				public:					
					void	push_back		(T &);
					void	push_back		(T *);			
					T &		operator []		(int i);
					const T & operator []	(int i) const;			
					int		size			() const;
			};
		}

		namespace s11
		{
			void s11_main();
		}

		namespace s12
		{			
																///font class declaration must be before the call in the Text struct declaration.
			class Font											/// could be struct probably if not for the Font_type
			{
				public:					
					enum class Font_type						/// writing enum class instead of enum - sparing the wrn message
					{
						helvetica	= FL_HELVETICA,
						hevletica_bold	= FL_HELVETICA_BOLD
						/// ...
					};					
					Font (Font_type ff) :
						f {int (ff)}
					{}
					Font (int ff) :
						f {ff}
					{}
					int as_int() const {return f;}		
				private:
					int f;
			};
			struct Text : Shape 
			{						
				Text (Point x, const string & s) :
					lab {s}
				{
					add (x);									/// anchor - defines the bottom left corner of a text area
				}				
				void	draw_lines	() const;
				void	set_label	(const string & s)	
				{
					lab = s;
				}
				string	label		() const
				{
					return lab;
				}
				void	set_font	(Font f)
				{
					fnt = f;
				}
				Font	font		() const
				{
					return fnt;
				}
				void	set_font_size (int s)
				{
					fnt_sz = s;
				}
				int		font_size	() const
				{
					return fnt_sz;
				}		
				private:				
					string	lab;
					Font	fnt		{fl_font()};
					//int		fnt_sz	{(fl_size() < 14) ? 14 : fl_size()};
					int		fnt_sz	{max (fl_size (), 14)};		/// a bit cleaner than ternary operator
			};		
		}

		namespace s13
		{
			struct Circle : Shape
			{
					Circle (Point, int);		
					void	draw_lines	() const;
					Point	center		() const;
					int		radius		() const
					{
						return r;
					}				
					void	set_radius	(int rr)
					{
						set_point (
							0, 
							Point {								// this is a top left conrner of a rectangle containing the circle:	
								center().x - rr,				// towards  circle left border
								center().y - rr					// towards circle top border
							}
						);
					}		
				private:
					int r;
			};

			void main();
		}

		namespace s14
		{
			struct Ellipse : Shape
			{
					//Ellipse (Point p, int w, int h);
					Ellipse (Point p, int w1, int h1) :
						w {w1},
						h {h1}
					{
						add(p);
					}
					void	draw_lines	() const;
					Point	focus1		() const;
					Point	focus2		() const;
					Point	center		() const
					{
						return point(0);
					}
					void	set_major	(int ww)
					{
						set_point (
							0, 
							Point {
								center().x - ww,				/// to the left 
								center().y - h					/// to the top corner
							}
						);
						w = ww;
					}
					int		major		() const 
					{
						return w;
					}
					void	set_minor	(int hh)
					{
						set_point (
							0, 
							Point {
								center().x - w,					/// to the left corner
								center().y - hh					/// upwards
							}
						);
						h = hh;
					}
					int		minor		() const 
					{
						return h;
					}
		
				private:
					int
						w,										/// horizontal radius
						h;										/// vertical radius
			};
		}

		namespace s15
		{
			struct Marked_polyline : s05::Open_polyline
			{
					Marked_polyline (const string & m) :
						mark {verify_mark(m)}
					{}		
					Marked_polyline (const string & m, initializer_list<Point> lst) :
						Open_polyline {lst},					// directly refering to the parent class constructor here
						mark {verify_mark (m)}
					{}	
					void draw_lines () const;
		
				private:
					string mark;		
					void	draw_mark	(Point, char) const;		
					string	verify_mark (const string & m)		/// added to clean the constructors a bit
					{						
						return (m == "" ? "*" : m);
					}		
			};		
			void main();
		}

		namespace s16
		{
			struct Marks : s15::Marked_polyline
			{
					Marks (const string & m) :
						Marked_polyline {m}
					{
						make_invisible();
					}
					Marks (const string & m, initializer_list<Point> lst) :
						Marked_polyline {m, lst}
					{
						make_invisible();
					}
				private:
					void make_invisible()
					{
						set_color (Color {Color::Transparency::invisible});
					}
			};
			
			void main();
		}

		namespace s17
		{
			struct Mark : s16::Marks
			{
				Mark (Point xy, char c) : 
					Marks {string { 1, c}}
				{
					add (xy);
				}
			};

			void main();
		}

		namespace s18
		{
			enum class Suffix
			{
				none,
				jpg,
				gif
			};
			struct Image : Shape
			{
					Image (Point xy, string file_name, Suffix e = Suffix::none);
					~Image ()
					{
						delete p;
					}
					void draw_lines() const;
					void set_mask (Point xy, int ww, int hh)
					{
						w = ww;
						h = hh;
						cx = xy.x;
						cy = xy.y;
					}				
				private:
					int
						w,
						h,
						cx,
						cy;
					Fl_Image 
						* p;
					Text 
						fn;

					bool can_open (const string & s)
					{
						ifstream 
							ff (s);
						return bool (ff);						/// this would probably yield wrong type, so preventing by casting to bool
					}
			};

			struct Bad_image : Fl_Image 
			{
				Bad_image (int h, int w) :
					Fl_Image {h, w, 0}
				{}
				void draw (int x, int y, int, int, int, int)
				{
					draw_empty (x, y);
				}
			};
		}
	}

	namespace drill
	{
		namespace d01
		{
			void main();
		}

		namespace d02
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

		namespace d05
		{
			void main();
		}	
	}

	namespace excercise
	{
		namespace e01
		{
			struct Arc : Graph_lib::Ellipse
			{
					Arc (Point p, int ww, int hh, double a1, double a2) :
						start {a1}, end {a2}, Ellipse {p, ww, hh}
					{}

					void draw_lines() const;
				private:

					double
						start,
						end;
			};

			void main();
		}

		namespace e02
		{
			struct Arc : Graph_lib::Circle
			{
				Arc (Point p, int r, int s) :
					start {double ( 90 * s)}, Circle {p, r}
					{}
					void draw_lines() const;
				private:
					double
						start;
			};

			void main();
		}
	}
}