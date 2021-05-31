#pragma once
#include "../_add_libs/PPP2Code/Gui.h"

namespace ch16
{
	namespace sample
	{
		namespace s01
		{
			using namespace Graph_lib;
			struct Simple_window : Window
			{
					Simple_window (Point xy, int w, int h, const string & title);

					void wait_for_button();
				private:
					Button 
						next_button;
					bool 
						button_pushed;

				/// Widget interface requires two functions for a proper callback communication
				/// one to connect with the system lower levels
				/// the other to deliver action on our level on the callback
					static void cb_next (Address, Address);
					void next();
			};
		}

		namespace s02
		{
			using namespace Graph_lib;
			struct Simple_window : Window /// wished for inherit from s01::Simple_window, but the implementation wouldn't allow
			{
				Simple_window (Point xy, int w, int h, const string & title);
				Button 
					next_button;
				bool
					button_pushed;
				void next(){}
			};
		}

		namespace s03
		{
			using namespace Graph_lib;

			struct Button : Widget
			{
				Button (
					Point xy, 
					int w, 
					int h, 
					const string & label, 
					Callback cb
				);

			};
		}

		namespace s04
		{
			using namespace Graph_lib;
			using Graph_lib::Window;
			class Widget
			{
				public :
					Widget (
						Point xy, 
						int w, 
						int h, 
						const string & s, 
						Callback cb
					);

					virtual	void	move	(int dx, int dy);
					virtual	void	hide	();
					virtual	void	show	();
					virtual	void	attach	(Window &) = 0;

					Point
						loc;
					int
						width,
						height;
					string
						label;
					Callback
						do_it;
				protected :
					Window * own;
					Fl_Widget * pw;
			};
		}

		namespace s05
		{
			using namespace Graph_lib;
			using Graph_lib::Window;
			class Button : public Widget	/// what is this public thing?
			{
				public :
					Button (
						Point xy, 
						int ww, 
						int hh, 
						const string & s, 
						Callback cb
					) :
						Widget {xy, ww, hh, s, cb}
					{}
					void attach (Window & win);
			};
		}

		namespace s06
		{
			using namespace Graph_lib;
			using Graph_lib::Window;
			struct In_box : Widget
			{
				In_box (Point xy, int w, int h, const string & s) :
					Widget {xy, w, h, s, 0}
				{}
				int get_int ();
				string get_string();
				void attach (Window & win);					
			};

			struct Out_box : Widget 
			{
				Out_box (Point xy, int w, int h, const string & s) :
					Widget {xy, w, h, s, 0}
				{}
				void put (int);
				void put (const string &);
				void attach (Window & win);
			};
		}

		namespace s07
		{
			using namespace Graph_lib;
			using Graph_lib::Window;
			struct Menu : Widget
			{
				enum Kind {
					horizontal,
					vertical
				};
				Menu (Point xy, int w, int h, Kind kk, const string & label);
				Vector_ref <Button> 
					selection;
				Kind
					k;
				int
					offset;
				int attach (Button & p);
				int attach (Button * p);
				void show()
				{
					//for (Button & b : selection)				/// non suitable 'begin()' was found for 'seleection'
						//b.show();
					for (int i = 0; i < selection.size(); ++i)
						selection[i].show();
				}
				void hide();
				void move (int dx, int dy);
				void attach (Window & win);
			};
		}

		namespace s08
		{
			using namespace Graph_lib;
			struct Lines_window : Window 
			{
					Lines_window (Point xy, int w, int h, const string & title);
					Open_polyline
						lines;
				private :
					Button
						next_button,
						quit_button;
					In_box
						next_x,
						next_y;
					Out_box 
						xy_out;

					void next();
					void quit();
			};
			int main();
		}
	}
}