/*
 * Filename: p2.c
 * Project: Array
 * WAP: Find the mean of n numbers using an array
 * Created Date: Saturday, September 1st 2018, 12:18:49 am
 * Author: Aiman Kazi
 * 
 * Copyright (c) 2018 Visual Labs Learning Solution
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i;
    int n;
    int sum = 0;
    float mean;
    int array[20]; // array of size 20

    printf("Enter the number of elements in an array"); // example 5
    scanf("%d", &n);                                    // 5 will get stored in n

    // accepting the elements in an array
    for (i = 0; i < n; i++)
    {
        printf("\narray[%d] = ", i);
        scanf("%d", &array[i]);
        sum = sum + array[i];
    }

    // Print the elements in an array with thier index position
    printf("\nThe elements in an array are : \n");

    for (i = 0; i < n; i++)
    {
        printf("array[i] = %d. \n", array[i]);
    }
    // calculating the mean of an array
    mean = sum / n;

    printf("The sum of array elements = %d.\n", sum);
    printf("The mean of array elements = %f.\n", mean);

    return 0;
}
