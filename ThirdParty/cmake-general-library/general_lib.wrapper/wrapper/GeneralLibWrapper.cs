using CLI;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GeneralLibWrapper
{
    public class GeneralLib
    {
        #region Properties

        public Configuration Configuration
        {
            get
            {
                return _configuration;
            }
        }

        #endregion

        #region Fields

        private readonly CLI.GeneralLib m_GeneralLib;
        private readonly Configuration _configuration;
        private OnManagedBufferReadyCallback m_OnBufferReadyEvent;

        #endregion

        #region Ctor

        public GeneralLib(Configuration config)
        {
            m_GeneralLib = new CLI.GeneralLib(
                new CLI.Properties()
                {
                    FileName = config.FileName,
                    AllocSizeKb = config.Counter,
                    FunctionMap = config.FunctionMap
                });
        }

        #endregion

        #region Public Methods

        public void Register(Action<byte> func)
        {
            m_OnBufferReadyEvent = new OnManagedBufferReadyCallback(func);
            m_GeneralLib.Register(m_OnBufferReadyEvent);
        }

        public void Work()
        {
            m_GeneralLib.Work();
        }
        #endregion
    }
}
