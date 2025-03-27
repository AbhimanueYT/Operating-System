#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int n,char *arg[]){
int fd1,fd2;
if (n!=3){
	printf("Error: ./a.out src.txt des.txt");
	return 0;
	}
fd1 = open(arg[1],O_RDONLY);
if (fd1 == -1){
	perror("File Error");
	}
fd2 = open(arg[2],O_WRONLY | O_CREAT,0644);
if (fd2 == -1){
	perror("File Error");
	close(fd1);	
	}
int end = lseek(fd1,0,SEEK_END);
lseek(fd1,0,0);
char data[end];
read(fd1,data,end);
for(int i=0;i<end;i++)
	write(fd2,&data[end-(i+1)],1);
close(fd1);
close(fd2);
return 0;
}
