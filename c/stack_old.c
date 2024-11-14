//
//  stack.c
//  testc
//
//  Created by Benjamin Alexander on 02/09/2023.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int val;
    struct _node* next;
} node;

typedef struct _stack {
    struct _node* head;
    int len;
} stack;

stack* create_stack(void) {
    stack* s = malloc(sizeof(stack));
    s->head = NULL;
    s->len = 0;
    return s;
}

stack* add_node(stack* s, int v) {
    node* new_node = malloc(sizeof(node));
    new_node->val = v;
    new_node->next = NULL;
    
    printf("added node %i\n", v);

    if (s->len == 0) {
        s->head = new_node;
        s->len++;
        return s;
    }
    
    new_node->next = s->head;
    s->head = new_node;
    s->len++;
    return s;
}

void print_stack(stack* s) {
    printf("printing stack...\n");
    if (s->len == 0) {
        printf("empty stack\n");
        return;
    }

    node* current = s->head;
    for (int i = 0; i < s->len; i++) {
        printf("%i ", current->val);
        current = current->next;
    }
    printf("\n");
}

void free_stack(stack* s) {
    printf("freeing stack\n");
    if (s->len == 0) {
        free(s);
        return;
    }
    
    node* current = s->head;
    for (int i = 0; i < s->len; i++) {
        node* tmp = current->next;
        free(current);
        current = tmp;
    }
    free(s);
}

int pop_stack(stack* s) {
    if (s->len == 0) {
        printf("stack empty, cannot pop\n");
        return 0;
    }

    node* next = s->head->next;
    int val = s->head->val;
    free(s->head);
    s->head = next;
    s->len--;
    printf("popped %i off of stack\n", val);
    return val;
}

int peek_stack(stack* s) {
    if (s->len == 0) {
        printf("stack empty, nothing to peek\n");
        return 0;
    }
    int v = s->head->val;
    printf("popped %i off of stack", v);

    return v;
}

int main(int argc, const char * argv[]) {
    stack* s = create_stack();
    for (int i = 0; i < 3; i++) {
        add_node(s, i);
    }
    print_stack(s);
    add_node(s, 6);
    print_stack(s);
    pop_stack(s);
    print_stack(s);
    free_stack(s);
    return 0;
    
}








