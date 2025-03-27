#include<stdio.h>

int main(){
//sf=size of frame, sp=size of page,m=miss,h=hit,k=store last used index in frame
int sf,sp,k=0,m=0,h=0,skip=0;

//initialize frame and page
printf("Frames = ");
scanf("%d",&sf);
int frame[sf];
for(int i=0;i<sf;i++)//to know frame is empty
	frame[i]=-1;
printf("No. of Pages = ");
scanf("%d",&sp);
int page[sp];
printf("Pages = ");
for(int i=0;i<sp;i++)
	scanf("%d",&page[i]);
	
//working of FIFO
for(int i=0;i<sp;i++){
	for(int j=0;j<sf;j++){//for hit
		if(frame[j]==page[i]){
			h++;
			skip=1;
			break;
			}
		}
	if(skip==0){//for miss
		for(int j=0;j<sf;j++){//if frame is empty
			if(frame[j]==-1){
				frame[j]=page[i];
				m++;
				skip=1;
				break;
				}
		}
		if(skip==0){//insert page by first in first order in frame
			frame[k]=page[i];
			k++;
			if(k==sf)//if it reached end of the frame then assign index 0 
				k=0;
			m++;
			}
		}
	skip=0;
	}
printf("Miss = %d\n",m);
printf("Hit = %d\n",h);
for(int n=0;n<sf;n++){
	printf("%d ",frame[n]);
	}
return 0;
}
