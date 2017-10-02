#include <iostream>
#include "Core/rmlib.h"

using namespace std;

int main(){
    cout << "Creando libreria" << endl;
    char* ip = ("127.0.0.1");
    char* ipHA = ("127.0.0.1");
    int port = 8888;
    int portHA = 5555;

    Rmlib r1 =  Rmlib();
    r1. rm_init(ip,port,ipHA,portHA);
    cout << "Libreria creada" << endl;

    char* key = "Hola";
    int value = 1230;
    int size_value = sizeof(value);
    r1.rm_new(key,&value,size_value);


    return 0;
}
