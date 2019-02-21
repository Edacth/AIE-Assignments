using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO;
using Craft2Git;
using Newtonsoft;

namespace Craft2Git
{
    public class PackList : ObservableCollection<PackEntry>
    {
        public PackList()
        {
          
            
        }
    }


    public partial class MainWindow : Window
    {
        PackList[] leftListGroup;
        string defaultFilePath = "C:/Users/s189062/Desktop/Addon Source/";
        string leftFilePath = "C:/Users/s189062/Desktop/Addon Source/";
        string rightFilePath = "C:/Users/s189062/Desktop/Addon Destination";
        int leftTabSelected = 0;
        Binding leftBinding1;
        Binding leftBinding2;
        Binding leftBinding3;
        Binding leftBinding4;

        public MainWindow()
        {
            ////////////////////
            //Left Side init////
            ////////////////////
            
            leftListGroup = new PackList[4];
            for (int i = 0; i < leftListGroup.Length; i++)
            {
                leftListGroup[i] = new PackList();
            }
            leftBinding1 = new Binding();
            leftBinding2 = new Binding();
            leftBinding3 = new Binding();
            leftBinding4 = new Binding();
            leftBinding1.Source = leftListGroup[0];
            leftBinding2.Source = leftListGroup[1];
            leftBinding3.Source = leftListGroup[2];
            leftBinding4.Source = leftListGroup[3];
            
            InitializeComponent();

            txtbox_left.Text = defaultFilePath;


            //list_left.SetBinding(ListBox.ItemsSourceProperty, leftBinding1);
            UpdateLeftFocus();
        }

        private void LeftCopy(object sender, RoutedEventArgs e)
        {
            string sourceFilePath = leftListGroup[leftTabSelected][list_left.SelectedIndex].filePath;
            string destFilePath = rightFilePath;
            //DirectoryCopy("C:/Users/s189062/Desktop/Addon Source/Vanilla_Behavior_Pack_1.9.0", "C:/Users/s189062/Desktop/Addon Destination/Vanilla_Behavior_Pack_1.9.0", true);
            DirectoryCopy("C:/Users/s189062/Desktop/Addon Source/Vanilla_Behavior_Pack_1.9.0", "C:/Users/s189062/Desktop/Addon Destination/Vanilla_Behavior_Pack_1.9.0", true);
        }

        private void loadPacks(string filePath)
        {

            ////////////////////
            //Behavior packs////
            ////////////////////
            string[] subDirectories;
            try
            {
                subDirectories = Directory.GetDirectories(filePath + "/development_behavior_packs");
            }
            catch (Exception)
            {

                return;
            }
            for (int i = 0; i < subDirectories.Length; i++)
            {
                string filePathAppended = subDirectories[i] + "/manifest.json";
                if (File.Exists(filePathAppended))
                {

                    string contents = File.ReadAllText(filePathAppended);
                    PackEntry newEntry = Newtonsoft.Json.JsonConvert.DeserializeObject<PackEntry>(contents);
                    newEntry.filePath = filePathAppended;

                    newEntry.iconPath = subDirectories[i] + "/pack_icon.png";

                    leftListGroup[0].Add(newEntry);
                }
            }
            ////////////////////
            //Resource packs////
            ////////////////////
            try
            {
                subDirectories = Directory.GetDirectories(filePath + "/development_resource_packs");
            }
            catch (Exception)
            {
                return;
            }
            for (int i = 0; i < subDirectories.Length; i++)
            {
                string filePathAppended = subDirectories[i] + "/manifest.json";
                if (File.Exists(filePathAppended))
                {

                    string contents = File.ReadAllText(filePathAppended);
                    PackEntry newEntry = Newtonsoft.Json.JsonConvert.DeserializeObject<PackEntry>(contents);
                    newEntry.filePath = filePathAppended;

                    newEntry.iconPath = subDirectories[i] + "/pack_icon.png";

                    leftListGroup[1].Add(newEntry);
                }
            }
            ////////////////////
            //Uncategorized/////
            ////////////////////
            try
            {
                subDirectories = Directory.GetDirectories(filePath);
            }
            catch (Exception)
            {

                return;
            }
            for (int i = 0; i < subDirectories.Length; i++)
            {
                string filePathAppended = subDirectories[i] + "/manifest.json";
                if (File.Exists(filePathAppended))
                {

                    string contents = File.ReadAllText(filePathAppended);
                    PackEntry newEntry = Newtonsoft.Json.JsonConvert.DeserializeObject<PackEntry>(contents);
                    newEntry.filePath = filePathAppended;

                    newEntry.iconPath = subDirectories[i] + "/pack_icon.png";

                    leftListGroup[3].Add(newEntry);
                }
            }
        }

        private void txtbox_left_TextChanged(object sender, TextChangedEventArgs e)
        {
            leftFilePath = txtbox_left.Text;
            leftListGroup[0].Clear();
            Console.WriteLine("Ran");
            loadPacks(leftFilePath);

        }

        private void LeftTabChanged(object sender, RoutedEventArgs e)
        {
            
            if (tab_leftBehavior.IsSelected)
            {
                leftTabSelected = 0;
            }
            else if (tab_leftResource.IsSelected)
            {
                leftTabSelected = 1;
            }
            else if (tab_leftWorld.IsSelected)
            {
                leftTabSelected = 2;
            }
            else if (tab_leftUncat.IsSelected)
            {
                leftTabSelected = 3;
            }
            UpdateLeftFocus();
        }

        private void UpdateLeftFocus()
        {
            switch (leftTabSelected)
            {
                case 0:
                    list_left.SetBinding(ListBox.ItemsSourceProperty, leftBinding1);
                    break;
                case 1:
                    list_left.SetBinding(ListBox.ItemsSourceProperty, leftBinding2);
                    break;
                case 2:
                    list_left.SetBinding(ListBox.ItemsSourceProperty, leftBinding3);
                    break;
                case 3:
                    list_left.SetBinding(ListBox.ItemsSourceProperty, leftBinding4);
                    break;
                default:
                    list_left.SetBinding(ListBox.ItemsSourceProperty, leftBinding1);
                    break;
            }
        }

        private static void DirectoryCopy(string sourceDirName, string destDirName, bool copySubDirs)
        {
            // Get the subdirectories for the specified directory.
            DirectoryInfo dir = new DirectoryInfo(sourceDirName);

            if (!dir.Exists)
            {
                throw new DirectoryNotFoundException(
                    "Source directory does not exist or could not be found: "
                    + sourceDirName);
            }

            DirectoryInfo[] dirs = dir.GetDirectories();
            // If the destination directory doesn't exist, create it.
            if (!Directory.Exists(destDirName))
            {
                Directory.CreateDirectory(destDirName);
            }

            // Get the files in the directory and copy them to the new location.
            FileInfo[] files = dir.GetFiles();
            foreach (FileInfo file in files)
            {
                string temppath = (destDirName + "/" + file.Name);
                file.CopyTo(temppath, false);
            }

            // If copying subdirectories, copy them and their contents to new location.
            if (copySubDirs)
            {
                foreach (DirectoryInfo subdir in dirs)
                {
                    string temppath = (destDirName + "/" + subdir.Name);
                    DirectoryCopy(subdir.FullName, temppath, copySubDirs);
                }
            }
        }

    }

    
}
