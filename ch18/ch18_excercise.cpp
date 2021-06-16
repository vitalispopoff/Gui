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
	}
}