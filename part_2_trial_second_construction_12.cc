`/*ORDER 12
 * What does this program do?
 * perm1 and perm2 are block diagonal permutation matrices of order 12, with block size=4. 
 * Two Hadamard matrices of order 12,matrix1 and matrix2 are made from Williamson matrices. 
 * This program can be used to test if the Hadamard product of row perm1 applied to matrix1, and column perm2 applied to matrix2 is also Hadamard. Uses Had_Had_t() function. 
 * In addition this program counts for how many of those compliant permutations perm1 and perm2 in the previous step, one of the diagonal blocks is the identity permutation
 * I_4, 
 * Example:  if perm1 and perm2 when applied to matrix1 and matrix2 respectively, produce two matrices whose Hadamard product is Hadamard, then perm1 and perm2 are compliant. 
 * If in either perm1 or perm2, one of the diagonal blocks is identity, then 'count' is incremented. 
*/


/*
 * Input required.
 * Any number between 0 and 7.
 */


/*
 * Data structures
 * This program uses static arrays of size 12, except for matrix1 and matrix2 which are pointers.All pointer related functions that are not defined here 
 * can be found in make_Bush_matrices.cc included in the program.
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
//Global variables
int Had_prod[12][12]={{0}};
int hht[12][12] = {{0}};

// Checks if a matrix is Hadamard or not
bool Had_Had_t();

//Functions that havent been used in the program because they only involve pointers.
//Produces the Kronecker product of circulant matrix and random matrix a.
int** new_constr(int** circulant,int order_circ, int** a,int order_a);
//auxillary function to calculate minimum number of zeroes in a row in a matrix. 
bool count_zeroes();
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
int** circulant1;int** circulant2;int** circulant3;int** circulant4;
int** circulanttest;	
int** matrix;
int** matrix1;
int** matrix2;

/* main is passed two arguments, argc and argv[], which is a string
 * argc refers to the total number of arguments passed while calling the function
 * argv[] is an array of strings which are the arguments passed to the program
 * An example, if the instruction is: "gcc -o myprog myprog.c", then argc=4, argv[0] = gcc argv[1]=-o argv[2]=myprog argv[3]=myprog.c
 * if the instruction is "2cpmm 10",where 2cpmm is the executable for this program, argv[0]=2cpmm, argv[1]=10
 */


int main(int argc,char* argv[])
{
	int circ1[3][3] ={{1,1,-1},{-1,1,1},{1,-1,1}};
	int circ2[3][3] ={{-1,1,-1},{-1,-1,1},{1,-1,-1}};
	int circ3[3][3] ={{1,1,1},{1,1,1},{1,1,1}};
	int circ4[3][3] ={{1,-1,-1},{-1,1,-1},{-1,-1,1}};
	int circtest[3][3]={{-1,-1,1},{1,-1,-1},{-1,1,-1}};
	int a_source[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
	int b_source[4][4]={{0,1,0,0},{-1,0,0,0},{0,0,0,-1},{0,0,1,0}};
	int c_source[4][4]={{0,0,1,0},{0,0,0,1},{-1,0,0,0},{0,-1,0,0}};
	int d_source[4][4]={{0,0,0,1},{0,0,-1,0},{0,1,0,0},{-1,0,0,0}};

	circulant1 = initialize_matrix(&circ1[0][0],3,3);
	circulant2 = initialize_matrix(&circ2[0][0],3,3);
	circulant3 = initialize_matrix(&circ3[0][0],3,3);
	circulant4 = initialize_matrix(&circ4[0][0],3,3);
	circulanttest = initialize_matrix(&circtest[0][0],3,3);
	a = initialize_matrix(&a_source[0][0],4,4);
	b = initialize_matrix(&b_source[0][0],4,4);
	c = initialize_matrix(&c_source[0][0],4,4);
	d = initialize_matrix(&d_source[0][0],4,4);

	//First Williamson matrix.
	matrix = Kronecker(circulant3,a,3,4);
	matrix = Add(matrix,Kronecker(circulant1,b,3,4),12,12);
	matrix = Add(matrix,Kronecker(circulant1,c,3,4),12,12);
	matrix = Add(matrix,Kronecker(circulant1,d,3,4),12,12);
	matrix1 = matrix;
	
	//Second Williamson matrix.
	matrix = Kronecker(circulant3,a,3,4);
        matrix = Add(matrix,Kronecker(circulant2,b,3,4),12,12);
        matrix = Add(matrix,Kronecker(circulant2,c,3,4),12,12);
        matrix = Add(matrix,Kronecker(circulant2,d,3,4),12,12);
        matrix2 = matrix;

	


        // This part of the program permutes matrix1 and matrix2 in permissible ways(eg, permuting a column block/row block, but not across column blocks)
        // and checks if their Hadamard product is Hadamard or not. The outer loop permutes matrix1 and the inner loop permutes matrix2.
     
		int perm1[12]={0};
		int perm2[12]={0};
		int index = atoi(argv[1]);
		int* bin = integer_to_k(index,3);

 
 
//Matrix that contains all possible permutations on four variables.
	int all_perm_4[24][4]={{0,1,2,3},{0,1,3,2},{0,2,1,3},{0,2,3,1},{0,3,1,2},{0,3,2,1},{1,0,2,3},{1,0,3,2},{1,2,0,3},{1,2,3,0},{1,3,0,2},{1,3,2,0},{2,0,1,3},{2,0,3,1},{2,1,0,3},{2,1,3,0},{2,3,0,1},{2,3,1,0},{3,0,1,2},{3,0,2,1},{3,1,0,2},{3,1,2,0},{3,2,0,1},{3,2,1,0}};
	bool cz;
	bool check;
	int count=0;
	
	//Outer nested loop for perm1
	for(int i=0/*(12*bin[0])*/;i<24/*(12+12*bin[0])*/;i++)
	{
		for(int j=0/*(12*bin[1])*/;j<24/*(12+12*bin[1])*/;j++)
		{
			for(int k=0/*(12*bin[2])*/;k<24/*(12+12*bin[2])*/;k++)
			{
						
						//Makes the first permutation matrix perm1
					//	cout<<" j= "<<j<<" k= "<<k<<endl;
						for(int a1=0;a1<4;a1++)
						{
							perm1[a1]=all_perm_4[i][a1];
						}
						for(int b1=4;b1<8;b1++)
						{
							perm1[b1]=4+all_perm_4[j][b1-4];
						}
						for(int c1=8;c1<12;c1++)
						{
							perm1[c1]=8+all_perm_4[k][c1-8];
						}

						//Inner nested loop for perm2.
						for(int n=0;n<24;n++)
						{
							for(int p=0;p<24;p++)
							{
								for(int q=0;q<24;q++)
								{
											//Makes the second permutation matrix perm2.
											for(int a2=0;a2<4;a2++)
                                                					{
												perm2[a2]=all_perm_4[n][a2];
											}
											for(int b2=4;b2<8;b2++)
											{
												perm2[b2]=4+all_perm_4[p][b2-4];
											}
											for(int c2=8;c2<12;c2++)
											{
												perm2[c2]=8+all_perm_4[q][c2-8];
											}

											//Checks if Hadamard product of row perm1 on matrix1 and col perm2 on matrix2 is Hadamard or not.
											for(int i1=0;i1<12;i1++)
											{
												for(int j1=0;j1<12;j1++)
												{
													Had_prod[i1][j1]=matrix1[perm1[i1]][j1]*matrix2[i1][perm2[j1]];
												}
											}
											check = Had_Had_t();	
											
											if(check==true)
											{
												//counts the number of permutations(either perm1 or perm2) that have identity on their diagonal 
												//blocks.
												if(i==0 || j==0 || k==0 || n==0 || p==0 || q==0)
												{
													cout<<"i="<<i<<" j="<<j<<" k="<<k<<endl;
													count++;
													cout<<"n="<<n<<" p="<<p<<" q="<<q<<endl;
													cout<<"_____________________________"<<endl;
												}
												/*
												for(int i3=0;i3<12;i3++)
												{
													for(int j3=0;j3<12;j3++)
													cout<<Had_prod[i3][j3]<<" ";
													cout<<endl;
												}
												cout<<"_________________________________"<<endl;

												*/
											}

										}
									}
								}
							}
						}
					}

cout<<"Total number of Hadamard matrices obtained = "<<count<<endl;
for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
		{
			if((j%4==0 || j%4==1 || j%4==2))
			{
				cout<<matrix1[i][j]<<" ";
			}
			else if(j%4==3)
			{
				cout<<matrix1[i][j]<<"|";
			}
			
		}
		cout<<endl;
		if(i%4==3)
		{
			cout<<"____________________________________"<<endl;
		}
		
	}
 for(int i=0;i<12;i++)
        {
                for(int j=0;j<12;j++)
                {
                        if((j%4==0 || j%4==1 || j%4==2))
                        {
                                cout<<matrix2[i][j]<<" ";
                        }
                        else if(j%4==3)
                        {
                                cout<<matrix2[i][j]<<"|";
                        }
                        
                }
                cout<<endl;
                if(i%4==3)
                {
                        cout<<"____________________________________"<<endl;
                }
                
        }
 //Checks if matrix 1 and matrix 2 is Hadamard. This piece of code was written here and not at the beginning of the program so that it's output can be viewed easily and
 //you dont have to scroll above the printed matrices to find it. 
 cout<<"Is matrix 1 Hadamard? "<<endl;
 cout<<check_Hadamard(matrix1,12)<<endl;
 cout<<"Is matrix2 Hadamard?"<<endl;
 cout<<check_Hadamard(matrix2,12)<<endl;
}

											









bool Had_Had_t()
{
	
	int sum=0;
	for(int i2=0;i2<12;i2++)
	{
		for(int j2=i2+1;j2<12;j2++)
		{
			sum=0;
			for(int k1=0;k1<12;k1++)
			{
				sum=sum+(Had_prod[i2][k1]*Had_prod[j2][k1]);
			}
			//hht[i2][j2]=sum;
			if(sum!=0)
			{
				return false;
			}

			
		}
	}
	return true;

}
bool count_zeroes()
{
        int min_count=12,count=0;
        for(int i=0;i<12;i++)
        {
                for(int j=0;j<12;j++)
                {
                        if(hht[i][j]==0)
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

