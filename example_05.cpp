
//#include "_add_libs/PPP2Code/Graph.h"
#include "_add_libs/PPP2Code/Simple_window.h"

using namespace Graph_lib;

namespace ch12
{
	void _05()
	{
		/// please, do enjoy your piece-of-turd-splattered-against-the-wall code formatting.		
		Graph_lib::Polygon poly;
		poly.add(Point{300,200});
		poly.add(Point{350,100});
		poly.add(Point{400,200});
		poly.set_color(Color::Color_type::red);
		poly.set_style(Line_style::Line_style_type::dash);
		Simple_window win{Point{100,100},600,400,""};
		win.attach(poly);
		win.wait_for_button();					
	}
}