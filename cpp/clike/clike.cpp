#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;

class Cat
{
public:
    Cat(){}
    string name;
};

int main()
{
    printf("Hello, world!");
    Cat cat;
    cat.name = "Tom";
    cout << cat.name;
}

