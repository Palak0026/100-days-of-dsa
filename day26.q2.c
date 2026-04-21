#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} MyLinkedList;

MyLinkedList* create() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

int get(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return -1;
    Node* temp = obj->head;
    for (int i = 0; i < index; i++) temp = temp->next;
    return temp->val;
}

void addAtHead(MyLinkedList* obj, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = obj->head;
    obj->head = node;
    obj->size++;
}

void addAtTail(MyLinkedList* obj, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;

    if (obj->head == NULL) obj->head = node;
    else {
        Node* temp = obj->head;
        while (temp->next) temp = temp->next;
        temp->next = node;
    }
    obj->size++;
}

void addAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size) return;

    if (index == 0) {
        addAtHead(obj, val);
        return;
    }

    Node* temp = obj->head;
    for (int i = 0; i < index - 1; i++) temp = temp->next;

    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = temp->next;
    temp->next = node;

    obj->size++;
}

void deleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return;

    if (index == 0) {
        Node* temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    } else {
        Node* temp = obj->head;
        for (int i = 0; i < index - 1; i++) temp = temp->next;
        Node* del = temp->next;
        temp->next = del->next;
        free(del);
    }

    obj->size--;
}

void display(MyLinkedList* obj) {
    Node* temp = obj->head;
    while (temp) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    MyLinkedList* list = create();

    addAtHead(list, 1);
    addAtTail(list, 3);
    addAtIndex(list, 1, 2);

    printf("%d\n", get(list, 1));

    deleteAtIndex(list, 1);

    printf("%d\n", get(list, 1));

    display(list);

    return 0;
}