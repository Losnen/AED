
#pragma once

#include <stdio.h>		// Cabecera que contendrá el procedimiento sprintf
#include <iostream>		// Cabecera que tendrá la E/S mediante flujo
#include <cmath>		// Cabecera que contendrá las funcioens matemáticas

using namespace std;


//========================================================================================
// Definición de tipos
//========================================================================================

/** Tipo de dato que almacenará cada elemento de la matriz. */
typedef double 		matrix_item_t;	
/** Tipo de dato para índices de la matriz.                 */
typedef unsigned short int 	matrix_inx_t;	
/** Tipo de dato para índices del vector  .                 */
typedef unsigned short int 	vector_inx_t;	

/**
        \author   	Samuel Ramos Barroso 
        \date 		Febrero de 2015

	\details 	Clase que representa una matriz de mxn elementos. */

class matrix_t {

//========================================================================================
// Atributos privados.
//========================================================================================

private:

	matrix_item_t*	M_;	/**< Puntero que apunta al comienzo del vector conteniendo los elementos de la matriz. */

	matrix_inx_t  	m_;	/**< Número de filas.   */
	matrix_inx_t	n_;	/**< Número de columnas.*/



//========================================================================================
// Métodos públicos.
//========================================================================================

public:

/**	
        \author   	Samuel Ramos Barroso 
        \date 		Febrero de 2015

	\details 	Constructor. Reserva memoria para una matriz de mxn elementos.

       * @param 	m número de filas del tipo matrix_inx_t.       
       * @param 	n número de columnas del tipo matrix_inx_t.       
       * @see 		matrix_inx_t.

*/

	matrix_t(matrix_inx_t m,matrix_inx_t n); 

/**	
        \author   	Samuel Ramos Barroso 
        \date 		Febrero de 2015

	\details 	Constructor por defecto. Construye una matriz de dimensión 0x0.

*/

	matrix_t(void); 	

/**
        \author   	Samuel Ramos Barroso 
        \date 		Febrero de 2015

	\details 	Destructor. Libera la memoria de la matriz.
 */

	~matrix_t(void);

/**
       	\author   	Samuel Ramos Barroso 
        \date 		Febrero de 2015

	\details 	Muestra la matriz formateada.

 */

	void  mostrarMatriz(void);


/**
       	\author   	Samuel Ramos Barroso 
        \date 		Febrero de 2015

	\details 	Devuelve el elemento de la posición (i,j) de la matriz.

       * @param 	i fila del elemento.
       * @param 	j columna del elemento
       * @see 		matrix_inx_t.
       * @return 	el valor en la posición (i,j).
       * @see 		vector_inx_t.
 */

	matrix_item_t get_matrix_item(matrix_inx_t i,matrix_inx_t j);


/**
       	\author   	Samuel Ramos Barroso 
        \date 		Febrero de 2015

	\details 	Asigna un valor al elemento (i,j) de la matriz.

       * @param 	it valor a asignar.
       * @param 	i fila del elemento.
       * @param 	j columna del elemento
       * @see 		matrix_inx_t.
  
 */

	void set_matrix_item(matrix_inx_t i,matrix_inx_t j,matrix_item_t it);

/**
       	\author   	Samuel Ramos Barroso 
        \date 		Febrero de 2015

	\details 	Devuelve el número de filas.

       * @return 	el número de filas m_.
       * @see 		matrix_inx_t.
  
 */

	matrix_inx_t get_m(void);


/**
       	\author   	Samuel Ramos Barroso 
        \date 		Febrero de 2015

	\details 	Devuelve el número de columnas.

       * @return 	el número de columnas n_.
       * @see 		matrix_inx_t.
  
 */

	matrix_inx_t get_n(void);

/**
       	\author   	Samuel Ramos Barroso 
        \date 		Febrero de 2015

	\details 	Devuelve el número de columnas.

       * @return 	el número de columnas n_.
       * @see 		matrix_inx_t.
  
 */

	bool cuadrada(void);
/**
       	\author   	Samuel Ramos Barroso 
        \date 		Febrero de 2015

	\details 	Devuelve si la matriz es cuadrada o no 

       * @return 	true o false 
 
  
 */


	void rellenar(void);
/**
       	\author   	Samuel Ramos Barroso 
        \date 		Febrero de 2015

	\details 	rellena la matriz.
  
 */

	bool multiplicable(matrix_t& A, matrix_t& B);
/**
       	\author   	Samuel Ramos Barroso 
        \date 		Febrero de 2015

	\details 	Devuelve si la matrix es multiplicable o no 

       * @return 	true o false.

  
 */

	void producto(matrix_t& A, matrix_t& B);
/**
       	\author   	Samuel Ramos Barroso 
        \date 		Febrero de 2015

	\details 	Hace el proeducto de matrices.

   
  
 */

	double sumafila(int i);
	double sumadiagonal(void);




//========================================================================================
// Métodos privados.
//========================================================================================

private:

/**
        \author   	Samuel Ramos Barroso 
        \date 		Febrero de 2015

	\details 	Devuelve la posición k dentro del vector M_ del elemento (i,j) de la matriz.

       * @param  	i fila del elemento.
       * @param  	j columna del elemento.
       * @see 		matrix_inx_t.
       * @return 	el índice k.
       * @see 		vector_inx_t.
 */

	vector_inx_t pos(matrix_inx_t i,matrix_inx_t j);

/**	
        \author   	Samuel Ramos Barroso 
        \date 		Febrero de 2015

	\details 	Reserva memoria para una matriz de mxn elementos.

       * @param 	m número de filas del tipo matrix_inx_t.       
       * @param 	n número de columnas del tipo matrix_inx_t.       
       * @see 		matrix_inx_t.
*/

	void crearMatriz(void); 
	

/**
        \author   	Samuel Ramos Barroso 
        \date 		Febrero de 2015

	\details 	Libera la memoria de la matriz.
 */

	void destruirMatriz(void);

/**
        \author   	Samuel Ramos Barroso 
        \date 		Febrero de 2015

	\details 	Redimensiona la matriz. Destruye la anterior, borrando su contenido, y construye una nueva matriz con la dimensión especificada.

       * @param  	m nuevo número de filas.
       * @param  	n nuevo número de columnas.
       * @see 		matrix_inx_t.   
 */

	void redimensiona(matrix_inx_t m,matrix_inx_t n);
};


