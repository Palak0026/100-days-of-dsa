#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* rotateRight(struct Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    int n = getLength(head);
    k = k % n;
    if (k == 0) return head;

    struct Node* tail = head;
    while (tail->next) tail = tail->next;

    tail->next = head;

    int steps = n - k;
    struct Node* temp = head;

    for (int i = 1; i < steps; i++) temp = temp->next;

    struct Node* newHead = temp->next;
    temp->next = NULL;

    return newHead;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        struct Node* node = createNode(x);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    int k;
    scanf("%d", &k);

    head = rotateRight(head, k);

    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}