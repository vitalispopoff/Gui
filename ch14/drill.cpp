#include "ch14.h"

namespace ch14
{
	namespace drill
	{
		namespace d01
		{
			void B1::vf	()
			{
				cout
					<< "B1::vf()"
					<< endl;
			}
			void B1::f	()
			{
				cout
					<< "B1::f()"
					<< endl;
			}
			void main	()
			{
				B1 
					b1;
				b1.vf();
				b1.f();
			}
		}
		//	d01::main() result:
		///	B1::vf()
		///	B1::f()

		namespace d02
		{
			void D1::vf	()
			{
				cout 
					<< "D1:\t";
				B1::vf();
			}
			void main	()
			{
				D1 d;
				d.vf();
				d.f();
			}
		}
		//	d02::main() result:
		///	D1:     B1::vf()
		///	B1::f()

		namespace d03
		{
			using namespace d01;
			using namespace d02;
			void main()
			{
				D1 
					d;
				B1 
					& b = d;
				b.vf();
				b.f();
			}
		}

		//	d03::main() result:
		///	D1:     B1::vf()
		///	B1::f()

		namespace d04
		{
			void D1::vf ()
			{
				cout
					<< "D1:\t";
				B1::vf ();
			}
			void D1::f	()
			{
				cout
					<< "D1::f\t";
				B1::f();
			}
			void main()
			{
				B1
					b;
				b.vf();
				b.f();
				
				cout 
					<< "\n---------\n";
				D1 
					d;
				d.vf();
				d.f();

				cout 
					<< "\n---------\n";

				B1
					& b1 = d;
				b1.vf();
				b1.f();
			}
		}

		//	d04::main() result:
		///	B1::vf()
		///	B1::f()
		///
		///	---------
		///	D1:     B1::vf()
		///	D1::f   B1::f()
		/// ---------
		///	D1:     B1::vf()
		///	B1::f()
	
		namespace d05
		{
			void	B1::vf	()	{cout << "B1::vf()\n";}
			void	B1::f	()	{cout << "B1::f()\n";}

			void	D1::vf	()	{cout << "D1::f() :\t"; B1::vf();}

			/// main_0 just doesn't work at all - no wonder...
			void main_0()
			{
			///	err C2259 - no initializing object of an abstract class
				//B1 b;
				//b.pvf();
				//b.vf();
				//b.f();
				//cout << "\n------\n";

				D1 d;
				d.pvf();
				d.vf();
				d.f();
				cout << "\n------\n";
				B1	& b1 = d;
				b1.pvf();
				b1.vf();
				b1.f();
			}
			/// main_0() result:
			///	D1::pvf
			///	D1::f() :       B1::vf()
			///	B1::f()
			/// 
			///	------
			///	D1::pvf
			///	D1::f() :       B1::vf()
			///	B1::f()

			void	D1::pvf	()	{cout << "D1::pvf\n";}

			void main()
			{
			/// err C2259 - no initializing objects of an abstract class.
				//B1 b;
				//b.pvf();
				//b.vf();
				//b.f();
				//cout << "\n------\n";

				D1 d;
				d.pvf();
				d.vf();
				d.f();
				cout << "\n------\n";
				B1	& b1 = d;
				b1.pvf();
				b1.vf();
				b1.f();
			}
			///	main() result:
			///	D1::pvf
			///	D1::f() :       B1::vf()
			///	B1::f()
			/// 
			///	------
			///	D1::pvf
			///	D1::f() :       B1::vf()
			///	B1::f()

			/// implementation of D1::pfv() doesn't make difference, as long as it is delivered.
		}

		namespace d06
		{
			void D2::pvf()
			{
				cout << "D2::pvf() :\t"; d05::D1::vf();
			}
			void main()
			{
				D2	d;
				d.pvf();
				d.vf();
				d.f();
			}

		}

		namespace d07
		{
			void D21::pvf()
			{
				cout << s;
			}
			void D22::pvf()
			{
				cout << i;
			}
			void f(B2 & b)
			{
				b.pvf();
			}
			void main()
			{
				D21	
					d21	{"d21"};
				D22 
					d22	{22};
				B2
					& b1 = d21;
				b1.pvf();
				//b1 = d22;	// didn't work >_>
				B2
					& b2 = d22;
				b2.pvf();
			}
		}
	}
}