#include <iostream>
#include "buffer.hpp"
#include <cstring>
// g++ -g main_buffer.cpp buffer.cpp dll_t.cpp  dll_node_t.cpp dll_char_node_t.cpp  queue_char_t.cpp

int main(void)
{ 
    aed_buff_t alm(10);
    char cadena[] = "En un lugar de la Mancha de cuyo nombre no quiero acordarme, no ha mucho tiempo que vivía un hidalgo de los de lanza en astillero, adarga antigua, rocín flaco y galgo corredor";
                
    for (int i=0; i<strlen(cadena); i++) 
    {
        alm.put(cadena[i]); 
       
    }
}  