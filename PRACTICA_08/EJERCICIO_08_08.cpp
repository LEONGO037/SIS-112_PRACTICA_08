// Materia: Programación I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creación: 26/11/2023
// Fecha modificación: 26/11/2023
// Número de ejericio: 8
// Problema planteado: Escribir un programa que genere a partir de un fichero de entrada que contiene una tabla de
// números reales otro fichero de salida <nombre>.BIN grabado en formato binario.
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<sstream>

using namespace std;

const char* Archivo_Texto = "TextoEj8.txt";
const char* Archivo_Binario = "BinarioEj8.bin";

//Escribe los datos en el archivo
void EscribirArchivoTexto (int, int);
//Escribir archivo binario
void EscribirArchivoBinario (int, int);

int main ()
{
    int filas, columnas;
    cout<<"Ingrese la cantidad filas de la tabla: ";
    cin>>filas;
    cout<<"Ingrese la cantidad columnas de la tabla: ";
    cin>>columnas;
    EscribirArchivoTexto(filas, columnas);
    EscribirArchivoBinario(filas, columnas);
    return 0;
}

void EscribirArchivoTexto (int f, int c)
{
    ofstream archivo;
    archivo.open(Archivo_Texto);
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<"Ingrese el valor de la fila "<<i+1<<" y la columna "<<j+1<<": ";
            float valor;
            cin>>valor;
            archivo<<valor;
            archivo<<" ";
        }
        archivo<<"\n";
    }
    archivo.close();
}

void EscribirArchivoBinario (int f, int c)
{
    ofstream archivo;
    ifstream archivotex;
    archivo.open(Archivo_Binario, ios::binary);
    archivo.write((char*)&f, sizeof(int));
    archivo.write((char*)&c, sizeof(int));
    archivo.close();
    archivotex.open(Archivo_Texto);
    while(!archivotex.eof())
    {
        string lineatexto;
        getline(archivotex, lineatexto);
        if(lineatexto.length()>0)
        {
            cout<<"entra"<<endl;
            stringstream separar (lineatexto);
            string numero;
            float valor [c];
            int i=0;
            while(getline(separar, numero, ' '))
            {
                valor[i]=stof(numero);
                i++;
            }
            archivo.open(Archivo_Binario, ios::app | ios::binary);
            archivo.write((char*)valor, c * sizeof(float));
            archivo.close();
        }
    }
    archivotex.close();
}
