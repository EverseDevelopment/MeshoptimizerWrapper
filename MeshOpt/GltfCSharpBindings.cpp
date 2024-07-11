#include "GltfCsharpBindings.h"

#pragma comment(lib, "gltfpacklib.lib")
#pragma comment(lib, "meshoptimizer.lib")

#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

#include <string>
#include <vector>
#include <iostream>


extern int gltf_main(int argc, char** argv);
extern Settings defaults();
extern int gltfpack(const char* input, const char* output, const char* report, Settings settings);

namespace Gltf
{

    void GltfPack::commandline(array<System::String^>^ args)
    {
        std::vector<std::string> cparams = { "gltfpack_csharp" };
        std::vector<char*> cparams_ptr;
        for (size_t i = 0; i < args->Length; i++)
        {
            auto csStrTemp = args[i];
            std::string temp(msclr::interop::marshal_as<std::string>(csStrTemp));
            cparams.push_back(temp);
        }

        for (auto& string : cparams)
            cparams_ptr.push_back(&string.front());

        gltf_main(cparams_ptr.size(), cparams_ptr.data());
    }

    int GltfPack::gltfpack(System::String^ csInput, System::String^ csOutput, System::String^ csReport, const GltfSettings^ settings)
    {
        std::string input(msclr::interop::marshal_as<std::string>(csInput));
        std::string output(msclr::interop::marshal_as<std::string>(csOutput));
        std::string report(msclr::interop::marshal_as<std::string>(csReport));

        return ::gltfpack(input.c_str(), output.c_str(), report.c_str(), *settings->settings);
    }

    GltfSettings^ GltfSettings::defaults()
    {
        GltfSettings^ settings = gcnew GltfSettings();
        *settings->settings = ::defaults();
        return settings;
    }

}