#include"textfunction.h"
#include"textfunction.cpp"
int main()
{
    load_file();
    int choice;
    while (true)
    {
        cout <<"\nPlease user chooses an option to apply :"<<endl;
        cout <<"1-Add new text to the end of the file \n2-Display the content of the file \n3-Empty the file\n4-Encrypt the file content \n5-Decrypt the file content\n6-Merge another file\n7-Count the number of words in the file\n8-Count the number of characters in the file\n9-Count the number of lines in the file\n10-Search for a word in the file\n11-Count the number of times a word exists in the file\n12-Turn the file content to upper case\n13-Turn the file content to lower case\n14-Turn file content to 1st caps\n15- Save\n16-Exit"<<endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            Adding_content();
            break;
        case 2:
            display();
            break;
        case 3:
            Empty_file();
            break;
        case 4:
            Encrypt_the_file_content();
            break;
        case 5:
            Decrypt_the_file_content();
            break;
        case 6:
            Merge_another_file();
            break;
        case 7:
            Count_the_number_of_words();
            break;
        case 8:
            Count_the_number_of_characters(); 
            break;
        case 9:
            Count_the_number_of_lines();
            break;
        case 10:
            Search_for_a_word_in_the_file();
            break;
        case 11:
            Count_the_number_of_times_a_word_exists_in_the_file();
            break;
        case 12:
            Turn_the_content_to_upper_case();
            break;
        case 13:
            Turn_the_content_to_lower_case();
            break;
        case 14:
            Turn_file_content_to_first_caps();
            break;
        case 15:
            Save();
            break;
        case 16:
            cout << "Hope you are happy and satisfied with our App";
            return 0;

        }
    }
    
}