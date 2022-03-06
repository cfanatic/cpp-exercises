// ==========================================================================================
// TODO: Complete exercise description.
// ==========================================================================================

#include "linked_list.hpp"

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
        new_element->set_next(std::make_shared<ListElement<T>>(*this));

    return new_element;
}

// In order to avoid unresolved symbol error during linking:
// Instantiate methods with argument 'int'
// OR
// Move the implementation above into 'linked_list.hpp' instead
template bool ListElement<int>::insert_front(std::shared_ptr<ListElement<int>> *head, const int &data);
template std::shared_ptr<ListElement<int>> ListElement<int>::insert_front(const int &data);