/**
 * @file linkedl.h
 * @author Karolis
 * @date -
 * 
 * @brief File contains few functions for simple linked list simulation
 */


/**
 * @brief Mallocs memory for struct entity
 * Assigns default values
 * @code
 * struct linked_list *head = init_list();
 * @endcode
 * @return pointer to malloced head node location
 * @note struct name must be "linked_list" and use only returned pointer for all other functions
*/
struct linked_list *init_list();


/**
 * @brief Pushes given value to the end of the linked list
 * @code
 * push(head, "int", 5);
 * push(head, "char", "test");
 * @endcode
 * @param head_node returned pointer from init_list() 
 * @param input_type data type of next argument
 * @param last argument must be the given value
 * @warning use only "int", "char" for last argument
*/
void push(struct linked_list *const head_node, const char *input_type, ...);


/**
 * @brief Removes last node from linked list
 * @code
 * pop(head);
 * @endcode
 * @param head_node returned pointer from init_list()
 * @return 0 - success
 * @return 1 - no value to remove
 * @return 2 - last value removed
 * @return -1 - error
*/
int pop(struct linked_list *const head_node);


/**
 * @brief Displays values of linked list
 * @code
 * display(head);
 * @endcode
 * @param head_node returned pointer from init_list()
*/
void display(struct linked_list *const head_node);