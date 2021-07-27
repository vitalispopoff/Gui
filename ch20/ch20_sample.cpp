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
				for (; f1 != e1; ++f1)
					cout
						<< * f1 << '\t';
				cout
					<< '\n';
			}

			void set (int * f1, int * e1, int val)
			{
				for (; f1 != e1; ++f1)
					* f1 = val;
			}

			void copy (int * f1, int * e1, int * f2)
			{
				for (; f1 != e1; ++f1, ++f2)
					* f2 = * f1;
			}

			const int 
				len {3};

			void main_0()
			{
				int 
					arr [len] = {};

				cout << arr << '\n';
				//print (b, e);
				print (arr, & arr[len]);

				cout << arr << '\n';
			}

			int main()
			{
				int
					arr1 [len],
					arr2 [len];

				set (arr1, &arr1[len], -1);

				print (arr1, & arr1[len]);
				copy (arr1, & arr1[len], arr2);

				print (arr2, & arr2[len]);

				return 0;
			}

		}

		namespace s04
		{
			template <typename Iterator>
				Iterator high (Iterator first, Iterator last)
			{
				Iterator 
					high = first;
				for (Iterator p = first; p != last; ++p)
					if (* high < * p) 
						high = p;
				return high;
			}

			// assuming both get_from_ functions implementations return proper pointers
			double * get_from_jack (int * count) {return nullptr;}
			vector <double> * get_from_jill () {return nullptr;}

			void fct()
			{
				int 
					jack_count = 0;	 // this one doesn't update, and ones it provides for the arr[0], and the other times for arr[len], right?
				vector <double> 
					* jill_data = get_from_jill(),
					& v = * jill_data;
				double 
					* jack_data = get_from_jack (& jack_count),
					* jack_high = high (jack_data, jack_data + jack_count),
					* jill_high = high (& v[0], & v[0] + v.size());
				cout
					<< "Jill's high\t" << * jill_high << '\n'
					<< "Jack's high\t" << * jack_high << '\n';
				delete [] jack_data;
				delete [] jill_data;
			}
		}

		namespace try_this_03
		{
			template <typename Iterator>
				Iterator high (Iterator first, Iterator last)
			{
				if (first && last && first != last)												// this will break the cycle lists tho
				{
					Iterator 
						high = first;
					for (Iterator p = first; p != last; ++p)
						if (* high < * p) 
							high = p;
					return high;
				}
				return nullptr;
			}
																								
			double * get_from_jack (int * count)												// assuming both get_from_ functions implementations return proper pointers
			{
				* count = 0;																	// returns the array length
				return (* count > 0) ? nullptr : nullptr;										// for true a proper pointer would be returned
			}
			vector <double> * get_from_jill () {return nullptr;}

			void fct()
			{
				vector <double> 
					* jill_data = get_from_jill();												// get_from_jill initializes the pointer regardless
					
				if (jill_data)																	// jil_data is null if get_from_jill doesn't deliver actual vector
				{
					vector <double>
						& v = * jill_data;
					double
						* jill_high = high (& v[0], & v[0] + v.size());

					jill_high
						? cout << "Jill's high\t" << * jill_high << '\n'
						: cout << "Jill's data not available";
				}
				else 
					cout << "Jill's data not available\n";				

				delete [] jill_data;															// there's no problem in deleting a nullptr, right?

				int 
					jack_count = 0;																// this one is to be revalued with each get_from_jack call
				double 
					* jack_data = (jack_count > 0) ? get_from_jack (& jack_count) : nullptr,
					* jack_high = jack_data ? high (jack_data, jack_data + jack_count) : nullptr;
				jack_data 
					? cout << "Jack's high\t" << * jack_high << '\n' 
					: cout << "Jack's data not available";
				delete [] jack_data;
			}

			int main()
			{
				fct();
				return 0;
			}
		}
	}
}