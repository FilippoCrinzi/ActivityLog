//
// Created by Filippo Crinzi on 26/09/24.
//



#include <gtest/gtest.h>
#include "../Activity.h"
#include "../Time.h"

TEST(ActivityTest, Constructor) {
    Time start(9, 0);
    Time finish(10, 0);
    Activity activity("Meeting", start, finish);

    EXPECT_EQ(activity.getDescription(), "Meeting");
    EXPECT_EQ(activity.getStart().getHour(), 9);
    EXPECT_EQ(activity.getStart().getMinutes(), 0);
    EXPECT_EQ(activity.getFinish().getHour(), 10);
    EXPECT_EQ(activity.getFinish().getMinutes(), 0);
}