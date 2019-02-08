using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace RoomEditor
{
    class Program
    {
        static void Main(string[] args)
        {
            string workingDir = System.IO.Directory.GetCurrentDirectory();
            
            string dllFileName = "/ExternalLib2.dll";
            string extClass = "ExternalLib2.MyExternalClass";
            string extMethod = "TestHelloWorld";

            //Load the external assembly
            Assembly ass = Assembly.LoadFile(workingDir + dllFileName);

            //Get the type of the desired class
            Type typ = ass.GetType(extClass);

            //Get the supporting method info so we can execute the method
            //MethodInfo meth = typ.GetMethod(extMethod);

            //Create instance of that object
            //object obj = Activator.CreateInstance(typ);

            //Invoke the method
            //meth.Invoke(obj, null);


            Room roomA = new Room();
            Wall wallA = new Wall();

            //Console.WriteLine(wallA.GetType());

            roomA.LoadData(@"testtext.txt");
            return;
        }
    }
}
