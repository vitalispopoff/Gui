#include "ch19.h"

#include <iostream>

namespace ch19
{
	namespace drill
	{
		using namespace std;
		namespace d01
		{
			int main ()
			{
				S<int>
					s;
				return 0;
			}
		}

		namespace d02
		{
			int main()
			{
				S<int>
					t;
				cout
					<< t.val;
				return 0;
			}
		}

		namespace d03
		{
			int main()
			{
				S <int>
					ti (-1);
				S <char>
					tc ('@');
				S <double>
					td (3.14);
				S <string>
					ts ("nope");
				S <vector<int>>
					tv;
				cout
					<< ti.val << '\n'
					<< tc.val << '\n'
					<< td.val << '\n'
					<< ts.val << '\n'
					<< '\n';
				return 0;
			}
		}

		namespace d05
		{
			int main()
			{
				S<char>
					tc ('@');
				cout
					<< tc.get() << '\n';
				return 0;
			}
		}

		namespace d06
		{
			template <typename T> T S<T>::get ()
			{
				return val;
			}
			int main()
			{
				S <char>
					tc ('@');
				cout
					<< tc.get() << '\n';
				return 0;
			}
		}

		namespace d07
		{
			template <typename T> T S<T>::get()
			{
				return val;
			}
			int main()
			{
				S <char>
					tc ('@');
				cout 
					<< tc.get() << '\n';
				return 0;
			}
		}

		namespace d08
		{
			int main()
			{
				S <int>
					ti (-1);
				S <char>
					tc ('@');
				S <double>
					td (3.14);
				S <string>
					ts ("nope");
				S <vector<int>>
					tv;
				cout
					<< ti.get() <<'\n'
					<< tc.get() <<'\n'
					<< td.get() <<'\n'
					<< ts.get() <<'\n';					
				return 0;
			}
		}

		namespace d09
		{
			template <typename T> T S<T>::get()
			{
				return val;
			}
			template <typename T> void S<T>::set(T v)
			{
				val = v;
			}
			int main()
			{
				S <char>
					tc {'@'};
				tc.set('%');
				cout
					<< tc.get() << '\n';
				return 0;
			}
		}

		namespace d10
		{
			template <typename T> T S<T>::get()
			{
				return val;
			}
			template <typename T> S<T> & S<T>::operator = (const T & t)
			{
				if (this != & t)
					val = t.get();
				return * this;
			}
			int main()
			{
				S<char>
					tc1 {'@'},
					tc2 {'%'};
				tc1 = tc2;
				cout 
					<< tc1.get() << '\n';
				return 0;
			}
		}

		namespace d11
		{
			template <typename T> T S<T>::get()
			{
				return val;
			}
			template <typename T> const T & S<T>::get() const
			{
				return val;
			}
			template <typename T> S<T> & S<T>::operator = (const T & t)
			{
				//if (val != * t)
					val = t;
				return * this;
			}
			int main()
			{
				S <char>
					tc {'@'};
				cout
					<< tc.get() << '\n';					
				return 0;
			}
		}

		namespace d12
		{
			template <typename T> void read_val (T & v)
			{
				cin 
					>> v;
			}
			int main()
			{
				string
					s;
				read_val(s);
				cout
					<< s <<'\n';
				return 0;
			}
		}

		namespace d13
		{
			int main()
			{
				S <int>
					ti;
				int
					i = ti.get();
				read_val(i);
				ti = i;
				cout
					<< ti.get() << '\n';
				S <double>
					td;
				double 
					d = td.get();
				read_val(d);
				cout
					<< td.get() << '\n';
				S <char>
					tc;
				char
					c = tc.get();
				read_val (c);
				tc = c;
				cout
					<< tc.get() << '\n';
				S <string>
					ts;
				string
					s = ts.get();
				read_val (s);
				ts = s;
				cout
					<< ts.get() << '\n';				
				return 0;
			}

		}
	}
}