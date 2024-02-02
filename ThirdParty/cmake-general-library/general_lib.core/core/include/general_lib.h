#ifndef __GENERAL_LIB__
#define __GENERAL_LIB__

// standard headers
#include <Windows.h>
#include <process.h>
#include <chrono>
#include <memory>
#include <ctime>

// local headers
#include "core_EXPORT.h"
#include "structs.h"

// enable C / C++ linkage
#ifdef __cplusplus
extern "C" {
#endif

	namespace core
	{
		// foward declerations 
		class settings;
		class resouce_handle;

		class CORE_EXPORT general_lib
		{
		public:

			
			general_lib() = delete;
			explicit general_lib(const core::properties& properties);
			~general_lib();
				
			void configure(const core::properties & properties);
			void register_callback(buffer_ready_callback buffer_ready_callback);
			void work();

			// inline functions
			inline time_t general_lib::get_local_time() const { return time(nullptr); }
			inline const char* general_lib::parse_local_time(time_t ts) const { return std::asctime(std::localtime(&ts)); }

		private:

			std::unique_ptr<core::settings> settings_;
			std::unique_ptr<core::resouce_handle> resource_;
			core::buffer_ready_callback buffer_ready_callback_;
		};
	}

#ifdef __cplusplus
}
#endif

#endif // __GENERAL__LIB
