#include <stdio.h>
int main()
{
    int processes[10];
    int burst_time[10];
    int arrival_time[10];
    int completion_time[10];
    int wait_time[10];
    int tat[10];


    printf("Enter the number of processes;");
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        processes[i]=i;
    }

    printf("Enter the burst time respectively;");
    for(int i=1;i<=n;i++){
        scanf("%d",&burst_time[i]);
    }

    printf("Enter the arrival time respectively;");
    for(int i=1;i<=n;i++){
        scanf("%d",&arrival_time[i]);
    }

    for(int i=1;i<=n;i++){
        if(i==1){
            wait_time[i]=0;
            completion_time[i]=burst_time[i]+arrival_time[i];
            tat[i]=completion_time[i]-arrival_time[i];

        }
        else{
            completion_time[i]=completion_time[i-1]+burst_time[i];
            tat[i]=completion_time[i]-arrival_time[i];
            wait_time[i]=tat[i]-burst_time[i];
             }
    }

    printf("process    AT        BT       CT      TAT      WT");
    for(int i=1;i<=n;i++){
        printf("\n%d\t\t%d\t%d\t%d\t%d\t%d",processes[i],arrival_time[i],burst_time[i],completion_time[i],tat[i],wait_time[i]);
    }

}