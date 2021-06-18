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

		/// 'parametric polymorphism', 'algorithm-oriented programming'
		/// types involved in code operations are determined at compile time,
		/// conversely OOP (class hierarchy + inheritance / virtual functions) is determined at run time
		namespace s09
		{
			template <typename T> 
				class m_vector
			{
				int
					sz,
					space;
				T * elem;
			public : 
				m_vector ();

				/// "The explicit specifier may only appear within the decl-specifier-seq 
				///	of the declaration of a constructor or conversion function (since C++11) 
				///	within its class definition."
				/// https://en.cppreference.com/w/cpp/language/explicit
				explicit m_vector (int s); 

				m_vector (const m_vector &);
				m_vector & operator = (const m_vector &);

				m_vector (m_vector &&);
				m_vector & operator = (m_vector &&);

				~ m_vector ();

				T & operator [] (int n);
				const T & operator [] (int n) const;

				int size () const;
				int capacity () const;

				void reserve (int new_alloc);
				void resize (int new_size);
				void push_back (const T & d);
			};

			int main();
		}

		/// as adviced : definitions of a template is included in a declaration:
		namespace s10
		{
			template <typename T>
				class m_vector
			{
				int 
					sz,
					space;
				T * elem;
			public:
				m_vector () : sz {0}, elem {nullptr}, space {0} {}
				m_vector (int s) :
					sz {s}, elem {new T [s]}, space {s}
				{
					for (int i = 0; i < sz; ++i)
						elem [i] = 0;
				}
																/// based on ch18::s04 '=' operator
				m_vector (const m_vector <T> & v) :
					sz {v.sz},
					elem {new T[v.sze]},
					space {v.sz}
				{
					copy (v.elem, v.elem + v.sz, elem);
				}
				m_vector<T> & operator = (const m_vector<T> & v)
				{
					T * p = new T [v.sz];
					copy (v.elem, v.elem + v.sz, elem); //shouldn't it be rather 'p' than 'elem ?
					delete [] elem;
					elem = p;
					sz = v.sz;
					return * this;
				}
																/// based on ch18::s05 copy constructor
				m_vector<T> (m_vector<T> && v) :
					sz {v.sz},
					elem {v.elem},
					space {v.space}
				{
					v.sz = 0;
					v.elem = nullptr;
				}
				m_vector<T> & operator = (m_vector && v);

				~ m_vector ()
				{
					delete [] elem;
				}
				T & operator [] (int n) const
				{
					return elem[n];
				}
				const T & operator [] (int n) const;

				int size () const
				{
					return sz;
				}
				int capacity () const
				{
					return space;
				}

				void reserve (int new_alloc)
				{
					if (new_alloc <= space)
						return;
					T * p = new T [new_alloc);
					for (int i = 0; i < sz; ++i)
						p[i] = elem [i]
					delete [] elem;
					elem = p;
					space = new_alloc;					
				}
				void resize (int new_size)
				{
					reserve (new_size);
					for (int i = sz; i < new_size; ++i)
						elem [i] = 0;
					sz = new_size;
				}
				void push_back (const T & d)
				{
					if (space ==0)
						reserve (8);
					else
						if (sz == space)
							reserve (space * 2);
					elem [sz] = d;
					++sz;
				}
			};

			int main();
		}
	}
}