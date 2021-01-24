#include <stdio.h>


//Time Complexity 
//Best case -> O(1)
//Worst case -> O(log n)
//Average case -> O(log n)
//Space Complexity -> O(1)

void binary_Search(int A[],int n , int key);
int main(void) {
  int key;
  int A[] = {3 ,7,11,17,25,45,67,89, 90,125};
  int n = 10;
  printf("Binary search\n");
  printf("enter the item you need to search ");
  scanf("%d",&key);
  binary_Search(A, n,key);
  return 0;
}

void binary_Search(int A[],int n , int key) {
  int low = 0;
  int high = n-1 , mid;

  while(low<=high) {
    mid = (low + high) / 2;

    if (A[mid] == key) {
      printf("Search is successful we have found the item %d ",key);
      return ;
    }
    else if(key > A[mid])   // 48 < 90
      low = mid + 1; //goin in right
    else 
      high = mid - 1;
    
  }
  printf("Search unsuccesful");
}