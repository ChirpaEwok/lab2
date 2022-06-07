#ifndef TESTS_H
#define TESTS_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>
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
    GetOutput(load(txt, "nothing");)
    ASSERT_EQ(output, "The file nothing cannot be opened\n");
}

#endif
