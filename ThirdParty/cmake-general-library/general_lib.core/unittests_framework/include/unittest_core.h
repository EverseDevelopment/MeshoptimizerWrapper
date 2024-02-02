
#ifndef __TEST_CONFIGURATION__
#define __TEST_CONFIGURATION__

#include <memory>
#include "json.hpp"

#include "unittests_framework_EXPORT.h"

using json = nlohmann::json;


// enable C / C++ linkage
#ifdef __cplusplus
extern "C" {
#endif

	namespace unittest_core 
	{
		 UNITTESTS_FRAMEWORK_EXPORT extern json configuration_json;
	}


#ifdef __cplusplus
}
#endif


#endif // !__TEST_CONFIGURATION__
