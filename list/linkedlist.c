/*
 * Filename: linkedlist.c
 * Project: datastructures
 * Created Date: Saturday, September 22nd 2018, 10:19:05 pm
 * Author: Aiman Kazi
 * 
 * Copyright (c) 2018 Visual Labs
 * 
 * Revision History
 */

// Including the required libraries written by someone
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next; //self - referential data type
};

struct node *start = NULL;

// total 12 operations on the list
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);

int main(int argc, char const *argv[])
{
    // code
    int option;
    do
    {
        printf("\nEnter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = create_ll(start);
            printf("LinkedList Created.");
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_beg(start);
            break;
        case 4:
            start = insert_end(start);
            break;
        case 5:
            start = insert_before(start);
            break;
        case 6:
            start = insert_after(start);
            break;
        case 7:
            start = delete_beg(start);
            break;
        case 8:
            start = delete_end(start);
            break;
        case 9:
            start = delete_node(start);
            break;
        case 10:
            start = delete_after(start);
            break;
        case 11:
            start = delete_list(start);
            break;
        case 12:
            start = sort_list(start);
            break;
        }
    } while (option < 13 && option > 0);
    return 0;
}

struct node *create_ll(struct node *start)
{
    // pointer to node
    struct node *newNode;
    struct node *ptr;

    int num;
    printf("\n Enter -1 to end.");
    printf("\n Enter the data : ");
    scanf("%d", &num);

    while (num != -1)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = num;

        if (start == NULL)
        {
            newNode->next = NULL;
            start = newNode;
        }
        else
        {
            ptr = start;

            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->next = NULL;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;

    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *newNode;
    int num;

    printf("\n Enter the data : ");
    scanf("%d", &num);

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = start;
    start = newNode;
    return start;
}

struct node *insert_end(struct node *start)
{
    struct node *newNode, *ptr;
    int num;

    printf("\n Enter the data : ");
    scanf("%d", &num);

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = NULL;
    ptr = start;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    return start;
}

struct node *insert_before(struct node *start)
{
    struct node *newNode, *ptr, *preptr;
    int num, val;

    printf("\n Enter the data : ");
    scanf("%d", &num);

    printf("\n Enter the element before which the data has to be inserted : ");
    scanf("%d", &val);

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    ptr = start;

    while (ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = newNode;
    newNode->next = ptr;
    return start;
}

struct node *insert_after(struct node *start)
{
    struct node *newNode, *ptr, *preptr;
    int num, val;

    printf("\n Enter the data : ");
    scanf("%d", &num);

    printf("\n Enter the element after which the data has to be inserted : ");
    scanf("%d", &val);

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    ptr = start;
    preptr = ptr;

    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = newNode;
    newNode->next = ptr;
    return start;
}

struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}
struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}

struct node *delete_node(struct node *start)
{
    struct node *ptr, *preptr;
    int val;
    printf("\n Enter the value of the node which has to be deleted:");
    scanf("%d", &val);
    ptr = start;

    if (ptr->data == val)
    {
        start = delete_beg(start);
        return start;
    }

    else
    {

        while (ptr->data != val)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        return start;
    }
}

struct node *delete_after(struct node *start)
{
    struct node *ptr, *preptr;
    int val;
    printf("\n Enter the value after which the node has to be deleted:");
    scanf("%d", &val);
    ptr = start;
    preptr = ptr;

    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
}

struct node *delete_list(struct node *start)
{
    struct node *ptr;

    if (start != NULL)
    {
        ptr = start;

        while (ptr != NULL)
        {
            printf("\n %d is to be deleted next", ptr->data);
            start = delete_beg(ptr);
            ptr = start;
        }
    }
    return start;
}

struct node *sort_list(struct node *start)
{
    struct node *ptr1, *ptr2;
    int temp;
    ptr1 = start;

    while (ptr1->next != NULL)
    {
        ptr2 = ptr1->next;

        while (ptr2 != NULL)
        {

            if (ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}
