#include "linked_list.hpp"

int main()
{
    std::shared_ptr<ListElement<int>> head = std::make_shared<ListElement<int>>(1337);

    auto print = [&]()
    {
        std::cout << "head.data: " << head->get_value() << std::endl;
    };

    std::cout << "Head of Linked List:" << std::endl;
    print();

    std::cout << "Inserting two elements before head:" << std::endl;
    head->insert_front(&head, 100);
    print();
    head = head->insert_front(200);
    print();

    std::cout << "Head of Linked List:" << std::endl;
    print();

    std::cout << "Printing two elements after head:" << std::endl;
    head = head->get_next();
    print();
    head = head->get_next();
    print();

    return 0;
}