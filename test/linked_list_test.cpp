#include <gtest/gtest.h>
#include "linked_list.hpp"

TEST(LinkedListTest, Initialize)
{
    std::shared_ptr<ListElement<int>> head = std::make_shared<ListElement<int>>(1337);
    EXPECT_EQ(head->get_value(), 1337);
}

TEST(LinkedListTest, InsertAtHead)
{
    std::shared_ptr<ListElement<int>> head = std::make_shared<ListElement<int>>(100);
    head->insert_front(&head, 200);
    head = head->insert_front(300);

    std::shared_ptr<ListElement<int>> temp;
    EXPECT_EQ(head->get_value(), 300);
    temp = head->get_next();
    EXPECT_EQ(temp->get_value(), 200);
    temp = temp->get_next();
    EXPECT_EQ(temp->get_value(), 100);
}