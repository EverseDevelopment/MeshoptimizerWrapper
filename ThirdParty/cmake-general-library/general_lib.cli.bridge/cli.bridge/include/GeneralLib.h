

#ifndef __GENERAL_LIB_CLI__
#define __GENERAL_LIB_CLI__

#include "ManagedObject.h"

namespace core
{
	class general_lib;
}

namespace CLI
{
	public ref struct Properties
	{
		System::String^ FileName;
		int AllocSizeKb;
		System::Collections::Generic::Dictionary<System::String^, unsigned char> ^FunctionMap;
	};

	private delegate void OnNativeBufferReadyCallback (unsigned char bufferId);
	public delegate void OnManagedBufferReadyCallback (unsigned char bufferId);

	public ref class GeneralLib : public ManagedObject<core::general_lib>
	{
	public:

		GeneralLib(Properties^ conf);
		~GeneralLib();

		OnNativeBufferReadyCallback^ m_OnNativeBufferReadyCallback;
		OnManagedBufferReadyCallback^ m_OnManagedBufferReadyCallback;

		void Register(OnManagedBufferReadyCallback^ onManagedBufferReadyCallback);
		void Work();

	private:
		void OnNativeBufferReadyInternal(unsigned char bufferId);
		void Config(Properties^ conf);
		core::properties ConvertToNativePropertiesPtr(Properties^ managed_conf);
		
	};
}		

#endif // __GENERAL_LIB_CLI__
