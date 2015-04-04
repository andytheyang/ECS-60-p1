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
    
    char character, num[250000];
    int value;
    
    List <int> list;
    ListItr <int> iter = list.zeroth();
    ifstream inf(filename);
    inf.getline(num, 250000);
    inf.ignore(2560, '\n');
    while(inf>>character>>value){
        if(character == 'i')
            list.insert(value, iter);
        else
            list.remove(value);
    }
    inf.close();
}

void RunCursorList(char *filename) {
    ifstream inf(filename);
}

void RunStackAr(char *filename) {
    ifstream inf(filename);
}

void RunStackLi(char *filename) {
    //    StackLi <int> list;
    //    ifstream inf(filename);
    //    char character, num;
    //    int value;
    //    while(inf>>character>>num){
    //        list.push(num);
    //        if(character == 'i')
    //            list.push(num);
    //        else
    //            list.pop();
    //    }
    //    for(int i=0;i<250000;i++){
    //
    //        list.pop();
    //    }
    
}

void RunQueueAr(char *filename) {
    ifstream inf(filename);
}

void RunSkipList(char *filename) {
    
    char character, num[250000];
    int value;
    
    SkipList<int> list(250000);
    ifstream inf(filename);
    inf.getline(num, 250000);
    inf.ignore(2560, '\n');
    while(inf>>character>>value){
        if(character == 'i')
            list.insert(value);
        else
            list.deleteNode(value);
    }
    inf.close();
    
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

