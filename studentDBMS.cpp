#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
int main()
{
	FILE *fp,*ft;
	char another,choice;
	struct student
	{
		char first_name[50], last_name[50];
		char course[100];
		int section;
	};
	
	struct student e;
	char xfirst_name[50], xlast_name[50];
	long int recsize;
	
	fp=fopen("users.txt","rb+");
	if(fp == NULL)
	{
		fp = fopen("users.txt","wb+");
		if(fp == NULL)
		{
			puts("Cannot open File");
			return 0;
		}
	}
	
	recsize = sizeof(e);
	while(1)
	{
		cout<<"\t\t****** STUDENT DATABASE MANAGEMENT SYSTEM ******";
		cout<<"\n\n                          ";
		cout<<"\n\n";
		cout<<"\n \t\t\t 1.Add Records";
		cout<<"\n \t\t\t 2.List Records";
		cout<<"\n \t\t\t 3.Modify Records";
		cout<<"\n \t\t\t 4.Delete Records";
		cout<<"\n \t\t\t 5.Exit Program";
		cout<<"\n\n";
		cout<<"\t\t\t Select Your Choice:=> ";
		fflush(stdin);
		choice= getche();
		switch(choice)
		{
			case '1':
				         fseek(fp,0,SEEK_END);
				         another = 'Y';
				         while(another == 'Y'|| another == 'y')
				         {
				         	cout<<"Enter the First Name: ";
				         	cin>>e.first_name;
				         	cout<<"Enter the Last Name: ";
				         	cin>>e.last_name;
				         	cout<<"Enter the Course: ";
				         	cin>>e.course;
				         	cout<<"Enter the Section: ";
				         	cin>>e.section;
				         	fwrite(&e,recsize,1,fp);
				         	cout<<"\n Add Another Record(Y/N) ";
				         	fflush(stdin);
				         	another= getchar();
													}
													break;
			case '2':
				         rewind(fp);
				         cout<<"***View the Records in the Database***";
				         cout<<"\n";
				         while(fread(&e,recsize,1,fp)==1)
				         {
				         	cout<<"\n";
				         	cout<<"\n"<<e.first_name<< setw(10) <<e.last_name;
				         	cout<<"\n";
				         	cout<<"\n"<<e.course<< setw(8) <<e.section;
				         	
													}
													cout<<"\n\n";
													system("pause");
													break;										
				case '3':
				         
				         another = 'Y';
				         while(another == 'Y'|| another == 'y')
				         {
				         	cout<<"\n Enter the Last Name of the Student: ";
				         	cin>>xlast_name;
				         	rewind(fp);
				         	while(fread(&e,recsize,1,fp)==1)
				         	{
				         		if(strcmp(e.last_name,xlast_name)==0)
				         		{
				         			cout<<"Enter new the First Name: ";
				         	cin>>e.first_name;
				         	cout<<"Enter new the Last Name: ";
				         	cin>>e.last_name;
				         	cout<<"Enter new the Course: ";
				         	cin>>e.course;
				         	cout<<"Enter new the Section: ";
				         	cin>>e.section;
				         	fseek(fp,- recsize,SEEK_CUR);
				         	fwrite(&e,recsize,1,fp);
				         	break;
															}
															else
															cout<<"record not found";
				         			
														}
														cout<<"\nModify Another Record(Y/N)";
				         	fflush(stdin);
				         	another= getchar();
													}
													break;
					case '4':
				         
				         another = 'Y';
				         while(another == 'Y'|| another == 'y')
				         {
				         	cout<<"Enter the Last Name of the Student to be Delete: ";
				         	cin>>xlast_name;
				         	ft=fopen("temp.dat","wb");
				         	rewind(fp);
				         	while(fread(&e,recsize,1,fp)==1)
				         	 if(strcmp(e.last_name,xlast_name)!=0){
				         	 	fwrite(&e,recsize,1,ft);
															}
															fclose(fp);
															fclose(ft);
															remove("users.txt");
															rename("temp.dat","users.txt");
															fp=fopen("users.txt","rb+");
															cout<<"\nDelete Another Record(Y/N)";
				         	fflush(stdin);
				         	another= getchar();
													}
													break;								
					case '5':
					           fclose(fp);
																cout<<"\n\n";
																cout<<"\t\t THANK YOU FOR USING THE SOFTWARE";
																cout<<"\n\n";
																exit(0);								
		}
	}
	return 0;
}
