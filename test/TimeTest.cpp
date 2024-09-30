//
// Created by Filippo Crinzi on 26/09/24.
//
#include <gtest/gtest.h>
#include "../Time.h"

TEST(TimeTest, Constructor) {
    Time time(14, 30);
    EXPECT_EQ(time.getHour(), 14);
    EXPECT_EQ(time.getMinutes(), 30);
}

TEST(TimeTest, InvalidTime) {
    EXPECT_THROW(Time(24, 0), std::invalid_argument);
    EXPECT_THROW(Time(10, 60), std::invalid_argument);
    EXPECT_THROW(Time(-1, 0), std::invalid_argument);
    EXPECT_THROW(Time(0, -1), std::invalid_argument);
}
