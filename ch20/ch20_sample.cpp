#include "ch20.h"

namespace ch20
{
	namespace sample
	{
		namespace s01
		{
			/// whatever the implementations for the get_from_ functions are there...
			double * get_from_jack (int * count) {return nullptr;}
			vector <double> * get_from_jill () {return nullptr;}

			void fct()
			{
				int 
					jack_count = 0;
				double 
					* jack_data = get_from_jack (& jack_count);

				vector <double> 
					* jill_data = get_from_jill();

				//...

				delete [] jack_data;
				delete jill_data;			
			}

			int main()
			{
				return 0;
			}
		}
	}
}