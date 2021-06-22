#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N,V;
	vector<int> W(N+1,0);
	vector<int> C(N+1,0);
	cin>>N>>V;
	for(int i=1;i<=N;++i){
		cin>>W[i];
	}
	for(int i=1;i<=N;++i){
		cin>>C[i];
	}
	vector<vector<int> > dp(N+1,vector<int>(V+1,0));
	for(int i=1;i<=N;++i){
		for(int j=W[i];j<=V;++j){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-W[i]]+C[i]);
		}
	} 
	
	cout<<dp[N][V]<<endl;
	//´òÓ¡dpÊý×é 
	for(int i=0;i<=N;++i)
	{
		for(int j=0;j<=V;++j)
		{
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}
} 
