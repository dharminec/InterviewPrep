#include <string>
using namespace std;

template <class T>
struct node {
    T data;
    struct node *next;
};

template <class T>
class Stack {
private:
      int top;
      int capacity;
      T *storage;
public:
      Stack(int);
      Stack(const Stack &);
      void push(T value) {
            if (top == capacity)
                  throw string("Stack's underlying storage is overflow");
            top++;
            storage[top] = value;
      }

      T peek() {
            if (top == -1)
                  throw string("Stack is empty");
            return storage[top];
      }

      void pop() {
            if (top == -1)
                  throw string("Stack is empty");
            top--;
      }

      bool isEmpty() {
            return (top == -1);
      }

      ~Stack() {
            delete[] storage;
      }
};

template <class T>
Stack<T>::Stack(int capacity)
{
    if (capacity <= 0)
    throw string("Stack's capacity must be positive");
    storage = new T[capacity];
    this->capacity = capacity;
    top = -1;
}

template<class T>
Stack<T>::Stack(const Stack<T> &Obj)
{
    capacity = Obj.capacity;
    top = Obj.top;
    storage = new T[capacity];

    for(int i=0;i<capacity;i++)
        storage[i] = Obj.storage[i];
}
int main()
{
    Stack<int> Sint(20);
    Stack<struct node<float> *> SNode(20);

    struct node<float> *temp= NULL;
    struct node<int> *temp1= NULL;
    SNode.push(temp);

    return 0;
}
