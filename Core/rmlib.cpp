
#include "rmlib.h"
#include <iostream>

using namespace std;

Rmlib::Rmlib()
{

}
///@brief funcion que instancia la libreria
///@tparam ip, ipHA son los ip de los servidores
///@tparam port, portHA son los puestos de cada server
void Rmlib::rm_init(char* ip, int port, char* ipHA, int portHA)
{
    this->ip = ip;
    this->port = port;
    this->ipHA = ipHA;
    this->portHA = portHA;
}
///@brief crea un new con los server
///@tparam los datos del key a introducir
void Rmlib::rm_new(char *key, void *value, int value_size)
{
    ClientRmlib client = ClientRmlib(this->ip, this->port, this->ipHA, this->portHA);
    this->key = key;
    this->value = value;
    this->value_size = value_size;

    char* message;
    rmRef_h instance = rmRef_h(this->key,this->value, this->value_size);
    message = generateMessage(instance, 'n');
    char* serverMessage;

    int state = client.connectClient();

    if (state == 1)
    {
        cout << "Conectado al Main server" << endl;
        cout << sizeof(message) << endl;
        serverMessage = client.sendMessage(message, sizeof(message));
        interpretMessage(serverMessage);


    } else if(state == 2)
    {
        cout << "Conectado al server HA" << endl;
        client.sendMessage(message, sizeof(message));
        serverMessage = client.sendMessage(message, sizeof(message));
        interpretMessage(serverMessage);

    } else if (state == 0)
    {
        cout << "Sin conexion a los servidores" << endl;
    }
}
///@brief hace un get de un dato del server
///@tparam key dato a buscar en el server
rmRef_h Rmlib::rm_get(char *key)
{
    ClientRmlib client = ClientRmlib(this->ip, this->port, this->ipHA, this->portHA);
    this->key = key;
    char* message;
    rmRef_h instance = rmRef_h(this->key, nullptr,0);
    message = generateMessage(instance, 'g');
    char* serverMessage;
    int state = client.connectClient();
    rmRef_h rInstance;

    if (state == 1)
    {
        cout << "Conectado al Main server" << endl;
        cout << sizeof(message) << endl;
        serverMessage = client.sendMessage(message, sizeof(message));
        rInstance = interpretMessage(serverMessage);
        if(rInstance.referencias != 0){
            cout << "Error al recibir Key" << endl;
        }else {
            return rInstance;
        }

    } else if(state == -2)
    {
        cout << "Conectado al server HA" << endl;
        client.sendMessage(message, sizeof(message));
        serverMessage = client.sendMessage(message, sizeof(message));
        rInstance = interpretMessage(serverMessage);
        if(rInstance.referencias != 0){
            cout << "Error al recibir Key" << endl;
        }else {
            return rInstance;
        }

    } else if (state == 0)
    {
        cout << "Sin conexion a los servidores" << endl;
    }

    return rInstance;
}
///@brief hace un delete de un dato del server
///@tparam handler dato a eliminar en el server
void Rmlib::rm_delete(rmRef_h *handler)
{
    ClientRmlib client = ClientRmlib(this->ip, this->port, this->ipHA, this->portHA);
    this->handler = handler;
    this->key = handler->key;
    rmRef_h instance = rmRef_h(this->key, nullptr,0);
    int state = client.connectClient();
    char* message;
    char* serverMessage;

    message = generateMessage(instance, 'd');

    if (state == 1)
    {
        cout << "Conectado al Main server" << endl;
        cout << sizeof(message) << endl;
        serverMessage = client.sendMessage(message, sizeof(message));
        interpretMessage(serverMessage);


    } else if(state == -2)
    {
        cout << "Conectado al server HA" << endl;
        client.sendMessage(message, sizeof(message));
        serverMessage = client.sendMessage(message, sizeof(message));
        interpretMessage(serverMessage);

    } else if (state == 0)
    {
        cout << "Sin conexion a los servidores" << endl;
    }
}
///@brief interpreta el mensaje que se recibe del server
///@tparam message mensaje recibido
rmRef_h Rmlib::interpretMessage(char* message)
{
    rmRef_h instance;
    int i = 0;
    string word;
    int type = 0;
    while (message[i] != '#'){
        instance.referencias = 1;
        while (message[i] != '@'){
            string c;
            char bd = message[i];
            c = bd;
            word = word + c;
            i++;
        }
        if (type == 0) {
            char *key;
            key = (char *) word.c_str();
            instance.key = key;
            type++;
            i++;
        }if(type == 1){
            int* value;
            value = (int*) word.c_str();
            instance.value = value;
            type++;
            i++;
        }if(type == 2){
            int value_size;
            value_size =  atoi(word.c_str());
            instance.value_size = value_size;
            type++;
            i++;
        }
    }
    return instance;
}
///@brief genera el mensaje que se le envia al server
///@tparam bd instancia que se le va a enviar
///@tparam type le indica al server que hacer con la informacion
char* Rmlib::generateMessage(rmRef_h bd, char type) {

    char* message;
    string  word;
    if(type == 'n') {
        string n,m,p,q, o;
        n = type;
        word = word + n;
        m = bd.key;
        word = word + m + '@';
        int* s = (int *)bd.value;
        o = *s;
        word = word +  o + '@';
        q = bd.value_size;
        word = word + q + '@' +'#';
        message =(char*) word.c_str();
    }
    if(type == 'g'){
        string n,m;
        n = type;
        word = word + n;
        m = bd.key;
        word = word + m + '@' + '#';
        message =(char*) word.c_str();

        //sprintf(message,"%c%s@#", type,bd.key);
    }
    if (type == 'd'){
        string n,m;
        n = type;
        word = word + n;
        m = bd.key;
        word = word + m + '@' + '#';
        message =(char*) word.c_str();
    }
    return message;
}
