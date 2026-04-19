#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

struct Node {
    int key;
    int count;
    struct Node* next;
};

struct Node* hashTable[SIZE];

int hash(int key) {
    return abs(key) % SIZE;
}

void insert(int key) {
    int index = hash(key);
    struct Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->key == key) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int getCount(int key) {
    int index = hash(key);
    struct Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->key == key) {
            return temp->count;
        }
        temp = temp->next;
    }

    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }

    int sum = 0;
    int count = 0;

    insert(0);

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        count += getCount(sum);
        insert(sum);
    }

    printf("%d\n", count);

    return 0;
}