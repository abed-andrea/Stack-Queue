#include <iostream>
using namespace std;

class Node {
  private:
    int data;
    Node* nextNode;

  public:
    Node(int data){
      this->data = data;
      nextNode = nullptr;
    }

    void setData(int data){
      this->data = data;
    }

    int getData(){
      return data;
    }

    void setNextNode(Node* nextNode){
      this->nextNode = nextNode;
    }

    Node* getNextNode(){
      return nextNode;
    }


};
class LLStack {
  private:
    Node *top;
    int stackSize;

  public:

    LLStack(){
      top = NULL;
      stackSize = 0;
    }
/*
    LLStack(int value) {
    Node *newNode = new Node(value);
    top = newNode;
    stackSize = 1;
  }
*/
  ~LLStack() {
    Node *temp = top;
    while (top) {
      top = top->getNextNode();
      delete temp;
      temp = top;
    }
  }

  void setTop(Node* top){
    this->top = top;
  }

  Node* getTop(){
    return top;
  }

  void setStackSize(int stackSize){
    this->stackSize = stackSize;
  }

  int getStackSize(){
    return stackSize;
  }


  void printStack(LLStack stackToPrint){

    LLStack *extraMemoryStack = new LLStack();

    Node *i = stackToPrint.getTop();
    Node *temp;

    while(i!=nullptr){
      temp = stackToPrint.pop();
      cout << temp->getData() << " ";
      extraMemoryStack->push(temp->getData());
      i = stackToPrint.getTop();
    }

    Node *j = extraMemoryStack->getTop();
    Node *hold;

    while(j!=nullptr){
      hold = extraMemoryStack->pop();
      stackToPrint.push(hold->getData());
      j = extraMemoryStack->getTop();
    }
  }

/*
  void printListTest(){
    Node *temp = top;
    while (temp != nullptr) {
      cout << temp->getData() << " ";
      temp = temp->getNextNode();
    }
  }
*/

  void push(int data) {
    Node *newNode = new Node(data);
    if (stackSize == 0) {
      top = newNode;
    } else {
      newNode->setNextNode(top);
      top = newNode;
    }
    stackSize++;
  }

  Node* pop() {
    if (stackSize == 0)
      cout << "Cannot pop from an empty stack.";
    Node *temp = top;
    if (stackSize == 1) {
      top = nullptr;
    } else {
      top = top->getNextNode();
    }
    stackSize--;

    return temp;
    delete temp;
  }

/*
  void peekStack() {
    if (top == nullptr) {
      cout << "Top: nullptr" << endl;
    } else {
      cout << "Top: " << top->getData() << endl;
    }
  }
*/

  int peek() {
    int elementPeeked;
    if (top == nullptr) {
      cout << "Cannot peek from empty stack" << endl;
      return -1;
    } else {
      elementPeeked = top->getData();
    }
    return elementPeeked;

  }



};

class StackQ {
  // Queue ADT
  //  This is your queue class
  //  Implement queue methods here
  //  Queue methods are given in the Assignment
  //  Queue is implemented by manipulating two stacks.
  //  You will need references to 2 stacks here
private:
LLStack *enQStack;
LLStack *deQStack;
LLStack *enQPrintStorage;

public:

StackQ(){
  enQStack = new LLStack();
  deQStack = new LLStack();
  cout << "Queue confirmed created";
}

~StackQ() {
    enQStack->~LLStack();
    deQStack->~LLStack();
  }

int getQueueSize(){
  return (enQStack->getStackSize() + deQStack->getStackSize());
}


void printEnQStack(){
  if (enQStack->getStackSize() == 0){
    cout<<"empty.\n";
  }
  else{
     enQStack->printStack(*enQStack);
  }
}

void printDeQStack(){
  if (deQStack->getStackSize() == 0){
    cout << "empty.\n";
  }
  else{
    deQStack->printStack(*deQStack);
  }
}

void printQueue(){

  if (deQStack->getStackSize() == 0 && enQStack->getStackSize() == 0){
    cout << "Queue is empty.\n";
    return;
  }
  else{

  deQStack->printStack(*deQStack);

  LLStack *newMemory = new LLStack();
  Node *i = enQStack->getTop();
  Node *temp;

  while(i!=nullptr){
    temp = enQStack->pop();
    newMemory->push(temp->getData());
    i = enQStack->getTop();
  }

  Node *j = newMemory->getTop();
  while(j!=nullptr){
    temp = newMemory->pop();
    cout << temp->getData() << " ";
    enQStack->push(temp->getData());
    j = newMemory->getTop();
  }

  }
}


void enqueue(int data){
  enQStack->push(data);
}


Node* dequeue (){
  Node* i = enQStack->getTop();
  Node* temp;
  Node* elementToReturn;

  if(enQStack->getStackSize() == 0 && deQStack->getStackSize() == 0){
    //cout <<"\nYou cannot dequeue from an empty queue.";
    return NULL;
  }

  //if (deQStack->getHead()!=nullptr)
  if (deQStack->getStackSize()!= 0){
    elementToReturn = deQStack->pop();
    return elementToReturn;
  }

  else{
    while (i!=nullptr){
      temp = enQStack->pop();
      deQStack->push(temp->getData());
      i = enQStack->getTop();
    }

    elementToReturn = deQStack->pop();
    return elementToReturn;
    }
}


int peekQueue(){
  Node* i = enQStack->getTop();
  Node* temp;
  int elementToReturn;

  if (enQStack->getStackSize() == 0 && deQStack->getStackSize() == 0){
    return -1;
  }

  if (deQStack->getStackSize()!= 0){
    elementToReturn = deQStack->peek();
    return elementToReturn;
  }

  while (i!=nullptr){
    temp = enQStack->pop();
    deQStack->push(temp->getData());
    i = enQStack->getTop();
  }

  elementToReturn = deQStack->peek();
  return elementToReturn;
}


};


int main() {


  StackQ *userQueue = new StackQ();

  int selection = 0;

  int userData;

  while(selection != 7){
    cout << "\n-------------------------------------\n";
		cout << "IMPLEMENTED QUEUE PROGRAM\n\n";
		cout << "Choose from the following: \n\n";
		cout << "1. Enqueue in the queue\n";
		cout << "2. Dequeue from the queue\n";
		cout << "3. Peek from the queue\n";
		cout << "4. Display the queue\n";
		cout << "5. Display the enQStack and deQStack\n";
		cout << "6. Display size of the queue\n";
		cout << "7. Exit\n";

		cin >> selection;

    if (selection < 1 || selection > 7){
      cout << "\nNot a valid selection. Please select a number from 1 - 7.";
      continue;
    }

    switch(selection){

      case 1:
        {
          cout<< "Case 1 chosen.\n\n";

          cout<< "For enqueue...\n\n";
          cout << "Please enter your data.\n";

				  cin >> userData;

				  userQueue->enqueue(userData);

          cout << "\nQueue after enqueue action: ";

				  userQueue->printQueue();
				  cout << "\n";
        }
      break;

      case 2:
        {
          cout<< "Case 2 chosen.\n\n";

          cout << "You have chosen to dequeue...\n\n";

          Node *dequeuedElement = userQueue->dequeue();

          if(dequeuedElement == NULL){
            cout << "You cannot dequeue from an empty queue.";
          }
          else{
            cout << "Element dequeued: " << dequeuedElement->getData();
          }

        }
      break;

      case 3:
        {
          cout << "Case 3 chosen.\n\n";

          cout << "You have chosen to peek from the queue...\n\n";

          int peekedElement = userQueue->peekQueue();

          if(peekedElement == -1){
            cout << "Cannot peek from an empty queue";
          }
          else{
            cout << "Element peeked: " << peekedElement;
          }

        }
      break;

      case 4:
        {
          cout << "Case 4 chosen.\n\n";

          cout << "You have chosen to display the queue...";

          cout<< "\n\nQUEUE: ";

          userQueue->printQueue();
        }
      break;

      case 5:
        {
          cout << "Case 5 chosen.\n\n";

          cout << "You have chosen to display the enQStack and deQStack...\n";

          cout<< "\nENQUEUE STACK (top -> bottom): \n";
          userQueue->printEnQStack();

          cout<< "\nDeQUEUE STACK (top -> bottom): \n";
          userQueue->printDeQStack();
        }
      break;

      case 6:
        {
          cout << "Case 6 chosen.\n\n";

          cout << "You have chosen to display the size of the queue...";

          cout<< "\nsize: " << userQueue->getQueueSize();
        }
      break;


      case 7:
		    {
			    cout << "Case 7 chosen.\n\n";

          userQueue->~StackQ();

          cout << "You have now exited.";

				}
			break;

    }

  }

}
