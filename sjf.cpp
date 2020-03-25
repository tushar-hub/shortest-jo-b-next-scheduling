#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int average_turnaroundtime=0,average_waitingtime=0;
struct Processes
{
    long pid=0;                                       
    long priority=0;                                  
    long arrival_time=0;                              
	long burst_time=0;                                
    long completion_time=0;                           
    long turnaround_time=0;                           
	long waiting_time=0; 
    bool completed=false;                            //true=means fully executed                                                       
};
bool comparison_Priority(Processes a, Processes b)        //Driver Function-Sorting According to Priority
{ 
    return (a.priority < b.priority); 
}
bool comparison_ArrivalTime(Processes a,Processes b)      //Driver Function-Sorting According to Arrival Time(Acending Order)
{
    return (a.arrival_time < b.arrival_time);
}
bool comparison_PID(Processes a,Processes b)              //Driver Function-Sorting According to PID(Acending Order)
{
    return (a.pid < b.pid);
}
bool comparison_BurstTime(Processes a,Processes b)  
{
    return (a.burst_time < b.burst_time);
}
int Show_Process(Processes p[],int n,bool b=false)
{
    if(b==false)
    {
        cout<<"\nPID || Arrival Time || Burst Time\n";
        for(long i=0;i<n;i++)
        {
            cout<<p[i].pid<<"\t"<<p[i].arrival_time<<"\t\t"<<p[i].burst_time<<"\n";
        }
    }
    if(b==true)
    {
        cout<<"\nPID || Arrival Time || Burst Time || Completetion Time || TurnAround time || Waiting Time\n";
        for(long i=0;i<n;i++)
        {
            cout<<p[i].pid<<"\t"<<p[i].arrival_time<<"\t\t"<<p[i].burst_time<<"\t\t"<<p[i].completion_time<<"\t\t"<<p[i].turnaround_time<<"\t\t"<<p[i].waiting_time<<"\n";
        }
    }
    return 0; 
}
int calculate_priority(Processes p[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(p[i].completed==false)
        {
            p[i].priority=1+(p[i].waiting_time/p[i].burst_time);
        }
    }
    return 0;
}
int calculate_waitingtime(Processes p[],int n,int time)
{
    for(int i=0;i<n;i++)
    {
        if(p[i].arrival_time<=time && p[i].completed==false)
        {
            p[i].waiting_time=time-p[i].arrival_time;
        }
    }
    return 0;
}
int calculation(Processes p[],int n,int time)
{
    int sumt=0,sumw=0;
    for(int i=0;i<n;i++)
    {
        p[i].turnaround_time=p[i].completion_time-p[i].arrival_time;
    }
    for(int i=0;i<n;i++)
    {
        sumt+=p[i].turnaround_time;
        sumw+=p[i].waiting_time;
    }
    cout<<"\n\n\t\tAverage waiting Time:"<<sumw/n;
    cout<<"\n\n\t\tAverage TurnAround Time:"<<sumt/n;
    return 0;
}
int SJF(Processes p[],int n,int max_arrival,int min_arrival)
{
    int time=min_arrival,flag=0;
    while(flag==0)
    {
        int current=0,greateast_priority=p[0].priority,execute=-1;
        for(int i=0;i<n;i++)
        {
            if(p[i].arrival_time<=time)
            {
                current=i;
                continue;
            }
        }
        for(int j=0;j<=current;j++)
        {
            if(p[j].priority>=greateast_priority && p[j].completed==false)
            {
                greateast_priority=p[j].priority;
                execute=j;
            }
        }
        time+=p[execute].burst_time;
        p[execute].completion_time=time;
        p[execute].completed=true;
        for(int k=0;k<n;k++)
        {
            if(p[k].completed==false)
            {
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
        }
        calculate_waitingtime(p,n,time);
        calculate_priority(p,n);
    }
    return time;
}
int main()
{
    int n,pid=1,time=0;
    int max_arrival=-1,min_arrival=INT_MAX;
    cout<<"Enter No Of Processes:";
    cin>>n;
    Processes p[n];
    while(n<=0)
    {
    	printf("please enter valid no. of processes\n");
    	cout<<"Enter No Of Processes again:";
    cin>>n;
    Processes p[n];
    	
	}
    for(int i=0;i<n;i++)
    {
        cout<<"FOR PROCESS:"<<i+1<<endl;
        p[i].pid=pid;
        cout<<"Enter Arrival Time:";
        cin>>p[i].arrival_time;
         while(p[i].arrival_time<=-1)
        {
        	printf("ARIVAL TIME CANNOT BE IN NEGATIVE\n");
        	cout<<"Enter Arrival Time again please\n:";
        cin>>p[i].arrival_time;
        }
        if(p[i].arrival_time<min_arrival)
        {
            min_arrival=p[i].arrival_time;
        }
        if(p[i].arrival_time>max_arrival)
        {
            max_arrival=p[i].arrival_time;          
        }
        cout<<"Enter Burst Time:";
        cin>>p[i].burst_time;
        while(p[i].burst_time<=-1)
        {
        	printf("BURST TIME CANNOT BE IN NEGATIVE\n");
        	 cout<<"Enter Burst Time again\n:";
            cin>>p[i].burst_time;
        	
		}
        cout<<endl;
        pid++;
    }
    sort(p,p+n,comparison_BurstTime);
    sort(p,p+n,comparison_ArrivalTime);
    Show_Process(p,n);
    calculate_priority(p,n);
    time=SJF(p,n,max_arrival,min_arrival);
    calculation(p,n,time);
    Show_Process(p,n,true);
    cout<<"\nALL the process Completed in:"<<time;
    system("pause");
    return 0;
}
