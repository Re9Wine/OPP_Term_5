using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

void firstTask();
vector<string> splitText(string, string);
string swapEvenAndOddWords(vector<string>, string);

void secondTask();
void printWhatCharacter(char);
const string RussianCharacters = "абвгдеёжзиклмнопрстуфхцчъыьэюя";
const string Digits = "0123456789";
const string LatinCharacters = "abcdefzhklmnopqrstvx";

void thirdTask();
string removeSingleLetterWords(string, string);

void fourthTask();
int findCountOfWordsThatStartAndEndWithTheSameLetters(char[]);

int main()
{
    thirdTask();
}

void firstTask() {
    string separator = " ";
    string text;

    cout << "Enter >= 2 words: ";
    getline(cin, text);

    vector<string> words = splitText(text, separator);

    cout << "Swaped even and odd words:" << endl;
    cout << swapEvenAndOddWords(words, separator) << endl;
}

vector<string> splitText(string text, string separator) {
    bool flag = true;
    int firstSeparatorIndex = -1;
    int secondSeparatorIndex = text.find(separator, firstSeparatorIndex + 1);
    vector<string> words;

    while (flag) {
        words.push_back(text.substr(firstSeparatorIndex + 1, secondSeparatorIndex - firstSeparatorIndex - 1));

        firstSeparatorIndex = secondSeparatorIndex;
        secondSeparatorIndex = text.find(separator, firstSeparatorIndex + 1);

        if (firstSeparatorIndex == -1) {
            flag = false;
        }
    }

    return words;
}

string swapEvenAndOddWords(vector<string> words, string separator) {
    string text = words[words.size() - 1];

    for (int i = 0; i < (int)(words.size() - 1); i++) {
        text += separator;
        text += words[i];
    }

    return text;
}

//--------------------------------------------------------------------

void secondTask() {
    char symbol;

    cout << "Enter character:";
    cin >> symbol;

    printWhatCharacter(symbol);
}

void printWhatCharacter(char symbol) {
    if (strchr(RussianCharacters.c_str(), tolower(symbol)) != NULL) {
        cout << "rus" << endl;
    }
    else if (strchr(LatinCharacters.c_str(), tolower(symbol)) != NULL) {
        cout << "lat" << endl;
    }
    else if (strchr(Digits.c_str(), symbol) != NULL) {
        cout << "digit" << endl;
    }
    else {
        cout << "unknown character" << endl;
    }
}

//------------------------------------------------------------------------------------------------------------------

void thirdTask() {
    string separator = " ";
    string text;

    cout << "Enter text: ";

    getline(cin, text);

    cout << "Text without single letter" << endl;
    cout << removeSingleLetterWords(text, separator) << endl;
}

string removeSingleLetterWords(string text, string separator)
{
    bool flag = true;
    string word;
    string buffer;
    int firstSeparatorIndex = -1;
    int secondSeparatorIndex = text.find(separator, firstSeparatorIndex + 1);


    while (flag) {
        word = text.substr(firstSeparatorIndex + 1, secondSeparatorIndex - firstSeparatorIndex - 1);

        if (size(word) == 1) {
            buffer = text.substr(secondSeparatorIndex + 1);

            if (size(text) - firstSeparatorIndex != 2) {
                text.insert(firstSeparatorIndex + 1, buffer);

                if (firstSeparatorIndex != -1) {
                    secondSeparatorIndex -= 2;
                }
                else {
                    secondSeparatorIndex = 0;
                }

                text.resize(size(text) - size(buffer) - 2);
            }
            else {
                text.resize(size(text) - 2);
            }
        }

        firstSeparatorIndex = secondSeparatorIndex;
        secondSeparatorIndex = text.find(separator, firstSeparatorIndex + 1);

        if (firstSeparatorIndex == -1) {
            flag = false;
        }
    }

    return text;
}

//------------------------------------------------------------------------------------------------------------------

void fourthTask() {
    char text[50];

    cout << "Enter text in capital letters in russian language: ";
    cin.getline(text, size(text));

    int wordsCount = findCountOfWordsThatStartAndEndWithTheSameLetters(text);

    cout << "Number of word that start and end with the same letters = " << wordsCount << endl;
}

int findCountOfWordsThatStartAndEndWithTheSameLetters(char text[]) {
    int sum = 0;
    bool flag = true;
    char* word = strtok(text, " ");

    while (flag) {
        if (word == NULL) {
            flag = false;
        }
        else {
            if (word[0] == word[strlen(word) - 1]) {
                sum++;
            }

            word = strtok(NULL, " ");
        }
    }

    return sum;
}
