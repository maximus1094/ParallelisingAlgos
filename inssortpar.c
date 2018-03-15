#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>

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

  // Variables for Threading
  int tcount;
  int tid;
  int partitionSize;
  int tbounds[8] = {0, 0, 0, 0, 0, 0, 0, 0};

  gettimeofday (&tvalBefore, NULL);

  #pragma omp parallel num_threads(4) private(tid, tcount, numberHolder)
  {
    // setup everything using a single thread
    #pragma omp single
    {
      tcount = omp_get_num_threads();
      partitionSize = size / tcount;

      tbounds[0] = 1;
      tbounds[1] = partitionSize - 1;

      tbounds[2] = partitionSize;
      tbounds[3] = partitionSize * 2 - 1;

      tbounds[4] = partitionSize * 2;
      tbounds[5] = partitionSize * 3 - 1;

      tbounds[6] = partitionSize * 3;
      tbounds[7] = partitionSize * 4;
    }

    #pragma omp sections
    {
      #pragma omp section
      {
        tid = omp_get_thread_num();

        int j;
        int i;
        for(i = tbounds[0]; i < tbounds[1]; i++) {

          j = i;
          while (numbers[j] < numbers[j-1] && j > tbounds[0] - 1) {
            // swap numbers 'j' and 'j-1'
            numberHolder = numbers[j];
            numbers[j] = numbers[j-1];
            numbers[j-1] = numberHolder;

            j--;
          }

        }

        printf("T%d :: I = %d\n", tid, i);
      }

      #pragma omp section
      {
        tid = omp_get_thread_num();

        int j;
        int i;
        for(i = tbounds[2]; i < tbounds[3]; i++) {

          j = i;
          while (numbers[j] < numbers[j-1] && j > tbounds[2] - 1) {
            // swap numbers 'j' and 'j-1'
            numberHolder = numbers[j];
            numbers[j] = numbers[j-1];
            numbers[j-1] = numberHolder;

            j--;
          }

        }

        printf("T%d :: I = %d\n", tid, i);
      }

      #pragma omp section
      {
        tid = omp_get_thread_num();

        int j;
        int i;
        for(i = tbounds[4]; i < tbounds[5]; i++) {

          j = i;
          while (numbers[j] < numbers[j-1] && j > tbounds[4] - 1) {
            // swap numbers 'j' and 'j-1'
            numberHolder = numbers[j];
            numbers[j] = numbers[j-1];
            numbers[j-1] = numberHolder;

            j--;
          }

        }

        printf("T%d :: I = %d\n", tid, i);
      }

      #pragma omp section
      {
        tid = omp_get_thread_num();

        int j;
        int i;
        for(i = tbounds[6]; i < tbounds[7]; i++) {

          j = i;
          while (numbers[j] < numbers[j-1] && j > tbounds[6] - 1) {
            // swap numbers 'j' and 'j-1'
            numberHolder = numbers[j];
            numbers[j] = numbers[j-1];
            numbers[j-1] = numberHolder;

            j--;
          }

        }

        printf("T%d :: I = %d\n", tid, i);
      }
    }
  }

  gettimeofday (&tvalAfter, NULL);

  printf("Time in microseconds: %ld microseconds\n",
            ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L
           +tvalAfter.tv_usec) - tvalBefore.tv_usec
         );
}

int main() {
  // Max size 100,000
  int SIZE = 500;
  int *numbers = (int*)malloc(SIZE * sizeof(int));

	loadNumbers("intarray_100k.txt", numbers, SIZE);
  insertionSort(numbers, SIZE);
  saveNumbersToFile("sortedarray.txt", numbers, SIZE);

  free(numbers);
  return 0;
}
