#include "_add_libs/PPP2Code/Graph.h"
#include "_add_libs/PPP2Code/Simple_window.h"

using namespace Graph_lib;

namespace ch12
{
	void _04()
	{
		Point
			tl		{100, 100},
			center	{20, 300},
			sin0	{20, 150};
		Simple_window
			win		{tl, 600, 400, ""};
		int
			length	{280},
			scale	{10},
			sinRes	{1000};
		double
			sinFrq	{25},									//v/ x axis scale
			sinAmp	{50};									//v/ y axis scale

		Axis
			xa		{Axis::Orientation::x, center, length, scale, "x axis"},
			ya		{Axis::Orientation::y, center, length, scale, "y axys"};
		Color
			black	{Color::Color_type::black},
			blue	{Color::Color_type::blue};
		Function 
			sine	{sin, 0, 100, sin0, sinRes,sinFrq, sinAmp};

		xa.set_color	(black);
		ya.set_color	(black);
		sine.set_color	(blue);
		win.attach (xa);
		win.attach (ya);
		win.attach (sine);
		win.wait_for_button();
	}
}