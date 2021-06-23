#include "ch19.h"

namespace ch19
{
	namespace excercise
	{
		namespace e01
		{
			template <typename T> void f(vector<T> & v1, vector<T> & v2)
			{
				for (int i = 0; i < v1.size() && i < v2.size(); ++i)
						v1[i] += v2[i];	
			}

			void case_01()
			{
				vector<int>
					v1 {0, 1, 2, 3},
					v2 {-1, 0, -1 , 1000, -5};
				f (v1, v2);
				for (int i : v1)
					cout 
						<< i 
						<< ", ";
				cout 
					<< '\n';
			}

			void case_02()
			{
				vector<char>
					v1 {65, 32, 24, 0},
					v2 {32, 32, 32, 33};
				f (v1, v2);
				for (char c : v1)
					cout
						<< c
						<< ", ";
				cout
					<< '\n';
			}

			void case_03()
			{
				vector<string>
					v1 {"", "a", "nope"},
					v2 {"\n", "_", " !", " whatever"};
				f (v1, v2);
				for (string s : v1)
					cout 
						<< s 
						<< ", ";
				cout 
					<< '\n';
			}
			int main()
			{
				case_01();
				cout
					<< "-----------\n";
				case_02();
				cout
					<< "-----------\n";
				case_03();
				cout
					<< "-----------\n";
				return 0;
			}
		}

		namespace e03
		{
			int main()
			{
				vector<Pair<char, string>>
					pairs;
				Pair <char, string>
					p1 {'a', "a letter a"};
				pairs.push_back(p1);
				pairs.push_back({'b', "a letter b"});

				for (Pair<char, string> p : pairs)
					cout
						<< p.val_t 
						<< " : "
						<< p.val_u
						<< '\n';				
				return 0;
			}			
		}

		namespace e04
		{
			Link * Link::insert (Link * p, Link * n)
			{
				if (!n)
					return p;
				if (!p)
					return n;
				n -> succ = p;
				if (p -> prev)
					p -> prev -> succ = n;
				n -> prev = p -> prev;
				p -> prev = n;
				return n;
			}

			int main()
			{

				return 0;
			}
		}
	}
}