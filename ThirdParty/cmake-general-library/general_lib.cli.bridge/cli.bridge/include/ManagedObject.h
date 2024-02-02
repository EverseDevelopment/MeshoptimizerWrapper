#ifndef __MANAGED_OBJ__
#define __MANAGED_OBJ__

#include <memory>

namespace CLI
{
	template<class T>
	public ref class ManagedObject
	{

	protected:
		T* instance_;

	public:
		ManagedObject(T* instance) :
			instance_(instance)
			{ }

		virtual ~ManagedObject()
		{
			if (instance_ != nullptr)
			{
				delete instance_;
			}
		}

		!ManagedObject()
		{
		if (instance_ != nullptr)
			{
				delete instance_;
			}	
		}

		std::unique_ptr<T> GetInstance()
		{
			return std::make_unique<T>(instance_);
		}
	};

	using namespace System::Runtime::InteropServices;
	static const char* string_to_char_array(System::String^ string)
	{
		const char *str = (const char*)(Marshal::StringToHGlobalAnsi(string)).ToPointer();
		return str;
	}
}
#endif // __MANAGED_OBJ__ 