


// public headers
#include "general_lib.h"
#include "resource_handle.h"
// internal headers

#include "internal_structs.h"
#include "internal_definitions.h"


namespace core
{
	general_lib::general_lib(const core::properties& properties) :
		buffer_ready_callback_ { nullptr },
		resource_ { nullptr },
		settings_ { nullptr }
	{		
		configure(properties);		
	}

	general_lib::~general_lib()
	{
	}

	void general_lib::configure(const core::properties& properties)
	{
		settings_ = std::make_unique<core::settings>(properties);			
		resource_ = std::make_unique<core::resouce_handle>(settings_);
	}

	void general_lib::work()
	{
		core::resource_struct resource_struct  = {};
		resource_struct.timestamp = get_local_time();
	
		resource_->work(resource_struct);
		
		if (buffer_ready_callback_ != nullptr)
		{
			buffer_ready_callback_(resource_struct.counter);
		}		
	}

	void general_lib::register_callback(buffer_ready_callback buffer_ready_callback)
	{
		buffer_ready_callback_ = buffer_ready_callback;
	}
}