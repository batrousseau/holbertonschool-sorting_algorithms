#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


/**
 * get_list_depth - return the number of element of a doubly
 * linked list
 * @list: pointer to the beginning of the list
 * Return: Number of element
 */

int get_list_depth(listint_t *list)
{
	int i = 0;
	int depth = 0;

	if (list == NULL)
	{
		return (-1);
	}

	for (i = 1; list->next != NULL; i++)
	{
		list = list->next;
	}
	depth = i;
	return (depth);
}

/**
 * swap_nodes - swap two nodes
 * @list: header pointer of the list
 * @a: node that must go b
 * @b: node that must go a
 * Return: Struct pointer of newly a (b)
 */

listint_t **swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *tmp_z = NULL;
	listint_t *tmp_a = NULL;
	listint_t *tmp_b = NULL;
	listint_t *tmp_c = NULL;

	if (a == NULL || b == NULL)
	{
		return (list);
	}
	/* capturing current nodes memories adres*/
	if (a->prev != NULL)
	{
		tmp_z = a->prev;
	}
	if (b->next != NULL)
	{
		tmp_c = b->next;
	}
	tmp_a = a;
	tmp_b = b;
	/* rerouting neighours nodes*/
	if (a->prev != NULL)
	{
		a->prev->next = tmp_b;
	}
	if (a->prev == NULL)
	{
		*list = tmp_b;
	}
	if (b->next != NULL)
	{
		b->next->prev = tmp_a;
	}
	b->prev = tmp_z;
	a->next = tmp_c;
	b->next = tmp_a;
	a->prev = tmp_b;
	a = tmp_b;
	b = tmp_a;
	return (list);
}


/**
 * insertion_sort_list - sort a doubly linked list
 * of integer using insertion sort algorithm
 * @list: pointer to header pointer of the list
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *h;
	listint_t *traveler; /* Celui qui remonte le courant (le "petit")*/

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* BOUCLE PRINCIPALE (L'Explorateur) */
	/* On ne met pas d'incrément ici (le 3ème paramètre est vide) */
	/* Car on n'avance pas 'h' si on vient de faire un swap ! */
	for (h = *list; h->next != NULL; )
	{
		if (h->n > h->next->n)
		{
			/* 1. On capture le petit (h->next) qui est mal placé */
			traveler = h->next;

			/* 2. On le fait passer devant h */
			swap_nodes(list, h, traveler);
			print_list(*list);

			/* 3. BOUCLE SECONDAIRE (Le Backtracking) */
			/* C'est un for sans init et sans incrément, juste une condition */
			/* Tant que traveler a un voisin gauche ET qu'il est plus petit que lui */
			for (; traveler->prev != NULL && traveler->n < traveler->prev->n; )
			{
				swap_nodes(list, traveler->prev, traveler);
				print_list(*list);
			}
			/* NOTE IMPORTANTE : */
			/* Ici, 'h' pointe toujours sur le "Gros" chiffre qui a bougé à droite. */
			/* Comme il a bougé physiquement, il a "avancé" tout seul. */
			/* Donc on ne fait RIEN ici*/
			/*La boucle principale reprendra avec le nouveau h->next. */
		}
		else
		{
			/* Si tout est rangé, on avance manuellement */
			h = h->next;
		}
	}
}
