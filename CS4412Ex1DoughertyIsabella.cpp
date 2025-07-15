// CS4412Ex1DoughertyIsabella.cpp
//CS4412EX1DoughertyIsabella
//Isabella Dougherty
//8/27/2024
//Exercise 1
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string com[] =
{ "a", "about", "all", "also", "and", "as", "at", "be", "because", "but",
"by", "can", "come", "could", "day", "do", "even", "find", "first", "for",
"from", "get", "give", "go", "have", "he", "her", "here", "him", "his",
"how", "I", "if", "in", "into", "it", "its", "just", "know", "like",
"look", "make", "man", "many", "me", "more", "my", "new", "no", "not",
"now", "of", "on", "one", "only", "or", "other", "our", "out", "people",
"say", "see", "she", "so", "some", "take", "tell", "than", "that", "the",
"their", "them", "then", "there", "these", "they", "thing", "think",
"this", "those", "time", "to", "two", "up", "use", "very", "want", "way",
"we", "well", "what", "when", "which", "who", "will", "with", "would",
"year", "you", "your" };
//Isabella Dougherty 8/26/24: The number of elements in the common word array
int numComWor = (sizeof(com) / sizeof(com[0])) - 1;
int attempts = 0;

//Isabella Dougherty 8/26/24: Adds the word at the indicated index of the common words array to the string "crack"
string crackAdd(string crack, int index) {
    return crack + com[index];
}

//Isabella Dougherty 8/26/24: Compares the first string that is input to the second string that's input, returning whether they are the same or not.
bool compareTo(string pass, string crack)
{
    if (pass == crack) return true;
    else return false;
}

//Isabella Dougherty 8/26/24: Intakes the password and a string that it will be compared to try to find the password
int crackPass(string pass, string crack, int i, int depth) {
    const int MAX_DEPTH = 3;
    attempts++;
    if (compareTo(pass, crack)) {
        return 1;
    }
    if (depth >= MAX_DEPTH) {
        /*cout << "Attempt number ";
        cout << attempts;
        cout << "\n";*/
        return 0;
    }
    for (int j = i; j < numComWor; j++) {
        string newCrack = crackAdd(crack, j);
        if (crackPass(pass, newCrack, 0, depth + 1) == 1) {
            return 1;
        }
    }
    return 0;
}

//Isabella Dougherty 8/26/24: Runs the rest of the code
int main()
{
    string input;
    bool acceptableInput = false;

    string comWordsPrint = "";
    for (int j = 0; j < numComWor; j++) comWordsPrint += com[j] + ", ";

    while (!acceptableInput) {
        cout << "Please enter 1 to 3 words from the list of words provided here: \n";
        cout << comWordsPrint;
        cout << "\n";
        getline(cin, input);
        if (input.length() > 21) {
            cout << "The input word was not in the provided list.";
        }
        else acceptableInput = true;
    }
    cout << "Your input password is: " + input + "\n";

    clock_t start = clock();

    if (crackPass(input, "", 0, 0) == 1) {
        cout << "Password cracked successfully!\n";
        cout << "Total attempts: ";
        cout << attempts;
        cout << "\n";
    }
    else {
        cout << "Password could not be cracked.\n";
        cout << "Total attempts: ";
        cout << attempts; 
        cout << "\n";
    }
    double elapsed_time = (double)(clock() - start) / CLOCKS_PER_SEC;
    cout << "Time taken to crack the password\n" << (elapsed_time) << ".\n";

    return 0;
}