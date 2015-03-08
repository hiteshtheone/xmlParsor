//
//  person.h
//  parsor
//
//  Created by hambarkh on 06/03/15.
//  Copyright (c) 2015 Akola. All rights reserved.
//

#ifndef parsor_person_h
#define parsor_person_h


#endif

#include <stdio.h>
#include <string>
#include <list>
#include <map>


using namespace std;

class person {
    string name;
    int age;
    list<person> kidsList;
    
public:
    string getName()
    {
        return name;
    }
    void setName(string aInName)
    {
        name = aInName;
    }
    int getAge()
    {
        return age;
    }
    void setAge(int aInAge)
    {
        age = aInAge;
    }
    ~person()
    {
        cout << "Person Name = " << name << " Age = " << age << endl;
    }
};

map<string,person> people;

void printPerson()
{
    cout << "in printPerson" << endl;
}

void getProperty(string const aInToken, string &aInVariable, string &aInValue)
{
    unsigned long i = aInToken.find("=");
    aInVariable.assign(aInToken,1,i-1);
    aInValue.assign(aInToken, i+2, aInToken.size()-i-5);
    //cout << "........variable= "<< aInVariable << " Value= " << aInValue << endl;
}

string ppl[] = {"shahaji","shivaji","sambhaji"};

void printMap()
{
    int i;
    map<string,person>::iterator p;
    for (i=0 ; i<3;i++)
    {
        p = people.find(ppl[i]);
        if (p != people.end())
        {
            cout << "Name and Age = " << p->second.getName() << " and  " << p->second.getAge() << endl;
        }
    }
}

void updateProperty(person *aInPerson, string aInToken)
{
    string lVariable,lValue;
    getProperty(aInToken,lVariable,lValue);
    cout << lVariable << " = variable, value = " << lValue << endl;
    if (lVariable== "name") {
        
        aInPerson->setName(lValue);
        //cout << "Person name is "<< aInPerson.getName() << endl;
    }
    else if (lVariable == "age")
    {
        int lVariable_int;
        string::size_type sz;
        try {
            lVariable_int = stoi(lValue,&sz);
        } catch (const std::invalid_argument& ia) {
            std::cerr << "Invalid Age: " << ia.what() << '\n';
            aInPerson->setAge(0);
            return;
        }
        
        aInPerson->setAge(lVariable_int);
        //cout << "Person age = " << aInPerson.getAge() << endl;
    }
}
