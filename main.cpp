#include "hwlib.hpp"

extern "C" void uart_put_char( char c ){
   hwlib::cout << c;
}

extern "C" void print_asciz(const char * s);

extern "C" void application();

extern "C" char convert_char( char c ){
   if(c>64 && c<91){
      c+=32;
   }
   else if(c>96 && c<123){
      c-=32;
   }
   return c;
}



int main( void ){	
   
   namespace target = hwlib::target;   
    
   // wait for the PC console to start
   hwlib::wait_ms( 2000 );

   application();
   
}
