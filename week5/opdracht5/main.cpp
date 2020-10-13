#include "template.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE( "add" ){
    std::stringstream s;
    my_array<int, 10> arr;
    arr.add(4);
    arr.add(2);
    arr.add(6);
    arr.add(2);

    s << arr;

    REQUIRE( s.str() == "{4,2,6}" );   
}

TEST_CASE( "remove" ){
    std::stringstream s;
    my_array<int, 10> arr;
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
    my_array<int, 10> arr;
    arr.add(1);
    arr.add(2);

    s << arr;
   
    REQUIRE( s.str() == "{1,2}" );   
}

TEST_CASE( "contains" ){
    my_array<int, 10> arr;
    arr.add(4);
    arr.add(2);
    arr.add(6);

    REQUIRE( arr.contains(2) == true );  
}

TEST_CASE( "max" ){
    my_array<int, 10> arr;
    arr.add(1);
    arr.add(3);
    arr.add(666);
    arr.add(2);
   
    REQUIRE( arr.max() == 666 );   
}

TEST_CASE( "type int" ){
    std::stringstream s;
    my_array<int, 3> arr;
    arr.add(4);
    arr.add(2);
    arr.add(6);

    s << arr;

    REQUIRE( s.str() == "{4,2,6}" );  
}

TEST_CASE( "type char" ){
    std::stringstream s;
    my_array<char, 3> arr;
    arr.add('r');
    arr.add('b');
    arr.add('c');

    s << arr;

    REQUIRE( s.str() == "{r,b,c}" );  
}


TEST_CASE( "max char" ){
   my_array< std::array< char, 3>, 3 > big_array;
   std::array< char, 3> array1 {'a','b','c'};
   std::array< char, 3> array2 {'x','y','z'};
   std::array< char, 3> array3 {'g','h','i'};
   big_array.add(array1);
   big_array.add(array2);
   big_array.add(array3);

   REQUIRE( big_array.max() == array2 );  
}

