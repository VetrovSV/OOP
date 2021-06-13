#include <iostream>
#include <map>
#include <algorithm>    // std::transform
#include <stdlib.h>

using namespace std;

using Foo = void(*)(string);

void weather(string s){
    cout << "Погода в Чите: -25, ясно" << endl;
}

void curency(string s){
    cout << "Доллар стоит 75 рублей :(" << endl;
}

void close(string s){
    exit(0);
}

int main()
{
    map<string, Foo> functions;

    functions["погода"] = weather;
    functions["курс"] = curency;
    functions["выход"] = close;

    while (true){
        cout << "Что показать? " << endl;
        string input;

        cin >> input;

        transform (input.begin(), input.end(), input.begin(), ::tolower);

        if ( functions.count(input) != 0 )
            functions[input]("");
        else
            cout << "нет такого обработчика: " << input << endl;}

    return 0;
}
