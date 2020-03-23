
#include<stdio.h>

struct process
{
    int pid;
    int status;
    int priority;
    int at;
    int bt;
    int ct;
    int wt;
    int tt;

};

void main()
{
    int i, time = 0, burst_time = 0, current,n;
    char c;
    float w_time = 0;
    float t_time = 0;
    float avg_w_time;
    float avg_t_time;
    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    struct process pro[n];

    for(i=0;i<n;i++)
    {
        pro[i].pid = i+1;
        printf("Enter details for process no. %d:\n", pro[i].pid);
        printf("Enter Arrival Time: ");
        scanf("%d", &pro[i].at);
        printf("Enter Burst Time: ");
        scanf("%d", &pro[i].bt);
        printf("Enter Priority: ");
        scanf("%d", &pro[i].priority);
        pro[i].status = 0;
        burst_time = burst_time + pro[i].bt;
    }

    struct process temp;
    int k, j;
    for(k = 0; k < n-1; k++)
    {
        for(j = i+1 ; j < n; j++)
        {
            if(pro[k].at > pro[j].at)
            {
                temp = pro[k];
                pro[k] = pro[j];
                pro[j] = temp;
            }
        }
    }


    pro[n].priority = 9999;
    printf("-----------------------------------------------------------------");
    printf("\nProcess   \tPriority\tArrival time\tBurst time\tWaiting Time");
    for(time = pro[0].at; time < burst_time;)
    {
        current = n;
        for(i=0;i<n;i++)
        {
            if(pro[i].at <= time && pro[i].status != 1 && pro[i].priority < pro[current].priority)
            {
                current = i;
            }
        }
        time = time + pro[current].bt;
        pro[current].ct = time;
        pro[current].tt = pro[current].ct - pro[current].at;
        pro[current].wt = pro[current].ct - pro[current].at - pro[current].bt;
        pro[current].status = 1;
        t_time = t_time + pro[current].tt;
        w_time = w_time + pro[current].wt;
        printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d", pro[current].pid, pro[current].priority, pro[current].at, pro[current].bt, pro[current].wt);
    }
    printf("\n\n-----------------------------------------------------------------\n\n");
    avg_t_time = t_time/n;
    avg_w_time = w_time/n;

    printf("\nAverage waiting time: %f\n", avg_w_time);
    printf("Average Turnaround Time: %f", avg_t_time);
}