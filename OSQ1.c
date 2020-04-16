// The following processes are being scheduled using a preemptive, round robin scheduling
// algorithm. Each process is assigned a numerical priority, with a higher number indicating
// a higher relative priority. In addition to the processes listed below, the system also has an
// idle task (which consumes no CPU resources and is identified as P_idle ). This task has
// priority 0 and is scheduled whenever the system has no other available processes to run.
// The length of a time quantum is 10 units. If a process is preempted by a higher-priority
// process, the preempted process is placed at the end of the queue.
// Thread Priority Burst Arrival
// P1 40 20 0
// P2 30 25 25
// P3 30 25 30
// P4 35 15 60
// P5 5 10 100
// P6 10 10 105
// Write a C code to
// a. Show the scheduling order of the processes using a Gantt chart.
// b. What is the turnaround time for each process?
// c. What is the waiting time for each process?
// d. What is the CPU utilization rate?


#include<stdio.h>
#include<conio.h>
int main()
{
    int n;
    printf("Enter the number of process : ");
    scanf("%d",&n);
    int arrival[n], burst[n], priority[n], process[n], timequantum;
    int i;

    //Input of Priority, Arrival Time and Burst Time of processes
    for(i=0;i<n;i++)
    {
        printf("For P%d :-\n",i+1);
        printf("Enter Priority : ");
        scanf("%d",&priority[i]);
        printf("Enter Burst Time : ");
        scanf("%d",&burst[i]);
        printf("Enter Arrival Time : ");
        scanf("%d",&arrival[i]);
    }

    printf("\nEnter time quantum : ");
    scanf("%d",&timequantum);

    int position, j, swap;
    for(i=0;i<n;i++)
	{
		position=i;
		for(j=i+1;j<n;j++)
		{
			if(arrival[j]<arrival[position])
   			position=j;
		}
		swap=burst[i];
		burst[i]=burst[position];
		burst[position]=swap;
		swap=arrival[i];
		arrival[i]=arrival[position];
		arrival[position]=swap;
        swap=priority[i];
		priority[i]=priority[position];
		priority[position]=swap;
		swap=process[i];
		process[i]=process[position];
		process[position]=swap;
	}

    float waiting, turnaround;
    int newburst[n];
    for (i=0; i<n; i++)
    {
        newburst[i]=burst[i];
    }
    int tim, remain = n, flag = 0, x = n, y = n, idle = 0;
    printf("\nProcess\tTurnaround Time\tWaiting Time");
    while(x)
    {
        for( tim=0, i=0; remain!=0;)
        {
            if(newburst[i]<=timequantum && newburst[i]>0)
            {
                tim=tim+newburst[i];
                newburst[i]=0;
                flag=1;
            }
            else if(newburst[i]>0)
            {
                newburst[i] = newburst[i] - timequantum;
                tim = tim+ timequantum;
            }
            if(newburst[i]==0 && flag==1)
            {
                remain--;
                printf("\nP%d\t\t%d\t\t%d\n",i+1,tim-arrival[i],tim-arrival[i]-burst[i]);
                waiting = waiting + tim - arrival[i] - burst[i];
                turnaround = turnaround + tim - arrival[i];
                flag = 0;
                x--;
            }
            if(i==y-1)
                i=0;
            if((arrival[i+1]>tim && newburst[i]==0))
            {
                idle = idle + (arrival[i+1] - tim);
                tim = (tim + (arrival[i+1] - tim));
                i++;
            }
            else if(arrival[i+1] <= tim)
            {
                i++;
            }
       }
    }
    printf("\nIdle Time : %d  \n",idle);
    float utilpercent = (tim - idle) * 100;
    printf("\nCPU utilization percentage : %f\n",utilpercent/tim);
    printf("\nAverage waiting time : %f\n\n",waiting/y);
    printf("Average turnaround time : %f\n\n",turnaround/y);
    
    return 0;
}