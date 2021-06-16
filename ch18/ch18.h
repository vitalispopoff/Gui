#pragma once

#include <initializer_list>		
#include <algorithm>			/// for the copy 
#include <string>				/// for the s06
#include <vector>				/// for the d05

namespace ch18
{
	namespace sample
	{
		namespace s01
		{
			class m_vector
			{
				int 
					sz;
				double 
					* elem;
			public :
				m_vector (int s) :
					sz {s},
					elem {new double[s]}
				{/* ... */}
				~ m_vector()
				{
					delete[] elem;
				}
			};
		}

		namespace s02
		{
			using namespace std;

			class m_vector
			{
				int
					sz;
				double
					* elem;
			public :
				m_vector (int s) :
					sz {s},
					elem {new double [sz]}
				{
					for (int i = 0; i < sz; ++i)
						elem[i] = 0.;
				}

				m_vector (initializer_list<double> lst) :
					sz {int(lst.size())},
					elem {new double[int(sz)]}
				{
					copy (lst.begin(), lst.end(), elem);
				}			
			};

			int main();
		}

		namespace s03
		{
			using namespace std;
			class m_vector
			{
				int
					sz;
				double
					* elem;
			public :
				m_vector (int s) :
					sz {s},
					elem {new double[s]}
				{/* ... */}

				m_vector (const m_vector & arg) :
					sz {arg.sz},
					elem {new double[arg.sz]}
				{
					//copy (arg, arg + sz, elem)
				}

				~ m_vector()
					{
						delete[] elem;
					}
			};
		}

		namespace s04
		{
			class m_vector
			{
				int
					sz;
				double 
					* elem;
			public :
				m_vector (int s) :
					sz {s},
					elem {new double[s]}
				{}

				m_vector & operator = (const m_vector &);

				int size()
				{
					return sz;
				}
			};

			int main();
		}

		namespace s05
		{
			class m_vector
			{
				int
					sz;
				double
					* elem;
			public :
				m_vector (m_vector &&);
				m_vector & operator = (m_vector && v);
			};
		}

		namespace s06
		{
			using namespace std;
			struct X
			{
				int
					val;
				X ();
				X (int v);
				X (const X & x);
				void out (const string &, int);
				X & operator = (const X & a)
				{
					out ("X::operator = ()", a.val);
					val = a.val;
					return * this;
				}
				~X ()
				{
					out ("~X()", 0);
				}
			};
			int main();
		}

		namespace s07
		{
			class m_vector
			{
				int
					sz;
				double
					* elem;
			public :
				m_vector (int s = 0) :
					sz {s},
					elem {new double[s]}
				{}
				m_vector (m_vector &&);
				m_vector & operator = (m_vector && v);
				double operator [] (int n)
				{
					return elem[n];
				}
			};

			int main();
		}

		namespace s08
		{
			class m_vector
			{
				int
					sz;
				double
					* elem;
			public :
				m_vector (int s = 0) :
					sz {s},
					elem {new double[s]}
				{}
				m_vector (m_vector &&);
				m_vector & operator = (m_vector && v);
				int size()
				{
					return sz;
				}
				double & operator [] (int n)
				{
					return elem[n];
				}
				double operator [] (int n) const
				{
					return elem[n];
				}
			};
			int main();
		}

		namespace s09
		{
			int main();
		}

		namespace s10
		{
		/// char[] 
			int main();
		}

		namespace s11
		{
			int main();
		}

		namespace s12
		{
			int main();
		}

		namespace s13
		{
			int main();	
		}

		namespace s14
		{
			int main();
		}

		namespace s15
		{
			int main();
		}

		namespace s16
		{
			int main();
		}

		namespace s17
		{
			int main();
		}
	}

	namespace drill
	{
		using namespace std;

		namespace d01
		{
			int main();
		}

		namespace d02
		{
			void f (int arr [], int len);
			int main();
		}

		namespace d05
		{
			void f (vector<int>);
			int main();
		}
	}
}