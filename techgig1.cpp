#include<stdio.h>
#include<string.h>
int min(int a,int b){
    return (a<b)?a:b;
}

int GetWaterLevel(int input1,int input2,int input3[])
{
    //Write code here
    int n=input1,m=input2,i,j,ans=0;
    int aa[11][11],b[11][11];
    for(i=0;i<n*m;i++)
    {
        aa[i/m][i%m]=input3[i];
    }
    for(i=1;i<n-1;i++)
    {
        int k,max=0,index;
        for(k=0;k<m;k++)
            {if(aa[i][k]>max)
             {
              max=aa[i][k];
            index = k;
             }  
            }
        int l=aa[i][0];            
        for(j=1;j<index;j++)
        {
           if(aa[i][j]<l)
            b[i][j]=l-aa[i][j];
            else
            {
                    b[i][j] = 0;
                if(max>aa[i][j])
                l=aa[i][j];
                else
                    l=max;
            }
        }
        l=aa[i][m-1];            
        for(j=m-1;j>index;j--)
        {
           if(aa[i][j]<l)
            b[i][j]=l-aa[i][j];
            else
            {
                    b[i][j] = 0;
                if(max>aa[i][j])
                l=aa[i][j];
                else
                    l=max;
            }
        }
        }
    for(j=1;j<m-1;j++)
    {
        int k,max=0,index;
        for(k=0;k<n;k++)
            {if(aa[k][j]>max)
             {
              max=aa[k][j];
            index = k;
             }  
            }
        int l=aa[0][j];            
        for(i=1;i<index;i++)
        {
           if(aa[i][j]<l)
            {
                if((l-aa[i][j])<b[i][j])
                b[i][j]=l-aa[i][j];
            }
            else
            {

                    b[i][j] = 0;
                if(max>aa[i][j])
                l=aa[i][j];
                else
                    l=max;
            }
        }
        l=aa[n-1][j];            
        for(i=n-1;i>index;i--)
        {
           if(aa[i][j]<l)
           {
            if((l-aa[i][j])<b[i][j])
            b[i][j]=l-aa[i][j];
           }
            else
            {
                    b[i][j] = 0;
                if(max>aa[i][j])
                l=aa[i][j];
                else
                    l=max;
            }
        }
        for(i=1;i<n-1;i++)
        {
            for(j=1;j<m-1;j++)
                ans+=b[i][j];
        }
    }
    return ans;
}
int main(){
    int n,m,a[101];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n*m;i++)
        scanf("%d",&a[i]);
    printf("%d\n",GetWaterLevel(n,m,a));
}