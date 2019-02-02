using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Properties;

namespace IntroToCSharp
{
    class Properties
    {
        static void Main(string[] args)
        {
            /* PLAYER TESTER
            Player player1 = new Player();
            Console.WriteLine(player1.Name);
            Console.WriteLine(player1.Score);
            */

            /* VECTOR3 TESTER
            Vector3 vec3a = new Vector3(1f, 2f, 3f);
            Vector3 vec3b = new Vector3(3f, 4f, 5f);

            Vector3 vec3c = vec3a + vec3b;
            Vector3 vec3d = vec3a.Normalized;
            Console.WriteLine(vec3c.x.ToString() + " " + vec3c.y.ToString() + " " + vec3c.z.ToString());
            Console.WriteLine(vec3a.Magnitude);
            Console.WriteLine(vec3d.x.ToString() + " " + vec3d.y.ToString() + " " + vec3d.z.ToString());
            Console.WriteLine(Vector3.Dot(vec3a, vec3b));
            */

            GameState gState = new GameState();
            gState.CurrentState = (gameStates)1;
            return;
        }

    }

    class Player
    {
        string name = "Jeff";
        int fragCount = 2;
        int deathCount = 0;
        int totalDamage = 10;

        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                if (!string.IsNullOrEmpty(value))
                {
                    name = value;
                }
            }
        }

        public int Score
        {
            get
            {
                return (fragCount - deathCount) * 10;
            }
        }


    }

    
}
