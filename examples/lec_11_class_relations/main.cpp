#include <iostream>
#include "person.h"

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

    return 0;
}
