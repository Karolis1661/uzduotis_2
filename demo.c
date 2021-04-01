#include <stdio.h>
#include "library_files/linkedl.h"

int main(void) {

    struct linked_list *p_head = init_list();

    push(p_head, "int", 10);
    push(p_head, "char", "test");
    push(p_head, "int", 15);
    push(p_head, "int", 1123);
    push(p_head, "int", 156);
    push(p_head, "char", "test123");

    pop(p_head);
    pop(p_head);
    pop(p_head);
    pop(p_head);
    pop(p_head);
    pop(p_head);
    

    return 0;
}