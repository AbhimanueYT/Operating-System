#include<stdio.h>

int main(){
int sf,i=0,m=0,h=0;//sf=size of frame,m=miss,h=hit


//initialize page and frame
int page[25] = {[0 ... 24]=-1};
printf("Frame size = ");
scanf("%d",&sf);
int frame[sf];

//set all frames to -1 to avoid confusion amoung pages and frame value
for(i=0;i<sf;i++){
	frame[i]=-1;
	}

printf("Pages = ");
i=0;
while (1){
	int t;
	scanf("%d",&t);
	if (getchar() == '\n'){
		page[i]=t;
		break;}
	page[i]=t;
	i++;
}
int sp=i;//size of page

//OPR working
for (i=0;i<=sp;i++){

	int c=0;
	for (int j=0;j<sf;j++){//for hit
		if(page[i]==frame[j]){
			h++;
			c=1;
			break;}
		}
	if (c==0){//for miss
		int index[sf];//to save index of pages in frame
		for(int j=0;j<sf;j++){//for empty frame
			if(frame[j]==-1){
				frame[j]=page[i];
				m++;
				c=1;
				break;
				}
			}
		if(c!=1){//for not empty frame
		//to know which page will be used furthest in the future
			for(int j=0;j<sf;j++){
				for(int k=i;k<=sp;k++){
					if(frame[j]==page[k]){
						index[j]=k;
						break;
						}
					index[j]=-1;
					}
				}
			int max=-1;//to save maximum index value of page
			int inf=-1;//to save index of frame whose page is not used in future 
			//to get index of the page which will be used furthest in the future
			for(int j=0;j<sf;j++){
				if(index[j]==-1){//if any page is not used in future
					inf=j;
					max=-1;
					break;
					}
				if(max<index[j])
					max=index[j];
				}
			
			//if any of the pages are used in future
			if(inf!=-1){
				frame[inf]=page[i];
				m++;
				}
			else{
				for(int j=0;j<sf;j++){
					if(frame[j]==page[max]){
						frame[j]=page[i];
						m++;
						break;
						}	
					}
				}
			}
		}
	}
printf("Miss = %d\n",m);
printf("Hit = %d\n",h);
for(i=0;i<sf;i++){
	printf("%d ",frame[i]);
	}

return 0;
}
