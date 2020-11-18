#include "university.h"

University::University()
{

}

Sertificate University::educate(const Person &p){
    Sertificate s;
    s.setId("46348");
    s.setName( p.getName() );
    // TODO: заполнить остальные поля

    return s;
}
