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
    
    char character;
    int value;

    List <int> list;
    ListItr <int> iter = list.zeroth();
    ifstream inf(filename);
    inf.ignore(2560, '\n');
//    inf.getline(num, 250000);
    
    while(inf >> character >> value){
        if(character == 'i')
            list.insert(value, iter);
        else
            list.remove(value);
        list.first();
    }
    inf.close();
}

void RunCursorList(char *filename) {

    ifstream inf(filename);
    inf.ignore(2560, '\n');
    char character;
    int value;

    CursorList<int> list(cursorSpace);
    CursorListItr<int> iter = list.zeroth();

    while (inf >> character >> value)
    {
        if(character == 'i')
           list.insert(value, iter);
        else
           list.remove(value);
    }

    inf.close();
}

void RunStackAr(char *filename) {
    ifstream inf(filename);
    inf.ignore(2560, '\n');
    char character;
    int value;

    StackAr<int> list(250000);

    while (inf >> character >> value)
    {
        if(character == 'i')
           list.push(value);
        else
           list.pop();
    }

    inf.close();
}

void RunStackLi(char *filename) {
        StackLi <int> list;
        ifstream inf(filename);
        inf.ignore(2560, '\n');
        char character;
        int value;

        while(inf >> character >> value){
            if(character == 'i')
               list.push(value);
            else
               list.pop();
        }

        inf.close(); 
}

void RunQueueAr(char *filename) {
        Queue<int> que(250000);
        ifstream inf(filename);
        inf.ignore(2560, '\n');

        char character;
        int value;

        while(inf >> character >> value){
            if(character == 'i')
               que.enqueue(value);
            else
               que.dequeue();
        }

        inf.close(); 

}

void RunSkipList(char *filename) {
    
    char character;
    int value;
    
    SkipList<int> list(1, 250000);	// what's going on??
    ifstream inf(filename);
    inf.ignore(2560, '\n');

    while(inf >> character >> value){
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
    cout<< "      ADT Menu" << endl;
    cout<< "0. Quit" << endl;
    cout<< "1. LinkedList" << endl;
    cout<< "2. CursorList" << endl;
    cout<< "3. StackAr" << endl;
    cout<< "4. StackLi" << endl;
    cout<< "5. QueueAr" << endl;
    cout<< "6. SkipList" << endl;
    cout<< "Your Choice >> ";
    cin >> input;

    if (input < 0 || input > 6)
    {
      cout << "Your choice is not between 1 and 6." << endl
           << "Please try again." << endl;
      return getChoice();
    }

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

