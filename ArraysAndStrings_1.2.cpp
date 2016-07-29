/*
 Write code to reverse a C-Style String. 
 ( C-String means that "abcd" is represented as five characters, including the null character. )
*/

#include <iostream>
#include <string>
using namespace std;

void reverse( char* cstring );

int main(int argc, char *argv[])
{
    char cstring[256];
    cout<<"enter a string to reverse: "<<endl;
    cin>>cstring;
    cout<<cstring<<endl;
    reverse( cstring );
    cout<< cstring<<endl;
}

void reverse( char* cstring )
{
    int len = (int)strlen(cstring) + 1; // get the length of the c-type string
    char *temp = new char[len];
    int i, j;
    for( i = len-2, j = 0; i >= 0 && j < len ; i--, j++ )
    {
        temp[j] = cstring[i];
    }
    
    temp[len-1]='\0';
    
    for(int i= 0; i<len;i++){
        cstring[i] = temp[i];
    }
    delete []temp;
}
