#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int val) {
    struct Node* newNode = createNode(val);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

struct Node* removeElements(struct Node* head, int val) {
    struct Node dummy;
    dummy.next = head;

    struct Node* prev = &dummy;
    struct Node* curr = head;

    while (curr != NULL) {
        if (curr->val == val) {
            prev->next = curr->next;
        } else {
            prev = curr;
        }
        curr = curr->next;
    }

    return dummy.next;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    int arr[] = {1,2,6,3,4,5,6};
    int n = 7;

    for (int i = 0; i < n; i++)
        append(&head, arr[i]);

    int val = 6;

    head = removeElements(head, val);

    printList(head);

    return 0;
}