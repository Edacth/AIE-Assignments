using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CustomEquatableStructs;

namespace CustomEquatableStructs
{
    class Program
    {
        static void Main(string[] args)
        {
            Vector2 vec2a = new Vector2(1, 2);
            Vector2 vec2b = new Vector2(1, 2);
            Vector2 vec2c = new Vector2(2, 1);

            Console.WriteLine(vec2a.x);

            Console.WriteLine(vec2a.Equals(vec2b));
            Console.WriteLine(vec2a.Equals(vec2c));

            Console.WriteLine(vec2a == vec2b);
            Console.WriteLine(vec2a == vec2c);

            Console.WriteLine(vec2a != vec2b);
            Console.WriteLine(vec2a != vec2c);

            vec2a.GetHashCode();
            return;
        }
    }
}
