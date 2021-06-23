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
			bool God::operator == (const God & g) const
			{
				if (this == & g)
					return true;
				if (this -> name == g.name && this -> attribute == g.attribute && this -> locomotion == g.locomotion)
					return true; 
				return false;
			}
			bool God::operator > (const God & g) const
			{
				if (name > g.name)
					return true;
				return false;
			}
			bool God::operator < (const God & g) const
			{
				if (name < g.name)
					return true;
				return false;
			}

			template <typename T> Link<T> * Link<T>::rew		()
			{
				if (! prev)
					return this;
				Link
					* anchor = this -> prev;
				while (anchor -> prev)
				{
					anchor = anchor -> prev;
					if (anchor == this)
						break;
				}
				return anchor;
			}
			template <typename T> Link<T> * Link<T>::ff			()
			{
				if (! succ)
					return this;
				Link
					* anchor = this -> succ;
				while (anchor -> succ)
				{
					anchor = anchor -> succ;
					if (anchor == this)
						break;
				}
				return anchor;
			}
			template <typename T> Link<T> * Link<T>::insert		(Link<T> * n)
			{
				if (!n)
					return this;
				n -> succ = this;
				if (prev)
					prev -> succ = n;
				n -> prev = prev;
				prev = n;
				return n;
			}
			template <typename T> Link<T> * Link<T>::push_back	(Link<T> * n)
			{
				if (n == this)
					return this;					
				Link
					* anchor = ff();
				n -> prev = anchor;
				anchor -> succ = n;
				anchor = rew();
				return anchor;
			}
			template <typename T> Link<T> * Link<T>::add_ordered(Link<T> * n)
			{
				Link
					* anchor = this;
				while (anchor)
				{
					if (anchor -> value < n -> value)
					{
						if (n -> value < anchor -> succ -> value)
						{
							break;
						}
						else
							if (anchor -> succ)
							{
								anchor = anchor -> succ;
							}
							else
							{
								break;
							}
					}
					else
						if (anchor -> prev)
						{
							anchor = anchor -> prev;
						}
						else
							break;
				}
				//anchor.push_back (n);
				return anchor;
			}

			int main()
			{
				Link<God>
					greek {God {"aaaaaab", "", ""}},
					apollo {God {"Apollo", "Lyre", "chariot"}},
					dionysus {God{"Dionysus", "wine", ""}},
					zeus {God{"Zeus", "lightning", "subway"}};
				//greek.push_back (& apollo);
				apollo.push_back (& dionysus);
				apollo.push_back (& zeus);

				Link<God>
					* the = dionysus.add_ordered(& greek);





				return 0;
			}
		}
	}
}