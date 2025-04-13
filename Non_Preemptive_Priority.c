#include<stdio.h>

struct proc{
	int pid,at,bt,pri,ct,tat,wt,rt,status;
	};

//Gantt chart entry
struct gantt{
	int pid,start,end;
	};

struct proc read(int i){
	struct proc p;
	scanf("%d%d%d",&p.at,&p.bt,&p.pri);
	p.pid=i+1;
	p.status=0;
	return p;
	}


int main(){

//n=number of process, index=to store index value of process, ct=compute completion time, stat=sum of TAT, swt=sum of WT, prio=priority of process, pri=used as flag to check priority.
int n, index = -1, ct, stat = 0, swt = 0, prio, pri;

printf("No of process = ");
scanf("%d",&n);

struct proc p[n];
struct gantt g[n];
int gidx = 0;

//Priority type
printf("1. Lower number has high priority\n2. Lower number has low priority\n");
scanf("%d",&prio);

//Read processes
for(int i=0;i<n;i++){
	printf("AT, BT and Priority of P%d = ",i+1);
	p[i]=read(i);
	}
	
//Sort by arrival time
for(int i=0;i<n-1;i++){
	for(int j=0;j<n-i-1;j++){
		if(p[j].at>p[j+1].at){
			struct proc t=p[j+1];
			p[j+1]=p[j];
			p[j]=t;
			}
		}
	}
	
ct = p[0].at;

for(int j=0;j<n;j++){
	if (prio==1)
		pri=100;//very high so lower number will be chosen
	else
		pri=-1;
	index = -1;
	for(int i=0;i<n;i++){
		if(p[i].at<=ct && p[i].status!=1){
			if((prio == 1 && p[i].pri<pri) || (prio == 2 && p[i].pri>pri)){
				pri=p[i].pri;
				index=i;
				}
			}
		}
		
	//if no process har arrived yet, CPU is idle
	if (index == -1) {
            // CPU is idle
            int next_arrival = 9999;
            for (int i = 0; i < n; i++) {
                if (p[i].status == 0 && p[i].at > ct && p[i].at < next_arrival) {
                    next_arrival = p[i].at;
                }
            }

            // Add idle time to Gantt chart
            g[gidx].pid = 0; // 0 means IDLE
            g[gidx].start = ct;
            g[gidx].end = next_arrival;
            gidx++;

            ct = next_arrival;
            j--; // retry this iteration with new ct
            continue;
        }
		
	//Gantt chart start
	g[gidx].pid = p[index].pid;
	g[gidx].start = ct;
	
	ct = ct + p[index].bt;
	
	g[gidx].end = ct;
	gidx++;
	
	p[index].ct=ct;
	p[index].tat=p[index].ct-p[index].at;
	stat+=p[index].tat;
	p[index].wt=p[index].tat-p[index].bt;
	swt+=p[index].wt;
	p[index].rt=p[index].at+p[index].wt;
	p[index].status=1;
	
	}
	
//Display Table
printf("\n PID\tAT\tBT\tPRI\tCT\tTAT\tWT\tRT\n");
for(int i=0;i<n;i++){
	int ind;
	for(int j=0;j<n;j++){//To print in user input order
		if(p[j].pid==i+1){
			ind=j;
			break;
			}
		}
	printf(" %d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[ind].pid,p[ind].at,p[ind].bt,p[ind].pri,p[ind].ct,p[ind].tat,p[ind].wt,p[ind].rt);
	}	
	
printf("Avg TAT = %.2f\n",(float)stat/n);//Average of TAT
printf("Avg WT = %.2f\n",(float)swt/n);//Average of WT

//Gantt chart
printf("Gantt chart\n");

printf("|");
// Process IDs
for (int i=0;i<gidx;i++) {
	 if (g[i].pid == 0)
            printf("IDLE\t");
        else
            printf("P%d\t", g[i].pid);
	printf("|");
	}
	
// Timeline
printf("\n%d", g[0].start);
for (int i = 0; i < gidx; i++) {
	printf("\t%d", g[i].end);
}
printf("\n");

return 0;
}
