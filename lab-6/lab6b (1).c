#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;     // For stack
struct node *front = NULL;   // For queue
struct node *rear = NULL;


void push() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to push: ");
    scanf("%d", &newnode->data);
    newnode->next = top;
    top = newnode;
    printf("Pushed successfully.\n");
}


void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct node *temp = top;
    printf("Popped: %d\n", temp->data);
    top = top->next;
    free(temp);
}

void displayStack() {
    struct node *temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void enqueue() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to enqueue: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (rear == NULL)
        front = rear = newnode;
    else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("Enqueued successfully.\n");
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    struct node *temp = front;
    printf("Dequeued: %d\n", temp->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void displayQueue() {
    struct node *temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int choice;

    while (1) {
        printf("\nMENU (Stack & Queue using Linked List)\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue\n");
        printf("5. Dequeue\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: displayStack(); break;
            case 4: enqueue(); break;
            case 5: dequeue(); break;
            case 6: displayQueue(); break;
            case 7: return 0;
            default: printf("Invalid choice\n");
        }
    }
}



