include (CSharpUtilities)

add_library (${LIBRARY_CSHARP_NAME} 
	${LIBRARY_TYPE}
		GeneralLibWrapper.cs
		Configuration.cs	
		Properties/AssemblyInfo.cs
)
	
csharp_set_designer_cs_properties(
	Properties/AssemblyInfo.cs
)

set_property (TARGET ${LIBRARY_CSHARP_NAME} PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION ${DOTNET_TARGET_FRAMEWORK_VERSION})
set_property (TARGET ${LIBRARY_CSHARP_NAME} PROPERTY WIN32_EXECUTABLE TRUE)
set_property (TARGET ${LIBRARY_CSHARP_NAME} PROPERTY VS_DOTNET_REFERENCES
	"Microsoft.CSharp"
	"PresentationCore"
	"PresentationFramework"
	"System"
	"System.Core"
	"System.Data"
	"System.Data.DataSetExtensions"
	"System.Net.Http"
	"System.Xaml"
	"System.Xml"
	"System.xml.Linq"
	"WindowsBase"
)

set_target_properties (${LIBRARY_CSHARP_NAME} PROPERTIES FOLDER ${CMAKE_PROJECT_NAME}/${LIBRARY_CSHARP_NAME})

add_dependencies (${LIBRARY_CSHARP_NAME} ${LIBRARY_BRIDGE_CLI_NAME})