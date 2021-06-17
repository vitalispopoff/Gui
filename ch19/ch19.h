#pragma once

namespace ch19
{
	namespace sample
	{
		namespace s01
		{
			int main();
		}

		namespace s02
		{
			int main();
		}

		namespace s03
		{
			class m_vector
			{
				int
					sz,
					space;
				double
					* elem;
			public :
				m_vector() :
					sz {0},
					elem {nullptr},
					space {0}		///not very well defined, isn't it?
				{}
				void reserve (int newalloc);
				int capacity() const
				{
					return space;
				}
			};
		}

		namespace s04
		{
			class m_vector
			{
				int
					sz,
					space;
				double
					* elem;
				///...
				void reserve (int newalloc) 
				{
					/// vide s03::m_vector::reserve()
				}
				void resize(int newsize);
			};
		}

		namespace s05
		{
			class m_vector
			{
				int
					sz,
					space;
				double
					* elem;
				///...
				void reserve (int newalloc)
				{
					/// vide s03::m_vector::reserve()
				}
				void resize (int newsize)
				{
					/// vide s04::m_vector::resize()
				}
				void push_back (double d);
			};
		}

		namespace s06
		{
			class m_vector
			{
				int
					sz,
					space;
				double
					* elem;
				///...
				void reserve (int newalloc)
				{
					/// vide s03::m_vector::reserve()
				}
				void resize (int newsize)
				{
					/// vide s04::m_vector::resize()
				}
				void push_back (double d)
				{
					/// vide s05::m_vector::push_back()
				}
				m_vector & operator = (const m_vector & a);

			};
		}

		namespace s07
		{
			class m_vector
			{
				int
					sz,
					space;
				double
					* elem;
				///...
				void reserve (int newalloc)
				{
					/// vide s03::m_vector::reserve()
				}
				void resize (int newsize)
				{
					/// vide s04::m_vector::resize()
				}
				void push_back (double d)
				{
					/// vide s05::m_vector::push_back()
				}
				m_vector & operator = (const m_vector & a);
			};			
		}

		namespace s08
		{
			class m_vector
			{
				int
					sz,
					space;
				double
					* elem;
			public:
				m_vector () :
					sz {0},
					elem {nullptr},
					space {0}
				{}
				explicit m_vector (int s) :
					sz {s},
					elem {new double[s]},
					space {s}
				{
					for (int i = 0; i < sz; ++i)
						elem [i] = 0;
				}
				m_vector (const m_vector &);
				m_vector & operator = (const m_vector &);
				m_vector & operator = (m_vector &&);
				~m_vector() 
				{
					delete [] elem;
				}
				double & operator [] (int n)
				{
					return elem [n];
				}
				const double & operator [] (int n) const
				{
					return elem [n];
				}
				int size () const
				{
					return sz;
				}
				int capacity () const 
				{
					return space;
				}
				void resize (int new_size);
				void puch_back (double d);
				void reserve (int new_alloc);
			};
		}
	}
}