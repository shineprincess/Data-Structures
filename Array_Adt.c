#include <stdio.h>
#include <stdlib.h>

struct arrayAdt{
//calc the size of array 
  int capacity;
//calc last index where value stored
  int lastIndex;
//ptr ->store int values in array
  int *ptr; 
};
struct arrayAdt *createArray(int capacity);
int getItem(int index,struct arrayAdt *arr);
int setItem(struct arrayAdt *arr,int index,int value);
int editItem(struct arrayAdt *arr,int index,int newValue);
 int countItems(struct arrayAdt*arr);
 int removeItem(struct arrayAdt *arr,int index);
 int search(struct arrayAdt *arr,int item);
 void sort(struct arrayAdt *arr);
 
int main(){
  int i;
  struct arrayAdt *arr;
  arr= createArray(5);
  setItem(arr,0,12);
  setItem(arr,1,45);
  setItem(arr,2,67);
  setItem(arr,3,5);
  setItem(arr,1,32);
  editItem(arr,0,50);
  removeItem(arr,0);
  
  for(i= 0;i< countItems(arr);i++){
    printf("%d ", getItem(i,arr));
    
  }
  
  sort(arr);
  printf("\n");
  for(i= 0;i< countItems(arr);i++){
    printf("%d ", getItem(i,arr));
    
  }
  i= search(arr,45);
  if(i == -1){
    printf("Item not found \n");
   }
  else{
    printf("Item found at index %d",i);
  }
  return 0;
}

struct arrayAdt *createArray(int capacity){
  struct arrayAdt *arr;
  
//malloc return address and void type so use struct arrayAdt for typecaste 
  arr=(struct arrayAdt*)(malloc(sizeof(struct arrayAdt)));
  
  arr->capacity= capacity;
  arr->lastIndex= -1;
  
//sizeof(int) becoz blocks are of int type 
//(int *) -> so that addres must be of int block 
  arr->ptr=(int*)malloc(arr->capacity*sizeof(int));
  
  return(arr);
}

int getItem(int index,struct arrayAdt *arr)
{
  int i; //for shifting value

  if(arr->lastIndex<index ||index<0){
    printf("\nInvalid Index");
    return(-1);
  }
  else{
    return(arr->ptr[index]);
  }
}

int setItem(struct arrayAdt *arr,int index,int value){
  int i;
  
//array is  full
  if(arr->lastIndex == arr->capacity-1){
    printf("\nOverflow\n");
    return(0);//insertion not possible
  }
  
  if(index<0 || index>arr->lastIndex+1){
    printf("\nInvalid Index\n");
//insettion fail
    return(0);
  }
  
  //shifting value
  if(index <= arr->lastIndex+1){
    arr->lastIndex = arr->lastIndex+1;
    i= arr->lastIndex;
    while(i!=index){
      arr->ptr[i]=arr->ptr[i-1];
      i--;
    }
    arr->ptr[index]= value;
    return(1);
  }
  
  if(index == arr->lastIndex+1){
    //arr->lastIndex++;
    arr->lastIndex +=1;
    arr->ptr[arr->lastIndex]= value;
    return(1);
  }
}

int editItem(struct arrayAdt *arr,int index,int newValue){
  if(index<0 || index>arr->lastIndex){
    printf("Invalid Index\n");
    return(0);
  }
  else{
    arr->ptr[index]=newValue;
    return(1);
  }
}

int countItems(struct arrayAdt *arr){
//if lastIndex= -1 thn +1 =0
  return(arr->lastIndex+1);
}

int removeItem(struct arrayAdt *arr,int index){
  if(index<0 || index>arr->lastIndex){
    printf("\nInvalid Index\n");
    return(0);
  }
  
//index>0 and index<lastIndex
//shifting
  if(index<arr->lastIndex){
    int i;
    i= index;
    while(i<arr->lastIndex){
      arr->ptr[i]=arr->ptr[i]+1;
      i++;
    }
    arr->lastIndex =arr->lastIndex-1;
    return(1);
  }
  if(index == arr->lastIndex){
    arr->lastIndex =arr->lastIndex-1;
    return(-1);
  }
}

int search(struct arrayAdt *arr,int item){
  
//list empty
  if(arr->lastIndex == -1){
    return(-1);
  }
  for(int i=0;i<arr->lastIndex;i++){
    if(arr->ptr[i] == item)
      return(i);
  }
  return(-1);
}

void sort(struct arrayAdt *arr){
  int n,round,i,temp;
  n= arr->lastIndex+1;
  for(round= 0; round<=n-1;round++){
    for(i= 0;i<=n-1-round;i++){
      if(arr->ptr[i]>arr->ptr[i+1]){
        temp=arr->ptr[i];
        arr->ptr[i]= arr->ptr[i+1];
        arr->ptr[i+1]= temp;
      }
    }
  }
  
}