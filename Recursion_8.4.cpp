/* Write a method to compute all permutations of a string */

#include <iostream>
#include <vector>

using namespace std;

vector<string> permutation( string str )
{
    vector<string> result;
    
    if( str == "" )
    {
        result.push_back("");
        return result;
    }
    
    string c = str.substr( 0, 1 ); // get first character
    string remain = str.substr( 1 ); // the reamming sub string
    vector<string> rem = permutation( remain ); // recursion
    
    for( string s : rem ){
        for( int i = 0; i <= s.size(); i++ )
        {
            string temp = s.substr( 0, i ) + c + s.substr( i );
            // cout << temp << endl;
            result.push_back( temp );
        }
    }
    return result;
}


int main()
{
    string str = "abcd";
    vector<string> result = permutation( str );
    cout << "permutation of \"" << str << "\" :" << endl;
    for( string s : result )
    {
        cout << s << endl;
    }
}
