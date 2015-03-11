//
//  main.cpp
//  parsor
//
//  Created by hambarkh on 24/02/15.
//  Copyright (c) 2015 Akola. All rights reserved.
//

#include <iostream>
#include <string.h>
#include "start.h"
#include "person.h"
#include "tokenize.h"
#include "stackify.h"

using namespace std;


void traverse(char *a);
void stackify();
extern void printMap();

int main(int argc, const char * argv[]) {
    traverse(xml); //tokenize
    printMap();
    stackify();
    cout << "calling destructors" << endl << endl;
    return 0;
}
