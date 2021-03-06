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

template <class T>
std::shared_ptr<ListElement<T>> ListElement<T>::find(std::shared_ptr<ListElement<T>> head, const T &data)
{
    std::shared_ptr<ListElement<T>> element = head;

    while ((element->get_next() != nullptr) && (element->get_value() != data))
    {
        element = element->get_next();
    }

    return element;
}

template <class T>
bool ListElement<T>::remove(std::shared_ptr<ListElement<T>> *head, std::shared_ptr<ListElement<T>> element)
{
    std::shared_ptr<ListElement<T>> temp = *head;

    if (temp->get_value() == element->get_value())
    {
        *head = temp->get_next();
        return true;
    }

    while (temp)
    {
        if (temp->get_next()->get_value() == element->get_value())
        {
            temp->set_next(element->get_next());
            return true;
        }
        temp = temp->get_next();
    }

    return false;
}

template <class T>
void ListElement<T>::remove_all(std::shared_ptr<ListElement<T>> *head)
{
    std::shared_ptr<ListElement<T>> to_delete = nullptr, to_save = *head;

    while (to_save->get_next() != nullptr)
    {
        to_delete = to_save;
        to_save = to_save->get_next();
        to_delete.reset();
    }

    *head = nullptr;
}

template <class T>
std::shared_ptr<ListElement<T>> ListElement<T>::operator[](const int &index)
{
    auto element = std::make_shared<ListElement<T>>(*this);
    int cnt = 0;

    while (cnt < index)
    {
        if (element->get_next() != nullptr)
        {
            element = element->get_next();
            cnt++;
        }
        else
        {
            element = nullptr;
            break;
        }
    }

    return element;
}

template <class T>
void ListElement<T>::operator=(const int &value)
{
    this->set_value(value);
}

// Avoid unresolved symbol error during linking
// --------------------------------------------
// Move the implementation above into 'linked_list.hpp'
//  OR
// Instantiate the class and all its member functions as below
template class ListElement<int>;