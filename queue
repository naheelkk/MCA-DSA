#include <stdio.h>
#include <stdlib.h>

int front = 0, rear = -1, size = 5, item, arr_queue[5];

void push(){
    if(rear >= size - 1){
        printf("Overflow\n");
    }
    else{
        printf("Enter your Item: ");
        scanf("%d",&item);
        rear++;
        arr_queue[rear] = item;
    }
}

void pop(){
    if(front > rear){
        printf("Underflow (Queue is Empty)\n");
    }
    else{
        item = arr_queue[front];
        printf("Popped item is %d\n", item);
        front++;
    }
}

void display(){
    if(front > rear){
        printf("Queue is Empty\n");
    } else {
        printf("Queue: ");
        for(int i = front; i <= rear; i++){
            printf("%d\t", arr_queue[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice;
    printf("You've got a Queue of Size %d\n", size);
    while(choice != 4){
        printf("1.Push\t 2.Pop\t 3.Display\t 4.Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}
