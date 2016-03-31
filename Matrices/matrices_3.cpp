#include "matrices_3.hpp"

#define MAX_MATRIX_ITEM 100

//========================================================================================
// Métodos privados.
//========================================================================================



vector_inx_t matrix_t::pos(matrix_inx_t i,matrix_inx_t j)
{
	if ((i<1)||(i>m_)||(j<1)||(j>n_)){
		std::cerr << "Error accediendo a matriz"<< std::endl;
		return 0;
        }

	return (i-1)*n_+j-1;


}



void matrix_t::crearMatriz(void) 
{
	M_= new matrix_item_t [m_*n_];	// Crea un vector de mxn elementos. 
	
	if (M_==NULL)  		// Si ha fallado la reserva de memoria. 
		std::cerr << "Error creando matriz." << std::endl;
}		



void matrix_t::destruirMatriz(void)
{
	if (M_!=NULL){
		delete [] M_;		// Libera la memoria previamente reservada para la matriz.
		M_=NULL;		// Asigna NULL al puntero.
	}

	m_=0;
	n_=0;
}




void matrix_t::redimensiona(matrix_inx_t m,matrix_inx_t n)
{
	destruirMatriz();

	m_=m;
	n_=n;

	crearMatriz();
}




//========================================================================================
// Métodos públicos.
//========================================================================================

matrix_t::matrix_t(matrix_inx_t m,matrix_inx_t n):
M_(NULL),
m_(m),
n_(n)
{
	crearMatriz();
}	




matrix_t::matrix_t(void):
M_(NULL),
m_(0),
n_(0)
{}		



matrix_t::~matrix_t(void)
{
	destruirMatriz();
}



void  matrix_t::mostrarMatriz(void)
{

	char aux[80];

	for(int i=1;i<=m_;i++){
	
		std::cout << "|";	
		for(int j=1;j<=n_;j++){
			sprintf(aux," %10.6lf ",get_matrix_item(i,j));
			cout << aux;
		}
		std::cout << " |";
		cout << endl;
	}

	cout << endl;	
}

void matrix_t::rellenar(void)
	{
		double numero; 
		for (int i=1; i<=m_; i++){
			for (int j=1; j<=n_; j++){
				cout << "Escribe los numeros: "	;		
				cin >> numero;
				set_matrix_item(i,j,numero);
			}
		}
	}


matrix_item_t matrix_t::get_matrix_item(matrix_inx_t i,matrix_inx_t j)
{
	return M_[pos(i,j)];
}


void matrix_t::set_matrix_item(matrix_inx_t i,matrix_inx_t j,matrix_item_t it)
{
	M_[pos(i,j)]=it;	
}




matrix_inx_t matrix_t::get_m(void)
{
	return m_;
}




matrix_inx_t matrix_t::get_n(void)
{
	return n_;
}

bool matrix_t::cuadrada(void)
{
	bool cuad = false;
	if (get_m() == get_n())
	{
		cuad = true;
		return cuad;
	}
	else
	{
		cuad = false;
		return cuad; 
	}
}


bool matrix_t::multiplicable(matrix_t& B, matrix_t& C)
{
	bool mult = false;
	if ((B.get_m() == C.get_n()))
	{
		mult = true;
		return mult;
	}
	else
	{
		mult = false;
		return mult; 
	}
}
void matrix_t::producto(matrix_t& B, matrix_t& C)
{
	if(multiplicable(B,C) == true){				
		redimensiona(B.get_m(), C.get_n());
		
		for (int i=1; i<=B.get_m(); i++){
			for (int j=1; j<=C.get_n(); j++){
				double aux = 0.0;
				set_matrix_item(i,j,aux);
				
				for (int k=1; k<=B.get_n(); k++){
					aux+=B.get_matrix_item(i,k)*C.get_matrix_item(k,j);
					set_matrix_item(i,j,aux);
					
				}
			}
		}

	}
	else{
		cerr << "Error, no se pueden multiplicar" << endl;
	}
}
double matrix_t::sumafila(int i)
{
	double suma=0.0;
	
	for (int j=1; j<=get_n(); j++)
	{
		suma+=get_matrix_item(i,j);	
	}
	
	cout << suma << endl;
	return suma;
}

double matrix_t::sumadiagonal(void)
{
	double suma=0.0;
	if(cuadrada()==true)
	{
		for(int i=1; i<=get_m(); i++)
		{	
			suma+=get_matrix_item(i,i);
		}
	}		
	
	cout << suma << endl;
	return suma;
}


