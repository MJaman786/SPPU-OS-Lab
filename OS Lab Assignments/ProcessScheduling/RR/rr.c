#include<stdio.h>
#include<conio.h>

void main(){
    int n, i, qt, count=0, temp, sq=0, bt[10], wt[10], tat[10],rem_bt[10];
    float awt = 0;
    float atat = 0;
    printf("Enter number of processes : ");
    scanf("%d",&n);
    printf("Enter burst time of processes : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&bt[i]);
        rem_bt[i] = bt[i];
    }
    printf("Enter quantum time : ");
    scanf("%d",&qt);
    while(1){
        for (i=0,count=0; i<n; i++)
        {
            temp = qt;
            if (rem_bt[i]==0)
            {
                count++;
                continue;
            }
            if (rem_bt[i]>qt)
            {
                rem_bt[i] = rem_bt[i] - qt;
            }
            else
                if(rem_bt[i]>=0){
                    temp = rem_bt[i];
                    rem_bt[i] = 0;
                }
                sq = sq+temp;
                tat[i] = sq;
        }
        if (n==count)
        {
            break;
        }
    }
    printf("\nProcess\tburst-time\tturnaround-time\twaiting-time\n");
    for ( i = 0; i < n; i++)
    {
        wt[i]=tat[i]-bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("\n%d\t %d\t\t %d\t\t %d\n",i+1, bt[i], tat[i], wt[i]);
    }
    awt = awt/n;
    atat = atat/n;
    printf("Average waiting time : %f\n",awt);
    printf("Average turn around time : %f",atat);
}

/*
output
Process burst-time      turnaround-time waiting-time

1        5               13              8

2        3               10              7

3        1               5               4

4        4               12              8
Average waiting time : 6.750000
Average turn around time : 10.000000
*/