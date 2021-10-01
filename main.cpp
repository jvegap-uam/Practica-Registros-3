/*
    Listar los empleados menores de 25 años
    Buscar los empleados que viven en X ciudad
    Ordenar el vector por Nombre y listarlo
    Salir*/

#include <iostream>
#include <cstring>
#include <string>

void listaMenores25();
void buscarCiudad();
void ordenarNombre();
void ingresarEmpleado();
void menu();

using namespace std;

struct empleados{
    char nombre[50];
    struct{
        char departamento[20], ciudad[20], barrio[50], direccion[150];
    }ubicacion;
    int edad;
    char sexo;
} empleado[50];
int maxNum=1;

int main(){
    menu();
    return 0;
}

void ingresarEmpleado(){
    int seguir=1;
    int i=0;
    cout << "---------------------" << endl;
    cout << "Ingresar empleados al sistema: " << endl;
    while (seguir==1){
        cout << "Empleado " << i << ": " << endl;
        cout << "Nombre: "; cin.ignore();
        cin.getline(empleado[i].nombre, 50);
        cout << "Ubicacion: " << endl;
        cout << "   Departamento: ";
        cin.getline (empleado[i].ubicacion.departamento, 20);
        cout << "   Ciudad: ";
        cin.getline (empleado[i].ubicacion.ciudad, 20);
        cout << "   Barrio: ";
        cin.getline (empleado[i].ubicacion.barrio, 50);
        cout << "   Direccion: ";
        cin.getline (empleado[i].ubicacion.direccion, 150);
        cout << "Edad: "; cin >> empleado[i].edad;
        cout << "Sexo (M,F): "; cin >> empleado[i].sexo;

        cout << "Desea seguir agregando empleados? (0,1): "; cin >> seguir;
        if (seguir==1){
            i++;
            maxNum++;
        }
    }

    menu();
}

void listaMenores25(){
    cout << "---------------------" << endl;
    cout << "Lista de empleados menores de 25 anios: " << endl;
    for (int i=0; i<maxNum; i++){
        if (empleado[i].edad<25){
            cout << i << ". " << empleado[i].nombre << endl;
            cout << "   Departamento: " << empleado[i].ubicacion.departamento << endl;
            cout << "   Ciudad: " << empleado[i].ubicacion.ciudad << endl;
            cout << "   Barrio: " << empleado[i].ubicacion.barrio << endl;
            cout << "   Direccion: " << empleado[i].ubicacion.direccion << endl;
            cout << "   Edad: " << empleado[i].edad << endl;
            cout << "   Sexo: "<< empleado[i].sexo << endl;
        }
    }
}

void buscarCiudad(){
/*    char citySearch[20];
    int result[maxNum];
    cout << "---------------------" << endl;
    cout << "Ingrese la ciudad por la que quiera filtrar a los empleados: ";
    cin.ignore();
    cin.getline(citySearch,20);
    for (int i=0; i<maxNum; i++){
        result[i]=strcmp(citySearch, empleado[i].ubicacion.ciudad);
        if (result[i]==0){
            cout << i << ". " << empleado[i].nombre << endl;
            cout << "   Departamento: " << empleado[i].ubicacion.departamento << endl;
            cout << "   Ciudad: " << empleado[i].ubicacion.ciudad << endl;
            cout << "   Barrio: " << empleado[i].ubicacion.barrio << endl;
            cout << "   Direccion: " << empleado[i].ubicacion.direccion << endl;
            cout << "   Edad: " << empleado[i].edad << endl;
            cout << "   Sexo: "<< empleado[i].sexo << endl;
        }
    }*/
    bool busca = false;
    char citySearch[20];
    cout << "---------------------" << endl;
    cout << "Ingrese la ciudad por la que quiera filtrar a los empleados: ";
    cin.ignore();
    cin.getline(citySearch, 20);
    for (int i = 0; i < maxNum; i++) {
        if (empleado[i].ubicacion.ciudad == citySearch) {
            cout << i << ". " << empleado[i].nombre << endl;
            cout << "   Departamento: " << empleado[i].ubicacion.departamento << endl;
            cout << "   Ciudad: " << empleado[i].ubicacion.ciudad << endl;
            cout << "   Barrio: " << empleado[i].ubicacion.barrio << endl;
            cout << "   Direccion: " << empleado[i].ubicacion.direccion << endl;
            cout << "   Edad: " << empleado[i].edad << endl;
            cout << "   Sexo: " << empleado[i].sexo << endl;
            busca = true;
        }
    }
    if (!busca)
        cout << "\nNo se encontraron empleados de " << citySearch;
}

void ordenarNombre(){
    char temp[50];

    for (int j=0; j<50; j++){
        for (int i=j+1; i<49; i++){
            if (strcmp(empleado[j].nombre,  empleado[i].nombre) > 0){
                strcpy(temp, empleado[j].nombre);
                strcpy(empleado[j].nombre, empleado[i].nombre);
                strcpy(empleado[i].nombre, temp);
                }
            }
        }
    }


void menu(){
    int opt;

    cout << "---------------------" << endl;
    cout << "Opciones: " << endl;
    cout << " 1) Agregar empleados. \n 2) Listar los empleados menores de 25 años. \n 3) Buscar los empleados que viven en X ciudad. \n 4) Ordenar el vector por Nombre y listarlo. \n 5) Salir." << endl;
    cout << "Opcion: "; cin >> opt;
    switch (opt){
        case 1:
            ingresarEmpleado();
            break;
        case 2:
            listaMenores25();
            break;
        case 3:
            buscarCiudad();
            break;
        case 4:
            ordenarNombre();
            break;
        case 5:
            break;
    }
}
