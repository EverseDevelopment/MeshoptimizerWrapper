using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using GeneralLibWrapper;

namespace WpfSample
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private GeneralLib m_GeneralLib;
        private byte m_BufferId = 0;

        public MainWindow()
        {
            InitializeComponent();
           
            // set wrapper using builder
            m_GeneralLib = new GeneralLib(

                new ConfigurationBuilder()
                    .FileName("temp.txt")
                    .Counter(10)
                    .FunctionMap(new Dictionary<string, byte>()
                        {
                            {"ParamName_1", 1 },
                            {"ParamName_2", 2 }
                        }
                    )
            );

            // register to callback
            m_GeneralLib.Register(OnBufferReady);


            lbl.Content = String.Format("Buffer id: {0}", m_BufferId);

        }

        private void OnBufferReady(byte id)
        {
            string message = String.Format("callback was triggered native code. Buffer id = {0}", id);
            Console.WriteLine(message);
            m_BufferId = id;

            lbl.Content = String.Format("Buffer id: {0}", m_BufferId);

        }

        private void Do_Work_Click(object sender, RoutedEventArgs e)
        {
            // do work method will trigger the registered method in callback
            m_GeneralLib.Work();

        }
        
    }
}
