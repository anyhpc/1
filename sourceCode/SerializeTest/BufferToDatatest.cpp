#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "BufferToData.h"

class BufferToDataTest : public ::testing::Test
{

};

TEST_F(BufferToDataTest, TestU8)
{
    char buffer[256] = {0};
    buffer[0] = static_cast<char>(0);
    uint8_t val = Serialize::BufferToData::Read<uint8_t>(buffer);
    ASSERT_EQ(val, 0);
    buffer[0] = static_cast<char>(255);
    val = Serialize::BufferToData::Read<uint8_t>(buffer);
    ASSERT_EQ(val, 255);
    buffer[0] = static_cast<char>(100);
    val = Serialize::BufferToData::Read<uint8_t>(buffer);
    ASSERT_EQ(val, 100);
    buffer[0] = static_cast<char>(200);
    val = Serialize::BufferToData::Read<uint8_t>(buffer);
    ASSERT_EQ(val, 200);
}
