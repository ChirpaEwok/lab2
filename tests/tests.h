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

#define GetErr(action) \
    testing::internal::CaptureStderr(); \
    { action } \
    output = testing::internal::GetCapturedStderr();

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
    GetOutput(save(txt, "usr/lib"););
    ASSERT_EQ(output, "The file usr/lib cannot be written\n");
    remove_all(txt);
}

TEST(show, correct_showing)
{
	text txt = txt_load(inputfile);
	std::string output;
    GetOutput(show(txt);)
    ASSERT_EQ(output, "1234\nqwer\nasdf\nz x c v\n");
    remove_all(txt);
}

TEST(show, show_empty)
{
    text txt = create_text();
    std::string output;
    GetErr(show(txt);)
    ASSERT_EQ(output, "There are already no any lines in the text!\n");
    remove_all(txt);
}

TEST(move, correct_moving)
{
	text txt = txt_load(inputfile);
	std::string output;
	move(txt, 1, 1);
	GetOutput(show(txt););
	ASSERT_EQ(output, "1234\nq|wer\nasdf\nz x c v\n");
	move(txt, 0, 10);
	GetOutput(show(txt););
	ASSERT_EQ(output, "1234|\nqwer\nasdf\nz x c v\n");
	move(txt, 2, -10);
	GetOutput(show(txt););
	ASSERT_EQ(output, "1234\nqwer\n|asdf\nz x c v\n");
	move(txt, -1, 1);
	GetOutput(show(txt););
	ASSERT_EQ(output, "1|234\nqwer\nasdf\nz x c v\n");
	remove_all(txt);
}

TEST(showwordbeginnings, correct_showing)
{
	text txt = txt_load(inputfile);
	std::string output;
	GetOutput(showwordbeginnings(txt););
	ASSERT_EQ(output, "1\nq\na\nzxcv\n");
	remove_all(txt);
}

TEST(showwordbeginnings, show_empty)
{
	text txt = create_text();
	std::string output;
	GetErr(showwordbeginnings(txt););
	ASSERT_EQ(output, "There are already no any lines in the text!\n");
    remove_all(txt);
}

#endif
