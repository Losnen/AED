#include "matrix_t.hpp"

#include <iomanip>
#include <cstdio>
#include <cmath>

int main (void){
  
   AED::matrix_t aux;
   AED::matrix_t x;
   cin >> x;
   cout << endl;
     
   
   x.ObtenerMenor(3,3,aux);
   
   cout << "|Matriz A|"<< endl;
   cout << x;
   cout << endl;
   cout << "----------------------------------------------------------------" << endl << endl;
   cout << "|Matriz Menor A|"<< endl;
   cout << aux;
   cout << endl;
   cout << "----------------------------------------------------------------" << endl << endl;
   cout << "El determinante de la matriz A es : ";
   cout << x.Determinante() << endl << endl;
   cout << "----------------------------------------------------------------" << endl << endl;
   
   AED::matrix_t y;
   cin >> y;
   
     
   x.inversa(x);
  
   cout << "|Matriz A inversa| "<<endl;
   cout << x;
   cout << endl;
   cout << "----------------------------------------------------------------" << endl << endl;
   cout << "|Matriz b|"<< endl;
   cout << y;
   cout << endl;
   cout << "----------------------------------------------------------------" << endl << endl;
   
   AED::matrix_t Z;
   
   cout << "|Matriz Solución x|"<< endl;;
   Z.multiplica(x,y);
   cout << Z;
}
