#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    printf("this is parent.PID:%d\n",(int)getpid());
    int rc=fork();
    if(rc<0){
        printf("Fork failed\n");
        exit(1);
    }
    else if(rc==0){
        sleep(5);
        printf("this is child.PID:%d\n",(int)getpid());
    }
    else{
        int rc_wait=wait(NULL);
        printf("this is my child is %d\n",rc);
    }
    printf("who am i ? PID %d\n",(int)getpid());
    return 0;
}