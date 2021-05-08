#include <FL/Fl.H>
#include <FL/Fl_Box.h>
#include <FL/Fl_Window.h>

int test()
{
	Fl_Window
		window(200, 200, "Window title");
	Fl_Box
		Box(0, 0, 200, 200, "Hey, I mean, Hello, World!");
	window.show();
	return Fl::run();
}