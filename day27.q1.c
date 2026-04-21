#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        while (diff--) head1 = head1->next;
    } else {
        while (diff--) head2 = head2->next;
    }

    while (head1 && head2) {
        if (head1 == head2) return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    int n, m;
    scanf("%d", &n);

    struct Node *head1 = NULL, *tail1 = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        struct Node* newNode = createNode(x);
        if (!head1) head1 = tail1 = newNode;
        else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    scanf("%d", &m);

    struct Node *head2 = NULL, *tail2 = NULL;

    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        struct Node* newNode = createNode(x);
        if (!head2) head2 = tail2 = newNode;
        else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    struct Node* temp1 = head1;
    while (temp1 && temp1->data != 30) temp1 = temp1->next;

    if (tail2) tail2->next = temp1;

    struct Node* intersection = getIntersection(head1, head2);

    if (intersection) printf("%d\n", intersection->data);
    else printf("No Intersection\n");

    return 0;
}