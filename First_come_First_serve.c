#include<stdio.h>

int main(){

int p,stat=0,swt=0;//stat=sum of TAT; swt=sum of WT, p=number of process

printf("No of process = ");
scanf("%d",&p);

//initialization
int at[p],bt[p],ct[p],tat[p],wt[p],rt[p],pid[p];
for(int i=0;i<p;i++){
	printf("AT and BT of P%d = ",i+1);
	scanf("%d",&at[i]);
	scanf("%d",&bt[i]);
	pid[i]=i+1;
	}

//Sort process in arrival time
for(int i=0;i<p-1;i++){
	for(int j=0;j<p-i-1;j++){
		if(at[j]>at[j+1]){
			int t=at[j];
			at[j]=at[j+1];
			at[j+1]=t;
			t=bt[j];
			bt[j]=bt[j+1];
			bt[j+1]=t;
			t=pid[j];
			pid[j]=pid[j+1];
			pid[j+1]=t;
			}
		}
	}
ct[0]=at[0]+bt[0];//Always first process's completion time will be at+bt of it
rt[0]=0;//Always first process's response time will be "0" 

for(int i=1;i<p;i++){
	if(ct[i-1]>=at[i]){
		ct[i]=ct[i-1]+bt[i];//Completion time
		rt[i]=ct[i-1]-at[i];//Response time
		}
	else{
		ct[i]=at[i]+bt[i];//Completion time
		rt[i]=0;//Response time
		}
	}
	
for(int i=0;i<p;i++){
	tat[i]=ct[i]-at[i];//Turn-around time
	wt[i]=tat[i]-bt[i];//waiting time
	}
	
//Display Table
printf(" PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
for(int i=0;i<p;i++){
	int index;
	for(int j=0;j<p;j++){
		if(pid[j]==i+1){
			index=j;
			break;
			}
		}
	printf(" %d\t%d\t%d\t%d\t%d\t%d\t%d\n",pid[index],at[index],bt[index],ct[index],tat[index],wt[index],rt[index]);
	}
for(int i=0;i<p;i++){
	stat+=tat[i];//Sum of TAT
	swt+=wt[i];//Sum of WT
	}
	
printf("Avg TAT = %.2f\n",(float)stat/p);//Average of TAT
printf("Avg WT = %.2f\n",(float)swt/p);//Average of WT

//Gantt chart
printf("Gantt chart\n");
if(at[0]>0)
	printf("(0)|idle (%d)| P%d (%d)|",at[0],pid[0],ct[0]);
else
	printf("(0)| P%d (%d)|",pid[0],ct[0]);
for(int i=1;i<p;i++){
	if(ct[i-1]>=at[i])
		printf(" P%d (%d)|",pid[i],ct[i]);
	else
		printf("idle (%d)| P%d (%d)|",at[i],pid[i],ct[i]);
	}

return 0;
}
