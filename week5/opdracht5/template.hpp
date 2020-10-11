#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP
#include <array>
#include <iostream>

template< typename T, int N >
class my_array {
private:
    std::array< T, N > arr;
    int arraySize = 0;

public:
    void add( T var ){
        if(arraySize==N){               //check vol
            return;
        }
        for( const auto & x : arr ){     //loop door de array heen
            if(x==var){
                return;
            }
        }
        arr[ arraySize ] = var;
        arraySize+=1;

    }

    void remove(T var){                 
        for( int i=0; i<arraySize; i++ ){
            if(arr[i] == var){
                arraySize -= 1;
                for(int j=i; j<arraySize; j++){
                    arr[j] = arr[j+1];
                }
                break;  
            }
        }
    }

    bool contains(T var){
        for( const auto & x : arr ){     //loop door de array heen
            if(x==var){
                return true;             //true als het nummer erin zit
            }
        }
        return false;
    }

    T max(){
        T maximum = arr[0];
        for( int i=0; i<arraySize; i++ ){     //loop door de array heen
            if(arr[i] > maximum){
                maximum = arr[i];
            }
        }
        return maximum;
    }

    friend std::ostream &operator<<( std::ostream & lhs, const my_array & rhs){
        lhs << "{";
        for( int i = 0; i < rhs.arraySize; i++ ){     //loop door de array heen
            lhs << rhs.arr[ i ];
            if(!(i==rhs.arraySize-1)){                //check voor de laatste in de array om daar geen ',' achter te zetten
                lhs << ",";
            }
        }
        lhs << "}";
        return lhs;
    }

};

#endif
