#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Display the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void bubbleSort(struct Node* head) {
    if (head == NULL) return;

    int swapped;
    struct Node* ptr;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != NULL) {
            if (ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
    } while (swapped);
}

struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* nextNode;

    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}


struct Node* concatenate(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct Node* temp = list1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = list2;
    return list1;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int choice, value;

    while (1) {
        printf("\n== LINKED LIST OPERATIONS ==\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Bubble Sort List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate List 1 + List 2\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert in List 1: ");
                scanf("%d", &value);
                insertEnd(&list1, value);
                break;

            case 2:
                printf("Enter value to insert in List 2: ");
                scanf("%d", &value);
                insertEnd(&list2, value);
                break;

            case 3:
                printf("List 1: ");
                display(list1);
                break;

            case 4:
                printf("List 2: ");
                display(list2);
                break;

            case 5:
                bubbleSort(list1);
                printf("List 1 after Bubble Sort:\n");
                display(list1);
                break;

            case 6:
                list1 = reverse(list1);
                printf("List 1 after Reversing:\n");
                display(list1);
                break;

            case 7:
                list1 = concatenate(list1, list2);
                printf("List 1 after Concatenation:\n");
                display(list1);
                break;

            case 8:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

