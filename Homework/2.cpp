#include<iostream>
#include <string>
using namespace std;

/* 请在这里填写答案 */
class Student {
protected:
	string name;
	string number;
public:
	Student(string num, string n) {
		number = num;
		name = n;
	}
	virtual void display() = 0;
	virtual double average() = 0;
	static double max;
};
double Student::max = 0;

class GroupA :public Student {
protected:
	int subject1, subject2;
public:
	GroupA(string num, string n, int s1, int s2) :Student(num, n) 
	{
		subject1 = s1;
		subject2 = s2;
	if (average() >= Student::max) 
		{
			Student::max = average();
		}
	}
	virtual double average() 
	{
		return (subject1 + subject2) / 2;
	}
	virtual void display() 
	{
		if (average() == Student::max) 
		{
			cout << number << " " << name << endl;
		}
	}
};
 
class GroupB :public Student {
protected:
	int subject1, subject2;
	char games;
public:
	GroupB(string num, string n, int s1, int s2, char gs) :Student(num, n) 
	{
		subject1 = s1;
		subject2 = s2;
		games = gs;
 
		if (average() >= Student::max) 
		{
			Student::max = average();
		}
	}
	virtual double average() 
	{
		return (subject1 + subject2) / 2;
	}
	virtual void display() 
	{
		if (average() >= (Student::max*0.7) && games == 'A') 
		{
			cout << number <<" "<<name << endl;
		}
		else if (average() == Student::max) 
		{   
			cout << number << " " << name << endl;
		}
	}
};
 
class GroupC :public Student {
protected:
	int subject1, subject2, subject3, subject4, subject5;
public:
	GroupC(string num, string n, int s1, int s2, int s3, int s4, int s5) :Student(num, n) 
	{
		subject1 = s1;
		subject2 = s2;
		subject3 = s3;
		subject4 = s4;
		subject5 = s5;
	}
	virtual double average() 
	{
		return (subject1 + subject2 + subject3 + subject4 + subject5) / 5;
	}
	virtual void display() 
	{
		if (average() >= Student::max*0.9)
		{
			cout << number << " " << name << endl;
		}
	}
};

int main()
{
    const int Size=50;
    string num, name;
    int i,ty,s1,s2,s3,s4,s5;
    char gs;
    Student *pS[Size];
    int count=0;
    for(i=0;i<Size;i++){
        cin>>ty;
        if(ty==0) break;
        cin>>num>>name>>s1>>s2;
        switch(ty){
             case 1:pS[count++]=new GroupA(num, name, s1, s2); break;
             case 2:cin>>gs; pS[count++]=new GroupB(num, name, s1,s2, gs); break;
             case 3:cin>>s3>>s4>>s5; pS[count++]=new GroupC(num, name, s1,s2,s3,s4,s5); break;
        }			
    }
    for(i=0;i<count;i++) {
        pS[i]->display();
        delete pS[i];
    }
    return 0;
}