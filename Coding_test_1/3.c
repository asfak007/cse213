
#include <stdio.h>
int main()
{
    int arr[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i, X, K;
    int size = 10;

    for(i=0; i<size; i++)
        {
            printf("%d ", arr[i]);

        }

    printf("\n");
    printf("Enter the position:\n ");
    scanf("%d", &K);

    printf("Enter the value:\n ");
    scanf("%d", &X);

    for (i=0; i==K; i++)
        {
            arr[i] = arr[i - 1];

        }


    arr[K - 1] = X;

    for(i=0; i<size; i++)
        {
            printf("%d ", arr[i]);
        }


    return 0;
}
