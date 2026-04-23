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

struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* temp = &dummy;
    dummy.next = NULL;

    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }

        struct Node* node = createNode(sum % 10);
        carry = sum / 10;

        temp->next = node;
        temp = node;
    }

    return dummy.next;
}

int main() {
    int n1, n2;
    scanf("%d", &n1);

    struct Node *l1 = NULL, *t1 = NULL;
    for (int i = 0; i < n1; i++) {
        int x;
        scanf("%d", &x);
        struct Node* node = createNode(x);
        if (!l1) l1 = t1 = node;
        else {
            t1->next = node;
            t1 = node;
        }
    }

    scanf("%d", &n2);

    struct Node *l2 = NULL, *t2 = NULL;
    for (int i = 0; i < n2; i++) {
        int x;
        scanf("%d", &x);
        struct Node* node = createNode(x);
        if (!l2) l2 = t2 = node;
        else {
            t2->next = node;
            t2 = node;
        }
    }

    struct Node* result = addTwoNumbers(l1, l2);

    while (result) {
        printf("%d ", result->data);
        result = result->next;
    }

    return 0;
}