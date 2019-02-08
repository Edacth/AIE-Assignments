using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;

enum fileSection
{
    misc,
    blockDefintions,
    roomDefinitions
}
namespace RoomEditor
{
    class Room
    {
        int numberOfBlocks = 0;
        int roomSizeX = 0;
        int roomSizeY = 0;
        Type[] blockDefinitions;

        Object[,] roomLayout;
        Assembly ass;
        public Room()
        {

        }
        
        public void LoadData(string filePath)
        {
            int currentSection = -1;
            int k = 0;
            string[] lines = System.IO.File.ReadAllLines(@"testtext.txt");
            for (int i = 0; i < lines.Length; i++)
            {

                if (!lines[i].StartsWith("##")) //Excludes comments
                {
                    switch (lines[i]) //Sets the section variable
                    {
                        case "[misc]":
                            currentSection = 0;
                            i++;
                            break;
                        case "[block definitions]":
                            currentSection = 1;
                            i++;
                            break;
                        case "[room definitions]":
                            currentSection = 2;
                            i++;
                            break;
                        case "[end]":
                            currentSection = -1;
                            i++;
                            break;
                    }

                    if (currentSection == (int)fileSection.misc) //If we're in misc section
                    {
                        if (lines[i].StartsWith("numberofblocks"))
                        {
                            string[] dissected = lines[i].Split('=');
                            Int32.TryParse(dissected[1], out numberOfBlocks);
                            blockDefinitions = new Type[numberOfBlocks];
                        }
                        else if (lines[i].StartsWith("roomsize"))
                        {
                            string[] dissected = lines[i].Split(new Char[] { '=', ',' });
                            Int32.TryParse(dissected[1], out roomSizeX);
                            Int32.TryParse(dissected[2], out roomSizeY);
                            roomLayout = new object[roomSizeY, roomSizeX];
                        }
                    }
                    else if (currentSection == (int)fileSection.blockDefintions) //If we're in block definition section
                    {
                        string[] dissected = lines[i].Split('.', '=');
                        int j = 0;

                        Int32.TryParse(dissected[2], out j);
                        if (dissected[0].StartsWith("RoomEditor"))
                        {
                            blockDefinitions[j] = Type.GetType(dissected[0] + "." + dissected[1]);
                        }
                        else
                        {
                            string workingDir = System.IO.Directory.GetCurrentDirectory();
                            string dllFileName = "/" + dissected[0] + ".dll";

                            ass = Assembly.LoadFile(workingDir + dllFileName);
                            Type typ = ass.GetType(dissected[0] + "." + dissected[1]);

                            blockDefinitions[j] = typ;
                        }
                        
                    }
                    else if (currentSection == (int)fileSection.roomDefinitions)
                    {
                        //for (int j = 0; j < roomSizeY; j++)
                        {
                            for (int j = 0; j < roomSizeX; j++)
                            {
                                string readBlock = lines[i].ElementAt(j).ToString();
                                int readBlockInt = 0;
                                Int32.TryParse(readBlock, out readBlockInt);
                                object t = Activator.CreateInstance(blockDefinitions[readBlockInt]);
                                roomLayout[k, j] = t;
                                
                            }
                            k++;
                        }

                        
                        /*for (int j = 0; j < roomSizeX; j++)
                        {
                            lines[i]
                        }
                        Type typ =Type.GetType("RoomEditor.Wall");
                        roomLayout[0, 0] = (Block)Activator.CreateInstance(typ);*/

                    }

                }
            }
            for (int i = 0; i < numberOfBlocks; i++)
            {
                Console.WriteLine(blockDefinitions[i]);
            }
            
        }
    }
}
