#include <stdio.h>
#include <conio.h>

void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
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


