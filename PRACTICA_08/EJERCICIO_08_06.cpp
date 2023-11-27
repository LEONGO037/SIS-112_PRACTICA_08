// Materia: Programación I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creación: 26/11/2023
// Fecha modificación: 26/11/2023
// Número de ejericio: 6
// Problema planteado: Escriba un programa que tome como entrada el fichero del ejercicio 4 y una condición sobre el
// campo Precio. La condición podrá ser:
// Precio mayo o igual a 100 o cualquier otro dato ingresado por teclado.
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

const char* Nombre_Fichero1 = "Fichero1.bin";
const char* Nombre_Seleccionado = "salida.dat";

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
vector<Articulo> Condicion (vector<Articulo>, float);
//Crea el nuevo archivo combinado
void SubirDatos (vector<Articulo>);
//Muestra los datos
void Mostrar(vector<Articulo>);

int main ()
{
    vector<Articulo> articulos;
    articulos = Descargar();
    float precio;
    cout<<"Ingrese la condicion del precio: ";
    cin>>precio;
    vector<Articulo> nuevos;
    nuevos = Condicion(articulos, precio);
    SubirDatos(nuevos);
    Mostrar(nuevos);
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

vector<Articulo> Condicion (vector<Articulo> arti, float precio)
{
    vector<Articulo> nuevo;
    for(int i=0;i<arti.size();i++)
    {
        if(arti[i].precio>=precio)
            nuevo.push_back(arti[i]);
    }
    return nuevo;
}

void SubirDatos (vector<Articulo> arti)
{
    ofstream archivo;
    archivo.open(Nombre_Seleccionado, ios::app);
    for(int i=0;i<arti.size();i++)
    {
        archivo<<arti[i].codigo;
        archivo<<";";
        archivo<<arti[i].nombre;
        archivo<<";";
        archivo<<arti[i].existencias;
        archivo<<";";
        archivo<<arti[i].precio;
        archivo<<"\n";
    }
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
    return articulos;
}
