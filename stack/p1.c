/*
 * Filename: p1.c
 * Project: WAP to perform PUSH, POP, PEEK operations on a stack
 * Created Date: Wednesday, September 5th 2018, 11:24:53 pm
 * Author: Aiman Kazi
 * 
 * Copyright (c) 2018 Visual Labs Learning Solution
 * 
 * Revision History : 
 * 
 */

#include <stdio.h>
#define MAX 3

// Array of size MAX
int st[MAX];

// Variable used to determine underflow condition
int top = -1;

// Function declarations for the Stack Operations
void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

int main(int argc, char const *argv[])
{
    int val;
    int option;

    do
    {
        printf("*****MAIN MENU*****\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.PEEK\n");
        printf("4.DISPLAY\n");

        printf("Enter your choice.\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the element you want.\n");
            scanf("%d", &val);
            push(st, val);
            break;

        case 2:
            val = pop(st);

            if (val != -1)
                printf("The value deleted from the stack is %d.\n", val);
            break;

        case 3:
            val = peek(st);
            if (val != -1)
                printf("The value stored at the top is %d.\n", val);
            break;

        case 4:
            display(st);
            break;
        default:
            break;
        }

    } while (option != 5);

    return 0;
}

void push(int st[], int val)
{
    // Check Overflow condition
    if (top == MAX - 1)
    {
        printf("Overflow Condition.\n");
    }
    else
    {
        top++;
        st[top] = val;
    }
}

int pop(int st[])
{
    int val;

    if (top == -1)
    {
        /* Check Underflow condition */
        printf("Underflow Condition.\n");
        return -1;
    }
    else
    { // performing pop operation
        val = st[top];
        top--;
        return val;
    }
}

int peek(int st[])
{
    int val;
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    else
    { // performing peek operation
        val = st[top];
        return val;
    }
}

void display(int st[])
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    { // print the elements of stack
        printf("ELEMENTS IN STACK.\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", st[i]);
        }
    }
}
