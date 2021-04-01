#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>
#include <assert.h>

#define IS_INT 1
#define IS_CHAR 2

struct linked_list {
    int data_type;
    void *data;
    struct linked_list *previous;
    struct linked_list *next;
    struct linked_list *tail;
};

struct linked_list *init_list(void) {
    /*
        * Initialize structs node
        * Assign default values -> -1 and NULL
        * Return node
    */

    struct linked_list *head = malloc(sizeof(struct linked_list));
    if (head == NULL) {
        puts("Memory allocation for init_list failed.");
        exit(EXIT_FAILURE);
    }

    head->data_type = -1;  // -1 means no data type is stored
    head->data = NULL;
    head->previous = NULL;
    head->next = NULL;
    head->tail = NULL;
    
    return head;
}

int check_type(const char *input_type) {
    
    if (strcmp(input_type, "int") == 0) {
        return 1;
    }
    else if (strcmp(input_type, "char") == 0) {
        return 2;
    }
    else {
        return 0;
    }
}

struct linked_list *ret_int_node(struct linked_list *const head_node, const int input_value) {

    struct linked_list *temp_node = init_list();

    temp_node->data = malloc(sizeof(int));
    if (temp_node->data == NULL) {
        puts("Memory allocation for init_list failed.");
        exit(EXIT_FAILURE);
    }

    *((int *) temp_node->data) = input_value;
    temp_node->data_type = IS_INT;
    
    return temp_node;
}

struct linked_list *ret_char_node(struct linked_list *const head_node, char *const input_value) {

    // It would be a great to check if input is really a char* and not an int
    // But how? 

    struct linked_list *temp_node = init_list();

    temp_node->data = malloc((strlen(input_value) + 1) * sizeof(char));
    if (temp_node->data == NULL) {
        puts("Memory allocation for char failed.");
        exit(EXIT_FAILURE);
    }

    strcpy( ((char *)temp_node->data) , input_value);
    temp_node->data_type = IS_CHAR;

    return temp_node;
}

int pop(struct linked_list *const head_node) {
    /*
        *Remove last value of the linked list
    */

    if(head_node->data == NULL) {
        // Nothing to pop out
        return 1;
    }

    if (head_node->next != NULL) {
        struct linked_list *temp_node;

        // Capture last node
        temp_node = head_node->tail;
       
        free(temp_node->data);
        
        // Go to previous node
        temp_node = temp_node->previous;
        
        free(temp_node->next);
        temp_node->next = NULL;
     
        // Update linked list last value
        head_node->tail = temp_node;

        return 0;
    } 
    else {
        // Reset head node when nothing else left
        free(head_node->data);
        head_node->data = NULL;
        head_node->data_type = -1;
        head_node->tail = NULL;
        
        return 2;
    }

    return -1;
}

int add_node(struct linked_list *const head_node, struct linked_list *temp_node) {
    
    // Adding a first node
    if(head_node->data_type == -1) {

        // Copy struct values
        *head_node = *temp_node;

        // Leave temp_node->data allocated memory for head node
        // and free rest of the struct
        free(temp_node);
        temp_node = NULL;

        return 0;
    }

    // Adding a second node to linked list
    if (head_node->data_type != -1 && head_node->next == NULL) {

        temp_node->previous = head_node;
        head_node->next = temp_node;
        head_node->tail = temp_node;

        return 0;
    }
    
    // Adding other nodes, when size of linked list >= 2
    if (head_node->next != NULL) {

        struct linked_list *temp_node2 = head_node;

        // Go to the last node
        temp_node2 = head_node->tail;
        
        // Push back last value and add new to the end
        // HEAD -> ... <-> [temp_node2] <-> [temp_node] -> NULL
        temp_node2->next = temp_node;
        temp_node->previous = temp_node2;

        // Update new last value
        head_node->tail = temp_node;

        return 0;
    }

    return -1;
}

void push(struct linked_list *const head_node, const char *input_type, ...) {
    /*
        * Accept any argument
        * Validate the argument and assign its value to proper type
        * Add the validated type to linked list end
    */

    int flag = check_type(input_type);
    struct linked_list *temp_node = NULL;

    va_list ap;
    va_start(ap, input_type);

    switch (flag) {
        case IS_INT:
            {
                int vl = va_arg(ap, int);
                temp_node = ret_int_node(head_node, vl);
                break;
            }

        case IS_CHAR:
            {   
                char *vl = va_arg(ap, char *); 
                temp_node = ret_char_node(head_node, vl);
                break;
            }

        default:
            puts("Undefined input type");
            break;
    }

    va_end(ap); // clean up

    if (temp_node != NULL) {
        add_node(head_node, temp_node);
    }
}

void display(struct linked_list *const head_node) {
    
    struct linked_list* temp_node = head_node;

    if (head_node->data != NULL) {

        while(temp_node != NULL) 
        {
            switch (temp_node->data_type) {
                case IS_INT:                                       
                    printf("%d", *( (int*)(temp_node->data) )); 
                    puts("");             
                    break;
                
                case IS_CHAR:
                    printf("%s", (char*)(temp_node->data));
                    puts("");
                    break;
                
                default:
                    break;
            }
            temp_node = temp_node->next;
        } 

    } 
}

