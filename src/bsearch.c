
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// utility function to print the contents of an array
void p_int_array(int a[], int n) {
int i;
     printf("[ \n");
     for(i=0; i<n; i++){
          printf("  %i\n", a[i]);
     }
     printf("]\n");
}

// insertion sort algorithm
void isort(int a[], int n)
{
    int i, j, val;

    for(i=1; i<n; i++)
    {
        j=i-1;
        val = a[i]; 
        while(j >= 0 && a[j] > val) {
            a[j+1] = a[j]; 
            j--;
        } 
        a[j+1] = val;
    }
}



// Recursive Binary Search Routine that does the "Real" Work
int bsearchR(int a[], int lo, int hi, int x) {
  int m;

  if(hi < lo) 
    return -1;   // SET A BREAKPOINT HERE!!!

  m = (lo + hi) / 2;

  if(a[m] == x) 
    return m;    // SET A BREAKPOINT HERE!!!
  else if(x < a[m])
    return bsearchR(a, lo, m-1, x);
  else
    return bsearchR(a, m+1, hi, x);
}


int bin_search(int a[], int n, int x) {
  return bsearchR(a, 0, n-1, x);
}


int main(){
  int a[127];
  int i, x;

  // store a few KNOWN numbers 
  a[0] = 88;
  a[1] = 222;
  a[2] = 777;

  srand(time(NULL));
  // randomize the rest
  for(i=3; i<127; i++)
    a[i] = rand() % 1000;

  printf("Array Contents BEFORE Sort:\n");
  p_int_array(a, 127);  
  isort(a, 127);
  printf("Array Contents AFTER Sort:\n");
  p_int_array(a, 127);  

  // search for elements we KNOW should be in the array.
  // let's make sure these work (return index containing search value)!
  printf("bin_search(88): %i\n", bin_search(a, 127, 88));
  printf("bin_search(222): %i\n", bin_search(a, 127, 222));
  printf("bin_search(777): %i\n", bin_search(a, 127, 777));

  // search for elements we KNOW should NOT be in the array.
  // let's make sure these work (return -1)!
  printf("bin_search(-1): %i\n", bin_search(a, 127, -1));
  printf("bin_search(1000): %i\n", bin_search(a, 127, 1000));
}


