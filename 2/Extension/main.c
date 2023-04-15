#include <stdio.h>
#include "dep.h"

// Print an array to the console.
void printArray(int arr[], int arrSize) {
  for (int i = 0; i < arrSize; i++) {
    printf("%d,", arr[i]);
  }
  printf("\n");
}

// Sort an array of integers in ascending order. Changes the original array.
void bubble_sort(int *arr, int arrSize) {
  // Determines whether a sort happened on this pass
  _Bool hasModifiedArray = 1;
  int maxIndex = arrSize - 1;
  while (hasModifiedArray) {
    hasModifiedArray = 0;
    for (int i = 0; i < maxIndex; i++) {
      int currentNumber = arr[i];
      int nextNumber = arr[i+1];
      if (currentNumber > nextNumber) {
        arr[i] = nextNumber;
        arr[i+1] = currentNumber;
        if (!hasModifiedArray) hasModifiedArray = 1;
      }
    }
  }
}

int main() {
  int *arr = get_input(); // array of random numbers
  // Extension task: create a sorting algorithm to sort the array of random numbers.

  // do not edit the dep.h and dep.c files.

  printf("Original: ");
  printArray(arr, SIZE);
  printf("\n");
  bubble_sort(arr, SIZE);

  printf("Sorted: ");
  printArray(arr, SIZE);
  system("pause");

  return 0;
}