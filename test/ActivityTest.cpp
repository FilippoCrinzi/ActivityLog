//
// Created by Filippo Crinzi on 26/09/24.
//



#include <gtest/gtest.h>
#include "../Activity.h"
#include "../Time.h"

TEST(ActivityTest, Constructor) {
    Time start(9, 0);
    Time finish(10, 0);
    Date date(26, 9, 2024);
    Activity activity("Meeting", start, finish, date);

    EXPECT_EQ(activity.getDescription(), "Meeting");
    EXPECT_EQ(activity.getStart().getHour(), 9);
    EXPECT_EQ(activity.getStart().getMinutes(), 0);
    EXPECT_EQ(activity.getFinish().getHour(), 10);
    EXPECT_EQ(activity.getFinish().getMinutes(), 0);
    EXPECT_EQ(activity.getDate().getDay(), 26);
    EXPECT_EQ(activity.getDate().getMonth(), 9);
    EXPECT_EQ(activity.getDate().getYear(), 2024);
}

TEST(ActivityTest, InvalidActivity){
    Time start(9, 0);
    Time finish(8, 0);
    Date date(26, 9, 2024);
    EXPECT_THROW(Activity("Meeting", start, finish, date), std::invalid_argument);
    Time start2(9, 0);
    Time finish2(9, 0);
    EXPECT_THROW(Activity("Meeting", start2, finish2, date), std::invalid_argument);
}