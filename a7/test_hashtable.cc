/*
 *  This is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  It is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  See <http://www.gnu.org/licenses/>.
 */
#include <string.h>

#include "gtest/gtest.h"

extern "C" {
#include "Hashtable.h"
}
const char* first = "first";
const char* second = "second";
const char* third = "third";
const char* fourth = "fourth";

TEST(Hashtable, Create) {
    Hashtable ht = CreateHashtable(5);
    EXPECT_FALSE(ht == NULL);
    EXPECT_FALSE(ht->buckets == NULL);
    EXPECT_EQ(NumElemsInHashtable(ht), 0);
    DestroyHashtable(ht, NULL);
}

TEST(Hashtable, AddOneRemoveOne) {
    Hashtable ht = CreateHashtable(5);
    EXPECT_EQ(NumElemsInHashtable(ht), 0);
    char* word = (char*)malloc(6 * sizeof(char));
    char* hello = (char*)malloc(6 * sizeof(char));
    char stackString[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    LinkedList list = CreateLinkedList();
    strcpy(word, stackString);
    strcpy(hello, stackString);
    AppendLinkedList(list, (void*)word);
    Put(ht, (void*)hello, (void*)list);
    EXPECT_EQ(NumElemsInHashtable(ht), 1);
    Remove(ht, (void*)hello, FreeKeyValuePair);
    EXPECT_EQ(NumElemsInHashtable(ht), 0);
    free(hello);
    DestroyHashtable(ht, FreeBucketList);
}

TEST(Hashtable, AddOneElemDestroy) {
    Hashtable ht = CreateHashtable(5);
    EXPECT_EQ(NumElemsInHashtable(ht), 0);
    char* word = (char*)malloc(6 * sizeof(char));
    char* hello = (char*)malloc(6 * sizeof(char));
    char stackString[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    LinkedList list = CreateLinkedList();
    strcpy(word, stackString);
    strcpy(hello, stackString);
    AppendLinkedList(list, (void*)word);
    Put(ht, (void*)hello, (void*)list);
    EXPECT_EQ(NumElemsInHashtable(ht), 1);
    EXPECT_EQ(NumElemsInHashtable(ht), 1);
    free(hello);
    DestroyHashtable(ht, FreeBucketList);
}

TEST(Hashtable, AddOneElemTwoTimes) {
    Hashtable ht = CreateHashtable(5);
    EXPECT_EQ(NumElemsInHashtable(ht), 0);
    char* word = (char*)malloc(6 * sizeof(char));
    char* hello = (char*)malloc(6 * sizeof(char));
    char stackString[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    LinkedList list = CreateLinkedList();
    strcpy(word, stackString);
    strcpy(hello, stackString);
    AppendLinkedList(list, (void*)word);
    int result = Put(ht, (void*)hello, (void*)list);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(NumElemsInHashtable(ht), 1);
    result = Put(ht, (void*)hello, (void*)list);
    EXPECT_EQ(result, 2);
    EXPECT_EQ(NumElemsInHashtable(ht), 1);
    free(hello);
    DestroyHashtable(ht, FreeBucketList);
}

TEST(Hashtable, AddMultipleItems) {
    Hashtable ht = CreateHashtable(100);
    EXPECT_EQ(NumElemsInHashtable(ht), 0);
    char* word = (char*)malloc(6 * sizeof(char));
    char* hello = (char*)malloc(6 * sizeof(char));
    char stackString1[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    LinkedList list1 = CreateLinkedList();
    strcpy(word, stackString1);
    strcpy(hello, stackString1);
    AppendLinkedList(list1, (void*)word);
    Put(ht, (void*)hello, (void*)list1);
    free(hello);
    ASSERT_EQ(NumElemsInHashtable(ht), 1);
    word = (char*)malloc(6 * sizeof(char));
    char* apple = (char*)malloc(6 * sizeof(char));
    char stackString2[6] = {'a', 'p', 'p', 'l', 'e', '\0'};
    LinkedList list2 = CreateLinkedList();
    strcpy(word, stackString2);
    strcpy(hello, stackString2);
    AppendLinkedList(list2, (void*)word);
    Put(ht, (void*)hello, (void*)list2);
    free(apple);
    ASSERT_EQ(NumElemsInHashtable(ht), 2);
    word = (char*)malloc(7 * sizeof(char));
    char* banana = (char*)malloc(7 * sizeof(char));
    char stackString3[7] = {'b', 'a', 'n', 'a', 'n', 'a', '\0'};
    LinkedList list3 = CreateLinkedList();
    strcpy(word, stackString3);
    strcpy(hello, stackString3);
    AppendLinkedList(list3, (void*)word);
    Put(ht, (void*)hello, (void*)list3);
    free(banana);
    ASSERT_EQ(NumElemsInHashtable(ht), 3);
    DestroyHashtable(ht, FreeBucketList);
}

TEST(Hashtable, LookupInHashtable) {
    Hashtable ht = CreateHashtable(5);
    EXPECT_EQ(NumElemsInHashtable(ht), 0);
    char* word1 = (char*)malloc(6 * sizeof(char));
    char* hello = (char*)malloc(6 * sizeof(char));
    char stackString1[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    LinkedList list1 = CreateLinkedList();
    strcpy(word1, stackString1);
    strcpy(hello, stackString1);
    AppendLinkedList(list1, (void*)word1);
    Put(ht, (void*)hello, (void*)list1);
    ASSERT_EQ(NumElemsInHashtable(ht), 1);
    char* word2 = (char*)malloc(6 * sizeof(char));
    char* apple = (char*)malloc(6 * sizeof(char));
    char stackString2[6] = {'a', 'p', 'p', 'l', 'e', '\0'};
    LinkedList list2 = CreateLinkedList();
    strcpy(word2, stackString2);
    strcpy(apple, stackString2);
    AppendLinkedList(list2, (void*)word2);
    Put(ht, (void*)apple, (void*)list2);
    ASSERT_EQ(NumElemsInHashtable(ht), 2);
    char* word3 = (char*)malloc(7 * sizeof(char));
    char* banana = (char*)malloc(7 * sizeof(char));
    char stackString3[7] = {'b', 'a', 'n', 'a', 'n', 'a', '\0'};
    LinkedList list3 = CreateLinkedList();
    strcpy(word3, stackString3);
    strcpy(banana, stackString3);
    AppendLinkedList(list3, (void*)word3);
    Put(ht, (void*)banana, (void*)list3);
    ASSERT_EQ(NumElemsInHashtable(ht), 3);
    int result = Contains(ht, hello);
    EXPECT_EQ(result, 0);
    result = Contains(ht, apple);
    EXPECT_EQ(result, 0);
    char* nonExistWord = (char*)malloc(7 * sizeof(char));
    char stackString4[7] = {'n', 'o', 'w', 'o', 'r', 'd', '\0'};
    strcpy(nonExistWord, stackString4);
    result = Contains(ht, nonExistWord);
    EXPECT_EQ(result, -1);
    EXPECT_EQ(NumElemsInHashtable(ht), 3);
    free(hello);
    free(apple);
    free(banana);
    DestroyHashtable(ht, FreeBucketList);
}

TEST(Hashtable, TwoElemsOneBucket) {
    Hashtable ht = CreateHashtable(5);
    EXPECT_EQ(NumElemsInHashtable(ht), 0);
    // key 10309024813521750789
    char* word1 = (char*)malloc(6 * sizeof(char));
    char* hello = (char*)malloc(6 * sizeof(char));
    char stackString1[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    LinkedList list1 = CreateLinkedList();
    strcpy(word1, stackString1);
    strcpy(hello, stackString1);
    AppendLinkedList(list1, (void*)word1);
    Put(ht, (void*)hello, (void*)list1);
    ASSERT_EQ(NumElemsInHashtable(ht), 1);
    // key 15973930870233961954
    char* word2 = (char*)malloc(6 * sizeof(char));
    char* apple = (char*)malloc(6 * sizeof(char));
    char stackString2[6] = {'a', 'p', 'p', 'l', 'e', '\0'};
    LinkedList list2 = CreateLinkedList();
    strcpy(word2, stackString2);
    strcpy(apple, stackString2);
    AppendLinkedList(list2, (void*)word2);
    Put(ht, (void*)apple, (void*)list2);
    ASSERT_EQ(NumElemsInHashtable(ht), 2);
    // both should be hashed to bucket 4, and both should exist
    int result = Contains(ht, hello);
    EXPECT_EQ(result, 0);
    result = Contains(ht, apple);
    EXPECT_EQ(result, 0);
    free(hello);
    free(apple);
    DestroyHashtable(ht, FreeBucketList);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
