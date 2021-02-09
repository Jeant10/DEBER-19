#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;
int main()
{ 
  string nombre;
  string apellido;
  string carrera;
  int edad;
  int op;
  do{
    cout<<"Opciones:\n";
    cout<<"1.-Ingresar datos\n2.-Mostrar datos\n";
    cout<<"Ingrese el numero de su opcion:\n";
    cin>>op;
    cin.ignore();
    if(op==1){
      char r;
      ofstream archivoprueba;
      string nombrearchivo;

      cout<<"Ingrese el nombre del archivo:\n";

      getline(cin,nombrearchivo);

      archivoprueba.open(nombrearchivo.c_str(),ios::out);
 
      do
      {

      cout<<"\tIngrese el nombre: ";
      getline(cin,nombre);
      cout<<"\tIngrese el apellido: ";
      getline(cin,apellido);
      cout<<"\tIngrese la carrera: ";
      getline(cin,carrera);
      cout<<"\tIngrese la edad: ";
      cin>>edad;

      archivoprueba<<nombre<<"  "<<apellido<<"  "<<carrera<<"  "<<edad<<"\n";

      cout<<"Desea agregar otros contactos: S/N \n";

      cin>>r;

      cin.ignore();

      }

      while(r=='S');

      archivoprueba.close();

      }
    } 
    while(op !=2);

    ifstream archivolectura("contactos.txt");

    string texto;

     while(!archivolectura.eof())

     {

     archivolectura>>nombre>>apellido>>carrera>>edad;  

     getline(archivolectura,texto); 

      if (!archivolectura.eof())
      { 

        cout<<"*************************"<<endl;
        cout<<"Nombre:"<<nombre<<endl;
        cout<<"Apellido:"<<apellido<<endl;
        cout<<"Carrera:"<<carrera<<endl;
        cout<<"Edad:"<<edad<<endl;

      }
    }

  archivolectura.close();

}

