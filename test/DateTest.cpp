//
// Created by Filippo Crinzi on 26/09/24.
//

#include <gtest/gtest.h>
#include "../Date.h"

TEST(DateTest, Constructor) {
    Date date(3, 10, 2022);
    EXPECT_EQ(date.getYear(), 2022);
    EXPECT_EQ(date.getMonth(), 10);
    EXPECT_EQ(date.getDay(), 3);
}

TEST(DateTest, InvalidDate) {
    EXPECT_THROW(Date(3,13,2022), std::invalid_argument);
    EXPECT_THROW(Date(32,8,2022), std::invalid_argument);
    EXPECT_THROW(Date(3,10,-2022), std::invalid_argument);
    EXPECT_THROW(Date(29,2,2021), std::invalid_argument);
    EXPECT_THROW(Date(31,11,2020), std::invalid_argument);


}