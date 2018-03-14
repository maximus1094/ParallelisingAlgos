#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Load all number from "path" to "array"
void loadNumbers(char *path, int *array, int size) {
    FILE *fp;
    fp = fopen(path, "r");

    int i = 0;
  	while(i < size) {
  		fscanf(fp, "%d", &array[i]);
      i++;
  	}

    fclose(fp);
}

// Save numbers to a file (for testing purposes)
void saveNumbersToFile(char *path, int *array, int size) {
  FILE *fp = fopen(path, "w");

  int i;
  for (i = 0; i < size; i++) {
    fprintf(fp, "%d\n", array[i]);
  }

  fclose(fp);
}

void insertionSort(int *numbers, int size) {
  struct timeval tvalBefore, tvalAfter;
  int i = 1;
  int j = 0;
  int numberHolder = 0;

  gettimeofday (&tvalBefore, NULL);
  while(i < size) {

    j = i;
    while (numbers[j] < numbers[j-1] && j > 0) {
      // swap numbers 'j' and 'j-1'
      numberHolder = numbers[j];
      numbers[j] = numbers[j-1];
      numbers[j-1] = numberHolder;

      j--;
    }

    i++;
  }
  gettimeofday (&tvalAfter, NULL);

  printf("Time in microseconds: %ld microseconds\n",
            ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L
           +tvalAfter.tv_usec) - tvalBefore.tv_usec
         );
}

int main() {
  int SIZE = 100000;
  int *numbers = (int*)malloc(SIZE * sizeof(int));

	loadNumbers("intarray_100k.txt", numbers, SIZE);
  insertionSort(numbers, SIZE);

  free(numbers);
  return 0;
}
