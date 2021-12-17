#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "List-DL.hpp"
template<typename T>
class Queue{
    private:
    List_DL<T> queue;
    public:
    bool empty() const;
    int size() const;

    const T& front() const;
    const T& back() const;

    void push(const T&);
    void pop();
};
template<typename T>
bool Queue<T>::empty() const{
    return queue.empty();
}
template<typename T>
int Queue<T>::size() const{
    int count = 0;
    for(typename List_DL<T>::Iterator it = queue.begin(); it != queue.end(); ++it){
        count++;
    }
    return count;
}

template<typename T>
const T& Queue<T>::front() const{
    return queue.front();
}
template<typename T>
const T& Queue<T>::back() const{
    return queue.back();
}

template<typename T>
void Queue<T>::push(const T& value){
    queue.push_back(value);
}
template<typename T>
void Queue<T>::pop(){
    queue.pop_front();
}
#endif // _QUEUE_HPP