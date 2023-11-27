// Materia: Programación I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creación: 26/11/2023
// Fecha modificación: 26/11/2023
// Número de ejericio: 7
// Problema planteado: Escriba un programa que tenga como entrada un fichero que contenga un texto y dé como
// resultado una estadística del número de palabras.
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<sstream>
using namespace std;

const char* Nombre_Archivo = "FicheroPalabra.txt";

//Ingresa el texto al archivo
void IngresarTexto ();
//Cuenta las palabras
void ContarPalabras ();

int main ()
{
    IngresarTexto();
    ContarPalabras();
    return 0;
}

void ContarPalabras ()
{
    string linea;
    ifstream archivo;
    archivo.open(Nombre_Archivo);
    getline(archivo, linea);
    archivo.close();
    int palabras = 0;
    stringstream contador(linea);
    string pal;
    while (getline(contador, pal, ' '))
    {
        if(pal.length()>0)
            palabras++;
    }
    cout<<"La cantidad de palabras que hay en el archivo es: "<<palabras<<endl;
}

void IngresarTexto ()
{
    char linea[150];
    cout<<"Ingrese el texto: ";
    fflush(stdin);
    cin.getline(linea, 150);
    ofstream archivo;
    archivo.open(Nombre_Archivo);
    archivo<<linea;
    archivo.close();
}
