#include<stdio.h>
#include<conio.h>
# define max 30
void main(){
    int i,j,n,t,p[max],bt[max],wt[max],tat[max];
    float awt=0,atat=0;
    //clrscr();
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    printf("Enter the process number : ");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&p[i]);
    }
    printf("Enter the burst time of processes : ");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&bt[i]);
    }
    // applying bubble sort
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n-i-1; j++)
        {
            if(bt[j]>bt[j+1]){
                t = bt[j];
                bt[j]=bt[j=1];
                bt[j+1]=t;

                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }
        
    }
    printf("process\tburst time\twaiting time\tturn-around-time\n");
    for ( i = 0; i < n; i++)
    {
        wt[i]=0;
        tat[i]=0;
        for ( j = 0; j < i; j++)
        {
            wt[i] = wt[i]+bt[j];
        }
        tat[i] = wt[i] + bt[j];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t %d\t\t %d\t\t %d\n",p[i],bt[i],wt[i],tat[i]);
    }
    awt = awt/n;
    atat = atat/n;
    printf("Average Waiting Time : %f\n",awt);
    printf("Average Turn Around Time : %f",atat);
    getch();
}
/*
OUTPUT
Enter the number of processes : 4
Enter the process number : 1 2 3 4 
Enter the burst time of processes : 3 2 5 7
process burst time      waiting time    turn-around-time
1        3               0               3
3        2               3               5
2        3               5               8
4        7               8               15
Average Waiting Time : 4.000000
Average Turn Around Time : 7.750000
*/