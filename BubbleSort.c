#include <stdio.h>


//Best case -> O(n)
//Worst case -> O(n^2)
// Average case -> O(n^2)
void bubble_Sort(int A[],int n);
int main(void) {
  int A[] = {12,56,7,13,90,16,33,72,42,86};
  printf("Bubble Sort\n");
  int n = 10;
  bubble_Sort(A,n);
  for(int i=0;i<=n-1;i++)
    printf("%d \n",A[i]);
  return 0;
}

void bubble_Sort(int A[],int n){
  int flag;
  int round , i , temp ;
  for(round=1; round <=n-1; round ++) {
    flag = 0;
    for(i=0 ; i<= n-1-round ; i++) {
      if(A[i] > A[i+1]) {
        flag = 1;
        temp = A[i];
        A[i] = A[i+1];
        A[i+1] = temp;
      }
    }
    if(flag == 0) {
      printf("Round = %d \n",round);
      return;
    }
  }
}