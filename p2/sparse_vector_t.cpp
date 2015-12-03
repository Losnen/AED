#include "sparse_vector_t.hpp"

#include <cmath>

#include <iostream>
#include <iomanip>
using namespace std;

sparse_vector_t::sparse_vector_t(void):
val_(NULL),
n_(0),
nz_(0),
inx_(NULL)
{}


sparse_vector_t::sparse_vector_t(const vector_t& v, double eps):
val_(NULL),
n_(v.get_n()),
nz_(0),
inx_(NULL)
{
    for(int i=0; i<v.get_n();i++)
    {
    	if(fabs(v[i])>eps)
    	{
    		nz_++;

    	}	
    }
    
    val_ = new double [nz_];
    inx_ = new int [n_];
    int aux=0;

	for(int i = 0; i < n_; i++)
    	{
    	if(fabs(v[i])>eps)
    	{
    		inx_[aux]=i;
    		val_[aux]=v[i];
    		aux++;
    	}
    }
}

sparse_vector_t::~sparse_vector_t(void)
{
	if (val_ != NULL)
	{
	  	delete [] val_;
	  	val_ = NULL;
    }

	if (inx_ != NULL)
	{
	  	delete [] inx_;
	  	inx_ = NULL;
    }
    n_=0;
    nz_=0;
}
int sparse_vector_t::get_n(void)
{
	return n_;
}

double sparse_vector_t::scalprod(const vector_t& v)
{
	double aux=0.0;
	for(int i=0; i<n_; i++)
	{
		aux+=val_[i]*v.get_val(inx_[i]);
	}
	
	return aux;

}

ostream& sparse_vector_t::write(ostream& os) const
{
    os << setw(8) << n_ << endl;
    os << setw(8) << nz_ << endl;
    
    for(int i = 0; i < nz_; i++)
        os << setw(8) << fixed << setprecision(4) << val_[i] << " ";
        
    os << endl;
        
    for(int i = 0; i < nz_; i++)
        os << setw(8) << inx_[i] << " ";    
    
    os << endl;
    
    return os;
}

double sparse_vector_t::suma_elem(void)
{
	double suma=0;
	
	for(int i=0; i<nz_; i++)
	{	
		suma+=val_[i];
	}
	
	return suma;
	
}

int sparse_vector_t::indice(vector_t& v)
{
	double aux=0.0;
	int pos=0;
	for(int i=0; i<nz_; i++)
	{
		if( aux < v.get_val(i))
		{
		aux=v.get_val(inx_[i]);
		pos=inx_[i];
		}
	}
	
	return pos;
	
}	


