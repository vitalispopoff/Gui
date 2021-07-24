#include "ch19.h"

#include <vector>
#include <iostream>

namespace ch19
{
	namespace excercise
	{
		using namespace std;

		namespace e01
		{
			template <typename T> 
				vector <T> & f (vector <T> & v1, vector <T> & v2)
			{
				for (int i = 0; i < (int) v1.size() && i < (int) v2.size(); ++i)
					v1 [i] += v2 [i];
				return v1;
			}

			int main ()
			{
				vector <int>
					v1 {0, 1, 2, 3, 4},
					v2 {-1, -2, -3, -4};
				f (v1, v2);

				for (int i : v1)
					cout
						<< i << ", ";
				cout
					<< '\n';		
				return 0;
			}

		}

		namespace e02
		{
			template <typename T> T f (vector <T> & v1, vector <T> & v2)
			{
				T result {0};

				for (int i = 0; i < (int) v1.size() && i < (int) v2.size(); ++i)
					result += ( v1 [i] * v2 [i]);

				return result;
			}

			int main ()
			{
				vector <int>
					v1 {0, 1, 2, 3},
					v2 {1};
				cout
					<< f (v1, v2);

				return 0;
			}
		}

		namespace e03
		{
			int main ()
			{
				vector <Pair <char>>
					v_p;
				Pair <char>
					p ('c', 'd');
				v_p.push_back (p);

				for (Pair <char> p : v_p)
					cout 
						<< p;
				cout
					<< '\n';
				return 0;
			}
		}

		namespace e04
		{
			template <typename T>
				Link <T> * insert (Link <T> * delivery, Link <T> * target)	/// puts delivery in front of target
			{
				if (delivery == nullptr)
					return target;
				if (target == nullptr)
					return delivery;
				delivery -> succ = target;
				if (target -> prev)
					target -> prev -> succ = delivery;
				delivery -> prev = target -> prev;
				target -> prev = delivery;
				return target;
			}
			template <typename T>
				Link <T> * add (Link <T> * delivery, Link <T> * target)	/// puts delivery after the target; insert() mirrored 
			{
				if (delivery == nullptr)
					return target;
				if (target == nullptr)
					return delivery;
				delivery -> prev = target;
				if (target -> succ)
					target -> succ -> prev = delivery;
				delivery -> succ = target -> succ;
				target -> succ = delivery;				
				return delivery;
			}
			template <typename T>
				Link <T> * find_first (Link <T> * l)
			{
				Link <T> * result = l;
				while (true)
				{
					if (result -> prev)
						result = result -> prev;
					else
						return result;
				}
				return result;
			}
			template <typename T>
				Link <T> * remove (Link <T> * l)
			{
				if (!(l -> prev) && !(l -> succ))
					return l;
				if (l -> prev)
					l -> prev -> succ = l -> succ;
				if (l -> succ)
					l -> succ -> prev = l -> prev;
				l -> prev = l -> succ = nullptr;
				return l;
			}

			template <typename T>
				void print_all (Link <T> * l)
			{
				Link <T>
					* current = l;
				while (true)
				{
					cout 
						<< current -> value;
					if (current -> succ == nullptr)
						break;
					cout
						<< '\n';
					current = (current -> succ);
				}
			}

			void main_1 ()
			{
				Link <string>
					l1 ("one"),
					l2 ("two"),
					l3 ("three"),
					* l = & l1;	// setting this definition before insert forces it to be '*' to keep it uptodate
				insert (insert (& l1, & l2), & l3);
				print_all (l);
			}

			void main_2 ()
			{
				Link <God>
					g1 (God ("Zeus", God::Mythology::GREEK, "", "lightning")),
					g2 (God ("Ianus", God::Mythology::ROMAN)),
					g3 (God ("Tryg�aw", God::Mythology::SLAVIC)),
					g4 (God ("Odin", God::Mythology::NORDIC, "Sleipner", "Gungnir"));
								
				print_all (find_first (add (& g4, add (& g3, insert (& g1, & g2))))); // is this a lisp vibe?
				cout
					<< "\n----\n"
					<< (remove (& g3) -> value)
					<< "\n----\n";
				
				print_all (find_first (& g4));
				cout
					<< "\n----\n";
			}

			int main ()
			{
				return 0;
			}
		}

		namespace e05
		{
			Int operator + (Int & i1, Int & i2)
			{
				return Int (i1.get() + i2.get());
			}
			Int operator - (Int & i1, Int & i2)
			{
				return Int (i1.get() - i2.get());
			}

			int main()
			{
				Int 
					i1 {1},
					i2 {2},
					i3 {i1 - i2};
				cout
					<< i3.get();

				return 0;
			}
		}
	}
}

/// first reading round below

//#include "ch19.h"
//
//namespace ch19
//{
//	namespace excercise
//	{
//		namespace e01
//		{
//			template <typename T> void f(vector<T> & v1, vector<T> & v2)
//			{
//				for (int i = 0; i < v1.size() && i < v2.size(); ++i)
//						v1[i] += v2[i];	
//			}
//
//			void case_01()
//			{
//				vector<int>
//					v1 {0, 1, 2, 3},
//					v2 {-1, 0, -1 , 1000, -5};
//				f (v1, v2);
//				for (int i : v1)
//					cout 
//						<< i 
//						<< ", ";
//				cout 
//					<< '\n';
//			}
//
//			void case_02()
//			{
//				vector<char>
//					v1 {65, 32, 24, 0},
//					v2 {32, 32, 32, 33};
//				f (v1, v2);
//				for (char c : v1)
//					cout
//						<< c
//						<< ", ";
//				cout
//					<< '\n';
//			}
//
//			void case_03()
//			{
//				vector<string>
//					v1 {"", "a", "nope"},
//					v2 {"\n", "_", " !", " whatever"};
//				f (v1, v2);
//				for (string s : v1)
//					cout 
//						<< s 
//						<< ", ";
//				cout 
//					<< '\n';
//			}
//			int main()
//			{
//				case_01();
//				cout
//					<< "-----------\n";
//				case_02();
//				cout
//					<< "-----------\n";
//				case_03();
//				cout
//					<< "-----------\n";
//				return 0;
//			}
//		}
//
//		namespace e03
//		{
//			int main()
//			{
//				vector<Pair<char, string>>
//					pairs;
//				Pair <char, string>
//					p1 {'a', "a letter a"};
//				pairs.push_back(p1);
//				pairs.push_back({'b', "a letter b"});
//
//				for (Pair<char, string> p : pairs)
//					cout
//						<< p.val_t 
//						<< " : "
//						<< p.val_u
//						<< '\n';				
//				return 0;
//			}			
//		}
//
//		namespace e04
//		{
//			bool God::operator == (const God & g) const
//			{
//				if (this == & g)
//					return true;
//				if (this -> name == g.name && this -> attribute == g.attribute && this -> locomotion == g.locomotion)
//					return true; 
//				return false;
//			}
//			bool God::operator > (const God & g) const
//			{
//				if (name > g.name)
//					return true;
//				return false;
//			}
//			bool God::operator < (const God & g) const
//			{
//				if (name < g.name)
//					return true;
//				return false;
//			}
//
//			template <typename T> Link<T> * Link<T>::rew		()
//			{
//				if (! prev)
//					return this;
//				Link
//					* anchor = this -> prev;
//				while (anchor -> prev)
//				{
//					anchor = anchor -> prev;
//					if (anchor == this)
//						break;
//				}
//				return anchor;
//			}
//			template <typename T> Link<T> * Link<T>::ff			()
//			{
//				if (! succ)
//					return this;
//				Link
//					* anchor = this -> succ;
//				while (anchor -> succ)
//				{
//					anchor = anchor -> succ;
//					if (anchor == this)
//						break;
//				}
//				return anchor;
//			}
//			template <typename T> Link<T> * Link<T>::insert		(Link<T> * n)
//			{
//				if (!n)
//					return this;
//				n -> succ = this;
//				if (prev)
//					prev -> succ = n;
//				n -> prev = prev;
//				prev = n;
//				return n;
//			}
//			template <typename T> Link<T> * Link<T>::push_back	(Link<T> * n)
//			{
//				if (n == this)
//					return this;					
//				Link
//					* anchor = ff();
//				n -> prev = anchor;
//				anchor -> succ = n;
//				anchor = rew();
//				return anchor;
//			}
//			template <typename T> Link<T> * Link<T>::add_ordered(Link<T> * n)
//			{
//				Link
//					* anchor = this;
//				while (anchor)
//				{
//					if (anchor -> value < n -> value)
//					{
//						if (n -> value < anchor -> succ -> value)
//						{
//							break;
//						}
//						else
//							if (anchor -> succ)
//							{
//								anchor = anchor -> succ;
//							}
//							else
//							{
//								break;
//							}
//					}
//					else
//						if (anchor -> prev)
//						{
//							anchor = anchor -> prev;
//						}
//						else
//							break;
//				}
//				//anchor.push_back (n);
//				return anchor;
//			}
//
//			int main()
//			{
//				Link<God>
//					greek {God {"aaaaaab", "", ""}},
//					apollo {God {"Apollo", "Lyre", "chariot"}},
//					dionysus {God{"Dionysus", "wine", ""}},
//					zeus {God{"Zeus", "lightning", "subway"}};
//				//greek.push_back (& apollo);
//				apollo.push_back (& dionysus);
//				apollo.push_back (& zeus);
//
//				Link<God>
//					* the = dionysus.add_ordered(& greek);
//
//
//
//
//
//				return 0;
//			}
//		}
//	}
//}