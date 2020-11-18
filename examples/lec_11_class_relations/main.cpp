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


//https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1&title=Untitled%20Diagram.drawio#R7VjLcpswFP0aL9MBBJgsGz%2FSRTuTjttpsuqoSAa1AnmEHEO%2FvsKId8HETxbZeHSvrh733KMjmQmYBfEjhxv%2FC0OYTgwNxRMwnxjG1Nbkb%2BpIMocJ7jOHxwnKXHrpWJG%2FWDnVOG9LEI5qgYIxKsim7nRZGGJX1HyQc7arh60Zra%2B6gR5uOVYupG3vD4KEn3kdY1r6P2Hi%2BfnKuq3yC2AerDKJfIjYruICiwmYccZE1griGaYpdjku2bhlR2%2BxMY5DMWTA0o199%2Bdq%2BZU%2FO44VPAYPd%2FxOzfIK6VYl%2FIR5xEK1ZZHkOPgioLKlT8DDmlA6Y5TxfQ9AEDtrV%2FojwdkfXOmxXQf%2FWssetQjmAsedu9cLTCSXMAuw4IkMUQMMTcGoeGSYyt6VVdFz0viViljKBxURvGLqEivZUHC9ATqjBd0cCjx64IB9a%2BDyxSogYSQPnTIZFz7zWAjpovQ%2BcLYNEU6n1aRVxnxmbKPg%2FY2FSJSCwK1g0lUBH8dEPKfDP1jKeqn0zGM1895IlJHtM91cP%2FgyF7blLu5JGijtgtzDoifO%2FH8xOaZQkNf6Ps5fGX08ldF6KyPx50llUGq%2BVPvKYXvrhhXtOJ7XqShoidT3UC7KIyKS0UmVeT82jTdb8K1kgmQN3REqvak3lN65NXxWCz4JAAm9PujOceU1gDBvfuXZLSDaQhuij%2Bl7VVqIwICF6JtPwr2AoSWhhViG%2BSPZMBsy2iGJ%2BgFJPEZ%2BzyijxmkyWi1pXubB0qqme2JE7rqgDzAb58ho0CLLSY2qvrgbE1nNp1dzoizp1kR7ihU5Hs%2B66VVZV7uGSwoeYl2VcwUDOy79g2%2BRM%2FLSeuflpXjpnIWX2jBe6kdp4fCH6DU5ab5z8lKc1Nsv5bFf0f3%2FXUcplh3%2Fbi9AzOItdyoxW6%2FqgcSUTIFJJWyTBkQ9G7at2jpW83Ne8%2BSdGG86%2FfFmA8A3x4NavGxkiAw8tdIsP41m4eX3ZbD4Bw%3D%3D
