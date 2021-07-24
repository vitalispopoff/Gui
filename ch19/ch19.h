#pragma once

#include <iostream>
#include <vector>
#include <typeinfo> // for the e06 just in case

namespace ch19
{
	using namespace std;

	namespace sample
	{
		/// copied from ch18
		/// m_vector
		namespace s00
		{
			class m_vector
			{
				int 
					sz;
				double 
					* elem;
			public :
			/// implicit constructor
				m_vector (int s = 0) :
					sz {s},
					elem {new double [s]}
				{}
			/// copy constructor
				m_vector (m_vector &&);					//wrn C26439
			/// assignment operator 
				m_vector & operator = (m_vector && v);		//wrn C26439
			/// vector size getter
				int size ()
				{
					return sz;
				}
			/// " access vector elements using the conventional subscript notation
			/// (on both the right-hand side and left-hand side of an assignment)"
			///  ???
				double & operator [] (int n)
				{
					return elem [n];
				}
				double operator [] (int n) const
				{
					return elem [n];
				}
			};

			int main();
		}

		namespace s01
		{}

		/// 19.2 - vector resizing
		namespace s02
		{
			/// some of the resizing functionalities of vector

			// vector<double> v(n); // size assignment at construction

			// v.resize (10);		// explicit resizing function

			// v.push_back (7)		// explicitly adding an element at the end of the vector

			// v = v2;				// assigning another vector, by copy (depending on a assignment operator implementation)
		}

		/// 19.2.1 - optimizing resize 
		namespace s03
		{
			class m_vector
			{
				int
					sz,			// inner array space currently used
					space;		// inner array actual length
				double 
					* elem;		// inner array pointer.
			public :
				/// default constructor defines an empty vector w/ the inner array not even initialized
				m_vector () :
					sz {0},
					elem {nullptr},
					space {0}
				{}
				/// the getters are added for testing purpose only.
				int get_size() const
				{
					return sz;
				}
				int get_space() const
				{
					return space;
				}
				double * get_elem() const
				{
					return elem;
				}
			};
			int main();
		}

		/// 19.2.2 reserve and capacity
		/// m_vector::reserve
		namespace s04
		{
			class m_vector
			{
			/// as before:
				int sz, space;
				double * elem;
			public :
				m_vector () : sz {0}, elem {nullptr}, space {0} {}

			/// new stuff:
				int capacity () const {return space;}

				/// takes care of organizing additional free space in the inner array
				void reserve (int new_alloc);

			/// getters for testing only:
				int get_size() const {return sz;}
				int get_space() const {return space;}
				double * get_elem() const{return elem;}
			};
			int main();
		}

		/// m_vector::resize
		namespace s05
		{
			class m_vector
			{
			/// as before:
				int sz, space;
				double * elem;
			public :
				m_vector () : sz {0}, elem {nullptr}, space {0} {}
				int capacity() const {return space;}
				void reserve (int new_alloc); 

			/// new stuff: 
				/// explicit size management interface
				void resize (int new_size);

			/// for testing only:
				int get_size() const {return sz;}
				int get_space() const {return space;}
				double * get_elem() const {return elem;}
			};
			int main();
		}

		/// 19.2.4
		/// m_vector::push_back
		namespace s06
		{
			class m_vector
			{
			/// as before:
				int sz, space;
				double * elem;
			public :
				m_vector () : sz{0}, elem {nullptr}, space {0} {}
				int capacity() const {return space;}
				void reserve (int new_alloc);
				void resize (int new_size);

			/// new stuff:
				void push_back (double d);

			/// for testing only:
				int get_size() const {return sz;}
				int get_space() const {return space;}
				double * get_elem() const {return elem;}
			};
			int main();
		}

		/// 19.2.5 assignemt operator
		/// m_vector::operator =
		namespace s07
		{
			class m_vector
			{
			/// as before:
				int sz, space;
				double * elem;
			public :
				m_vector () : sz {0}, elem {nullptr}, space {0} {}
				int capacity() const {return space;}
				void reserve (int new_alloc);
				void resize (int new_size);
				void push_back (double d);

			/// new stuff :
				m_vector & operator = (const m_vector & a);

			/// for testing only:
				int get_size() const {return sz;}
				int get_space() const {return space;}
				double * get_elem() const {return elem;}				
			};
			int main();
		}

		/// m_vector::operator = 
		namespace s08
		{
			class m_vector
			{
			/// as before:
				int sz, space;
				double * elem;
			public :
				m_vector () : sz {0}, elem {nullptr}, space {0} {}
				void reserve (int new_alloc);
				void resize (int new_size);
				void push_back (double d);

				int capacity() const {return space;}

			/// reimplementing :
				m_vector & operator = (const m_vector & a);

			/// for testing only:
				int get_size() const {return sz;}
				int get_space() const {return space;}
				double * get_elem() const {return elem;}				
			};
			int main();
		}

		/// m_vector::m_vector
		/// m_vector::operator =
		namespace s09
		{
			class m_vector
			{
			/// as before:
				int sz, space;
				double * elem;
			public :
				m_vector () : sz {0}, elem {nullptr}, space {0} {}
				int capacity() const {return space;}	// moved from "new stuff" because it already was in s06, and so added to following namespaces too.
				void reserve (int new_alloc);
				void resize (int new_size);
				void push_back (double d);
				m_vector & operator = (const m_vector & a);	/// copy assignment

			/// new stuff :
				explicit m_vector (int s) : sz {s}, elem {new double [s]}, space {s}
				{
					for (int i = 0; i < sz; ++i)
						elem [i] = 0;
				}
				m_vector (const m_vector &);				/// copy constructor


			/// both use an rvalue reference, which apparently is a big deal by itself:
			/// http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2010/n3055.pdf
			/// http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2010/n3092.pdf > 3.10
				m_vector (m_vector &&);						/// move constructor
				m_vector & operator = (m_vector &&);		/// move assignment

				~m_vector () {delete [] elem;}
				double & operator [] (int n) {return elem [n];}
				const double & operator [] (int n) const {return elem [n];}

				int size() const {return sz;}

			/// for testing only:
				double * get_elem() const {return elem;}				
			};

			int main();
		}

		/// 19.3 templates
		/// template m_vector
		namespace s10
		{
		/// C++14 additional definition of the type <T> understandable for the compiler
		/// it's called a "concept", which at compile time returns bool for the compiler (right?)
		/// in order to generate actual code from the template.
			// template <typename T> requires Element <t> () class m_vector {}

		/// C++14 respects also a shorter syntax
			// template <Element T> class m_vector{}

		/// C++11 doesn't have these kind of additional definitions tho
			template <typename T> 											
				class m_vector
			{
				int
					sz,
					space;
				T 
					* elem;
			public :
				m_vector () : sz {0}, elem {nullptr}, space {0} {}
				
				explicit m_vector (int s) : sz {s}, elem {new T [s]}, space {s}
				{
					for (int i = 0; i < sz; ++i)
						elem [i] = 0;
				}
				/// copy constructor and assignment
				m_vector (const m_vector &);
				m_vector & operator = (const m_vector &);

				/// move constructor and assignment
				m_vector (m_vector &&);
				m_vector & operator = (m_vector &&);

				~m_vector () {delete [] elem;}

				T & operator [] (int n) {return elem [n];}
				const T & operator [] (int n) const {return elem [n];}

				int size () const {return sz;}
				int capacity () const {return space;}

				void resize (int new_size);
				void push_back (const T & d);
				void reserve (int new_alloc);
			};

			int main();
		}

		/// 19.3.5
		/// template m_array::operator []
		namespace s11
		{
			template <typename T, int N>
				struct m_array
			{
				T
					elem [N];

				//m_array () {}			// empty constructor seems to mess things up only

				T & operator[] (int n);
				const T & operator[] (int n) const;
				T * data ()
				{
					return elem;
				}
				const T * data() const 
				{
					return elem;
				}
				int size() const
				{
					return N;
				}
			};
			int main();
		}

		namespace s12
		{
			using s11::m_array;
			
			template <typename C> 
				void printout (const C &);
			int main();
		}

		namespace s13
		{
			using s11::m_array;
			using s12::printout;

			template <class T, int N>
				void fill(m_array <T, N> &, const T &);
			int main();
		}

		namespace s14
		{
			template <typename T, typename A = allocator <T>>
				class m_vector
			{
			/// new stuff:
				A alloc;
			/// as before:
				int sz, space;
				T * elem;
			public :
				m_vector () : sz {0}, elem {nullptr}, space {0} {}

				void resize (int new_size);
				void push_back (const T & d);

				int capacity() const {return space;}

				m_vector & operator = (const m_vector & a);

			/// reimplementing to generic 
				void reserve (int new_alloc);


			/// for testing only:
				int get_size() const {return sz;}
				int get_space() const {return space;}
				T * get_elem() const {return elem;}				
			};

			int main();
		}

		/// 19.4
		namespace s15
		{
			/// new stuff
			struct out_of_range
			{
				string 
					message;
				out_of_range (){}
				out_of_range (string s) :
					message (s)
				{}
			};

			struct Range_error : out_of_range
			{
				int
					index;
				Range_error (int i) :
					out_of_range ("Range error"), index (i)
				{}
			};

			/// as before:
			template <typename T, typename A = allocator <T>>
				class m_vector
			{
				A alloc;
				int sz, space;
				T * elem;
			public :
				m_vector () : sz {0}, elem {nullptr}, space {0} {}
				void reserve (int new_alloc);
				void resize (int new_size);
				void push_back (const T & d);

				int capacity() const {return space;}

				m_vector & operator = (const m_vector & a);
			
			/// new stuff:
				T & operator [] (int n);
				const T & operator [] (int n) const;
				T & at (int n);
				const T & at (int n) const;

			/// for testing only:
				int get_size() const {return sz;}
				int get_space() const {return space;}
				T * get_elem() const {return elem;}				
			};


		int main();
		}

		namespace s16
		{
			using s15::Range_error;

			template <typename T> 
				struct m_vector : public std::vector <T>
				{
					using size_type = typename std::vector <T>::size_type;
					using vector<T>::vector;
					
					T & operator [] (size_type i)
					{
						if (i < 0 || this -> size() <= i)
							throw Range_error (i);
						return std::vector <T>::operator [] (i);
					}

					const T & operator [] (size_type i) const
					{
						if (i < 0 || this -> size () <= i)
							throw Range_error (i);
						return std::vector <T>::operator [] (i);
					}
				};

			int main();
		}

		/// 19.5.1 - "try this"
		namespace s17
		{
			int main();
		}

		/// guaranties:
		/// basic guarantee : no leaks
		/// strong guarantee : no flaws (in used resources)
		/// no-throw guarantee : no throws
		namespace s18
		{

			int main();
		}
		
		/// unique_ptr
		namespace s19
		{
			/// returns a pointer
			vector <int> * make_vec();

			/// returns a pointer container
			unique_ptr <vector <int>> make_vec_1();

			/// returns a vector 
			/// as is said to use a move constructor implemented straight in the vector
			vector <int> make_vec_2();

			int main ();
		}

	
	}

	namespace drill
	{
		namespace d01
		{
			template <typename T>
				struct S
			{
				T val;
			};
		}

		namespace d02
		{
			template <typename T>
				struct S
			{
				T val;
				S (T t) :
					val {t}
				{}
			};
		}

		namespace d03
		{
			template <typename T>
				struct S
			{
				T val;
				S () : val {T()} {}	// gotta add empty constructor
				S (T t) :
					val {t}
				{}
			};

			int main();
		}

		namespace d05
		{
			template <typename T>
				struct S
			{
				T val;
				S () : val {T()} {}
				S (T t) : val {t} {}

				T & get () {return val;}
			};

			int main ();
		}

		namespace d06
		{

			template <typename T>
				struct S
			{
				S () : val {T ()} {}
				S (T t) : val {t} {}
				T & get ();

			private :
				T val;
			};

			int main ();
		}

		namespace d08
		{
			template <typename T>
				struct S
			{
				S () : val {T ()} {}
				S (T t) : val {t} {}
				T & get ();
			private :
				T val;
			};
			int main();
		}

		namespace d09
		{
			template <typename T>
				struct S
			{
				S () : val {T()} {}
				S (T t) : val {t} {}
				T & get ();
				void set (T t);
			private :
				T val;
			};
			int main();
		}

		namespace d10
		{
			template <typename T>
				struct S
			{
				S () : val {T ()} {}
				S (T t) : val {t} {}
				T & get();
				S<T> & operator = (const T &);
			private :
				T val;
			};
			int main();
		}

		namespace d11
		{
			template <typename T>
				struct S
			{
				S () : val {T ()} {}
				S (T t) : val {t} {}
				T & get();
				S <T> & operator = (const T &);
				const S <T> & operator = (const T &) const;
			private :
				T val;
			};

			int main ();
		}

		namespace d12
		{
			template <typename T>
				struct S
			{
				S () : val {T ()} {}
				S (T t) : val {t} {}
				T & get();
				S <T> & operator = (const T &);
				const S <T> & operator = (const T &) const;
			private :
				T val;
			};

			template <typename T> 
				T & read_val (T & v);

			int main ();
		}

		namespace d13
		{
			template <typename T>
				struct S
			{
				S () : val {T ()} {}
				S (T t) : val {t} {}
				T & get();
				S <T> & operator = (const T &);
				const S <T> & operator = (const T &) const;
			private :
				T val;
			};

			template <typename T> 
				T & read_val (T & v);

			int main();
		}

		namespace d14
		{
			template <typename T>
				struct S
			{
				S () : val {T ()} {}
				S (T t) : val {t} {}
				T & get();
				S <T> & operator = (const T &);
				const S <T> & operator = (const T &) const;
			private :
				T val;
			};

			template <typename T> 
				T & read_val (T & v);

			template <typename T>
				istream & operator >> (istream & is, vector <T> & v);
			template <typename T>
				ostream & operator << (ostream & os, vector <T> & v);

			int main();
		}	
	}

	namespace excercise
	{
		namespace e01
		{
			template <typename T> 
				vector <T> & f (vector <T> & v1, vector <T> & v2);

			int main ();
		}

		namespace e02
		{
			template <typename T>
				T f (vector <T> & v1, vector <T> & v2);

			int main();		
		}

		namespace e03
		{
			template <typename T>
				class Pair
			{
				T s1, s2;
			public :
				Pair () : s1 {T ()}, s2 {T ()} {}
				Pair (T t1, T t2) : s1 {t1}, s2 {t2} {}
				T get_s1() {return s1;}
				T get_s2() {return s2;}

			};
			template <typename T> 
				ostream & operator << (ostream & os, Pair<T> & p)
			{
				os << p.get_s1() << ", " << p.get_s2();
				return os;
			}

			int main();
		}

		namespace e04
		{
			struct God
			{
				enum class Mythology
				{
					GREEK,
					ROMAN,
					SLAVIC,
					NORDIC,
					NONE
				};
				string mythology_to_string (Mythology m)
				{
					switch (m)
					{
						case Mythology::GREEK :
							return "greek"; break;
						case Mythology::ROMAN :
							return "roman"; break;
						case Mythology::SLAVIC :
							return "slavic"; break;
						case Mythology::NORDIC :
							return "nordic"; break;
						default :
							return "";
					}
				}

				string	
					name, vehicle, weapon;
				Mythology 
					mythology;
			
				God () : 
					mythology {Mythology::NONE} 
				{}
				God (string n, Mythology m, string v ="", string w ="") :
					name {n},
					mythology {m},
					vehicle {v},
					weapon {w}
				{}
			};

			inline ostream & operator << (ostream & os, God & g) // declared inline to avoid LINK2005, LINK1169
			{
				os
					<< g.name << ", "
					<< g.mythology_to_string (g.mythology) << ", "
					<< g.vehicle << ", "
					<< g.weapon;
				return os;
			}

			template <typename T>
				struct Link
			{
				T value;
				Link * prev, * succ;
				Link (const T & v, Link * p = nullptr, Link * s = nullptr) :
					value {v},
					prev {p},
					succ {s}
				{}
			};
			/// <summary>
			/// puts the first input in-front of the second input
			/// returns the latter
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <param name=""></param>
			/// <param name=""></param>
			/// <returns>latter in structure</returns>
			template <typename T> 
				Link <T> * insert (Link <T> *, Link <T> *);
			/// <summary>
			/// puts the first input after the second input
			/// returns the latter
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <param name=""></param>
			/// <param name=""></param>
			/// <returns>latter in structure</returns>
			template <typename T> 
				Link <T> * add (Link <T> *, Link <T> *);
			/// <summary>
			/// finds first object in the structure
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <param name=""></param>
			/// <returns>first in the structure</returns>
			template <typename T>
				Link <T> * find_first (Link <T> *);
			/// <summary>
			/// removes l from the structure
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <param name=""></param>
			/// <returns>* l</returns>
			template <typename T>
				Link <T> * remove (Link <T> *);
			


			int main();
		}

		namespace e05
		{
			class Int
			{
				int val;
				
				public :				
				Int () : val{0} {}
				Int (int i) : val {i} {}
				int get() {return val;}
				void set(int i) {val = i;}
			};
			Int operator + (Int &, Int &);
			Int operator - (Int &, Int &);
			Int operator * (Int &, Int &);
			Int operator / (Int &, Int &);
			ostream & operator << (ostream &, Int &);
			istream & operator >> (istream &, Int &);

			int main();
		}

		namespace e06
		{
			template <typename T> class Number
			{
				T val;
			public :
				Number () : val {T {0}} 
				{}
				Number (T t) : val {t}
				{}
				T get() {return val;}
				T set(T t) {val = t;}
				string type() {return typeid (val).name();}
			};
			template <typename T>
				Number <T> operator + (Number <T> &, Number <T> &);
			template <typename T>
				Number <T> operator - (Number <T> &, Number <T> &);
			template <typename T>
				Number <T> operator * (Number <T> &, Number <T> &);
			template <typename T>
				Number <T> operator / (Number <T> &, Number <T> &);
			template <typename T>
				Number <T> operator % (Number <T> &, Number <T> &);
			template <typename T>
				ostream & operator << (ostream & os, Number <T> & n)
			{
				os 
					<< n.get();
				return os;
			}
			int main();
		}

		namespace e07
		{
			template <typename T> 
				class Number
			{
				T val;
			public :
				Number () : val {T {0}} 
				{}
				Number (T t) : val {t}
				{}
				T get() {return val;}
				void set(T t) {val = t;}
				string type() {return typeid (val).name();}
			};
			template <typename T>
				void operator += (Number <T> & t1, Number <T> & t2)
			{
				t1.set(t1.get() + t2.get());
				//return t1;
			}
			template <typename T>
				Number <T> operator * (Number <T> & t1, Number <T> & t2)
			{
				return Number <T> {t1.get() * t2.get()};
			}
			template <typename T>
				ostream & operator << (ostream & os, Number <T> & n)
			{
				os << n.get();
				return os;
			}
			int main();
		}

		namespace e08
		{


			int main();
		}
	}
}