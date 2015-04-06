// Author: Andy Yang
// Author: Manu Sodhi

#include <iostream>
#include <fstream>
#include "StackAr.h"

using namespace std;

void printError(char *bracket, int line)
{
  cout << "Unmatched " << *bracket << " on line #" << line << endl;
}

int main(int argc, char *argv[])
{
  ifstream inf(argv[1]);
  StackAr<char> stack;
  char next;
  bool ignore = false;
  int curLine = 1, lastLine = 1;

  while (inf >> next)
  {
/*
    if (next == '/' && inf.peek() == '*')	// is a comment
    {
      ignore = true;
      stack.push(next);
      inf >> next;			// to ignore the *
      continue;
    }  // if comment

    if (next == '*' && inf.peek() == '/')	// is close comment
      

    if (ignore)
      continue;
*/
    if (next == '{' || next == '(' || next == '[')
    {
      lastLine = curLine;
      stack.push(next);
    }
    else if (next == '}' || next == ')' || next == ']')
    {
      lastLine = curLine;
      char previous = stack.topAndPop();	// get previous bracket
      // deal with null
      switch(next)
      {
        case '}' : if (previous != '{') {printError(&next, curLine); return 1;} break;
        case ')' : if (previous != '(') {printError(&next, curLine); return 1;} break;
        case ']' : if (previous != '[') {printError(&next, curLine); return 1;} break;
      }
    }

    if (inf.peek() == '\n')
      curLine++;
  }

  inf.close();

  if (!stack.isEmpty())
  {
    char previous = stack.topAndPop();
    printError(&previous, lastLine);
    return 1;
  }

  cout << "OK" << endl;
  return 0;
}  // main()
