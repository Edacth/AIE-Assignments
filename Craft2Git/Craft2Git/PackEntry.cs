using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media.Imaging;

namespace Craft2Git
{

    public class PackEntry
    {
        public int format_version { get; set; }
        public Header header { get; set; }
        public Module[] modules { get; set; }
        public Dependency[] dependencies { get; set; }
        public string filePath { get; set; }
        public string iconPath { get; set;} 
        //public PackEntry(string _name)
        //{
        //    //header.name = new string;
        //    header.name = _name;
        //}
    }

    public class Header
    {
        public string description { get; set; }
        public string name { get; set; }
        public string uuid { get; set; }
        public int[] version { get; set; }
    }

    public class Module
    {
        public string description { get; set; }
        public string type { get; set; }
        public string uuid { get; set; }
        public int[] version { get; set; }
    }

    public class Dependency
    {
        public string uuid { get; set; }
        public int[] version { get; set; }
    }

}
