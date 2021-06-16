#include "ch18.h"

#include <iostream>


namespace ch18
{
	namespace drill
	{
		namespace d01
		{
			int constexpr
				len = 10;
			int
				ga [len];
			void ga_populate()
			{
				for (int i = 0; i < len; ++i)
					ga[i] = 1 << i;
			}
			int main()
			{
				ga_populate();
				for (int i = 0; i < len; ++i)
					cout << ga[i] << (i < len - 1 ? ", " : "\n");
				return 0;
			}
		}

		namespace d02
		{
			void f (int arr[], int len)
			{
				int
					la [d01::len];				/// was to be declared as 10, changed to keep consistency across namespaces
				for (int i = 0 ; i < d01::len; ++i)
				{
					la[i] = d01::ga[i];
					cout 
						<< la[i] 
						<< (i < d01::len - 1 
							? ", " 
							: "\n");
				}

				int
					* p = new int[len];
				for (int i = 0; i < len; ++i)
				{
					p[i] = arr[i];
					cout 
						<< p[i] 
						<< (i < len - 1 
							? ", " 
							: "\n");
				}
				delete [] p;
			}
		
			int main()
			{
				d01::ga_populate();
				f(d01::ga, d01::len);

				int
					aa[10];
				for (int i = 0; i < 10; ++i)
				{
					if (i)
					{
						aa[i] = aa[i - 1] * i;
						continue;
					}
					aa[0] = 1;
				}
				cout 
					<< "\n-------------------------\n";
				f(aa, 10);
				return 0;
			}
		}

		namespace d05
		{
			vector<int>
				g(10);
			void g_populate()
			{
				int 
					val = g[0];
				for (int & i : g)
					i = (1 << val++);
			}

			void f (vector<int> v)
			{
				

			}


			int main()
			{
			/// vector drill 1.
				g_populate();
				cout 
					<< g.size() << endl;
				for (int i : g)
					cout << i << ", ";
			/// vector drill 3.

				return 0;
			}

		}
	}
}