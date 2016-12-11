/* Write a method to compute all subset(combination) of a string */

#include <iostream>
#include <vector>

using namespace std;

void combination( string str, vector<string>& result )
{
  int size = (int)str.length();
  int max = 1 << size;
  // cout << "max = " << max << endl;
  
  for( int i = 0; i < max; i++ )
  {
    int num = i;
    string temp ="";

    for( int index = size-1; index >= 0; index-- )
    {
      if( (num & 1)  == 1 )
      {
        temp+=str[index];
      }

      num = num >> 1;
    }
    result.push_back(temp);
  }
}

int main()
{
  vector<string> result;
  string str;

  cout << "Enter a string:" << endl;
  cin >> str;
  combination( str, result );

  for( string s : result )
  {
    cout << s << endl;
  }
  return 1;
}
