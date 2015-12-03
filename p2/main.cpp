#include <iostream>
using namespace std;

#include "vector_t.hpp"
#include "sparse_vector_t.hpp"

int main(void)
{
    vector_t v(6);

    v[0] = 0.0;
    v[1] = 0.0;
    v[2] = 5.0;
    v[3] = 6.0;
    v[4] = 0.0;
    v[5] = 4.0;
    
    vector_t x(6);

    x[0] = 8.0;
    x[1] = 1.0;
    x[2] = 3.0;
    x[3] = 5.0;
    x[4] = 4.0;
    x[5] = 3.0;
	

    sparse_vector_t s_v(v, 0.0);
    

    v.write(cout);
    
    cout << endl;
    
    s_v.write(cout);
    
    
   cout << s_v.scalprod(x) << endl;
   cout << s_v.suma_elem() << endl;
   cout << s_v.indice(v) << endl;
}
