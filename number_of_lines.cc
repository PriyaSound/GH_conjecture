#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include<sstream>
using namespace std;
bool readFile(int num, int part);

int main(int argc, char** argv)
{
	
	int upper_limit=0;
	if(atoi(argv[1])==2 || atoi(argv[1])==3 || atoi(argv[1])==4)
	{
		upper_limit=32;
	}
	else if(atoi(argv[1])==5 || atoi(argv[1])==6)
	{
		upper_limit=81;
	}
	for(int i=0;i<upper_limit;i++)
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
		/*
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
		*/
	}
	

	else if(num==2 || num==3 || num==4)
	{
		linenum=0;
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
                               
                        }while(outputfile.eof()==false);
			cout<<"Number of lines in: "<<filename<<" is "<<linenum<<endl;	
					outputfile.close();
					return true;
                }
                else
                {
                        cout<<"Can't open file"<<endl;
                        outputfile.close();
			return false;
                }
        }


 	else if(num==5)
        {
                linenum=0;
                filename = "/home/soundap9/attempt_final_o/o.65." + str_part;
                outputfile.open(filename.c_str(),ios::in|ios::out|ios::app);
                if(outputfile.is_open())
                {

                        do
                        {
                                getline(outputfile,line);
                                linenum++;

                        }while(outputfile.eof()==false);
                        cout<<"Number of lines in: "<<filename<<" is "<<linenum<<endl;
                                        outputfile.close();
					return true;
                }
                else
                {
                        cout<<"Can't open file"<<filename<<endl;
                        outputfile.close();
			return false;
                }
        }

        else if(num==6)
        {
		linenum=0;
                filename = "/home/soundap9/attempt_final_o/o.66." + str_part;
                outputfile.open(filename.c_str(),ios::in|ios::out|ios::app);
                if(outputfile.is_open())
                {

                        do
                        {
                                getline(outputfile,line);
                                linenum++;

                        }while(outputfile.eof()==false);
                        cout<<"Number of lines in: "<<filename<<" is "<<linenum<<endl;
                                        outputfile.close();
					return true;
                }
                else
                {
                        cout<<"Can't open file"<<filename<<endl;
                        outputfile.close();
			return false;
                }
        }

	else
	{
		cout<<"Enter a valid part number"<<endl;
		outputfile.close();
	}


}

				

