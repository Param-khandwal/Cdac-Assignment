
//Given a matrix A of size m x n, write a function that returns the sum of elements below
//the main diagonal, i.e those elements a ij for which i>j

// 1 2 3
// 1 2 3         i will sum below the daigonal element 1+2+2=5
// 2 2 3

#include<stdio.h>

int matrix(int m , int n, int arr[m][n]){
int total=0;
for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
	if(i>j)
	total+=arr[i][j];
	}
    }
 return total;
}
int main(){

int m=3,n=3;
int arr[3][3]={{1,2,3},{1,2,3},{2,2,3}};
printf("matrix %d  \n",matrix( m,n,arr));


}





/*
#include<stdio.h>
int matrix(int m , int n, int arr[m][n]){
int total=0;
for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
	if(i>j)
	total+=arr[i][j];
	}
    }
 return total;
}
int main(){

int m=3,n=3;
int arr[3][3]={{1,2,3},{1,2,3},{2,2,3}};
printf("matrix %d  \n",matrix( m,n,arr));


}

*/




