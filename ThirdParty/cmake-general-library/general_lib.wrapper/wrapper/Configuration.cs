using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GeneralLibWrapper
{
    public class Configuration
    {
        #region Properties

        public string FileName {get; set;}

        public int Counter { get; set; }

        public Dictionary<string, byte> FunctionMap { get; set; }

        #endregion

        #region Ctor

        public Configuration(
            string fileName,
            int allocSizeKB,
            Dictionary<string, byte> functionMap)
        {
            FileName = fileName;
            Counter = allocSizeKB;
            FunctionMap = functionMap;
        }
        #endregion
    }

    public class ConfigurationBuilder
    {
        private string m_fileName;
        private int m_counter;
        private Dictionary<string, byte> m_FunctionMap;

        #region Fields

        public ConfigurationBuilder Counter(int counter)
        {
            this.m_counter = counter;
            return this;
        }

        public ConfigurationBuilder FileName(string fileName)
        {
            this.m_fileName = fileName;
            return this;
        }

        public ConfigurationBuilder FunctionMap(Dictionary<string, byte> functionMap)
        {
            this.m_FunctionMap = functionMap;
            return this;
        }

        #endregion

        #region Builder Function

        public static implicit operator Configuration( ConfigurationBuilder cb)
        {
            return new Configuration(
                cb.m_fileName,
                cb.m_counter,
                cb.m_FunctionMap);
        }

        #endregion
    }
}
