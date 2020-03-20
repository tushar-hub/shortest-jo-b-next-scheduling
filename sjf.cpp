#include<iostream.h>
#include<stdio.h>
#include<conio.h>
int main()
{
  printf("\t\t\t--(OPERATING SYSTEM CA ON SCHEDULING)---");
  long int n,j=0,i=0;
  printg("PLEASE ENTER HT ENUMBER OF PROCESSES WITH YOU WANT TO PROCEED :");
  scanf("%ld",&n);
  double bT[n],aT[n],wT[n],tT[n],priority[n],pro[n],   
  order, cT[n],min,sum=0,sum1=0,avg_wait,avg_ta,wait_final, ta_final, wait_avg, ta_avg;
  for(i=0;i<n;i++)
  {
    printf("PLEASE ENTER THE ARRIVAL TIME FOR THE PROCESSES[%d]:",i+1);
    scanf("%lf",&aT[i]);
    printf("PLEASE ENTER THE BURST TIME TIME FOR THE PROCESSES[%d]:",i+1);
    scanf("%lf",&bT[i]);
    pro[i]=i+1;
  }
    printf("\n\n\t\t\t-------VALUES AFTER ARRANGING THE PROCEESES ACCORDING TO THEIR ARRIVAL TIME-------\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(aT[i]<aT[j])
      {
        order=pro[j];
        pro[j]=pro[i];
        pro[i]=order;
          order = aT[j];
        aT[j] = aT[i];
       aT[i] = order;
       
      order = bT[j];
        bT[j] = bT[i];
        bT [i] = order;
      }
    }
  }
  printf("\t\t\t---------------------------------------\n");
  printf("\t\t\t| PROCESS | ARRIVAL TIME | BURST TIME |\n");
  printf("\t\t\t---------------------------------------\n");
  for(i=0;i<n;i++)
  {
     printf("\t\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |\n",pro[i],aT[i],bT[i]);
  }
    printf("\t\t\t---------------------------------------\n");
