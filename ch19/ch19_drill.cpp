#include "ch19.h"

#include <iostream>
#include <vector>

namespace ch19
{
	namespace drill
	{
		using namespace std;

		namespace d03
		{			
			int main()
			{
				S <int>
					s_i {-1};
				S <char>
					s_c {'@'};
				S <double>
					s_d {.01};
				S <string>
					s_s {"letters"};
				S <vector <int>>
					s_v {{0, 1}};
				
				cout
					<< "s_i : \t" << s_i.val <<'\n'
					<< "s_c : \t" << s_c.val <<'\n'
					<< "s_d : \t" << s_d.val <<'\n'
					<< "s_s : \t" << s_s.val <<'\n'
					<< "s_v : \t";
				for (int i : s_v.val)
					cout
						<< i << ", ";
				cout
					<< '\n';
				return 0;
			}
		}

		namespace d05
		{
			int main ()
			{
				S <int> 
					s {1};
				cout
					<< s.val << '\n'
					<< s.get() << '\n';
				return 0;
			}
		}

		namespace d06
		{
			template <typename T> 
				T & S<T>::get()
			{
				return val;
			}

			int main ()
			{
				S <int>
					s {-1};
				cout
					<< s.get() << '\n';				
				return 0;
			}
		}

		namespace d08
		{
			template <typename T>
				T & S<T>::get()
			{
				return val;
			}

			int main ()
			{
				S <int>
					s_i {-1};
				S <char>
					s_c {'@'};
				S <double>
					s_d {.01};
				S <string>
					s_s {"letters"};
				S <vector <int>>
					s_v {{0, 1}};
				cout
					<< "s_i : \t" << s_i.get() << '\n'
					<< "s_c : \t" << s_c.get() << '\n'
					<< "s_d : \t" << s_d.get() << '\n'
					<< "s_s : \t" << s_s.get() << '\n'
					<< "s_v : \t";
				for (int i : s_v.get())
					cout 
						<< i << ", ";
				cout 
					<< '\n';




				return 0;
			}
		}

		namespace d09
		{
			template <typename T>
				T & S<T>::get()
			{
				return val;
			}

			template <typename T>
				void S<T>::set (T t)
			{
				val = t;
			}

			int main()
			{
				S <int>
					s {-1};
				s.set (1);
				cout
					<< s.get() << '\n';
				return 0;
			}
		}

		namespace d10
		{
			template <typename T> 
				T & S <T>::get() {return val;}
			template <typename T> 
				S <T> & S <T>::operator = (const T & t)
			{
				val = t;
				return * this;
			}

			int main ()
			{
				S <int>
					s {1};
				s = S <int> (2);
				cout
					<< s.get() << '\n';
				return 0;
			}
		}

		namespace d11
		{
			template <typename T> 
				T & S <T>::get () { return val;}
			template <typename T>
				S <T> & S <T>::operator = (const T & t)
			{
				val = t;
				return * this;
			}
			template <typename T>
				const S <T> & S <T>::operator = (const T & t) const
			{
				val = t;
				return * this;
			}

			int main()
			{
				S <int>
					s {1},
					t {-1};
				s = t;

				cout 
					<< s.get() << '\n';

				return 0;
			}


		}

		namespace d12
		{
			template <typename T>
				T & S <T>::get () {return val;}
			template <typename T>
				S <T> & S <T>::operator = (const T & t)
			{
				val = t;
				return * this;
			}
			template <typename T>
				const S <T> & S <T>::operator = (const T & t) const
			{
				val = t;
				return * this;
			}
			template <typename T>
				T & read_val (T & v)
			{
				cin 
					>> v;
				return v;
			}

			int main ()
			{
				int
					i;
				S <int>
					s = read_val(i);
				
				cout
					<< s.get() << '\n';

				return 0;
			}
		}

		namespace d13
		{
			template <typename T>
				T & S <T>::get () {return val;}
			template <typename T>
				S <T> & S <T>::operator = (const T & t)
			{
				val = t;
				return * this;
			}
			template <typename T>
				const S <T> & S <T>::operator = (const T & t) const
			{
				val = t;
				return * this;
			}
			template <typename T>
				T & read_val (T & v)
			{
				cin 
					>> v;
				return v;
			}

			int main()
			{
				int
					i;
				S <int>
					s_i = read_val (i);
				char
					c;
				S <char>
					s_c = read_val (c);
				double
					d;
				S <double>
					s_d = read_val (d);
				string
					s;
				S <string>
					s_s = read_val (s);

				cout
					<< "s_i :\t" <<	s_i.get() << '\n'
					<< "s_c :\t" <<	s_c.get() << '\n'
					<< "s_d :\t" <<	s_d.get() << '\n'
					<< "s_s :\t" <<	s_s.get() << '\n';
				return 0;
			}
		}

		namespace d14
		{
			template <typename T>
				T & S <T>::get () {return val;}
			template <typename T>
				S <T> & S <T>::operator = (const T & t)
			{
				val = t;
				return * this;
			}
			template <typename T>
				const S <T> & S <T>::operator = (const T & t) const
			{
				val = t;
				return * this;
			}

			template <typename T>
				T & read_val (T & v)
			{
				cin 
					>> v;
				return v;
			}

			template <typename T>
				istream & operator >> (istream & is, vector <T> & v)
			{
				T v1;
				cin 
					>> v1;				
				v.push_back (v1);
				return is;
			}
			template <typename T>
				ostream & operator << (ostream & os, vector <T> & v)
			{
				for (T t : v)
					os << t;
				return os;
			}

			int main()
			{
				vector <int>
					v;
				S <vector <int>>
					s_v = read_val(v);
				cout 
					<< s_v.get();
				return 0;
			}

		}

	}
}


/// first reading round

//#include "ch19.h"
//
//#include <iostream>
//
//namespace ch19
//{
//	namespace drill
//	{
//		using namespace std;
//		namespace d01
//		{
//			int main ()
//			{
//				S<int>
//					s;
//				return 0;
//			}
//		}
//
//		namespace d02
//		{
//			int main()
//			{
//				S<int>
//					t;
//				cout
//					<< t.val;
//				return 0;
//			}
//		}
//
//		namespace d03
//		{
//			int main()
//			{
//				S <int>
//					ti (-1);
//				S <char>
//					tc ('@');
//				S <double>
//					td (3.14);
//				S <string>
//					ts ("nope");
//				S <vector<int>>
//					tv;
//				cout
//					<< ti.val << '\n'
//					<< tc.val << '\n'
//					<< td.val << '\n'
//					<< ts.val << '\n'
//					<< '\n';
//				return 0;
//			}
//		}
//
//		namespace d05
//		{
//			int main()
//			{
//				S<char>
//					tc ('@');
//				cout
//					<< tc.get() << '\n';
//				return 0;
//			}
//		}
//
//		namespace d06
//		{
//			template <typename T> T S<T>::get ()
//			{
//				return val;
//			}
//			int main()
//			{
//				S <char>
//					tc ('@');
//				cout
//					<< tc.get() << '\n';
//				return 0;
//			}
//		}
//
//		namespace d07
//		{
//			template <typename T> T S<T>::get()
//			{
//				return val;
//			}
//			int main()
//			{
//				S <char>
//					tc ('@');
//				cout 
//					<< tc.get() << '\n';
//				return 0;
//			}
//		}
//
//		namespace d08
//		{
//			int main()
//			{
//				S <int>
//					ti (-1);
//				S <char>
//					tc ('@');
//				S <double>
//					td (3.14);
//				S <string>
//					ts ("nope");
//				S <vector<int>>
//					tv;
//				cout
//					<< ti.get() <<'\n'
//					<< tc.get() <<'\n'
//					<< td.get() <<'\n'
//					<< ts.get() <<'\n';					
//				return 0;
//			}
//		}
//
//		namespace d09
//		{
//			template <typename T> T S<T>::get()
//			{
//				return val;
//			}
//			template <typename T> void S<T>::set(T v)
//			{
//				val = v;
//			}
//			int main()
//			{
//				S <char>
//					tc {'@'};
//				tc.set('%');
//				cout
//					<< tc.get() << '\n';
//				return 0;
//			}
//		}
//
//		namespace d10
//		{
//			template <typename T> T S<T>::get()
//			{
//				return val;
//			}
//			template <typename T> S<T> & S<T>::operator = (const T & t)
//			{
//				if (this != & t)
//					val = t.get();
//				return * this;
//			}
//			int main()
//			{
//				S<char>
//					tc1 {'@'},
//					tc2 {'%'};
//				tc1 = tc2;
//				cout 
//					<< tc1.get() << '\n';
//				return 0;
//			}
//		}
//
//		namespace d11
//		{
//			template <typename T> T S<T>::get()
//			{
//				return val;
//			}
//			template <typename T> const T & S<T>::get() const
//			{
//				return val;
//			}
//			template <typename T> S<T> & S<T>::operator = (const T & t)
//			{
//				//if (val != * t)
//					val = t;
//				return * this;
//			}
//			int main()
//			{
//				S <char>
//					tc {'@'};
//				cout
//					<< tc.get() << '\n';					
//				return 0;
//			}
//		}
//
//		namespace d12
//		{
//			template <typename T> void read_val (T & v)
//			{
//				cin 
//					>> v;
//			}
//			int main()
//			{
//				string
//					s;
//				read_val(s);
//				cout
//					<< s <<'\n';
//				return 0;
//			}
//		}
//
//		namespace d13
//		{
//			int main()
//			{
//				S <int>
//					ti;
//				int
//					i = ti.get();
//				read_val(i);
//				ti = i;
//				cout
//					<< ti.get() << '\n';
//				S <double>
//					td;
//				double 
//					d = td.get();
//				read_val(d);
//				cout
//					<< td.get() << '\n';
//				S <char>
//					tc;
//				char
//					c = tc.get();
//				read_val (c);
//				tc = c;
//				cout
//					<< tc.get() << '\n';
//				S <string>
//					ts;
//				string
//					s = ts.get();
//				read_val (s);
//				ts = s;
//				cout
//					<< ts.get() << '\n';				
//				return 0;
//			}
//
//		}
//	}
//}
