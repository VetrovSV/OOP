using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


// Имя этого пространство имён используется при подключении этого файла
// using
namespace XamlCsharpAppExample
{

    // Этот класс использутся в классе MainWindow
 
    /// <summary>
    /// Описывает основную логику программы: выдаёт приветствия
    /// </summary>
    internal class HelloUsername
    {
        public string greet(string username)
        {   if ( (username == null) | (username == "") )
                    username = "%username";
            return "Hello, " + username + "!";
        }
    }

    
}
