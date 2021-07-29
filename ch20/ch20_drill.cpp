#include "ch20.h"

namespace ch20
{
	namespace drill
	{
		void d00 ()
		{
			// 1.

			const int
				len = 10;
			int 
				a1 [len] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

			// 2.
			
			vector <int> 
				v1 (& a1 [0], & a1 [9]);		// using iterators, right?

			// 3.
			
			list <int>
				l1 (v1.begin (), v1.end ());

			// 4.

			int
				a2 [len];
			for (int i = 0; i < len; ++i)
				a2 [i] = a1 [i];

			vector <int>
				v2 = v1;

			list <int>
				l2 = l1;

			// 5.

			for (int & i : a2)
				i += 2;

			for (int & i : v2)
				i += 3;
			
			for (int & i : l2)
				i += 5;
		}

		
			int *  copy (int * f1, int * e1, int * f2)
		{
			while (f1 != e1)
			{
				* f2 = * f1;
				++f1;
				++f2;
			}
			return f2;
		}

		int main()
		{

			//d00();

			int 
				a1 [3] {-1, 1, 10},
				a2 [3];

			copy (a1, & a1[3], a2);

			for (int i : a2)
				cout << i << ", ";
			return 0;
		}


	}
}