#pragma once

#include <initializer_list>		
#include <algorithm>			/// for the copy 
#include <string>				/// for the s06

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
	}
}