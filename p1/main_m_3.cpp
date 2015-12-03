#include "matrices_3.hpp"

int main(void)
{
	matrix_t A;
	matrix_t B(2,3);
	matrix_t C(3,2);
	matrix_t D(2,2);

	B.rellenar();
	B.mostrarMatriz();
	C.rellenar();
	C.mostrarMatriz();
	B.sumafila(2);	
	C.sumafila(2);
	D.rellenar();
	D.mostrarMatriz();
	D.sumadiagonal();

	A.producto(B,C);
	A.producto(C,B);
	A.mostrarMatriz();	
		

	
		
}
