#ifndef __RESOURCE_HANDLE__
#define __RESOURCE_HANDLE__

// standard library
#include <memory.h>

// local headers
#include "internal_structs.h"

namespace core
{
	class resouce_handle
	{
	public:

		resouce_handle() = delete;
		explicit resouce_handle(const std::unique_ptr<core::settings>& settings);
		void resouce_handle::work(core::resource_struct& resource_struct);
		~resouce_handle() = default;

		/*
		resouce_handle() = delete;
		explicit resouce_handle(const core::properties& properties);
		~resouce_handle();
		void work(const core::resource_struct& resource_struct);
		*/
		
	private:
		int counter_;	
		std::string payload_;
	};
}


#endif // __INTERNAL_DEFINITIONS__
