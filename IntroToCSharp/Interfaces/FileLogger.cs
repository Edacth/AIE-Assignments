using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Interfaces
{
    class FileLogger
    {
        FileStream FS = new FileStream("output.txt", FileMode.Append, FileAccess.Write);
        public int SeverityMin { get; set; }

        public void Log(string message, int severity)
        {
            //FS.Write()
        }

        public void Assert(bool condition, string message, int severity)
        {
        }
    }
}
