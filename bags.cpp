// Author: Andy Yang
// Author: Manvinder Sodhi

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "StackLi.h"
#include "QueueAr.h"

using namespace std;

typedef Queue<short> container;
typedef StackLi<container> containerStack;

int main(int argc, char *argv[])
{
  ifstream inf(argv[1]);
  int size = atoi(argv[2]);
  containerStack cStack;

  short bag;
  container *currentContainer = new container(size);	// set container size

  while (inf >> bag)
  {
    if (currentContainer->isFull())	// is full
    {
      container out(*currentContainer);
      cStack.push(out);	// add to stack
      delete currentContainer;
      currentContainer = new container(size);
    }

    if (!currentContainer->isFull())
    {
      currentContainer->enqueue(bag);
    }
  }  // while all bags

  cStack.push(*currentContainer);

  while (!cStack.isEmpty())
  {
    container unloaded = cStack.topAndPop();	// get and remove top container

    while (!unloaded.isEmpty())
      cout << unloaded.dequeue() << " ";
  }  // while there are more containers

  cout << endl;

   return 0;
}  // main()
