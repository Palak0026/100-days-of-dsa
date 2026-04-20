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

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) tail->next = l1;
    else tail->next = l2;

    return dummy.next;
}

int main() {
    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL, *temp = NULL, *newNode;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);
        if(head1 == NULL) {
            head1 = newNode;
            temp = head1;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &m);
    temp = NULL;
    for(int i = 0; i < m; i++) {
        scanf("%d", &value);
        newNode = createNode(value);
        if(head2 == NULL) {
            head2 = newNode;
            temp = head2;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    struct Node* merged = mergeLists(head1, head2);

    temp = merged;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}