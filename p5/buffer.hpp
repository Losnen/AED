#include "queue_char_t.hpp"
#include <iostream>

class aed_buff_t
{
    private:
        AED::queue_char_t    cola;
        int             max_buff_sz_;
        int             curr_buff_sz_;
        
    public:
    
        aed_buff_t(int max_buff_sz);
        ~aed_buff_t(void);
        void flush(void);
        void put (char c);

};
