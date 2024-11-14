#include <stdlib.h>
#include <stdio.h>

typedef struct _stack {
    node* head;
    int len;
} stack;

typedef struct _node {
    struct _node* next;
    int val;
} node;


stack* create_stack(void) {
    stack* s = malloc(sizeof(stack));

    s->head = NULL;
    s->len = 0;
    
    return s;
}

stack* push(int value, stack* s) {
    node* new_node = malloc(sizeof(node));

    new_node->val = value;
    new_node->next = NULL;

    new_node->next = s->head;
    s->len++;

    s->head = new_node;

    return s;
}

stack* print_stack(stack* s) {
    if (s->len == 0) {
        printf("empty stack.");
        return s;
    }

    node* current_node = s->head;

    while (current_node != NULL) {
        printf("%i ", current_node->val);
        current_node = current_node->next;
    }
    printf("stack printed\n");

    return s;
}

void free_stack(stack* s) {

    if (s->head == NULL) {
        free(s);
        return;
    }

    node* current_node = s->head;

    while (current_node != NULL) {
        node* tmp = current_node->next;
        free(current_node);
        current_node = tmp;
    }

    free(s);
}

int pop_stack(stack* s) {
    if (s->len == 0) {
        printf("you cant pop from an empty stack");
        return -1;
    }

    node* new_head = s->head->next;
    int val = s->head->val;

    free(s->head);
    s->head = new_head;

    s->len--;

    return val;
}











