#ifndef TESTS_H
#define TESTS_H

#include <gtest/gtest.h>
#include <sstream>
#include <fstream>

extern "C"{
    #include "../text/text.h"
    #include "../text/_text.h"
    #include "../app/common.h"
}

#define GetOutput(action) \
    testing::internal::CaptureStdout(); \
    { action } \
    output = testing::internal::GetCapturedStdout();

char *inputfile = INPUTDIR "/input.txt";

text txt_load(char *filename)
{
	text txt = create_text();
 	load(txt, filename);
 	return txt;
}

TEST(load, nonexistent_file)
{
    text txt = create_text();
    std::string output;
    GetOutput(load(txt, "nothing.txt"););
    ASSERT_EQ(output, "The file nothing.txt cannot be opened\n");
}

TEST(load, regular_file)
{
    text txt = txt_load(inputfile);
    std::ifstream f;
    std::string s;
    node *current = txt->begin;
    while(std::getline(f, s))
    {
    EXPECT_EQ(current->contents, s);
	current=current->next;
    }
}

TEST(save, correct_saving)
{
    text txt = txt_load(inputfile);
    save(txt, "output.txt");
    text out = txt_load("output.txt");
    show(out);
    std::ifstream file("output.txt");
    std::stringstream s;
    s << file.rdbuf();
    ASSERT_EQ(s.str(), "1234\nqwer\nasdf\nz x c v\n");
    remove_all(txt);
}

TEST(save, save_to_not_writable_file)
{
    text txt = txt_load(inputfile);
    std::string output;	
    GetOutput(save(txt, "immutable.txt"););
    ASSERT_EQ(output, "The file immutable.txt cannot be written\n");
    remove_all(txt);
}

#endif
