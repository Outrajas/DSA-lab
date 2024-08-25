#include <iostream>
using namespace std;

//Function to check greater number:
int max(int m, int n){return (m>n) ? m : n;}

//Function to add 2 polynomials:
int* add(int A[] , int B[] , int m , int n){
	int size = max(m,n);
	int* sum = new int[size];
	for (int i=0 ; i<m ; i++){
		sum[i] = A[i];
	}
	for (int i=0 ; i<n ; i++){
		sum[i] += B[i];
	}
	
	return sum;
}

void print_poly(int poly[] , int n){
	for (int i=0 ; i<n ; i++){
		cout<<poly[i];
		if(i!=0){
			cout<<"x^"<<i;
		}
		if(i!=n-1){
			cout<<"+";
		}
	}
}

int main(){
	int A[] = {5,0,10,6};
	int B[] = {1,2,4};
	int m = sizeof(A)/sizeof(A[0]);
	int n = sizeof(B)/sizeof(B[0]);
	cout<<"First Polynomial is:"<<endl;
	print_poly(A,m);
	cout<<"\nSecond Polynomial is:"<<endl;
	print_poly(B,n);
	
	int* sum = add(A,B,m,n);
	int size = max(m,n);
	
	cout<<"\nSum of polynomials is:\n";
	print_poly(sum,size);
	
	
	
	
	return (0);
}


