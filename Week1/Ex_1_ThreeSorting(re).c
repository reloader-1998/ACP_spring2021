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
        printArray(arr, n);
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

        printArray(arr, n);
    }
}

/* Function to sort an array using bubble sort*/
void bubbleSort(int arr[], int n)
{
    int length = n;
    int i;
    int key;
    while(n > 1){
        for(i = 0;i < n - 1;i++){
            if(arr[i] > arr[i + 1]){
                key = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = key;
            }
            printArray(arr, length);
        }
        n--;
    }
}

// A utility function to print an array of size n
int printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}


/* Driver program to test insertion sort */
int main()
{

    char c = putchar;
    while(c != EOF){
        int arr[] = { 12, 11, 13, 5, 6 };
        int n = sizeof(arr) / sizeof(arr[0]);


        int k;
        printf("Enter a key (1:selection; 2:insertion; 3:bubble):\t");
        scanf("%d", &k);
        switch(k){
        case 1:
            printf(" Doing selection sort\n");
            selectionSort(arr, n);
            break;
        case 2:
            printf(" Doing insertion sort\n");
            insertionSort(arr, n);
            break;
        case 3:
            printf(" Doing bubble sort\n");
            bubbleSort(arr, n);
            break;
        default:
            printf("wrong input");
            c = EOF;
        }
        printf("result:\n");
        printArray(arr, n);
    }

    return 0;
}
