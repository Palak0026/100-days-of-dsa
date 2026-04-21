#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
bool removeLoop(struct Node* head) {
    if (!head || !head->next) return false;

    struct Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) break;
    }

    if (slow != fast) return false;

    slow = head;

    if (slow == fast) {
        while (fast->next != slow) fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    fast->next = NULL;
    return true;
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(3);
    head->next->next = createNode(4);

    head->next->next->next = head->next;

    if (removeLoop(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}