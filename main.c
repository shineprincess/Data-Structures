#include <stdio.h>


//Time Complexity for linear serach 
//Best -> O(1)
//Worst -> O(n)
//Average -> O(n)
//Space Complexity -> O(1)

int main(void) {
  printf("Linear Search\n");

  int a[10] = {10, 23, 40, 1, 2, 0, 14, 13, 50, 9};

  int flag, i, item ;

  printf("Enter the item you want to search ");
  scanf("%d",&item);

  for(i=0;i<10;i++){
    if(a[i] == item) {
      flag = i+1;
      break;
    }

    else {
      flag=0;
    }
  }

  if(flag!=0){
    printf("%d item found at location %d",item,flag);
  }

   else 
   { 
      printf("\nItem not found\n"); 
   } 
  return 0;
}