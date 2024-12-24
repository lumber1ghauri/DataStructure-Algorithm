#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> findOccurrences(const string &pattern, const string &text)
{
    vector<int> result;
    int patternLength = pattern.length();
    int textLength = text.length();
    for (int i = 0; i <= textLength - patternLength; i++)
    {
        bool matchFound = true;
        for (int j = 0; j < patternLength; j++)
        {
            if (text[i + j] != pattern[j])
            {
                matchFound = false;
                break;
            }
        }
        if (matchFound)
        {
            result.push_back(i);
        }
    }

    return result;
}

int main()
{
    string text = "abcabdddddab";
    string pattern = "ab";

    vector<int> occurrences = findOccurrences(pattern, text);

    if (occurrences.empty())
    {
        cout << "Pattern not found!" << endl;
    }
    else
    {
        cout << "Pattern found at indexes: ";
        for (int index : occurrences)
        {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}
