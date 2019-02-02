using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interfaces
{
    class ConsoleLogger : ILogger
    {
        public int SeverityMin { get; private set; }

        public void Log(string message, int severity)
        {
            if (severity >= SeverityMin)
            {
                Console.WriteLine(message);
            }
        }

        public void Assert(bool condition, string message, int severity)
        {
            if (!condition && severity >= SeverityMin)
            {
                Console.WriteLine(message);
            }
        }


    }
}
