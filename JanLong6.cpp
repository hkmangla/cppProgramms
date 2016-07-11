#include<iostream>
#include<math.h>
#define mod 1000000007
using namespace std;
int check(int m,int aa[],int a[])
{
	int sum=0;int ii=300;
	for(int i=0;i<m;i++)
	{
		if(a[aa[i]]==1)
		{
			int kf=aa[i];
			sum++;
			for(int j=0;j<m;j++)
			{
				for(int k=0;k<m;k++)
				{
					if(ii!=k)
					{
						if(kf==aa[k])
						{
							if(k%2==0)
							{
								ii=k+1;kf=aa[ii];sum++;
								break; 
							}
							if(k%2==1)
							{
								ii=k-1;kf=aa[ii];sum++;
								break;
							}
						}
					}
				}
				if(a[kf]==1)
				{
					a[kf]=0;
					break;
				}
			}
		}
	}
	return sum;
}
long long int fact(long long int a)
{
	if(a==1||a<=0)
		return 1;
	else
		return (a*fact(a-1))%mod;
 } 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i,j,k,n; int m;
		cin>>n>>m;
	    int c[10],d[10];
		long long int per[10],pairs[10];
		for(i=0;i<10;i++)
		{
		    pairs[i]=0;
		    per[i]=0;
	    }
		per[0]=fact(n);
		for(i=1;i<8;i++)
    	{
	    	if((n-i)>=0)
			    per[i]=fact(n-i);
		}
		for(i=0;i<m;i++)
		{
		    cin>>c[i]>>d[i];
		}
		//single pair
		pairs[1]=(2*per[1]*m)%mod;
		//double pair
		for(i=0;i<m-1;i++)
		{
			for(j=i+1;j<m;j++)
			{
				int aa[10],size=4;
				aa[0]=c[i];aa[1]=d[i];aa[2]=c[j];aa[3]=d[j];
				for(int ii=0;ii<3;ii++)
				{
					for(int jj=ii+1;jj<4;jj++)
					{
						if(aa[ii]==aa[jj])
						{
							size--;
						}
					}
				}
				if(size==3)
					pairs[2]+=2*per[2];
				if(size==4)
					pairs[2]+=4*per[2];
				pairs[2]%=mod;
			}
		}
		//triple pair
	    for(i=0;i<m-2;i++)
		{
			for(j=i+1;j<m-1;j++)
			{
				for(k=j+1;k<m;k++)
				{
					//cout<<"1 ";
					int size=6;
					int aa[15]; aa[0]=c[i];aa[1]=d[i];aa[2]=c[j];aa[3]=d[j];aa[4]=c[k];aa[5]=d[k];
					int a[100000];
					for(int o=0;o<100000;o++)
						a[o]=1;
					for(int ii=0;ii<5;ii++)
					{
						int kc=0;
						for(int jj=ii+1;jj<6;jj++)
						{
							if(aa[ii]==aa[jj])
							{
								size--;
								a[aa[ii]]++;
								kc++;
							}
						}
						if(kc>=2)
						{
							size=0;
							break;
						}
					}
					
					if(size!=0)
					{
						int yyy=check(6,aa,a);
						if(yyy!=size)
							size=0;
					}
					if(size==4)
						pairs[3]+=2*per[3];
					if(size==5)
						pairs[3]+=4*per[3];
					if(size==6)
						pairs[3]+=8*per[3];
                    pairs[3]%=mod;
			   }
			}
		}
		//four pair
		for(i=0;i<m-3;i++)
		{
			for(j=i+1;j<m-2;j++)
			{
				for(k=j+1;k<m-1;k++)
				{
					for(int l=k+1;l<m;l++)
					{
						int size=8;
						int aa[15]; aa[0]=c[i];aa[1]=d[i];aa[2]=c[j];aa[3]=d[j];aa[4]=c[k];aa[5]=d[k];aa[6]=c[l];aa[7]=d[l];
						int a[100000];
						for(int o=0;o<100000;o++)
							a[o]=1;
						for(int ii=0;ii<7;ii++)
						{
							int kc=0;
							for(int jj=ii+1;jj<8;jj++)
							{
								if(aa[ii]==aa[jj])
								{
								size--;
								a[aa[ii]]++;
								kc++;
								}
							}
							if(kc>=2)
							{
								size=0;
								break;
							}
						}
						if(size!=0)
						{
							int yyy=check(8,aa,a);
							if(yyy!=size)
								size=0;
						}
						if(size==5)
							pairs[4]+=2*per[4];
						if(size==6)
							pairs[4]+=4*per[4];
						if(size==7)
							pairs[4]+=8*per[4];
						if(size==8)
							pairs[4]+=16*per[4];
						pairs[4]%=mod;
				   }
			   }
			}
		}
		//five pair
		for(i=0;i<m-4;i++)
		{
			for(j=i+1;j<m-3;j++)
			{
				for(k=j+1;k<m-2;k++)
				{
					for(int l=k+1;l<m-1;l++)
					{
						for(int ll=l+1;ll<m;ll++)
						{
							int size=10;
							int aa[15]; aa[8]=c[ll];aa[9]=d[ll];aa[0]=c[i];aa[1]=d[i];aa[2]=c[j];aa[3]=d[j];aa[4]=c[k];aa[5]=d[k];aa[6]=c[l];aa[7]=d[l];
							int a[100000];
							for(int o=0;o<100000;o++)
								a[o]=1;
							for(int ii=0;ii<9;ii++)
							{
								int kc=0;
								for(int jj=ii+1;jj<10;jj++)
								{
									if(aa[ii]==aa[jj])
									{
										size--;
										a[aa[ii]]++;
										kc++;
							    	}
								}
								if(kc>=2)
								{
									size=0;
									break;
								}
							}
							if(size!=0)
							{
								int yyy=check(10,aa,a);
								if(yyy!=size)
									size=0;
							}
							if(size==6)
								pairs[5]+=2*per[5];
							if(size==7)
								pairs[5]+=4*per[5];
							if(size==8)
								pairs[5]+=8*per[5];
							if(size==9)
								pairs[5]+=16*per[5];
							if(size==10)
								pairs[5]+=32*per[5];
							pairs[5]%=mod;
					   }
					}	
				}
			}
		}
		//six pair
		for(i=0;i<m-5;i++)
		{
			for(j=i+1;j<m-4;j++)
			{
				for(k=j+1;k<m-3;k++)
				{
					for(int l=k+1;l<m-2;l++)
					{
						for(int ll=l+1;ll<m-1;ll++)
						{
							for(int kk=ll+1;kk<m;kk++)
							{
								int size=12;
								int aa[15]; 
								aa[8]=c[ll];aa[9]=d[ll];aa[10]=c[kk];aa[11]=d[kk];aa[0]=c[i];aa[1]=d[i];aa[2]=c[j];aa[3]=d[j];aa[4]=c[k];aa[5]=d[k];aa[6]=c[l];aa[7]=d[l];
								int a[100000];
								for(int o=0;o<100000;o++)
									a[o]=1;
								for(int ii=0;ii<11;ii++)
								{
									int kc=0;
									for(int jj=ii+1;jj<12;jj++)
									{
										if(aa[ii]==aa[jj])
										{
											size--;
											a[aa[ii]]++;
											kc++;
										}
									}
									if(kc>=2)
									{
										size=0;
										break;
									}
								}
								if(size!=0)
								{
									int yyy=check(12,aa,a);
									if(yyy!=size)
										size=0;
								}
								if(size==7)
									pairs[6]+=2*per[6];
								if(size==8)
									pairs[6]+=4*per[6];
								if(size==9)
									pairs[6]+=8*per[6];
								if(size==10)
									pairs[6]+=16*per[6];
								if(size==11)
									pairs[6]+=32*per[6];
								if(size==12)
									pairs[6]+=64*per[6];
								pairs[6]%=mod;
						   }
					   }
					}
				}
			}		
		}
		//seven pair
		for(i=0;i<m-6;i++)
		{
			for(j=i+1;j<m-5;j++)
			{
				for(k=j+1;k<m-4;k++)
				{
					for(int l=k+1;l<m-3;l++)
					{
						for(int ll=l+1;ll<m-2;ll++)
						{
							for(int kk=ll+1;kk<m-1;kk++)
							{
								for(int kkk=kk+1;kkk<m;kkk++)
								{
									int size=14;
									int aa[15]; aa[12]=c[kkk];aa[13]=d[kkk];aa[8]=c[ll];aa[9]=d[ll];aa[10]=c[kk];aa[11]=d[kk];aa[0]=c[i];aa[1]=d[i];aa[2]=c[j];aa[3]=d[j];aa[4]=c[k];aa[5]=d[k];aa[6]=c[l];aa[7]=d[l];
									int a[100000];
									for(int o=0;o<100000;o++)
										a[o]=1;
									for(int ii=0;ii<13;ii++)
									{
										int kc=0;
										for(int jj=ii+1;jj<14;jj++)
										{
											if(aa[ii]==aa[jj])
											{
												size--;
												a[aa[ii]]++;
												kc++;
											}
										}
										if(kc>=2)
										{
											size=0;
											break;
										}
									}
									if(size!=0)
									{
										int yyy=check(14,aa,a);
										if(yyy!=size)
											size=0;
									}	
									if(size==8)
										pairs[7]+=2*per[7];
									if(size==9)
										pairs[7]+=4*per[7];
									if(size==10)
										pairs[7]+=8*per[7];
									if(size==11)
										pairs[7]+=16*per[7];
									if(size==12)
										pairs[7]+=32*per[7];
									if(size==13)
										pairs[7]+=64*per[7];
									if(size==14)
										pairs[7]+=128*per[7];
									pairs[7]%=mod;
							   }			
						   }
						}
					}
				}
			}	
		}
		long long int ans=per[0]-pairs[1]+pairs[2]-pairs[3]+pairs[4]-pairs[5]+pairs[6]-pairs[7];
		ans%=mod;
		if(ans<0)
			ans+=mod;
		cout<<ans<<endl;
	}
	return 0;
}
