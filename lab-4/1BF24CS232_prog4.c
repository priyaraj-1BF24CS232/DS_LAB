#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void createNode(int n) {
    struct Node *newNode, *temp;
    int data, i;

    if (n <= 0) {
        printf("Should be more than 0\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory alloc failed\n");
            return;
        }        
        printf("Enter the data for node %d : ", i);
        scanf("%d", &data);
        newNode -> data = data;
        newNode -> next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp -> next = newNode;
        }
        temp = newNode;
    }

    printf("Linked list created successfully \n");
}

void insertAtBeginning (int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> next = head;
    head = newNode;
    printf("Node is inserted at the beginning\n");
}

void insertAtEnd (int value) { 
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp -> next;
        }
        temp -> next = newNode;
    }

    printf("Node is inserted at the end\n");
}

void insertAtAny (int value, int pos) {
    int i;
    struct Node *newNode, *temp = head;

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;

    for (i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp -> next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    } else {
        newNode -> next = temp -> next;
        temp -> next = newNode;
        printf("Node inserted at position %d\n", pos);
    }
}

void display() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("\nLinked List : ");
    while (temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int main() {
    int choice, n, data, pos;
    while (1) {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Any Position\n");
        printf("4. Insert at End\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            createNode(n);
            break;
            
        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
        case 3:
            printf("Enter data and position: ");
            scanf("%d %d", &data, &pos);
            insertAtAny(data, pos);
            break;
        case 4:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Try again \n");
        }
    }
    return 0;
}
