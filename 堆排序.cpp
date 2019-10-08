#include<iostream>
using namespace std;

const int MaxSize=100;
int A[MaxSize],N;

void swap(int i,int j)
{
	int temp=A[i];
	A[i]=A[j];
	A[j]=temp;
} 

void downAdjust(int low,int high)
{
	int temp;
	int i=low,j=2*i;
	while(j<=high){
		if(j+1<=high&&A[j+1]>A[j])
			j=j+1;
		if(A[i]<A[j]){
			swap(i,j);
			i=j;
			j=2*i;
		}
		else break;
	}
}

void heapSort()
{
	for(int i=N/2;i>=1;--i)
		downAdjust(i,N);
	for(int i=N;i>1;--i){
		swap(1,i);
		downAdjust(1,i-1);
	}
}

int main()
{
	cin>>N;
	for(int i=1;i<=N;++i)
		cin>>A[i];
	heapSort();
	for(int i=1;i<N;++i)
		cout<<A[i]<<' ';
	cout<<A[N];
	return 0;	
} 
