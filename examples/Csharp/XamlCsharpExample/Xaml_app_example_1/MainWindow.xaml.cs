// подключение модулей (пространств имён)

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

//
// класс HelloUsername подключать не нужно,
// он тоже находится в пространстве имён XamlCsharpAppExample

namespace XamlCsharpAppExample
{
    // Это документирующий комментарий
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        // экземпляр класса с логикой программы
        HelloUsername hello;


        /// <summary>
        /// Класс главного окна
        /// </summary>
        public MainWindow()
        {
            InitializeComponent();
            hello = new HelloUsername();
        }

        // Обработчик нажатия на кнопку (см. файл MainWindow.xaml, свойство clicked в Button)
        private void button_hello_Click(object sender, RoutedEventArgs e)
        {
            Label_hello.Content = hello.greet( textbox_name.Text );
        }
    }
}
