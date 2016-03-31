#include "buffer.hpp"
    
        aed_buff_t::aed_buff_t(int max_buff_sz):
        cola(),
        max_buff_sz_(max_buff_sz),
        curr_buff_sz_(0){}
        
        aed_buff_t::~aed_buff_t(void)
        {
            flush();
        }
        
        void aed_buff_t::flush(void)
        {
            while(!cola.empty())
            {
                cout << cola.get();
                
            }
            curr_buff_sz_=0; 
            cout << endl;
        }
        
        void aed_buff_t::put(char c)
        {
            if(curr_buff_sz_==max_buff_sz_)
            flush();
            
            cola.put(c);
            curr_buff_sz_++;
        }
