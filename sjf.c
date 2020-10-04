#include<stdio.h>

void main()
{
    int n;
    float avg_wt,avg_tat;
    printf("Enter number of process: ");
    scanf("%d",&n);
    int processes[n],burst_time[n],wt[n],tat[n],i,j,total_wt=0,total_tat=0,temp;
    for(int k=0;k<n;k++)
    {
	 printf("Enter process id and burst time of process %d: ",(k+1));
	 scanf("%d",&processes[k]);
     scanf("%d",&burst_time[k]);
    }
    
 //Bubble sort to sort burst time
    for(i = 0; i < n-1; i++) { 
      for(j = 0; j < n-1-i; j++) {
         if(burst_time[j] > burst_time[j+1]) {
            temp = burst_time[j];
            burst_time[j] = burst_time[j+1];
            burst_time[j+1] = temp;
         }
      }
    }
    wt[0]=0; 
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=burst_time[j];
 
        total_wt=total_wt+wt[i];
    }
 
    avg_wt=(float)total_wt/n;
 
    printf("Processes\tBurst Time\tWaiting Time\tTurn-Around Time \n");
    for(i=0;i<n;i++)
    {
        tat[i]=burst_time[i]+wt[i];   
        total_tat+=tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d",processes[i],burst_time[i],wt[i],tat[i]);
        printf("\n");
    }
 
    avg_tat=(float)total_tat/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}

