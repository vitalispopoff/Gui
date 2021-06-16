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
						aa[i] = aa[i - 1] * (i + 1);
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
				gv(10);
			void g_populate()
			{
				int 
					val = gv[0];
				for (int & i : gv)
					i = (1 << val++);
			}

			void f (vector<int> v)
			{
			/// vector drill 3.
				vector<int> 
					lv(v.size());
				lv = gv;
			/// making sure the '=' operator copied vector as supposed
				vector<int>
					* gv_p = & gv,
					* lv_p = & lv;
				cout
					<< '\n' << gv_p << ", " << lv_p << endl;
				cout
					<< "lv :\t";
				for (int i : lv)
					cout 
						<< i << ", ";
				cout 
					<< endl;
				vector <int>
					lv2 = v;
				cout
					<< "lv2 :\t";
				for (int i : lv2)
					cout 
						<< i << ", ";
				cout 
					<< endl;
					

			}


			int main()
			{
			/// vector drill 1.
				g_populate();
				cout
					<< "gv :\t";
				for (int i : gv)
					cout << i << ", ";
				cout
					<< endl;
			/// vector drill 4.
				f(gv);
				cout 
					<< "\n-----------------\n";
				vector <int>
					vv;
				cout 
					<< "vv size :\t" << vv.size() << endl;
				for(int i = 0; i < 10; ++i)
				{
					if (i)
					{
						vv.push_back(vv[i - 1] * (i + 1));
						continue;
					}
					vv.push_back(1);
				}
				for (int i : vv)
					cout 
						<< i 
						<< ", ";
				cout 
					<< "\n-----------------\n";
				f(vv);
				return 0;
			}

		}
	}
}