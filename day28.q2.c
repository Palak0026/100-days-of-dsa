#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

struct Node* reverse(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(struct Node* head) {
    if (!head || !head->next) return true;

    struct Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* second = reverse(slow);
    struct Node* first = head;

    while (second) {
        if (first->data != second->data) return false;
        first = first->next;
        second = second->next;
    }

    return true;
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

    if (isPalindrome(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}