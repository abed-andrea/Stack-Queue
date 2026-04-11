#include <iostream>


class Node {
    private:
        int value;
        Node* next;

    public:
        Node(int value){
            this->value = value;
            next = nullptr;
        }

        int getValue(){
            return value;
        }

        void setValue(int value){
            this->value = value;
        }

        Node* getNext(){
            return next;
        }

        void setNext(Node* next){
            this->next = next;
        }
};


class LLStack {
    private:
        Node* top; //pointer to a node object
        int stack_size;
    
    public:
        LLStack(){
            top = nullptr; //doesn't point to anything when stack is initialized
            stack_size = 0;
        }

        ~LLStack(){
            //std::cout << "Destroying Stack";
            while (top!=nullptr){
                Node* temp = top;
                top = top->getNext();
                //std::cout << "Popping " << temp->getValue() << "\n";
                delete temp;
            }
        }

        bool isEmpty(){
            return stack_size == 0;
        }

        int peek(){
            if (isEmpty()){
                std::cout << "Stack is empty. Nothing to peek";
                return -1;
            }
            else{
                return top->getValue();
            }
        }

        void push(int value){
            Node* new_node = new Node(value); //actually allocate memory for a node
            
            new_node->setNext(top); //it will point to the current top
            
            top = new_node; //then top will point to the actual top (aka the newly added element)
            
            stack_size++;
        }

        int pop(){

            if (isEmpty()){
                throw std::runtime_error("Stack is empty");
            }

            Node* temp = top; // hold temporary pointer to the top
        
            int value = temp->getValue(); // hold the value to return
           
            top = top->getNext(); // the new top becomes what was below it

            delete temp; // free the momory, do not need temp = nullptr because temp will be destroyed after function ends anyways

            stack_size--;

            return value;
        }

        int getStackSize(){
            return stack_size;
        }

        Node* getTop(){
            return top;
        }

};


class StackQueue {
    private:
        LLStack enqueueStack; //enqueue stack -- structure that simply holds pointer to top node, and integer for stack size
        LLStack dequeueStack; //dequeue stack
    
    public:
        StackQueue(){
            // enqueue and dequeue stacks already intialzied/constructors called
        }

        bool isEmpty(){
            return enqueueStack.isEmpty() && dequeueStack.isEmpty();
        }

        int getSize(){
            return enqueueStack.getStackSize() + dequeueStack.getStackSize();
        }

        void enqueue(int value){
            enqueueStack.push(value);
        }


        int dequeue(){
            // if entire queue is empty
            if (isEmpty()){
                throw std::runtime_error("Queue is empty");
            }

            // if dequeue stack is empty, pop everything from enqueue and push to dequeue
            if (dequeueStack.isEmpty()){
                while (!enqueueStack.isEmpty()){
                    int value = enqueueStack.pop();
                    dequeueStack.push(value);
                }
            }

            // pop from dequeue stack
            return dequeueStack.pop();
        }

        int peek(){
            // if entire queue is empty
            if (isEmpty()){
                throw std::runtime_error("Queue is empty");
            }

            // if dequeue stack is empty, pop everything from enqueue and push to dequeue
            if (dequeueStack.isEmpty()){
                while (!enqueueStack.isEmpty()){
                    int value = enqueueStack.pop();
                    dequeueStack.push(value);
                }
            }

            return dequeueStack.peek();
        }

        void displayQueue(){

            if (isEmpty()){
                std::cout << "Queue is empty";
                return;
            }

            // if there are elements in the dequeue stack, print those first
            if (!dequeueStack.isEmpty()){
                Node* temp = dequeueStack.getTop();
                while (temp != nullptr){
                    std::cout << temp->getValue() << " ";
                    temp = temp->getNext();
                }
            }

            // if there are elements in the enqueue stack, reverse the order using temporary stack, then print the values like the dequeue stack
            if (!enqueueStack.isEmpty()){

                LLStack tempStack; 
                Node* temp = enqueueStack.getTop();

                while (temp != nullptr){
                    tempStack.push(temp->getValue());
                    temp = temp->getNext();
                }

                temp = tempStack.getTop(); // now temp points to reversed enqueue stack

                while (temp != nullptr){
                    std::cout << temp->getValue() << " ";
                    temp = temp->getNext();
                }

            }
        }

};




int main(){

    int selection = 0;
    int value;

    StackQueue queue; // initialize queue

    while(selection != 6){
    std::cout << "\n\n-------------------------------------\n\n";
		std::cout << "STACK QUEUE PROGRAM\n\n";
		std::cout << "Choose from the following: \n\n";
		std::cout << "1. Enqueue\n";
		std::cout << "2. Dequeue\n";
		std::cout << "3. Peek\n";
        std::cout << "4. Display size\n";
		std::cout << "5. Display the queue\n";
		std::cout << "6. Exit\n";

		std::cin >> selection;

    if (selection < 1 || selection > 6){
      std::cout << "\nNot a valid selection. Please select a number from 1 - 6.\n";
      continue;
    }

    switch(selection){

      case 1:
        {
            std::cout<< "\nPlease enter the value you would like to enqueue.\n\n";
		    std::cin >> value;
            queue.enqueue(value);
        }
      break;

      case 2:
        {
            std::cout<< "\nYou have chosen to dequeue.\n\n";
            try{
                std::cout << "Element dequeued: " << queue.dequeue() << "\n\n";
            }
            catch(std::runtime_error& e){
                std::cout << e.what() << "\n\n";
            }
        }
      break;

      case 3:
        {
            std::cout<< "\nYou have chosen to peek.\n\n";
            try{
                std::cout << "Element peeked: " << queue.peek() << "\n\n";
            }
            catch(std::runtime_error& e){
                std::cout << e.what() << "\n\n";
            }
        }
      break;

      case 4:
        {
            std::cout<< "\nThe queue has " << queue.getSize() << " elements\n";
        }
      break;

      case 5:
        {
            std::cout<< "\nQueue:   ";
            queue.displayQueue();
        }
      break;

      case 6:
        {
            std::cout<< "You have now exited.\n\n";
        }
      break;
    }
    }

    return 0;
}
