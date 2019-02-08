using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Serialization;
using System.IO;
using System.Text;
using System.Reflection;

namespace Serialization
{
    class Program
    {
        static void Main(string[] args)
        {
            Enemy enemyA = new Enemy("demon_boss", 470, 700, 1000, true);
            string filePath = "demon_lord.txt";

            string serialized = Serialize(enemyA);
            WriteToFile(serialized, filePath);
            return;
        }

        public static string Serialize(object obj)
        {
            StringBuilder sb = new StringBuilder();
            sb.Append("<?");
            sb.AppendLine();
            Type typ = obj.GetType();
            List<PropertyInfo> props = new List<PropertyInfo>(typ.GetProperties());
            foreach (PropertyInfo property in props)
            {
                MethodInfo meth = property.GetMethod;
                sb.Append("[" + property.Name + "=" + meth.Invoke(obj, null) + "]\n");
                
            }
            sb.Append("?>");
            return sb.ToString();
        }

        public static void WriteToFile(string contents, string filePath)
        {
            // Delete the file if it exists.
            if (File.Exists(filePath))
            {
                //File.Delete(filePath);
            }

            File.WriteAllText(filePath, contents);
            Console.WriteLine(contents);
        }
    }
}
