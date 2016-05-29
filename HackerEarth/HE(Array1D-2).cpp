#include "stdio.h"
#include "iostream"
using namespace std;
int arr[100001];int T;
int main(int argc, char const *argv[])
{
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		for(int i=0;i<N;++i)
		{
			cin>>arr[i];
		}
		int min,count;
		min=0x7fffffff;
		count=0;
		for(int i=0;i<N;++i)
		{
			if(arr[i]<=min)
			{
				min=arr[i];
				++count;
			}

		}
		cout<<count<<endl;
	}
	return 0;
}