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

#endif


