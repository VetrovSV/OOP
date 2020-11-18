#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include "person.h"
#include "sertificate.h"

/* Университет */
class University
{
public:
    University();

    Sertificate *educate(const Person& p);
};

/* University ассоциирует Sertificate и Person
 * */

#endif // UNIVERSITY_H
