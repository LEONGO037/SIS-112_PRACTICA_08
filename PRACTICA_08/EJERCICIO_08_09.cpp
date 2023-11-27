// Materia: Programación I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creación: 26/11/2023
// Fecha modificación: 26/11/2023
// Número de ejericio: 9
// Problema planteado: Dado una tabla grabada en un fichero en formato binario <nombre>.BIN hallar la suma
// horizontal y vertical y grabar la tabla y los resultados en otro fichero de texto o binario según se
// introduzca por pantalla.
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<sstream>
#include<vector>

using namespace std;

const char* Archivo_Texto = "TextoEj9.txt";
const char* Archivo_Binario_Nuevo = "BinarioEj9.bin";
const char* Archivo_Binario = "BinarioEj8.bin";

//Lee el archivo binario con los datos de la tabla
vector<float> LeerArchivoBinario ();
//Convierte a matriz la tabla
vector<vector<float>> ConvertirMatriz(vector<float>);
//Hace la suma de la tabla
void SumaTabla (vector<vector<float>>&);
//Mostrar la matriz
void Imprimir(vector<vector<float>>);
//Elige si guardar en un archivo binario o de texto
void menu (vector<vector<float>>);
//Guarda los datos en un archivo binario
void EnArchivoBinario (vector<vector<float>>);
//Guarda los datos en un archivo de texto
void EnArchivoTexto(vector<vector<float>>);
int main()
{
    fflush(stdin);
    vector<float> numero = LeerArchivoBinario();
    vector<vector<float>> matriz = ConvertirMatriz(numero);
    SumaTabla(matriz);
    Imprimir(matriz);
    cout<<"==============================================="<<endl;
    menu(matriz);
    return 0;
}

void EnArchivoTexto(vector<vector<float>> mat)
{
    ofstream archivo;
    archivo.open(Archivo_Texto);
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[i].size();j++)
        {
            archivo<<mat[i][j];
            archivo<<"\t";
        }
        archivo<<"\n";
    }
}

void EnArchivoBinario (vector<vector<float>> mat)
{
    ofstream archivo;
    archivo.open(Archivo_Binario_Nuevo, ios::binary);
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[i].size();j++)
            archivo.write((char*)&mat[i][j], sizeof(float));
    }
    archivo.close();
}

void menu (vector<vector<float>> mat)
{
    int opcion;
    cout<<"1. Guardar en archivo binario"<<endl;
    cout<<"2. Guardar en archivo de texto"<<endl;
    cout<<"Opcion a elegir: ";
    cin>>opcion;
    switch(opcion)
    {
    case 1:
        EnArchivoBinario(mat);
        break;
    case 2:
        EnArchivoTexto(mat);
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;
    }
}

void Imprimir(vector<vector<float>> mat)
{
    cout<<"Haciendo las sumas de las filas y columnas la tabla queda:"<<endl;
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[i].size();j++)
            cout<<mat[i][j]<<"\t";
        cout<<"\n";
    }
}

void SumaTabla (vector<vector<float>>& mat)
{
    //filas
    for(int i=0;i<mat.size();i++)
    {
        float suma=0.0;
        for(int j=0;j<mat[i].size();j++)
            suma += mat[i][j];
        mat[i].push_back(suma);
    }
    mat.push_back(mat[0]);
    //Columnas
    for(int i=0;i<mat[0].size();i++)
    {
        float suma=0.0;
        for(int j=0;j<mat.size()-1;j++)
            suma += mat[j][i];
        mat[mat.size()-1][i]=suma;
    }
}

vector<vector<float>> ConvertirMatriz(vector<float> num)
{
    vector<vector<float>> matriz;
    int filas = static_cast<int>(num[0]);
    num.erase(num.begin() + 0);
    int columnas = static_cast<int>(num[0]);
    num.erase(num.begin() + 0);
    int cont = 0;
    for(int i=0;i<filas;i++)
    {
        vector<float> fila;
        for(int j=0;j<columnas;j++)
        {
            fila.push_back(num[cont]);
            cont++;
        }
        matriz.push_back(fila);
    }
    return matriz;
}

vector<float> LeerArchivoBinario ()
{
    ifstream archivo;
    archivo.open(Archivo_Binario, ios::binary);
    vector<float> numeros;
    float numero;
    int numentero;
    archivo.read((char*)&numentero, sizeof(int));
    numero=static_cast<float>(numentero);
    numeros.push_back(numero);
    archivo.read((char*)&numentero, sizeof(int));
    numero=static_cast<float>(numentero);
    numeros.push_back(numero);
    while(archivo.read((char*)&numero, sizeof(float)))
        numeros.push_back(numero);
    archivo.close();
    return numeros;
}
