using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;       // для ObservableCollection
// ObservableCollection -- коллекция, которую можно использовать совместно с DataGrid
// Эта коллекция можеть оповещать о своём изменении DataGrid
// DataGrid, в свою очередь, автоматически поддерживает сортировки и т.п.

namespace WpfApp_DataGrid
{   
    /// <summary>
    /// Содержит данные БД, 
    /// данные можно подключить к GridView
    /// </summary>
    class DataBase
    {

        public ObservableCollection<Customer> data;

        public DataBase()
        {
            data = new ObservableCollection<Customer>();
        }

        void save()
        {
            // todo: сохранение данных в файл
        }

        void load()
        {
            // todo: загрузка данных из файла
        }
        

        /// Добавление случайной записи в таблицу
        public void add_random_data()
        { 
            Random rnd = new Random();
            // todo: static member
            List<String> names = new List<string> { "Гвидо ван Россум ", "Бьёрн Страуструп", "Деннис Ритчи", "Дональд Эрвин Кнут" };

            data.Add(new Customer( names[rnd.Next(names.Count)], rnd.Next() ));
        }
    }
}
