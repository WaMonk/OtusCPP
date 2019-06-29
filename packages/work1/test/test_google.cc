#include <gtest/gtest.h>

class GSimpleTest : public ::testing::Test {
public:
	
	void SetUp() { /* called before every test */ }
    void TearDown() { /* called after every test */ }

};

TEST_F(GSimpleTest, void) {
    int d1 = 10;
   	int d2 = 10;

    ASSERT_EQ(d1, d2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}