#ifndef GUI_GUARD
#define GUI_GUARD

//#include "fltk.h"				//v/ contrary to 12.8 this seems unnecessary
#include "Window.h"
#include "Graph.h"			

namespace Graph_lib 
{	
	typedef void * Address;
	typedef void (* Callback)(Address, Address);				/// FLTK's required function type for all callbacks

	template<class W> W &reference_to(Address pw)				/// treat an address as a reference to a W
	{
		return *static_cast<W *>(pw);
	}
																/// Widget is a handle to a Fl_widget - it is *not* a Fl_widget																
	class Widget												/// We try to keep our interface classes at arm's length from FLTK
	{
		public:
			Widget(Point xy, int w, int h, const string& s, Callback cb)
				: loc(xy), width(w), height(h), label(s), do_it(cb)
			{}

			virtual void	move		(int dx, int dy) 
			{ 
				hide(); 
				pw -> position(loc.x += dx, loc.y += dy); 
				show(); 
			}
			virtual void	hide		() 
			{	
				pw -> hide();
			}
			virtual void	show		() 
			{
				pw -> show(); 
			}
			virtual void	attach		(Window &) = 0;			/// each Widgit define at least one action for a window

			Point 
				loc;
			int 
				width,
				height;
			string 
				label;
			Callback 
				do_it;

			virtual ~Widget() {}

			//Widget(const Widget &a) 
			//	: loc(a.loc) 
			//{ 
			//	error("attempt to copy Widget by constructor"); 
			//}

			//Widget & operator = (const Widget &a)
			//{
			//	error("attempt to copy Widget by cassignment");
			//	return *this;
			//}

		protected:
			Window * own;										/// every Widget belongs to a Window
			Fl_Widget *pw;
		private:
			Widget & operator = (const Widget &);				/// don't copy Widgets
			Widget(const Widget &);
	};

	class Button : public Widget 
	{
		public:
			Button(Point xy, int ww, int hh, const string &s, Callback cb)
				: Widget(xy, ww, hh, s, cb)
			{}
			void attach(Window &win);
	};

	struct In_box : Widget 
	{
		In_box(Point xy, int w, int h, const string &s)
			: Widget(xy, w, h, s, 0)
		{}
		int get_int();
		string get_string();

		void attach(Window& win);
	};

	struct Out_box : Widget 
	{
		//Out_box(Point xy, int w, int h, const string &s, Window& win)
		Out_box(Point xy, int w, int h, const string &s) : 
			Widget(xy, w, h, s, 0)
		{}
		
		void	put		(int);
		void	put		(const string &);
		void	attach	(Window &win);
	};

	struct Menu : Widget 
	{
		enum class Kind											//v/ enum changed to enum class
		{ 
			horizontal, 
			vertical 
		};
		
		Menu(Point xy, int w, int h, Kind kk, const string &s);

		//int		insert		(int i, const Button &b);		/// not implemented
		int		attach		(Button& b);						/// attach button; Menu does not delete &b
		int		attach		(Button* p);						/// attach new button; Menu deletes p
		void	attach		(Window &win)
		{
			for (int i = 0; i < selection.size(); ++i) 
				win.attach(selection[i]);
		}	
		void	show		() 
		{ 
			for (int i = 0; i < selection.size(); ++i) 
				selection[i].show();
		}
		void	hide		() 
		{ 
			for (int i = 0; i < selection.size(); ++i) 
				selection[i].hide(); 
		}
		void	move		(int dx, int dy)
		{ 
			for (int i = 0; i < selection.size(); ++i) 
				selection[i].move(dx,dy); 
		}

		Vector_ref<Button>				//v/ begs for Graph.h
			selection;
		Kind 
			k;
		int 
			offset;
	};
}
#endif