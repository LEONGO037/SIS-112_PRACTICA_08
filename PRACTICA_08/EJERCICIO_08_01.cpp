// Materia: Programación I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creación: 26/11/2023
// Fecha modificación: 26/11/2023
// Número de ejericio: 1
// Problema planteado: Escribir un programa con la opción de encriptar y de desencriptar un fichero de texto.
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const char* Nombre_Archivo = "Fichero.txt";
const char* Nombre_Archivo_Encriptado = "FicheroEncriptado.COD";

void EscribirArchivo();
void Desencriptar ();

int main ()
{
    int opcion;
    do
    {
        cout<<"1. Aniadir nuevo texto para encriptar"<<endl;
        cout<<"2. Ver archivo encriptado"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Opcion a elegir: ";
        cin>>opcion;
        switch(opcion)
        {
        case 1:
            EscribirArchivo();
            break;
        case 2:
            Desencriptar();
            break;
        case 3:
            cout<<"Salio del sistema"<<endl;
            break;
        default:
            cout<<"Opcion no valida"<<endl;
            break;
        }
    }while(opcion!=3);

}
void Desencriptar ()
{
    ifstream archivo;
    archivo.open(Nombre_Archivo_Encriptado);
    if(archivo.good())
    {
        string lineatexto;
        while(!archivo.eof())
        {
            getline(archivo, lineatexto);
            if(lineatexto.length() > 0)
            {
                cout<<"La linea encriptada es: "<<lineatexto<<endl;
                cout<<"La linea desencriptada es: ";
                for( char letra: lineatexto)
                {
                    int valor = static_cast<int>(letra);
                    int nuevovalor = valor - 3;
                    char caracter = static_cast<char>(nuevovalor);
                    cout<<caracter;
                }
                cout<<"\n";
            }
        }
    }
}
void EscribirArchivo()
{
    ofstream archivo;
    ofstream ArchivoEscritura;
    archivo.open(Nombre_Archivo, ios::app);
    string texto;
    cout<<"Ingrese el texto que desea encriptar: ";
    fflush(stdin);
    cin>>texto;
    archivo<<texto;
    archivo<<"\n";
    archivo.close();
    string lineanueva;
    for(char letra: texto)
    {
        int valor = static_cast<int>(letra);
        int nuevovalor = valor + 3;
        char caracter = static_cast<char>(nuevovalor);
        lineanueva += caracter;
    }
    ArchivoEscritura.open(Nombre_Archivo_Encriptado, ios::app);
    ArchivoEscritura<<lineanueva;
    ArchivoEscritura<<"\n";
    ArchivoEscritura.close();
}
