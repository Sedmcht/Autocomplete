#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include "Trie.h"


using namespace std;



int main()
{
    TrieNode* MyTrie = getNewNode();
    string line;

    ifstream in("word.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        cout << "Dictionary is loaded successfully";
        int wordCounter = 0;

        while (getline(in, line))
        {
            insert(MyTrie, line);
            ++wordCounter;

            if (!(wordCounter % 100000))
            {
                system("cls");
                cout << "Building a prefix tree " << wordCounter << " words uploaded" << endl;
            }
        }
    }
    else
    {
        cout << "Unable to open dictionary file";
        return -1;
    }

    in.close();

    cout << "The creation of the prefix tree has been successfully completed, please enter the text in Russian" << endl;

    string input;
    vector<string> result;

    while (true)
    {


        char ch = _getch();

        if (ch != 8 && (ch < 48 || ch > 57))
            input += ch;

        if (ch == 8 && input.size() > 0)
            input.pop_back();

        if (result.size() > ch - 48 && (ch > 48 || ch < 57) && input.size() > 0)
            input = result[ch - 48];

        system("cls");

        cout << input << "\n" << endl;

        if (input.size() > 0)
        {
            result = finisher(MyTrie, input);

            int cl = 0;

            for (auto string : result)
            {
                cout << cl << " " << string << endl;
                cl++;
            }

            if (result.size())
                cout << "\nPlease use the 0-9 keys to autocomplete the word";
            else
                cout << "\nNo matching words found";
        }


    }


}
