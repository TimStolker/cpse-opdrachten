#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP
#include <array>
#include <iostream>

class my_array {
private:
    std::array< int, 10 > arr;
    int arraySize = 0;

public:
    void add( int number ){
        if(arraySize==10){               //check vol
            return;
        }
        for( const auto & x : arr ){     //loop door de array heen
            if(x==number){
                return;
            }
        }
        arr[ arraySize ] = number;
        arraySize+=1;

   }

    void remove(int number){                 
        for( int i=0; i<arraySize; i++ ){
            if(arr[i] == number){
                arraySize -= 1;
                for(int j=i; j<arraySize; j++){
                    arr[j] = arr[j+1];
                }
                break;  
            }
        }
    }

    bool contains(int number){
        for( const auto & x : arr ){     //loop door de array heen
            if(x==number){
                return true;             //true als het nummer erin zit
            }
        }
        return false;
    }

    friend std::ostream &operator<<( std::ostream & lhs, const my_array & rhs){
        lhs << "{";
        for( int i = 0; i < rhs.arraySize; i++ ){     //loop door de array heen
            lhs << rhs.arr[ i ];
            if(!(i==rhs.arraySize-1)){
                lhs << ",";
            }
        }
        lhs << "}";
        return lhs;
    }

};





#endif
