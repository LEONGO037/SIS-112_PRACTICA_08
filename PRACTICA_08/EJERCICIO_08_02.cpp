// Materia: Programación I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creación: 26/11/2023
// Fecha modificación: 26/11/2023
// Número de ejericio: 2
// Problema planteado: Escriba un programa que cree un fichero de texto llamado "PERSONAS.BIN" en el que se
// guarde la información de un número indeterminado de personas.
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

const char* Nombre_Archivo = "PERSONAS.bin";

struct Persona
{
    char nombre[30];
    int edad;
    char sexo;
    char fechanacimiento [11];
};

//Escribe los datos en el archivo binario
void EscribirArchivo (Persona);

main ()
{
    Persona per;
    do
    {
        cout<<"Ingrese el nombre de la persona: ";
        fflush(stdin);
        cin.getline(per.nombre, 30);
        if(strcmp(per.nombre," ") != 0)
        {
            cout<<"Ingrese la edad: ";
            cin>>per.edad;
            cout<<"Ingrese el sexo (M)asculino (F)emenino: ";
            cin>>per.sexo;
            cout<<"Ingrese la fecha de nacimiento dd/mm/yyyy: ";
            fflush(stdin);
            cin.getline(per.fechanacimiento, 11);
            EscribirArchivo(per);
        }
    }while (strcmp(per.nombre," ") != 0);
    return 0;
}

void EscribirArchivo (Persona per)
{
    ofstream archivo;
    archivo.open(Nombre_Archivo, ios:: app | ios::binary);
    archivo.write((char*)&per, sizeof(Persona));
    archivo.close();
}
