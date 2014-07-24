/*
 * I'm only including this program as an exercise in memory management and writing clean codes:what not to do.
 * */


#include <iostream>
#include <cmath>
#include<math.h>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdio.h>      /* printf */
#include <math.h>
#include"/home/soundap9/Documents/Bush_Hadamard/mathad01_make_Bush_matrices.cc"
using namespace std;


//Produces the Kronecker product of circulant matrix and random matrix a.
int** new_constr(int** circulant,int order_circ, int** a,int order_a);
//auxillary function to calculate minimum number of zeroes in a row in a matrix. 
bool count_zeroes(int** Had);

//Generates a 3-block diagonal permuation matrix depending on the parameters.
int** block_diagonal_perm(int index_a,int index_b, int index_c,int index_d, int index_e, int k);

// Generates a random permutation matrix of order 4 based on an index that can vary between 0 and 23.
int** generate_perm_4(int index);

//Generates a random permutation matrix of order 12 with the three permutation matrices of order 4 on its block diagonal.
int** random_perm_matrix(int** a, int** b, int** c,int** d,int** e);

int** a;
int** b;
int** c;
int** d;
int main()
{

        int** Williamson1;
	int** Williamson2;
	int** Williamson3;
	int** Williamson4;
	int Will_1[5][5]={{-1,1,1,1,1},{1,-1,1,1,1},{1,1,-1,1,1},{1,1,1,-1,1},{1,1,1,1,-1}};
	int Will_2[5][5]={{-1,1,1,1,1},{1,-1,1,1,1},{1,1,-1,1,1},{1,1,1,-1,1},{1,1,1,1,-1}};
	int Will_3[5][5]={{1,1,-1,-1,1},{1,1,1,-1,-1},{-1,1,1,1,-1},{-1,-1,1,1,1},{1,-1,-1,1,1}};
	int Will_4[5][5]={{1,-1,1,1,-1},{-1,1,-1,1,1},{1,-1,1,-1,1},{1,1,-1,1,-1},{-1,1,1,-1,1}};
	int a_source[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
        int b_source[4][4]={{0,1,0,0},{-1,0,0,0},{0,0,0,-1},{0,0,1,0}};
        int c_source[4][4]={{0,0,1,0},{0,0,0,1},{-1,0,0,0},{0,-1,0,0}};
        int d_source[4][4]={{0,0,0,1},{0,0,-1,0},{0,1,0,0},{-1,0,0,0}};

	Williamson1 = initialize_matrix(&Will_1[0][0],5,5);
        Williamson2 = initialize_matrix(&Will_2[0][0],5,5);
        Williamson3 = initialize_matrix(&Will_3[0][0],5,5);
        Williamson4 = initialize_matrix(&Will_4[0][0],5,5);
        a = initialize_matrix(&a_source[0][0],4,4);
        b = initialize_matrix(&b_source[0][0],4,4);
        c = initialize_matrix(&c_source[0][0],4,4);
        d = initialize_matrix(&d_source[0][0],4,4);

        int** matrix;
        int** matrix1;
        int** matrix2;
        matrix = Kronecker(Williamson1,a,5,4);
        matrix = Add(matrix,Kronecker(Williamson2,b,5,4),20,20);
        matrix = Add(matrix,Kronecker(Williamson3,c,5,4),20,20);
        matrix = Add(matrix,Kronecker(Williamson4,d,5,4),20,20);
        matrix1 = matrix;
        
	matrix = Kronecker(Williamson1,a,5,4);
        matrix = Add(matrix,Kronecker(Williamson2,b,5,4),20,20);
        matrix = Add(matrix,Kronecker(Williamson3,c,5,4),20,20);
        matrix = Add(matrix,Kronecker(Williamson4,d,5,4),20,20);
        matrix2 = matrix;
       
        
        // This part of the program permutes matrix1 and matrix2 in permissible ways(eg, permuting a column block/row block, but not across column blocks)
        // and checks if their Hadamard product is Hadamard or not. The outer loop permutes matrix1 and the inner loop permutes matrix2.
        int** perm1;
        int** perm2;
        int** matrix1_new;
        int** matrix2_new;
 int** Had;
        bool zero;
        int count=0;
        polynomial** p;
 //Adding code to accomodate all types of block diagonal permutation matrices and not just those of the IxR type.
                int** perm11;
                int** perm12;
                int** perm13;
                int** perm14;
		int** perm15;
		int** perm21;
                int** perm22;
                int** perm23;
		int** perm24;
		int** perm25;
                int** permutation_matrix_1;
                int** permutation_matrix_2;
                bool cz;
                int** Had_Had_t;
                int** matrix_new_1;
                int** matrix_new_2;
                polynomial** GH;

                for(int i=0;i<24;i++)
                {
                        cout<<"i ="<<i<<endl;
			for(int j=0;j<24;j++)
                        {
                                for(int k=0;k<24;k++)
                                {
					for(int l=0;l<24;l++)
					{
						for(int m=10;m<24;m++)
						{
                                        		perm11 = generate_perm_4(i);
                                        		perm12 = generate_perm_4(j);
                                        		perm13 = generate_perm_4(k);
                                        		perm14 = generate_perm_4(l);
							perm15 = generate_perm_4(m);
							permutation_matrix_1 = random_perm_matrix(perm11,perm12,perm13,perm14,perm15);
                                        		for(int n=0;n<24;n++)
                                        		{
                                                		cout<<"n="<<n<<endl;
								for(int p=0;p<24;p++)
                                                		{
                                                        		for(int q=0;q<24;q++)
                                                        		{
                                                                		for(int r=0;r<24;r++)
										{
											for(int s=0;s<24;s++)
											{
											perm21 = generate_perm_4(n);
                                                                			perm22 = generate_perm_4(p);
                                                                			perm23 = generate_perm_4(q);
											perm24 = generate_perm_4(r);
											perm25 = generate_perm_4(s);
                                                                			permutation_matrix_2 = random_perm_matrix(perm21,perm22,perm23,perm24,perm25);

											matrix_new_1 = matrix_multiplication(permutation_matrix_1,matrix1,20);
                                                                			matrix_new_2 = matrix_multiplication(matrix2,permutation_matrix_2,20);
											Had = Hadamard_product(matrix_new_1,matrix_new_2,20);
                                                                			Had_Had_t = matrix_multiplication(Had,Trans(Had,20),20);
                                                                			//print(Had_Had_t,20);	
											if(count_zeroes(Had_Had_t)==true)
											{
												print(Had_Had_t,20);                                                                      
                                                                			}
                                                                			for(int i=0;i<4;i++)
											{
												
											free(perm11[i]); free(perm12[i]); free(perm13[i]); free(perm14[i]); free(perm15[i]);
											free(perm21[i]); free(perm22[i]); free(perm23[i]); free(perm24[i]); free(perm25[i]);
										perm11[i]=NULL;perm12[i]=NULL;perm13[i]=NULL;perm14[i]=NULL;perm15[i]=NULL;
									perm21[i]=NULL;perm12[i]=NULL;perm13[i]=NULL;perm14[i]=NULL;perm15[i]=NULL;	
											}
											for(int i=0;i<20;i++)
											{
                                                                				free(permutation_matrix_2[i]);
												permutation_matrix_2[i] = NULL;
												free(Had[i]);
												Had[i]=NULL;
												free(Had_Had_t[i]);
												Had_Had_t[i]=NULL;
												free(matrix_new_1[i]);
												matrix_new_1[i] =NULL;
												free(matrix_new_2[i]);
												matrix_new_2[i]=NULL;
											}
											//free[] permutation_matrix_1;
											//free[] permutation_matrix_2;
											//free[] Had;
											//free[] Had_Had_t;
											//free[] matrix_new_1;
											//free[] matrix_new_2;
											
											}
										}	
									}
								}
							}
							for(int i=0;i<20;i++)
							{
								free(permutation_matrix_1[i]);
								permutation_matrix_1[i] = NULL;
							}

                                                   }
                                          }
                                   }
			}
               }
                        
  
		/*
for(int i=0;i<4;i++)
        {
                for(int j=0;j<4;j++)
                {
                        for(int k=0;k<4;k++)
                        {
                                for(int p=0;p<4;p++)
                                {
                                        for(int q=0;q<4;q++)
                                        {
                                                permutation_matrix_1 = block_diagonal_perm(i,j,k,p,q,2);
                                                        for(int l=0;l<4;l++)
                                                        {
                                                                for(int m=0;m<4;m++)
                                                                {
                                                                        for(int n=0;n<4;n++)
                                                                        {
                                                                                for(int r=0;r<4;r++)
                                                                                {
                                                                                        for(int s=0;s<4;s++)
                                                                                        {
                                                                                        permutation_matrix_2 = block_diagonal_perm(l,m,n,r,s,2);
                                                                                        matrix_new_1 = matrix_multiplication(permutation_matrix_1,matrix1,20);
                                                                                        matrix_new_2 = matrix_multiplication(matrix2, permutation_matrix_2,20);
                                                                                        Had = Hadamard_product(matrix_new_1,matrix_new_2,20);
                                                                                        Had_Had_t = matrix_multiplication(Had,Trans(Had,20),20);
                                                                                        if(count_zeroes(Had_Had_t)==true)
                                                                                        {
                                                                                                print(Had_Had_t,20);
                                                                                        }
                                                                                        }
                                                                                }
                                                                        }
                                                                }

                                                }
                                        }
                                }
                        }
                }
        }
               */ 

        cout<<"Matrix 1 and Matrix 2"<<endl;
        print(matrix1,20);
        cout<<"______________________"<<endl;
        print(matrix2,20);
        cout<<"_____________________"<<endl;
                return 0;
}
bool count_zeroes(int** Had)
{
        int min_count=20,count=0;
        for(int i=0;i<20;i++)
        {
                for(int j=0;j<20;j++)
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
        if(min_count==15)
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
int** random_perm_matrix(int** a, int** b, int** c, int** d, int** e)
{
int** perm = new int*[20];
        //Create and initialize Permutation matrix to 0
        for(int i=0;i<20;i++)
        {
                perm[i]=new int[20];
                for(int j=0;j<20;j++)
                {
                        perm[i][j]=0;
                }
        }
        //Filling first diagonal block with a
        for(int i=0;i<4;i++)
        {
                for(int j=0;j<4;j++)
                {
                        perm[i][j]=a[i][j];
                }
        }
        //Filling second diagonal block with b
        for(int i=4;i<8;i++)
        {
                for(int j=4;j<8;j++)
                {
                        perm[i][j]=b[i-4][j-4];
                }
        }
        //Filling third diagonal block with c
        for(int i=8;i<12;i++)
        {
                for(int j=8;j<12;j++)
                {
                        perm[i][j]=c[i-8][j-8];
                }
        }
	//Filling the diagonal block with d
	for(int i=12;i<16;i++)
	{
		for(int j=12;j<16;j++)
		{
			perm[i][j] = d[i-12][j-12];
		}
	}
	//Filling the diagonal block with e
	for(int i=16;i<20;i++)
	{
		for(int j=16;j<20;j++)
		{
			perm[i][j]=e[i-16][j-16];
		}
	}
        return perm;
}

int** block_diagonal_perm(int index_a,int index_b, int index_c,int index_d, int index_e,int k)
{
        int** a = generate_IR(index_a,k);
        int** b = generate_IR(index_b,k);
        int** c = generate_IR(index_c,k);
	int** d = generate_IR(index_d,k);
	int** e = generate_IR(index_e,k);
        int** perm = new int*[20];
        //Create and initialize Permutation matrix to 0
        for(int i=0;i<20;i++)
        {
                perm[i]=new int[20];
                for(int j=0;j<20;j++)
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
 //Filling fourth diagonal block with IR(index_d)
        for(int i=12;i<16;i++)
        {
                for(int j=12;j<16;j++)
                {
                        perm[i][j]=c[i-12][j-12];
                }
        }
  //Filling fifth  diagonal block with IR(index_e)
        for(int i=16;i<20;i++)
        {
                for(int j=16;j<20;j++)
                {
                        perm[i][j]=c[i-16][j-16];
                }
        }      
       delete a; delete b; delete c; delete d; delete e;	
	return perm;
}

