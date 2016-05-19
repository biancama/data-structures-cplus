//
// Created by Massimo Biancalani on 27/04/16.
//

#include "gtest/gtest.h"
#include "SinglyLinkedList.hpp"

TEST(singlyLinkedList_check, singlyLinkedList_check01) {
    structure::SinglyLinkedList<int> ll;
    ASSERT_EQ(0, ll.size());
    ASSERT_EQ(true, ll.isEmpty());
    ll.addFirst(10);
    ASSERT_EQ(1, ll.size());
    ASSERT_EQ(false, ll.isEmpty());
    ASSERT_EQ(10, ll.first());
    ASSERT_EQ(10, ll.get(0));
    ll.addFirst(10);
    ASSERT_EQ(2, ll.size());
    ASSERT_EQ(false, ll.isEmpty());
    ASSERT_EQ(10, ll.first());
    ll.set(1, 20);
    ASSERT_EQ(20, ll.get(1));
    ASSERT_EQ(20, ll.last());
    ll.addFirst(40);
    ASSERT_EQ(40, ll.get(0));
    ll.add(2, 50);
    ASSERT_EQ(50, ll.get(2));
    ll.remove(1);
    ASSERT_EQ(3, ll.size());
    ASSERT_EQ(50, ll.get(1));
    ll.addFirst(5);
    ASSERT_EQ(4, ll.size());
    ASSERT_EQ(5, ll.get(0));
    ll.addLast(60);
    ASSERT_EQ(5, ll.size());
    ASSERT_EQ(60, ll.get(4));
    ll.removeFirst();
    ASSERT_EQ(4, ll.size());
    ASSERT_EQ(40, ll.get(0));
}

