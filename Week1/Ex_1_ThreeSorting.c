// C program for three types of sort
#include <math.h>
#include <stdio.h>

/* Function to sort an array using selection sort */
void selectionSort(int arr[], int n)
{
    int i;
    int j;
    int key;
    for(i = 0;i < n;i++){
        /* Swap the element while the element is
          greater than a[i]*/
        for(j = i + 1;j < n;j++){
            if(arr[i] > arr[j]){
                key = arr[i];
                arr[i] = arr[j];
                arr[j] = key;
            }
        }
    }
}

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i;
    int key;
    int j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/* Function to sort an array using bubble sort*/
void bubbleSort(int arr[], int n)
{
    int i;
    int key;
    while(n > 1){
        for(i = 0;i < n - 1;i++){
            if(arr[i] > arr[i + 1]){
                key = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = key;
            }
        }
        n--;
    }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Driver program to test insertion sort */
int main()
{

    int arr1[] = { 12, 11, 13, 5, 6 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    insertionSort(arr1, n1);
    printArray(arr1, n1);

    int arr2[] = { 12, 11, 13, 5, 6 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    selectionSort(arr2, n2);
    printArray(arr2, n2);

    int arr3[] = { 12, 11, 13, 5, 6 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    bubbleSort(arr3, n3);
    printArray(arr3, n3);


    return 0;
}
