#pragma once
#include "../_add_libs/PPP2Code/Gui.h"
//#include "../_add_libs/PPP2Code/Simple_window.h"

namespace ch15
{	
	namespace excercise
	{
		void keep_open();

		namespace e01
		{
			void main();
		}	

		/// needs a function pointer - have learned it yet?
		namespace e02
		{
			struct  Fct : Graph_lib::Function
			{
					Fct (
							Graph_lib::Fct f,
							double r1,
							double r2,
							Graph_lib::Point orig,
							int count = 100,
							double xscale = 25.,
							double yscale = 25.
						) :
						Function {f, r1, r2, orig, count, xscale, yscale}
					{
						r1_ = r1;
						r2_ = r2;
						orig_ = orig;
						count_ = count;
						xscale_ = xscale;
						yscale_ = yscale;
					}
					void reset();
				protected :
					double r1_, r2_, xscale_, yscale_;
					Graph_lib::Point orig_;
					int count_;
			};

			void main();
		}

		namespace e04
		{
		 void main();
		}

		namespace e05
		{
			void main();
		}
	}
}