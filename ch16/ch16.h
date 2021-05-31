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

				void next();
			};

		}
	}
}