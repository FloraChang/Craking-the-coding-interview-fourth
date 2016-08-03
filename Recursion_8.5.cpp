/*
 Implement the algorithm to print all valid (e.g., properly opened and closed) combinations of n-pairs of parentheses.
 EXAMPLE:
 input: 3 (e.g., 3 pairs of parentheses)
 output: ()()(), ()(()), (())(), ((()))
 */

#include <iostream>
using namespace std;

void parentheses( int l, int r, char* str, int idx )
{
    if( l < 0 )
        return;
    
    if( l == 0 && r == 0)  // print the string when pairs are arranged completely
    {
        for( int i = 0; i < idx; i++ )
        {
            cout << str[i];
        }
        cout << endl;
        return;
    }

    if( l > 0 ) // add the left parenthese
    {
        str[idx] = '(';
        parentheses( l - 1, r, str, idx + 1 );
    }
    if( r > l ) // add the right parenthese if valid
    {
        str[idx] = ')';
        parentheses( l, r - 1, str, idx + 1 );
    }
}

int main()
{
    int pairs = 0;
    cout << "Enter how many pairs of parenthese: ";
    cin >> pairs;
    
    if( pairs <= 0 )
    {
        cout<< "Invalid number!" << endl;
        return 0;
    }
    
    char *str = new char[ 2 * pairs ]; // new a char string
    parentheses( pairs, pairs, str, 0 );

    return 1;
}
