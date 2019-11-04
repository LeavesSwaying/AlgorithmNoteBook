#include<cstdio>
#include<cmath>
const int maxn=11;

int n,P[maxn],hashTable[maxn]={false};
int count=0; 

void generateP(int index)
{
	if(index==n+1)
	{
		bool flag=true;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;j++)
				if(abs(i-j)==abs(P[i]-P[j]))
					flag=false;
		if(flag) ++count;
		return;
	}
	for(int x=1;x<=n;++x)
	{
		if(hashTable[x]==false){
			P[index]=x;
			hashTable[x]=true;
			generateP(index+1);
			hashTable[x]=false;
		}
	}
}

void generatePC(int index)
{
	if(index==n+1){
		++count;
		return;
	}
	for(int x=1;x<=n;++x)
	{
		if(hashTable[x]==false){
			bool flag=true;
			for(int pre=1;pre<index;++pre)
			{
				if(abs(index-pre)==abs(x-P[pre])){
					flag=false;
					break;
				}
			}
			if(flag){
				P[index]=x;
				hashTable[x]=true;
				generatePC(index+1);
				hashTable[x]=false;
			}
		}
	}
}

int main()
{
	n=8;
	generatePC(1);
	printf("%d",count);
	return 0;	
} 
