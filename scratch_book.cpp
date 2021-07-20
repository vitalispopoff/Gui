
#include <cstdlib>	// for the abs()
#include <iostream> // for the cout

namespace scratch_book
{
	using namespace std;

	double q_sqrt (float input)
	{
		const float 
			c = 1.5;
		float
			x {input * 0.5f},
			y {input};
		int 
			i {* ( int *) &y};

		i = 0x5f3759df - (i >> 1);
		y = * (float *) &i;
		
		y *= (c - (x * y * y));

		return 1 / y;
	}

	int main ()
	{
		int 
			i {0x5f3759df};
		float
			f {* (float *) &i};
			//g { bit_cast <float> (i)}; // bit_cast only since C++ 20


		cout
			<< fixed << i << '\n'
			<< fixed << f << '\n'
			//<< fixed << g << '\n'
			;
		return 0;
	}
}