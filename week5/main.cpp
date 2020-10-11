#include "template.hpp"
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE( "add" ){
    std::stringstream s;
    my_array arr;
    arr.add(4);
    arr.add(2);
    arr.add(6);
    arr.add(2);

    s << arr;

    REQUIRE( s.str() == "{4,2,6}" );   
}

TEST_CASE( "remove" ){
    std::stringstream s;
    my_array arr;
    arr.add(1);
    arr.add(2);
    arr.add(3);

    arr.remove(2);
    arr.remove(4);

    s << arr;
   
    REQUIRE( s.str() == "{1,3}" ); 
}

TEST_CASE( "operator<<" ){
    std::stringstream s;
    my_array arr;
    arr.add(1);
    arr.add(2);

    s << arr;
   
    REQUIRE( s.str() == "{1,2}" );   
}

TEST_CASE( "contains" ){
    my_array arr;
    arr.add(4);
    arr.add(2);
    arr.add(6);

    REQUIRE( arr.contains(2) == true );  
}

