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
//Global variables
int** perm_matrix;
int** perm_matrix_1;
int** perm_matrix_2;
int** mult_matrix_1;
int** mult_matrix_2;
//Produces the Kronecker product of circulant matrix and random matrix a.
int** new_constr(int** circulant,int order_circ, int** a,int order_a);
//auxillary function to calculate minimum number of zeroes in a row in a matrix. 
bool count_zeroes(int** Had);

//Generates a 3-block diagonal permuation matrix depending on the parameters.
int** block_diagonal_perm(int index_a,int index_b, int index_c,int index_d, int index_e, int k);

// Generates a random permutation matrix of order 4 based on an index that can vary between 0 and 23.
int** generate_perm_4(int index);

//Generates a random permutation matrix of order 12 with the three permutation matrices of order 4 on its block diagonal.
int** random_perm_matrix(int a, int b, int c,int d,int e);

int** a;
int** b;
int** c;
int** d;
int main(int argc,char* argv[])
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
      

cout<<"Testing:"<<endl;
cout<<double(inner_product(matrix1[0],matrix2[0],20))<<endl;
        
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
                bool cz;
                int** Had_Had_t;
                int** matrix_new_1;
                int** matrix_new_2;
                polynomial** GH;
		
		int index = atoi(argv[1]);
		int* bin = integer_to_k(index,5);
                for(int i=(12*bin[0]);i<(12+12*bin[0]);i++)
                {
			for(int j=(12*bin[1]);j<(12+12*bin[1]);j++)
                        {
				for(int k=(12*bin[2]);k<(12+12*bin[2]);k++)
                                {
					for(int l=(12*bin[3]);l<(12+12*bin[3]);l++)
					{
						for(int m=(12*bin[4]);m<(12+12*bin[4]);m++)
						{
                                        		cout<<"i="<<i<<" j="<<j<<" k="<<k<<" l="<<l<<" m="<<m<<endl;
							perm_matrix_1 = random_perm_matrix(i,j,k,l,m);
							mult_matrix_1 = matrix_multiplication(perm_matrix_1,matrix1,20);
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
											
											perm_matrix_2 = random_perm_matrix(n,p,q,r,s);
											mult_matrix_2 = matrix_multiplication(matrix2,perm_matrix_2,20);
											Had = Hadamard_product(mult_matrix_1,mult_matrix_2,20);
                       		                                       			Had_Had_t = matrix_multiplication(Had,Trans(Had,20),20);
											if(check_Hadamard(Had_Had_t,20)==true)
											{
												cout<<"n= "<<n<<" p= "<<p<<" q= "<<q<<" r= "<<r<<" s= "<<s<<endl;
												print(Had_Had_t,20);                                                                      
                                                                			}
											//free(perm11);free(perm12);free(perm13);free(perm14);free(perm15);
											//free(perm21);free(perm22);free(perm23);free(perm24);free(perm25);

											for(int i=0;i<20;i++)
											{
												delete (perm_matrix_2[i]);
												perm_matrix_2[i] = NULL;
												
												delete (mult_matrix_2[i]);
												mult_matrix_2[i] = NULL;
												
												delete (Had[i]);
												Had[i]=NULL;
												
												delete(Had_Had_t[i]);
												Had_Had_t[i]=NULL;
												
												delete (perm_matrix[i]);
												perm_matrix[i] = NULL;
												
												delete (mult_matrix[i]);
												mult_matrix[i] = NULL;
												//cout<<"check"<<endl;
												
												delete (Hadprod_matrix[i]);
												Hadprod_matrix[i] = NULL;
												
												delete (Trans_matrix[i]);
												Trans_matrix[i] = NULL;
											}
												//delete perm_matrix_2;
												//delete mult_matrix_2;
												//delete Had;
												//delete Had_Had_t;
												delete perm_matrix;
												delete mult_matrix;
												delete Hadprod_matrix;
												delete Trans_matrix;	
											
											}
										}	
									}
								}
							}
						     for(int i=0;i<20;i++)
						     {

                                                                delete (perm_matrix_1[i]);
								perm_matrix_1[i]=NULL;
								
								delete(mult_matrix_1[i]);
								mult_matrix_1[i] = NULL;
								
							
						     }

							delete perm_matrix_1;
							delete mult_matrix_1;
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
int** random_perm_matrix(int ind_a, int ind_b, int ind_c, int ind_d, int ind_e)
{

	int** a = generate_perm_4(ind_a);
	int** b = generate_perm_4(ind_b);
	int** c = generate_perm_4(ind_c);
	int** d = generate_perm_4(ind_d);
	int** e = generate_perm_4(ind_e);
	 perm_matrix = new int*[20];
        //Create and initialize Permutation matrix to 0
        for(int i=0;i<20;i++)
        {
                perm_matrix[i]=new int[20];
                for(int j=0;j<20;j++)
                {
                        perm_matrix[i][j]=0;
                }
        }
        //Filling first diagonal block with a
        for(int i=0;i<4;i++)
        {
                for(int j=0;j<4;j++)
                {
                        perm_matrix[i][j]=a[i][j];
                }
        }
        //Filling second diagonal block with b
        for(int i=4;i<8;i++)
        {
                for(int j=4;j<8;j++)
                {
                        perm_matrix[i][j]=b[i-4][j-4];
                }
        }
        //Filling third diagonal block with c
        for(int i=8;i<12;i++)
        {
                for(int j=8;j<12;j++)
                {
                        perm_matrix[i][j]=c[i-8][j-8];
                }
        }
	//Filling the diagonal block with d
	for(int i=12;i<16;i++)
	{
		for(int j=12;j<16;j++)
		{
			perm_matrix[i][j] = d[i-12][j-12];
		}
	}
	//Filling the diagonal block with e
	for(int i=16;i<20;i++)
	{
		for(int j=16;j<20;j++)
		{
			perm_matrix[i][j]=e[i-16][j-16];
		}
	}
	for(int i=0;i<4;i++)
	{
		free(a[i]);
		free(b[i]);
		free(c[i]);
		free(d[i]);
		free(e[i]);
	}
	free(a);
	free(b);
	free(c);
	free(d);
	free(e);

        return perm_matrix;
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

