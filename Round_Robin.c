#include <stdio.h>

struct proc{
	int pid, at, bt, ct, tat, wt, in, rem;//in = inside queue, rem = remaining
};

int main(){
	//n = number of process, tq = time quantum, stat = sum of AT, swt = sum of WT, time = time = current time.
	int n, tq, stat = 0, swt = 0, time = 0;
	
	printf("No of process = ");
	scanf("%d",&n);
	
	struct proc p[n];
	int queue[100], rear = 0, front = 0;
	int slice[100], next = 0;//Time slice for Gantt chart
	int complete = 0;//number of completed process
	
	//Input
	for(int i = 0; i < n; i++){
		printf("AT & BT for P%d = ",i+1);
		scanf("%d%d", &p[i].at, &p[i].bt);
		p[i].pid=i+1;
		p[i].rem=p[i].bt;
		p[i].in = 0;
	}
	
	printf("Time Quantum = ");
	scanf("%d",&tq);
	
	//Add first process that arrives at time 0 or earliest
	int max=1000;
	for(int i = 0; i < n; i++){
		if(p[i].at < max)
			max = p[i].at;
	}
	time = max;
	slice[next++] = time;
	for(int i = 0; i < n; i++){
		if(p[i].at == time && !p[i].in){
			queue[rear++] = i;
			p[i].in = 1;
		}
	}
	
	printf("Gantt Chart \n|");
	while(complete < n){
		if(front == rear){
			//Queue is empty, CPU is IDLE
			printf("idle\t|");
			time++;
			
			for(int i = 0; i < n; i++){
				if(p[i].at == time && !p[i].in){
					queue[rear++] = i;
					p[i].in = 1;
				}
			}
			slice[next++] = time;
			continue;
		}
		
		int idx = queue[front++];
		printf("P%d\t|", p[idx].pid);
		
		int exec = (p[idx].rem >= tq) ? tq : p[idx].rem;
		time += exec;
		p[idx].rem -= exec;
		
		//Add new processes that have arrived during execution
		for(int i = 0; i < n; i++){
			if(p[i].at > time - exec && p[i].at <= time && !p[i].in){
				queue[rear++] = i;
				p[i].in = 1;
			}
		}
		
		if(p[idx].rem == 0){
			p[idx].ct = time;
			complete++;
			slice[next++] = time;
		}
		else{
			queue[rear++] = idx;//Not finished, re-add to queue
			slice[next++] = time;
		}
	}
	
	//Display time slice in Gantt chart
	printf("\n");
	for(int i = 0; i < next; i++)
		printf("%d\t", slice[i]);
	
	//Calculate TAT, WT
	printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    	for (int i = 0; i < n; i++) {
        	p[i].tat = p[i].ct - p[i].at;
        	p[i].wt = p[i].tat - p[i].bt;
        	stat += p[i].tat;
        	swt += p[i].wt;
        	printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
	}

	printf("\nAvg TAT = %.2f", (float)stat / n);
	printf("\nAvg WT = %.2f\n", (float)swt / n);
	
return 0;
}
