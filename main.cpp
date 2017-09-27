#include <iostream>
#include "Core/rmlib.h"

using namespace std;

char* ip = ("127.0.0.1");
char* ipHA = ("127.0.0.1");
int port = 8888;
int portHA = 5555;



int main(){
    cout << "Creando libreria" << endl;


    Rmlib r1 =  Rmlib();
    r1. rm_init(ip,port,ipHA,portHA);

    cout << "Libreria creada" << endl;
    char* key = "Hola";
    int value = 1230;
    int size_value = sizeof(value);
    cout << size_value << endl;
    r1.rm_new(key,&value,size_value);
    cout << "New hecho" << endl;


    return 0;
}
