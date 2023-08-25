#include "monty.h"

/**
 * add_rear - add node at the end of a list
 * @head: double pointer
 * @n: value to be added
 * Return: address of new element
 */
stack_t *add_rear(stack_t **head, const int n)
{
	stack_t *newnode, *tmp;

	if (head  == NULL)
	{
		return (NULL);
	}

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_global();
		exit(EXIT_FAILURE);
	}
	newnode->n = n;
	newnode->next = NULL;
	if (*head == NULL)
	{
		newnode->prev = NULL;
		*head = newnode;
		return (newnode);
	}
	tmp = *head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = newnode;
	newnode->prev = tmp;
	return (newnode);
}

/**
 * *add_front - add node at front of a list
 * @head: Double pointer
 * @n: value to be assigned to the new node
 * Return: the address of the new element
 */
stack_t *add_front(stack_t **head, const int n)
{
	stack_t *newnode;

	if (head == NULL)
	{
		return (NULL);
	}
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_global();
		exit(EXIT_FAILURE);
	}
	newnode->n = n;
	newnode->prev  = NULL;
	newnode->next = *head;
	if (*head != NULL)
	{
		(*head)->prev = newnode;
	}
	*head = newnode;
	return (newnode);
}

/**
 * free_list - frees a list
 * @head: points to the head node of the list
 * Return: nothing
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
