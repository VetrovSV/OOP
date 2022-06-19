/// Исходный код класса главного окна
/// Имя этого класса указано в XAML файле MainPage

#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

#include "bank.h"

using namespace std;

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::ViewManagement;


namespace winrt::CppWinRTUWP::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
        
    }

    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
    
    /// Обработчик нажатия на кнопку Вычислить
    void MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&){
        // чтение данных из полей ввода, преобразование (hstring) в std::string
        string sumt = to_string(textbox_sum().Text());
        string timet = to_string(textbox_time().Text());
        string perct = to_string(textbox_perc().Text());

        float s = stof(sumt);
        float t = stof(timet);
        float p = stof(perct);


        float profit = calc_profit(s, t, p);
        float result = s + profit;

        string profitt = std::format("{:.2f}", profit);
        string resultt = std::format("{:.2f}", result);
        // функция format стала доступна в С++20 
        // включить стандарт: Свойства проекта -> Свойства конфигурации > С\С++ > Все параметры | Стандарт языка С = С++20 или latest

        textblock_profit().Text( to_hstring(profitt) );
        textblock_result().Text( to_hstring(resultt) );
    }
}
