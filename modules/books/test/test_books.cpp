// Copyright 2019 Pasechnik Nikita

#include <gtest/gtest.h>

#include "include/Books.h"

TEST(Pasechnik_Nikita_BooksTest, CanCreateBooks) {
    // Arrange
    int arr[5] = { 1, 2, 3, 4, 5 };

    // Assert
    ASSERT_NO_THROW(Books magazin(5, arr));
}

TEST(Pasechnik_Nikita_BooksTest, FiveSameBooks) {
    // Arrange
    int arr[5] = { 5, 0, 0, 0, 0 };
    Books coll(5, arr);

    // Act
    double pay = coll.CalculateAllPayment(arr);

    // Assert
    EXPECT_EQ(pay, 40.0);
}

TEST(Pasechnik_Nikita_BooksTest, FiveDifferentBooks) {
    // Arrange
    int arr[5] = { 1, 1, 1, 1, 1 };
    Books coll(5, arr);

    // Act
    double pay = coll.CalculateAllPayment(arr);

    // Assert
    EXPECT_EQ(pay, 30.0);
}

TEST(Pasechnik_Nikita_BooksTest, FiveDiffCollection) {
    // Arrange
    int arr[5] = { 1, 2, 3, 4, 5 };
    Books coll(5, arr);

    // Act
    double pay = coll.CalculateAllPayment(arr);

    // Assert
    EXPECT_EQ(pay, 100.4);
}
