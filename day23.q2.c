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

int hasCycle(struct Node *head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int n, value, pos;
    struct Node *head = NULL, *temp = NULL, *newNode, *cycleNode = NULL;
    
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }

        if(i == 0) cycleNode = head;
    }

    scanf("%d", &pos);

    if(pos >= 0) {
        temp = head;
        for(int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        struct Node *last = head;
        while(last->next != NULL) {
            last = last->next;
        }
        last->next = temp;
    }

    if(hasCycle(head))
        printf("true");
    else
        printf("false");

    return 0;
}