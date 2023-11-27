// Materia: Programación I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creación: 26/11/2023
// Fecha modificación: 26/11/2023
// Número de ejericio: 3
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

const char* Nombre_Archivo = "PERSONAS.bin";
const char* Archivo_Aceptados = "PERSONAS.DAT";

struct Persona
{
    char nombre[30];
    int edad;
    char sexo;
    char fechanacimiento [11];
};

//Copia los datos del archivo al programa
void CopiarDatos(vector<Persona>&);
//Busca el nombre de la persona entre los datos
void BuscarCliente(char[30], vector<Persona>);
//Encuentra los candidatos aceptados
void CandidatosAceptados(vector<Persona>, char[11], char);
//Escribir los candidatos aceptados
void EscribirCandidatos (Persona);
int main()
{
    vector<Persona> personas;
    CopiarDatos(personas);
    char NombreCliente[30];
    cout<<"Ingrese el nombre del cliente del que desea saber los candidatos aceptados: ";
    fflush(stdin);
    cin.getline(NombreCliente, 30);
    BuscarCliente(NombreCliente, personas);
    return 0;
}
void EscribirCandidatos (Persona per)
{
    ofstream archivo;
    archivo.open(Archivo_Aceptados, ios::app);
    archivo<<per.nombre;
    archivo<<"\n";
    archivo.close();
}
void CandidatosAceptados(vector<Persona> per, char fecha[11], char sexo)
{
    for(int i=0;i<per.size();i++)
    {
        char* FechasBuscador=strtok(fecha, "/");
        int Buscador[3];
        int f=0;
        while (FechasBuscador != nullptr)
        {
            Buscador[f]=stoi(FechasBuscador);
            f++;
            FechasBuscador = strtok(nullptr, "/");
        }
        char auxi[11];
        strcpy(auxi, per[i].fechanacimiento);
        char* FechasAceptado=strtok(auxi, "/");
        int Aceptado[3];
        f=0;
        while (FechasAceptado != nullptr)
        {
            Aceptado[f]=stoi(FechasAceptado);
            f++;
            FechasAceptado = strtok(nullptr, "/");
        }
        if(Buscador[1]==Aceptado[1] && Buscador[2]==Aceptado[2] && sexo != per[i].sexo)
        {
            cout<<"La persona "<<per[i].nombre<<" es candidata aceptada"<<endl;
            EscribirCandidatos(per[i]);
        }
    }
}
void BuscarCliente(char nom[30], vector<Persona> pers)
{
    int valor=0;
    for(int i=0;i<pers.size();i++)
    {
        if(strcmp(pers[i].nombre, nom) == 0)
        {
            CandidatosAceptados(pers, pers[i].fechanacimiento, pers[i].sexo);
            valor++;
            break;
        }
    }
    if(valor==0)
        cout<<"Cliente no encontrado"<<endl;
}
void CopiarDatos(vector<Persona>& per)
{
    ifstream archivo;
    Persona p;
    archivo.open(Nombre_Archivo, ios::binary);
    while(archivo.read((char*)&p, sizeof(Persona)))
        per.push_back(p);
}
