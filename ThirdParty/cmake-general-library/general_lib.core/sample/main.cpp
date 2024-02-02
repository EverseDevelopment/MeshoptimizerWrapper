#include "general_lib.h"

int main()
{
	core::properties properties = {};
	properties.file_name = "data";
	properties.counter = 1;

	std::unique_ptr<core::general_lib> obj_ptr = std::make_unique<core::general_lib>(properties);

	obj_ptr->work();
}