/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** sort_entities
*/

#include "entity_display.h"
#include "wolf.h"

entities_t *first_part(entities_t *head, const entities_t *mid_node)
{
    entities_t *first_node = head;

    while (head->next != mid_node) {
        head = head->next;
    }
    head->next = NULL;
    return first_node;
}

entities_t *second_part(entities_t *head)
{
    entities_t *temp_node = head;
    entities_t *mid = head;

    while (temp_node != NULL) {
        temp_node = temp_node->next;
        if (temp_node == NULL)
            break;
        temp_node = temp_node->next;
        mid = mid->next;
    }
    return mid;
}

static entities_t *fusion(entities_t *head_1, entities_t *head_2)
{
    entities_t *head_result = NULL;

    if (head_1 == NULL)
        return head_2;
    if (head_2 == NULL)
        return head_1;
    if (head_1->p_dist > head_2->p_dist) {
        head_1->next = fusion(head_1->next, head_2);
        return head_1;
    } else {
        head_2->next = fusion(head_1, head_2->next);
        return head_2;
    }
    return head_result;
}

entities_t *sort_entities(entities_t *head)
{
    entities_t *head_2 = NULL;
    entities_t *head_1 = NULL;

    if (head == NULL || head->next == NULL)
        return head;
    head_2 = second_part(head);
    head_1 = first_part(head, head_2);
    head_1 = sort_entities(head_1);
    head_2 = sort_entities(head_2);
    return fusion(head_2, head_1);
}
