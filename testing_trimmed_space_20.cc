
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
int Had_prod[20][20]={{0}};
int hht[20][20] = {{0}};

// Checks if a matrix is Hadamard or not
bool Had_Had_t();

//Converts a given index to a binary of 5 digits

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
int main(int argc,char* argv[])
{

        int** Williamson1;
	int** Williamson2;
	int** Williamson3;
	int** Williamson4;
	int** Williamsont;
	int Will_1[5][5]={{-1,1,1,1,1},{1,-1,1,1,1},{1,1,-1,1,1},{1,1,1,-1,1},{1,1,1,1,-1}};
	int Will_2[5][5]={{-1,1,1,1,1},{1,-1,1,1,1},{1,1,-1,1,1},{1,1,1,-1,1},{1,1,1,1,-1}};
	int Will_3[5][5]={{1,1,-1,-1,1},{1,1,1,-1,-1},{-1,1,1,1,-1},{-1,-1,1,1,1},{1,-1,-1,1,1}};
	int Will_4[5][5]={{1,-1,1,1,-1},{-1,1,-1,1,1},{1,-1,1,-1,1},{1,1,-1,1,-1},{-1,1,1,-1,1}};
	int Will_t[5][5]={{-1,1,-1,1,1},{1,-1,1,-1,1},{1,1,-1,1,-1},{-1,1,1,-1,1},{1,-1,1,1,-1}};
	int a_source[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
        int b_source[4][4]={{0,1,0,0},{-1,0,0,0},{0,0,0,-1},{0,0,1,0}};
        int c_source[4][4]={{0,0,1,0},{0,0,0,1},{-1,0,0,0},{0,-1,0,0}};
        int d_source[4][4]={{0,0,0,1},{0,0,-1,0},{0,1,0,0},{-1,0,0,0}};

	Williamson1 = initialize_matrix(&Will_1[0][0],5,5);
        Williamson2 = initialize_matrix(&Will_2[0][0],5,5);
        Williamson3 = initialize_matrix(&Will_3[0][0],5,5);
        Williamson4 = initialize_matrix(&Will_4[0][0],5,5);
	Williamsont = initialize_matrix(&Will_t[0][0],5,5);

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
        matrix = Add(matrix,Kronecker(Williamsont,d,5,4),20,20);
        matrix2 = matrix;
     	
	cout<<"Is matrix2 Hadamard?"<<endl;
	cout<<check_Hadamard(matrix2,20)<<endl;     
	//Hadamard matrix of order 20 constructed by Tonchev
	int Hadamard_20_2[20][20] ={{+1,+1,+1,+1,+1,+1,+1,+1,+1,+1,+1,+1,+1,+1,+1,+1,+1,+1,+1,+1},
		{+1,+1,+1,+1,+1,+1,+1,+1,+1,+1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{+1,+1,+1,+1,+1,-1,-1,-1,-1,-1,+1,+1,+1,+1,+1,-1,-1,-1,-1,-1},
		{+1,+1,+1,+1,-1,+1,-1,-1,-1,-1,+1,-1,-1,-1,-1,+1,+1,+1,+1,-1},
		{+1,+1,+1,-1,-1,-1,+1,+1,-1,-1,-1,+1,+1,-1,-1,+1,+1,-1,-1,+1},
		{+1,+1,-1,+1,-1,-1,+1,+1,-1,-1,-1,-1,-1,+1,+1,-1,-1,+1,+1,+1},
		{+1,+1,-1,-1,+1,+1,-1,-1,+1,-1,-1,+1,-1,+1,-1,+1,-1,+1,-1,+1},
		{+1,+1,-1,-1,+1,+1,-1,-1,-1,+1,-1,-1,+1,-1,+1,-1,+1,-1,+1,+1},
		{+1,+1,-1,-1,-1,-1,+1,-1,+1,+1,+1,+1,-1,-1,+1,-1,+1,+1,-1,-1},
		{+1,+1,-1,-1,-1,-1,-1,+1,+1,+1,+1,-1,+1,+1,-1,+1,-1,-1,+1,-1},
		{+1,-1,+1,+1,-1,-1,-1,-1,+1,+1,-1,+1,-1,-1,+1,+1,-1,-1,+1,+1},
		{+1,-1,+1,-1,+1,-1,+1,-1,+1,-1,+1,-1,+1,-1,-1,-1,-1,+1,+1,+1},
		{+1,-1,+1,-1,+1,-1,-1,+1,-1,+1,-1,+1,-1,+1,-1,-1,+1,+1,+1,-1},
		{+1,-1,+1,-1,-1,+1,+1,-1,-1,+1,-1,-1,+1,+1,+1,+1,-1,+1,-1,-1},
		{+1,-1,+1,-1,-1,+1,-1,+1,+1,-1,+1,-1,-1,+1,+1,-1,+1,-1,-1,+1},
		{+1,-1,-1,+1,+1,-1,+1,-1,-1,+1,+1,-1,-1,+1,-1,+1,+1,-1,-1,+1},
		{+1,-1,-1,+1,+1,-1,-1,+1,+1,-1,-1,-1,+1,-1,+1,+1,+1,+1,-1,-1},
		{+1,-1,-1,+1,-1,+1,+1,-1,+1,-1,-1,+1,+1,+1,-1,-1,+1,-1,+1,-1},
		{+1,-1,-1,+1,-1,+1,-1,+1,-1,+1,+1,+1,+1,-1,-1,-1,-1,+1,-1,+1},
		{+1,-1,-1,-1,+1,+1,+1,+1,-1,-1,+1,+1,-1,-1,+1,+1,-1,-1,+1,-1}
	};
	// Hadamard matrix of order 20 constructed by Paley(?)
	int Hadamard_20_3[20][20] = {{+1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{+1,+1,-1,+1,+1,-1,-1,-1,-1,+1,-1,+1,-1,+1,+1,+1,+1,-1,-1,+1},
		{+1,+1,+1,-1,+1,+1,-1,-1,-1,-1,+1,-1,+1,-1,+1,+1,+1,+1,-1,-1},
	    	{+1,-1,+1,+1,-1,+1,+1,-1,-1,-1,-1,+1,-1,+1,-1,+1,+1,+1,+1,-1},
		{+1,-1,-1,+1,+1,-1,+1,+1,-1,-1,-1,-1,+1,-1,+1,-1,+1,+1,+1,+1},
		{+1,+1,-1,-1,+1,+1,-1,+1,+1,-1,-1,-1,-1,+1,-1,+1,-1,+1,+1,+1},
		{+1,+1,+1,-1,-1,+1,+1,-1,+1,+1,-1,-1,-1,-1,+1,-1,+1,-1,+1,+1},
		{+1,+1,+1,+1,-1,-1,+1,+1,-1,+1,+1,-1,-1,-1,-1,+1,-1,+1,-1,+1},
		{+1,+1,+1,+1,+1,-1,-1,+1,+1,-1,+1,+1,-1,-1,-1,-1,+1,-1,+1,-1},
		{+1,-1,+1,+1,+1,+1,-1,-1,+1,+1,-1,+1,+1,-1,-1,-1,-1,+1,-1,+1},
		{+1,+1,-1,+1,+1,+1,+1,-1,-1,+1,+1,-1,+1,+1,-1,-1,-1,-1,+1,-1},
		{+1,-1,+1,-1,+1,+1,+1,+1,-1,-1,+1,+1,-1,+1,+1,-1,-1,-1,-1,+1},
		{+1,+1,-1,+1,-1,+1,+1,+1,+1,-1,-1,+1,+1,-1,+1,+1,-1,-1,-1,-1},
		{+1,-1,+1,-1,+1,-1,+1,+1,+1,+1,-1,-1,+1,+1,-1,+1,+1,-1,-1,-1},
		{+1,-1,-1,+1,-1,+1,-1,+1,+1,+1,+1,-1,-1,+1,+1,-1,+1,+1,-1,-1},
		{+1,-1,-1,-1,+1,-1,+1,-1,+1,+1,+1,+1,-1,-1,+1,+1,-1,+1,+1,-1},
		{+1,-1,-1,-1,-1,+1,-1,+1,-1,+1,+1,+1,+1,-1,-1,+1,+1,-1,+1,+1},
		{+1,+1,-1,-1,-1,-1,+1,-1,+1,-1,+1,+1,+1,+1,-1,-1,+1,+1,-1,+1},
		{+1,+1,+1,-1,-1,-1,-1,+1,-1,+1,-1,+1,+1,+1,+1,-1,-1,+1,+1,-1},
		{+1,-1,+1,+1,-1,-1,-1,-1,+1,-1,+1,-1,+1,+1,+1,+1,-1,-1,+1,+1}
	};
        
        // This part of the program permutes matrix1 and matrix2 in permissible ways(eg, permuting a column block/row block, but not across column blocks)
        // and checks if their Hadamard product is Hadamard or not. The outer loop permutes matrix1 and the inner loop permutes matrix2.
     
 //Adding code to accomodate all types of block diagonal permutation matrices and not just those of the IxR type.
             
//		cout<<check_Hadamard(Hadamard_20_2,20)<<endl;
//		cout<<check_Hadamard(Hadamard_20_3,20)<<endl;
		int perm1[20]={0};
		int perm2[20]={0};
		int index = atoi(argv[1]);
		int* bin = integer_to_k(index,5);

 
 
//function to display the permutations.
	int all_perm_4[24][4]={{0,1,2,3},{0,1,3,2},{0,2,1,3},{0,2,3,1},{0,3,1,2},{0,3,2,1},{1,0,2,3},{1,0,3,2},{1,2,0,3},{1,2,3,0},{1,3,0,2},{1,3,2,0},{2,0,1,3},{2,0,3,1},{2,1,0,3},{2,1,3,0},{2,3,0,1},{2,3,1,0},{3,0,1,2},{3,0,2,1},{3,1,0,2},{3,1,2,0},{3,2,0,1},{3,2,1,0}};
	bool cz;
	bool check;
	
	for(int i=0/*(12*bin[0])*/;i<1/*(12+12*bin[0])*/;i++)
	{
		for(int j=(12*bin[1]);j<(12+12*bin[1]);j++)
		{
			for(int k=(12*bin[2]);k<(12+12*bin[2]);k++)
			{
				for(int l=(12*bin[3]);l<(12+12*bin[3]);l++)
				{
					for(int m=(12*bin[4]);m<(12+12*bin[4]);m++)
					{
						
						cout<<"i ="<<i<<" j= "<<j<<" k= "<<k<<" l= "<<l<<" m= "<<m<<endl;
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
						for(int d1=12;d1<16;d1++)
						{
							perm1[d1]=12+all_perm_4[l][d1-12];
						}
						for(int e1=16;e1<20;e1++)
						{
							perm1[e1]=16+all_perm_4[m][e1-16];
						}

						for(int n=0;n<24;n++)
						{
							//cout<<" n= "<<n<<endl;
							for(int p=0;p<24;p++)
							{
								for(int q=0;q<24;q++)
								{
									for(int r=0;r<24;r++)
									{
										for(int s=0;s<24;s++)
										{
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
											for(int d2=12;d2<16;d2++)
											{       
												perm2[d2]=12+all_perm_4[r][d2-12];
											}
											for(int e2=16;e2<20;e2++)
											{       
												perm2[e2]=16+all_perm_4[s][e2-16];
											}
											for(int i1=0;i1<20;i1++)
											{
												for(int j1=0;j1<20;j1++)
												{
													//Had_prod[i1][j1]=Hadamard_20_2[perm1[i1]][j1]*Hadamard_20_3[i1][perm2[j1]];
													Had_prod[i1][j1]=matrix1[perm1[i1]][j1]*matrix2[i1][perm2[j1]];

												}
											}
											check = Had_Had_t();	
											
											if(check==true)
											{
												for(int i3=0;i3<20;i3++)
												{
													for(int j3=0;j3<20;j3++)
													cout<<Had_prod[i3][j3]<<" ";
													cout<<endl;
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
	}

											







}


bool Had_Had_t()
{
	
	int sum=0;
	for(int i2=0;i2<20;i2++)
	{
		for(int j2=i2+1;j2<20;j2++)
		{
			sum=0;
			for(int k1=0;k1<20;k1++)
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
        int min_count=20,count=0;
        for(int i=0;i<20;i++)
        {
                for(int j=0;j<20;j++)
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

