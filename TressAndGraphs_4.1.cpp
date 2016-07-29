/* 
 Implement a function to check if a tree is balanced. For the purposes of this question, 
 a balanced tree is defined to be a tree such that no two leaf nodes differ in distance from the root by more than one.
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
    int data;
    node* l;
    node* r;
};

int maxDepth( node* root )
{
    if( root == NULL )
    {
        return 0;
    }
    return 1 + max( maxDepth( root->l ), maxDepth( root->r ) );
}

int minDepth( node* root )
{
    if( root == NULL )
    {
        return 0;
    }
    return 1 + min( maxDepth( root->l ), maxDepth( root->r ) );
}

bool isBalanced( node* root )
{
    return ( maxDepth(root) - minDepth(root) <= 1 );
}

int main()
{
    node* head = NULL;
    cout << isBalanced( head ) << endl;
}
