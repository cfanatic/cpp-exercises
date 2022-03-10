#include <gtest/gtest.h>
#include "linked_list.hpp"

TEST(LinkedListTest, Initialize)
{
    std::shared_ptr<ListElement<int>> head;
    head = std::make_shared<ListElement<int>>();
    EXPECT_EQ(head->get_value(), 0);
    head = std::make_shared<ListElement<int>>(1337);
    EXPECT_EQ(head->get_value(), 1337);
}

TEST(LinkedListTest, InsertAtHead)
{
    std::shared_ptr<ListElement<int>> head = std::make_shared<ListElement<int>>();
    head->set_value(100);
    head->insert_front(&head, 200);
    head = head->insert_front(300);

    std::shared_ptr<ListElement<int>> temp;
    EXPECT_EQ(head->get_value(), 300);
    temp = head->get_next();
    EXPECT_EQ(temp->get_value(), 200);
    temp = temp->get_next();
    EXPECT_EQ(temp->get_value(), 100);
}

TEST(LinkedListTest, Find)
{
    std::shared_ptr<ListElement<int>> head = std::make_shared<ListElement<int>>();
    head = head->insert_front(300);
    head = head->insert_front(200);
    head = head->insert_front(100);

    // structure
    // ---------
    // head: 100 -> 200 -> 300 -> tail: 0

    std::shared_ptr<ListElement<int>> element = std::make_shared<ListElement<int>>();
    element = element->find(head, 0);
    EXPECT_EQ(element->get_value(), 0);
    element = element->find(head, 300);
    EXPECT_EQ(element->get_value(), 300);
    element = element->find(head, 200);
    EXPECT_EQ(element->get_value(), 200);
    element = element->find(head, 100);
    EXPECT_EQ(element->get_value(), 100);
    element = element->find(head, -1);
    EXPECT_EQ(element->get_value(), 0);
}