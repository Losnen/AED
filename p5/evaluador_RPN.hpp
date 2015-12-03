#include <cstring>
#include <cstdlib>
#include "stack_int_t.hpp"

namespace AED {
class evaluador_RPN_t 
{

  private:
   	stack_char_t pila;
  public: 
	
	evaluador_RPN_t(void);
	~evaluador_RPN_t(void);
	int eval(char* expres);
	bool es_operando(char* expres);



};
}
