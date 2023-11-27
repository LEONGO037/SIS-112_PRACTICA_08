// Materia: Programación I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creación: 26/11/2023
// Fecha modificación: 26/11/2023
// Número de ejericio: 4
// Problema planteado: Amplíe el programa anterior que procesa clientes de una agencia matrimonial para que tome
// los datos de todos los candidatos a estudiar del fichero PERSONAS.DAT del ejercicio anterior,
// lea el cliente del teclado y finalmente genere como resultado un listado por pantalla con los
// nombres de los candidatos aceptados y un fichero llamado ACEPTADOS.DAT con toda la
// información correspondiente a los candidatos aceptados.
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

const char* Nombre_Fichero1 = "Fichero1.bin";
const char* Nombre_Fichero2 = "Fichero2.bin";

struct Articulo
{
    int codigo;
    char nombre[30];
    int existencias;
    float precio;
};

//Ingresar los datos nuevos
vector<Articulo> IngresarDatos();
//Ordena los datos
void OrdenarDatos (vector<Articulo>&);
//Adicionar datos al fichero 1
void ArchivoFichero1 ();
//Adicionar datos al fichero 2
void ArchivoFichero2 ();

void limpiarBuffer();
int main ()
{
    int opcion;
    do
    {
        ifstream arc;
        arc.open(Nombre_Fichero1, ios::binary);
        Articulo articu;
        while(arc.read((char*)&articu, sizeof(Articulo)))
        {
            cout<<articu.codigo<<endl;
            cout<<articu.nombre<<endl;
            cout<<articu.existencias<<endl;
            cout<<articu.precio<<endl;
        }
        arc.close();
        cout<<"1. Ingresar articulos al fichero 1"<<endl;
        cout<<"2. Ingresar articulos al fichero 2"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Opcion a elegir: ";
        cin>>opcion;
        switch(opcion)
        {
        case 1:
            ArchivoFichero1();
            break;
        case 2:
            ArchivoFichero2();
            break;
        case 3:
            cout<<"Salio del sistema"<<endl;
            break;
        default:
            cout<<"Opcion no valida"<<endl;
            break;
        }
    }while(opcion!=3);
    return 0;
}
void limpiarBuffer()
{
    cin.clear();
    cin.ignore(10000, '\n');
}
void ArchivoFichero1 ()
{
    ofstream archivo;
    vector<Articulo> articulos;
    articulos = IngresarDatos();
    for(int i=0;i<articulos.size();i++)
    {
        cout<<articulos[i].codigo<<endl;
        cout<<articulos[i].nombre<<endl;
        cout<<articulos[i].existencias<<endl;
        cout<<articulos[i].precio<<endl;
    }
    archivo.open(Nombre_Fichero1, ios::binary);
    for(int i=0;i<articulos.size();i++)
    {
        archivo.write((char*)&articulos[i], sizeof(Articulo));
    }
    archivo.close();
}
void ArchivoFichero2 ()
{
    ofstream archivo;
    vector<Articulo> articulos;
    articulos = IngresarDatos();
    for(int i=0;i<articulos.size();i++)
    {
        cout<<articulos[i].codigo<<endl;
        cout<<articulos[i].nombre<<endl;
        cout<<articulos[i].existencias<<endl;
        cout<<articulos[i].precio<<endl;
    }
    archivo.open(Nombre_Fichero2, ios::binary);
    for(int i=0;i<articulos.size();i++)
    {
        archivo.write((char*)&articulos[i], sizeof(Articulo));
    }
    archivo.close();
}
void OrdenarDatos (vector<Articulo>& arti)
{
    for(int i=0;i<arti.size();i++)
    {
        for(int j=0;j<arti.size();j++)
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
vector<Articulo> IngresarDatos()
{
    vector<Articulo> art;
    Articulo arti;
    do
    {
        cout<<"Ingrese el codigo del articulo: ";
        cin>>arti.codigo;
        limpiarBuffer();
        if(arti.codigo!=0)
        {
            cout<<"Ingrese el nombre del articulo: ";
            cin.getline(arti.nombre, 30);
            cout<<"Ingrese la cantidad de existencias del aritulo: ";
            cin>>arti.existencias;
            cout<<"Ingrese el precio por unidad del articulo: ";
            cin>>arti.precio;
            art.push_back(arti);
        }
    }while(arti.codigo!=0);
    OrdenarDatos(art);
    return art;
}
