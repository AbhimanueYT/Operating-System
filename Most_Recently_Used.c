#include<stdio.h>

int main(){
//sf=size of frame, sp=size of page,m=miss,h=hit
int sf,sp,m=0,h=0,skip=0;

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
		
//working of LRU
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
		if(skip==0){
			int max=-1;//assign min value, to get maximum value in index
			int index[sf];
			for(int j=0;j<sf;j++){//to get index value of pages present in frame
				for(int k=0;k<=i;k++){
					if(frame[j]==page[k]){
						index[j]=k;
						}
					}
				}
			for(int j=0;j<sf;j++){//to get maximum value
				if(max<index[j])
					max=index[j];
				}
			for(int j=0;j<sf;j++){//to replace the value in frame with page
				if(page[max]==frame[j]){
					frame[j]=page[i];
					m++;
					break;
					}
				}
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
