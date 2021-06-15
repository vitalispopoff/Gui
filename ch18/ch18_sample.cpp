#include "ch18.h"

#include <vector>
#include <iostream>


namespace ch18
{
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
			X 
				glob(2);
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
					<< "glob\t" << & glob 
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
				X
					* loc1_p = new X (loc1);
				//cout 
				//	<< "loc1_p?\t" << (loc1_p ? "yep" : "nope");
				delete loc1_p;
				cout 
					<< "loc1 via loc1_p\t" << loc1_p -> val
					<< "\n--------------\n";
			/// loc2
				//X	
				//	loc2 {loc};
				//cout 
				//	<< "loc2\t" << & loc2
				//	<< "\n--------------\n";
			/// loc redeclare
				//loc = X {5};
				//loc.out("loc.out()", loc.val);
				//cout 
				//	<< "loc\t" << & loc 
				//	<< "\n--------------\n";

				//loc2 = copy(loc);
				//loc2 = copy2(loc);
				//X
				//	loc3 {6},
				//	& r = ref_to(loc);
				//delete make(7);
				//delete make(8);
				//vector<X> 
				//	v(4);
				//XX 
				//	loc4;
				//X 
				//	* p = new X {9};
				//delete p;
				//X
				//	* pp = new X[5];
				//delete [] pp;
	
				return notify_on_close();
			}
		}
	}
}