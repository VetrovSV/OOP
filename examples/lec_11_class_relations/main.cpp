#include <iostream>
#include "university.h"

using namespace std;

int main()
{
    Person p("Ivan", "Ivanov", "Ivanovich", "male");

    p.birth_date.setDay(11);
    p.birth_date.setMonth(11);
    p.birth_date.setYear(2000);

    p.birth_date = Date(12,12, 2001);

    Sertificate *s = new Sertificate();
    p.sertificate = s;


    Person peter("Petrov","Petr","P", "male");
    University cal_tech;
    peter.sertificate = cal_tech.educate( peter );


    return 0;
}

// Диаграмма классов
//https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1&title=Untitled%20Diagram.drawio#R7VnJbtswEP0aHVOI2qwcIy%2FpIQXSukWbU8FItMVWIg2Kju1%2BfUcStUeOknhDUcCQxeFwe%2FP4yLE1cxxvbwVehZ94QCLN0IOtZk40w0DIcOErtexyi2M5uWEpaKCcKsOc%2FiHKqCvrmgYkaThKziNJV02jzxkjvmzYsBB803Rb8Kg56govSccw93HUtX6ngQxzq2uMKvtHQpdhMTJyrvOaGBfOaiVJiAO%2BqZnMqWaOBecyf4u3YxKl4BW45O1mPbXlxARhckiDmb8N%2FZ%2Fz2Wfxw3Xt%2BDb2rsSV6uUJR2u14HsiEs7UlOWuwCGUcQRvSDO9BY2iMY%2B4yGrMABN34YM9kYL%2FJrUax3fJ4wJq1CBESLLtnT0qMQEyER4TKXbgohoYuoJR8ciwVHlTRQUVpAlrEbGVDSsiLMuuK6zgRcH1CuiMDnQTLMnFA2c65wauGKwGEglg06kiFzLkS85wNK2snuBrFpC0Wx1Klc8d5ysF7y8i5U4pCF5LDqYa%2BGRL5Y%2B0%2BYeRrYoPtarJVnWdFXZFgcGC663S8kO9smqXlYqG%2BQrTZe0PG6DA18Ine%2BAylephsSRyj5%2F1PA0EibCkT815HD6m6LwxrYdUHxrSS49oz8Y%2BTUTNjrx9YzCoSKjcXZzIWY5xYaeD1YFvDgukC%2Bxf4BnRhs90zw2f3YEPAKBsuQ%2B6IxyWln1uIJwOEF2hZcFNetOFUkBxzFnwNaQsE7BgRqNSLFlxvTasloxWkmg0NBG9oImV%2FhrDBfiAQmq8T0jrQS1uRYPFVXV3zynMuiSQabVuW0aLGPmaVKv6bb3Vkd2%2BtrU7yhfd6SgjWbnGt%2FNudFLeNQ7i6lzuo92LN4vhHLsg7nTEx7VPyx2IJt7V3FapQ9I%2FYWQ%2FP%2BG%2BebX9DafhDy%2F5DA5KZPcgRNaHCujo%2BAJ6SPq%2FKLHWxW2Tf0ZiUfeKfdSz%2FY3MfEW2XCMmiR755kictAdysicjPoZ02wfipIVOI93lr0BqHNvW989LSXWP1B9HulE3idKAaB48keZ62buVPfXUco0ye3cTQT4ANPFwRJewdSY%2BEI6INNfiTBZ8Tfmbpg7Ux9GNcoxpEGTcTVbYh%2BTjjixSupmV5YvKAMxOhsY4y3%2FikFjix3IIFReYlu3BB0AfpzvMhmmOoYyqMnxSdyHHnEHXmGa7hOBEbkgiD5Pu2GaLbaib7rjPZDuG079B3vczUjfvGxZxvVblZs9Z9sybTLPnuOnmZW1n%2F9kylC3tgxddH40tUKz%2BGMnlpPp7yZz%2BBQ%3D%3D
