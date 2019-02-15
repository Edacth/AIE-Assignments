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

namespace Craft2Git
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    /// 
    public class addonEntry
    {
        private string name;
        private string filePath;

        public string Name { get => name; set => name = value; }
        public string FilePath { get => filePath; set => filePath = value; }

        public addonEntry(string _name, string _filePath)
        {
            name = _name;
            filePath = _filePath;
        }
    }

    public class addonList : ObservableCollection<addonEntry>
    {
        public addonList()
        {
            addonEntry entry1 = new addonEntry("Arena", "C://");
            Add(entry1);
            Add(new addonEntry("Battle", "C://"));
            
        }
    }

    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            addonList listData = new addonList();
            Binding binding1 = new Binding();

            binding1.Source = listData;
            list_left.SetBinding(ListBox.ItemsSourceProperty, binding1);
        }

        private void OnClickLeft(object sender, RoutedEventArgs e)
        {
            ////list_left.Items.
            //txtbox_left.Text = list_left.Items[0];
        }
    }
}
