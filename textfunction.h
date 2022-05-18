#ifndef FUNCTION_H
#define FUNCTION_H
#include<iostream>
#include<string>
#include<cstdio>
#include<fstream>
#include<vector>
#include<cctype>
using namespace std;


void load_file();
void Adding_content();
void display();
void Empty_file();
void Encrypt_the_file_content();
void Decrypt_the_file_content();
void Merge_another_file();
void vector_of_word();
void Count_the_number_of_words();
void Count_the_number_of_characters(); 
void Count_the_number_of_lines();
void Search_for_a_word_in_the_file();
void Count_the_number_of_times_a_word_exists_in_the_file();
void Turn_the_content_to_upper_case();
void Turn_the_content_to_lower_case();
void Turn_file_content_to_first_caps();
void Save();
vector<string> word;


string text = "";
fstream textfile, newtextfile; char fileName[81], newfile[81];


#endif FUNCTION_H