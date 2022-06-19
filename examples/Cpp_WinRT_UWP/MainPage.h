/// Исходный код класса главного окна
/// Имя этого класса указано в XAML файле MainPage

#pragma once

#include "MainPage.g.h"

namespace winrt::CppWinRTUWP::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::CppWinRTUWP::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
