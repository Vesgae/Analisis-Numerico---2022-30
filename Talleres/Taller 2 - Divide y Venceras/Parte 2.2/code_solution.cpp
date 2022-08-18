//Edwin Vesga - Nicolas Ramos
#include <cmath>
#include <iostream>
using namespace std;
int toBinary(int l, int posicion);
int binary_invert_iterative(int binary, int cifras);
int main() {
  int numero;
  int numero_binario;
  int cifras;
  cout<<"Ingerse el numero a probar: ";
  cin>>numero;
  numero_binario = toBinary(numero, 1);
  cifras;= log10(numero_binario);
  cout << numero_binario << endl;
  cout << cifras << endl;
  cout << binary_invert_iterative(numero_binario, cifras) << endl;
}
int toBinary(int l, int posicion) {
  int cifra_binaria = l % 2;
  int nuevo_numero = l / 2;
  if (nuevo_numero == 0) {
    return cifra_binaria * posicion;
  } else {
    return (cifra_binaria * posicion) + toBinary(nuevo_numero, posicion * 10);
  }
}
int binary_invert_iterative(int binary, int cifras) {
  int posicion_cifra = 0;
  int binario_invertido = 0;
  int nuevo_binario = binary;
  cifras += 1;
  if (binary == 1 || binary == 0) {
    return binary;
  }
  for (int i = cifras - 1; i >= 0; i--) {
    posicion_cifra = pow(10, i);
    binario_invertido += ((nuevo_binario % 10) * posicion_cifra);
    nuevo_binario /= 10;
  }
  return binario_invertido;
}
