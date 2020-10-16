#include "gtest/gtest.h"
#include "lib/message.h"

TEST(message_test,content) {
    EXPECT_EQ(get_message(), "Hello World!");
}