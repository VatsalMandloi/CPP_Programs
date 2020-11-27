#include<fstream.h>
#include<iomanip.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
class student
{
	int rollno;
	char name[50];
	char dob[9];
	int p_marks, c_marks, m_marks, e_marks, cs_marks;
	float per;
	char grade;
	void calculate();
public:
	void getdata();
	void showdata();
	void show_tabular();
	int retrollno();
};
void student::calculate()
{
	per=(p_marks+c_marks+m_marks+e_marks+cs_marks)/5.0;
	if(per>=60)
		grade='A';
	else if(per>=50)
		grade='B';
	else if(per>=33)
		grade='C';
	else
		grade='F';
}

void student::getdata()
{
	cout<<"\nEnter The roll number of student ";
	cin>>rollno;
	cout<<"\n\nEnter The Name of student ";
	gets(name);
	cout<<"\nEnter The Date Of Birth of student";
	gets(dob);
	cout<<"\nEnter The marks in physics out of 100 : ";
	cin>>p_marks;
	cout<<"\nEnter The marks in chemistry out of 100 : ";
	cin>>c_marks;
	cout<<"\nEnter The marks in maths out of 100 : ";
	cin>>m_marks;
	cout<<"\nEnter The marks in english out of 100 : ";
	cin>>e_marks;
	cout<<"\nEnter The marks in computer science out of 100 : ";
	cin>>cs_marks;
	calculate();
}

void student::showdata()
{
	cout<<"\nRoll number of student : "<<rollno;
	cout<<"\nName of student : "<<name;
	cout<<"\nDate Of Birth ofstudent :"<<dob;
	cout<<"\nMarks in Physics : "<<p_marks;
	cout<<"\nMarks in Chemistry : "<<c_marks;
	cout<<"\nMarks in Maths : "<<m_marks;
	cout<<"\nMarks in English : "<<e_marks;
	cout<<"\nMarks in Computer Science :"<<cs_marks;
	cout<<"\nPercentage of student is  :"<<per;
	cout<<"\nGrade of student is :"<<grade;
}

void student::show_tabular()
{int pos;
     pos=58-strlen(name);
	cout<<"\n Rollno.| "<<rollno<<"\n Name   | "<<name<<setw(pos)<<"|";
	cout<<"\n Marks  | "<<setw(2)<<p_marks<<" | "<<setw(2)<<c_marks<<" | "<<setw(2)<<m_marks<<" | "<<setw(2);
	cout<<e_marks<<" | "<<setw(2)<<cs_marks<<" | "<<setw(4)<<per<<" | "<<setw(2)<<grade<<setw(25)<<"|\n";
	cout<<"\t|----------------------------------------------------------|";
}
int student::retrollno()
{
	return rollno;
}
void write_student();
void display_all();
void display_sp(int);
void modify_student(int);
void delete_student(int);
void class_result();
void result();
void intro();
void entry_menu();
void main()
{
	char ch;
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2);
	clrscr();
	do
	{       clrscr();
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. RESULT MENU";
		cout<<"\n\n\t02. ENTRY/EDIT MENU";
		cout<<"\n\n\t03. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-3) ";
		cin>>ch;
		clrscr();
		switch(ch)
		{
			case '1': result();
				break;
			case '2': entry_menu();
				break;
			case '3':
				break;
			default :cout<<"\nPlease!!!!Enter correct number";
		}
	}while(ch!='3');
getch();
}
void write_student()
{
	student st;
	ofstream outFile;
	outFile.open("student.dat",ios::binary|ios::app);
	st.getdata();
	outFile.write((char *) &st, sizeof(st));
	outFile.close();
	cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	getch();
}
void display_all()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read((char *) &st, sizeof(st)))
	{
		st.showdata();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	getch();
}
void display_sp(int n)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}

	int flag=0;
	while(inFile.read((char *) &st, sizeof(st)))
	{
		if(st.retrollno()==n)
		{cout<<"\n\n\t\t\t      STUDENTS RESULT \n\n";
		 cout<<"\n\t|==========================================================|\n";
		 cout<<"\t|  P    C    M    E   CS   %age   Grade                    |"<<endl;
		 cout<<"\t|==========================================================|";
			 st.show_tabular();
			 flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		cout<<"\n\nrecord not exist";
	getch();
}
void modify_student(int n)
{
	int found=0;
	student st;
	fstream File;
	File.open("student.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	while(File.read((char *) &st, sizeof(st)) && found==0)
	{
		if(st.retrollno()==n)
		{
			st.showdata();
			cout<<"\n\nPlease Enter The New Details of student\n";
			st.getdata();
			int pos=(-1)*sizeof(st);
			File.seekp(pos,ios::cur);
			File.write((char *) &st, sizeof(st));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}
	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();
}
void delete_student(int n)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &st, sizeof(st)))
	{      if(st.retrollno()!=n)
		{
			outFile.write((char *) &st, sizeof(st));
		}
	}
	outFile.close();
	inFile.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	cout<<"\n\n\tRecord Deleted ..";
	getch();
}
void class_result()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	cout<<"\n\n\t\t\t    ALL STUDENTS RESULT \n\n";
	cout<<"\t|==========================================================|\n";
	cout<<"\t|  P    C    M    E   CS   %age   Grade                    |"<<endl;
	cout<<"\t|==========================================================|";
	while(inFile.read((char *) &st, sizeof(st)))
	{
		st.show_tabular();
	}
	cout<<"\n\t|__________________________________________________________|";
	getch();
	inFile.close();
}
void result()
{
	char ch;
	int rno;
	cout<<"\n\n\n\tRESULT MENU";
	cout<<"\n\n\n\t1. Class Result";
	cout<<"\n\n\t2. Student Report Card";
	cout<<"\n\n\t3. Back to Main Menu";
	cout<<"\n\n\n\tEnter Choice (1/2/3)? ";
	cin>>ch;
	clrscr();
	switch(ch)
	{
	case '1' :class_result(); break;
	case '2' :cout<<"\n\n\tEnter Roll Number Of Student : ";
		  cin>>rno;
		  display_sp(rno); break;
	case '3' :break;
	default :cout<<"\a";
	}
}
void entry_menu()
{
	char ch;
	int num;
	clrscr();
	cout<<"\n\n\n\tENTRY MENU";
	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
	cout<<"\n\n\t3.SEARCH STUDENT RECORD ";
	cout<<"\n\n\t4.MODIFY STUDENT RECORD";
	cout<<"\n\n\t5.DELETE STUDENT RECORD";
	cout<<"\n\n\t6.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
	cin>>ch;
	clrscr();
	switch(ch)
	{
	case '1':	write_student(); break;
	case '2':	display_all(); break;
	case '3':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
			display_sp(num); break;
	case '4':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
			modify_student(num);break;
	case '5':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
			delete_student(num);break;
	case '6':	break;
	default:	cout<<"\nPlease!!!!Enter correct number"; entry_menu();
	}
}
