#include <memory>
#include "general_lib.h"
#include "../include/GeneralLib.h"

namespace CLI
{
	GeneralLib::GeneralLib(Properties^ managed_conf)
		: ManagedObject(new core::general_lib(ConvertToNativePropertiesPtr(managed_conf)))
	{
	}

	GeneralLib::~GeneralLib()
	{
	}


	#pragma region Public Methods


	void GeneralLib::Register(OnManagedBufferReadyCallback^ OnManagedBufferReadyCallback)
	{
		// register managed to cli callback
		m_OnManagedBufferReadyCallback = OnManagedBufferReadyCallback;

		// register cli to native callback
		m_OnNativeBufferReadyCallback = gcnew OnNativeBufferReadyCallback(this, &GeneralLib::OnNativeBufferReadyInternal);
		System::IntPtr ptr = Marshal::GetFunctionPointerForDelegate(m_OnNativeBufferReadyCallback);
		core::buffer_ready_callback func_ptr = static_cast<core::buffer_ready_callback>(ptr.ToPointer());
		instance_->register_callback(func_ptr);
	}

	void GeneralLib::Work()
	{
		instance_->work();
	}


	#pragma endregion


	#pragma region Private Methods


	void GeneralLib::Config(Properties^ managed_conf)
	{
		core::properties native_properties = ConvertToNativePropertiesPtr(managed_conf);
		instance_->configure(native_properties);
	}

	void GeneralLib::OnNativeBufferReadyInternal(unsigned char bufferId)
	{
		m_OnManagedBufferReadyCallback(bufferId);
	}

	core::properties GeneralLib::ConvertToNativePropertiesPtr(Properties^ managed_conf)
	{
		core::properties tmp_properties = {};

		// primitive copy
		tmp_properties.file_name = string_to_char_array(managed_conf->FileName);
		tmp_properties.counter = managed_conf->AllocSizeKb;

		// collections
		for each (System::Collections::Generic::KeyValuePair<System::String^, unsigned char>
			kvp in managed_conf->FunctionMap)
		{
			tmp_properties.func_map.insert({ string_to_char_array(kvp.Key), kvp.Value });
		}

		return tmp_properties;
	}

	#pragma endregion

}