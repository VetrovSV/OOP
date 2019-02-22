#include <iostream>
#include <cassert>
#include "test.h"

using namespace std;

void test_SimpleClass_constructor(){
    {   // отдельные проверки должны быть в отдельных блоках,
        // чтобы исклюить влияние одних проверок на другие
        Seconds s;
        assert(s.seconds() == 0);   }

    {   Seconds *s = new Seconds;
        assert(s->seconds() == 0);   }

    {   Seconds *s = new Seconds(5);
        assert(s->seconds() == 5);   }

    {   Seconds s(0);
        assert(s.seconds() == 0);   }

    {
        Seconds s(42);
        assert(s.seconds() == 42);  }

    {
        Seconds s(59);
        assert(s.seconds() == 59);  }


    {   try{
            Seconds s(60);
            assert(0 && "s.setSeconds(60) Failed");}
        catch (SecondsException e) {;} }


    {   try{
            Seconds s(100);
            assert(0 && "s.setSeconds(100) Failed");}
        catch (SecondsException e) {;} }

    {   try{
            Seconds s(-1);
            assert(0 && "s.setSeconds(-1) Failed");
        }
        catch (SecondsException e) {;} }

    {   try{
            Seconds s(-100);
           assert(0 && "s.setSeconds(-100) Failed");}
        catch (SecondsException e) {;} }

    cout << "test_SimpleClass_constructor OK" << endl;
}


void test_SimpleClass_setSeconds(){
    {   Seconds s;
        s.setSeconds(0);
        assert(s.seconds() == 0);   }

    {
        Seconds s;
        s.setSeconds(42);
        assert(s.seconds() == 42);  }

    {
        Seconds s;
        s.setSeconds(59);
        assert(s.seconds() == 59);  }


    {   Seconds s;
        try{
            s.setSeconds(60);
            assert(0 && "s.setSeconds(60) Failed");}
        catch (SecondsException e) {;} }


    {   Seconds s;
        try{
            s.setSeconds(100);
            assert(0 && "s.setSeconds(100) Failed");}
        catch (SecondsException e) {;} }

    {   Seconds s;
        try{
            s.setSeconds(-1);
            assert(0 && "s.setSeconds(-1) Failed");
        }
        catch (SecondsException e) {;} }

    {   Seconds s;
        try{
            s.setSeconds(-100);
           assert(0 && "s.setSeconds(-100) Failed");}
        catch (SecondsException e) {;} }

    cout << "test_SimpleClass_setSeconds OK" << endl;
}


void test_SimpleClass_tostring(){
    {   Seconds s(0);
        assert(s.toString() == "0");   }

    {   Seconds s(5);
        assert(s.toString() == "5");   }

    {   Seconds s(59);
        assert(s.toString() == "59");   }
    cout << "test_SimpleClass_tostring OK" << endl;
}


void test_SimpleClass_plus_operator(){
    {   Seconds s1(13), s2(20);
        Seconds s = s1 + s2;
        assert( s.seconds() == 33 );
    }

    {   Seconds s1(0), s2(20);
        Seconds s = s1 + s2;
        assert( s.seconds() == 20 );
    }

    {   Seconds s1(0), s2(0);
        Seconds s = s1 + s2;
        assert( s.seconds() == 0 );
    }

    {   Seconds s1(10), s2(49);
        Seconds s = s1 + s2;
        assert( s.seconds() == 59 );
    }

    {   Seconds s1(10), s2(50);
        Seconds s = s1 + s2;
        assert( s.seconds() == 0 );
    }
    cout << "test_SimpleClass_plus_operator OK" << endl;
}


void test_SimpleClass_increment_operator(){
    {   Seconds s;
        s++;
        assert(s.seconds() == 1); }

    {   Seconds s(2);
        s++;
        assert(s.seconds() == 3);}

    {   Seconds s(58);
        s++;
        assert(s.seconds() == 59);}

    {   Seconds s(59);
        s++;
        assert(s.seconds() == 0);}

    cout << "test_SimpleClass_increment_operator OK" << endl;
}


void test_SimpleClass_plus_increment(){
    Seconds s1, s2(12);
    Seconds s3 = s1 + s2++;
    assert (s3.seconds() == 12);
    assert (s2.seconds() == 13);
    cout << "test_SimpleClass_plus_increment OK" << endl;
}


void test_SimpleClass_all(){
    test_SimpleClass_constructor();
    test_SimpleClass_setSeconds();
    test_SimpleClass_tostring();
    test_SimpleClass_plus_operator();
    test_SimpleClass_increment_operator();
    test_SimpleClass_plus_increment();
    cout << "test_SimpleClass OK" << endl << endl;
}

