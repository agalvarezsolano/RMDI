#include <iostream>
#include "rmlib.h"

using namespace std;

char* ip = ("127.0.0.1");
char* ipHA = ("127.0.0.1");
int port = 5555;
int portHA = 8888;



int main(){
    cout << "Creando libreria" << endl;


    Rmlib r1 =  Rmlib();
    r1. rm_init(ip,port,ipHA,portHA);

    cout << "Libreria creada" << endl;
   // r1.rm_new()


    return 0;
}
