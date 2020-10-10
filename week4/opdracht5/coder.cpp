#include <iostream>
#include <fstream>

#include "compressor.hpp" 
#include "decompressor.hpp" 

int main( void ){	
   lz_compressor< 4096 > compressor;
 
   std::ifstream f1;
   f1.open( "wilhelmus.txt" );
   if( ! f1.is_open()){
      std::cerr << "input file not opened";
      return -1;      
   }
   
   std::ofstream f2;
   f2.open( "compressed.asm" );
   if( ! f2.is_open()){
      std::cerr << "output file not opened";
      return -1;      
   }

   f2 << ".cpu cortex-m0\n";
   f2 << ".text\n";
   f2 << ".align 2\n";
   f2 << ".global asc\n" << "\n";
   f2 << "asc:\n";
   f2 << "  .asciz \"" ;

   compressor.compress( 
      [ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
      [ &f2 ]( char c ){
         if(c == '\n'){
            f2.put( '\\');
            f2.put( 'n' );
         }
         else{ 
            f2.put( c );
         }
         
      }
   );

   f2 << "\"" ;
   
   f1.close();
   f2.close();
   
   f1.open( "compressed.txt" );
   if( ! f1.is_open()){
      std::cerr << "compressed file not opened";
      return -1;      
   }   

}
