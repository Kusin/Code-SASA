//2020.01.22 Kyungmo Ku
#include<iostream> //Build Heap 의 Time complexity :https://www.geeksforgeeks.org/time-complexity-of-building-a-heap/ 
using namespace std;
class Heap{
	private:
		int n,m,arr[100010];
		int size;
	public:
		inline void swap(int a,int b){
			arr[a]^=arr[b]^=arr[a]^=arr[b];
		}
		int del();
		void downheap(int );
		void makeheap();
		void heapsort();
		Heap(){
			scanf("%d",&n);
			size=n; m=n; 
			for(int i=1;i<=n;i++)
				scanf("%d",arr+i);
			makeheap();
		}
		void showHeap(){
			for(int i=1;i<=n;i++)
				cout<<arr[i]<<'\n';
		}
};
void Heap::downheap(int k){
	int child;
	while(2*k<=size){
		child=2*k;
		if(child<size && arr[child] < arr[child+1]) //더  큰 자식노드를 찾는다. 
			child++;
		if(arr[k] >= arr[child])
			break;
		swap(k,child);
		k=child;																											
	}
}
void Heap::makeheap(){
	for(int i=n/2;i>=1;i--){
		downheap(i);
	}
}
int Heap::del(){
	int v=arr[1];
	arr[1] = arr[size--];
	downheap(1);
	return v;
}
void Heap::heapsort(){
	for(int i=n;i>n-m;i--){
		arr[i]=del();
	}
}
int main(){
	Heap hp;
	hp.heapsort();
	hp.showHeap();
}
