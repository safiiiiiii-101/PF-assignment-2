#include <stdio.h>

int main()
{

  int array_size = 5;
  int array[array_size];
  
  printf("Please enter the values you would like to input in the array, only values less than 9999 should be entered: \n");
  
  for (int m = 0; m < array_size; m++)
  {
    scanf("%d", &array[m]);
    
    while (array[m] >= 9999)
    {
        printf("Please enter a value again, the array won't accept values greater than 9998: ");
        scanf("%d", &array[m]);
    }
  }
  
  int l_num, s_l_num;
  int smallest = 9999;
  int s_smallest = 9999;
  
  for (int m = 0; m < array_size; m++)
  {
    if (array[m] < smallest)
    {
        smallest = array[m];
    }
    else if (array[m] > smallest && array[m] < s_smallest)
    {
        s_smallest = array[m];
    }
  }
  
  if (s_smallest == 9999)
  {
      printf("No occurances of any second smallest value was found in the entered array....");
  }
  else 
  {
      printf("The Second smallest element in the array is: %d", s_smallest);
  }
  
  return 0;
}