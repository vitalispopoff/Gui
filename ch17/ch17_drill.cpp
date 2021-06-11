#include "ch17.h"
#include <iostream>
#include <vector>

namespace ch17
{
	namespace drill
	{
		using namespace std;
		using ch17::keep_open;
		namespace d01
		{
			int main()
			{
			/// drill 01
				int
					len {10},
					* a = new int[len];
				for (int i = 0; i < len; ++i)
					a[i] = i;				
			/// drill 02
				for (int i = 0; i < len; ++i)
				{	cout 
						<< a[i]
						<< (i < len - 1 ? ", " : ".\n");				
				}
			/// drill 03
				delete[]a;
				//cout << * a; // wanna make sure the a is deleted? enjoy your read access violation				
				return keep_open();
			}
		}

		namespace d04
		{
			ostream & print_array10 (ostream & os, int * a)
			{
				if (!a)
					return os;
				for (int i = 0; i < 10; ++i)
					cout 
						<< a[i]
						<< (i < 10 - 1 ? ", " : ".");
				return os;
			}			
			int main()
			{
				int
					len = 10,
					* arr = new int [len];
				for (int i = 0; i < len; ++i)
					arr[i]= 100 + i;							
				print_array10 (cout, arr);
				delete [] arr;
				return keep_open();
			}
		}

		namespace d06
		{
			int main()
			{
				int
					len = 11,
					* a = new int[len];
				for (int i = 0; i < len; ++i)
					a[i] = 100 + i;
				for (int i = 0; i < len; ++i)
					cout << a[i] << (i < len - 1 ? ", " : ".");
				delete [] a;
				return keep_open();
			}
		}

		namespace d07
		{
			ostream & print_array (ostream & os, int * a, int n)
			{
				if(!a)
					return os;
				for(int i = 0; i < n; ++i)
					os 
						<< a[i]
						<< (i < n - 1 
							? ", "
							: ".");
				return os;
			}
			int main()
			{
				int 
					l = 100,
					* a = new int [l];
				for (int i = 0; i < l; ++i)
					a[i] = i << 1;

				print_array(cout, a, l);
				delete[] a;
				return keep_open();			
			}
		}

		namespace d08
		{
			int main()
			{
				int
					l = 20,
					* a = new int[l];
				for (int i = 0; i < l; ++i)
					a[i] = i << i;
				for (int i = 0; i < l; ++i)
					cout
						<< a[i]
						<< (i < l - 1 
							? ", "
							: ".");
				delete [] a;
				return keep_open();
			}
		}

		namespace d10
		{
			ostream & print_vector (ostream & os, vector<int> * v)
			{
				if (!v)
					return os;
				int
					last = v -> back();
				for (int i : * v)
					cout 
					<< i 
					<< (i != last
						? ", " 
						: ".");
			}
			void re_drill_05()
			{
				int
					l	{10},
					val {100};
				vector<int>
					* v = new vector<int>(l);
				for (int & i : * v)
					i = val++;
				print_vector(cout, v);
				delete (v);
			}

			void re_drill_06()
			{
				int
					l {11},
					val {100};
				vector<int>
					* v = new vector <int>(l);
				for (int & i : * v)
					i = val++;
				print_vector (cout, v);
				delete (v);	// to see it erasing the vector from memmory, go for the debug and add 'v' to the watchlist
			}

			void re_drill_08()
			{
				int
					l {20},
					val{100};
				vector<int>
					* v = new vector <int> (l);
				for (int & i : *v)
					i = val ++;
				print_vector(cout, v);
				delete (v);
			}

			int main()
			{
				re_drill_05();
				cout 
					<< endl;
				re_drill_06();
				cout 
					<< endl;
				re_drill_08();
				cout 
					<< endl;
				return keep_open();
			}
		}

		namespace d11
		{
			using d07::print_array;
			int main()
			{
				int
					len {10},
					* i = new int (7),
					* p1 = i;
				cout 
					<< p1 
					<< " : " 
					<< & p1;
			/// drill 13
				int
					l {7},
					* a = new int[l];
				auto populate = [] (int * p, const int & len)
				{
					for (int index = 0; index < len; ++index)
						p[index] = 1 << index;
				};
				populate(a, l);
			/// drill 14
				print_array(cout, a, l);
				cout << endl;
				int
					* p2 = a;
				cout << & p2 << endl;
				print_array(cout, p2, l);
			/// drill 15
				int 
					* p3 = p2;
			/// drill 16
				p1 = p2;
			/// drill 17
				p3 = p2;
			/// drill 18
				cout 
					<< p1 << " : " << * p1 << endl
					<< p2 << " : " << * p2 << endl;
			/// drill 19
				delete i;
				i = nullptr;
				p3 = nullptr;
				p2 = nullptr;
				p1 = nullptr;
				delete [] a;
				a = nullptr;
			/// drill 20
				l = 10;
				a = new int[l];
				populate(a, l);
				p1 = a;
				int
					* a1 = new int[l];
				p2 = a1;
				for(int index = 0; index < l; ++index)
				{
					p2[index] = p1[index];
				}
				print_array (cout, p1, 10);
				cout << endl;
				print_array (cout, p2, 10);
				p2 = nullptr;
				p1 = nullptr;
				delete [] a1;
				a1 = nullptr;
				delete [] a;
				a = nullptr;
				return keep_open();
			}
		}

		namespace d20
		{
			int main()
			{
				auto populate = [] (vector<int> * p)
				{
					int val = 1;
					for (int & i : * p)
					{
						i = val;
						val += val;
					}
				};
				auto print_vector = [] (vector<int> * p)
				{
					int
						last = p -> back();
					for (int i : * p)
						cout 
							<< i 
							<< (i != last 
								? ", "
								: ".");
				};
				int
					l = 10;
				vector<int>
					* v1 = new vector<int>(l);
				populate(v1);
				print_vector(v1);
				cout 
					<< endl;
				vector<int>
					* p1 = v1,
					* v2 = new vector<int>(l),
					* p2 = v2;
				for(int index = 0; index < l; ++index)
					(* p2) [index] = (* p1) [index];
				print_vector(p1);			
				cout 
					<< endl;
				print_vector(p2);
				p2 = nullptr;
				p1 = nullptr;
				delete (v2);
				delete (v1);
				return keep_open();				
			}
		}

		namespace d21
		{
			int main()
			{
				int
					i = 0;
				cout << & i << endl;
				int 
					* b = & i;
				cout << b << ", " << & i << endl;
				cout << & b << endl;


				return keep_open();
			}
		}
	}
}