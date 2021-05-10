#include "../_add_libs/PPP2Code/Graph.h"
#include "../_add_libs/PPP2Code/Simple_window.h"

using namespace Graph_lib;

namespace ch12
{
	namespace example
	{
		void _08()
		{

			string
				content		{"Would use 'cin', but 'wait_for_button' would prevent. Sorry"};
			int
				height		{400},
				width		{600},
				txtSize		{16},
				txtLen		{int(sizeof(content)) * txtSize},
				txtAnchX	{(width - txtLen) >> 1},
				txtAnchY	{(height - txtSize) >> 1};
			Point
				tl			{100, 100},
				txtAnch		{txtAnchX, txtAnchY};
			Simple_window
				win			{tl, width, height, ""};
			Text
				txt			{txtAnch, content};
			Color
				color		{Color::Color_type::black};
			Font
				f			{Font::Font_type::helvetica};
			txt.set_color	(color);
			txt.set_font	(f);
			txt.set_font_size(txtSize);

			win.attach		(txt);
			win.wait_for_button();
		}
	}
}