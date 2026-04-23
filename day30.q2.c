#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    int arr[100];
    int top;
};

void push(struct Stack* s, int x) {
    s->arr[++s->top] = x;
}

int pop(struct Stack* s) {
    return s->arr[s->top--];
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

struct Node* newNode(int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = x;
    node->next = NULL;
    return node;
}

struct Node* addLists(struct Node* l1, struct Node* l2) {
    struct Stack s1, s2;
    s1.top = s2.top = -1;

    while(l1) {
        push(&s1, l1->data);
        l1 = l1->next;
    }

    while(l2) {
        push(&s2, l2->data);
        l2 = l2->next;
    }

    int carry = 0;
    struct Node* head = NULL;

    while(!isEmpty(&s1) || !isEmpty(&s2) || carry) {
        int sum = carry;

        if(!isEmpty(&s1))
            sum += pop(&s1);

        if(!isEmpty(&s2))
            sum += pop(&s2);

        struct Node* node = newNode(sum % 10);
        node->next = head;
        head = node;

        carry = sum / 10;
    }

    return head;
}

struct Node* create(int n) {
    struct Node *head = NULL, *temp = NULL;
    int x;
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node* node = newNode(x);
        if(head == NULL) {
            head = temp = node;
        } else {
            temp->next = node;
            temp = node;
        }
    }
    return head;
}

void display(struct Node* head) {
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n1, n2;
    scanf("%d", &n1);
    struct Node* l1 = create(n1);

    scanf("%d", &n2);
    struct Node* l2 = create(n2);

    struct Node* result = addLists(l1, l2);
    display(result);

    return 0;
}