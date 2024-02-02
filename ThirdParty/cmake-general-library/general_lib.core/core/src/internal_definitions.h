#ifndef __INTERNAL_DEFINITIONS__
#define __INTERNAL_DEFINITIONS__

namespace core
{
	// literals
	constexpr unsigned long long operator"" _kb(unsigned long long size)
	{
		return size * 1024;
	}

	class consts
	{
	public:
		static const int const_val = 1024;
	};

}

#endif // __INTERNAL_DEFINITIONS__
