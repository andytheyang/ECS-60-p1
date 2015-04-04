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

int main()
{
    cout << "Filename >> ";
    char filename[10];
    int input;
    cin >> filename;
    CPUTimer ct;
    
    //Display the initial menu/
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
    
    //While and if statements if the input isn't correct.
    while(input < 0 || input > 6){
        if (input<0 || input > 6) {
            cout << "Your choice is not between 1 and 6." << endl;
            cout<< "Please try again." << endl;
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
        }
    }
    
    if (input > 0){
        ct.reset();
        switch (input)
        {
            case 1: RunList(filename); break;
            case 2: RunCursorList(filename); break;
            case 3: RunStackAr(filename); break;
            case 4: RunStackLi(filename); break;
            case 5: RunQueueAr(filename); break;
            case 6: RunSkipList(filename); break;
        }
        cout << "CPU time: " << ct.cur_CPUTime() << endl;
    }
    else{
        cout << "CPU time: " << 0 << endl;
    }
    return 0;
}

