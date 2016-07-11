#include<stdio.h>
int main()
{
	int male[100],female[100];
	int n,m; float summale= 0,sumfemale = 0;
	float avgmale,avgfemale;
	printf("Give No. of Male and Female\n");
	scanf("%d%d",&n,&m);
	printf("Male Height\n");
	for(int i = 0; i < n; i++)
	scanf("%d",&male[i]);
	printf("Female height\n");
	for(int i = 0; i < m; i++)
	scanf("%d",&female[i]);
	for(int  i = 0 ;i < n; i++)
	summale = summale + male[i];
	avgmale = summale/n;
	for(int  i = 0 ;i < m; i++)
	sumfemale = sumfemale + female[i];
	avgfemale = sumfemale/m;
	printf("Average of male and female Height is %f and %f respectively\n\n",avgmale,avgfemale);
}
