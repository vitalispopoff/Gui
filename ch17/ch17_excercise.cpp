#include "ch17.h"

namespace ch17
{
	namespace excercise
	{
		using ch17::keep_open;

		namespace e02
		{
			int main()
			{
				cout 
					<< "short :\t" << sizeof(short) << endl
					<< "int : \t" << sizeof(int) << endl
					<< "long : \t" << sizeof(long long) << endl;
				return keep_open();
			}
		}

		namespace e03
		{
			void to_lower (char * s)
			{
				for (char * c = s; * c != 0; ++c)
					if (* c > 64 && * c < 91)
						* c+= 32;
			}

			int main()
			{				
				string 
					s = "StrIng_S" + char(0);
				char
					* p = & s[0];
				to_lower (p);
				cout 
					<< s;
				return keep_open();
			}
		}

		namespace e04
		{
			char * strdup(const char * s)
			{
				int 
					index = 0;
				while (s[index] != 0)
					++index;
				char 
					* s1 = new char[index + 1];
				for (int i = 0 ; i < index + 1; ++i)
					s1[i] = s[i];
				
				return s1;	
			}
			int main()
			{
				auto  print_array = [](char * s)
				{
					int
						i = 0;
					while (s[i])
						cout << s[i++];
				};
				string 
					s = "String_s" + char(0);
				char 
					* p = & s[0],
					* p1 = strdup(p);
				cout << s << endl;
				print_array(p);
				cout << endl;
				print_array(p1);
				cout << endl;
				delete [] p1;
				p1 = nullptr;
				return keep_open();
			}
		}

		namespace e05
		{
			char * findx(char * s, char * x)
			{
				int
					i {0},
					j {0};
				while (s[i] && x[j])
				{
					if (s[i] != x[j])
					{
						i++;
						j = 0;
					}
					while (s[i] == x[j])
					{
						i++;
						j++;
					}
				}
				if (s[i])
				{
					int
						index = i - j;
					cout << "index : " << index << endl;
					char 
						* result = & s[index];
					return result;
				};
				return nullptr;
			}
			int main()
			{
				auto print_string = [](const char * c)
				{
					int 
						i {0};
					while (c[i])
						cout << c[i];	
				};
				string
					s1 = "012qqqaabgbbafibacquw1209abc109mcw" + char(0),
					s2 = "abc" + char(0);
				char 
					* p1 = & s1[0],
					* p2 = & s2[0],
					* result = findx(p1, p2);
				cout << p2 << '\t' << p1 << endl;
				cout << result << endl;
				return keep_open();
			}
		}

		namespace e06
		{
			int main()
			{
				while (true)
				{
					double
						* d = new double[1];
				}
				return keep_open();
			}
		}

		namespace e07
		{
			int main()
			{
				int
					len {0};
				char
					c {0},
					* c1 = nullptr,
					* c2 = nullptr;
				while (cin >> c && c != '!')
				{				
					len++;
					c1 = new char[len];
					for (int i = 0; i < len - 1; ++i)
						c1[i] = c2[i];
					c1[len - 1] = c;
					delete [] c2;
					c2 = c1;
				}

				for (int i = 0; i < len; ++i)
					cout << c2[i];
				cout << endl;
				return keep_open();
			}
		}

		namespace e08
		{
			int main()
			{
				char 
					c {0};
				string
					* s1 = new string;
				while (cin >> c && c != '!')
					s1->push_back (c);
				cout 
					<< * s1 
					<< endl;
				return keep_open();
			}
		}

		namespace e09
		{
			int main()
			{
				int
					c1 {0},
					c2 {1},
					c3 {2};
				cout 
					<< "\nstack :\n"
					<< & c1 << endl
					<< & c2 << endl
					<< & c3 << endl;
				int
					* d1 = new int (0),
					* d2 = new int (1),
					* d3 = new int (2);
				cout 
					<< "\nheap :\n"
					<< & d1 << endl
					<< & d2 << endl
					<< & d3 << endl;
				delete d1;
				delete d2;
				delete d3;
				d1 = d2 = d3 = nullptr;
				return keep_open();
			}
		}

		namespace e13
		{}
	}
}