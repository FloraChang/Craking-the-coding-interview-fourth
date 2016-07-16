/*
 You have two numbers represented by a linked list, where each node contains a single digit. 
 The digits are stored in reverse order, such that the 1’s digit is at the head of the list. 
 Write a function that adds the two numbers and returns the sum as a linked list.
 
 EXAMPLE
 Input: (3 -> 1 -> 5), (5 -> 9 -> 2)
 Output: 8 -> 0 -> 8
 */

#include <iostream>

using namespace std;

// node
typedef struct node {
    int data;
    node* next;
} node;

// linked list
class list
{
public:
    
    /* constructor */
    list()
    {
        head = NULL;
        last = NULL;
    }
    /* member functions */
    void addNode( int data )
    {
        node* newNode = new node();
        newNode->data = data;
        
        if( head == NULL )
        {
            head = newNode;
            last = head;
        }
        else
        {
            last->next = newNode;
            last = last->next;
        }
    }
    
    void printList()
    {
        node* current = head;
        while( current != NULL )
        {
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }

    /* member variables */
    node* head;
    node* last;

};

void addList( list* result, node* a, node* b, int carry = 0 );

int main()
{
    // initialize two linked list A, B
    int numberA[5] = { 3, 1, 5, 7, 8 };
    int numberB[4] = { 5, 9, 2 };

    list listA, listB;
    for( int i = 0; i < 5 ; i++ )
    {
        listA.addNode(numberA[i]);
    }
    
    for( int i = 0; i < 4 ; i++ )
    {
        listB.addNode(numberB[i]);
    }
    
    listA.printList();
    listB.printList();
    
    list* result = new list();
    
    // result: add the digits from linked list A and B
    addList( result, listA.head, listB.head );

    result->printList();

    return 1;
}

void addList( list* result, node* a, node* b, int carry )
{
    int sum;
    
    if( a != NULL && b != NULL )
    {
        sum = a->data + b->data + carry;
        result->addNode( sum % 10 );
        carry = sum / 10;
        addList( result, a->next, b->next, carry );
    }
    else if( a != NULL )
    {
        result->addNode( a->data + carry );
        addList( result, a->next, b );
    }
    else if( b != NULL )
    {
        result->addNode( b->data + carry );
        addList( result, a, b->next );
    }
}
