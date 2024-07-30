#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;
int get_file_emp();

class employee
{
public:
    int empid;
    char ename[50];
    char designation[50];
    float salary;
    int holidays_allowed;
    friend void search();
    friend void remove_employee();
public:
    void accept()
    {
        cout<<endl<<"Enter Emp ID ";
        cin>>empid;
        cout<<endl<<"Enter Ename ";
        cin>>ename;
        cout<<endl<<"Enter Designation ";
        cin>>designation;
        cout<<endl<<"Enter Salary ";
        cin>>salary;
        cout<<endl<<"Enter Holidays_allowed";
        cin>>holidays_allowed;
    }
    void show_data()
    {
        cout<<endl;
        cout<<setw(12);
        cout<<empid;
        cout<<setw(50);
        cout<<ename;
        cout<<setw(25);
        cout<<designation;
        cout<<setw(8);
        cout<<salary;
        cout<<setw(5);
        cout<<holidays_allowed;
    }

}empobj;

class salary_disburse
{
private:
    int empid;
    char month[50];
    char year[10];
    char date[15];
    int holidays;
    float amount_given;
    friend void show_salary();
public:
    void display()
    {
        cout<<endl<<setw(15);
        cout<<empid;
        cout<<setw(20);
        cout<<month;
        cout<<setw(20);
        cout<<year;
        cout<<setw(30);
        cout<<date;
        cout<<setw(5);
        cout<<holidays;
        cout<<setw(10);
        cout<<amount_given;
    }
    void new_salary()
    {
        cout<<endl<<"Enter empid";
        cin>>empid;
        int p=get_file_emp();
        fstream rd;
        int flag=0;
        rd.open("employees.txt",ios::in);
        for(int i=1;i<=p;i++)
        {
            rd.read((char *)&empobj,sizeof(empobj));

            if(empobj.empid==empid)
            {
                cout<<endl<<"-------------------------Employee Details------------------------------";
                empobj.show_data();
                flag=1;
                cout<<endl<<"-----------------------------------------------------------------------";
                break;
            }
        }
        if(flag==1)
        {
            cout<<endl<<"employee ID OK";
            cout<<endl<<"Enter Month";
            cin>>month;
            cout<<endl<<"Enter Year";
            cin>>year;
            cout<<"Enter Date of Salary";
            cin>>date;
            cout<<"Enter Holidays";
            cin>>holidays;
            if(holidays>empobj.holidays_allowed)
            {
                int diff=holidays-empobj.holidays_allowed;
                float perday_salary=empobj.salary/30.0;
                amount_given=perday_salary*(30-diff);
            }
            else
            {
                amount_given=empobj.salary;
            }
            cout<<endl<<"Net Salary to be disbursed"<<amount_given;
        }
        else
        {
            cout<<endl<<"Employee ID Not OK";
        }

    }

}salobj;

int get_file_emp()
{
    fstream rd;
    rd.open("employees.txt",ios::in);
    rd.seekg(0,ios::end);
    int p=rd.tellg()/sizeof(empobj);
    rd.close();
    return p;
}
void add_employee()
{
    fstream wr;
    wr.open("employees.txt",ios::app);
    empobj.accept();
    wr.write((char *)&empobj,sizeof(empobj));
    wr.close();
    cout<<endl<<"Object Created successfully";
}
void display()
{
    fstream rd;
    rd.open("employees.txt",ios::in);
    rd.seekg(0,ios::end);
    int p=rd.tellg()/sizeof(empobj); // p will have number of objects
    rd.seekg(0,ios::beg);
     cout<<endl;
        cout<<setw(12);
        cout<<"EMPID";
        cout<<setw(50);
        cout<<"NAME";
        cout<<setw(25);
        cout<<"Designation";
        cout<<setw(8);
        cout<<"salary";
        cout<<"\t\t";
        cout<<"holidays_allowed";
        cout<<endl<<"-------------------------------------------------------------------";
    for(int i=1;i<=p;i++)
    {
        rd.read((char *)&empobj,sizeof(empobj));
        empobj.show_data();
    }
    cout<<endl<<"---------------------------------------------------------------------";
    rd.close();
}


void search()
{
    int eid;
    cout<<endl<<"Enter Employee ID";
    cin>>eid;
    int count=get_file_emp();
    fstream rd;
    rd.open("employees.txt",ios::in);
    for(int i=1;i<=count;i++)
    {
        rd.read((char *)&empobj,sizeof(empobj));
        if(empobj.empid==eid)
        {
            empobj.show_data();
        }
    }
}

void remove_employee()
{
    int eid;
    cout<<endl<<"Enter Employee ID";
    cin>>eid;
    int count=get_file_emp();
    fstream rd,wr;
    rd.open("employees.txt",ios::in);
    wr.open("temp.txt",ios::out);
    for(int i=1;i<=count;i++)
    {
        rd.read((char *)&empobj,sizeof(empobj));
        if(empobj.empid==eid)
        {
            cout<<endl<<"Object Removed";
        }
        else
        {
            wr.write((char *)&empobj,sizeof(empobj));
        }
    }
    wr.close();
    rd.close();
    remove("employees.txt");
    rename("temp.txt","employees.txt");
}

void give_salary()
{
    fstream wr;
    wr.open("salary.txt",ios::app);
    salobj.new_salary();
    wr.write((char *)&salobj,sizeof(salobj));
    cout<<endl<<"Salary Disbursement successful";
}

void show_salary()
{
    char month[20],year[20];
    cout<<endl<<"Enter Month";
    cin>>month;
    cout<<endl<<"Enter Year";
    cin>>year;
    fstream rd;
    rd.open("salary.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(salobj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=size;i++)
    {
        rd.read((char *)&salobj,sizeof(salobj));
        if(strcmp(salobj.month,month)==0 && strcmp(salobj.year,year)==0)
        {
            salobj.display();
        }
    }
}

int main()
{
    while(1)
    {
        cout<<endl<<"Press 1 to Add New Employee";
        cout<<endl<<"Press 2 to View All Employees";
        cout<<endl<<"Press 3 to Search All Employees";
        cout<<endl<<"Press 4 to Remove Record";
        cout<<endl<<"Press 5 to Disburse Salary";
        cout<<endl<<"Press 6 to Check Monthly Salary Report";
        cout<<endl<<"Press 8 to exit";

        int choice;
        cin>>choice;
        if(choice==1)
        {
            add_employee();
        }
        else if(choice==2)
        {
            display();
        }
        else if(choice==3)
        {
            search();
        }
        else if(choice==4)
        {
            remove_employee();
        }
        else if(choice==5)
        {
            give_salary();
        }
        else if(choice==6)
        {
            show_salary();
        }
        else
        {
            break;
        }
    }
}



