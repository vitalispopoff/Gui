#include "ch15_excercise.h"
#include "ch15_sample.h"
#include <fstream>
#include <iostream>
#include <sstream>

namespace ch15
{
	namespace excercise
	{
		namespace e05
		{
			int
				n {1};
			double
				leibniz_prev {1};
			double leibniz (double x)
			{
				int
					denominator	{1 + (n << 1)},
					sign		{((n & 1) << 1) - 1};
				return leibniz_prev + 1. / double(denominator) * double(sign);
			}
			void main()
			{
				int
					win_size {600};
				Point
					win_anchor {1100, 400};
				Simple_window
					window	{win_anchor, win_size, win_size, ""};

				int
					margin {100},
					ax_len {win_size - (margin << 1)};
				Point
					orig	{win_size >> 1, win_size >> 1},
					ax_x_anchor	{margin, orig.y},
					ax_y_anchor {orig.x, win_size - margin};
				Axis
					ax_x	{Axis::Orientation::x, ax_x_anchor, ax_len},
					ax_y	{Axis::Orientation::y, ax_y_anchor, ax_len};					
				window.attach (ax_x);
				window.attach (ax_y);
				for ( ; n < 50; ++n)
				{
					std::ostringstream
						ss;
					ss 
						<< n;
					window.set_label (ss.str().c_str());				
					Function
						f_leibniz {
							[] (double x) {return leibniz(x);},
							-10,
							11,
							orig,
						};
					window.attach(f_leibniz);
					window.wait_for_button();
					window.detach(f_leibniz);
				}
			}
		}

		namespace e06
		{
			vector<double>	
				bar_values {100, 50, 1};
			Bar_chart
				bar	{{50, 50}, 500, 300, bar_values};
			void main()
			{
			Simple_window
				window {{1000, 500}, 600, 400, ""};
				window.attach (bar);
				window.wait_for_button();
			}
		}

		namespace e07
		{
			//using e06::bar_values;
			vector<double>	
				bar_values {100, 50, 1};
			void main()
			{
				Simple_window
					window {{1000, 500}, 600, 400, ""};
				Bar_chart
					bar {{50, 50}, 500, 300, bar_values};
				bar.set_fill_color (Color::Color_type::dark_cyan);
				window.attach (bar);
				window.wait_for_button();	
			}
		}		

		namespace e08
		{
			vector <pair <int, int>> load_data()
			{
				string
					filename {"../_other/wzrost.txt"};
				ifstream
					ifs (filename);
				if (!ifs)
					error ("couldn't open file " + filename);
				vector <pair <int, int>>
					result;
				char
					c1	{0},
					c2	{0},
					c3	{0};
				pair <int, int>
					p;
				while (ifs >> c1 >> p.first >> c2 >> p.second >> c3)					
				{
					result.push_back(p);
					if (c1 != '(' || c2 != ',' || c3 != ')')
						error ("failed to read file");
				};
				ifs.close();
				return result;
			}

			void main()
			{
				Simple_window
					window	{{1000, 500}, 600, 400, ""};
				vector <pair <int, int>>
					bar_values = load_data();
				Bar_chart
					bar	{{50, 50}, {500, 300}};
				 
				for ( pair <int, int> p : bar_values)
				{
					stringstream
						ss;
					ss << p.first;
					string
						s;
					ss >> s;
					bar.add_bar(s, double (p.second));
				}
				bar.set_color ({Color::Color_type::black, Color::Transparency::visible});
				bar.set_fill_color ({Color::Color_type::cyan, Color::Transparency::visible});
				window.attach (bar);
				Axis 
					axis	{Axis::Orientation::y, {bar.anch.x - 10, bar.anch.y + bar.size.y}, bar.size.y, int(bar.max_bar_value)};
				window.attach (axis);
				window.wait_for_button();
			}
		}
	}
}