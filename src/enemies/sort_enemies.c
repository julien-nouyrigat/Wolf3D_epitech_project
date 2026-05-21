/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** sort_enemies
*/

#include "wolf.h"

enemy_t *first_part(enemy_t *head, const enemy_t *mid_node)
{
    enemy_t *first_node = head;

    while (head->next != mid_node) {
        head = head->next;
    }
    head->next = NULL;
    return first_node;
}

enemy_t *second_part(enemy_t *head)
{
    enemy_t *temp_node = head;
    enemy_t *mid = head;

    while (temp_node != NULL) {
        temp_node = temp_node->next;
        if (temp_node == NULL)
            break;
        temp_node = temp_node->next;
        mid = mid->next;
    }
    return mid;
}

static enemy_t *fusion(enemy_t *head_1, enemy_t *head_2)
{
    enemy_t *head_result = NULL;

    if (head_1 == NULL)
        return head_2;
    if (head_2 == NULL)
        return head_1;
    if (head_1->monster->order_dist > head_2->monster->order_dist) {
        head_1->next = fusion(head_1->next, head_2);
        return head_1;
    } else {
        head_2->next = fusion(head_1, head_2->next);
        return head_2;
    }
    return head_result;
}

enemy_t *sort_enemies(enemy_t *head)
{
    enemy_t *head_2 = NULL;
    enemy_t *head_1 = NULL;

    if (head == NULL || head->next == NULL)
        return head;
    head_2 = second_part(head);
    head_1 = first_part(head, head_2);
    head_1 = sort_enemies(head_1);
    head_2 = sort_enemies(head_2);
    return fusion(head_2, head_1);
}
