#include <iostream>
#include <vector>
using namespace std;

void reverseString(string &str)
{
    int n = str.length();
    int si = 0;
    int ei = n - 1;
    while (si < ei)
    {
        char temp = str[si];
        str[si] = str[ei];
        str[ei] = temp;
        si++;
        ei--;
    }
}

// leetcode 2108

bool isPalindrome(string str)
{
    int si = 0, ei = str.length() - 1;

    while (si < ei)
    {
        if (str[si++] != str[ei--])
        {
            return false;
        }
    }
    return true;
}

string firstPalindrome(vector<string> &words)
{
    int n = words.size();

    for (int i = 0; i < n; i++)
    {
        if (isPalindrome(words[i]))
        {
            return words[i];
        }
    }

    return "";
}

// leetcode 125
bool isPalindrome(string s)
{

    int i = 0, j = s.size() - 1;
    if (s.size() <= 1)
    {
        return true;
    }

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    while (i < j)
    {
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')))
        {
            i++;
            continue;
        }
        if (!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9')))
        {
            j--;
            continue;
        }
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

void generateSubstring(string &str)
{
    int n = str.length();
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            for (int k = i; k <= j; k++)
            {
                cout << str[k];
            }
            cout << endl;
        }
    }
}

void generateSubstringTwo(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        for (int len = 1; i + len <= str.length(); len++)
        {
            cout << (str.substr(i, len)) << endl;
        }
    }
}

void generatePalindromicSubstrings(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        for (int len = 1; i + len <= str.length(); len++)
        {
            string temp = str.substr(i, len);
            if (isPalindrome(temp))
            {
                cout << temp << endl;
            }
        }
    }
}

// leetcode 3

int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    if (n <= 1)
    {
        return n;
    }

    int si = 0;
    int ei = 0;
    int count = 0;
    int len = 0;

    vector<int> map(128, 0);

    while (ei < n)
    {
        if (map[s[ei++]]++ > 0)
        {
            count++;
        }

        while (count > 0)
        {
            if (map[s[si++]]-- > 1)
            {
                count--;
            }
        }

        len = max(len, ei - si);
    }
    return len;
}
int main()
{
    string str = "Nishtha Goyal";
    reverseString(str);
    cout << str << endl;
    // cout<<str[2]<<endl;

    // char arr[5] = {'a', 'e', 'i', 'o', 'u'};

    // string fullName;
    // getline(cin, fullName);

    // // reverse a string

    // cout<<fullName<<endl;
}