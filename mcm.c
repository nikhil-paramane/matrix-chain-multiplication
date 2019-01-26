/*********************************************************************************
	Assignment: Sub: Design And Analysis of Algorithm							 *
																				 *
	Program Name: Matrix Chain Multiplication									 *
	Coders: 1: Name: Nikhil S. Paramane.											 *
				Roll Number: 16220												 *
			2: Vishal Kangane													 *
				Roll Number: 16213	 											 *
				M.Sc.(IMCA-1)													 *
*********************************************************************************/
#include <stdio.h>
#include<stdlib.h>


int **keys; //TO store minimum value indexses of weights
char ch='A'; //Names of matrices

long int mij(long int **weights,int *p, int num_matrices, int n, int m){//Gives minimum no of multiplication
	int k;
	long int temp=0;
	for(k=n; k<m; k++){
		if(temp==0){
			temp=weights[n][k]+weights[k+1][m]+(p[n]*p[k+1]*p[m+1]);
			keys[n][m]=k;
		}else if(temp>(weights[n][k]+weights[k+1][m]+(p[n]*p[k+1]*p[m+1]))){
				temp=weights[n][k]+weights[k+1][m]+(p[n]*p[k+1]*p[m+1]);
				keys[n][m]=k;
		}//end of else if
	}//end of i for
	//printf("weights[%d][%d]: %ld  key:%d\n",n,m,temp,keys[n][k]);
	return temp;
}//end of mij function	

void printorder(int **keys,int num_matrices,int i, int j){//printing parenthesis according to mij
	if(i==j){//if only one matrix
		printf("%c",ch++);
		return;
	}//end of if
	printf("(");
	printorder(keys,num_matrices,i,keys[i][j]);//Recursive call 1
	
	printorder(keys,num_matrices,keys[i][j]+1,j);//Recursive call 2
	printf(")");
}//end of printorder function

int main(){
	int num_matrices,i=0,j=0,k,num_keys;
	printf("How many Matrices: ");
	scanf("%d",&num_matrices);
	while(num_matrices<0){//
		printf("Please Enter Positive Number :");
		scanf("%d",&num_matrices);	
	}
	if(num_matrices==0){
		return 0;
	}
	long int ** weights; //storing no of multiplications
	
	weights=(long int **)malloc(sizeof(long int *)*num_matrices);
	if(weights==NULL){
		printf("Memory Allocation Failed\n");
		exit(0);
	}//end of if
	for(i=0; i<num_matrices; i++){
		weights[i]=(long int *)malloc(sizeof(long int)*num_matrices);
		if((weights+i)==NULL){
			printf("Memory Allocation Failed\n");
			exit(0);
		}
		weights[i][i]=0;
	}//end of i for;
	
	int *p;
	p=(int *)malloc(sizeof(int)*num_matrices+1);
	
	if(p==NULL){
		printf("Memory Allocation Failed\n");
		exit(0);
	}
	
	keys=(int **)malloc(sizeof(int*)*num_matrices);
	if(keys==NULL){
		printf("Memory Allocation Failed\n");
		exit(0);
	}
	for(i=0; i<num_matrices; i++){
		keys[i]=(int *)malloc(sizeof(int)*num_matrices);
		if(keys[i]==NULL){
			printf("Memory Allocation Failed\n");
			exit(0);	
		}//end of if
	}//end of i for
	printf("\nEnter: ");
	
	printf("\nNumber of Rows for Matrix 1 : ");
	scanf("%d",&p[0]);
	for(i=0; i<num_matrices; i++){
		printf("\nNumber of Columns for %d Matrix: ",i+1);
		scanf("%d",&p[i+1]);
	}//end of i for;
	k=0;
	int l;
	//mij(weights, d1, p, num_matrices, 0, 1);
	for(l=0; l<num_matrices-1; l++){	
		for(i=0; i<num_matrices-l-1; i++){
			weights[i][k+1]=mij(weights, p, num_matrices, i,k+1);
			k++;
			if(k==(num_matrices-1)){
					k=l+1;
				}//end of if
				
		}//end of i for
	}//end of l for
	printf("\n\nMinimum Number of Multiplications: %ld\n\n",weights[0][num_matrices-1]);
	printf("Multiplication Order: ");
	printorder(keys,num_matrices,0, num_matrices-1); //printing
	return 0;
	
}//end of main;
