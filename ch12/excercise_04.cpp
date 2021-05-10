#include<iostream>

#include "../_add_libs/PPP2Code/Graph.h"
#include "../_add_libs/PPP2Code/Simple_window.h"

using namespace std;
using namespace Graph_lib;

namespace ch12
{
	namespace excercise
	{
		void __04()
		{					
			Color 
				red		{Color::Color_type::red},
				white	{Color::Color_type::white};			

			Simple_window
				window		{Point {100, 100}, 301, 301, "exc 04"};		

			Graph_lib::Rectangle
				r1{Point {1, 1}, 99, 99},
				r2{Point {1, 100}, 99, 99},
				r3{Point {1, 200}, 99, 99},
				r4{Point {101, 1}, 99, 99},
				r5{Point {101, 100}, 99, 99},
				r6{Point {101, 200}, 99, 99},
				r7{Point {201, 1}, 99, 99},
				r8{Point {201, 100}, 99, 99},
				r9{Point {201, 200}, 99, 99};

			r1.set_fill_color	(red);
			r2.set_fill_color	(white);
			r3.set_fill_color	(red);
			r4.set_fill_color	(white);
			r5.set_fill_color	(red);
			r6.set_fill_color	(white);
			r7.set_fill_color	(red);
			r8.set_fill_color	(white);
			r9.set_fill_color	(red);

			window.attach	( r1);
			window.attach	(r2);
			window.attach	(r3);
			window.attach	(r4);
			window.attach	(r5);
			window.attach	(r6);
			window.attach	(r7);
			window.attach	(r8);
			window.attach	(r9);

			window.wait_for_button();
		}
	}
}