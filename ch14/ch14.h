#pragma once

#include <iostream>

#include "../_add_libs/PPP2Code/Simple_window.h"	// still struggiling with single declarations

using namespace std;

namespace ch14
{
	namespace sample
	{
		namespace s01
		{
			class Shape
			{
				public:
					void		draw		() const;
					virtual void	move	(int, int);
					void		set_color	(Color);
					Color		color		() const;
					void		set_style	(Line_style);
					Line_style	style		() const;
					Point		point		(int) const;
					int	number_of_points	() const;
				
					/// prevent copying by declaring constructor deletion
					/// this is said to solve possilby nasty repercussions 
					/// when the pass by ref and copying would clash with one another
					/// (e.g. slicing, i.e. losing part of an object while copying as an argument in another objects definition)
					/// usual question tho: are there any scenarios for intentional exploiting the slicing effect ?
					Shape	(const Shape &) = delete;
					Shape & operator = (const Shape &) = delete;

					virtual ~Shape() {}
				protected:										/// preventing from using Shapes on its own - in Java terms - Shape is an abstract class
					Shape () {}
					Shape (initializer_list<Point>);

					virtual void draw_lines() const;			/// "virtual" declares the function to be overrideable
					void add (Point);
					void set_point(int, Point);
				private:
					vector<Point> 
						points	{};		/// adding the initialization braces to make clear its a field
					Line_style
						ls		{0};				
					Color 
						lcolor	{fl_color()},
						fcolor	{Color::Transparency::invisible};
			};
		}

		namespace s02
		{
			struct S0
			{
				S0 (string str) :
					s {str}
				{}
				virtual void funk()
				{
					cout << s;
				}
				string s;
			};

			struct S1 : S0
			{
				S1 (string str) :
					S0 {str}
				{}					
				
				void funk()
				{
					cout << "it's S1: ";
					S0::funk();
				}
			};

			void main();

		}

		///	overriding functions requires both declaration statements to be exactly the same
		namespace s03
		{
			struct B
			{
				virtual void f () const
				{
					cout
						<< "B::f"
						<< endl;
				}
				void g() const
				{
					cout
						<< "B::g"
						<< endl;

				}
			};
			struct D : B
			{
				void f () const		/// will override (the "virtual" statement goes only with the original declaration)
				{
					cout 
						<< "D::f"
						<< endl;
				}
				void g ()
				{
					cout 
						<< "D::g"
						<< endl;
				}
			};
			struct DD : D
			{
				void f()			/// won't override - virtual declaration contained 'const' statement
				{
					cout 
						<< "DD::f"
						<< endl;
				}	
				void g () const		/// shoul it override? not only original haven't declared 'const', it hasn't declared 'virtual' either.
				{
					cout 
						<< "DD::g"
						<< endl;
				}
			};
			
			void call (const B &);

			void main();
		}

		namespace s05
		{

		/// f() is directly defined as unimplementable in the A, 
		/// and since the A object couldn't execute the f(), the constructor won't deliver
		/// thus declaring whole class as abstract, 
		/// as the only solution is to derive a child class which overrides f().
			class A
			{
				public :
					virtual	void foo () = 0;	
					virtual void bar () = 0;
			};
		/// implementing both virtual functions B is a proper concrete class.
			class B
			{
				public :
					void foo() {};
					void bar() {};
			};

		/// C is abstract too, as all the functions declared unimplemented virtuals
		/// need their implementations expressed.
		/// f() still needs 'virtual' declaration, 
		/// because due to the lack of the g() implementation
		/// the C is still an abstract class - take a look at B, 
		/// which being concrete class, doesn't bother skiping the 'virtual' statements
			class C : A
			{
				public :
					void foo () {};
			};
		/// B delivers implementation for f(), once D implements g() it at last is concrete.
		/// D is struct to make its members public by default
			struct D : C
			{
				public :
					void bar () {};
			};

		/// E being class (members 'private' by default) cannot access C's not implemented foo()
		/// even tho it was public in the first place. from E's point of view foo() is private.
		/// take a look at D which easily access C's public foo()
			class E : C
			{
				public :
					void bar () {};
			};

		/// F can't access either of D's member functions, both of them are from F's point of view private. 
			class F : D
			{};

			void main();
		}

		namespace s06
		{
			class C0
			{
				public :
				virtual void f() = 0;
				//C0 () {}		// is an implicit conscrutor public by default?
			};

			struct C1 : C0
			{
				//C1 () {}	// if the C0 constructor is private this won't work
				void f() override {}

			};
			void main();
		}

		namespace s07
		{
			class A
			{
				public :
					virtual void pub() = 0;
				protected :
					virtual void prot() = 0;
				private :
					virtual void priv() = 0;					
			};

			class B
			{
				public :
					void pub() {}
				//protected :	// as 'public' here, prot() is accessible to be inherited from A , but not as 'protected'
					void prot() {}
				//private :		// priv is inaccessible regardless, thus skipable as virtual
					void priv() {}
			};

			/// C is abstract even tho subclasses will skip the nope() implementation.
			class C
			{
				private:
					virtual void nope() = 0;
			};			
			void main();
		}
	}

	namespace drill
	{
		namespace d01
		{
			class B1
			{
				public :
					virtual void vf();
					void f();
			};
			void main();
		}

		namespace d02
		{
			//class D1 : d01::B1		/// err C2243 - B1 is inaccessible - regardless on steps: struct B1, public constructor, D1 public constructor - fails
			struct D1 : d01::B1			/// the only solution working and the only step apparently necessary here is to make the D1 'struct'
			{
				public :
					void vf () override;	
			};
			void main();
		}

		namespace d03
		{
			void main();
		}

		namespace d04
		{
			using namespace d01;

			struct D1 : B1
			{
				public :
					void vf () override;
					void f ();				
			};
			void main();
		}

		namespace d05
		{
			class B1
			{
				public :
					virtual void pvf() = 0;	/// need "no implementation" ('= 0') declared explicitly
					virtual void vf();					
					void f();
			};

			struct D1 : B1
			{
				public :					/// don't need this in struct, right?
					void pvf() override;	/// in order to implement, must be declared, and to make D1 concrete must be implemented.
					void vf() override;
			};
			void main_0();
			void main();

		}

		namespace d06
		{
			struct D2 : d05::D1
			{
				public :
					void pvf() override;
			};

			void main();
		}

		namespace d07
		{
			class B2
			{
				/// declarations (e.g.constructors) not necessarily propagate 
				/// further down the inheritance line

				public :
				virtual void pvf () = 0;
			};
			struct D21 : B2		/// class ain't workin' really, switching to struct
			{			
				private :
					string s;
				protected :
					D21(){}				/// declared to help D22 with its constructor, this didn't work from the B2 level
				public :
					D21 (string str) :
						s {str}
					{}
					virtual void pvf () override;
			};
			struct D22 : D21
			{
				private : 
					int i;
				public :
					D22 (int in) :
						i {in}
					{}
					void pvf () override;
			};

			void f(B2 &);

			void main();
		}
	}

	namespace excercise
	{
		namespace e01
		{
			struct Arc : Graph_lib::Ellipse
			{
					Arc (Point p, int ww, int hh, double a1, double a2) :
						start {a1}, end {a2}, Ellipse {p, ww, hh}
					{
						set_color(Color::Color_type::black);
					}

					void draw_lines() const;
				private:
					double
						start,
						end;
			};

			struct Face : Circle
			{
				Face (Point p, int r) :
					Circle {p, r}
				{}

				void draw_lines() const;

			};
			struct Smiley : Face
			{
				Smiley (Point p, int r) :
					Face {p, r}
				{}
				void draw_lines() const;
			};

			struct Frowny : Face
			{
				Frowny (Point p, int r) :
					Face {p, r}
				{}
				void draw_lines() const;
			};

			void main();

		}

		namespace e02
		{
			// the intellisense alrady warning that shape constructor is inacccessible
			void main();		
		}

		namespace e04
		{
			struct Immobile_Circle : Circle
			{
				Immobile_Circle (Point p, int r) :
					Circle {p, r}
				{}
				void move(int dx, int dy) override {}
			};

			void main();
		}

		namespace e05
		{
			struct Striped_rectangle : Graph_lib::Rectangle
			{
				Striped_rectangle (Point p, int w, int h) :
					Rectangle {p, w, h}
				{}
				Striped_rectangle (Point p1, Point p2) :
					Rectangle {p1, p2}
				{}

				void draw_lines() const;
			};

			void main();
		}

		namespace e06a
		{
			struct Striped_circle : Circle
			{
				Striped_circle (Point p, int r) :
					Circle {p, r}
				{}
				void draw_lines () const;
			};
			void main();
		}

		namespace e06b
		{
			struct Striped_circle : Circle
			{
				Striped_circle (Point p, int r) :
					Circle {p, r}
				{}
				void draw_lines () const;
			};
			void main();
		}

		namespace e06
		{
			struct Striped_circle : Circle
			{
				Striped_circle (Point p, int r) :
					Circle {p, r}
				{}
				void draw_lines () const;
			};
			void main();
		}

		namespace e08a
		{
			struct Octagon : Circle
			{
				Octagon	(Point p, int r) :
					Circle {p, r}
				{}
				void draw_lines() const;
			};
			void main();
		}

		namespace e08
		{
			struct Octagon : Polygon
			{
					Octagon	(Point, int);								
			};

			void main();
		}

		namespace e11a
		{
			struct Binary_tree : Shape
			{
					Binary_tree (Point anchor, double length, double slope , int tiers = 0) :
						anchor_ {anchor}, length_ {length}, slope_ {slope}
					{						
						if (tiers > 0)
						{
							set_angle_factors(tiers);
							set_points(tiers);
						}
					}
					void draw_lines () const;
					void set_angle_factors (int);
					vector<double>
						angle_factors {0., 0., 1., -1.};

				private:
					Point
						anchor_;
					double
						length_,
						slope_;
					void set_points (int);
			};
		
			void main();
		}
		
		namespace e11
		{
			struct Binary_tree : Shape
			{
					Binary_tree (Point anchor, double length, double slope , int tiers = 0) :
						anchor_ {anchor}, length_ {length}, slope_ {slope}
					{						
						if (tiers > 0)
						{
							set_angle_factors(tiers);
							set_points(tiers);
						}
					}
					void draw_lines () const;
					void set_angle_factors (int);
					vector<double>
						angle_factors {0., 0., 1., -1.};

				protected:
					Point
						anchor_;
					double
						length_,
						slope_;
					void set_points (int);
			};
		
			void main();
		}

		namespace e12
		{
			struct Binary_tree : e11::Binary_tree
			{
				Binary_tree (Point anchor, double length, double slope , int tiers = 0) :
					e11::Binary_tree {anchor, length, slope, tiers}
				{}
				virtual void draw_lines() const;
				virtual void draw_drawing(Point, Point) const;
			};

			void main();
		}

		namespace e13
		{
			struct Binary_tree : e12::Binary_tree
			{
				Binary_tree (Point anchor, double length, double slope , int tiers = 0) :
					e12::Binary_tree {anchor, length, slope, tiers}
				{}
				virtual void draw_lines() const
				{
					e12::Binary_tree::draw_lines();
				}
				virtual void	draw_drawing	(Point, Point) const;
				virtual void	draw_branches	(Point, Point) const;
				virtual void	draw_nodes		(Point) const;
			};

			struct Arrow_tree : Binary_tree
			{
				Arrow_tree (Point anchor, double length, double slope , int tiers = 0) :
					Binary_tree {anchor, length, slope, tiers}
				{}
				void draw_branches(Point, Point) const;
			};

			void main();
		}

		namespace e14
		{
			struct Binary_tree : Shape
			{
					Binary_tree (Point, double, double, int);

					void draw_lines () const;
				protected:
					Point
						anchor_;
					double
						length_,
						slope_;
					vector<double>
						angle_factors {0., 0., 1., -1.},
						& af_ref = angle_factors;

					void set_points (int);
					void set_angle_factors (int);

					void draw_branches (vector<Point> &, int) const;
					void draw_nodes (vector<Point> &, int) const;
			};

			void main();
		}
	}
}