#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <time.h>
#include <unistd.h>

using namespace std;

//Para los hombres el usuario es uMxyz y la contraseña 1234.
//Para las mujeres el usuario es uFxyz y la contraseña 1234.

int main(){
    string usuarioU, claveU, ticket, nombre, apellido, correo, carrera;
    char matriculaActiva;
    int opcion, identificadorTicket, cedula, codigo;

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    cout<<"Ingrese su usuario: ";
    cin>>usuarioU;
    cout<<"Ingrese la clave: ";
    cin>>claveU;
    cout<<"Usted mantiene su matricula activa?, responda con s o n: ";
    cin>>matriculaActiva;

    switch(matriculaActiva){
        case 's': cout<<"\nBievenido al sistema";
        if(usuarioU=="uMxyz" || usuarioU=="uFxyz" && claveU=="1234"){
            cout<<"\nDatos correctos";
            cout<<put_time(&tm,"\nUsted ingreso al sistema hoy %d-%m-%Y a la hora %H:%M");
        }
        else{
            cout<<"\nDatos incorrectos, vuelva pronto";
            exit(0);
        }
        break;
        
        case 'n': cout<<"\nNo puede entrar al sistema, vuelva pronto";
        exit(1);

        default: cout<<"\nResponda con s o n solamente, vuelva pronto";
        exit(1);
    }

    cout<<"\n\nPor favor, cambie su clave: ";
    cin>>claveU;
    cout<<"Su nueva clave es "<<claveU;

    do{
        cout<<"\n\nOpciones";
        cout<<"\n1. Subir ticket.";
        cout<<"\n2. Ver ticket";
        cout<<"\n3. Salir del sistema o cerrar sesion";
        cout<<"\nElija una opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1: cout<<"\nTipos de tickets (Quejas y sugerencias)";
            cout<<"\nCual desea escoger?: ";
            cin>>ticket;
            cout<<"\nIngrese sus datos";
            cout<<"\nNombre: ";
            cin>>nombre;
            cout<<"Apellido: ";
            cin>>apellido;
            cout<<"Cedula o identificacion: ";
            cin>>cedula;
            cout<<"Correo: ";
            cin>>correo;
            cout<<"Carrera: ";
            cin>>carrera;
            identificadorTicket=rand()%5000+1000;
            cout<<"Aqui esta su codigo de ticket: "<<identificadorTicket;
            break;

            case 2: cout<<"\nColoque aqui su codigo de ticket para ver su informacion: ";
            cin>>codigo;
            if(codigo==identificadorTicket){
                cout<<"El tipo de ticket que usted escogio es de "<<ticket<<" con el nombre de "<<nombre<<" y apellido "<<apellido<<" de cedula "<<cedula;
            }
            else{
                cout<<"\nTicket invalido, intente de nuevo";
            }
            break;
        }
    }while(opcion!=3);

    cout<<put_time(&tm,"\nUsted cerro sesion a las %H:%M");
    cout<<"\nGracias por entrar";

    return 0;
}