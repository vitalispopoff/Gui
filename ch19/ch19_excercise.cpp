#include "ch19.h"

#include <vector>
#include <iostream>
#include <typeinfo> // for the e06 just in case
#include <cstdint> // for the e06
#include <string> // for the e06

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
					g3 (God ("Tryg³aw", God::Mythology::SLAVIC)),
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
			Int operator * (Int & i1, Int & i2)
			{
				return Int (i1.get() * i2.get());				
			}
			Int operator / (Int & i1, Int & i2)
			{
				if (i2.get() == 0)
				{
					cerr
						<< "Dividing by zero. Zero returned instead.";
					return 0;
				}
				return Int (i1.get() / i2.get());
			}
					
			ostream & operator << (ostream & os, Int & i)
			{
				os 
					<< i.get();
				return os;
			}
			istream & operator >> (istream & is, Int & i)
			{
				int input;
				is
					>> input;
				i.set(input);
				return is;
			}

			int main()
			{
				Int 
					i1 {1},
					i2 {2},
					i3 {i1 / i2};
				cout
					<< i3 << '\n';

				return 0;
			}
		}

		namespace e06
		{
			template <typename T>
				Number <T> operator + (Number <T> & t1, Number <T> & t2)
			{
				return Number<T> {t1.get() + t2.get()};
			}
			template <typename T>
				Number <T> operator - (Number <T> & t1, Number <T> & t2)
			{
				return Number<T> {t1.get() - t2.get()};
			}
			template <typename T>
				Number <T> operator * (Number <T> & t1, Number <T> & t2)
			{
				return Number<T> {t1.get() * t2.get()};
			}
			template <typename T> 
				Number <T> operator / (Number <T> & t1, Number <T> & t2)
			{
				if (t2.get() == 0)
				{
					cerr << "Dividing by zero. Zero returned instead";
					return Number <T> {0};
				}
				return Number <T> {t1.get() / t2.get()};
			}
			template <typename T>
				Number <T> operator % (Number <T> & t1, Number <T> & t2)
			{
				if (t2.get() == 0)
					return t1;	// because why not?
				T result = t1.get() - floor (t1.get() / t2.get());
				return Number <T> {result};
			}

			int main()
			{
				Number<double>
					i1 {3.141592628},
					i2 {1.618},
					i3 {i1 % i2};
				cout 
					<< i3;				
				return 0;
			}
		}

		namespace e07
		{
			template <typename T>
				Number <T> add_vectors (vector <Number <T>> & v, vector <Number <T>> & u)
			{
				Number <T> result {0};

				for (int i = 0; i < (int) v.size() || i < (int) u.size(); ++i)
				{
					result.set(result.get() + (v [i] * u [i]).get());
				}
				return result;
			}

			void main_1()
			{
				vector <Number <int>>
					v = {Number <int> {0}, Number <int> {1}, Number <int> {2}},
					u = {Number <int> {1}, Number <int> {-1}, Number <int> {-2}};

				cout << (Number <int> &) add_vectors (v, u);
			}
			void main_2()
			{
				vector <Number <double>>
					v = {Number <double> {0.1}, Number <double> {1.89}, Number <double> {2.7143}},
					u = {Number <double> {1.6}, Number <double> {-1.618}, Number <double> {-2.001}};

				cout << (Number <double> &) add_vectors (v, u);
			}
			int main()
			{
				//main_1();
				main_2();
				return 0;
			}
		}

		namespace e08
		{

			int main()
			{
				return 0;
			}
		}
	}
}