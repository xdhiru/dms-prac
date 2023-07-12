# include <conio.h>
# include <iostream>
using namespace std;
void perm(int A[] , int n , int b ){
	if(b==n-1){
		for (int j = 0 ; j<n ; j++){
			cout<<A[j];
			
		}cout<<"\n";
	}
	else{
		for (int i=b;i<n;i++){
			swap(A[b],A[i]);
			perm(A,n,b+1);
			swap (A[b],A[i]);
		}
	}
}
void perm_rep(int A[],int B[],int n ,int b){
	if(b==n){
		for(int j=0 ; j<n ; j++){
			cout<<B[j];
			
		}cout<<"\n";
	}
	else{
		for(int i =0;i<n;i++){
			B[b]=A[i];
			perm_rep(A,B,n,b+1);
		}
	}
}
int main()
{
	static int n;
	int A[n];
	int B[n];                                                    
	int b=0;
	int ch;
	cout<<"enter the no of elements";
	cin>>n;
	cout<<"enter the elements";
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	cout<<endl;
	cout<<"1. permutation without repeatition";
	cout<<endl;
	cout<<"2. permutation  with repeatition";
	cout<<endl;
	cout<<"enter your choice";
	cin>>ch;
	cout<<endl;
	switch(ch)
	{
		case 1 : perm(A,n,b);
		   break;
		case 2 : perm_rep(A,B,n,b);
		   break;
		default : 
		cout<<"invalid input";  
	};
	cin.get();
	return 0; 
	}