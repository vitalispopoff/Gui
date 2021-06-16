#include "ch18.h"

#include <vector>
#include <iostream>

namespace ch18
{
	using namespace std;
	int keep_open ()
	{
		int
			in_;
		std::cin 
			>> in_;
		return 0;
	}

	namespace sample
	{
		namespace s02
		{
			//using namespace std;	stated in header already, so unnecessary here, os is it?
			int main()
			{
				auto print = [](vector<int> v)
				{
					for (int i : v)
						cout 
							<< i 
							<< ", ";
					cout 
						<< endl;
				};
				vector<int> 
					v1 {3};	
				print(v1);
				vector<int>
					v2 (3);
				print (v2);
				//return keep_open();
				return 0;
			}
		}

		namespace s03
		{}

		namespace s04
		{
			using namespace std;
			m_vector & m_vector::operator = (const m_vector & a)
			{
				double
					* p = new double[a.sz];
				copy (a.elem, a.elem + a.sz, elem);
				delete [] elem;
				elem = p;
				sz = a.sz;
				return * this;
			}

			void print (m_vector & v)
				{
					for (int i = 0; i < v.size(); ++i)
						cout 
							<< i 
							<< ", ";
					cout 
						<< endl;
				};

			int main()
			{
				m_vector
					v1 (3),
					v2 = v1;
				print(v1);
				print(v2);
				cout 
					<< & v1 
					<< endl
					<< & v2 
					<< endl;
				return 0;
			}
		}

		namespace s05
		{
			m_vector::m_vector (m_vector && v) :
				sz {v.sz},
				elem {v.elem}
			{
				v.sz = 0;
				v.elem = nullptr;
			}

			m_vector & m_vector::operator = (m_vector && v)
			{
			/// clean the current elem
				delete [] elem;
			/// take the elem from v 
				elem = v.elem;
				sz = v.sz;
			/// cut out v from its former elem
				v.elem = nullptr;
				v.sz = 0;
			/// we the elem now
				return * this;
			}
		}

		namespace s06
		{
			int notify_on_close()
			{
				cout 
					<< "closing\n";
				return 0;
			}

			X::X () :
				val {0}
			{
				out("X()", 0);
			}
			X::X (int v) :
				val {v}
			{
				out ("X(int)", v);
			}
			X::X (const X & x) :
				val {x.val}
			{
				out ("X(X &)", x.val);
			}
			void X::out (const string & s, int nv)
			{
				cerr
					<< "\t"
					<< this << " -> "
					<< s	<< ": "
					<< val	<< " ("
					<< nv	<< ")\n";
			}
		///-------------------------			
			//X 
			//	glob(2);
		///-------------------------
			X copy(X a)
			{
				return a;
			}
			X copy2 (X a)
			{
				X 
					aa = a;
				return aa;
			}
			X & ref_to (X & a)
			{
				return a;
			}
			X * make (int i)
			{
				X 
					a(i);
				return new X(a);
			}
			struct XX
			{
				X
					a, b;
			};
		///-------------------------
			int main()
			{
			/// global
				cout 
				//	<< "glob\t" << & glob 
					<< "\n--------------\n";
			/// loc declared w/ '{}'
				X	
					loc {4};
				cout 
					<< "loc\t" << & loc 
					<< "\n--------------\n";
			/// loc1 declared w/ '()'
				X
					loc1 (3);
				cout 
					<< "loc1\t" << & loc1  << endl
					<< "\n--------------\n";
			/// copy loc1 to the heap
				X
					* loc1_p = new X (loc1);
				delete loc1_p;
				cout 
					<< "loc1_p\t" << & loc1_p -> val << " -> " << loc1_p -> val
					<< "\n--------------\n";
			/// loc2
				X	
					loc2 {loc};
				cout 
					<< "loc2\t" << & loc2
					<< "\n--------------\n";
			/// loc redeclare
				loc = X {5};
				cout 
					<< "loc\t" << & loc 
					<< "\n--------------\n";
				loc.out("loc.out()", loc.val);
				cout 
					<< "locout\t"
					<< "--------------\n";

				loc2 = copy(loc);
				cout 
					<< "loc2\t" << & loc2
					<< "\n--------------\n";
				loc2 = copy2(loc);
				cout 
					<< "loc2\t" << & loc2
					<< "\n--------------\n";
				X
					loc3 {6};
				cout 
					<< "loc3\t" << & loc3
					<< "\n--------------\n";
				X
					& r = ref_to(loc);
				cout 
					<< "r\t" << & r
					<< "\n--------------\n";
				delete make(7);
				cout 
					<< "\n--------------\n";
				delete make(8);
				cout 
					<< "\n--------------\n";
				vector<X> 
					v(4);
				cout
					<< "v\t" << & v
					<< "\n--------------\n";
				XX 
					loc4;
				cout
					<< "loc4\t" << & loc4
					<< "\n--------------\n";
				X 
					* p = new X {9};
				cout
					<< "p\t" << & p
					<< "\n--------------\n";
				delete p;
				cout
					<< "p\t" << & p
					<< "\n--------------\n";
				X
					* pp = new X[5];
				cout
					<< "pp\t" << & pp
					<< "\n--------------\n";
				delete [] pp;
				cout
					<< "pp\t" << & pp
					<< "\n--------------\n";
	
				return notify_on_close();
			}
		}

		namespace s07
		{
			m_vector::m_vector (m_vector && v) :
				sz {v.sz},
				elem {v.elem}
			{
				v.sz = 0;
				v.elem = nullptr;
			}
			m_vector & m_vector::operator = (m_vector && v)
			{
				delete [] elem;
				elem = v.elem;
				sz = v.sz;
				v.elem = nullptr;
				v.sz = 0;
				return * this;
			}
			int main()
			{
				m_vector
					v1 (1);
				cout 
					<< "v1\t" << & v1 << endl;
				m_vector
					v2 = v1[2];
				cout 
					<< "v2\t" << & v2 << endl;
				//v1[3] = v2; //expression must be a modifiable lvalue
				return 0;
			}
		}

		namespace s08
		{
			m_vector::m_vector (m_vector && v) :
				sz {v.sz},
				elem {v.elem}
			{
				v.sz = 0;
				v.elem = nullptr;
			}
			m_vector & m_vector::operator = (m_vector && v)
			{
				delete [] elem;
				elem = v.elem;
				sz = v.sz;
				v.elem = nullptr;
				v.sz = 0;
				return * this;
			}

			int main()
			{
				m_vector v(10);
				for (int i = 0; i < v.size(); ++i)
				{
					v[i] = i;
					cout << v[i] << ", ";
				}

				return 0;
			}

			void ff (const m_vector & cv, m_vector & v)
			{
				double 
					d = cv[1];
				//cv[1] = 2.0; // obviously a const
					d = v[1];
				v[1] = 2.0;
			}
		}

		namespace s09
		{
			const int 
				max = 100;
			int 
				gai[max];
			void f (int n)
			{
				char 
					lac[20];
				int 
					lai[60];
				double
					//lad[n],				// expression must have a constant value.
					* bad = new double[n];	// non const length variable works if the array is allocated on heap.
				* lac = 'b';	// as established in ch17 (s06::main) : *lac == lac[0];

								// will check them exclusively in main
				//lac[-2] = 'b';	
				//lac[200]='c';
			}

			int main()
			{
				short
					* c1 = new short[1];
				cout
					<< c1 << endl
					<< & c1[-1] << endl
					<< & c1[200] << endl;

				return 0;
			}
		}

		namespace s10
		{
			void char_array_on_heap()
			{
				char
					* c = new char[3];
				c[2] = char(0);
				c[1] = '1';
				* c = '0';
				cout
					<< * c << endl
					<< c << endl;
			}

			void char_array_on_stack()
			{
				char
					c [3] {'0', '1', char(0)},
					* p = c;
				cout 
					<< * p << endl
					<< p << endl;
			}

			int main()
			{
				//char_arr_on_heap();
				char_array_on_stack();

				return 0;
			}
		}

		namespace s11
		{
			int main()
			{
				double
					ad[10],
					* p = & ad[5];
				* p = 7;
				p[2] = 6;
				p[-3] = 9;
				--p;
				* p = 1;

				for ( double *p = &ad[0]; p < & ad[10]; ++p)
					cout
						<< * p << ", ";
				return 0;
			}
		}

		namespace s12
		{
			int main()
			{
				char
					c[] = {'0', '1'},
					d[] = "2",
					* c1 = c,
					* d1 = d;
				cout 
					<< & c1 << '\t' << c1 << endl
					<< & d1 << '\t' << d1 << endl;
				return 0;
			}
		}

		namespace s13
		{
			vector<int> & f()
			{
				vector<int> 
					x (7);
				return x;
			}
			int main()
			{
				vector<int> 
					& p = f();
				//p[4] = 15;	// expression vector subscript out of range
				return 0;
			}
		}

		namespace s14
		{
			bool is_palindrome (const string & s)
			{
				int
					first = 0,
					last = s.length() - 1;
				while (first < last)
				{
					if (s[first] != s[last])
						return false;
					++first;
					--last;
				}
					return true;
			}

			int main()
			{
				string 
					s;
				for (; cin >> s && s != "exit"; )
				{
					cout
						<< s 
						<< " is";
					if (!is_palindrome (s))
						cout 
							<< "not";
					cout
						<< " a palindrome\n";
				}
				if (s == "exit")
					cout
						<< "exit is not a palindrome\n";
				return 0;
			}
		}

		namespace s15
		{
			bool is_palindrome (const char s[], int n)
			{
				int
					first = 0,
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

			int main()
			{
				constexpr int
					max = 128;
				cout 
					<< "Empty slots are populated with char(" << int (cout.fill()) << ").\n";

				for (char s[max]; read_word (cin, s, max); )
				{
					cout
						<< s << " is";
					if (!is_palindrome (s, strlen(s)))
						cout
							<< " not";
					cout 
						<< " a palindrome\n";

					return 0;
				}
			}
		}

		namespace s16
		{
			bool is_palindrome (const char * first, char * last)
			{
				while (first < last)
				{
					if (* first != * last)
						return false;
					++first;
					--last;
				}
				return true;
			}

			int main()
			{
				const int
					max = 128;
				for (char s[max]; s15::read_word (cin, s, max); )
				{
					cout
						<< s
						<< " is";
					if (!is_palindrome (& s[0], & s[strlen (s) - 1]))
						cout << " not";
					cout << " a palindrome\n";
				}
				return 0;
			}
		}

		namespace s17
		{
			// ...aaaaaand a recursive one as well...
			bool is_palindrome (const char * first, const char * last)
			{
				if (first < last)
				{
					if (* first != * last)
						return false;
					return is_palindrome (first + 1, last - 1);
				}
				return true;
			}

			int main()
			{
				const int
					max = 128;
				for (char s[max]; s15::read_word (cin, s, max); )
				{
					cout
						<< s
						<< " is";
					if (!is_palindrome (& s[0], & s[strlen (s) - 1]))
						cout << " not";
					cout << " a palindrome\n";
				}
				return 0;
			}
		}
	}
}