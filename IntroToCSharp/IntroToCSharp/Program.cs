using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IntroToCSharp
{
    class Program
    {
        public static List<string> blacklist = new List<string>() {
                  "carter", "dick", "voldimort", "fuck", "x", "shit"
            };
        static void Main(string[] args)
        {
            

            Console.WriteLine("Please enter a username");
            string username = Console.ReadLine();

            Console.WriteLine("---Welcome to Chat.exe---");


            while (true)
            {
                string input = Console.ReadLine();
                string[] words = new string[10];

                int startIndex = 0;
                int wordsIndex = 0;
                while (startIndex < input.Length)
                {
                    int nextSpace = input.IndexOf(" ", startIndex);
                    if (nextSpace == -1)
                    {
                        nextSpace = input.Length;
                    }
                    
                    words[wordsIndex] = input.Substring(startIndex, nextSpace - startIndex);
                    startIndex = nextSpace + 1;
                    wordsIndex++;
                }
                
                if (input.StartsWith("/"))
                {
                    switch (words[0])
                    {
                        case "/blacklist":
                            switch (words[1])
                            {
                                case "add":
                                    if (words[2] != null)
                                    {
                                        blacklist.Add(words[2].ToLower());
                                        Console.WriteLine("[SYSTEM]: " + words[2] + " has been added to the blacklist.");
                                        break;
                                    }
                                    Console.WriteLine("[SYSTEM]: Missing fields");
                                    break;

                                case "remove":
                                    if (words[2] != null)
                                    {
                                        removeFromBlacklist(words[2].ToLower());
                                        Console.WriteLine("[SYSTEM]: " + words[2] + " has been removed from the blacklist.");
                                        break;
                                    }
                                    Console.WriteLine("[SYSTEM]: Missing fields");
                                    break;

                                default:
                                    Console.WriteLine("[SYSTEM]: Usage: /blacklist <add:remove> <entry>");
                                    break;
                            }
                            break;

                        case "/repeat":
                            int x = 0;
                            Int32.TryParse(words[2], out x);
                            for (int i = 0; i < x; i++)
                            {
                                Console.WriteLine("[SYSTEM]: " + words[1]);
                            }
                            break;

                        case "/name":
                            if (words[1] != null)
                            {
                                username = words[1];
                                Console.WriteLine("Name changed to " + username);
                                break;
                            }
                            Console.WriteLine("[SYSTEM]: Missing fields");
                            break;

                        default:
                            Console.WriteLine("[SYSTEM]: Command not recognized.");
                            break;
                    }
                }
                else
                {
                    for (int i = 0; i < blacklist.Count(); i++)
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

        public static void removeFromBlacklist(string entry)
        {
            blacklist.RemoveAll(x=> { return x == entry; });
        }
    }
}
