// TODOs:
// 1. update all descriptions: quick sort, linear, binary search
// 2. Allow user to select which sorting method they want for bsearch?
// 3. Or sort it but don't display which type it is.
// 4. Fix the counter on binary search when it is run multiple times

// Include Helper Libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

// Declare prototypes
void display_arr(int arr[], int length);
void bubble_sort(int arr[], int length);
void selection_sort(int arr[], int length);
void insertion_sort(int arr[], int length);
void merge_sort(int arr[], int left, int right);
void copy_arr(int copy[], int arr[], int length);
void quick_sort(int arr[], int low, int high);
int linear_search(int arr[], int length, int target);
void binary_search(int arr[], int low, int high, int target, int *count);

int main(int argc, char *argv[])
{
    system("clear");
    // If user does not provide any numbers, exit
    if (argc < 2)
    {
        printf("Usage: add numbers followed by spaces to sort\n");
        printf("Example: ./algorithms 5 1 3 8 6 4 2 7\n");
        return 1;
    }

    // Get length of array user inputted
    int length = argc - 1;

    // Declare new array and put elements inside array
    int arr[length];
    for (int i = 0; i < length; i++)
    {
        arr[i] = atoi(argv[i + 1]);
    }

    // Make a copy of the array prior to sorting so users
    // Can run multiple sorting algorithms
    int copy[length];
    for (int i = 0; i < length; i++)
    {
        copy[i] = arr[i];
    }

    char algorithm[12];
    bool quit = false;


    do
    {
        printf("Which algorithm do you want to use on : ");
        display_arr(copy, length);
        printf("Sorting: bubble, selection, insertion, merge, or all\n");
        printf("Searching: linear or binary, or quit\n");
        scanf("%s", algorithm);

        if ((strncmp(algorithm, "bubble", 6)) == 0)
        {
            system("clear");
            printf("Bubble Sort\n\n");
            printf("Swapping adjacent pairs of elements if they are out of order\n");
            printf("Bubbling larger elements to the right and smaller ones to the left\n\n");
            printf("Big O of n**2, Omega of n\n\n");
            copy_arr(copy, arr, length);
            bubble_sort(arr, length);
            printf("\n");
        }
        else if ((strncmp(algorithm, "selection", 9)) == 0)
        {
            system("clear");
            printf("Selection Sort\n\n");
            printf("Selecting the smallest unsorted element and\n");
            printf("swapping it with the first unsorted element\n\n");
            printf("Big O of n**2, Omega of n**2\n\n");
            copy_arr(copy, arr, length);
            selection_sort(arr, length);
            printf("\n");
        }
        else if ((strncmp(algorithm, "insertion", 9)) == 0)
        {
            system("clear");
            printf("Insertion Sort\n\n");
            printf("Proceeding once through from left to right\n");
            printf("Shifting elements to insert each element into its correct place\n\n");
            printf("Big O of n**2, Omega of n\n\n");
            copy_arr(copy, arr, length);
            insertion_sort(arr, length);
            printf("\n");
        }
        else if ((strncmp(algorithm, "merge", 5)) == 0)
        {
            system("clear");
            printf("Merge Sort\n\n");
            printf("Splitting the full array into subarrays\n");
            printf("Then merging those subarrays back together in correct order\n\n");
            printf("Big O of n * log(n), Omega of n * log(n)\n\n");
            printf("Running merge sort on : ");
            copy_arr(copy, arr, length);
            display_arr(arr, length);
            merge_sort(arr, 0, length - 1);
            printf("\n");
        }
        else if ((strncmp(algorithm, "quick", 5)) == 0)
        {
            system("clear");
            printf("Quick Sort\n\n");
            printf("Something goes here, about using a pivot\n");
            printf("And some more things to explain it\n\n");
            printf("Big O of n * log(n), Omega of n * log(n)\n\n");
            printf("Running quick sort on : ");
            copy_arr(copy, arr, length);
            display_arr(arr, length);
            quick_sort(arr, 0, length - 1);
            printf("\n");
        }
        else if ((strncmp(algorithm, "linear", 6)) == 0)
        {
            system("clear");
            printf("Linear Search\n\n");
            printf("Explanation of linear search goes here\n");
            printf("Big O of n, Omega of 1\n\n");
            copy_arr(copy, arr, length);
            int target;
            printf("\nWhat is the target to search? ");
            scanf("%d", &target);
            printf("Running linear search on : ");
            display_arr(arr, length);
            linear_search(arr, length, target);
            printf("\n");
        }
        else if ((strncmp(algorithm, "binary", 6)) == 0)
        {
            system("clear");
            printf("Binary Search\n\n");
            printf("Explain binary search here\n");
            printf("Big O of log(n), Omega of log(n)\n\n");
            printf("Must be sorted first, will sort and then run\n");
            copy_arr(copy, arr, length);
            bubble_sort(arr, length);
            int target;
            printf("\nWhat is the target to search? ");
            scanf("%d", &target);
            printf("Running binary search on : ");
            display_arr(arr, length);
            int any = 0;
            int *count = &any;
            binary_search(arr, 0, length, target, count);
            printf("Total iterations: %i\n", count);
            printf("\n");
        }
        else if ((strncmp(algorithm, "all", 3)) == 0)
        {
            system("clear");
            copy_arr(copy, arr, length);
            printf("\nRunning all sorting algorithms......\n\n");
            bubble_sort(arr, length);
            copy_arr(copy, arr, length);
            printf("\n");
            display_arr(arr, length);
            printf("\n");
            selection_sort(arr, length);
            copy_arr(copy, arr, length);
            printf("\n");
            insertion_sort(arr, length);
            copy_arr(copy, arr, length);
            printf("\n");
            printf("Running merge sort on : ");
            display_arr(arr, length);
            merge_sort(arr, 0, length - 1);
            printf("\n");
        }
        else if ((strncmp(algorithm, "quit", 4)) == 0)
        {
            quit = true;
            break;
        }
        else
        {
            printf("\nPlease choose from the following options,\n");
        }
    }
    while (!quit);
    return 0;
}

void copy_arr(int copy[], int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = copy[i];
    }
}

// Bubble sort to sort the array
void bubble_sort(int arr[], int length)
{
    printf("Running bubble sort on : ");
    display_arr(arr, length);
    printf("\n");
    int temp;
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < length - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                sorted = false;
            }
            if (i == length - 2)
            {
                display_arr(arr, length);
            }
        }
    }
}

// Selection Sort
void selection_sort(int arr[], int length)
{
    printf("Running selection sort on : ");
    display_arr(arr, length);
    printf("\n");
    int min, idx, temp;
    for (int j = 0; j < length - 1; j++)
    {
        min = arr[j];
        for (int i = j + 1; i < length; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
                idx = i;
            }
        }
        if (arr[j] != min)
        {
            temp = arr[j];
            arr[j] = arr[idx];
            arr[idx] = temp;
        }
        display_arr(arr, length);
    }
}


void insertion_sort(int arr[], int length)
{
    printf("Running insertion sort on : ");
    display_arr(arr, length);
    printf("\n");
    int key, j;
    for (int i = 1; i < length; i++) // Iterate through array starting at index 1
    {
        key = arr[i];  // Key is the current element we are trying to insert in place
        
        // Compare the key to the elements on the left
        j = i - 1;
        while (arr[j] > key && j >= 0)  // If element left of key is bigger, then move it to the right
        {
            arr[j + 1] = arr[j];
            j--;  // Decrement j as we move towards the beginning of the hand
        }
        arr[j + 1] = key;
        display_arr(arr, length);
    }
}


// Merge
void merge(int arr[], int left, int middle, int right)
{
	// create temporary array
	int temp[right - left];

	int i = left;       // Left array lowest unpicked index
    int j = middle + 1; // Right array lowest unpicked index
    int k = 0;          // Index for combined array

	while(i <= middle && j <= right)
    {
		if(arr[i] < arr[j]) 
        {
			temp[k] = arr[i];
			k++;
            i++;
		}
		else 
        {
			temp[k] = arr[j];
			k++;
            j++;
		}
	}

	// add elements remaining in the "left array" 
	while(i <= middle) 
    {
		temp[k] = arr[i];
		k++;
        i++;
	}

	// add elements remaining in the "right array"
	while(j <= right) 
    {
		temp[k] = arr[j];
		k++;
        j++;
	}

	// copy temp to original array
    int m = left;
    for (int l = 0; l < k; l++) 
    {

        arr[m] = temp[l];
        m++;
    }

    display_arr(arr, right + 1);
}

// Merge sort
void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {   
        int middle = (left + right) / 2;
        merge_sort(arr, left, middle); 
        merge_sort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

// Quick Sort
int partition(int arr[], int low, int high)
{
    int pivot, temp;
    int i = low;
    int j = high;
    pivot = arr[low];
 
    while (i < j)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;
    display_arr(arr, high + 1);
    return j;
}

void quick_sort(int arr[], int low, int high)
{
    int j;
    if (low < high)
    {
        j = partition(arr, low, high);
        quick_sort(arr, low, j - 1);
        quick_sort(arr, j + 1, high);
    }

}

int linear_search(int arr[], int length, int target)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        count++;
        if (target == arr[i])
        {
            printf("Found %i at index %i\n", target, i);
            printf("Total iterations: %i\n", count);
            return 0;
        }
    }
    printf("Not found\n");
    printf("Total iterations: %i\n", count);
    return 1;

    printf("Running insertion sort on : ");
    display_arr(arr, length);
    printf("\n");
}

void binary_search(int arr[], int low, int high, int target, int *count)
{
    *count++;
    printf("count: %i\n", *count);
    if (low > high)
    {
        printf("Not found\n");
        return;
    }

    int middle = (high + low) / 2;

    if (target == arr[middle])
    {
        printf("Found %i at index %i\n", target, middle);
    }
    else if (target < arr[middle])
    {
        binary_search(arr, low, middle - 1, target, count);
    }
    else if (target > arr[middle])
    {
        binary_search(arr, middle + 1, high, target, count);
    }
}


// Prints the elements in an array followed by a space
void display_arr(int arr[], int length)
{
    for (int k = 0; k < length; k++)
    {
        printf("%i ", arr[k]);
    }
    printf("\n");
}
