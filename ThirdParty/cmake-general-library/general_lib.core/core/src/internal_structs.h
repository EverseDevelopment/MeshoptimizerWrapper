#ifndef __INTERNAL_STRUCTS__
#define __INTERNAL_STRUCTS__

// standard headers
#include <string>
#include <unordered_map>

// boost
#include <boost\bimap\bimap.hpp>

namespace core
{

	class settings
	{
		using settings_bimap_type = boost::bimaps::bimap<std::string, unsigned char>;
		

		public:

			settings() = delete;
			~settings() = default;

			explicit settings(const core::properties& properties)
			{
				file_name_ = properties.file_name;
				counter_ = properties.counter;

				for (const auto& kvp : properties.func_map)
				{
					func_bimap_.insert({ kvp.first, kvp.second });
				}
			}


			const std::string get_file_name() const { return file_name_; }
			const int get_counter() const { return counter_; }
			const settings_bimap_type get_settings_bimap() const { return func_bimap_; }

		private:
				std::string	file_name_;
				unsigned int counter_;
				settings_bimap_type func_bimap_;

	};

	struct resource_struct
	{
	private:
		static constexpr int PAYLOAD_SIZE = 10;

	public:
		time_t timestamp;
		char payload[PAYLOAD_SIZE];
		int counter;

		friend std::ostream& operator<<(std::ostream& os, const resource_struct& data);
	};

	inline std::ostream& operator<<(std::ostream& os, const resource_struct& data)
	{
		return os
			<< "[" << data.timestamp << "]"
			<< " payload: " << data.payload;
	}
}

#endif // __INTERNAL_DEFINITIONS__


