#ifndef LISTSH
#define LISTSH

#include <unistd.h>

/**
 * struct list_s - singly linked list node
 * @str: string data for the name of the environment variable or alias
 * @val: value string data for the value of the environment variable or alias
 * @len: length of the string data (name)
 * @valLen: length of the value string data
 * @next: pointer to the next node in the list
 *
 * Description: This struct represents a node in a singly linked list
 * for storing environment variables or aliases in the shell.
 */

typedef struct list_s
{
	char *str;         /* The name of the environment variable or alias */
	char *val;         /* The value of the environment variable or alias */
	unsigned int len;  /* Length of the name (string data) */
	unsigned int valLen; /* Length of the value (string data) */
	struct list_s *next; /* Pointer to the next node in the list */
} list_t;

/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 * Return: On success 1, on error, -1 is returned,
 * and errno is set appropriately.
 */
int _putchar(char c);

/**
 * print_list - Prints all elements of a linked list
 * @h: Pointer to the head of the list
 * Return: The number of nodes in the list
 */
size_t print_list(list_t *h);

/**
 * list_len - Counts the number of nodes in a linked list
 * @h: Pointer to the head of the list
 * Return: The number of nodes in the list
 */
size_t list_len(list_t *h);

/**
 * add_node - Adds a new node at the beginning of a linked list
 * @head: Pointer to the head of the list
 * @str: String data (name) for the new node
 * @val: String data (value) for the new node
 * Return: Address of the new node, or NULL on failure
 */
list_t *add_node(list_t **head, char *str, char *val);

/**
 * free_list - Frees a linked list
 * @head: Pointer to the head of the list to free
 */
void free_list(list_t *head);

/**
 * get_node - Finds a node in the linked list by its name (string data)
 * @head: Pointer to the head of the list
 * @str: The name of the node to find
 * Return: Address of the found node, or NULL if not found
 */
list_t *get_node(list_t *head, char *str);

#endif /* LISTSH */

