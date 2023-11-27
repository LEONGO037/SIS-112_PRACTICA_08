// Materia: Programación I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creación: 26/11/2023
// Fecha modificación: 26/11/2023
// Número de ejericio: 5
// Problema planteado: Escriba un programa que dados dos ficheros generados por el programa anterior y ordenados
// genere un tercer fichero que sea el resultado de mezclar de formar ordenada los dos primeros.
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

const char* Nombre_Fichero1 = "Fichero1.bin";
const char* Nombre_Fichero2 = "Fichero2.bin";
const char* Nombre_Fichero3 = "Fichero3.bin";

struct Articulo
{
    int codigo;
    char nombre[30];
    int existencias;
    float precio;
};

//Copia los datos de los archivos al programa
vector<Articulo> Descargar ();
//Ordena los datos
void OrdenarDatos (vector<Articulo>&);
//Crea el nuevo archivo combinado
void SubirDatos (vector<Articulo>);
//Muestra los datos
void Mostrar(vector<Articulo>);

int main ()
{
    vector<Articulo> articulos;
    articulos = Descargar();
    SubirDatos(articulos);
    Mostrar(articulos);
    return 0;
}

void Mostrar(vector<Articulo> art)
{
    for(int i=0;i<art.size();i++)
    {
        cout<<"El codigo del articulo es: "<<art[i].codigo<<endl;
        cout<<"El nombre del articulo es: "<<art[i].nombre<<endl;
        cout<<"El numero de existencias es: "<<art[i].existencias<<endl;
        cout<<"El precio del articulo es: "<<art[i].precio<<endl;
        cout<<"=========================================================="<<endl;
    }
}

void OrdenarDatos (vector<Articulo>& arti)
{
    for(int i=0;i<arti.size();i++)
    {
        for(int j=0;j<arti.size()-1;j++)
        {
            if(arti[j].codigo>arti[j+1].codigo)
            {
                Articulo temp = arti[j];
                arti[j] = arti[j+1];
                arti[j+1]=temp;
            }
        }
    }
}
void SubirDatos (vector<Articulo> arti)
{
    ofstream archivo;
    archivo.open(Nombre_Fichero3, ios::app | ios::binary);
    for(int i=0;i<arti.size();i++)
        archivo.write((char*)&arti[i], sizeof(Articulo));
    archivo.close();
}

vector<Articulo> Descargar ()
{
    vector<Articulo> articulos;
    Articulo art;
    ifstream archivo1;
    archivo1.open(Nombre_Fichero1, ios::binary);
    while(archivo1.read((char*)&art, sizeof(Articulo)))
        articulos.push_back(art);
    archivo1.close();
    ifstream archivo2;
    archivo2.open(Nombre_Fichero2, ios::binary);
    while(archivo2.read((char*)&art, sizeof(Articulo)))
        articulos.push_back(art);
    archivo2.close();
    OrdenarDatos(articulos);
    return articulos;
}
