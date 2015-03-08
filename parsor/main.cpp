//
//  main.cpp
//  parsor
//
//  Created by hambarkh on 24/02/15.
//  Copyright (c) 2015 Akola. All rights reserved.
//

#include <iostream>
#include <string.h>
#include "person.h"
#include "start.h"

#define MAX_TOKEN_NO 20
using namespace std;


char xml[] = "<person><name=\"shahaji\"/><age=\"56\"/><person><name=\"shivaji\"/><age=\"28\"/></person><person><name=\"sambhaji\"/><age=\"20\"/></person></person>";
string token[MAX_TOKEN_NO];

void traverse(char* a);
void printTokens();
int token_number = 0;
extern void printPerson();
extern void printMap();

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!!!\n" << xml << endl;
    traverse(xml);
    printTokens();
    printMap();
    return 0;
}

void printTokens()
{
    int i;
    for (i=0; i<token_number; i++) {
        cout << token[i] << endl;
    }
}

void traverse(char *aInXml)
{
    unsigned long int i,i2,i3,i4,t;
    string lXml = aInXml;
    i = lXml.find('<');
    person *lPerson = NULL;
    while (i!=string::npos) ///what is this!!!
    {
        
        i2 = lXml.find("/>");
        i3 = lXml.find(">");
        i4 = lXml.find("</");
        

        //cout << "i2 = " << i2 << " i3 = " <<i3 << " i4 = "<<i4 << endl;
        if (i4 == i) {
            //end of person object
            token[token_number].assign(lXml,i,i3+1);
            //cout << "size = " << lXml.size() <<endl;
            lXml = lXml.assign(lXml,i3+1-i,lXml.size()-i3+i-1);
            //cout << "token i4 = "<< token[token_number]<<endl;
            token_number++;
        }
        else if (i3<i2) {
            // end of person tag
            token[token_number].assign(lXml,i,i3+i+1);
            t = i3;
            cout << "token i3 = "<< token[token_number]<<endl;
            token_number++;
            //Push old person into map and stack
            if (lPerson != NULL) {
                people.insert(pair<string, person>(lPerson->getName(),*lPerson));
                delete lPerson;
                lPerson = NULL;
            }
            
            lXml = lXml.assign(lXml,t+i+1,lXml.size()-t-i-1);
        }
        else{
            // end of property
            token[token_number].assign(lXml,i,i2+i+2);
            t = i2;
            cout << "token i2 = " << token[token_number] << endl;
            token_number++;
            lXml = lXml.assign(lXml,t+i+2,lXml.size()-t-i-2);
            //create person object
            if (lPerson == NULL)
            {
                cout << "person = NULL" << endl;
                lPerson = new person;
            }
            // Update property
            updateProperty(lPerson,token[token_number-1]);
        }
        
        
        //cout << "hitesh i = " << i << " i2 = " << i2 << " i3 = " << i3 << token[token_number-1] << endl;
        cout << "lXml = "<<lXml << endl << endl ;
        
        i = lXml.find('<');
      
        //cout << "i = " << i << endl << endl;
    }
    if (lPerson != NULL) {
        people.insert(pair<string, person>(lPerson->getName(),*lPerson));
        delete lPerson;
        lPerson = NULL;
    }
    //All are put in MAP
    //Look into Map
    
}
