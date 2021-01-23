#include <stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack {
  int top;
  int capacity;
  int *array;
};

struct Stack *create(int cap) {
  struct Stack *stack;
  stack =  (struct Stack *)malloc(sizeof(struct Stack ));
  stack->top = -1;
  stack->capacity=cap;
  stack->array = (int*) malloc(stack->capacity * sizeof(int));
  // size would be 6*4 = 24
  return stack;
}

int isFull(struct Stack *stack) {
  if(stack->top == stack->capacity-1) {
    return(1);
  }
  return (0);
}

int isEmpty(struct Stack *stack) {
  if(stack->top == -1) {
    return(1);
  }
  else 
    return(0);
}


void push(struct Stack *stack, int item) {
  if(!isFull(stack)) {
    stack->top++;
    stack->array[stack->top] = item;
    printf("We have pushed %d to stack\n", item); 
  }
}

int pop(struct Stack *stack) {
  int item;
  if(!isEmpty(stack)) {
    item = stack->array[stack->top];
    stack->top--;
    return(item);
  }
  return(-1);
  
}

int main(void) {
  struct Stack *stack ;
  int value,choice;
  stack = create(4);
  
  while(1) {

    printf("\n 1: Push \n 2: Pop \n 3: Exit \n Enter one of your choices: ");
    scanf("%d",&choice);

    switch(choice)
        {
            case 1:
                printf("Enter the item you want to insert :");
                scanf("%d",&value);
                push(stack,value);
            break;

            case 2:
                value = pop(stack);
                if(value == -1)
                  printf("Stack is empty");
                else 
                  printf("We have popped %d from stack\n", value);
                break;

            case 3:
                exit(0);

            default:
                printf("\nPlease enter a correct option\n");
            break;
        }
  }
  return(0);
}









  
