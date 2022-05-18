#include"textfunction.h"
//______________________________//


char End[10000];

void load_file()
{

    cout << "Enter the name of a file: ";
    cin.getline(fileName, 81);
    textfile.open(fileName, ios_base::in);
    cout << "File " << fileName << " opened.\n";
    if (textfile.fail())
    {
        cout<<"This file is created for you :) "<<endl;
        textfile.open(fileName, ios_base::out);
    }
    else
    {
        char read;
        textfile.get(read);
        while(!textfile.eof())
        {

            text+=read;
            textfile.get(read);

        }
        // textfile>>text;
    }



}

//______________________________//

void Adding_content()

{
    char text2[10000];
    cout<<"Please enter your text: ";
    cin.ignore();
    cin.getline(text2,10000,char(26));
    text+=text2;
    cout<<text;

}

//______________________________//

void display()
{
    cout<<text<<endl;

}

//______________________________//

void Empty_file()
{
    text="";
    cout<<text;
}

//______________________________//

void Encrypt_the_file_content()
{
    string encryption = "";
    int numofshifts=1;

    for (int c = 0; c < text.length(); c++)
    {


        if (text[c] == '\n')
        {
            encryption+='\n';
        }
        else
        {
        encryption += char(int(text[c]) + numofshifts);
        }


    }
    text=encryption;
    cout<<text;
}

//______________________________//

void Decrypt_the_file_content()
{
    string decryption = "";
    int numofshifts=1;

    for (int c = 0; c < text.length(); c++)
    {
        if (text[c] == '\n')
        {
            decryption +='\n';
        }
        else
        {
        decryption += char(int(text[c]) - numofshifts);
        }

    }
    text=decryption;
    cout<<text;

}

//______________________________//

void Merge_another_file()
{   string secText;
    cout << "Enter the name of the second file: ";
    cin.ignore();
    cin.getline(newfile, 81);
    newtextfile.open(newfile, ios_base::in);
    while (newtextfile.fail())
    {
        cout<<"This file doesn't exist\nEnter valid file: "<<endl;
        cin.getline(newfile, 81);
    }
    cout << "File " << newfile << " opened.\n";
    char read;
    newtextfile.get(read);
    while(!newtextfile.eof())
    {

        secText+=read;
        newtextfile.get(read);

    }
    text += '\n';
    text = text + secText;
    // textfile>>text;


   // cout << "Enter the name of the fie you want to merge with:";
    cout << text << endl;
}

//______________________________//
void vector_of_word()
{
    string letters = "";
    int i = 0;

    while (i < text.length())
    {
        if ((text[i] != ' ') && (text[i] != '\n'))
        {
            letters += text[i];
            //i++;
        }
        else // (letters.size() != 0)
        {
            word.push_back(letters);
            letters.clear();
        }
        i++;
    }
    word.push_back(letters);

}
void Count_the_number_of_words()
{
    vector_of_word();
    cout << "The number of words is:" << word.size() << endl;
    word.clear();
}
//______________________________//
void Count_the_number_of_characters()
{
    int count = 0;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != '\n')
        {
            count++;
        }
    }
    cout << "Number of charachters is:" << count << endl;
}
//______________________________//
void Count_the_number_of_lines()
{
    int count = 1;
    for (int i = 0; i < text.length(); i++)
    {
      if (text[i] == '\n')
      {
            ++count;
      }
    }
    if (text == "")
    {
        count = 0;
    }
    cout << "The number of lines is:" << count << endl;
}
//______________________________//
void Search_for_a_word_in_the_file()
{
    string search, upper;
    int s = 0 ;
    vector_of_word();
    cout << "Enter the word you want to search for:";
    cin >> search;
    for (int x = 0; x < search.length(); x++)
    {
        search[x] = toupper(search[x]);
    }



    for (int y = 0; y < word.size(); y++)
    {
        upper = word[y];
        for (int z = 0; z < upper.length(); z++)
        {
            upper[z] = toupper(upper[z]);
        }

        if (search == upper)
        {
            s++;
        }
    }
    if (s > 0)
    {
        cout << "The word exist"<<endl;
        s = 0;
    }
    else
    {
        cout << "Doesn't exist" << endl;
    }


    word.clear();

}
//______________________________//

void Count_the_number_of_times_a_word_exists_in_the_file()
{

   string search, upper;
    int s = 0 , counter = 0;
    vector_of_word();
    cout << "Enter the word you want to search for:";
    cin >> search;
    for (int x = 0; x < search.length(); x++)
    {
        search[x] = toupper(search[x]);
    }



    for (int y = 0; y < word.size(); y++)
    {
        upper = word[y];
        for (int z = 0; z < upper.length(); z++)
        {
            upper[z] = toupper(upper[z]);
        }

        if (search == upper)
        {
            s++;
            counter += 1;
        }
    }
    if (s > 0)
    {
        s = 0;
        cout << "The word exists " << counter << " times" << endl;

    }
    else
    {
        cout << "Doesn't exist" << endl;
    }


    word.clear();

}

//______________________________//

void Turn_the_content_to_upper_case()
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] = toupper(text[i]);
    }
}

//______________________________//

void Turn_the_content_to_lower_case()
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] = tolower(text[i]);
    }
}

//______________________________//

void Turn_file_content_to_first_caps()
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] = tolower(text[i]);
    }

    text[0] = toupper(text[0]);

    for (int i = 0; i < text.length(); i++)
    {
        if ((text[i] == ' ') || (text[i] == '\n'))
        {
            text[i+1] = toupper(text[i+1]);
        }
    }
    cout << text << endl;
}

//______________________________//

void Save()
{
    ofstream textfile(fileName);
    textfile << text;
    textfile.close();
}

//______________________________//