#include "ch18.h"

#include <iostream>

namespace ch18
{
	namespace excercise
	{
		namespace e01
		{
			char * strdup (const char * c)
			{
				int 
					index = 1;	/// already taking into account the termination char.
				char
					* c1 = const_cast<char *> (c);
				while (* c1)
				{
					++index;
					++c1;
				}
				char
					* s = new char [index],
					* result = s;
				c1 = const_cast<char *> (c);
				while (* c1)
				{
					* s = * c1;
					++s;
					++c1;
				}
				* s = char(0);
				return result;
			}
			int main()
			{
				char 
					 c [] {"szereg_pozbawionych_znaczenia_liter"},
					 * s = strdup(c),
					 * s_prev = s;
				while (* s_prev)
					cout 
						<< * (s_prev++);
				cout
					<< endl;			
				return 0;
			}
		}

		namespace e02
		{
			char * findx (const char * s, const char * x)
			{
				char 
					* p1 = const_cast <char *> (s),
					* p2 = const_cast <char *> (x);
				if (p1 == p2)
					return p1;
				while (* p1 && * p2 && * p1 == * p2)
				{
					p1++;
					p2++;
				}
				if (! * p2)
					return const_cast <char *> (s);
				if (! * p1)
					return const_cast <char *> (x);
				p1 = const_cast <char *> (s);
				p1++;
				if (* p1)
					return findx (p1, x);
				return p2;
			}

			int main()
			{
				char
					s1 [] {"abcd"},
					s2 [] {"bc"},
					* m1 = findx(s1, s2);
				while (* m1)
				{
					cout << * m1;
					m1++;
				}
				cout 
					<< endl;

				return 0;
			}
		}

		namespace e03
		{
			int strcmp (const char * s1, const char * s2)
			{
				if (s1 == s2)
					return 0;
				char
					* p1 = const_cast <char *> (s1),
					* p2 = const_cast <char *> (s2);
				while (* p1 && * p2)
				{
					if (* p1 != * p2)
						return int(* p1) - int(* p2);
					p1++;
					p2++;
				}
				if (* p1)
					return 1;
				if (* p2)
					return -1;
				return 0;
			}
			int main()
			{
				char
					s1 [] {"abc"},
					s2 [] {"abcd"};
				cout
					<< strcmp (s1, s2) << endl;
				char 
					s3 [] {"abc"},
					s4 [] {"abb"};
				cout
					<< strcmp (s3, s4) << endl;

				char
					s5 [] {"a_c"},
					s6 [] {"a_c"};
				cout 
					<< strcmp (s5, s6) << endl;
				char
					s7 [] {"_"};
				cout
					<< strcmp (s7, s7) << endl;
				return 0;
			}
		}

		namespace e04
		{
			void havoc_strdup()
			{
				char
					s [] {'a', 'b', 'c'},
					* p = s,
					* p1 = e01::strdup(p),
					* p2 = p1;
				cout
					<< "\ns :\t";
				while (* p)
					cout
						<< * (p++);
				cout
					<< "\np1 :\t";				
				while (* p2)
					cout 
						<< *(p2++);
			}
			void havoc_findx()
			{
				char
					s [] {'a', 'b', 'c', 'd'},
					x [] {'b', 'c'},
					* ps = s,
					* px = x,
					* f = e02::findx (ps, px);
				cout
					<< "\ns :\t";
				while (* ps)
					cout
						<< * (ps++);
				cout
					<< "\nx :\t";
				while (* px)
					cout
						<< * (px++);
				cout
					<< "\nf :\t";
				while (* f)
					cout
						<< * (f++);
			}
			void havoc_strcmp()
			{
				char
					s [] {'a', 'b', 'c', 'd'},
					x [] {'a', 'b', 'c', 'e'},
					* ps = s,
					* px = x;
				cout 
					<< "compare :\t"
					<< e03::strcmp(ps, px);
				cout
					<< "\ns :\t";
				while (* ps)
					cout
						<< * (ps++);
				cout
					<< "\nx :\t";
				while (* px)
					cout
						<< * (px++);
			}
			int main()
			{
				havoc_strdup();
				cout
					<< "\n------------------\n";
				havoc_findx();
				cout
					<< "\n------------------\n";
				havoc_strcmp();
				cout 
					<< endl;
				return 0;
			}
		}

		namespace e05
		{
			string cat_dot (const string & s1, const string & s2)
			{	
				return s1 + "." + s2;
			}

			int main()
			{
				cout
					<< cat_dot ("Niels", "Bohr")
					<< endl;
				return 0;
			}
		}

		namespace e06
		{
			string cat_dot (const string & s1, const string & s2, const string & separator)
			{
				return s1 + separator + s2;
			}

			int main()
			{
				cout
					<< cat_dot ("Niels", "Bohr", ":")
					<< endl;
				return 0;
			}
		}

		namespace e07
		{
			char * cat_dot (const char * s1, const char * s2, const char * separator)
			{
				char
					* s1p = const_cast <char *> (s1),
					* s2p = const_cast <char *> (s2),
					* sep = const_cast <char *> (separator);
				int
					index = 1;
				while (* s1p)
				{
					index++;
					s1p++;
				}
				while (* s2p)
				{
					index++;
					s2p++;
				}
				while (* sep)
				{
					index++;
					sep++;
				}
				s1p = const_cast <char *> (s1);
				s2p = const_cast <char *> (s2);
				sep = const_cast <char *> (separator);

				char 
					* res = new char [index];
					res[index - 1] = char(0);
				int
					i = 0;
				while (* s1p)
					res[i++] = * (s1p++);
				while (* sep)
					res[i++] = * (sep++);
				while (* s2p)
					res[i++] = * (s2p++);

				return res;
			}

			int main()
			{
				char 
					s1 [] {"Niels"},
					s2 [] {"Bohr"},
					separator [] {"-"},
					* c = cat_dot (s1, s2, separator),
					* cp = c;
				cout
					<< endl;
				while (* cp)
					cout
						<< * (cp++);
				cout 
					<< endl;
				cp = nullptr;
				delete [] c;
				c = nullptr;
				return 0;
			}
		}

		namespace e08
		{
			bool is_palindrome_1 (const string & s)
			{
				string
					reversed;
				for (int i = 0; i < s.size(); ++i)
					reversed += s[s.size() - 1 - i];
				for(int i = 0; i < s.size(); ++i)
					if (s[i] != reversed[i])
						return false;
				return true;
			}

			bool is_palindrome_2 (const char s[], int n)
			{
				char
					* reversed = new char[n];
				for (int i = 0; i < n; ++i)
					reversed[n - 1 - i] = s[i];
				for (int i = 0; i < n; ++i)
					if (reversed[i] != s[i])
					{
						delete [] reversed;
						return false;
					}
				delete [] reversed;
				return true;
			}

			bool is_palindrome_3 (const char * first, const char * last)
			{
				int
					len {0};
				while (first[len++] != * last);
				char
					* reversed = new char[len],
					* rev_p = reversed;
				while (len > 0)
					* (rev_p ++) = first[(len--) - 1];
				rev_p = nullptr;
				while (first[len++] != * last)
					if (reversed[len] != first[len])
					{
						delete [] reversed;
						return false;
					}
				delete [] reversed;
				return true;
			}

			int main()
			{
				string
					s1 {"kajak"},
					s2 {"kayax"};
				cout 
					<< "kajak : "
					<< (is_palindrome_1(s1) ? "yep" : "nope")
					<< endl
					<< "kayax : "
					<< (is_palindrome_1(s2) ? "yep" : "nope")
					<< endl;
				char
					c1 [] {"kajak"},
					c2 [] {"kayax"};
				cout
					<< "kajak : "
					<< (is_palindrome_2(c1, 5) ? "yep" : "nope")
					<< endl
					<< "kayax : "
					<< (is_palindrome_2(c2, 5) ? "yep" : "nope")
					<< endl;
				char
					* start1 = & c1[0],
					* end1 = & c1[4],
					* start2 = & c2[0],
					* end2 = & c2[4];
				cout
					<< "kajak : "
					<< (is_palindrome_3(start1, end1) ? "yep" : "nope")
					<< endl
					<< "kayax : "
					<< (is_palindrome_3(start2, end2) ? "yep" : "nope")
					<< endl;
				return 0;
			}
		}

		namespace e09
		{			
			void lambdas ()
			{
				auto f1 = []{};
				auto f2 = []{};
				auto * f1p = & f1;
				auto * f2p = & f2;
				cout 
					<< "lambdas :\n" 
					<< f1p << endl
					<< f2p << endl
					<< "-----------\n";
			}
			auto * f0 = & lambdas;
			//const auto * f_1 = f0;		/// eventually these two got reported as wrong
			//constexpr auto * f_2 = f0;
			constexpr double 
				d1 {0};
			const double
				d2 {0};
			const double
				* d3 = new double {0};
			double
				* d4 = new double {0};
			int main()
			{
				double
					d5 {0},
					d6 {0},
					d7 [3],
					* d10 = new double{0},
					* d11 = new double[4];				
				lambdas();
				cout
					<< "function pointers as globals and consts :\n"
					<< f0 << endl
					//<< f_1 << endl
					//<< f_2 << endl
					<< "-----------\n"
					<< "globals : \n"
					<< & d1 << endl
					<< & d2 << endl
					<< "globals by 'new': \n"
					<< d3 << endl
					<< d4 << endl
					<< "-----------\n"
					<< "locals on stack :\n"
					<< & d5 << endl
					<< & d6 << endl
					<< & d7 << endl
					<< "-----------\n"
					<< "locals on heap :\n"
					<< d10 << endl
					<< d11 << endl;				
				return 0;
			}
		}

		namespace e10
		{
			bool is_palindrome (const char s[], int n)
			{
				int
					first {0},
					last = n - 1;
				while (first < last)
				{
					if (s[first] != s[last])
						return false;
					++first;
					--last;
				}
				return true;				
			}

			istream & read_word (istream & is, char * buffer, int max)
			{
				is.width (max);
				is 
					>> buffer;
				return is;
			}
			void m1 ()
			{
				constexpr int
					max = 128;
				for (char s[max]; read_word(cin, s, max); )
				{
					cout
						<< s 
						<< " is";
					if (! is_palindrome (s, strlen (s)))
						cout
							<< " not";
					cout
						<< " a palindome\n";
				}
			}

			int main()
			{
				return 0;
			}
		}
	}
}