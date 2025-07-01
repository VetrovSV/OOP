#include <stdio.h>
#include <stdlib.h>

// typedef float TData;

/// Узел списка
struct Node {
    TData data;
    struct Node * next;
};

// ...
typedef struct Node   Node;


/// 
Node* create_node(int data){
    Node * node = malloc( sizeof(Node) );
    node->data = data;
    node->next = NULL; 

    return node;
}

#define TData int;

/// ...
void print_list(Node * first ){
    Node* cur = first;

    while( cur != NULL){
        printf("%d  ", cur->data);
        cur = cur->next;
    }
}


/// 
Node* create_random_list(size_t n){
    if ( n == 0 ) return NULL;

    Node * first = create_node( rand()%100 );
    n--;

    Node * last = first;

    while ( n != 0){
        Node *new_node = create_node( rand()%100 );
        last->next = new_node;
        last = new_node;
        n--;
    }

    return first;
}

int main(){

    // Node * head = create_node(10);
    // Node * new_node = create_node(20);
    // head->next = new_node;


    Node * head = create_random_list(15);

    print_list(head);

    puts("");
    // todo: освобождение памяти списка
    return 0;
}