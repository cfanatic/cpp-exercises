#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <memory>
#include <string>

template <class T>
class ListElement
{

public:
    ListElement() : next(nullptr), data(0) {}
    ListElement(const T &value) : next(nullptr), data(value) {}
    ~ListElement() {}

    std::shared_ptr<ListElement<T>> get_next() const { return next; }
    const T &get_value() const { return data; }
    void set_next(std::shared_ptr<ListElement<T>> element) { next = element; }
    void set_value(const T &value) { data = value; }

    bool insert_front(std::shared_ptr<ListElement<T>> *head, const T &data);
    std::shared_ptr<ListElement<T>> insert_front(const T &data);
    std::shared_ptr<ListElement<T>> find(std::shared_ptr<ListElement<T>> head, const T &data);
    bool remove(std::shared_ptr<ListElement<T>> *head, std::shared_ptr<ListElement<T>> element);

private:
    std::shared_ptr<ListElement<T>> next;
    T data;
};

#endif // LINKED_LIST_HPP