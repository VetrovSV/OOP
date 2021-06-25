using System;
using System.Collections.Generic;
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

namespace WpfApp_DataGrid
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        DataBase data;

        public MainWindow()
        {
            InitializeComponent();
            data = new DataBase();
            datagrid.ItemsSource = data.data;
        }

        private void button_add_row_Click(object sender, RoutedEventArgs e)
        {
            data.add_random_data();
        }
    }
}
