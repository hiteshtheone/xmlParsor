//
//  person.h
//  parsor
//
//  Created by hambarkh on 06/03/15.
//  Copyright (c) 2015 Akola. All rights reserved.
//

#ifndef parsor_person_h
#define parsor_person_h

#include <stdio.h>
#include <string>
#include <list>
#include <map>


using namespace std;

class person {
    string name;
    int age;
    list<string> kidsList;
    list<string>::iterator kidsIter;
    
public:
    void addKid(string aInKid)
    {
        cout << "aINkid = " << aInKid << endl;
    
        kidsList.push_back(aInKid);
    }
    person* getKid(string aInKid);
    
    void printKids()
    {
        kidsIter = kidsList.begin();
        cout << "Parent is " << getName() << endl;
        while (kidsIter != kidsList.end()) {
            cout << "Kid = " << *kidsIter << endl;
            kidsIter++;
        }
    }
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
    person operator=(person aInPerson)
    {
        this->setName(aInPerson.getName());
        this->setAge(aInPerson.getAge());
        return *this;
    }
    ~person()
    {
        printKids();
        cout << "Person Name = " << name << " Age = " << age << endl;
    }
};

map<string,person> people;
map<string,person>::iterator peopleIter;

person* person::getKid(string aInKid)
{
    peopleIter = people.find(aInKid);
    if (peopleIter != people.end())
    {
        return &peopleIter->second;
    }
    return NULL;
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

#endif


