
// standard headers
#include <iostream>

// public headers
#include "structs.h"

// implementation headers (private)
#include "internal_structs.h"
#include "internal_definitions.h"
#include "resource_handle.h"

namespace core
{
	
	resouce_handle::resouce_handle(const std::unique_ptr<core::settings>& settings) :
		counter_{ settings->get_counter() },
		payload_( settings->get_file_name() )
	{		
	}

	void resouce_handle::work(core::resource_struct& resource_struct)
	{		
		resource_struct.counter++;
		
		memcpy(resource_struct.payload,
			payload_.c_str(),
			sizeof(resource_struct.payload));

		std::cout << resource_struct;
	}
}
