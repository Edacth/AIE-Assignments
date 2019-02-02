using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interfaces
{
    interface ILogger
    {
        void Log(string message, int severity);
        void Assert(bool condition, string message, int severity);
        int SeverityMin { get; }
    }
}
