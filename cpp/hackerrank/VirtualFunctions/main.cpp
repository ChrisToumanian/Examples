#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
public:
    char* name;
    int age;

    Person()
    {
    }

	virtual void getdata();
    virtual void putdata();
};

class Professor : Person
{
public:
    int publications;
    int cur_id;

    Professor()
    {
    }

    void getdata()
    {
		cin >> name >> age >> publications;
    }

    void putdata()
    {
		cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }
};

class Student : Person
{
public:
    int marks[6];
    int cur_id;

    Student()
    {
    }

    void getdata()
    {

    }

    void putdata()
    {

    }
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
