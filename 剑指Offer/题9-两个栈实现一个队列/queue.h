/**
 * 通过两个栈实现一个队列
 * 每次enqueue时，都放到stack1
 * 每次删除时，如果stack2为空，就先将stack1全部弹出压到stack2,再从stack2弹出栈顶。如果不为空直接从stack2弹出栈顶元素。
*/

#include <iostream>
#include <stack>
#include <exception>

template<typename T> class CQueue {
public:
    CQueue();
    ~CQueue();
    void enqueue(const T& data);
    T dequeue();
private:
    std::stack<T> s1;
    std::stack<T> s2;
};

template<typename T>
CQueue<T>::CQueue() {

}

template<typename T>
CQueue<T>::~CQueue() {
}

template<typename T>
void CQueue<T>::enqueue(const T& data) {
    s1.push(data);
}

template<typename T>
T CQueue<T>::dequeue() {
    if (s2.size() <= 0) {
        while(s1.size() > 0) {
            T data = s1.top();
            s1.pop();
            s2.push(data);
        }
    }
    if (s2.size() <= 0) 
        throw new std::runtime_error("queue is empty");
    T head = s2.top();
    s2.pop();
    return head;
}
