# ParallelisingAlgos
Taking one searching and one sorting algorithms (Linear Search & Insertion Sort) and parallelising them using OpenMP. <br />
Parallelized programs are written in C programming language with the help of OpenMP library. <br />
To ease the compilation of C programs, a Python script was written, which compiles the programs when called.

## Running the programs
- Compile using the command `python compile.py`
- The above command will only work if the filenames of C programs weren't changed.
- Run the serial and parallel programs using compiled files.

## Algorithms

### Linear Search
Testing using an array with 100k numbers, looking for a number at the end of the array.
Serial program outperformed the parallel one because of the overhead of starting and ending threads. 

### Insertion Sort
 - From what I've observed, most common implementation of this algorithm turned out to be non-parallelizable. 
 - I've put up my unfinished second attempt at parallelizing it, that is splitting an array into 4 partitions, and letting each thread work in it's own partition. The only way for a thread A to get into a partition of a thread B (this is required as all elements need to be compared) is to wait for thread A to finish the current iteration and put it to sleep. This means that iterations have to be synchronized across all threads in their own partitions and all threads must wait for the last thread to finish to move onto the next iteration.
 - In my opinion this approach had too many modifications to the original algorithm, and it was starting to look like a modified Shell Sort, so I decided to stop working on it. The output of what I have now is an array split into 4 partitions, where the numbers within the partitions are sorted.
