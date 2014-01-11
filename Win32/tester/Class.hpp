#ifndef _ENUM_HPP_
#define _ENUM_HPP_

namespace what
{
	class tests
	{
	public:
		static enum t
		{
			one,
			two, 
			three, 
			four
		};

		int static getValue( tests::t enum_in);
	};

};

#endif