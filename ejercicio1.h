/*
Ejercicio # 1: Usar estructuras y grabar datos a un archivo, utilizar funciones

Descripción de problema:  Escribir una función Salario que calcule los salarios de un trabajador para un número dado de horas trabajadas y un salario hora.
Las horas que superen las 40 horas semanales se pagarán como extras con un salario hora 1,5 veces el salario ordinario. Así mismo se deberá calcular el monto a pagar de IGSS por cada trabajador.

El programa debera contener un menu para:
1) Invocar dicha funcion y grabar datos a un archivo,
2) Adicionalmente deberá tener una opción para leer el archivo y grabar los datos en memoria. 
3) Una opción para mostrar cuanto se paga de total de planilla e IGSS.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include<ctime> 
#include <stdio.h>
#include <vector>
using namespace std;

float total_igss;
vector<string> en_memoria;

struct Trabajadores {
  string nombre;
  float salario_x_h;
  int horas_trabajadas;
  float salario_semana;
  int horas_extras;
  float igss;
};



void calculo_grabar()
{
    Trabajadores x;

    cout << "Ingrese el nombre del trabajador: " << "\n";
    cin >> x.nombre;
    cout << "Ingrese el salario por hora del trabajador: " << "\n";
    cin >> x.salario_x_h;
    cout << "Ingrese el total de horas trabajas del trabajador: " << "\n";
    cin >> x.horas_trabajadas;

    // declaro las variables para el calculo
    float extra_total, igss, total;
    int tiempoextra;

    if (x.horas_trabajadas > 40) {
      tiempoextra=x.horas_trabajadas-40;
      cout << tiempoextra;

      extra_total=(tiempoextra*1.5)*x.salario_x_h;
      
      total=((x.horas_trabajadas-tiempoextra)*x.salario_x_h)+extra_total;
      

    } else {
      total=(x.horas_trabajadas*x.salario_x_h);
    }
    x.salario_semana=total;
    x.horas_extras=tiempoextra;
    x.igss=total*(4.83/100);
    total_igss=total_igss+x.igss;

    // grabamos en el archivo.
    ofstream miarchivo("planilla.txt", std::ios_base::app);
    miarchivo << x.nombre << endl;
    miarchivo << x.salario_x_h << endl;
    miarchivo << x.horas_trabajadas << endl;
    miarchivo << x.salario_semana << endl;
    miarchivo << x.horas_extras << endl;
    miarchivo << x.igss << endl;

    //Cerramos la escritura del archivo.
    miarchivo.close();
}

void leer_archivo(){
    //declaramos la variable para leer archivo
    ifstream miarchivo;
    
    //std::ifstream file("myfile", std::ios::binary | std::ios::ate);
    //abrimos archivo 
    miarchivo.open("planilla.txt",ios::in);
    
    //declare string to hold each line of text
    string line;

    //loop through myinfile while line exist
    while(getline(miarchivo,line))
    {
        cout << line << endl;
        // grabo en memoria
        en_memoria.push_back(line);
    }

    //make sure and close ifstream
    miarchivo.close();
    string empty;
    cin >> empty;
    return;

}

int main() {
  int contador;
  char tecla;
  string empty;
  bool bandera=false;
  
  do
    {
        system("clear");
        cin.clear();
        cout << "Calculo de Salario" << endl;
        cout << "-----------" << endl << endl;
        cout << "\t1 .- Ingresar Trabajador" <<endl;
        cout << "\t2 .- Leer registros y grabar en memoria" <<endl;
        cout << "\t3 .- Mostrar total de planilla" << endl;
        cout << "\t4 .- Salir" << endl << endl;
        cout << "Elije una opcion: ";
 
        cin >> tecla;
 
		switch(tecla)
    		{
			case '1':
				system("clear");
        calculo_grabar();
        contador=contador+1;
        break;
 
			case '2':
        system("clear");
        leer_archivo();
        break;
      
      case '3':
        system("clear");
        cout << "El total de planilla del IGSS es de:" << "\n";
        cout << "Q." << total_igss;
        cin >> empty;
        break;

      case '4':
				bandera=true;
				//exit(1);
				break;
 
			default:
				system("clear");
				cout << "Opcion no valida.\a\n";
				getchar();
        getline(cin, empty);
				break;
		}
    }while(bandera!=true);
  
  return 0;
}
