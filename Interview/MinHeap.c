#include <iostream>
using namespace std;
#define Max  1000

class MinHeap{
    int capacity;
    int *HArray;
    int size;
    public:
    MinHeap (int cap);
    int parentindex (int i) {return (i-1) /2 ;}
    int Leftchildindex (int i) {return (2*i +1) ;}
    int Rightchildindex (int i) {return (2*i + 2); }
    bool HasLeftChild (int index) {return  Leftchildindex(index) < size;}
    bool HasRightChild (int index) {return Rightchildindex(index) < size;}
    bool HasParent (int index) {return parentindex(index) >= 0;}
    
    int Leftchild (int index) {return HArray[Leftchildindex(index)];}
    int Rightchild (int index) {return HArray[Rightchildindex(index)];}
    int parent (int index) {return HArray[parentindex(index)];}
    
    void HeapifyUp();
    void HeapifyDown();
    void printHarry()
    {
        for(int i=0; i< size;i++)
            cout << HArray[i]<<" ";
    }
    
    void insert(int key);
    void extractMin();
};

void MinHeap :: extractMin()
{
    if(size <= 0){
        cout << "Heap is empty" ;   
        return;
    }
        
    cout << HArray[0]<<endl;
    HArray[0] = HArray[size -1];
    size--;
    HeapifyDown();
    
}
void MinHeap :: insert(int key)
{
    if(size >= capacity)
    {
        cout << "Heap is full";
        return ;
    }
    
    HArray[size] = key;
    size++;
    HeapifyUp();
}

MinHeap ::MinHeap(int cap)
{
    capacity = cap;
    HArray = new int[capacity];
    size = 0;
}


void MinHeap :: HeapifyUp()
{
    int index = size -1;
    while(HasParent(index) && HArray[parentindex(index)] > HArray[index]){
        swap(HArray[index], HArray[parentindex(index)]);
        index = parentindex(index);
    }
} 

void MinHeap :: HeapifyDown()
{
    int smallestidex = 1;
    int index = 0;
    while(HasLeftChild(index))
    {
        smallestidex = Leftchildindex(index);
        if(HasRightChild(index) && (Rightchild(index) < Leftchild(index)))
            smallestidex = Rightchildindex(index);
         if(HArray[index] < HArray[smallestidex])
                return;
        swap(HArray[index] ,HArray[smallestidex]);
        index = smallestidex;
    }
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a =*b;
    *b = temp;
}
 

#define Heapsize 10
int main()
{
    MinHeap H(Heapsize);
    H.insert(1);
    H.insert(60);
    H.insert(15);
    H.insert(100);
    H.insert(0);
    H.insert(6);
    H.extractMin();
    H.extractMin();
    H.extractMin();
    H.extractMin();
    H.extractMin();
    H.extractMin();
    H.extractMin();
    H.extractMin();
    H.printHarry();
    return 0;
}
