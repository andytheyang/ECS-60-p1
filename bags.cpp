// Author: Andy Yang
// Author: Manu Sodhi

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "StackAr.h"
#include "QueueAr.h"

using namespace std;

typedef Queue<short> container;
typedef StackAr<container> containerStack;

int main(int argc, char *argv[])
{
  ifstream inf(argv[1]);
  int size = atoi(argv[2]);
  containerStack cStack;

  short bag;
  container *currentContainer = new container(size);	// set container size

  while (inf >> bag)
  {
    if (!currentContainer->isFull())	// if space
    {
      currentContainer->enqueue(bag);
    }
    else
    {
      container out(*currentContainer);
      cStack.push(out);	// add to stack
      delete currentContainer;
      currentContainer = new container(size);
    }
  }  // while all bags

  while (!cStack.isEmpty())
  {
    container unloaded = cStack.topAndPop();	// get and remove top container

    while (!unloaded.isEmpty())
      cout << unloaded.dequeue() << " ";
  }  // while there are more containers

   return 0;
}  // main()
