#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <memory>
#include <string>

template <class T>
class ListElement
{

public:
    ListElement(const T &value) : next(nullptr), data(value) {}
    ~ListElement() {}

    std::shared_ptr<ListElement<T>> get_next() const { return next; }
    const T &get_value() const { return data; }
    void set_next(std::shared_ptr<ListElement<T>> element) { next = element; }
    void set_value(const T &value) { data = value; }

    bool insert_front(std::shared_ptr<ListElement<T>> *head, const T &data);
    std::shared_ptr<ListElement<T>> insert_front(const T &data);

private:
    std::shared_ptr<ListElement<T>> next;
    T data;
};

template <class T>
bool ListElement<T>::insert_front(std::shared_ptr<ListElement<T>> *head, const T &data)
{
    ListElement<T> *new_element = new ListElement<T>(data);

    if (new_element == nullptr)
        return false;

    new_element->set_next(*head);
    *head = static_cast<std::shared_ptr<ListElement<T>>>(new_element);

    return true;
}

template <class T>
std::shared_ptr<ListElement<T>> ListElement<T>::insert_front(const T &data)
{
    std::shared_ptr<ListElement<T>> new_element = std::make_shared<ListElement<T>>(data);

    if (new_element != nullptr)
        new_element->set_next(this->get_next());

    return new_element;
}

#endif // LINKED_LIST_HPP