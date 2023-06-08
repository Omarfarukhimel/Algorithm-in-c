#include <stdio.h>

int main()
{
  // a test array and array length
  int a[] = {5, 9, 7, 6, 4, 0, 2, 3, 8, 1};
  int length = 10;

  // Selection sort algorithm to sort the array in ascending order
  for (int i = 0; i < length - 1; i++)
  {
    int min_pos = i; // Assume the current element is the minimum
    for (int j = i + 1; j < length; j++)
    {
      if (a[j] < a[min_pos])
        min_pos = j; // Update the minimum position if a smaller element is found
    }
    if (min_pos != i)
    {
      int temp = a[i]; // Swap the current element with the minimum element
      a[i] = a[min_pos];
      a[min_pos] = temp;
    }
  }

  // Print the sorted array
  for (int i = 0; i < length; i++)
  {
    printf("a[%d] = %d\n", i, a[i]);
  }

  return 0; // End of the program
}
