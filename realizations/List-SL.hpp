#ifndef LIST_SL_HPP
#define LIST_SL_HPP

template<typename T>
class List{
private:
    struct Node{
        T value;
        Node* next;
        Node(const T& value, Node* next = nullptr) : value(value), next(next) {}
    };

    Node* first;
    Node* last;//check

    //void copy(const Node*); // друг метод за копиране
    void copy(const List<T>&);
    void free();

public:
    List();
    List(const List<T>&);
    List<T>& operator=(const List<T>&);
    ~List();

    bool empty() const;
    void push_front(const T&);
    void pop_front();
    T& front();//check
    const T& front() const;//check

    class Iterator{
        private:
        Node* curr;

        public:
        Iterator();
        Iterator(List<T>::Node*);
        Iterator& operator=(const Iterator&);

        void operator++();
        bool operator==(const Iterator&)const;//check
        bool operator!=(const Iterator&)const;//check
        T& operator*();

        const T& operator*() const;//check

        friend class List<T>;
    };

    Iterator begin() const;
    Iterator end() const;

    void insert_after(Iterator&, const T&);//check
    void erase_after(Iterator&);//check

    friend class Iterator;
};

//copy method
// ако е един елемент, как се случват нещата?
template<typename T>
void List<T>::copy(const List<T>& other){
    if(other.empty()){
        first = nullptr;
        last = nullptr;
        return;
    }

    Node* this_node = new Node(other.first->value);
    Node* other_node = other.first->next;
    first = this_node;

    while(other_node != nullptr){
        this_node->next = new Node(other_node->value);
        this_node = this_node->next;
        other_node = other_node->next;
    }
    last = this_node;
}

/*
//Друг вариант за копиране
template<typename T>
void List<T>::copy(const List<T>::Node* other_node){
    if(other_node == nullptr) return;

    copy(other_node->next);
    push_front(other_node->value);
}

template<typename T>
void List<T>::copy(const List<T>& other){
    first = last = nullptr;
    copy(other.first);
}
*/

//delete method
template<typename T>
void List<T>::free(){
    while(!empty()){
        pop_front();
    }
}

// default constructor
template<typename T>
List<T>::List() : first(nullptr), last(nullptr){}

// copy constructor
template<typename T>
List<T>::List(const List<T>& other){
    copy(other);
}

// assingment constructor
template<typename T>
List<T>& List<T>::operator=(const List<T>& other){
    if(this != &other){
        free();
        copy(other);
    }
    return *this;
}

// destructor
template<typename T>
List<T>::~List(){
    free();
}

// checks if the list is empty
template<typename T>
bool List<T>::empty() const{
    return first == nullptr && last == nullptr;
}

// method which adds element in the front of the list
template<typename T>
void List<T>::push_front(const T& value){
    Node* new_element = new Node(value, first);
    first = new_element;
    if(last == nullptr) last = first;
}

// method which removes the first element
template<typename T>
void List<T>::pop_front(){
    Node* tmp = first;
    first = first->next;
    delete tmp;
    if(first == nullptr) last = first;
}

// returns a reference to the first element
template<typename T>
T& List<T>::front(){
    return first->value;
}

// returns constant of type T to the first element
template<typename T>
const T& List<T>::front() const{
    return first->value;
}


//iterator class
template<typename T>
List<T>::Iterator::Iterator(){
    curr = nullptr;
}

template<typename T>
List<T>::Iterator::Iterator(List<T>::Node* node){
    curr = node;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator=(const List<T>::Iterator& other){
    curr = other.curr;
}

template<typename T>
void List<T>::Iterator::operator++(){
    if(curr == nullptr) return;
    curr = curr->next;
}

template<typename T>
bool List<T>::Iterator::operator==(const List<T>::Iterator& other) const{
    return curr == other.curr;
}

template<typename T>
bool List<T>::Iterator::operator!=(const List<T>::Iterator& other) const{
    return curr != other.curr;
}

template<typename T>
T& List<T>::Iterator::operator*() {
    return curr->value;
}

template<typename T>
const T& List<T>::Iterator::operator*() const{
    return curr->value;
}

template<typename T>
typename List<T>::Iterator List<T>::begin() const{
    return List<T>::Iterator(first);
}

template<typename T>
typename List<T>::Iterator List<T>::end() const{
    return List<T>::Iterator(last->next);
}

template<typename T>
void List<T>::insert_after(List<T>::Iterator& position, const T& value){
    Node* node = position.curr;
    Node* new_node = new Node(value, node->next);
    node->next = new_node;
}

template<typename T>
void List<T>::erase_after(List<T>::Iterator& position){
    Node* node = position.curr;
    Node* to_be_deleted = node->next;
    node->next = to_be_deleted->next;
    delete to_be_deleted;
}



#endif //LIST_SL_HPP
