#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
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

// Use Linear Search to look for number "lookingFor" in array "numbers"
void linearSearch(int *numbers, int size, int lookingFor) {
	struct timeval tvalBefore, tvalAfter;
  int tid;

	// Linear Search
	int i;
  int foundNumber = 0;

  //gettimeofday (&tvalBefore, NULL);
  #pragma omp parallel private(tid) shared(foundNumber)
  {
    tid = omp_get_thread_num();

    #pragma omp for
  	for (i = 0; i < size; i++) {

  		if(lookingFor == numbers[i]) {
        // if found the number, stop all the threads
        foundNumber = 1;
        //printf("T%d :: Found Number :: I = %d\n", tid, i);
  		}
      if(foundNumber) {
        i = size;
      }

  	}

  }
  //gettimeofday (&tvalAfter, NULL);
  /*
  printf("Time in microseconds: %ld microseconds\n",
            ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L
           +tvalAfter.tv_usec) - tvalBefore.tv_usec
         );
         */
}

int main() {
	int SIZE = 100000;
  // Test cases:
  // Number 1 is at the end of the array (length - 1)
  // Number 2 is at the beginning (index 7)
  int FIND_NUMBER = 1;
	int *numbers = (int*)malloc(SIZE * sizeof(int));

	loadNumbers("intarray_100k.txt", numbers, SIZE);
	linearSearch(numbers, SIZE, FIND_NUMBER);

  free(numbers);
	return 0;
}
