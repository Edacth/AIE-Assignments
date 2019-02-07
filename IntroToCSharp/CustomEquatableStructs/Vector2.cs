using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CustomEquatableStructs
{
    struct Vector2 : IEquatable<Vector2>
    {
        public int x;
        public int y;

        public Vector2(int _x, int _y)
        {
            x = _x;
            y = _y;
        }

        public bool Equals(Vector2 other)
        {
            if (x == other.x && y == other.y)
            {
                return true;
            }
            return false;
        }

        public static bool operator ==(Vector2 a, Vector2 b)
        {
            if (a.x == b.x && a.y == b.y)
            {
                return true;
            }
            return false;
        }

        public static bool operator !=(Vector2 a, Vector2 b)
        {
            if (a.x != b.x || a.y != b.y)
            {
                return true;
            }
            return false;
        }

        public override Int32 GetHashCode()
        {
            Console.WriteLine(x ^ y);
            return x ^ y;
        }
    }
}
