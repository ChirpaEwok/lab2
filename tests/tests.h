#ifndef TESTS_H
#define TESTS_H

#include <gtest/gtest.h>
#include <sstream>
#include <fstream>

extern "C"{
    #include "../app/text/text.h"
    #include "../app/text/_text.h"
    #include "../app/common.h"
}

#define GetOutput(action) \
    testing::internal::CaptureStdout(); \
    { action } \
    output = testing::internal::GetCapturedStdout();

char* filename = "input.txt";

TEST(load, nonexistent_file)
{
    text txt = create_text();
    std::string output;
    GetOutput(load(txt, "nothing.txt");)
    ASSERT_EQ(output, "The file nothing.txt cannot be opened\n");
}

TEST(load, unreadable_file)
{
    text txt = create_text();
    std::string output;
    GetOutput(load(txt, "unreadable.txt");)
    ASSERT_EQ(output, "The file unreadable.txt cannot be opened\n");
}

#endif
