#include <stdio.h>
#include <stdlib.h>

int *queue;
int rear = -1, front = -1, capacity = 3;

void enqueue(int x);
void dequeue();
void rearele();
void frontele();
int isEmpty();
int isFull();
void display();

int main() {
    int ch, x;

    queue = (int*)calloc(capacity, sizeof(int));

    do {
        printf("\nMENU:\n1. INSERT\n2. DELETE\n3. REAR ELEMENT\n4. FRONT ELEMENT\n5. DISPLAY\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                rearele();
                break;
            case 4:
                frontele();
                break;
            case 5:
                display();
                break;
            default:
                printf("Wrong Choice\n");
        }
    } while (ch >= 1 && ch <= 5);

    free(queue);
    return 0;
}

void enqueue(int x) {
    if (isFull()) {
        printf("Queue is full, resizing...\n");
        int newCapacity = 2 * capacity;
        int* temp = (int*)calloc(newCapacity, sizeof(int));
        int i, j = 0;

        for (i = front; i != rear; i = (i + 1) % capacity) {
            temp[j++] = queue[i];
        }
        temp[j++] = queue[rear]; // Add the last element

        free(queue);
        queue = temp;
        front = 0;
        rear = capacity - 1; // Set rear to the last valid index
        capacity = newCapacity;
    }

    rear = (rear + 1) % capacity;
    queue[rear] = x;
    if (front == -1) front = 0;
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is underflow\n");
        return;
    }

    printf("Deleted element is %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % capacity;
    }
}

void rearele() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue rear element is: %d\n", queue[rear]);
}

void frontele() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue front element is: %d\n", queue[front]);
}

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (rear + 1) % capacity == front;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");
    for (int i = front; i != rear; i = (i + 1) % capacity) {
        printf("%d\t", queue[i]);
    }
    printf("%d\n", queue[rear]);
}
