#include <stdio.h>
#include "dep.h"

// Quick function I made to print the arrays to the console for debugging purposes
void printArray(int arr[], int arrSize) {
  for (int i = 0; i < arrSize; i++) {
    printf("%d,", arr[i]);
  }
  printf("\n");
}

int main() {
  int *arr = get_input(); // array of random numbers
  // your task is to print the number that's repeated the most and the
  // number that's repeated the least.

  // do not edit the dep.h and dep.c files.

  // --------------------------------------------------------------------------

  // So, if I was doing this in JS, I'd think about making a way to store how many times each number was repeated,
  // which means making an object with the keys being 1-10, and the values being the amount of times they show up in the array.
  // So like: {
  //   1: 12,
  //   2: 5,
  //   ...
  //   10: 7
  // }
  // I have absolutely no idea how to do this in C, but then it occurred to me - that data structure is literally just an array!

  // Make an array with 10 values to store the counts of each number, with each value starting at 0:
  int counts[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  // view the array of random numbers if you want
  // printArray(arr, 100);

  // Loop through the random numbers
  for (int i = 0; i < SIZE; i++) {
    // Since the random numbers are 1 to 10, and my "counts" array starts indexing at 0,
    // we need to take 1 from the number, so that 1 goes into the 0 slot, and 10 goes into the 9 slot, etc.
    // Add 1 to the respective count:
    counts[arr[i] - 1] += 1;
  }

  // To determine the smallest and biggest number, these numbers are changed whenever a new smallest/biggest number is found in the counts array.
  // The "Index" variables are needed to find out which number was repeated the most/least times, as that corresponds to the position in the counts array.
  int smallestNumber = counts[0];
  int smallestNumberIndex = 0;
  int biggestNumber = counts[0];
  int biggestNumberIndex = 0;

  // Technically I didn't need the "smallestNumber" and "biggestNumber" variables 'cause I'm only supposed to print
  // the number that's there the most, not actually how many times it appears.. but whatever, this way is cooler :^)

  // Loop through the counts array, to determine which number is biggest and which is smallest
  // start at 1 because the starting numbers are already initialised above
  for (int i = 1; i < 10; i++) {
    if (counts[i] < smallestNumber) {
      smallestNumber = counts[i];
      smallestNumberIndex = i;
    }
    if (counts[i] > biggestNumber) {
      biggestNumber = counts[i];
      biggestNumberIndex = i;
    }
  }

  printf("The number that appears the least is %d, which appears %d times.\nThe number that appears the most is %d, which appears %d times.",
    // Adding one because the random numbers are between 1-10, not 0-9.
    smallestNumberIndex + 1, 
    smallestNumber,
    biggestNumberIndex + 1,
    biggestNumber
  );

  return 0;
}