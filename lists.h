#ifndef LISTSH
#define LISTSH

#include <unistd.h>

/**
 * struct list_s - singly linked list node
 * @str: string data
 * @val: value string data
 * @len: length of the string data
 * @valLen: length of the value string data
 * @next: pointer to the next node in the list
 */
typedef struct list_s
{
    char *str;          /* Pointer to the string data */
    char *val;          /* Pointer to the value string data */
    unsigned int len;   /* Length of the string data */
    unsigned int valLen;/* Length of the value string data */
    struct list_s *next;/* Pointer to the next node in the list */
} list_t;

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to be written.
 *
 * Return: On success, 1 is returned. On error, -1 is returned.
 */
int _putchar(char c);

/**
 * print_list - Prints all elements of a linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_list(list_t *h);

/**
 * list_len - Counts the number of elements in a linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t list_len(list_t *h);

/**
 * add_node - Adds a new node at the beginning of the linked list.
 * @head: Double pointer to the head of the list.
 * @str: Pointer to the string data for the new node.
 * @val: Pointer to the value string data for the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, char *str, char *val);

/**
 * free_list - Frees the memory allocated for a linked list.
 * @head: Pointer to the head of the list.
 *
 * This function frees the memory allocated for each node in the linked list,
 * including the string and value data.
 */
void free_list(list_t *head);

/**
 * get_node - Finds a node in the linked list with a specific string data.
 * @head: Pointer to the head of the list.
 * @str: Pointer to the string data to find.
 *
 * Return: The node that contains the string data, or NULL if not found.
 */
list_t *get_node(list_t *head, char *str);

#endif

