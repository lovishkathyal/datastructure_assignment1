#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void add(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int findMiddle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int main() {
    struct Node* head1 = NULL;
    add(&head1, 1);
    add(&head1, 2);
    add(&head1, 3);
    add(&head1, 4);
    add(&head1, 5);
    
    printf("Input linked list: ");
    printList(head1);
    printf("Output middle node: %d\n", findMiddle(head1)); // Output: 3

    struct Node* head2 = NULL;
    add(&head2, 1);
    add(&head2, 2);
    add(&head2, 3);
    add(&head2, 4);
    add(&head2, 5);
    add(&head2, 6);

    printf("Input linked list: ");
    printList(head2);
    printf("Output middle node: %d\n", findMiddle(head2)); // Output: 4

    return 0;
}
