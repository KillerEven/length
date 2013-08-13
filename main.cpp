//length
#include<fstream>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<cstdio>

using namespace std;

typedef struct unit
{
	char name[20];//unit name
	double num;//1 unit equals num m
}UN;

int k=1;
UN unGroup[100]={{"m",1}};//unit group

int cmp(char a[],char b[]);
double search(char un[]);

int main()
{
	int i;
	double nmA,nmB,sum,status;
	string line;
	char unA[20],unB[20],tmp[20];
	char c;
	char lineC[200];
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	while(1)
	{
		getline(fin,line);
		if(line.length()==0)break;
		line.copy(lineC,line.length(),0);
		sscanf(lineC,"%lf %s %s %lf %s",&nmA,unA,tmp,&nmB,unB);
		strcpy(unGroup[k].name,unA);
		unGroup[k].num=nmB/nmA;
		k++;
	}
	fout<<"c.even@live.cn"<<endl<<endl;
	for(i=0;i<10;i++)	
	{
		sum=0;
		status=1;
		do
		{
			fin>>nmA>>unA;
			sum+=status*nmA*search(unA);
			c=fin.get();
			if(c==' ')c=fin.get();
			if(c=='+')status=1;
			if(c=='-')status=-1;
		}while(c!='\n'&&c!='\r');
		fout<<setiosflags(ios::fixed)<<setprecision(2)<<sum;
		fout<<" m"<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

int cmp(char a[],char b[])//a funtion to calc the similarity of two string
{
	int len,i,r=0;
	if(strlen(a)<strlen(b))len=strlen(a);
	else len=strlen(b);
	for(i=0;i<len;i++)
	{
		if(a[i]==b[i])r++;
	}
	return r;
}

double search(char un[])
{
	int i,max=0,r;
	for(i=0;i<k;i++)//get the similarist unit
	{
		if(cmp(unGroup[i].name,un)>max)
		{
			max=cmp(unGroup[i].name,un);
			r=i;
		}
	}
	return unGroup[r].num;
}
