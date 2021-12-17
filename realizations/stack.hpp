#ifndef STACK_HPP
#define STACK_HPP
#include "List-SL.hpp"
template <typename T>
class Stack{
    private:
    List<T>stack;
    public:
    const T& front() const;
    void push(const T&);
    void pop();
    int size() const;
    bool empty() const;
};
template <typename T>
const T& Stack<T>::front() const{
    return stack.front();
}
template <typename T>
void Stack<T>::push(const T& value){
    stack.push_front(value);
}
template <typename T>
void Stack<T>::pop(){
    stack.pop_front();
}
template <typename T>
int Stack<T>::size() const{
    int count = 0;
    for(typename List<T>::Iterator it = stack.begin(); it != stack.end(); ++it){
        count++;
    }
    return count;
}
template <typename T>
bool Stack<T>::empty() const{
    return stack.empty();
}
#endif //STACK_HPP