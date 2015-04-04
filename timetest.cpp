// Author: Andy Yang
// Author: Manvinder Sodhi
#include <iostream>
#include <fstream>
#include "CPUTimer.h"
#include "dsexceptions.h"
#include "LinkedList.h"
#include "StackAr.h"
#include "CursorList.h"
#include "QueueAr.h"
#include "StackLi.h"
#include "vector.h"
#include "SkipList.h"
vector<CursorNode <int> > cursorSpace(250000);
using namespace std;

void RunList(char *filename) {
    ifstream inf(filename);
    inf.close();
}

void RunCursorList(char *filename) {
    ifstream inf(filename);
}

void RunStackAr(char *filename) {
    ifstream inf(filename);
}

void RunStackLi(char *filename) {
    ifstream inf(filename);
}

void RunQueueAr(char *filename) {
    ifstream inf(filename);
}

void RunSkipList(char *filename) {
    ifstream inf(filename);
}

int getChoice(){
    int input;
    cout << endl;
    cout<< "ADT Menu" << endl;
    cout<< "0. Quit" << endl;
    cout<< "1. LinkedList" << endl;
    cout<< "2. CursorList" << endl;
    cout<< "3. StackAr" << endl;
    cout<< "4. StackLi" << endl;
    cout<< "5. QueueAr" << endl;
    cout<< "6. SkipList" << endl;
    cout<< "Your Choice >> ";
    cin >> input;
    return input;
}

int main()
{
    char filename[10];
    int choice;
    CPUTimer ct;
    
    cout << "Filename >> ";
    cin >> filename;
    
    do
    {
        choice = getChoice();
        ct.reset();
        switch (choice)
        {
            case 1: RunList(filename);       break;
            case 2: RunCursorList(filename); break;
            case 3: RunStackAr(filename);    break;
            case 4: RunStackLi(filename);    break;
            case 5: RunQueueAr(filename);    break;
            case 6: RunSkipList(filename);   break;
        }
        cout << "CPU time: " << ct.cur_CPUTime() << endl;
    } while(choice > 0);
    
    return 0;
}

