#include <iostream>
#include <queue>
#include <exception>

template<typename T> 
class MyStack {
public:
    MyStack();
    ~MyStack();
    void push(const T& data);
    T pop();
private:
    void swapQueue();
private:
    std::queue<T> q1;
    std::queue<T> q2;
};

template<typename T> 
MyStack<T>::MyStack() {

}

template<typename T> 
MyStack<T>::~MyStack() {

}
template<typename T> 
void MyStack<T>::swapQueue() {
    std::queue<T> temp = q1;
    q1 = q2;
    q2 = temp;
}

template<typename T> 
void MyStack<T>::push(const T& data) {
    q1.push(data);
}

template<typename T> 
T MyStack<T>::pop() {
    if (q1.empty()) {
         throw new std::runtime_error("stack is empty");
    } else {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        T res = q1.front();
        q1.pop();
        swapQueue();
        return res;
    }
}