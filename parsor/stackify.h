//
//  stackify.h
//  parsor
//
//  Created by hambarkh on 08/03/15.
//  Copyright (c) 2015 Akola. All rights reserved.
//

#ifndef parsor_stackify_h
#define parsor_stackify_h


#endif
//#include "start.h"

using namespace std;

string stack[MAX_TOKEN_NO];
int top = -1 ;

int push(string aInPersonName)
{
    if (top < MAX_TOKEN_NO)
    {
        top++;
        stack[top] = aInPersonName;
        
        //cout << "Pushing " << stack[top] << endl;
        return true;
    }
    return false;
}

string pop()
{
    if (top > -1){
        //cout << "Popping "<< stack[top] << " top = " << top << endl;
        top--;
        //cout << "Popping "<< stack[top+1] << " top = " << top << endl;
        return stack[top+1];
    }
    return "EMPTY";
}

void updateParent(string aInPersonName)
{
    string lParentName =  pop();
    //person lParent;
    if (lParentName != "EMPTY")
    {
        map<string,person>::iterator p;
        p = people.find(lParentName);
        //cout << "lParentName = " << lParentName << endl;
        //p->second.setAge(99);
        //person lParent = p->second;
        p->second.addKid(aInPersonName);
        //lParent.addKid(aInPersonName);
        //people.insert(pair<string,person>(lParentName,lParent));
        push(p->second.getName());
    }
}

void stackify()
{
    printTokens();
    int i;
    person *lPerson = NULL;
    //cout << "create stack from tokens" << endl;
    //scan through tokens and create perons and people
    for (i=0; i<token_number; i++) {
        cout << "Token = " << token[i] << endl;
        if (token[i] == "<person>") //start of person
        {
            //create person Mo
            lPerson = new person;
        }
        else if (token[i].find("name") != string::npos)
        {
            //update name
            updateProperty(lPerson,token[i]);
        }
        else if(token[i].find("age") != string::npos)
        {
            //update age and update parent and add lPerson to Map
            updateProperty(lPerson,token[i]);
            people.insert(pair<string, person>(lPerson->getName(),*lPerson));
            //update parent
            updateParent(lPerson->getName());
            //update stack
            push(lPerson->getName());
            delete lPerson;
            lPerson = NULL;
        }
        else if (token[i].find("</person>") != string::npos)
        {
            pop();
        }
    }
    
}