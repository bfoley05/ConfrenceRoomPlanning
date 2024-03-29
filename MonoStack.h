#ifndef MONOSTACK_H
#define MONOSTACK_H

#include<iostream>
using namespace std;

template <class T>
class MonoStack{
    public:
        int counter;
        double* canSee;

        MonoStack(){
            mSize = 64;
            top = -1;
            myArray = new T[mSize];
            canSee = new double[mSize];
            std::fill_n(canSee, mSize, 0.0);
            o = 'd';
        };
        MonoStack(int maxSize, char stackType){
            mSize = maxSize;
            top = -1;
            myArray = new T[mSize];
            canSee = new double[mSize];
            std::fill_n(canSee, mSize, 0.0);
            o = stackType;
        };
        ~MonoStack(){
            delete[] myArray;
            delete canSee;
        };

        void decreasingStack(T data){
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
        };

        void increasingStack(T data){
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
        };

        void push(T data){
            if(isFull()){
                T *temp = new T[2*mSize];
                for(int i = 0; i <mSize; ++i){
                    temp[i] = myArray[i];
                }
                mSize *=2;
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
        };

        T pop(){
            if(isEmpty()){
                throw runtime_error("Stack is empty");
            }
            return myArray[top--];
        };
        T peek(){
            if (isEmpty()){
                throw runtime_error("Stack is empty");
            }
            return myArray[top];
        }; //or top

        int getSize(){
            return top+1;
        };
        bool isEmpty(){
            return (top == -1);
        };
        bool isFull(){
            return (top == mSize -1);
        };
    private:
        int top;
        int mSize;
        T *myArray;
        char o;
};


#endif