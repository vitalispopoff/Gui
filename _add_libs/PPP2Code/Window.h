#ifndef WINDOW_GUARD
#define WINDOW_GUARD 1

#include <string>
#include <vector>
#include "fltk.h"
#include "Point.h"
//#include "GUI.h"

using namespace std;

namespace Graph_lib 
{
	class Shape;												/// "forward declare" Shape	
	class Widget;
	class Window : public Fl_Window 
	{ 
		public: 
			Window(int, int, const string &);					/// let the system pick the location
			
			Window(Point, int, int, const string &);			/// top left corner in xy

			virtual ~Window() {}

			void	attach		(Shape	& s);
			void	attach		(Widget & w);
			void	detach		(Shape	& s);					/// remove s from shapes 
			void	detach		(Widget & w);					/// remove w from window (deactivate callbacks)
			void	put_on_top	(Shape	& p);					/// put p on top of other shapes

			int		x_max		() const 
			{
				return w;
			}
			int		y_max		() const 
			{ 
				return h; 
			}
			void	resize		(int ww, int hh) 
			{ 
				w = ww, 
				h = hh; 
				size(ww,hh); 
			}
			void	set_label	(const string & s) 
			{ 
				label(s.c_str()); 
			}

		protected:
			void	draw		();
     
		private:
			  void init			();

			//vector<Shape *> 
			vector<Shape * >
				shapes;											/// shapes attached to window
			int													/// window size
				w,
				h;					
	}; 

	int gui_main();												/// invoke GUI library's main event loop

	inline int x_max()											/// width of screen in pixels
	{
		return Fl::w();
	}
	inline int y_max()											/// height of screen in pixels
	{
		return Fl::h();
	}
}
#endif
