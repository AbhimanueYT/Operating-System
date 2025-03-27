#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[]){
int fd1,fd2;
char c;
ssize_t readit;
if (argc!=3){
	printf("Error: ./a.out src.txt des.txt");
	return 0;
	}
else{
	fd1 = open(argv[1],O_RDONLY);
	if (fd1 == -1){
		printf("File error");
		return 0;
		}
	fd2 = open(argv[2],O_WRONLY | O_CREAT,0644);
	if (fd2 == -1){
		perror("File error");
		close(fd1);
		return 0;
		}
	while((readit=read(fd1,&c,1))>0){
		write(fd2,&c,1);
		}
	printf("Done");
	}
close(fd1);
close(fd2);
return 0;
}
