/*
Una empresa tiene diez almacenes y necesita crear un programa que lea las ventas mensuales de los diez almacenes, calcular la media de ventas y obtener un  listado de los almacenes cuyas ventas mensuales son superiores a la media.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>

using namespace std;

int tiendas=5;

struct Almacenes{
  string nombre;
  float venta;
} almacen[5];

int main(){
  for (int x=0; x<tiendas; x++){
    cout << "Ingrese el nombre del almacen" << "\n";
    cin >> almacen[x].nombre;
    cout << "Ingrese venta mensual" << "\n";
    cin >> almacen[x].venta;
  }

  // Mostrar la media
  float media=0;
  for (int x=0; x<tiendas; x++){
    media=media+almacen[x].venta;
  }
  // sacamos la media
  media=media/tiendas;
  for (int x=0; x<=tiendas; x++){
    if (almacen[x].venta>media){
      cout << almacen[x].nombre << "  " << almacen[x].venta << "\n";
    }
    
  }
  return 0;
}
