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
        string filePath = "C:/Users/s189062/Desktop/Addon Source/";
        int leftTabSelected = 0;
        Binding leftBinding1;
        Binding leftBinding2;
        Binding leftBinding3;

        public MainWindow()
        {
            ////////////////////
            //Left Side init////
            ////////////////////
            
            leftListGroup = new PackList[3];
            for (int i = 0; i < leftListGroup.Length; i++)
            {
                leftListGroup[i] = new PackList();
            }
            leftBinding1 = new Binding();
            leftBinding2 = new Binding();
            leftBinding3 = new Binding();
            leftBinding1.Source = leftListGroup[0];
            leftBinding2.Source = leftListGroup[1];
            leftBinding3.Source = leftListGroup[2];
            
            InitializeComponent();

            txtbox_left.Text = defaultFilePath;

            //list_left.SetBinding(ListBox.ItemsSourceProperty, leftBinding1);
            UpdateLeftFocus();
        }

        private void OnClickLeft(object sender, RoutedEventArgs e)
        {
            ////list_left.Items.
            //txtbox_left.Text = list_left.Items[0];
            PackEntry entry1 = loadPack(filePath);
            leftListGroup[0].Add(entry1);
        }

        public PackEntry loadPack(string filePath)
        {
            string contents = File.ReadAllText(filePath);
            return Newtonsoft.Json.JsonConvert.DeserializeObject<PackEntry>(contents);

        }

        private void loadPacks(string filePath)
        {
            string[] subDirectories;
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

                    leftListGroup[0].Add(newEntry);
                }
                if (File.Exists(subDirectories[i] + "/development_resource_packs"))
                {
                    Console.WriteLine("Found dev");
                }
            }
        }

        private void txtbox_left_TextChanged(object sender, TextChangedEventArgs e)
        {
            filePath = txtbox_left.Text;
            leftListGroup[0].Clear();
            Console.WriteLine("Ran");
            loadPacks(filePath);

        }

        private void LeftTabChanged(object sender, RoutedEventArgs e)
        {
            if (tab_leftUncat.IsSelected)
            {
                leftTabSelected = 0;
            }
            else if (tab_leftBehavior.IsSelected)
            {
                leftTabSelected = 1;
            }
            else if (tab_leftResource.IsSelected)
            {
                leftTabSelected = 2;
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
                default:
                    list_left.SetBinding(ListBox.ItemsSourceProperty, leftBinding1);
                    break;
            }
        }

    }

    
}
