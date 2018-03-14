# ParallelisingAlgos
Taking one searching and one sorting algorithm and parallelising them using OpenMP.

# Running the programs
- Compile using the command "python compile.py"
- The above command will only work if the .c filenames weren't changed
- Run the serial and parallel programs using "./lin_search_norm" and "./lin_search_par" respectively

# Linear Search
Testing using an array with 100k numbers, looking for a number at the end of the array.
Serial program outperform the parallel one because of the overhead of starting and ending threads. 
