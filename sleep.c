#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
int p = fork();
if (p==-1){
	printf("Nope");
	return 1;
	}
else if (p==0){
	printf("Zzz.... (5sec)\n");
	sleep(5);
	printf("Child created :) %d\n",getpid());
	return 0;
	}
else{
	wait(NULL);
	printf("Parent created !! %d\n",getppid());
	}
return 0;
}
