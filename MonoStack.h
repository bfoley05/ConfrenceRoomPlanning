#ifndef MONOSTACK_H
#define MONOSTACK_H

#include<iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

template <class T>
class MonoStack{
public:
    int counter = 0;
    double* canSee;

    MonoStack();
    MonoStack(int maxSize, char stackType);
    ~MonoStack();

    void push(T data);
    T pop();
    T peek();
    int getSize();
    bool isEmpty();
    bool isFull();

private:
    void decreasingStack(T data);
    void increasingStack(T data);

    int top;
    int mSize;
    T *myArray;
    char o;
};

template <class T>
MonoStack<T>::MonoStack(){
    mSize = 64;
    top = -1;
    myArray = new T[mSize];
    canSee = new double[mSize];
    std::fill_n(canSee, mSize, 0.0);
    o = 'd';
}

template <class T>
MonoStack<T>::MonoStack(int maxSize, char stackType){
    mSize = maxSize;
    top = -1;
    myArray = new T[mSize];
    canSee = new double[mSize];
    std::fill_n(canSee, mSize, 0.0);
    o = stackType;
}

template <class T>
MonoStack<T>::~MonoStack(){
    delete[] myArray;
    delete[] canSee;
}

template <class T>
void MonoStack<T>::decreasingStack(T data){
    int pos = 0;
    T *temp = new T[mSize];
    T dataToTransfer;
    while(!isEmpty() && peek() <= data){
        if(peek() == data){
            throw runtime_error("Cannot have duplicate values");
        }
        dataToTransfer = pop();
        temp[pos] = dataToTransfer;
        pos++;
    }
    if(isEmpty()){
        canSee[counter] = data;
        counter++;
    }
    top++;
    myArray[top] = data;
    for(int i = pos-1; i >= 0; --i){
        top++;
        myArray[top] = temp[i];
    }
    delete[] temp;
}

template <class T>
void MonoStack<T>::increasingStack(T data){
    int pos = 0;
    T *temp = new T[mSize];
    T dataToTransfer;
    while(!isEmpty() && peek() >= data){
        if(peek() == data){
            throw runtime_error("Cannot have duplicate values");
        }
        dataToTransfer = pop();
        temp[pos] = dataToTransfer;
        pos++;
    }
    if(pos == 0){
        canSee[counter] = data;
        counter++;
    }
    top++;
    myArray[top] = data;
    for(int i = pos-1; i >= 0; --i){
        top++;
        myArray[top] = temp[i];
    }
    delete[] temp;
}

template <class T>
void MonoStack<T>::push(T data){
    if(isFull()){
        T *temp = new T[2*mSize];
        for(int i = 0; i < mSize; ++i){
            temp[i] = myArray[i];
        }
        mSize *= 2;
        delete[] myArray;
        myArray = temp;
    }
    if(o == 'i' && !isEmpty()){
        increasingStack(data);
    }
    if(o == 'd' && !isEmpty()){
        decreasingStack(data);
    }
    if(isEmpty()){
        canSee[counter] = data;
        counter++;
        top++;
        myArray[top] = data;
    }

}

template <class T>
T MonoStack<T>::pop(){
    if(isEmpty()){
        throw runtime_error("Stack is empty");
    }
    return myArray[top--];
}

template <class T>
T MonoStack<T>::peek(){
    if(isEmpty()){
        throw runtime_error("Stack is empty");
    }
    return myArray[top];
}

template <class T>
int MonoStack<T>::getSize(){
    return top + 1;
}

template <class T>
bool MonoStack<T>::isEmpty(){
    return (top == -1);
}

template <class T>
bool MonoStack<T>::isFull(){
    return (top == mSize - 1);
}

#endif
