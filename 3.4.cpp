/*
  In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different sizes which can slide onto any tower.
  The puzzle starts with disks sorted in ascending order of size from top to bottom (e.g., each disk sits on top of an even larger one). You have the following constraints:
 (A) Only one disk can be moved at a time. 
 (B) A disk is slid off the top of one rod onto the next rod. 
 (C) A disk can only be placed on top of a larger disk. 
 Write a program to move the disks from the first rod to the last using Stacks.
 */

#include <iostream>
#include <stack>

using namespace std;

class Tower
{
public:
    stack<int> disks;
    int id;
    
    Tower( int num )
    {
        id = num;
    }
};

void moveDisk( int disk, Tower& source, Tower& destination, Tower& aux, int& steps )
{
    if( disk == 1 )
    {
        steps++;
        cout << steps << ": Move " << disk << " from Tower "<< source.id << " to Tower " << destination.id<<"."<<endl;
        destination.disks.push( source.disks.top() );
        source.disks.pop();
    }
    else
    {
        moveDisk( disk - 1, source, aux, destination, steps );
        steps++;
        cout << steps << ": Move " << disk << " from Tower " << source.id << " to Tower " << destination.id<<"."<<endl;
        destination.disks.push( source.disks.top() );
        source.disks.pop();
        moveDisk( disk - 1, aux, destination, source, steps );
    }
}

int main()
{
    int N = 10;
    int steps = 0;
    Tower tower1(1), tower2(2), tower3(3);
    
    for( int i = N; i >= 1 ; i-- )
    {
        tower1.disks.push(i);
    }

    moveDisk( N, tower1, tower2, tower3, steps );
    cout << "It needs " << steps << " steps to move " << N << " disks" << endl;
    
    return 1;
}
