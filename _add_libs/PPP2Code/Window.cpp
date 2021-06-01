#include<vector>
//#include "Window.h"				//v/ contrary to the 12.8 assumption this one seems unnecessary
#include "Graph.h"
#include "Gui.h"


using namespace std;

namespace Graph_lib 
{
	Window::Window(int ww, int hh, const string &title)
		: Fl_Window(ww, hh, title.c_str()), w(ww), h(hh)
	{
		init();
	}

	Window::Window(Point xy, int ww, int hh, const string &title)
		: Fl_Window(xy.x, xy.y, ww, hh, title.c_str()), w(ww), h(hh)
	{
		init();
	}

	void Window::init()
	{
	   resizable(this);
	   show();
	} 

	void Window::draw()
	{
		Fl_Window::draw();
		for (unsigned int i = 0; i < shapes.size(); ++i) 
			shapes[i] -> draw();		//v/ begs for Graph.h
	}

	void Window::attach(Widget & w)
	{
		begin();												/// FTLK: begin attaching new Fl_Wigets to this window
		w.attach(* this);				//v/ begs for Gui.h		/// let the Widget create its Fl_Wigits			
		end();													/// FTLK: stop attaching new Fl_Wigets to this window
	}

	void Window::detach(Widget & b)
	{
		b.hide();						//v/ begs for Gui.h
	}

	void Window::attach(Shape &s)
	{
			shapes.push_back( & s);
			//s.attached = this;
	}
	
	void Window::detach(Shape &s)
	{
			for (unsigned int i = shapes.size(); 0 < i; --i)	/// guess last attached will be first released
				if (shapes[i - 1] == &s)
					shapes.erase(shapes.begin() + (i - 1));		///&shapes[i-1]);
	}

	void Window::put_on_top(Shape &p) 
	{
		for (int i = 0; i < int (shapes.size()); ++i) 
		{
			if ( &p == shapes[i]) 
			{
				for (++i; i < int (shapes.size()); ++i)
					shapes[i - 1] = shapes[i];
				shapes[shapes.size() - 1] = &p;
				return;
			}
		}
	}

	int gui_main() 
	{ 
		return Fl::run(); 
	}

} // Graph
