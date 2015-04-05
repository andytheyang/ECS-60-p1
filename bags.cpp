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
  container currentContainer(size);	// set container size

  while (inf >> bag)
  {
    if (!currentContainer.isFull())	// if space
    {
      currentContainer.enqueue(bag);
    }
    else
    {
      cStack.push(currentContainer);	// add to stack
      // make a new container
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
