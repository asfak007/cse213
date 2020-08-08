
#include <stdio.h>
void PrintArray(int *a, int size);

int main()
{
    int i;
    int arr[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[100];
    int size = 10;

    int *first_arr = arr;
    int *second_arr = arr2;
    int *n;

    n = &arr[size - 1];
    while(first_arr <= n)
    {
        *second_arr = *first_arr;

        first_arr++;
        second_arr++;
    }

    printf("First array is :\n");
    PrintArray(arr, size);

    printf("\nSecond Array after copy :\n");
    PrintArray(arr2, size);

    return 0;
}

void PrintArray(int *a, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", *(a + i));
}
