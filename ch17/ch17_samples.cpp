#include "ch17.h"

#include <vector>
#include <iostream>
#include <string>


namespace ch17
{
	using namespace std;
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
		namespace s01
		{
			//using namespace std;
			int main()
			{
				vector <double> age (4);
				age[0] = 0.33;
				age[1] = 22.0;
				age[2] = 27.2;
				age[3] = 54.2;

				return 0;
			}
		}

		namespace s02
		{		
			int m_vector::size() const 
			{
				return sz;
			}
		}

		namespace s03
		{
			//using namespace std;

			int main()
			{
				int 
					i {17},
					* ptr = & i;
				cout 
					<< i 
					<< " at " 
					<< ptr 
					<< " is indeed "
					<< * ptr
					<< endl;
				(* ptr) ++;	// changes the pointed value : increments 'i'
				cout 
					<< ptr 
					<< " is now "
					<< * ptr;
				* ptr ++;	// changes the pointer value : points at next 4 bytes in memory

				/// the line above brings an interesting question:
				///	the pointers address was adjusted based on assumed data type (int = 32 bites = 4 bytes)
				/// the data type of the variable stored in the next memory slot is not confirmed,
				/// nor is it provided at all - right?

				cout 
					<< i 
					<< " is not longer pointed at by the ptr:\n\t"
					<< ptr 
					<< ", "
					<< * ptr
					<< endl;
					

				return keep_open();
			}
		}

		namespace s04
		{
			/// the below calls for further investigation

			//using namespace std;
			int main()
			{
				long
					l {0x7FFF'FFFF};					
				int 
					i {0},
					j {1};
				long
					* l_ = & l;
				int 
					* i_ = &i;

				cout 
					<< hex
					<< *l_
					<< " : "
					<< l_
					<< endl;
				++l_;
				cout
					<< * l_
					<< " : "
					<< l_
					<< endl;

				//cout 
				//	<< hex
				//	<< i_ << " : "
				//	<< * i_
				//	<< endl;
				//i_--;
				//cout 
				//	<< i_ << " : "
				//	<< * i_
				//	<< endl;
					

				return keep_open();

			}

		}

		namespace s05
		{
			//using namespace std;
			void sizes(char c, int i, int * p)
			{
				cout
					<< "the size of char is "
					<< sizeof(char) 
					<< ' ' 
					<< sizeof(c) 
					<< endl;
				cout
					<< "the size of int is "
					<< sizeof(int) 
					<< ' '
					<< sizeof(i)
					<< endl;
				cout 
					<< "the size of int * is "
					<< sizeof(int *) 
					<< ' '
					<< sizeof(p)
					<< endl;
			}
			int main ()
			{
				char 
					c {0};
				int 
					i = c,
					* p = & i;
				sizes (c, i, p);
				cout 
					<< "---------------------" << endl;
				bool
					b = bool (c);
				double
					d = double(b);
				string
					s = to_string(d),
					s1 {
						"Johann Gambolputty de von Ausfern Schplenden Schlitter Crasscrenbon Fried Digger Dangle Dungle Burstein von Knacker Thrasher Apple Banger Horowitz Ticolensic Grander Knotty Spelltinkle Grandlich Grumblemeyer Spelterwasser Kürstlich Himbleeisen Bahnwagen Gutenabend Bitte Eine Nürnburger Bratwustle Gerspurten mit Zweimache Luber Hundsfut Gumberaber Shönendanker Kalbsfleisch Mittler Raucher von Hautkopft of Ulm."
					};
				cout 
					<< "bool "
					<< sizeof(bool)
					<< ' '
					<< sizeof(b)
					<< endl;
				cout
					<< "double "
					<< sizeof(double)
					<< ' '
					<< sizeof(d)
					<< endl;
				cout
					<< "string "
					<< sizeof(string)
					<< ' '
					<< sizeof(s)
					<< endl;
				cout 
					<< "the biggest name in history of music "
					<< sizeof(string)
					<< ' '
					<< sizeof(s1)
					<< endl;
				cout 
					<< "---------------------" << endl;
				vector<int> v (1000);
				cout 
					<< "vector size "
					<< sizeof(v)
					<< endl;

				
				return keep_open();
			}
		}

		namespace s06
		{
			//using namespace std;
			int main()
			{
				int
					* p = new int[2] {-1, -1};	/// pointer declaration with subscript operator '[]' initializes object sequence. (an array?)
												/// got it initialized at once to avoid wrn C6001 at the 'x' declaration
				int
					x = * p;
				int
					y = p[0],		/// pass by value - changing it won't affect p[0]
					& z = p[0];		/// pass by reference - will it interfere with p[0]
				auto print = [&] 
				{
					cout << "p[0] : " << p[0] << "\ty : " << y << "\tz : " << z << endl;
				};

				print();
				y = 0;
				print();
				p[0] = 1;
				print();
				z = 2;
				print();
				* p = 3;
				print();
				return keep_open();
			}
		}

		namespace s07
		{
			int main()
			{
				double
					* p0 = nullptr;
				cout << (bool(p0) == (p0 != nullptr) ? "yep" : "nope") << endl;
				/// checking whether pointer is initialized -
				/// it's logically equivalent to check whether pointer is declared "nullptr" (the null pointer)
				/// 'nullptr' is since C++, earlier '0' or 'NULL' were in use

				return keep_open();
			}
		}

		namespace s08
		{
			void example_01()
			{
				char
					* p = nullptr;
				auto f = [&]
				{
					char
						i = '@';
					p = & i;
				};
				f();
				cout << * p << endl;
			}
			void example_02()
			{
				int
					* p = nullptr;
				auto f = [&]
				{
					p = new int[1];
				};
				f();
				cout << bool(p) << endl;
				if (p)
					cout 
						<< p << " : "
						<< * p 
						<< endl;
				delete p;
				cout << bool(p) << endl;
				if (p)
					cout 
						<< p << " : "
						//<< * p	// exception : read access violation
						<< endl;			
			}

			int main()
			{
				//example_01();
				example_02();


				return keep_open();
			}
		}

		namespace s09
		{
			m_vector::m_vector (int s) :
				sz {s},
				elem {new double[s]}
			{
				for (int i = 0; i < s; ++i)
					elem[i] = 0;
			}

			int m_vector::size() const 
			{
				return sz;
			}
		}

		namespace s10
		{
			int main()
			{
				TB303
					* tb303 = new TB303 {Bass::Wave::SQR, 43.65};
				if(tb303)
					cout 
						<< static_cast<int>((*tb303).wave()) 
						<< ", "
						<< (*tb303).freq()
						<< endl;
				delete tb303;
				//(* tb303).freq(); Exc : memory access violation
				if (tb303)
				{
					TB303
						cache;
					tb303 = & cache;
					cout 
						<< static_cast<int>((*tb303).wave()) 
						<< ", "
						<< (*tb303).freq()
						<< endl;
				}
				cout 
					<< "getting cache freq out of scope: " 
					<< (* tb303).freq();
				return keep_open();
			}
		}
	}
}
