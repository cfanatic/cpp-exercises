#include "linked_list.hpp"

int main()
{
    std::cout << "Example of using std::make_shared() and std::shared_ptr()" << std::endl;

    std::shared_ptr<ListElement<int>> head = std::make_shared<ListElement<int>>(1337);

    auto print = [&]()
    {
        std::cout << "head.data: " << head->get_value() << std::endl;
    };

    print();
    head->insert_front(&head, 100);
    print();
    head = head->insert_front(200);
    print();

    return 0;
}