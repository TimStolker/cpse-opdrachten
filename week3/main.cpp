#include "hwlib.hpp"
#include "hwlib.hpp"

constexpr double pow( double g, int n ){
   double result = 1;
   while( n > 0 ){
       result *= g;
       --n;
   }
   return result;
}

constexpr double fac( int n ){
   double result = 1;
   while( n > 0 ){
       result *= n;
       --n;
   }
   return result;
}

constexpr double sin( double a ){
   return 
      a 
      - pow( a, 3 ) / fac( 3 ) 
      + pow( a, 5 ) / fac( 5 ) 
      - pow( a, 7 ) / fac( 7 )
      + pow( a, 9 ) / fac( 9 ) 
      - pow( a, 11 ) / fac( 11 ) 
      + pow( a, 13 ) / fac( 13 );
}

constexpr double cos( double a ){
   return 
      1 
      - pow( a, 2 ) / fac( 2 ) 
      + pow( a, 4 ) / fac( 4 ) 
      - pow( a, 6 ) / fac( 6 )
      + pow( a, 8 ) / fac( 8 ) 
      - pow( a, 10 ) / fac( 10 ) 
      + pow( a, 12 ) / fac( 12 )
      - pow (a, 14) / fac( 14 );
       
}

constexpr double radians_from_degrees( int degrees ){
   return 2 * 3.14 * ( degrees / 360.0 );
}

constexpr double scaled_sine_from_degrees( int degrees ){
   return 30 * ( 1.0 + sin( radians_from_degrees( degrees )));
}

constexpr double scaled_cosine_from_degrees( int degrees ){
   return 30 * ( 1.0 + cos( radians_from_degrees( degrees )));
}

   
template< int N, typename T >
class lookup {
private:    
   std::array< T, N > values = {};

public: 

   template< typename F >
   constexpr lookup( F function ){
      for( int i = 0; i < N; i++ ){
          values[ i ] = function( i*6 );
      }
   }

   constexpr T get( int n ) const {
      return values[ n ];    
   }
};

void clock(auto &display, auto targetMin, auto targetHour){
   display.clear();

   constexpr auto sinusses = lookup< 60, int >( scaled_sine_from_degrees );
   constexpr auto cosinusses = lookup< 60, int >( scaled_cosine_from_degrees );

   for(int i = 0; i<60; i+=5){
      display.write(hwlib::xy(sinusses.get( i )+32, cosinusses.get( i )));  //32 voor in het midden

   }
   auto hour = hwlib::line(hwlib::xy(64,32), targetHour);
   auto min = hwlib::line(hwlib::xy(64,32), targetMin);

   min.draw(display);
   hour.draw(display);

   display.flush();

}



int main( void ){	 



   namespace target = hwlib::target;
   
   auto scl = target::pin_oc( target::pins::scl );
   auto sda = target::pin_oc( target::pins::sda );
   
   auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );
   
   auto display = hwlib::glcd_oled( i2c_bus, 0x3c );  

   auto sw1 = hwlib::target::pin_in( hwlib::target::pins::d7 );
   auto sw2 = hwlib::target::pin_in( hwlib::target::pins::d6 );
   
   constexpr auto sinusses = lookup< 60, int >( scaled_sine_from_degrees );
   constexpr auto cosinusses = lookup< 60, int >( scaled_cosine_from_degrees );

   auto start = hwlib::now_us();
   int i = 59;
   int j = 59;
   while(true){
      if(sw1.read() == 0){
         if(i != 0){
            i--;
         } 
      }
      if(sw2.read() == 0){
         if(j != 0){
            j-=5;
         } 
      }
      if(hwlib::now_us() > (start + 60000000)){
            hwlib::cout << "loop?" << hwlib::endl;
         i--;
         auto targetMin = hwlib::xy(sinusses.get( i )+32, cosinusses.get( i ));  //32 voor in het midden
         auto targetHour = hwlib::xy(sinusses.get( j )+32, cosinusses.get( j ));
         if(i == 0){
            i = 59;
            j-=5;
            if(j < 5){
               j = 59;
            }
         }
         clock(display,targetMin,targetHour);
         start = hwlib::now_us();

      }
       
   }
   
     

}
