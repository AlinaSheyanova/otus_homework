#include "gtest/gtest.h"

#include <sstream>
#include <fstream>

#include "reader.h"
#include "writer.h"
#include "processor.h"

// Test read from string stream
TEST(ReaderTest, ReadFromStringStream)
{
    std::istringstream iss("cmd1\ncmd2\n{\n");
    Reader reader(iss, 3);
    Processor processor;
    reader.registerListener(&processor);

    std::ostringstream oss;
    Writer writer(oss);
    processor.registerListener(&writer);

    reader.read();

    const std::string expectedOutput = "bulk: cmd1, cmd2\n";
    ASSERT_EQ(oss.str(), expectedOutput);
}

// Test read from input file
TEST(ReaderTest, ReadFromFile)
{
    std::ifstream inputFile("testFile.txt");
    Reader reader(inputFile, 3);
    Processor processor;
    reader.registerListener(&processor);

    std::ostringstream oss;
    Writer writer(oss);
    processor.registerListener(&writer);

    reader.read();

    const std::string expectedOutput = "bulk: cmd1, cmd2, cmd3\nbulk: cmd4, cmd5, cmd6\n";
    ASSERT_EQ(oss.str(), expectedOutput);
}

// Test if dynamic block with inner block implemented properly
TEST(DynamicBlockTest, InnerDynamicBlocks)
{
    std::istringstream iss("cmd1\ncmd2\n{\ncmd3\n{\ncmd4\n}\ncmd5\n}\n");
    Reader reader(iss, 3);
    Processor processor;
    reader.registerListener(&processor);

    std::ostringstream oss;
    Writer writer(oss);
    processor.registerListener(&writer);

    reader.read();

    const std::string expectedOutput = "bulk: cmd1, cmd2\nbulk: cmd3, cmd4, cmd5\n";
    ASSERT_EQ(oss.str(), expectedOutput);
}

// Test if block is skipped when EOF is reached inside dynamic block.
TEST(DynamicBlockTest, EOFInsideDynamicBlock)
{
    std::istringstream iss("cmd1\ncmd2\n{\ncmd3\n");
    Reader reader(iss, 2);
    Processor processor;
    reader.registerListener(&processor);

    std::ostringstream oss;
    Writer writer(oss);
    processor.registerListener(&writer);

    reader.read();

    const std::string expectedOutput = "bulk: cmd1, cmd2\n";
    ASSERT_EQ(oss.str(), expectedOutput);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}