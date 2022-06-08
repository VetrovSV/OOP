using System;
using System.Collections.Generic;
using System.ComponentModel;            // для наблюдаемой коллекции BindingList
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WpfApp_DataGrid
{   
    /// <summary>
    /// Содержит данные БД, 
    /// данные можно подключить к GridView
    /// </summary>
    class DataBase
    {
        public BindingList<Customer> data;

        public DataBase()
        {
            data = new BindingList<Customer>();
        }

        void save()
        {
            // todo: сохранение данных в файл
        }

        void load()
        {
            // todo: загрузка данных из файла
        }

        public void add_random_data()
        { 
            Random rnd = new Random();
            List<String> names = new List<string> { "Гвидо ван Россум ", "Бьёрн Страуструп", "Деннис Ритчи", "Дональд Эрвин Кнут" };
            data.Add(new Customer( names[rnd.Next(names.Count)], rnd.Next() ));
        }
    }
}
