#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
};
 
typedef struct LinkedList
{
    struct Node *head;
};

void insert_node(struct Node* node, struct Node* newNode) {
    newNode->next = node->next;
    node->next = newNode;
   
}

void print_list(struct LinkedList* list) {
    struct Node* temp = list->head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete_node(struct LinkedList* list, struct Node *deleteNode) {
    struct Node* temp = list->head;
    struct Node* prev = list->head;

    while (temp != deleteNode)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == list->head)
        list->head = temp->next;
    else
        prev->next = temp->next;
        
}


int main()
{
    struct Node headNode;
    headNode.data = 2;
    headNode.next = NULL;
    
    struct LinkedList testList;
    testList.head = &headNode;
    
    struct Node tempNode1;
    tempNode1.data = 4;
    tempNode1.next = NULL;
    insert_node(testList.head,&tempNode1);
    
    print_list(&testList);
    
    struct Node tempNode2;
    tempNode2.data = 10;
    tempNode2.next = NULL;
    insert_node(testList.head,&tempNode2);
    
    print_list(&testList);
    
    delete_node(&testList,&tempNode2);
    
    print_list(&testList);
}
