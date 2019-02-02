using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Interfaces;

namespace Interfaces
{
    class Program
    {
        static void Main(string[] args)
        {
            ILogger logMachine = new ConsoleLogger();

            logMachine.SeverityMin = 0;
            logMachine.Log("I live!", 1);

            logMachine.SeverityMin = 2;
            logMachine.Log("I live!", 1);

            return;
        }
    }
}
