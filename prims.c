#include<stdio.h>
void prims(int n,int cost[n][n]);
int min(int n,int k,int cost[n][n]);
int mincost(int near[],int n,int cost[n][n]);

int main()
{
    int i,j,n;
    printf("\nEnter the number of nodes: ");
    scanf("%d",&n);
    int cost[n][n];
    printf("\nEnter the cost: ");
    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
       {
          printf("\nEnter for (%d,%d): ",i,j);
          scanf("%d",&cost[i][j]);
       }
    }
    printf("\nEnter costs are:\n");
    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
       {
          printf("\t %d",cost[i][j]);
       }
       printf("\n");
    }
    prims(n,cost); 
	return 0;
}

int min(int n,int k,int cost[n][n])
{
   int m=99,t,i;
   for(i=0;i<n;i++)
   {
      if(cost[k][i] < m)
      {
         m = cost[k][i];
         t = i;
      }
   }
   return t;
}

int mincost(int near[],int n,int cost[n][n])
{
   int i,t,m=99;
   printf("\nNear array:\n");
   for(i=0;i<n;i++)
   {
	   printf("%d\t",near[i]);
   }
   for(i=0;i<n;i++)
   {
       if(near[i] != -1 && cost[i][near[i]]<m)
       {
           m = cost[i][near[i]];
           t = i;
       }
   }
   return t;
}

void prims(int n,int cost[n][n])
{
   int k=0,l=0,t[4][2],i,near[n],j,mcost=0;
   l = min(n,k,cost);
   t[0][0] = k;
   t[0][1] = l;
   mcost = mcost + cost[k][l];
   printf("\nEdges are:%d-%d",t[0][0],t[0][1]);  
   for(i=0;i<n;i++)
   {
      if(cost[i][k] < cost[i][l])
      {
          near[i] = k;
      }
      else
      { 
          near[i] = l;
      }
   }
   near[k] = -1;
   near[l] = -1;
   for(i=1;i<n-1;i++)
   {
      k = mincost(near,n,cost);
      l = near[k];
	  printf("\nnew edges will be added");
      t[i][0] = k;
      t[i][1] = l;
      mcost = mcost + cost[k][l];
	  printf("\nEdges are:%d-%d",t[i][0],t[i][1]);  
      near[k] = -1;
      for(j=0;j<n;j++)
      {
         if(near[j] != -1 && cost[j][near[j]] > cost[k][j])
         {
             near[j] = k; 
         }
      }
   }
   printf("\nTotal minimum cost: %d",mcost);
}



