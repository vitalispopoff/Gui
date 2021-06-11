#include "ch17.h"

namespace ch17
{
	namespace excercise
	{
		using ch17::keep_open;
		namespace e01
		{
			void to_lower (char * s)
			{
				for (char * c = s; * c != 0; ++c)
					if (* c > 64 && * c < 90)
						* c+= 32;
			}

			int main()
			{				
				string 
					s = "StrIng_S" + char(0);
				char
					* p = & s[0];
				to_lower (p);
				cout 
					<< s;
				return keep_open();
			}
		}
	}
}