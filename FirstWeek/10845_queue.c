#include <stdio.h>
#include <string.h>

int buffer[10001];
int n=0;
int front_ = 0;
int back_ = 0;
int output[10000];
int outnum = -1;

void push(int a) {
    
    
    buffer[back_] = a;
    back_++;
    n++;
    
}

void pop() {

    outnum++;
    if(front_==back_){
        output[outnum]=-1;
    }
    else{
        
        n--; 
        output[outnum]=buffer[front_];
        front_++;
    }
    
}

void size() {
    outnum++;
    output[outnum]=n;
}

void empty() {
    outnum++;
    if(front_ < back_) {
        output[outnum]=0;
    }
    else if(front_ == back_) {
        output[outnum]=1;
    }
}

void front() {
    outnum++;
    if(front_ < back_) {
        output[outnum]=buffer[front_];
    }
    else if(front_ == back_) {
        output[outnum]=-1;
    }
}

void back() {
    outnum++;
    if(front_ < back_) {
        output[outnum]=buffer[back_-1];
    }
    else if(front_ == back_) {
        output[outnum]=-1;
    }
}



int main() {

    int commandNum = 0;
    scanf("%d", &commandNum);
    int a;

    for(int i=0; i<commandNum; i++) {
        
        char expression[30];
        scanf("%s", expression);

        if(!strcmp(expression, "push")){
            scanf("%d", &a);
            push(a);
        }
        else if(!strcmp(expression, "pop")){
            pop();
        }
        else if(!strcmp(expression, "size")){
            size();
        }
        else if(!strcmp(expression, "empty")){
            empty();
        }
        else if(!strcmp(expression, "front")){
            front();
        }
        else if(!strcmp(expression, "back")){
            back();
        }
    }
    for (int i = 0; i<= outnum; i++) {
        printf("%d\n", output[i]);
    }
    
    return 0;

}