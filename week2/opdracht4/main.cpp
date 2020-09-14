
#include "fur_elise.hpp"
#include "rtttl_player.hpp"
#include <fstream>
#include <string>
#include <iostream>

const char sos[]          = "SOS:d=4,o=5,b=60:a,p,a,p,a,p,2a.,p,2a.,p,2a.,p,a,p,a,p,a";
const char let_it_be[]    = "Beatles Let It Be:d=4,o=5,b=100:16e6,8d6,c6,16e6,8g6,8a6,8g.6,16g6,8g6,8e6,16d6,8c6,16a,8g,e.6,p,8e6,16e6,8f.6,8e6,8e6,8d6,16p,16e6,16d6,8d6,2c.6";
const char muppets[]      = "Muppets:d=4,o=5,b=250:c6,c6,a,b,8a,b,g,p,c6,c6,a,8b,8a,8p,g.,p,e,e,g,f,8e,f,8c6,8c,8d,e,8e,8e,8p,8e,g,2p,c6,c6,a,b,8a,b,g,p,c6,c6,a,8b,a,g.,p,e,e,g,f,8e,f,8c6,8c,8d,e,8e,d,8d,c";
const char rickroll[]     = "Never gonna give you up:d=4,o=5,b=120:16c,16d,16f,16d,16a.,16p,32p,8a,16p,g.,16c,16d,16f,16d,16g.,16p,32p,8g,16p,8f.,16e,8d,16c,16d,16f,16d,f,8g,8e.,16d,8c,8c4,8c,8g,8p,2f,16c,16d,16f,16d,16a.,16p,32p,8a,16p,g.,16c,16d,16f,16d,c6,8e,8f.,16e,8d,16c,16d,16f,16d,f,8g,8e.,16d,8c,8c4,8c,8g,8p,2f";
const char one[]          = "NumberOne:d=16,o=5,b=168:4f.,8c6,16b5,16c6,16b5,16c6,8b5,8c6,4g#5,4f.,8f,8g#5,8c6,4c#6,4g#5,4c#6,4d#6,8c6,8c#6,8c6,8c#6,2c6";


class note_player_pc : public note_player  {
private:
   std::ofstream & myfile;
public:
   note_player_pc(std::ofstream & myfile):
      myfile( myfile )
   {}

   void play( const note & n){
      std::string freq = "";
      std::string dur = "";

      if(n.duration == 440){
         freq = "note::A4";
      }
      else if(n.frequency == 466){
         freq = "note::A4s";
      }
      else if(n.frequency == 494){
         freq = "note::B4";
      }
      else if(n.frequency == 523){
         freq = "note::C5";
      }
      else if(n.frequency == 554){
         freq = "note::C5s";
      }
      else if(n.frequency == 587){
         freq = "note::D5";
      }
      else if(n.frequency == 622){
         freq = "note::D5s";
      }
      else if(n.frequency == 659){
         freq = "note::E5";
      }
      else if(n.frequency == 698){
         freq = "note::F5";
      }
      else if(n.frequency == 740){
         freq = "note::F5s";
      }
      else if(n.frequency == 740){
         freq = "note::F5s";
      }
      else if(n.frequency == 784){
         freq = "note::G5";
      }
      else if(n.frequency == 830){
         freq = "note::G5s";
      }
      else if(n.frequency == 880){
         freq = "note::A5";
      }
      else if(n.frequency == 932){
         freq = "note::A5s";
      }
      else if(n.frequency == 987){
         freq = "note::B5";
      }


      if(n.duration == 1000000){
         dur = "note::dF";
      }
      else if(n.duration == 500000){
         dur = "note::dH";
      }
      else if(n.duration == 250000){
         dur = "note::dQ";
         
      }

      if(freq == ""){
         freq = std::to_string(n.frequency);
      }
      if(dur == ""){
         dur = std::to_string(n.duration);
      }


      myfile << "    p.play( note{ " << freq << ",  " << dur << " } ); \n";
   
      std::cout<< n.frequency << " " << n.duration <<  std::endl;

   }
};

int main( void ){	 

   
   std::ofstream myfile; 
   auto p = note_player_pc(myfile);
   myfile.open("melody.cpp");
   myfile << "#include \"melody.hpp\" \n" << "void melody::play( note_player & p ){ \n";

   
   
   
   if( 0 ){
      auto fe = fur_elise();
      fe.play( p );
   }      
   
   if( 0 ){ rtttl_play( p, sos ); }   
   if( 0 ){ rtttl_play( p, let_it_be );  }
   if( 0 ){ rtttl_play( p, muppets );  }
   if( 1 ){ rtttl_play( p, rickroll );  }
   if( 0 ){ rtttl_play( p, one );  }
   
   myfile << "} \n";
   myfile.close();
}
