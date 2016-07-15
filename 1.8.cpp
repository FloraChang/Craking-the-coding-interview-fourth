/* 
 Assume you have a method isSubstring which checks if one word is a substring of another.
 Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring
 (i.e., "waterbottle" is a rotation of "erbottlewat").
 */

#include <iostream>
#include <string>
using namespace std;

bool isSubString( string a, string b );
bool isRotation( string a, string b );

int main(int argc, char *argv[])
{
    string a = "apple";
    string b = "leapp";

    if( isRotation( a, b ) )
    {
        cout<< b <<" is a rotation of " << a << endl;
    }
    else
    {
        cout<< b <<" is not a rotation of "<< a << endl;
    }
    return 1;
}

bool isSubString( string a, string b )
{
    if( a.find(b) != string::npos )
    {
        return true;
    }
    return false;
}

bool isRotation( string a, string b )
{
    if( a.length() != b.length() )
    {
        return false;
    }
    else
    {
        return isSubString( a + a, b ); // key idea is to concatenate "string a" itself
    }
}
