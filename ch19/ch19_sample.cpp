#include "ch19.h"
#include <vector>
#include <iostream>
namespace ch19
{
	namespace sample
	{
		using namespace std;
		namespace s01
		{
			int main()
			{
				vector <double>
					* p = new vector <double> (10);
				int
					n = 0;
				for (double d; cin >> d; )
				{
					if (n == p -> size())
					{
						vector <double> 
							* q = new vector <double> (p -> size() * 2);
						copy (p -> begin(), p -> end(), q -> begin());
						delete p;
						p = q;
					}
					(* p) [n] = d;
					++n;
				}
				return 0;
			}
		}

		namespace s02
		{
			int main()
			{
				vector <double>
					v,
					v2(1);
				v.resize(10);
				v.push_back (.7);
				v = v2;

				return 0;
			}
		}

		namespace s03
		{
			void m_vector::reserve (int newalloc)
			{
				if (newalloc <= space)
					return;
				double
					* p = new double [newalloc];
				for (int i = 0; i < sz; ++i)
					p[i] = elem [i];
				delete [] elem;
				elem = p;
				space = newalloc;
			}
		}

		namespace s04
		{
			void m_vector::resize(int newsize)
			{				
				reserve (newsize);				
				for (int i = sz; i < newsize; ++i)	
					elem[i] = 0;
				sz = newsize;
			}
		}

		namespace s05
		{
			void m_vector::push_back (double d)
			{
				if (space == 0)
					reserve (8);
				else
					if (sz == space)
						reserve (space * 2);
				elem [sz] = d;
				++sz;
			}
		}

		namespace s06
		{
			m_vector & m_vector::operator = (const m_vector & a)
			{
				double 
					* p = new double[a.sz];
				for (int i = 0; i < a.sz; ++i)
					p[i] = a.elem[i];
				delete [] elem;
				space = sz = a.sz;
				elem = p;
				return * this;
			}
		}

		namespace s07
		{
			m_vector & m_vector::operator = (const m_vector & a)
			{
				if (this == &a)
					return * this;
				if (a.sz <= space)
				{
					for (int i = 0; i < a.sz; ++i)
						elem [i] = a.elem[i];
					sz = a.sz;
					return * this;
				}
				double
					* p = new double [a.sz];
				for (int i = 0; i < a.sz; ++i)
					p[i] = a.elem[i];
				delete [] elem;
				space = sz - a.sz;
				elem = p;
				return * this;
			}
		}

		namespace s08
		{
			void m_vector::resize (int new_size){}
			void m_vector::puch_back (double d){}
			void m_vector::reserve (int new_alloc){}
		}

		namespace s09
		{
			template <typename T>
				m_vector<T>::m_vector () :
				sz {0},
				elem {nullptr},
				space {0}
			{}

			template <typename T>		
				m_vector<T>::m_vector (int s) :					///'explicit' only in declarations in the class def
				sz{s},
				elem {new T [s]},
				space {s}
			{
				for (int i = 0; i < sz; ++i)
					elem [i] = 0;
			}

			template <typename T>
				m_vector<T>::m_vector (const m_vector<T> & v)
			{}

			template <typename T>
				m_vector<T> & m_vector<T>::operator = (const m_vector<T> & v)
			{}

			template <typename T>
				m_vector<T>::m_vector (m_vector<T> && v)
			{}
			template <typename T>
				m_vector<T> & m_vector<T>::operator = (m_vector<T> && v)
			{}

			template <typename T>
				m_vector<T>:: ~ m_vector ()
			{
				delete [] elem;
			}
			
			template <typename T>
				T & m_vector<T>::operator [] (int n)
			{
				return elem [n];
			}
			
			template <typename T> 
				const T & m_vector<T>::operator [] (int n) const
			{
				return elem [n];
			}
			template <typename T> 
				int m_vector<T>::size () const
			{
				return sz;
			}

			template <typename T> 
				int m_vector<T>::capacity () const
			{
				return space;
			}

			template <typename T> 
				void m_vector<T>::resize (int new_size)
			{}
			template <typename T> 
				void m_vector<T>::push_back (const T & d)
			{}
			template <typename T> 
				void m_vector<T>::reserve (int new_alloc)
			{}

		}
	}
}