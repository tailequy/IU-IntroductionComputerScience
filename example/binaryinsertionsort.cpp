#include <stdio.h>
#include <conio.h>

// A binary search based function to find the position where item should be inserted in array[low..high]
int binarySearch(int array[], int item,
                 int low, int high)
{
    if (high <= low)
        return (item > array[low]) ?
                (low + 1) : low;
 
    int mid = (low + high) / 2;
 
    if (item == array[mid])
        return mid + 1;
 
    if (item > array[mid])
        return binarySearch(array, item,
                            mid + 1, high);
    return binarySearch(array, item, low,
                        mid - 1);
}
 
// Function to sort an array a[] of size 'n'
void insertionSort(int array[], int n)
{
    int i, loc, j, k, selected;
 
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = array[i];
 
        // find location where selected should be inserted
        loc = binarySearch(array, selected, 0, j);
 
        // Move all elements after location to create space
        while (j >= loc)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = selected;
    }
}

// function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
int main()
{
	int size,i;
	int array[1000];
	printf("Input a sequence, how many items? size = ");
	scanf("%d",&size);
	for (i=0;i<size;i++)
	{
		printf("Input an the %d element: ",i);
		scanf("%d",&array[i]);
	}
	printf("Imported array:\n");
  	printArray(array, size);
	insertionSort(array, size);
  	printf("Sorted array in Acsending Order:\n");
  	printArray(array, size);
	return 1;
}
