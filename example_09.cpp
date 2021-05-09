#include "_add_libs/PPP2Code/Simple_window.h"

using namespace Graph_lib;

namespace ch12
{
	void _09()
	{
		string
			imgAdd	{"E:\\_LAB\\_C\\Gui\\_other\\"},
			//imgName	{"kuvaton-kuka_jatti_ikkunan_auki2.jpg"};
			imgName	{"dog_9.gif"};
		Point
			tl		{100, 100};
		int
			width	{600},
			height	{400};
		Simple_window
			win		{tl, width, height, ""};
		Image
			img		{Point {0, 0}, string(imgAdd + imgName)};
		win.attach	(img);
		win.set_label(imgName);
		win.wait_for_button();
	}	
}