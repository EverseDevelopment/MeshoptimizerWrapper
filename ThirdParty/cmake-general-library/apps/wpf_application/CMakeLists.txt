
set (WPF_APP_TARGET wpf_sample)
set (APP_FOLDER "applications")


include (CSharpUtilities)

set (PROPERTIES_SOURCES
    Properties/AssemblyInfo.cs
    Properties/Resources.Designer.cs
    Properties/Resources.resx
    Properties/Settings.Designer.cs
    Properties/Settings.settings
)

set (XAML_SOURCES
    App.xaml
    App.xaml.cs
    MainWindow.xaml
    MainWindow.xaml.cs
)

add_executable (${WPF_APP_TARGET}
	App.config
	${XAML_SOURCES}
	${PROPERTIES_SOURCES}
)


csharp_set_designer_cs_properties(
	${PROPERTIES_SOURCES}
)
csharp_set_xaml_cs_properties(
    ${XAML_SOURCES}
)

set_property (SOURCE App.xaml PROPERTY VS_XAML_TYPE "ApplicationDefinition")
set_property (TARGET ${WPF_APP_TARGET} PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION ${DOTNET_TARGET_FRAMEWORK_VERSION})
set_property (TARGET ${WPF_APP_TARGET} PROPERTY WIN32_EXECUTABLE TRUE)
set_property (TARGET ${WPF_APP_TARGET} PROPERTY VS_DOTNET_REFERENCES
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
	"WindowsFormsIntegration"
	"System.Windows"
	"System.Windows.Controls.Ribbon"
	"System.Windows.Forms"
	"System.Drawing"
)

set_target_properties (${WPF_APP_TARGET} PROPERTIES FOLDER ${APP_FOLDER}/${WPF_APP_TARGET})

add_dependencies (${WPF_APP_TARGET} ${LIBRARY_CSHARP_NAME})