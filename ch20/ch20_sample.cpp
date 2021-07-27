#include "ch20.h"

#include <array>
#include <iterator>

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

				///... find the max in each of data sets delivered by the get_from_ functions

				double 
					h = -1,
					* jack_high = nullptr,
					* jill_high = nullptr;

				for (int i = 0; i < jack_count; ++i)
					if (h < jack_data [i])
					{
						jack_high = & jack_data [i];
						h = jack_data [i];
					}

				h = -1;
				for (int i = 0; i < (int) jill_data -> size(); ++i)
					if (h < (* jill_data) [i])
					{
						jill_high = & (* jill_data) [i];
						h = (* jill_data) [i];
					}

				if (jill_high && jack_high)														// trying just to avoid the nullptrs
					cout
						<< "Jill's max :\t" << * jill_high << '\n'
						<< "Jack's max :\t" << * jack_high << '\n';


				delete [] jack_data;
				delete jill_data;			
			}
		}

		namespace s02
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
					* jill_data = get_from_jill(),
					& v = * jill_data;

				///... find the max in each of data sets delivered by the get_from_ functions

				double 
					h = -1,
					* jack_high = nullptr,
					* jill_high = nullptr;

				for (int i = 0; i < jack_count; ++i)
					if (h < jack_data [i])
					{
						jack_high = & jack_data [i];
						h = jack_data [i];
					}

				h = -1;
				for (int i = 0; i < (int) v.size(); ++i)
					if (h < v [i])
					{
						jill_high = & v [i];
						h = v [i];
					}

				if (jill_high && jack_high)														// trying just to avoid the nullptrs
					cout
						<< "Jill's max :\t" << * jill_high << '\n'
						<< "Jack's max :\t" << * jack_high << '\n';


				delete [] jack_data;
				delete jill_data;			
			}		
		}

		namespace s03
		{
			/// whatever the implementations for the get_from_ functions are there...
			double * get_from_jack (int * count) {return nullptr;}
			vector <double> * get_from_jill () {return nullptr;}

			/// a common code block for both structures processed by the latter part of the fct()
			/// but instead of a single pointer we input two pointers defining the data structure processed, right?
			double * high (double * first, double * last)
			{
				double 
					h = -1,
					* high = nullptr;

				for (double * p = first; p != last; ++p)
					if (h < * p)
					{
						high = p;
						h = * p;
					}
				return high;
			}

			void fct()
			{
				int
					jack_count = 0;
				double 
					* jack_data = get_from_jack (& jack_count),
					* jack_high = high (jack_data, jack_data + jack_count);

				vector <double> 
					* jill_data = get_from_jill(),
					& v = * jill_data;
				double 
					* jill_high = high (& v[0], & v[0] + v.size());

				cout
					<< "Jill's max : \t" << * jill_high << '\n'
					<< "Jack's max : \t" << * jack_high << '\n';
			}
		}

		namespace try_this_02
		{
			// arr1 is [f1:e1), 
			// arr2  is [f2:f2+(e1-f1))
			// so...
			// f1 is arr1 start
			// e1 is arr1 end
			// f2 is arr2 start
			void print (int * f1, int * e1)
			{
				for (; f1 < e1; ++f1)
					cout
						<< * f1;
			}

			int main()
			{
				const int len {1};
				int 
					arr [len] = {},
					* b = arr,
					* e = & arr[len];

				print (b, e);

				return 0;
			}

		}
	}
}