#include "ch14.h"

namespace ch14
{
	namespace sample
	{
		namespace s01
		{
			Shape::Shape (initializer_list<Point> lst)
			{
				for (Point p : lst) 
					add(p);
			}

			void Shape::set_color (Color col)
			{
				lcolor = col;
			}
			Color Shape::color() const
			{
				return lcolor;
			}
			void Shape::add (Point p)
			{
				points.push_back (p);
			}
			void Shape::set_point(int i, Point p)
			{
				points[i] = p;
			}
			Point Shape::point (int i) const
			{
				return points[i];
			}
			int Shape::number_of_points () const
			{
				return points.size();
			}

			void Shape::draw () const
			{
				/// set color and style to those of shape object
				Fl_Color oldc = fl_color();
				fl_color (lcolor.as_int());
				fl_line_style (ls.style(), ls.width());
				/// draw stuff
				draw_lines ();
				/// reset color and style to fltk defaults
				fl_color (oldc);
				fl_line_style (0);
			}

			void Shape::draw_lines() const
			{}

			void Shape::move (int dx, int dy)
			{
				for (int i = 0; i < points.size(); ++i)
				{
					points[i].x += dx;
					points[i].y += dy;
				}
			}
		}

		namespace s02
		{
			void main()
			{
				S0
					s0 {"original"};
				S1
					s1 {"copy"};

				S0 (s1).funk();	// calls S0::funk();
				
				s0 = s1;

				s0.funk();	// calls S0::funk()
			}

		}

		namespace s03
		{
			void call (const B & b)
			{
				b.f();
				b.g();
				cout 
					<< endl;
			}
			void main()
			{
				B 
					b;
				D
					d;
				DD
					dd;
				
				call (b);
				call (d);
				call (dd);

				cout 
					<< "\n----------------------------\n";

				b.f();											/// prints "B::f"
				b.g();											/// prints "B::g"

				cout 
					<< "\n----------------------------\n";

				d.f();											/// prints "D::f"
				d.g();											/// prints "D::g"

				B(d).f();										/// prints "B::f"
				B(d).g();										/// prints "B::g"

				cout 
					<< "\n----------------------------\n";

				B(dd).f();										/// prints "B::f"
				B(dd).g();										/// prints "B::g"

				D(dd).f();										/// prints "D::f"
				D(dd).g();										/// prints "D::g"

				dd.f();											/// prints "DD::f"
				dd.g();											/// prints "DD::g"

				cout 
					<< endl;

			}
		}

		namespace s04
		{
			struct B
			{
				virtual void f () const {cout << "B::f";}
						void g () const {cout << "B::g";}
			};
			struct D : B
			{
						void f () const override {cout << "D::f";}
				//		void g ()		override {cout << "D::g";}	/// attempt overriding a not delcared function (in B)
			};
			struct DD : D
			{
				//		void f ()		override {cout << "DD::f";}	/// attempt overriding a not delcared function (in D)
				//		void g () const override {cout << "DD::g";} /// attempt overriding a not delcared function (in D)
			};



		}

		namespace s05
		{	
			void main()
			{
				//A	a;		/// err C2259
				//a.f();	/// err C2039
				//a.g();	/// err C2039

				B	b;		
				b.foo();

				//C	c;		/// err C2259
				//c.f();	/// err C2039
				//c.g();	/// err C2039

				D	d;
				d.foo();
				d.bar();

				E	e;
				//e.foo();	/// err C2247

				F	f;
				//f.foo();	/// err C2247
				//f.bar();	/// err C2247
			}
		}

		namespace s06
		{
			void main()
			{
				C1 c1;
				c1.f();
				C0
					& c = c1;
				
				c.f();	//this one won't work - f() not because it's virtual, but beccause it's private 
			}

		}

		namespace s07
		{
			void main()
			{
				B b;
				b.pub();
				b.prot();
				//b.priv();	// inaccessible by definition

				//C c;
			}
		}
	}
}