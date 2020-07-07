#include <iostream>
#include "queue.h"
#include "stack.h"

int main() {

    CQueue<char> q;
    q.enqueue('a');
    q.enqueue('b');
    q.enqueue('c');
    std::cout << q.dequeue() << std::endl;
    std::cout << q.dequeue() << std::endl;
    q.enqueue('d');
    q.enqueue('e');
    q.enqueue('f');
    std::cout << q.dequeue() << std::endl;
    std::cout << q.dequeue() << std::endl;

    MyStack<int> s;
	s.push(4);
	s.push(6);
	s.push(3);
	s.push(1);
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
    s.push(5);
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;

    return 0;
}

