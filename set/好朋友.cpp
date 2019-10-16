#include<iostream>
using namespace std;

const int maxsize=100;
int set[maxsize],N,M;
bool isRoot[maxsize];

int find(int x)
{
	while(x!=set[x])
		x=set[x];
	return x;
}

void Unint(int x,int y)
{
	int faA=find(x);
	int faB=find(y);
	if(faA!=faB)
		set[faA]=faB;
}

int main()
{
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		set[i]=i;
		isRoot[i]=false;
	}
	for(int i=0;i<m;++i){
		scanf("%d%d",&a,&b);
		Unint(a,b);
	}
	for(int i=1;i<=n;++i)
		isRoot[find(i)]=true;
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		if(isRoot[i]) ++ans;
	}
	printf("%d",ans);
	return 0;
} 
