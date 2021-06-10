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
	}
}