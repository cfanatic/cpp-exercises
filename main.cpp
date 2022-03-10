#include "linked_list.hpp"

int main()
{
    std::shared_ptr<ListElement<int>> head = std::make_shared<ListElement<int>>(1337);

    auto print = [&]()
    {
        std::cout << "head.data: " << head->get_value() << std::endl;
    };

    auto print_all = [&]()
    {
        std::shared_ptr<ListElement<int>> temp = head;
        while (temp->get_next() != nullptr)
        {
            std::cout << "element.data: " << temp->get_value() << std::endl;
            temp = temp->get_next();
        }
    };

    std::cout << "Head of Linked List:" << std::endl;
    print();

    std::cout << "Inserting two elements before head:" << std::endl;
    head->insert_front(&head, 100);
    print();
    head = head->insert_front(200);
    print();
    head = head->insert_front(300);
    print();
    head = head->insert_front(400);
    print();

    std::cout << "Head of Linked List:" << std::endl;
    print();

    std::cout << "Content of old Linked List:" << std::endl;
    print_all();
    std::shared_ptr<ListElement<int>> to_delete;
    to_delete = head->find(head, 200);
    head->remove(&head, to_delete);
    std::cout << "Content of new Linked List:" << std::endl;
    print_all();

    std::cout << "Printing two elements after head:" << std::endl;
    head = head->get_next();
    print();
    head = head->get_next();
    print();

    return 0;
}