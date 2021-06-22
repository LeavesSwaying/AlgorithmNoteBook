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
	vector<int> dp(V+1,0);
	for(int i=1;i<=N;++i){
		for(int j=V;j>=W[i];--j){
			dp[j]=max(dp[j],dp[j-W[i]]+C[i]);
		}
	} 
	
	cout<<dp[V]<<endl;
	//´òÓ¡dpÊý×é 
	for(int i=0;i<=V;++i)
	{
		cout<<dp[i]<<' ';
	}
} 
