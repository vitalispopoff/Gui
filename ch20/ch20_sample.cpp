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
				for (int i = 0; i < jill_data -> size(); ++i)
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

			int main()
			{
				return 0;
			}
		}


		namespace try_this_01
		{
			double * get_from_jack (int * count) {return nullptr;}
			vector <double> get_from_jill () {return vector <double> {};}	// should return the reference ?

			void fct()
			{
				int 
					jack_count = 0;
				double 
					* jack_data = get_from_jack (& jack_count);

				vector <double> 
					jill_data = get_from_jill (); 
					//&& jill_data = get_from_jill();	// could it be like this ? how to make get_from_jill return by reference w/o a full implementation ?

				///... find the max in each of data sets delivered by the get_from_ functions

				double 
					h = -1,
					* jack_high,
					jill_high;

				for (int i = 0; i < jack_count; ++i)
					if (h < jack_data [i])
					{
						jack_high = & jack_data [i];
						h = jack_data [i];
					}

				h = -1;
				for (int i = 0; i < jill_data.size(); ++i)
					if (h < jill_data[i])
					{
						jill_high = jill_data [i];
						h = jill_data [i];
					}

				if (jill_high && jack_high)														// trying just to avoid the nullptrs
					cout
						<< "Jill's max :\t" << jill_high << '\n'
						<< "Jack's max :\t" << * jack_high << '\n';

				delete [] jack_data;
			}			
		}

		namespace s02
		{


		}
	}
}