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
    +Output:
      -1. Insert.
2. Display.
3. exit.
Enter Option: 1
Enter Element: 10
Inserted successfully at 0

1. Insert.
2. Display.
3. exit.
Enter Option: 1
Enter Element: 20
Inserted successfully at 1

1. Insert.
2. Display.
3. exit.
Enter Option: 1
Enter Element: 30
Inserted successfully at 2

1. Insert.
2. Display.
3. exit.
Enter Option: 1 
Enter Element: 40
Inserted successfully at 3

1. Insert.
2. Display.
3. exit.
Enter Option: 1 
Enter Element: 50
Inserted successfully at 4

1. Insert.
2. Display.
3. exit.
Enter Option: 1
Enter Element: 60
Array size increased for more 5 Elements, Size is 10   // array size is increased
Inserted successfully at 5

1. Insert.
2. Display.
3. exit.
Enter Option: 2
Array values are:
0-10 1-20 2-30 3-40 4-50 5-60

1. Insert.
2. Display.
3. exit.
Enter Option: 3
Thank you..
