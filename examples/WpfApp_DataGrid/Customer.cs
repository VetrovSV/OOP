using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WpfApp_DataGrid
{   
    /// <summary>
    /// Клиент -- предствляет одну строку таблицы
    /// </summary>
    class Customer
    {
        private String name;
        private int id;

        public Customer(string name, int id)
        {
            Name = name;
            Id = id;
        }

        public string Name { get => name; set => name = value; }
        public int Id { get => id; set => id = value; }
    }
}
