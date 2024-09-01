#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CircularQueue {
    struct Node* front;
    struct Node* rear;
};

void initializeQueue(struct CircularQueue* queue) {
    queue->front = queue->rear = NULL;
}

int isEmpty(struct CircularQueue* queue) {
    return queue->front == NULL;
}

void enQueue(struct CircularQueue* queue, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    printf("Input operation: enQueue(%d)\n", value);

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
        queue->rear->next = queue->front;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
        queue->rear->next = queue->front;
    }

    printf("%d inserted into the queue.\n", value);
}

int deQueue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Input operation: deQueue()\n");
        printf("Output: Queue is empty.\n");
        return -1;
    }

    int value;
    struct Node* temp = queue->front;

    printf("Input operation: deQueue()\n");

    if (queue->front == queue->rear) {
        value = queue->front->data;
        free(queue->front);
        queue->front = queue->rear = NULL;
    } else {
        value = queue->front->data;
        queue->front = queue->front->next;
        queue->rear->next = queue->front;
        free(temp);
    }

    printf("Output: %d removed from the queue.\n", value);
    return value;
}

int front(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Input operation: front()\n");
        printf("Output: Queue is empty.\n");
        return -1;
    }

    printf("Input operation: front()\n");
    printf("Output: Front element is %d.\n", queue->front->data);
    return queue->front->data;
}

int rear(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Input operation: rear()\n");
        printf("Output: Queue is empty.\n");
        return -1;
    }

    printf("Input operation: rear()\n");
    printf("Output: Rear element is %d.\n", queue->rear->data);
    return queue->rear->data;
}

int main() {
    struct CircularQueue queue;
    initializeQueue(&queue);

    enQueue(&queue, 10);
    enQueue(&queue, 20);
    enQueue(&queue, 30);
    front(&queue);
    rear(&queue);
    deQueue(&queue);
    deQueue(&queue);
    deQueue(&queue);
    deQueue(&queue);

    return 0;
}
