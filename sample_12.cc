/* This program is just an exercise in memory management:what not to do to overload your program
 */

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdio.h>      /* printf */
#include <math.h>
#include"/home/soundap9/Documents/Bush_Hadamard/make_Bush_matrices.cc"
using namespace std;

//Four circulant matrices of order 3.
int** circulant1 = new int*[3];
int** circulant2 = new int*[3];
int** circulant3 = new int*[3];
int** circulant4 = new int*[3];



//Produces the Kronecker product of circulant matrix and random matrix a.
int** new_constr(int** circulant,int order_circ, int** a,int order_a);
const int n = 4;
//auxillary function to calculate minimum number of zeroes in a row in a matrix. 
bool count_zeroes(int** Had);

//Generates a 3-block diagonal permuation matrix depending on the parameters.
int** block_diagonal_perm(int index_a,int index_b, int index_c, int k);

// Generates a random permutation matrix of order 4 based on an index that can vary between 0 and 23.
int** generate_perm_4(int index);

//Generates a random permutation matrix of order 12 with the three permutation matrices of order 4 on its block diagonal.
int** random_perm_matrix(int** a, int** b, int** c);

int** a;
int** b;
int** c;
int** d;
int main()
{
	
	int circ1[3][3] ={{1,1,-1},{-1,1,1},{1,-1,1}};
	int circ2[3][3] ={{-1,1,-1},{-1,-1,1},{1,-1,-1}};
	int circ3[3][3] ={{1,1,1},{1,1,1},{1,1,1}};
	int circ4[3][3] ={{1,-1,-1},{-1,1,-1},{-1,-1,1}};
	int a_source[n][n]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
	int b_source[n][n]={{0,1,0,0},{-1,0,0,0},{0,0,0,-1},{0,0,1,0}};
	int c_source[n][n]={{0,0,1,0},{0,0,0,1},{-1,0,0,0},{0,-1,0,0}};
	int d_source[n][n]={{0,0,0,1},{0,0,-1,0},{0,1,0,0},{-1,0,0,0}};

	circulant1 = initialize_matrix(&circ1[0][0],3,3);
	circulant2 = initialize_matrix(&circ2[0][0],3,3);
	circulant3 = initialize_matrix(&circ3[0][0],3,3);
	circulant4 = initialize_matrix(&circ4[0][0],3,3);
	a = initialize_matrix(&a_source[0][0],n,n);
	b = initialize_matrix(&b_source[0][0],n,n);
	c = initialize_matrix(&c_source[0][0],n,n);
	d = initialize_matrix(&d_source[0][0],n,n);

	int** matrix;
	int** matrix1;
	int** matrix2;	
	matrix = new_constr(circulant3,3,a,4);
	matrix = Add(matrix,new_constr(circulant2,3,b,4),3*n,3*n);
	matrix = Add(matrix,new_constr(circulant2,3,c,4),3*n,3*n);
	matrix = Add(matrix,new_constr(circulant2,3,d,4),3*n,3*n);
	matrix1 = matrix;
	/*
	int perm_array1[12] ={3,2,1,0,7,6,5,4,11,10,9,8};
	matrix1 = matrix_multiplication(permutation(perm_array1,12,1),matrix1,12);
	print(matrix1,3*n);
	cout<<"__________________"<<endl;
	cout<<(check_Hadamard(matrix1,3*n))<<endl;
	*/

	int perm_array2[12] = {3,2,1,0,7,6,5,4,11,10,9,8};
	matrix = new_constr(circulant3,3,a,4);
        matrix = Add(matrix,new_constr(circulant1,3,b,4),3*n,3*n);
        matrix = Add(matrix,new_constr(circulant1,3,c,4),3*n,3*n);
        matrix = Add(matrix,new_constr(circulant1,3,d,4),3*n,3*n);
        matrix2 = matrix;
	//print(matrix1,12);
	cout<<"______________________"<<endl;
	//print(matrix2,12);
	/*
	matrix2 = matrix_multiplication(matrix2, permutation(perm_array2,12,2),12);
	print(matrix2,3*n);
	cout<<"_________________"<<endl;
        cout<<(check_Hadamard(matrix2,3*n))<<endl;
	*/

	// This part of the program permutes matrix1 and matrix2 in permissible ways(eg, permuting a column block/row block, but not across column blocks)
	// and checks if their Hadamard product is Hadamard or not. The outer loop permutes matrix1 and the inner loop permutes matrix2.
	
	/*
	int** perm1;
	int** perm2;
	int** matrix1_new;
	int** matrix2_new;
	int** Had;
	bool zero;
	int count=0;
	polynomial** p;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				perm1 = block_diagonal_perm(i,j,k,2);
				matrix1_new = matrix_multiplication(perm1,matrix1,12);
				for(int l=0;l<4;l++)
				{
					for(int m=0;m<4;m++)
					{
						for(int n=0;n<4;n++)
						{
							perm2 = block_diagonal_perm(l,m,n,2);
							matrix2_new = matrix_multiplication(matrix2,perm2,12);
							Had = Hadamard_product(matrix1_new,matrix2_new,12);
							//cout<<check_Hadamard(Had,12);
							zero = count_zeroes(matrix_multiplication(Had,Trans(Had,12),12));
							if(zero==true)
							{
								p = make_GH_from_H(matrix1_new, matrix2_new, 12, 2);
								//print_p(p,12);		
							cout<<"\\\\ Matrix  "<<count<<"\\\\"<<endl;	
								cout<<"$P_1 = "<<endl;					
								cout<<"\\left("<<endl;
								cout<<"\\begin{array}{cccccccccccc}"<<endl;
								print(perm1,12);
								cout<<"\\end{array}"<<endl;
								cout<<"\\right)"<<endl;
								cout<<"$"<<endl;
								
								cout<<"$P_2 ="<<endl;                                   
                                                                cout<<"\\left("<<endl;
                                                                cout<<"\\begin{array}{cccccccccccc}"<<endl;      
								print(perm2,12);
								cout<<"\\end{array}"<<endl;
                                                                cout<<"\\right)"<<endl;
                                                                cout<<"$"<<endl;

								cout<<"$HH^{t} = "<<endl;
								cout<<"\\left("<<endl;
                                                                cout<<"\\begin{array}{cccccccccccc}"<<endl;
								print(matrix_multiplication(Had,Trans(Had,12),12),12);
								cout<<"\\end{array}"<<endl;
                                                                cout<<"\\right)"<<endl;
                                                                cout<<"$"<<endl;

								count++;
							}
							
						}
					}
				}
			}
		}
	}
	*/
	//cout<<count<<endl;





	/*
	cout<<check_Hadamard(Hadamard_product(matrix1,matrix2,3*n),3*n)<<endl;
	int** Had;
	Had = Hadamard_product(matrix1,matrix2,3*n);
	print(matrix_multiplication(Had,Trans(Had,12),12),12);
*/

		//Adding code to accomodate all types of block diagonal permutation matrices and not just those of the IxR type.
		int** perm11;
		int** perm12;
		int** perm13;
		int** perm21;
		int** perm22;
		int** perm23;
		int** permutation_matrix_1;
		int** permutation_matrix_2;
		bool cz;
		int** Had;
		int** HHt;
		int** matrix_new_1;
		int** matrix_new_2;
		polynomial** GH;
		int count=0;

		for(int i=0;i<24;i++)
		{
			for(int j=0;j<24;j++)
			{
				for(int k=0;k<24;k++)
				{
					perm11 = generate_perm_4(i);
					perm12 = generate_perm_4(j);
					perm13 = generate_perm_4(k);
					permutation_matrix_1 = random_perm_matrix(perm11,perm12,perm13);
					matrix_new_1 = matrix_multiplication(permutation_matrix_1,matrix1,12);
					for(int l=0;l<24;l++)
					{
						for(int m=0;m<24;m++)
						{
							for(int p=0;p<24;p++)
							{
								perm21 = generate_perm_4(l);
								perm22 = generate_perm_4(m);
								perm23 = generate_perm_4(p);
								permutation_matrix_2 = random_perm_matrix(perm21,perm22,perm23);
								matrix_new_2 = matrix_multiplication(matrix2,permutation_matrix_2,12);
								Had = Hadamard_product(matrix_new_1,matrix_new_2,12);
								HHt = matrix_multiplication(Had,Trans(Had,12),12);
								cz  = count_zeroes(HHt);
								if(cz==true)
								{
									//cout<<"$P1 ="<<endl;
        	                                                        //cout<<"\\left("<<endl;
	                                                                //cout<<"\\begin{array}{cccccccccccc}"<<endl;
       									print(permutation_matrix_1,12);
									//cout<<"\\end{array}"<<endl;
                                	                                //cout<<"\\right)"<<endl;
                                        	                        //cout<<"$"<<endl;
									//cout<<","<<endl<<endl;

									//cout<<"$P2 ="<<endl;
                                                                        //cout<<"\\left("<<endl;
                                                                        //cout<<"\\begin{array}{cccccccccccc}"<<endl;
                                                                        print(permutation_matrix_2,12);
									//cout<<"\\end{array}"<<endl;
                                                                        //cout<<"\\right)"<<endl;
                                                                        //cout<<"$"<<endl;
									//cout<<","<<endl<<endl;

									//cout<<"$H ="<<endl;
                                                                        //cout<<"\\left("<<endl;
                                                                        //cout<<"\\begin{array}{cccccccccccc}"<<endl;
                                                                        print(Had,12);
                                                                        //cout<<"\\end{array}"<<endl;
                                                                        //cout<<"\\right)"<<endl;
                                                                        //cout<<"$"<<endl;
									//cout<<","<<endl<<endl;
									
									GH = make_GH_from_H(matrix_new_1, matrix_new_2,12,2);
									
									//cout<<"$GH ="<<endl;
                                                                        //cout<<"\\left("<<endl;
                                                                        //cout<<"\\begin{array}{cccccccccccc}"<<endl;
                                                                        //print_p(GH,12);
									//cout<<"\\end{array}"<<endl;
                                                                        //cout<<"\\right)"<<endl;
                                                                        //cout<<"$"<<endl;
									cout<<"-------------------------------------------"<<endl;	
									
									
									//cout<<"Matrix 1"<<endl;
									//cout<<check_Hadamard(matrix_multiplication(permutation_matrix_1,matrix1,12),12)<<endl;
									//cout<<"Matrix 2"<<endl;
									//cout<<check_Hadamard(matrix_multiplication(matrix2,permutation_matrix_2,12),12)<<endl;
									//cout<<"______________________________"<<endl;
									

								}
									for(int v1=0;v1<4;v1++)
									{
										delete (perm21[v1]);perm21[v1]=NULL;
										delete (perm22[v1]);perm22[v1]=NULL;
										delete (perm23[v1]);perm23[v1]=NULL;
									}
									for(int v2=0;v2<12;v2++)
									{
										delete (permutation_matrix_2[v2]);permutation_matrix_2[v2]=NULL;
										delete (matrix_new_2[v2]);matrix_new_2[v2]=NULL;
										delete (Had[v2]); Had[v2]=NULL;
										delete (HHt[v2]); HHt[v2]=NULL;
										// Deleting global variables
										mult_matrix[v2] = NULL;
										Hadprod_matrix[v2] = NULL;
										delete (Trans_matrix[v2]); Trans_matrix[v2] = NULL;
										//if(cz==true)
										//	delete (GH[v2]); GH[v2]=NULL;

									}
							}
						}
					}
					for(int v3=0;v3<4;v3++)
					{
						delete (perm11[i]); perm11[i]=NULL;
						delete (perm12[i]); perm12[i]=NULL;
						delete (perm13[i]); perm13[i]=NULL;
					}
					for(int v4=0;v4<12;v4++)
					{
						delete (permutation_matrix_1[i]);permutation_matrix_1[i]=NULL;
						delete (matrix_new_1[v4]);matrix_new_1[v4]=NULL;
						mult_matrix[v4]=NULL;
					}
				}
			}
		}


				
	cout<<"Matrix 1 and Matrix 2"<<endl;	
	print(matrix1,12);
	cout<<"______________________"<<endl;
	print(matrix2,12);
	cout<<"_____________________"<<endl;
		return 0;
}

int** new_constr(int** circulant,int order_circ,int** a, int order_a)
{
	return(Kronecker(circulant,a,order_circ,order_a));
}

//Auxillary function to calculate minimum number of zeroes in a row in a matrix (delete if not needed)
//Returns true of the minimum is 10, i.e a maximum of 2 non zero entries in each row.
bool count_zeroes(int** Had)
{
	int min_count=12,count=0;
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
		{
			if(Had[i][j]==0)
			{
				count++;
			}
		}
		if(count<min_count)
			min_count=count;
		count=0;
	}
	if(min_count==11)
		return true;
	else
		return false;
}

int** generate_perm_4(int index)
{
	int** matrix = new int*[4];
for(int i=0;i<4;i++)
{
	matrix[i] = new int[4];
	for(int j=0;j<4;j++)
	{
		matrix[i][j]=0;
	}
}
int a = int(index/6);

int b = int(index - (a*6))/2;
int countb=0;;
int indexb=1;
int c = int(index - (a*6) - (b*2));
int countc =0;
int indexc =1;
int d=0;
int countd=0;
int indexd=1;
matrix[0][a] = 1;
while(countb<=b)
{
	if(matrix[0][(a+indexb)%4]==0)
	{
		countb++;
	}
	indexb++;
}
matrix[1][(a+indexb-1)%4]=1;
indexb = (a+indexb-1)%4;
while(countc<=c)
{
	if(matrix[1][(indexb+indexc)%4]==0 && matrix[0][(indexb+indexc)%4]==0)
	{
		countc++;
	}
	indexc++;
}
matrix[2][(indexb+indexc-1)%4]=1;
indexc = (indexb+indexc-1)%4;
while(countd<=d)
{
	if(matrix[2][(indexc+indexd)%4]==0 && matrix[1][(indexc+indexd)%4]==0 && matrix[0][(indexc+indexd)%4]==0)
	{
		countd++;
	}
	indexd++;
}
matrix[3][(indexd+indexc-1)%4]=1;
return matrix;
}

int** random_perm_matrix(int** a, int** b, int** c)
{
int** perm = new int*[12];
        //Create and initialize Permutation matrix to 0
        for(int i=0;i<12;i++)
        {
                perm[i]=new int[12];
                for(int j=0;j<12;j++)
                {
                        perm[i][j]=0;
                }
        }
        //Filling first diagonal block with IR(index_a)
        for(int i=0;i<4;i++)
        {
                for(int j=0;j<4;j++)
                {
                        perm[i][j]=a[i][j];
                }
        }
        //Filling second diagonal block with IR(index_b)
        for(int i=4;i<8;i++)
        {
                for(int j=4;j<8;j++)
                {
                        perm[i][j]=b[i-4][j-4];
                }
        }
        //Filling third diagonal block with IR(index_c)
        for(int i=8;i<12;i++)
        {
                for(int j=8;j<12;j++)
                {
                        perm[i][j]=c[i-8][j-8];
                }
        }
        return perm;
}
//This function returns a 3-block diagonal permutation matrix of order 12. The parameters determine the index of the IR matrix that is needed.
int** block_diagonal_perm(int index_a,int index_b, int index_c,int k)
{
	int** a = generate_IR(index_a,k);
	int** b = generate_IR(index_b,k);
	int** c = generate_IR(index_c,k);
	int** perm = new int*[12];
	//Create and initialize Permutation matrix to 0
	for(int i=0;i<12;i++)
	{
		perm[i]=new int[12];
		for(int j=0;j<12;j++)
		{
			perm[i][j]=0;
		}
	}
	//Filling first diagonal block with IR(index_a)
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			perm[i][j]=a[i][j];
		}
	}
	//Filling second diagonal block with IR(index_b)
	for(int i=4;i<8;i++)
	{
		for(int j=4;j<8;j++)
		{
			perm[i][j]=b[i-4][j-4];
		}
	}
	//Filling third diagonal block with IR(index_c)
	for(int i=8;i<12;i++)
	{
		for(int j=8;j<12;j++)
		{
			perm[i][j]=c[i-8][j-8];
		}
	}

	return perm;
}
