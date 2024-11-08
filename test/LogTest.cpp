//
// Created by Filippo Crinzi on 18/10/24.
//
#include <gtest/gtest.h>
#include "../Log.h"

TEST(LogTest, AddActivity) {
    Log log;
    Time start(9, 0);
    Time finish(10, 0);
    Date date(26, 9, 2024);
    Activity activity("Meeting", start, finish, date);
    log.addActivity(activity);

    EXPECT_EQ(log.countActivities(), 1);
}

TEST(LogTest, FindActivity) {
    Log log;
    Time start(9, 0);
    Time finish(10, 0);
    Date date(26, 9, 2024);
    Activity activity("Meeting", start, finish, date);
    log.addActivity(activity);
    const std::list<Activity> &activities = log.find(date);

    EXPECT_EQ(activities.size(), 1);
}

TEST(LogTest, RemoveActivity) {
    Log log;
    Time start(9, 0);
    Time finish(10, 0);
    Date date(26, 9, 2024);
    Activity activity("Meeting", start, finish, date);
    log.addActivity(activity);
    log.removeActivity(activity);

    EXPECT_EQ(log.countActivities(), 0);
}

TEST(LogTest, UpdateActivity) {
    Log log;
    Time start(9, 0);
    Time finish(11, 30);
    Date date(26, 9, 2024);
    Activity activity("Meeting", start, finish, date);
    log.addActivity(activity);
    Time newStart(11, 0);
    const std::list<Activity> &activities = log.find(date);
    auto updatedActivity = std::find(activities.begin(), activities.end(), activity);
    log.updateActivity(activity, newStart, Log::FieldToUpdate::Start);

    //in questo modo controllo che l'attività sia stata effettivamente modificata e che la modifica sia corretta
    EXPECT_EQ(updatedActivity->getStart(), newStart);

    Time newFinish(12, 0);
    log.updateActivity(Activity("Meeting", newStart, finish, date), newFinish, Log::FieldToUpdate::Finish);

    EXPECT_EQ(updatedActivity->getFinish(), newFinish);

    QString newDescription("Lunch");
    log.updateActivity(Activity("Meeting", newStart, newFinish, date), newDescription, Log::FieldToUpdate::Description);

    EXPECT_EQ(updatedActivity->getDescription(), newDescription);

    Date newDate(27, 9, 2024);
    log.updateActivity(Activity(newDescription, newStart, newFinish, date), newDate, Log::FieldToUpdate::Date);

    EXPECT_NO_THROW({ const std::list<Activity> &activities2 = log.find(newDate); });
}

TEST(LogTest, RemoveActivityException) {
    Log log;
    Time start(9, 0);
    Time finish(10, 0);
    Date date(26, 9, 2024);
    Activity activity("Not insert", start, finish, date);

    EXPECT_THROW(log.removeActivity(activity), std::invalid_argument);
}

TEST(LogTest, UpdateActivityException) {
    Log log;
    Time start(9, 0);
    Time finish(10, 0);
    Date date(26, 9, 2024);
    Activity activity("Not insert", start, finish, date);
    Time newTime(11, 0);

    EXPECT_THROW(log.updateActivity(activity, newTime, Log::FieldToUpdate::Start), std::invalid_argument);
    EXPECT_THROW(log.updateActivity(activity, Time(30,00), Log::FieldToUpdate::Finish), std::invalid_argument);

    QString newDescription("Not_insert");

    EXPECT_THROW(log.updateActivity(activity, newDescription, Log::FieldToUpdate::Description), std::invalid_argument);

    Date newDate(27, 9, 2024);

    EXPECT_THROW(log.updateActivity(activity, newDate, Log::FieldToUpdate::Date), std::invalid_argument);

    log.addActivity(activity);
    //verifico che se provo a modificare un attributo con il campo sbagliato mi lanci un'eccezione
    EXPECT_THROW(log.updateActivity(activity, newDate, Log::FieldToUpdate::Description), std::invalid_argument);
    EXPECT_THROW(log.updateActivity(activity, newDescription, Log::FieldToUpdate::Date), std::invalid_argument);
    EXPECT_THROW(log.updateActivity(activity, newTime, Log::FieldToUpdate::Date), std::invalid_argument);

    Time newFinish(8, 0);
    Time newStart(11, 0);

    EXPECT_THROW(log.updateActivity(activity, newFinish, Log::FieldToUpdate::Finish), std::invalid_argument);
    EXPECT_THROW(log.updateActivity(activity, newStart, Log::FieldToUpdate::Start), std::invalid_argument);

    Time newFinish2(9, 0);
    Time newStart2(10, 0);

    EXPECT_THROW(log.updateActivity(activity, newFinish2, Log::FieldToUpdate::Finish), std::invalid_argument);
    EXPECT_THROW(log.updateActivity(activity, newStart2, Log::FieldToUpdate::Start), std::invalid_argument);
}

TEST(LogTest, AddDuplicateActivity) {
    Log log;
    Time start(9, 0);
    Time finish(10, 0);
    Date date(26, 9, 2024);
    Activity activity("Meeting", start, finish, date);
    log.addActivity(activity);

    EXPECT_THROW(log.addActivity(activity), std::invalid_argument);
}