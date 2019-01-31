using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IntroToCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] blacklist = { "carter", "dick", "voldimort", "fuck"};

            Console.WriteLine("Please enter a username");
            string username = Console.ReadLine();

            Console.WriteLine("---Welcome to Chat.exe---");
            /*for (int i = 0; i < args.Length; i++)
            {
                Console.WriteLine(args[i]);
            }*/

            while (true)
            {
                string input = Console.ReadLine();

                for (int i = 0; i < blacklist.Length; i++)
                {
                    if (input.ToLower().Contains(blacklist[i]))
                    {
                        string replacement = "";
                        for (int j = 0; j < blacklist[i].Length; j++)
                        {
                            replacement = string.Concat(replacement, "*");
                        }
                        
                        input = input.Replace(blacklist[i], replacement);
                    }
                }

                Console.WriteLine("<" + username + "> " + input);
            }
            
            
        }
    }
}
