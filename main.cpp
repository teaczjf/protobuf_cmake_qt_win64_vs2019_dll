#include <iostream>
#include <string>
#include "addressbook.pb.h"
using namespace std;
int main ( int argc, char *argv[] )
{


    Person person;
    person.set_id ( 123 );
    cout << "学生id = %d" << person.id() ;
    person.set_name ( "小明" );
    cout <<  "学生姓名 = %s" << person.name().c_str() ;

    return 0;
}
