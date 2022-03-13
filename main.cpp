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

    std::cout << "head[0]: " << (*head)[0]->get_value() << std::endl;
    std::cout << "head[1]: " << (*head)[1]->get_value() << std::endl;
    std::cout << "head[2]: " << (*head)[2]->get_value() << std::endl;
    std::cout << "head[3]: " << (*head)[3]->get_value() << std::endl;
    std::cout << "head[4]: " << (*head)[4]->get_value() << std::endl;

    std::cout << "Setting head[1]=500" << std::endl;
    *((*head)[1]) = 500;

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