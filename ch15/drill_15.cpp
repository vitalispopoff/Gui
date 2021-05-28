//#include <stdexcept>
#include <iostream>
#include "ch15_drill.h"


namespace ch15
{
	namespace drill
	{
		using namespace constants;

		// part 1

		namespace d01
		{			
			void main()
			{
				Graph_lib::Window
					win {win_anchor, win_size.x, win_size.y, win_lab};
				Axis
					ax_x {
						Axis::Orientation::x,
						{(win_size.x - ax_len) >> 1, win_size.y >> 1},						
						ax_len,
						ax_unit_len,
						ax_lab
					},
					ax_y {
						Axis::Orientation::y,
						{win_size.y >> 1, win_size.y - ((win_size.y - ax_len) >> 1)},
						ax_len,
						ax_unit_len,
						ax_lab
					};
				ax_x.set_color	(ax_col);
				ax_y.set_color	(ax_col);
				win.attach	(ax_x);
				win.attach	(ax_y);			
				Function
					f1 {
						[] (double) { return 1.;},
						f_min,
						f_max,
						f_orig,
						f_count, 
						f_x_unit_len,
						f_y_unit_len,
					};
				win.attach (f1);
				for (char c {0};  c != 'x'; std::cin >> c)
					Fl::wait();
			}
		}

		namespace d03
		{			
			void main()
			{
				Graph_lib::Window
					win {win_anchor, win_size.x, win_size.y, win_lab};
				constants::Axis
					ax_x {Axis::Orientation::x},
					ax_y {Axis::Orientation::y};
				win.attach	(ax_x);
				win.attach	(ax_y);			
				constants::Function
					f1 {[] (double) {return 1.;}};
				win.attach (f1);
				for (char c {0};  c != 'x'; std::cin >> c)
					Fl::wait();
			}
		}

		namespace d04
		{
			void main()
			{
				Graph_lib::Window
					win {win_anchor, win_size.x, win_size.y, win_lab};
				constants::Axis
					ax_x {Axis::Orientation::x},
					ax_y {Axis::Orientation::y};
				win.attach	(ax_x);
				win.attach	(ax_y);			
				constants::Function
					f1 {[] (double) {return 1.;}},
					f2 {[] (double x) {return x * 0.5;}};
				win.attach (f1);
				win.attach (f2);
				for (char c {0};  c != 'x'; std::cin >> c)
					Fl::wait();
			}
		}

		// part 2

		namespace d05
		{
			double slope (double x) 
			{
				return x * 0.5;
			}
			void main()
			{
				Graph_lib::Window
					win {win_anchor, win_size.x, win_size.y, win_lab};
				constants::Axis
					ax_x {Axis::Orientation::x},
					ax_y {Axis::Orientation::y};
				win.attach	(ax_x);
				win.attach	(ax_y);			
				constants::Function
					f1 {[] (double) {return 1.;}},
					f2 {[] (double x) {return x * 0.5;}};
				win.attach (f1);
				win.attach (f2);
				Text
					f2_lab { 
						{f_orig.x + int(f_min * f_x_unit_len), f_orig.y - 10 - int(slope(f_min) * f_y_unit_len)}, // '- 10' at .y coord should be derived from font size
						"x/2"
					};
				win.attach (f2_lab);

				for (char c {0};  c != 'x'; std::cin >> c)
					Fl::wait();
			}
		}

		namespace d06
		{
			double	slope	(double x) 
			{
				return x * 0.5;
			}
			double	square	(double x)
			{
				return x * x;
			}
			void main()
			{
				Graph_lib::Window
					win {win_anchor, win_size.x, win_size.y, win_lab};
				constants::Axis
					ax_x {Axis::Orientation::x},
					ax_y {Axis::Orientation::y};
				win.attach	(ax_x);
				win.attach	(ax_y);			
				constants::Function
					f1	{[] (double) {return 1.;}},
					f2	{slope},
					f3	{square, f_min, f_max, f_orig, f_count * ax_unit_len};
				win.attach (f1);
				win.attach (f2);
				win.attach (f3);
				Text
					f2_lab { 
						{f_orig.x + int(f_min * f_x_unit_len), f_orig.y - 10 - int(slope(f_min) * f_y_unit_len)}, // '- 10' at .y coord should be derived from font size
						"x/2"
					};
				win.attach (f2_lab);

				for (char c {0};  c != 'x'; std::cin >> c)
					Fl::wait();
			}
		}
		
		namespace d07
		{
			using d06::slope;
			using d06::square;
			void main()
			{
				Graph_lib::Window
					win {win_anchor, win_size.x, win_size.y, win_lab};
				constants::Axis
					ax_x {Axis::Orientation::x},
					ax_y {Axis::Orientation::y};
				win.attach	(ax_x);
				win.attach	(ax_y);			
				constants::Function
					f1	{[] (double) {return 1.;}},
					f2	{slope},
					f3	{square, f_min, f_max, f_orig, f_count * ax_unit_len},
					f4	{[] (double x) {return cos(x);}, f_min, f_max, f_orig, f_count * ax_unit_len};
				f4.set_color (Color::Color_type::blue);	///p2 drill 8
				win.attach (f1);
				win.attach (f2);
				win.attach (f3);
				win.attach (f4);
				Text
					f2_lab { 
						{f_orig.x + int(f_min * f_x_unit_len), f_orig.y - 10 - int(slope(f_min) * f_y_unit_len)}, // '- 10' at .y coord should be derived from font size
						"x/2"
					};
				win.attach (f2_lab);

				for (char c {0};  c != 'x'; std::cin >> c)
					Fl::wait();
			}
		}

		namespace d09
		{
			using d06::slope;
			using d06::square;
			double sloping_cos (double x)
			{
				return cos (x);
			}
			void main()
			{
				Graph_lib::Window
					win {win_anchor, win_size.x, win_size.y, win_lab};
				constants::Axis
					ax_x {Axis::Orientation::x},
					ax_y {Axis::Orientation::y};
				win.attach	(ax_x);
				win.attach	(ax_y);			
				constants::Function
					f1	{[] (double) {return 1.;}},
					f2	{slope},
					f3	{square, f_min, f_max, f_orig, f_count * ax_unit_len},
					f4	{[] (double x) {return cos(x);}, f_min, f_max, f_orig, f_count * ax_unit_len},
					f5	{sloping_cos, f_min, f_max, f_orig, f_count * ax_unit_len};
				f4.set_color (Color::Color_type::blue);	///p2 drill 8
				win.attach (f1);
				win.attach (f2);
				win.attach (f3);
				win.attach (f4);
				win.attach (f5);
				Text
					f2_lab { 
						{f_orig.x + int(f_min * f_x_unit_len), f_orig.y - 10 - int(slope(f_min) * f_y_unit_len)}, // '- 10' at .y coord should be derived from font size
						"x/2"
					};
				win.attach (f2_lab);

				for (char c {0};  c != 'x'; std::cin >> c)
					Fl::wait()
					;
			}
		}

		// part 3

		namespace d10
		{
			Person::Person (string n, int a = 0) :
					name {n}
			{
				if (a < 0)
					error ("negative age nod allowed");
				age = a;
			}
			ostream & operator << (ostream & os, Person & p)
			{
				os 
					<< p.name 
					<<", " 
					<< p.age;
				return os;						
			}
			void main()
			{
				Person 
					p	{"Goofy", 63};
				std::cout 
					<< p
					<< endl;		
				for(char c {0}; c != 'x' ;std::cin >> c);
			}
		}

		namespace d12
		{
			using d10::Person;
			using d10::operator <<;
			istream & operator >> (istream & is, Person & p)
			{
				is 
					>> p.name 
					>> p.age;
				return is;
			}
			void main()
			{
				Person 
					p;
				std::cin 
					>> p;
				std::cout 
					<< p
					<< endl;		
				for(char c {0}; c != 'x' ;std::cin >> c);
			}
		}

		namespace d14
		{
			ostream & operator << (ostream & os, Person & p)
			{
				os 
					<< p.name()
					<<", " 
					<< p.age();
				return os;						
			}
			istream & operator >> (istream & is, Person & p)
			{
				string n;
				int a;
				is >> n >> a;
				p.name(n);
				p.age(a);
				return is;
			}
			void main()
			{
				Person 
					p;
				std::cin 
					>> p;
				std::cout 
					<< p
					<< endl;		
				for(char c {0}; c != 'x' ;std::cin >> c);
			}
		}

		namespace d15
		{
			Person::Person () :
				name_ {""}, age_{0}
			{}
			Person::Person (string n, int a = 0) :
				name_{check_name(n)},  age_{check_age(a)}
			{}

			void Person::name (string n)
			{
				set_name(check_name(n));
			}
			void Person::age (int a)
			{
				set_age (check_age(a));
			}

			string	Person::check_name	(string n)
			{
				for(char c : n)
					if( ispunct(c))
						error ("punctuation characters are not allowed");
				return n;
			}
			int		Person::check_age	(int a)
			{
				if (a < 0 || a > 150)
					error ("input is outside the age range");
				return a;
			}

			ostream & operator << (ostream & os,d15::Person & p)
			{
				os 
					<< p.name()
					<<", " 
					<< p.age();
				return os;						
			}
			istream & operator >> (istream & is, d15::Person & p)
			{
				string n;
				int a;
				is >> n >> a;
				p.name(n);
				p.age(a);
				return is;
			}

			void main()
			{
				Person 
					p;
				std::cin 
					>> p;
				std::cout 
					<< p
					<< endl;		
				for(char c {0}; c != 'x' ;std::cin >> c);
			}
		}

		namespace d16
		{
			using namespace d15;
			void main()
			{
				vector<Person>
					peeps;
				try
				{
					while(true)
					{
						Person p;
						cin >> p;
						peeps.push_back(p);
						int 
							index {int(peeps.size())};
						index -= (index > 0);
						cout << peeps[index].name() << " saved under index " << index << endl;
					}
				}
				catch (exception & e)
				{
					for(Person p : peeps)
						cout << p << endl;
				}
				for(char c {0}; c != 'x' ;std::cin >> c);
			}
		}


	}	
}