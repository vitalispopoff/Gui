#pragma once

#include <iostream>
namespace ch17
{
	namespace sample
	{
		using namespace std;

		namespace s01
		{
			int main();
		}

		namespace s02
		{
			/// basic idea of what the vector has
			class m_vector
			{
				int
					sz;							/// size
				double
					* elem;						/// pointer to the member elements sequence in the memory
			public :
				m_vector (int s) :
					sz {s}
				{}								/// still no idea how to make the 'elem' working
				int size() const;
			};		
		}

		namespace s03
		{
			int main();
		}

		namespace s04
		{
			int main();
		}

		namespace s05
		{
			int main();
		}

		namespace s06
		{
			int main();
		}

		namespace s07
		{
			int main();
		}

		namespace s08
		{
			int main();
		}

		namespace s09
		{
			class m_vector
			{
				int
					sz;
				double
					* elem;
			public :
				m_vector (int s);				/// elem uses 'new' to initialize an array (?) on the free store
												/// that will end up with memory leaks tho
				int size() const;
			};
		}

		namespace s10
		{
			class Bass
			{
			public :
				enum class Wave
				{
					SQR,
					SAW,
					TRI,
					SIN
				};
				double virtual freq() const
				{
					return freq_;
				}
				void virtual freq(double f)
				{
					freq_ = f;
				}
				Wave virtual wave() const
				{
					return wave_;
				}
				void virtual wave(Wave w)
				{
					wave_ = w;
				}

			protected :
				Bass () :
					wave_{Wave::SIN}, 
					freq_ {440.}
				{}
					
				Bass (Wave w, double f) : 
					wave_ {w}, freq_ {f}
				{
					cout << "Bass at " << f << "Hz declared"<<endl;
				}
				Bass (const Bass &) = delete;
				Bass & operator = (const Bass &) = delete;
				virtual ~Bass() 
				{
					cout << "Bass at " << freq_ << "Hz undeclared, and deleted" << endl;
				}
				double 
					freq_;			
				Wave 
					wave_;
			};

			//ostream & operator << (ostream & os , const Bass & b) 
			//{
			//	os 
			//		<< static_cast<int>(b.wave()) 
			//		<< ", " 
			//		<< b.freq();
			//	return os;
			//}

			struct TB303 : Bass
			{
				TB303 () {}
				TB303 (Wave w, double f) :
					Bass {w, f}
				{}			
			};

			int main();
		}

		namespace s11
		{
			class m_vector
			{
				int
					sz;
				double
					* elem;
			public :
				m_vector (int s);
				~m_vector() 
				{
					delete[] elem;
				}
					
				int size() const;
				double get(int n) const
				{
					return elem[n];
				}
				void set(int n, double d) 
				{
					elem[n] = d;
				}
			};
		}

		namespace s12
		{
			int main();
		}

		namespace s13
		{
			int main();
		}

		namespace s14
		{
			int main();
		}

		namespace s15
		{
			int main();
		}

		namespace s16
		{
			struct m_Link
			{
				string
					value;
				m_Link
					* prev,
					* succ;
				m_Link (const string & v, m_Link * p = nullptr, m_Link * s = nullptr) :
					value {v},
					prev {p},
					succ {s}
				{}
				/// https://github.com/vitalispopoff/DSA_LectureAnalysis/wiki/3.2-Doubly-linked-lists
				m_Link * insert (m_Link * p, m_Link * n);
				m_Link * add (m_Link * p, m_Link * n);
				m_Link * erase (m_Link * p);
				m_Link * find (m_Link * p, const string & s);
				m_Link * advance (m_Link * p, int n);
				void print_all(m_Link * p);
			};
			int main();
		}

		namespace s17
		{
			/// m_Link functions (at least part of em) may have been thought 
			///to be declared outside the m_Link class...
			int main();
		}
	}
}