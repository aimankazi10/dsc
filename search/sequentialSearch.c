/*
 * Filename: sequentialSearch.c
 * Project: datastructures - Linear Search
 * Created Date: Friday, August 31st 2018, 7:37:19 pm
 * Author: Aiman Kazi
 * 
 * Copyright (c) 2018 Visual Labs Learning Solution
 */

#include <stdio.h>

// Function declaration
int sequential(int array[], int key, int n);

int main(int argc, char const *argv[])
{
    int array[50]; // array of size 50
    int key;
    int n;
    int i;
    int result;

    printf("Enter the number of elements you want to store in an array. \n");
    scanf("%d", &n);
    printf("Enter %d elements \n", n);

    // Loop to accept values from user and store it in an array
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    // Accept the element to search from user
    printf("Enter the element to search.\n");
    scanf("%d", &key);

    result = sequential(array, key, n);

    if (result == -1)
    {
        printf("No element found.");
    }
    else
    {
        printf("Element %d found at location %d", key, result + 1);
    }

    return 0;
}

int sequential(int array[], int key, int n)
{
    int i = 0;

    while (i < n && key != array[i])
    {
        i++;
    }

    if (i < n)
    {
        return i;
    }

    return -1;
}
