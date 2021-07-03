#include <stdio.h>
#include <stdlib.h>

void inputarray(int arr[], int total_index)
{
    for (int i = 0; i < total_index; i++)
        {
            printf("Enter a positive element at index %d: ", i);
            scanf("%d", &arr[i]);
        }
}

int main()
{
    int size,temp,count=0;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));

    inputarray(arr, size);

    for (int i = 0; i < size; i++)
    {
        temp=arr[i];
        for (int j = i+1; j < size; j++)
        {
            if(temp == arr[j])
            {
                count++;
                break;
            }
        }
    }
    printf("\nNumber of (extra) duplicate elements: %d\n", count);

    free(arr);
    return 0;
}