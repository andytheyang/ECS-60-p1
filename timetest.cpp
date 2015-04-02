// Author: Andy Yang

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


int main()
{
  cout << "Filename >> ";
  char *filename;
  cin >> filename;
  ifstream ifs(filename);

  ifs.ignore(2560, '\n');	// ignore first comment line

  int input;
  do
  {
    cout << endl
         << "      ADT Menu" << endl
         << "0. Quit" << endl
         << "1. LinkedList" << endl
         << "2. CursorList" << endl
         << "3. StackAr" << endl
         << "4. StackLi" << endl
         << "5. QueueAr" << endl
         << "6. SkipList" << endl
         << "Your Choice >> ";
    cin >> input;

    if (input < 0 || input > 6)
      cout << "Your choice is not between 1 and 6." << endl
           << "Please try again." << endl;

  } while (input);  // while input != 0

  ifs.close();		// close filestream

  return 0;
}
