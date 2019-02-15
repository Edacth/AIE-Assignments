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
        PackList listData;
        string defaultFilePath = "C:/Users/s189062/Desktop/Addon Source/";
        string filePath = "C:/Users/s189062/Desktop/Addon Source/";

        public MainWindow()
        {
            
            listData = new PackList();
            Binding binding1 = new Binding();
            binding1.Source = listData;
            
            InitializeComponent();

            txtbox_left.Text = defaultFilePath;

            loadPacks(filePath);

            list_left.SetBinding(ListBox.ItemsSourceProperty, binding1);
        }

        private void OnClickLeft(object sender, RoutedEventArgs e)
        {
            ////list_left.Items.
            //txtbox_left.Text = list_left.Items[0];
            PackEntry entry1 = loadPack(filePath);
            listData.Add(entry1);
        }

        public PackEntry loadPack(string filePath)
        {
            string contents = File.ReadAllText(filePath);
            return Newtonsoft.Json.JsonConvert.DeserializeObject<PackEntry>(contents);

        }

        public void loadPacks(string filePath)
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

                    listData.Add(newEntry);
                }
            }
        }

        private void txtbox_left_TextChanged(object sender, TextChangedEventArgs e)
        {
           filePath = txtbox_left.Text;
            while (listData.Count >= 1)
            {
                listData.RemoveAt(0);
            }
            loadPacks(filePath);
        }
    }

    
}
