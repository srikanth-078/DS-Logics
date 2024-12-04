# DS-Logics

# In this you can find Data structures logics.
  -> Like sorting techniques. but not normal solving problems.
  -> it's unique.

1st one: increaseArraySize
  + In this you can see a c code that is to change the size of array at runtine environment.
  + allocation dynamic memory using "malloc" function.
  + reallocating using realloc function these function available in 'stdlib.h' header file.
  Logic:
      i.  *count + 1 >= *size checking this condition first.
      ii. *size = *size + MAX; // added estra maximum size to array.
     iii. *arr = (int *)realloc(*arr, (*size) * sizeof(int)); reallocating.
          we can also use this doubling the size of array
          // *size = *size * 2; // Double the array size
            // int *newArr = (int *)malloc(*size * sizeof(int)); //Here we can use malloc function also.
