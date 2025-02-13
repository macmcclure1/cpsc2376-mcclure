
TEST(MathUtilsTest, SumRangeTest) {
    EXPECT_EQ(MathUtils::sumRange(1, 5), 15); // 1+2+3+4+5 = 15
    EXPECT_EQ(MathUtils::sumRange(-3, 3), 0); // -3 + -2 + -1 + 0 + 1 + 2 + 3 = 0
    EXPECT_EQ(MathUtils::sumRange(5, 5), 5); // Single number
}

TEST(MathUtilsTest, ContainsNegativeTest) {
    EXPECT_TRUE(MathUtils::containsNegative({3, -1, 5, 7}));
    EXPECT_FALSE(MathUtils::containsNegative({3, 1, 5, 7})); // All positive
    EXPECT_FALSE(MathUtils::containsNegative({})); // Empty list
}

TEST(MathUtilsTest, FindMaxTest) {
    EXPECT_EQ(MathUtils::findMax({3, -1, 5, 7}), 7);
    EXPECT_EQ(MathUtils::findMax({-5, -1, -3
