#include<stdio.h>
int check_overflow(int n);
int main()
{

    int arr[100];
    int i = 0;
    int size = 100;
    while(scanf("%d",&arr[i]) != EOF)
    {
        i++;
        if(check_overflow(i)==0)
        {
            printf("Overflow\n");
            break;
        }
    }

    for(i = 0; i<size; i++)
        printf("%d ", arr[i]);

    return 0;
}

int check_overflow(int n)
{
    if(n+1>100)
        return 0;
}
