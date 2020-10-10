#include "hwlib.hpp"

extern "C" void uart_put_char( char c ){
   hwlib::cout << c ;
}

extern "C" void decode();



int main(){
   hwlib::wait_ms(100);
   decode();


}
