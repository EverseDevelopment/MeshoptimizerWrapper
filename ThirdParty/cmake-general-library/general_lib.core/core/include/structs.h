#ifndef __STRUCTS__
#define __STRUCTS__

// standard headers
#include <string>
#include <unordered_map>

// local headers
#include "core_EXPORT.h"

// enable C / C++ linkage
#ifdef __cplusplus
extern "C" {
#endif

namespace core
{
	typedef void(__stdcall *buffer_ready_callback)(unsigned char);

	// set struct aligment 
	#pragma pack(1)
	struct CORE_EXPORT properties
	{
		const char* file_name;
		unsigned int counter;
		std::unordered_map<std::string, unsigned char> func_map;
	};
}

#ifdef __cplusplus
}
#endif

#endif // __STRUCTS__ 
