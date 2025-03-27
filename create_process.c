#include<stdio.h>
#include<unistd.h>

int main(){
int p = fork();
if (p==-1){
	printf("Nope");
	return 1;
	}
else if (p==0)
	printf("Child created :) %d\n",getpid());
else
	printf("Parent created !! %d\n",getppid());
return 0;
}
