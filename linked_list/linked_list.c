#include <stdio.h>

struct LinkedList{
    int data;
    struct LinkedList *next;
<<<<<<< HEAD
    //*next is a self-referencing pointer to struct LinkedList
};

typedef struct LinkedList *node; 
//Define node as pointer of data type struct LinkedList

node createNode(){
    node temp; // declare a node temp
    temp = (node) malloc ( sizeof( struct LinkedList ) );
    //allocate memory using malloc
    temp->next = NULL; 
    // (*temp).next points to NULL
=======
    /* *next is a self-referencing pointer to struct LinkedList */
};

typedef struct LinkedList *node; /* Define node as pointer of data type struct
LinkedList */

node createNode(){
    node temp; // declare a node
    temp = (node) malloc ( sizeof( struct LinkedList ) );
    /* allocate memory using malloc */
    temp->next = NULL; //make next point to NULL
>>>>>>> 28c979d054b81802529b02f4beddfaaf43c66143
    return temp; // return the new node
}

node addNode( node head, int value ){
<<<<<<< HEAD
    node temp, p; // declare two nodes: temp and p
    temp = createNode(); 
    // create node will return a new node with data = value and next pointing
    // to null 
=======
    node temp, p; // declare two nodes temp and p
    temp = createNode(); 
    /* create node will return a new node with data = value and next pointing
    to null */
>>>>>>> 28c979d054b81802529b02f4beddfaaf43c66143
    temp->data = value; // add element's value to data part of node
    if (head == NULL){
        head = temp; // when linked list is empty
    }
    else {
        p = head; //assign head to p
        while (p->next != NULL) {
            p = p->next; //traverse the list until p is the last node. The
            //last node always points to NULL.
            }
            p->next = temp; //Point the previous last node to the new node 
            //created.
    }
    return head;
}
               
int main() {
    // stuff
}


