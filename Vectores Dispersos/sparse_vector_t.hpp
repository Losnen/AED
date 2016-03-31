#pragma once

#include "vector_t.hpp"


class sparse_vector_t
{
  private:
    double* val_; // Vector que almacena los valores de los elementos no nulos
    int     n_;   // Número de elementos del vector original
    int     nz_;  // Número de elementos no nulos
    int*    inx_; // Vector que almacena las posiciones de los elementos no nulos. 
  public:
  	sparse_vector_t(void); // Constructor por defecto
  	sparse_vector_t(const vector_t& v, double eps); // Constructor de copia
   	~sparse_vector_t(void); // Destructor
   	int get_n(void); // Devuelve el numero de elementos del vector
   	ostream& write(ostream& os) const; // Método que imprime el vector.
	double scalprod(const vector_t& v); // Producto escalar
	double suma_elem(void);
	int indice(vector_t& v);
};
