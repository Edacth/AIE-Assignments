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
using System.Windows.Forms;
using System.Drawing;
using System.Diagnostics;

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
        #region Class-wide Variables
        PackList[] leftListGroup;
        PackList[] rightListGroup;
        string defaultLeftFilePath = "C:\\Users\\s189062\\Desktop\\Addon Source";
        string defaultRightFilePath = "C:\\Users\\s189062\\Desktop\\Addon Destination";
        string leftFilePath = "C:\\Users\\s189062\\Desktop\\Addon Source";   
        string rightFilePath = "C:\\Users\\s189062\\Desktop\\Addon Destination";
        int leftTabSelected = 0;
        int rightTabSelected = 0;
        System.Windows.Data.Binding leftBinding1;
        System.Windows.Data.Binding leftBinding2;
        System.Windows.Data.Binding leftBinding3;
        System.Windows.Data.Binding leftBinding4;
        System.Windows.Data.Binding rightBinding1;
        System.Windows.Data.Binding rightBinding2;
        System.Windows.Data.Binding rightBinding3;
        System.Windows.Data.Binding rightBinding4;
        #endregion

        public MainWindow()
        {
            #region Left Side Init
            ////////////////////
            //Left Side init////
            ////////////////////

            leftListGroup = new PackList[4];
            for (int i = 0; i < leftListGroup.Length; i++)
            {
                leftListGroup[i] = new PackList();
            }

            leftBinding1 = new System.Windows.Data.Binding();
            leftBinding2 = new System.Windows.Data.Binding();
            leftBinding3 = new System.Windows.Data.Binding();
            leftBinding4 = new System.Windows.Data.Binding();
            leftBinding1.Source = leftListGroup[0];
            leftBinding2.Source = leftListGroup[1];
            leftBinding3.Source = leftListGroup[2];
            leftBinding4.Source = leftListGroup[3];


            #endregion

            #region Right Side Init
            ////////////////////
            //Right Side init///
            ////////////////////

            rightListGroup = new PackList[4];
            for (int i = 0; i < rightListGroup.Length; i++)
            {
                rightListGroup[i] = new PackList();
            }

            rightBinding1 = new System.Windows.Data.Binding();
            rightBinding2 = new System.Windows.Data.Binding();
            rightBinding3 = new System.Windows.Data.Binding();
            rightBinding4 = new System.Windows.Data.Binding();
            rightBinding1.Source = rightListGroup[0];
            rightBinding2.Source = rightListGroup[1];
            rightBinding3.Source = rightListGroup[2];
            rightBinding4.Source = rightListGroup[3];

            #endregion

            InitializeComponent();

            leftText.Text = defaultLeftFilePath;
            rightText.Text = defaultRightFilePath;
            leftList.SelectedIndex = leftTabSelected;
            rightList.SelectedIndex = rightTabSelected;

            UpdateLeftFocus();
            UpdateRightFocus();
        }

        private void LeftCopy(object sender, RoutedEventArgs e)
        {
            string sourceFilePath = System.IO.Path.GetDirectoryName(leftListGroup[leftTabSelected][leftList.SelectedIndex].filePath);
            string[] stringSeparators = new string[] { "\\" };
            string[] splitEntryPath = leftListGroup[leftTabSelected][leftList.SelectedIndex].filePath.Split(stringSeparators, StringSplitOptions.None);

            string destFilePath;
            if (leftTabSelected == 3)
            {
                destFilePath = System.IO.Path.Combine(rightFilePath, splitEntryPath[splitEntryPath.Length - 2]);
            }
            else
            {
                destFilePath = System.IO.Path.Combine(rightFilePath, splitEntryPath[splitEntryPath.Length - 3], splitEntryPath[splitEntryPath.Length - 2]);
            }
            DirectoryCopy(sourceFilePath, destFilePath, true);
            loadRightPacks(rightFilePath);
            if (rightList.SelectedIndex == -1)
            {
                rightList.SelectedIndex = 0;
            }
        }

        private void RightCopy(object sender, RoutedEventArgs e)
        {
            string sourceFilePath = System.IO.Path.GetDirectoryName(rightListGroup[rightTabSelected][rightList.SelectedIndex].filePath);
            string[] stringSeparators = new string[] { "\\" };
            string[] splitEntryPath = rightListGroup[rightTabSelected][rightList.SelectedIndex].filePath.Split(stringSeparators, StringSplitOptions.None);

            string destFilePath;
            if (rightTabSelected == 3)
            {
                destFilePath = System.IO.Path.Combine(leftFilePath, splitEntryPath[splitEntryPath.Length - 2]);
            }
            else
            {
                destFilePath = System.IO.Path.Combine(leftFilePath, splitEntryPath[splitEntryPath.Length - 3], splitEntryPath[splitEntryPath.Length - 2]);
            }
            DirectoryCopy(sourceFilePath, destFilePath, true);
            loadLeftPacks(leftFilePath);
            if (leftList.SelectedIndex == -1)
            {
                leftList.SelectedIndex = 0;
            }
        }

        private void loadLeftPacks(string filePath)
        {
            
            #region Behavior Packs
            ////////////////////
            //Behavior packs////
            ////////////////////
            string[] subDirectories;
            leftListGroup[0].Clear();
            try
            {
                subDirectories = Directory.GetDirectories(System.IO.Path.Combine(filePath, "development_behavior_packs"));

                for (int i = 0; i < subDirectories.Length; i++)
                {
                    string filePathAppended = System.IO.Path.Combine(subDirectories[i], "manifest.json");
                    if (File.Exists(filePathAppended))
                    {

                        string contents = File.ReadAllText(filePathAppended);
                        PackEntry newEntry = Newtonsoft.Json.JsonConvert.DeserializeObject<PackEntry>(contents);
                        newEntry.filePath = filePathAppended;

                        newEntry.iconPath = System.IO.Path.Combine(subDirectories[i], "pack_icon.png");

                        newEntry.loadIcon();
                        
                        leftListGroup[0].Add(newEntry);
                    }
                }
            }
            catch (Exception ex)
           {
                Console.WriteLine(ex);
                var st = new StackTrace(ex, true);
                Console.WriteLine(ex.ToString());
            }
            
            #endregion
            #region Resource Packs
            ////////////////////
            //Resource packs////
            ////////////////////
            leftListGroup[1].Clear();
            try
            {
                subDirectories = Directory.GetDirectories(System.IO.Path.Combine(filePath, "development_resource_packs"));

                for (int i = 0; i < subDirectories.Length; i++)
                {
                    string filePathAppended = System.IO.Path.Combine(subDirectories[i], "manifest.json");
                    if (File.Exists(filePathAppended))
                    {

                        string contents = File.ReadAllText(filePathAppended);
                        PackEntry newEntry = Newtonsoft.Json.JsonConvert.DeserializeObject<PackEntry>(contents);
                        newEntry.filePath = filePathAppended;

                        newEntry.iconPath = System.IO.Path.Combine(subDirectories[i], "pack_icon.png");

                        newEntry.loadIcon();

                        leftListGroup[1].Add(newEntry);
                    }
                }
            }
            catch (Exception)
            {


            }

            #endregion
            #region Uncategorized
            ////////////////////
            //Uncategorized/////
            ////////////////////
            leftListGroup[3].Clear();
            try
            {
                subDirectories = Directory.GetDirectories(filePath);

                for (int i = 0; i < subDirectories.Length; i++)
                {
                    string filePathAppended = System.IO.Path.Combine(subDirectories[i], "manifest.json");
                    if (File.Exists(filePathAppended))
                    {

                        string contents = File.ReadAllText(filePathAppended);
                        PackEntry newEntry = Newtonsoft.Json.JsonConvert.DeserializeObject<PackEntry>(contents);
                        newEntry.filePath = filePathAppended;

                        newEntry.iconPath = System.IO.Path.Combine(subDirectories[i], "pack_icon.png");

                        newEntry.loadIcon();

                        leftListGroup[3].Add(newEntry);
                    }
                }
            }
            catch (Exception)
            {

                
            }
            
            #endregion
        }

        private void loadRightPacks(string filePath)
        {

            #region Behavior Packs
            ////////////////////
            //Behavior packs////
            ////////////////////
            string[] subDirectories;
            rightListGroup[0].Clear();
            try
            {
                subDirectories = Directory.GetDirectories(System.IO.Path.Combine(filePath, "development_behavior_packs"));

                for (int i = 0; i < subDirectories.Length; i++)
                {
                    string filePathAppended = System.IO.Path.Combine(subDirectories[i], "manifest.json");
                    if (File.Exists(filePathAppended))
                    {

                        string contents = File.ReadAllText(filePathAppended);
                        PackEntry newEntry = Newtonsoft.Json.JsonConvert.DeserializeObject<PackEntry>(contents);
                        newEntry.filePath = filePathAppended;

                        newEntry.iconPath = System.IO.Path.Combine(subDirectories[i], "pack_icon.png");

                        newEntry.loadIcon();

                        rightListGroup[0].Add(newEntry);
                    }
                }
            }
            catch (Exception)
            {

            }

            #endregion
            #region Resource Packs
            ////////////////////
            //Resource packs////
            ////////////////////
            rightListGroup[1].Clear();
            try
            {
                subDirectories = Directory.GetDirectories(System.IO.Path.Combine(filePath, "development_resource_packs"));

                for (int i = 0; i < subDirectories.Length; i++)
                {
                    string filePathAppended = System.IO.Path.Combine(subDirectories[i], "manifest.json");
                    if (File.Exists(filePathAppended))
                    {

                        string contents = File.ReadAllText(filePathAppended);
                        PackEntry newEntry = Newtonsoft.Json.JsonConvert.DeserializeObject<PackEntry>(contents);
                        newEntry.filePath = filePathAppended;

                        newEntry.iconPath = System.IO.Path.Combine(subDirectories[i], "pack_icon.png");

                        newEntry.loadIcon();

                        rightListGroup[1].Add(newEntry);
                    }
                }
            }
            catch (Exception)
            {


            }

            #endregion
            #region Uncategorized
            ////////////////////
            //Uncategorized/////
            ////////////////////
            rightListGroup[3].Clear();
            try
            {
                subDirectories = Directory.GetDirectories(filePath);

                for (int i = 0; i < subDirectories.Length; i++)
                {
                    string filePathAppended = System.IO.Path.Combine(subDirectories[i], "manifest.json");
                    if (File.Exists(filePathAppended))
                    {

                        string contents = File.ReadAllText(filePathAppended);
                        PackEntry newEntry = Newtonsoft.Json.JsonConvert.DeserializeObject<PackEntry>(contents);
                        newEntry.filePath = filePathAppended;

                        newEntry.iconPath = System.IO.Path.Combine(subDirectories[i], "pack_icon.png");

                        newEntry.loadIcon();

                        rightListGroup[3].Add(newEntry);
                    }
                }
            }
            catch (Exception)
            {


            }

            #endregion
        }

        private void leftText_TextChanged(object sender, TextChangedEventArgs e)
        {
            leftFilePath = leftText.Text;
            loadLeftPacks(leftFilePath);
            

        }

        private void rightText_TextChanged(object sender, TextChangedEventArgs e)
        {
            rightFilePath = rightText.Text;
            loadRightPacks(rightFilePath);


        }

        private void LeftTabChanged(object sender, RoutedEventArgs e)
        {
            
            if (leftBehaviorTab.IsSelected)
            {
                leftTabSelected = 0;
            }
            else if (leftResourceTab.IsSelected)
            {
                leftTabSelected = 1;
            }
            else if (leftWorldTab.IsSelected)
            {
                leftTabSelected = 2;
            }
            else if (leftUncatTab.IsSelected)
            {
                leftTabSelected = 3;
            }
            UpdateLeftFocus();
        }

        private void RightTabChanged(object sender, RoutedEventArgs e)
        {

            if (rightBehaviorTab.IsSelected)
            {
                rightTabSelected = 0;
            }
            else if (rightResourceTab.IsSelected)
            {
                rightTabSelected = 1;
            }
            else if (rightWorldTab.IsSelected)
            {
                rightTabSelected = 2;
            }
            else if (rightUncatTab.IsSelected)
            {
                rightTabSelected = 3;
            }
            UpdateRightFocus();
        }

        private void UpdateLeftFocus()
        {
            switch (leftTabSelected)
            {
                case 0:
                    leftList.SetBinding(System.Windows.Controls.ListBox.ItemsSourceProperty, leftBinding1);
                    break;
                case 1:
                    leftList.SetBinding(System.Windows.Controls.ListBox.ItemsSourceProperty, leftBinding2);
                    break;
                case 2:
                    leftList.SetBinding(System.Windows.Controls.ListBox.ItemsSourceProperty, leftBinding3);
                    break;
                case 3:
                    leftList.SetBinding(System.Windows.Controls.ListBox.ItemsSourceProperty, leftBinding4);
                    break;
                default:
                    leftList.SetBinding(System.Windows.Controls.ListBox.ItemsSourceProperty, leftBinding1);
                    break;
            }
            leftList.SelectedIndex = 0;
        }

        private void UpdateRightFocus()
        {
            switch (rightTabSelected)
            {
                case 0:
                    rightList.SetBinding(System.Windows.Controls.ListBox.ItemsSourceProperty, rightBinding1);
                    break;
                case 1:
                    rightList.SetBinding(System.Windows.Controls.ListBox.ItemsSourceProperty, rightBinding2);
                    break;
                case 2:
                    rightList.SetBinding(System.Windows.Controls.ListBox.ItemsSourceProperty, rightBinding3);
                    break;
                case 3:
                    rightList.SetBinding(System.Windows.Controls.ListBox.ItemsSourceProperty, rightBinding4);
                    break;
                default:
                    rightList.SetBinding(System.Windows.Controls.ListBox.ItemsSourceProperty, rightBinding1);
                    break;
            }
            rightList.SelectedIndex = 0;
        }

        
        private static void DirectoryCopy(string sourceDirName, string destDirName, bool copySubDirs)
        {
            //The majority of this function is from MSDN
            //https://docs.microsoft.com/en-us/dotnet/standard/io/how-to-copy-directories

            // Get the subdirectories for the specified directory.
            DirectoryInfo sourceDir = new DirectoryInfo(sourceDirName);
            DirectoryInfo destDir = new DirectoryInfo(destDirName);
            if (!sourceDir.Exists)
            {
                return;
                throw new DirectoryNotFoundException(
                    "Source directory does not exist or could not be found: "
                    + sourceDirName);
            }

            if (destDir.Exists)
            {
                Directory.Delete(destDirName, true);
            }

            DirectoryInfo[] dirs = sourceDir.GetDirectories();
            // If the destination directory doesn't exist, create it.
            if (!Directory.Exists(destDirName))
            {
                Directory.CreateDirectory(destDirName);
            }

            // Get the files in the directory and copy them to the new location.
            FileInfo[] files = sourceDir.GetFiles();
            foreach (FileInfo file in files)
            {
                string temppath = System.IO.Path.Combine(destDirName, file.Name);
                file.CopyTo(temppath, false);
            }

            // If copying subdirectories, copy them and their contents to new location.
            if (copySubDirs)
            {
                foreach (DirectoryInfo subdir in dirs)
                {
                    string temppath = System.IO.Path.Combine(destDirName, subdir.Name);
                    
                    DirectoryCopy(subdir.FullName, temppath, copySubDirs);
                }
            }
        }

        private void leftOpenDialog(object sender, RoutedEventArgs e)
        {
            FolderBrowserDialog dialog = new FolderBrowserDialog();
            DialogResult result = dialog.ShowDialog();

            if ((int)result == 1)
            { 
                leftFilePath = dialog.SelectedPath;
                leftText.Text = leftFilePath;
                loadLeftPacks(leftFilePath);
            }
        }

        private void rightOpenDialog(object sender, RoutedEventArgs e)
        {
            FolderBrowserDialog dialog = new FolderBrowserDialog();
            DialogResult result = dialog.ShowDialog();

            if ((int)result == 1)
            {
                rightFilePath = dialog.SelectedPath;
                rightText.Text = rightFilePath;
                loadRightPacks(rightFilePath);
            }
        }

        private void leftRefreshClick(object sender, RoutedEventArgs e)
        {
            loadLeftPacks(leftFilePath);
        }

        private void rightRefreshClick(object sender, RoutedEventArgs e)
        {
            loadRightPacks(rightFilePath);
        }

        private void leftDeleteClick(object sender, RoutedEventArgs e)
        {
            string filePath = System.IO.Path.GetDirectoryName(leftListGroup[leftTabSelected][leftList.SelectedIndex].filePath);

            DirectoryInfo dir = new DirectoryInfo(filePath);
            if (!dir.Exists)
            {
                return;
                throw new DirectoryNotFoundException(
                    "Source directory does not exist or could not be found: "
                    + filePath);
            }

            if (dir.Exists)
            {
                Directory.Delete(filePath, true);
                loadLeftPacks(leftFilePath);
            }
        }

        private void rightDeleteClick(object sender, RoutedEventArgs e)
        {
            string filePath = System.IO.Path.GetDirectoryName(rightListGroup[rightTabSelected][rightList.SelectedIndex].filePath);

            DirectoryInfo dir = new DirectoryInfo(filePath);
            if (!dir.Exists)
            {
                return;
                throw new DirectoryNotFoundException(
                    "Source directory does not exist or could not be found: "
                    + filePath);
            }

            if (dir.Exists)
            {
                Directory.Delete(filePath, true);
                loadRightPacks(rightFilePath);
            }
        }
    }

    
}
