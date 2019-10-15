#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int choice,nostate,inputs;
	cout<<"Enter Type of DFA:- \n1.Ending with string \n2.Starting with string \n3.Substring\n";
	cin>>choice;
	cout<<"Enter No. of input symbol\n";
	cin>>inputs;
	string dfa_str;
	string input_symbols;
	int i=0;
	cout<<"Enter input symbols:\n";
	while(i<inputs)
	{	char temp;
		cin>>temp;
		input_symbols.push_back(temp);
		i++;
	}
	int dfa_trans[100][inputs];
	int pcount=0;
	int ptemp=0;
	int flag=0;
	switch(choice) {
		case 1:
			cout<<"Enter Suffix:\n";
			cin>>dfa_str;
			nostate=dfa_str.length()+1;
			i=0;
			{ int j=0;
				for(j=0;j<inputs;j++)
				{
					if(input_symbols[j]==dfa_str[0])
					{	
						dfa_trans[i][j]=1;
					}
					else
					{
						dfa_trans[i][j]=0;
						
					}
				}	
			}
			
			for(i=1;i<nostate;i++)
			{ptemp=pcount;
			int ptemp2=pcount;	
				for(int j=0;j<inputs;j++)
				{
				ptemp=ptemp2;
					
					if(dfa_str[i]==input_symbols[j])
					{
						dfa_trans[i][j]=i+1;
						if(dfa_str[i]==dfa_str[pcount])
						{	pcount++; }	
						else
						{
						
							while(pcount>0)
							{
								string start=dfa_str.substr(0,pcount);
								string last=dfa_str.substr(i-pcount+1,pcount);
								//cout<<start<<" "<<last<<" ---- ";
								if(start.compare(last)==0)
								{//cout<<" voila ";
									break;
								}
								else
								{
									pcount--; 
								}
								
							}
						}
					}
					else if(input_symbols[j]==dfa_str[ptemp])
					{
						dfa_trans[i][j]=ptemp+1;	
					}
					else
					{//	ptemp=ptemp2;
					//	cout<<" i "<<i<<" pcount "<<pcount<<endl;
							while(ptemp>0)
							{
								string start=dfa_str.substr(0,ptemp);
								string last=dfa_str.substr(i-ptemp+1,ptemp-1);
								last.push_back(input_symbols[j]);
								//cout<<start<<" "<<last<<" ---- ";
								if(start.compare(last)==0)
								{//cout<<"yes"<<j;
									break;
								}
								else
								{
									ptemp--;
								}
								
							}
							dfa_trans[i][j]=ptemp;
					} 
				}
			}				
			
			break;
		case 2:
			cout<<"Enter Prefix:\n";
			cin>>dfa_str;
			nostate=dfa_str.length()+2;
			for(i=0;i<nostate-2;i++)
			{
				int j=0;
				for(j;j<inputs;j++)
				{
				if(dfa_str[i]==input_symbols[j])
				{
					dfa_trans[i][j]=i+1;
				}
				else
				{
					dfa_trans[i][j]=nostate-1;
				}
				}
			}
			for(i;i<nostate;i++)
			{
				for(int j=0;j<inputs;j++)
				{dfa_trans[i][j]=i;
				}
			}
			break;	
		case 3:
			cout<<"Enter Substring:\n";
			cin>>dfa_str;
			nostate=dfa_str.length()+1;
			i=0;
			{ int j=0;
				for(j=0;j<inputs;j++)
				{
					if(input_symbols[j]==dfa_str[0])
					{	
						dfa_trans[i][j]=1;
					}
					else
					{
						dfa_trans[i][j]=0;
					}
				}	
			}
			
			for(i=1;i<nostate-1;i++)
			{ptemp=pcount;
			int ptemp2=pcount;	
				for(int j=0;j<inputs;j++)
				{
				ptemp=ptemp2;
					
					if(dfa_str[i]==input_symbols[j])
					{
						dfa_trans[i][j]=i+1;
						if(dfa_str[i]==dfa_str[pcount])
						{	pcount++; }	
						else
						{
						
							while(pcount>0)
							{
								string start=dfa_str.substr(0,pcount);
								string last=dfa_str.substr(i-pcount+1,pcount);
								cout<<start<<" "<<last<<" ---- ";
								if(start.compare(last)==0)
								{//cout<<" voila ";
									break;
								}
								pcount--;
							}
						}
					}
					else if(input_symbols[j]==dfa_str[ptemp])
					{
						dfa_trans[i][j]=ptemp+1;	
					}
					else
					{	ptemp=pcount;
					//	cout<<" i "<<i<<" pcount "<<pcount<<endl;
							while(ptemp>0)
							{
								string start=dfa_str.substr(0,ptemp);
								string last=dfa_str.substr(i-ptemp+1,ptemp-1);
								last.push_back(input_symbols[j]);
								cout<<start<<" "<<last<<" ---- ";
								if(start.compare(last)==0)
								{cout<<"yes"<<j;
									break;
								}
								ptemp--;
							}
							dfa_trans[i][j]=ptemp;
					} 
				}
			}	
	/*		if(flag!=1)
			{
		//		pcount=0;
			}*/
			for(int j=0;j<inputs;j++)
			{ 	
			dfa_trans[i][j]=i;	
			}
			
			break;		
		}
		
		cout<<"    \t|\t";
		for(int j=0;j<inputs;j++)
		{
			cout<<input_symbols[j]<<"\t";
		}
		cout<<endl;
		//cout<<"________|__________________________________________________________";
		cout<<"________|";
		for(int j=0;j<inputs;j++)
		{
			cout<<"_________";
		}
		cout<<endl;
		for(int k=0;k<nostate;k++)
		{	if(k==0)
			{	cout<<"->";
			}
			
			else
			{if(choice==2)
			{	if(k==nostate-2)
				cout<<" *";
				else if(k==nostate-1)
				cout<<" D";
				else
				cout<<"  ";
			}
			else
			{	if(k==nostate-1)
				cout<<" *";
				else
				cout<<"  ";
			}
			}
			cout<<"q"<<k<<"\t|\t";
			for(int j=0;j<inputs;j++)
			{int temp2=dfa_trans[k][j];
				cout<<"q"<<temp2<<"\t";
			}
			cout<<endl;
		}
		
		string pstring;
		cout<<"\nEnter string to be recognized";
		cout<<endl;
		
		cin>>pstring;
		int cur_i=0;
		cout<<endl;
		for(int k=0;k<pstring.length();k++)
		{
			cout<<"q"<<cur_i<<"---"<<pstring[k]<<"-->";
			int j;
			j=input_symbols.find(pstring[k]);
			cur_i=dfa_trans[cur_i][j];
			
		}
		cout<<"q"<<cur_i;
		if(choice==2)
		{
			if(cur_i==nostate-2)
			{cout<<"\n String Accepted \n";
			}
			else
			{
				cout<<"\n String not Accepted\n";
			}
		}
		else
		{
			if(cur_i==nostate-1)
			{cout<<"\n String Accepted \n";
			}
			else
			{
				cout<<"\n String not Accepted\n";
			}	
		}	
}
