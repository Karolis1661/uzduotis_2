#include <stdio.h>
#include "linkedl.h"

int main(void) {
    
    struct linked_list *head = init_list();

    push(head, "int", 5);
    push(head, "char", "test");
    display(head);

    return 0;
}