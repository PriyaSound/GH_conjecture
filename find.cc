/*
 * This program checks 4 output files of 4 different programs run on condor, based on the index input which can be 1, 2, 3 or 4, for strings of the type "-1".
 * The four files are the output files for 4 condor programs run on cluster 15, 16, 17 and 20
 * 3 of the files are located in /home/soundap9/o and are called:
 * 
 * o.15.($part) (index=1)
 * Details:
 * (Stopped)
 *
 * o_part2.16.($part) (index=2)
 * Details:
 * Program: part_2_trial_second_construction_20.cc
 * Executable: p2tsc2
 * (Running)
 *
 *
 * o_part3.17.($part) (index=3)
 * Details:
 * Program: part_3_trial_second_construction_20.cc
 * Executable: p3tsc2
 * (Running)
 *
 *
 * 1 is located in /home/soundap9/attempt_2_o and is called:
 * o_part4.20.($part) (index=4)
 * Details:
 * Program: 20_check_permutation_matrix1_matrix2.cc
 * Executable: 2cpmm
 * (Running)
 *
 * The program basically checks if any of the 3 programs have printed a Hadamard matrix.
 */

#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include<sstream>
using namespace std;
bool readFile(int num, int part);

int main(int argc, char** argv)
{
	
	for(int i=0;i<32;i++)
	{
		readFile(atoi(argv[1]),i);
	}

	return 0;
	
}

bool readFile(int num, int part)
{
	bool found = false;
	string line, word;
	int pos=0, linenum=0;
	fstream outputfile;
	string filename;
	stringstream ss;
	
	ss<<num;
	string str_num = ss.str();
	ss.str(std::string());
	ss.clear();

	ss<<part;
	string str_part = ss.str();
	ss.str(std::string());
	ss.clear();

	ss<<(14+num);
	string str_14num = ss.str();
	ss.str(std::string());
	ss.clear();

	if(num==1)
	{
		filename = "/home/soundap9/o/o.15." +  str_part;
		outputfile.open(filename.c_str(),ios::in|ios::out|ios::app);
		if(outputfile.is_open())
		{
			for(int i=0;i<20;i++)
			{	
				if(outputfile.eof()==false)
				{
					getline(outputfile,line);
				}
				else
				{
					cout<<filename<<endl;
					cout<<"Reached end of file. Sorry"<<endl;
					outputfile.close();
					return false;
				}
			}

			do
			{
				getline(outputfile,line);
				linenum++;
				pos = line.find("-1");
				
				if(pos != string::npos)
				{
					cout<<"Line number "<<linenum<<endl;
					cout<<" Position: "<<pos<<endl;
					outputfile.close();
					return true;
				}
				else if(outputfile.eof())
				{
					cout<<filename<<endl;
					cout<<"Reached end of file. String not found."<<endl;
					outputfile.close();
					return false;
				}
			}while(found==false);
		}
		else
		{
			cout<<"Can't open file"<<endl;
			outputfile.close();
			return false;
		}
	}
	else if(num==2 || num==3 || num==4)
	{
		linenum=0;
		found=false;
		if(num==2 || num==3)
		filename = "/home/soundap9/o/o_part" +  str_num + "." +  str_14num + "." +  str_part;
		else if(num==4)
		filename = "/home/soundap9/attempt_2_o/o_part" + str_num + ".20." + str_part;
		outputfile.open(filename.c_str(),ios::in|ios::out|ios::app);
                if(outputfile.is_open())
                {       
                        
                        do
                        {       
                                getline(outputfile,line);
				linenum++;
                                pos = line.find("-1"); 
                                if(pos!= string::npos)
                                {
                                        cout<<"Line number "<<linenum<<endl;
                                        cout<<" Position: "<<pos<<endl;
                                        outputfile.close();
                                        return true;
                                }
                                else if(outputfile.eof())
                                {
                                        cout<<"Reached end of file. String not found for part 2 or 3"<<endl;
					cout<<filename<<endl;	
					outputfile.close();
                                        return false;
                                }
                        }while(found==false);
                }
                else
                {
                        cout<<"Can't open file"<<endl;
                        outputfile.close();
			return false;
                }
        }

	else
	{
		cout<<"Enter a valid part number"<<endl;
		outputfile.close();
		return false;
	}

	return 0;
}

				

