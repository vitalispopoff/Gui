#include "../_add_libs/PPP2Code/Simple_window.h"

using namespace Graph_lib;

namespace ch12
{
	namespace example
	{
		void _12()
		{
			int
				dispX	{x_max()},
				dispY	{y_max()},
				winX	{dispX >> 1},
				winY	{dispY >> 1},
				anchX	{dispX >> 2},
				anchY	{dispY >> 2};
			Point
				winAnch	{anchX, anchY};
			Simple_window
				win		{winAnch, winX, winY, ""};

			int
				imgX	{320},
				imgY	{240};
			Point
				imgAnch	{(winX - imgX) >> 1,(winY - imgY) >> 1},
				crop	{120, 60};
			string
				imgAdd	{"E:\\_LAB\\_C\\Gui\\_other\\"},
				imgName	{"kuvaton-kuka_jatti_ikkunan_auki2.jpg"};
			Image
				img		{imgAnch, imgAdd + imgName};

			img.set_mask(crop, imgX, imgY);
		
			win.attach	(img);
			win.wait_for_button();
		}
	}
}