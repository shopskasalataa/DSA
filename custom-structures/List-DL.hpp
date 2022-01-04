#ifndef LIST_DL_HPP
#define LIST_DL_HPP
template<typename T>
class List_DL {
private:
    struct Node {
        T value;
        Node* next;
        Node* prev;
        Node(const T& value, Node* next = nullptr, Node* prev = nullptr) : value(value), next(next), prev(prev) {}
    };
    Node* first;
    Node* last;

    void copy(const List_DL<T>&);
    void copy(const List_DL<T>::Node*);
    void free();

public:
    List_DL();
    List_DL(const List_DL<T>&);
    List_DL<T>& operator=(const List_DL<T>&);
    ~List_DL();

    bool empty() const;
    void push_front(const T&);
    void push_back(const T&);
    void pop_front();
    void pop_back();

    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    class Iterator {
    private:
        Node* curr;

    public:
        Iterator();
        Iterator(List_DL<T>::Node*);
        Iterator& operator=(const Iterator&);

        void operator++();
        void operator--();
        bool operator==(const Iterator&) const;
        bool operator!=(const Iterator&) const;

        T& operator*();
        const T& operator*() const;

        friend class List_DL;
    };
    Iterator begin() const;
    Iterator end() const;

    void insert_after(Iterator&, const T&);
    void erase_after(Iterator&);

    friend class Iterator;
};
template<typename T>
void List_DL<T>::copy(const List_DL<T>::Node* other_node) {
    if (other_node == nullptr) return;

    copy(other_node->next);
    push_front(other_node->value);
}
template<typename T>
void List_DL<T>::copy(const List_DL<T>& other) {
    first = last = nullptr;
    copy(other.first);
}
template<typename T>
void List_DL<T>::free() {
    while (!empty()) {
        pop_front();
    }
}

template<typename T>
List_DL<T>::List_DL() : first(nullptr), last(nullptr) {}
template<typename T>
List_DL<T>::List_DL(const List_DL<T>& other) {
    copy(other);
}
template<typename T>
List_DL<T>& List_DL<T>::operator=(const List_DL<T>& other) {
    if (this != &other) {
        free();
        copy(other);
    }
    return *this;
}
template<typename T>
List_DL<T>::~List_DL() {
    free();
}

template<typename T>
bool List_DL<T>::empty() const {
    return first == nullptr && last == nullptr;
}
template<typename T>
void List_DL<T>::push_front(const T& value) {
    Node* new_element = new Node(value, first);
    if (first != nullptr) first->prev = new_element;
    first = new_element;
    if (last == nullptr) last = first;
}
template<typename T>
void List_DL<T>::push_back(const T& value) {
    Node* new_element = new Node(value, nullptr, last);
    if (last != nullptr) last->next = new_element;
    last = new_element;
    if (first == nullptr) first = last;
}
template<typename T>
void List_DL<T>::pop_front() {
    Node* tmp = first;
    first = first->next;
    delete tmp;
    if (first == nullptr) last = first;
    else first->prev = nullptr;
}
template<typename T>
void List_DL<T>::pop_back() {
    Node* tmp = last;
    last = last->prev;
    delete tmp;
    if (last == nullptr) first = last;
    else last->next = nullptr;
}

template<typename T>
T& List_DL<T>::front() {
    return first->value;
}
template<typename T>
const T& List_DL<T>::front() const {
    return first->value;
}
template<typename T>
T& List_DL<T>::back() {
    return last->value;
}
template<typename T>
const T& List_DL<T>::back() const {
    return last->value;
}

template<typename T>
List_DL<T>::Iterator::Iterator() {
    curr = nullptr;
}
template<typename T>
List_DL<T>::Iterator::Iterator(List_DL<T>::Node* node) {
    curr = node;
}
template<typename T>
typename List_DL<T>::Iterator& List_DL<T>::Iterator::operator=(const List_DL<T>::Iterator& other) {
    curr = other.curr;
    return *this;
}

template<typename T>
void List_DL<T>::Iterator::operator++() {
    if (curr == nullptr) return;
    curr = curr->next;
}
template<typename T>
void List_DL<T>::Iterator::operator--() {
    if (curr == nullptr) return;
    curr = curr->prev;
}
template<typename T>
bool List_DL<T>::Iterator::operator==(const List_DL<T>::Iterator& other) const {
    return curr == other.curr;
}
template<typename T>
bool List_DL<T>::Iterator::operator!=(const List_DL<T>::Iterator& other) const {
    return curr != other.curr;
}

template<typename T>
T& List_DL<T>::Iterator::operator*() {
    return curr->value;
}
template<typename T>
const T& List_DL<T>::Iterator::operator*() const {
    return curr->value;
}

template<typename T>
typename List_DL<T>::Iterator List_DL<T>::begin() const {
    return List_DL<T>::Iterator(first);
}
template<typename T>
typename List_DL<T>::Iterator List_DL<T>::end() const {
    return List_DL<T>::Iterator(last->next);
}

template<typename T>
void List_DL<T>::insert_after(List_DL<T>::Iterator& position, const T& value) {
    Node* node = position.curr;
    Node* new_node = new Node(value, node->next, node);
    node->next = new_node;
    new_node->next->prev = new_node;
}
template<typename T>
void List_DL<T>::erase_after(List_DL<T>::Iterator& position) {
    Node* node = position.curr;
    Node* to_be_deleted = node->next;
    node->next = to_be_deleted->next;
    node->next->prev = node;
    delete to_be_deleted;
}
#endif // LIST_DL_HPP