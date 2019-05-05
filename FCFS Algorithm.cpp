	
#include<iostream>
using namespace std; 
int main()
{
    int p,bursttime[10],waitingtime[10],tat[10],avwt=0,avtat=0,i,j;
    cout<<"Enter total number of processes(should not be more than 10):";
    cin>>p;
 
    cout<<"\nEnter Process Burst Time\n";
    for(i=0;i<p;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>bursttime[i];
    }
 
    waitingtime[0]=0;    //waiting time for first process is 0
 
    //calculating waiting time
    for(i=1;i<p;i++)
    {
        waitingtime[i]=0;
        for(j=0;j<i;j++)
            waitingtime[i]+=bursttime[j];
    }
 
    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
 
    //calculating turnaround time
    for(i=0;i<p;i++)
    {
        tat[i]=bursttime[i]+waitingtime[i];
        avwt+=waitingtime[i];
        avtat+=tat[i];
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bursttime[i]<<"\t\t"<<waitingtime[i]<<"\t\t"<<tat[i];
    }
 
    avwt/=i;
    avtat/=i;
    cout<<"\n\nAverage Waiting Time:"<<avwt;
    cout<<"\nAverage Turnaround Time:"<<avtat;
 
    return 0;
}
