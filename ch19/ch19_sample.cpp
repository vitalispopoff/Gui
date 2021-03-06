#include "ch19.h"
#include <vector>

namespace ch19
{
	namespace sample
	{

		namespace s00
		{
			m_vector::m_vector (m_vector && v) :				//wrn C26439
				sz {v.sz},
				elem {v.elem}
			{
				v.sz = 0;
				v.elem = nullptr;
			}
			m_vector & m_vector::operator = (m_vector && v)		//wrn C26439
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
					v;
				cout
					<< v.size() 
					<< '\n';
				m_vector
					v1 (1);
				v1[0] = 0.618;
				cout
					<< v[0] 
					<< '\n';
				return 0;
			}
		}

		namespace s01
		{
			void main()
			{
				/// concept of a dynamic size functionality and its implementation
				/// for a theorized analog of the m_vector - one that supports
				/// generics

				//n_vector <double> 
				//	* p = new n_vector <double> (10);
				//int
				//	n = 0;
				//for (double d; cin >> d)
				//{
				//	if (n == p 0> size())
				//	{
				//		n_vector <double> 
				//			* q = new n_vector <double> (p -> size() * 2);
				//		copy (p -> begin(), p -> end(), q -> begin());
				//		delete p;
				//		p = q;
				//	}
				//	(* p)[n] = d;
				//	++n;
				//}
			}
		}
		
		namespace s03
		{

			int main()
			{
				m_vector
					v;
				cout 
					<< v.get_size() 
					<< '\n'
					<< v.get_space()
					<< '\n'
					<< v.get_elem()
					<< '\n';
				return 0;	
			}
		}

		namespace s04
		{
			void m_vector::reserve (int new_alloc)
			{
				/// size may only grow 
				if (new_alloc <= space)
					return;

				/// allocating array on the heap - this will hurt
				double
					* p = new double [new_alloc];

				/// copying elem value to the new array
				/// only the 'sz' number of elements is initialized in the new array
				for (int i = 0; i < sz; ++i)
					p[i] = elem [i];

				delete [] elem;
				elem = p;
				space = new_alloc;
			}

			int main()
			{
				m_vector
					v;
				cout 
					<< v.get_size() 
					<< '\n'
					<< v.get_space()
					<< '\n'
					<< v.get_elem()
					<< '\n';
				v.reserve(1);
				cout 
					<< v.get_size() 
					<< '\n'
					<< v.get_space()
					<< '\n'
					<< v.get_elem()
					<< '\n';
				return 0;
			}
		}

		namespace s05
		{
		/// as before:
			void m_vector::reserve (int new_alloc)
			{
				if (new_alloc <= space)
					return;
				double
					* p = new double [new_alloc];
				for (int i = 0; i < sz; ++i)
					p[i] = elem [i];
				delete [] elem;
				elem = p;
				space = new_alloc;
			}
		
		/// new stuff:
			void m_vector::resize (int new_size)
			{
				/// takes care of securing the required space
				reserve (new_size);

				/// forced initalization of a leftovers
				for (int i = sz; i < new_size; ++i)
					elem [i] = 0;
				/// establishing whole array to be publicly recognized as available
				sz = new_size;
			}

			int main()
			{
				m_vector
					v;
				cout 
					<< v.get_size() << '\n'
					<< v.get_space() << '\n'
					<< v.get_elem() << '\n';
				v.resize(1);
				cout 
					<< v.get_size() << '\n'
					<< v.get_space() << '\n'
					<< v.get_elem() << '\n';
				cout
					<< "-----------\n";
				m_vector
					v1;
				//v1.resize(-1);				// unsurprisingly this one doesn't work.
				cout 
					<< v1.get_size() << '\n'
					<< v1.get_space() << '\n'
					<< v1.get_elem() << '\n';
				v1.resize(0);
				cout 
					<< v1.get_size() << '\n'
					<< v1.get_space() << '\n'
					<< v1.get_elem() << '\n';
				return 0;
			}
		}

		namespace s06
		{
		/// as before:
			void m_vector::reserve (int new_alloc)
			{
				if (new_alloc <= space)
					return;
				double
					* p = new double [new_alloc];
				for (int i = 0; i < sz; ++i)
					p[i] = elem [i];
				delete [] elem;		/// what when elem == nullptr
				elem = p;
				space = new_alloc;
			}		
			void m_vector::resize (int new_size)
			{
				reserve (new_size);
				for (int i = sz; i < new_size; ++i)
					elem [i] = 0;
				sz = new_size;
			}
		
		/// new stuff:
			
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
			int main()
			{
				m_vector
					v;
				v.reserve (1);
				v.push_back(-1);
				cout	
					<< v.get_size()
					<< " : "
					<< * v.get_elem()
					<< '\n';
				return 0;
			}
		}

		namespace s07
		{
		/// as before :
			
			void m_vector::reserve (int new_alloc)
			{
				if (new_alloc <= space)
					return;
				double
					* p = new double [new_alloc];
				for (int i = 0; i < sz; ++i)
					p[i] = elem [i];
				delete [] elem;		/// what when elem == nullptr
				elem = p;
				space = new_alloc;
			}		
			void m_vector::resize (int new_size)
			{
				reserve (new_size);
				for (int i = sz; i < new_size; ++i)
					elem [i] = 0;
				sz = new_size;
			}
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

		/// new stuff :
			m_vector & m_vector::operator = (const m_vector & a)
			{
				// allocating exactly as much as is used in the input variable's elem
				double
					* p = new double [a.sz];

				// copying the input variable elem content
				for (int i = 0; i < a.sz; ++i)
					p[i] = a.elem[i];
				
				//update own elem
				delete [] elem;
				elem = p;

				// update other member variables
				space = sz = a.sz;

				return * this;
			}

			int main()
			{
				m_vector
					v1,
					v2;
				v1.push_back (-1);
				v2.push_back (-2);
				cout
					<< * v1.get_elem()
					<< '\n';
				cout
					<< * v2.get_elem()
					<< '\n';
				v2 = v1;
				cout
					<< * v2.get_elem()
					<< '\n';							
				return 0;
			}
		}

		namespace s08
		{
		/// as before :
			
			void m_vector::reserve (int new_alloc)
			{
				if (new_alloc <= space)
					return;
				double
					* p = new double [new_alloc];
				for (int i = 0; i < sz; ++i)
					p[i] = elem [i];
				delete [] elem;		/// what when elem == nullptr
				elem = p;
				space = new_alloc;
			}		
			void m_vector::resize (int new_size)
			{
				reserve (new_size);
				for (int i = sz; i < new_size; ++i)
					elem [i] = 0;
				sz = new_size;
			}
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

		/// new stuff :
			m_vector & m_vector::operator = (const m_vector & a)
			{
				// self-assignment case
				if (this == & a)
					return * this;

				// input's elem fits in own elem - no need for reallocation
				if (a.sz <= space)
				{
					for (int i = 0; i < a.sz; ++i)
						elem [i] = a.elem [i];
					sz = a.sz;
					return * this;
				}
				
				/// old stuff :
				double
					* p = new double [a.sz];
				for (int i = 0; i < a.sz; ++i)
					p[i] = a.elem[i];				
				delete [] elem;
				elem = p;
				space = sz = a.sz;
				return * this;
			}

			int main()
			{
				m_vector
					v1,
					v2;
				v1.push_back (-1);
				v2.push_back (-2);
				cout
					<< * v1.get_elem()
					<< '\n';
				cout
					<< * v2.get_elem()
					<< '\n';
				v2 = v1;
				cout
					<< * v2.get_elem()
					<< '\n';							
				return 0;
			}
		}

		namespace s09
		{
		/// as before :
			
			void m_vector::reserve (int new_alloc)
			{
				if (new_alloc <= space)
					return;
				double
					* p = new double [new_alloc];
				for (int i = 0; i < sz; ++i)
					p[i] = elem [i];
				delete [] elem;
				elem = p;
				space = new_alloc;
			}		
			void m_vector::resize (int new_size)
			{
				reserve (new_size);
				for (int i = sz; i < new_size; ++i)
					elem [i] = 0;
				sz = new_size;
			}
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
			m_vector & m_vector::operator = (const m_vector & a)
			{
				if (this == & a)
					return * this;
				if (a.sz <= space)
				{
					for (int i = 0; i < a.sz; ++i)
						elem [i] = a.elem [i];
					sz = a.sz;
					return * this;
				}
				double
					* p = new double [a.sz];
				for (int i = 0; i < a.sz; ++i)
					p[i] = a.elem[i];				
				delete [] elem;
				elem = p;
				space = sz = a.sz;
				return * this;
			}

		/// new stuff (implementations based on 18.3.4) :
			m_vector::m_vector (const m_vector & v) : 
				sz {v.sz}, elem {new double[v.sz]}, space {v.sz}
			{
				for (int i = 0 ; i < v.size();  ++i)
					elem[i] = v[i];
			}
			m_vector::m_vector (m_vector && v) :
				sz {v.sz}, elem {v.elem}, space {v.space}
			{
				v.sz = v.space = 0;
				v.elem = nullptr;
			}
			m_vector & m_vector::operator = (m_vector && v) 
			{
				// snatch input's elem
				delete [] elem;
				elem = v.elem;

				// update other members
				sz = v.sz;
				space = v.space;

				// clean input
				v.elem = nullptr;
				v.sz = v.space = 0;		

				return * this;
			}
			
			void test_1()
			{
				m_vector
					v1(2),
					v2 = v1;
				cout
					<< v1.get_elem() 
					<< " : "
					<< v1.size()
					<<'\n';
				cout
					<< v2.get_elem()
					<< " : "
					<< v2.size()
					<< '\n';
			}

			void test_2()
			{
				m_vector
					v1(2),
					v2 = v1;
				m_vector
					v3 (v2);
				cout
					<< v1.get_elem() 
					<< " : "
					<< v1.size()
					<<'\n';
				cout
					<< v2.get_elem()
					<< " : "
					<< v2.size()
					<< '\n';
				cout
					<< v3.get_elem()
					<< " : "
					<< v3.size()
					<< '\n';
			}
			void test_3()
			{
				m_vector
					v1(2);
				m_vector
					v3 (v1);
				cout
					<< v1.get_elem() 
					<< " : "
					<< v1.size()
					<<'\n';
				cout
					<< v3.get_elem()
					<< " : "
					<< v3.size()
					<< '\n';
				/// how do you force the move constructor then ?
			}

			void test_0()
			{
				int x = -1,
					* y = & x,
					&& z = int(x);
				//cout
				//	<< y	<< '\n'
				//	<< & x	<< '\n'
				//	<< & z	<< '\n'
				//	<< * (& z)	<< '\n';

				cout
					<< "x    :\t" << typeid(z).name() << "\t" << & z << '\n'
					<< "y (*):\t" << typeid(* y).name() << "\t" << & y << '\n'
					<< "y    :\t" << typeid(y).name() << "\t" << & y << '\n'
					<< "y (&):\t" << typeid(& y).name() << "\t" << & y <<'\n'
					<< "z (&):\t" << typeid(& z).name() << "\t" << & z << '\n';
			}

			int main()
			{
				test_3();

				return 0;
			}
		}

		namespace s10
		{

		/// copy constructor and assigment

			template <typename T>
				m_vector<T>::m_vector (const m_vector & v) : 
					sz {v.sz}, 
					elem {new T [v.sz]}, 
					space {v.sz}
			{
				for (int i = 0 ; i < v.size();  ++i)
					elem[i] = v[i];
			}
			
			template <typename T>
				m_vector<T> & m_vector<T>::operator = (m_vector && v) 
			{
				delete [] elem;
				elem = v.elem;
				sz = v.sz;
				space = v.space;
				v.elem = nullptr;
				v.sz = v.space = 0;		
				return * this;
			}

		/// move constructor and assignment

			template <typename T>
				m_vector<T>::m_vector (m_vector && v) :
					sz {v.sz}, 
					elem {v.elem}, 
					space {v.space}
			{
				v.sz = v.space = 0;
				v.elem = nullptr;
			}

			template <typename T>
				m_vector<T> & m_vector<T>::operator = (const m_vector & a)
			{
				if (this == & a)
					return * this;
				if (a.sz <= space)
				{
					for (int i = 0; i < a.sz; ++i)
						elem [i] = a.elem [i];
					sz = a.sz;
					return * this;
				}
				T
					* p = new T [a.sz];
				for (int i = 0; i < a.sz; ++i)
					p[i] = a.elem[i];				
				delete [] elem;
				elem = p;
				space = sz = a.sz;
				return * this;
			}

		/// content management
		
			template <typename T>
				void m_vector<T>::reserve (int new_alloc)
			{
				if (new_alloc <= space)
					return;
				T
					* p = new T [new_alloc];
				for (int i = 0; i < sz; ++i)
					p[i] = elem [i];
				delete [] elem;
				elem = p;
				space = new_alloc;
			}		
			
			/// the below three will be discussed in s14
			template <typename T>
				void m_vector<T>::resize (int new_size)
			{
				reserve (new_size);
				for (int i = sz; i < new_size; ++i)
					elem [i] = 0;
				sz = new_size;
			}

			template <typename T>
				void m_vector<T>::push_back (const T & d)
			{
				if (space == 0)
					reserve (8);
				else
					if (sz == space)
						reserve (space * 2);
				elem [sz] = d;
				++sz;
			}

			int main()
			{
				m_vector <int>
					m_v;
				m_v.push_back(1);
				cout
					<< m_v.size();
				m_v.resize(2);
				cout
					<< "\n--------\n"
					<< m_v.size();
				return 0;
			}
		}

		namespace s11
		{
			template <typename T, int N> 
				T & m_array<T, N>::operator[] (int n)
			{
				return elem[n];
			}

			template <typename T, int N> 
				const T & m_array<T, N>::operator[] (int n) const
			{
				return elem[n];
			}
			
			int main()
			{

				m_array<int, 3>
					arr;
				cout
					<< arr.size() << '\n';
				arr[0] = 1;
				arr[1] = -1;
				arr [2] = 0;
				for (int i = 0; i < arr.size(); ++i)
					cout
						<< arr[i]
						<< '\n';
				cout
					<< endl;
				
					

				return 0;
			}
		}

		namespace s12
		{
			using s11::m_array;

			m_array <int, 256> 
				gb;
			m_array <double, 6>
				ad = {0., 1.1, 2.2, 3.3, 4.4, 5.5};
			const int
				max = 16; //1024; // a bit too long to list

			template <typename C> void printout (const C & c)
			{
				for (int i = 0; i < c.size(); ++i)
					cout
						<< c[i] << '\n';
			}

			void some_fct (int n)
			{
				m_array<char, max> 
					loc = {'a'};
				printout (loc);
				cout
					<< "\n-------------\n";

				m_array <char, max> 
					loc2 = loc;
				loc[0] = 'b';
				printout (loc);
				cout
					<< "\n-------------\n";
				loc = loc2;
				printout (loc);
				cout
					<< "\n-------------\n";
			}

			int main()
			{
				some_fct(2);
				return 0;
			}
		}

		namespace s13
		{
			using s11::m_array;
			using s12::printout;

			template <class T, int N> 
				void fill (m_array <T, N> & b, const T & val)
			{
				for (int i = 0; i < N; ++i)	// N is by definition a constant at compile time already
					b[i] = val;
			}

			int main()
			{
				m_array <char, 16>
					buf;
				fill (buf, 'x');
				printout (buf);
				cout
					<< "\n--------------\n";
				m_array <double, 8>
					b2;
				// fill <char, 16> (buf, 'x')	// is a proper statement here, and said to be an overkill on a daily basis
				fill (b2, .0);					// this shortcut is usually enough specific
				printout (b2);
				cout
					<< "\n--------------\n";
				return 0;
			}
		}

		namespace s14
		{
			template <typename T, typename A>
				void m_vector<T, A>::resize (int new_size)
			{
				reserve (new_size);
				for (int i = sz; i < new_size; ++i)
					elem [i] = 0;
				sz = new_size;
			}
			template <typename T, typename A>
				void m_vector<T, A>::push_back (const T & d)
			{
				if (space == 0)
					reserve (8);
				else
					if (sz == space)
						reserve (space * 2);
				elem [sz] = d;
				++sz;
			}
			template <typename T, typename A>
				m_vector<T,A> & m_vector<T, A>::operator = (const m_vector & a)
			{
				if (this == & a)
					return * this;
				if (a.sz <= space)
				{
					for (int i = 0; i < a.sz; ++i)
						elem [i] = a.elem [i];
					sz = a.sz;
					return * this;
				}				
				double
					* p = new double [a.sz];
				for (int i = 0; i < a.sz; ++i)
					p[i] = a.elem[i];				
				delete [] elem;
				elem = p;
				space = sz = a.sz;
				return * this;
			}

		///	reimplementing
			template <typename T, typename A>
				void m_vector<T,A>::reserve (int new_alloc)
			{
				if (new_alloc <= space)
					return;
				T * p = alloc.allocate(new_alloc);
				for (int i = 0; i < sz; ++i)
					alloc.construct (&p[i], elem [i]);
				for (int i = 0; i < sz; ++i)
					alloc.destroy (& elem [i]);
				alloc.deallocate (elem, space);
				elem = p;
				space = new_alloc;
			}		

			int main()
			{
				m_vector <int>
					m;
				auto print_out = [&]{
					cout
					<< "capacity\t" << m.capacity() << '\n'
					<< "get_size\t" << m.get_size() << '\n'
					<< "get_space\t" << m.get_space() << '\n';	
				};

				print_out();
				m.reserve(1);
				cout 
					<< "\tafter reserve() \n";
				print_out();
				return 0;
			}
		}

		namespace s15
		{
		/// as before :
			template <typename T, typename A>
				void m_vector<T,A>::reserve (int new_alloc)
			{
				if (new_alloc <= space)
					return;
				T * p = alloc.allocate(new_alloc);
				for (int i = 0; i < sz; ++i)
					alloc.construct (&p[i], elem [i]);
				for (int i = 0; i < sz; ++i)
					alloc.destroy (& elem [i]);
				alloc.deallocate (elem, space);
				elem = p;
				space = new_alloc;
			}
			template <typename T, typename A>
				void m_vector<T, A>::resize (int new_size)
			{
				reserve (new_size);
				for (int i = sz; i < new_size; ++i)
					elem [i] = 0;
				sz = new_size;
			}
			template <typename T, typename A>
				void m_vector<T, A>::push_back (const T & d)
			{
				if (space == 0)
					reserve (8);
				else
					if (sz == space)
						reserve (space * 2);
				elem [sz] = d;
				++sz;
			}
			template <typename T, typename A>
				m_vector<T,A> & m_vector<T, A>::operator = (const m_vector & a)
			{
				if (this == & a)
					return * this;
				if (a.sz <= space)
				{
					for (int i = 0; i < a.sz; ++i)
						elem [i] = a.elem [i];
					sz = a.sz;
					return * this;
				}				
				double
					* p = new double [a.sz];
				for (int i = 0; i < a.sz; ++i)
					p[i] = a.elem[i];				
				delete [] elem;
				elem = p;
				space = sz = a.sz;
				return * this;
			}

		/// new stuff:
			template <typename T, typename A> 
				T & m_vector <T, A> :: operator [] (int n)
			{
				return elem [n];
			}
			template <typename T, typename A>
				T & m_vector <T, A> :: at (int n)
			{
				if (n < 0 || sz <= n)
					throw out_of_range();
				return elem [n];
			}
			
			int main()
			{
				m_vector<int>
					m;
				m.push_back (0);
				m.push_back (1);
				m.push_back (-1);
				cout
					<< m.at (2);

				return 0;
			}
		}

		namespace s16
		{

			int main()
			{
				m_vector <int> m (1);
				cout
					<< m[0];

				return 0;
			}
		}

		namespace s17
		{
			void suspicious (vector <int> & v, int s)
			{
				int 
					* p = nullptr;
				try
				{
					p = new int[s];
				}
				catch (...)
				{

				}
				vector <int>
					v1;

				//...

				int 
					* q = nullptr;
				try
				{
					q = new int [s];
				}
				catch (...)
				{
					if (p != nullptr) 
					{
						delete [] p;
						cout << "p freed";
					}
				}
				vector <double>
					v2;

				//...

				if (p != nullptr) 
				{
					delete [] p;
					cout << "\np freed\n";
				}
				if (q != nullptr) 
				{
					delete [] q;
					cout << "\nq freed\n";
				}
			}

			int main()
			{
				vector<int>
					v (1);
				suspicious (v, 2);

				return 0;
			}
		}

		namespace s18
		{
			const int 
				x = 1000;

			vector <int> * make_vec ()
			{
				vector <int> * 
					v = new vector <int>;
				try
				{
					// whatever code that fills v
					for (int i = 0; i < x; ++i)
						v-> push_back (i);

					return v;
				}
				catch (...)
				{
					delete v;
					v = nullptr; // guess we should do this as well
					throw;
				}
			}

			int main()
			{
				for (int i : * make_vec ())
					cout 
						<< i << ", ";
				return 0;
			}
		}

		namespace s19
		{
			const int 
				x {1000};

			vector <int> * make_vec ()
			{
				unique_ptr <vector <int>> 
					p {new vector <int>};
			
				// part of code that fills p
				try
				{
					for (int i = 0; i < x; ++i)
						p -> push_back (i);
				}
				catch (...)
				{
					// ???
					throw;
				}

				return p.release();			
			}

			unique_ptr <vector <int>> make_vec_1 ()
			{
				unique_ptr <vector <int>> 
					p {new vector <int>};
				//...
				try
				{
					for (int i = 0; i < x; ++i)
						p -> push_back (i);
				}
				catch (...)
				{
					// ???
					throw;
				}
					
				return p;
			}

			vector <int> make_vec_2 ()
			{
				vector <int>
					res;
				//...
				try
				{
					for (int i = 0; i < x; ++i)
						res.push_back(i);
				}
				catch (...)
				{
					// ???
					throw;
				}
				
				return res;
			}
			
			int main ()
			{
				return 0;
			}
		}


	}
}

/// first reading round

//#include "ch19.h"
////#include <vector>
////#include <iostream>
//namespace ch19
//{
//	namespace sample
//	{
//		using namespace std;
//		namespace s01
//		{
//			int main()
//			{
//				vector <double>
//					* p = new vector <double> (10);
//				int
//					n = 0;
//				for (double d; cin >> d; )
//				{
//					if (n == p -> size())
//					{
//						vector <double> 
//							* q = new vector <double> (p -> size() * 2);
//						copy (p -> begin(), p -> end(), q -> begin());
//						delete p;
//						p = q;
//					}
//					(* p) [n] = d;
//					++n;
//				}
//				return 0;
//			}
//		}
//
//		namespace s02
//		{
//			int main()
//			{
//				vector <double>
//					v,
//					v2(1);
//				v.resize(10);
//				v.push_back (.7);
//				v = v2;
//
//				return 0;
//			}
//		}
//
//		namespace s03
//		{
//			void m_vector::reserve (int newalloc)
//			{
//				if (newalloc <= space)
//					return;
//				double
//					* p = new double [newalloc];
//				for (int i = 0; i < sz; ++i)
//					p[i] = elem [i];
//				delete [] elem;
//				elem = p;
//				space = newalloc;
//			}
//		}
//
//		namespace s04
//		{
//			void m_vector::resize(int newsize)
//			{				
//				reserve (newsize);				
//				for (int i = sz; i < newsize; ++i)	
//					elem[i] = 0;
//				sz = newsize;
//			}
//		}
//
//		namespace s05
//		{
//			void m_vector::push_back (double d)
//			{
//				if (space == 0)
//					reserve (8);
//				else
//					if (sz == space)
//						reserve (space * 2);
//				elem [sz] = d;
//				++sz;
//			}
//		}
//
//		namespace s06
//		{
//			m_vector & m_vector::operator = (const m_vector & a)
//			{
//				double 
//					* p = new double[a.sz];
//				for (int i = 0; i < a.sz; ++i)
//					p[i] = a.elem[i];
//				delete [] elem;
//				space = sz = a.sz;
//				elem = p;
//				return * this;
//			}
//		}
//
//		namespace s07
//		{
//			m_vector & m_vector::operator = (const m_vector & a)
//			{
//				if (this == &a)
//					return * this;
//				if (a.sz <= space)
//				{
//					for (int i = 0; i < a.sz; ++i)
//						elem [i] = a.elem[i];
//					sz = a.sz;
//					return * this;
//				}
//				double
//					* p = new double [a.sz];
//				for (int i = 0; i < a.sz; ++i)
//					p[i] = a.elem[i];
//				delete [] elem;
//				space = sz - a.sz;
//				elem = p;
//				return * this;
//			}
//		}
//
//		namespace s08
//		{
//			void m_vector::resize (int new_size){}
//			void m_vector::puch_back (double d){}
//			void m_vector::reserve (int new_alloc){}
//		}
//
//		namespace s09
//		{
//			template <typename T>
//				m_vector<T>::m_vector () :
//				sz {0},
//				elem {nullptr},
//				space {0}
//			{}
//
//			template <typename T>		
//				m_vector<T>::m_vector (int s) :					///'explicit' only in declarations in the class def
//				sz{s},
//				elem {new T [s]},
//				space {s}
//			{
//				for (int i = 0; i < sz; ++i)
//					elem [i] = 0;
//			}
//
//			template <typename T>
//				m_vector<T>::m_vector (const m_vector<T> & v)
//			{}
//
//			template <typename T>
//				m_vector<T> & m_vector<T>::operator = (const m_vector<T> & v)
//			{}
//
//			template <typename T>
//				m_vector<T>::m_vector (m_vector<T> && v)
//			{}
//			template <typename T>
//				m_vector<T> & m_vector<T>::operator = (m_vector<T> && v)
//			{}
//
//			template <typename T>
//				m_vector<T>:: ~ m_vector ()
//			{
//				delete [] elem;
//			}
//			
//			template <typename T>
//				T & m_vector<T>::operator [] (int n)
//			{
//				return elem [n];
//			}
//			
//			template <typename T> 
//				const T & m_vector<T>::operator [] (int n) const
//			{
//				return elem [n];
//			}
//			template <typename T> 
//				int m_vector<T>::size () const
//			{
//				return sz;
//			}
//
//			template <typename T> 
//				int m_vector<T>::capacity () const
//			{
//				return space;
//			}
//
//			template <typename T> 
//				void m_vector<T>::resize (int new_size)
//			{}
//			template <typename T> 
//				void m_vector<T>::push_back (const T & d)
//			{}
//			template <typename T> 
//				void m_vector<T>::reserve (int new_alloc)
//			{}
//
//			int main()
//			{
//				m_vector<char>
//					c (1);
//				cout
//					<< int(c[0]) 
//					<< endl;					
//				c[0] = '@';
//				cout
//					<< c[0] 
//					<< endl;
//				return 0;
//			}
//		}
//
//		namespace s10
//		{
//			int main()
//			{
//				return 0;
//			}
//		}
//
//		namespace s11
//		{}
//
//		namespace s12
//		{
//			using s11::m_array;
//
//			//template <typename C>
//			//	void printout (const C & c)
//			//{
//			//	for (int i = 0; i < c.size(); ++i)				/// c2228
//			//		cout
//			//			<< c[i]
//			//			<< '\n';
//			//}
//
//			int main()
//			{
//				double
//					d [1];
//				vector <double>
//					dv (1);
//				m_array<double, 1>
//					dm;
//
//				//printout (d);
//				//cout
//				//	<< "\n-------------\n";
//				//printout (dv);
//				//cout
//				//	<< "\n-------------\n";
//				//printout (dm);
//				//cout
//				//	<< "\n-------------\n";
//				return 0;
//			}
//		}
//
//		namespace s13
//		{}
//
//		namespace s14
//		{}
//
//		namespace s15
//		{
//			void print_some (m_vector<int> & v)
//			{
//				int
//					i = -1;
//				while (cin >> i && i != -1)
//				try
//				{
//					cout
//						<< "v["
//						<< i
//						<< "]=="
//						<< v.at(i)
//						<<	'\n';
//				}
//				catch (out_of_range)
//				{
//					cout
//						<< "bad index: "
//						<< i 
//						<< "\n";
//				}
//			}		
//		}
//
//		namespace s16
//		{}
//
//		namespace s17
//		{
//			using s16::Vector;
//			void suspcious (int s, int x)
//			{
//				int
//					* p = new int[s];
//				Vector<int> 
//					v1();
//				try
//				{
//					if (x && x < s) // added the end range verifier
//					{
//						//p[x] = v1.at(x);
//						//p[x] = v1;
//					}
//				}
//				catch (...) ///everything
//				{
//					delete[] p;
//					p = nullptr; /// better off with updating pointer, right?
//					throw;		/// it's said to rethrow caught exception
//				}
//
//				///...
//				int * q = new int[s];
//				Vector<double> v2();
//				///...
//				delete[] p;
//				delete[] q;
//			}
//		}
//
//		namespace s18
//		{}
//
//		namespace s19
//		{}
//	}
//}