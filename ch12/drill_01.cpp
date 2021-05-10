#include "../_add_libs/PPP2Code/Graph.h"
#include "../_add_libs/PPP2Code/Simple_window.h"

using namespace Graph_lib;

namespace ch12
{
	namespace drill
	{
		void _01()
		{
			int
				dispW	{x_max()},								//v/	display width
				dispH	{y_max()},								//v/	display height
				winW	{600},									//v/	window width
				winH	{400},									//v/	window height
				anchW	{(dispW - winW) >> 1},					//v/	top left corner X of the window to display it centered
				anchH	{(dispH - winH) >> 1};					//v/	top left corner Y fo the window to display it centered
			Point
				anchor	{anchW, anchH};
			Simple_window
				win		{anchor, 600, 400, "My window"};

			win.wait_for_button();
		}
	}
}