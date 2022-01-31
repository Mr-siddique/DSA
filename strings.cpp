#include <bits/stdc++.h>
using namespace std;
//getline(cin,variable name,character to stop(optional))=>instead of cin>>to take input as string we use getline bcs it takes enter as delemeter by default not empty charachter
bool palindromeCheck(string str)
{
    int i = 0, j = str.length() - 1;
    while (i < j)
    {
        if (str[i++] != str[j--])
            return false;
    }
    return true;
}
bool checkSubsequence(string str1, string str2)
{
    int i = 0, j = 0;
    while (i < str1.length() && j < str2.length())
    {
        if (str1[i] == str2[j])
            j++;
        i++;
    }
    return j == str2.length();
}
bool checkSubsequence(string str1, string str2, int m, int n)
{
    // 2 1
    //  1 1
    if (n == 0)
        return true;
    if (m == 0)
        return false;
    else if (str1[m - 1] == str2[n - 1])
        return checkSubsequence(str1, str2, m - 1, n - 1);
    else
        return checkSubsequence(str1, str2, m - 1, n);
}
bool checkAnagram(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}
bool checkAnagram2(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;
    unordered_map<char, int> mp;
    for (int i = 0; i < str1.length(); i++)
        mp[str1[i]]++;
    for (int i = 0; i < str2.length(); i++)
    {
        if (mp.find(str2[i]) == mp.end())
            return false;
        mp[str2[i]]--;
        if (mp[str2[i]] == 0)
            mp.erase(str2[i]);
    }
    return mp.size() == 0;
}
bool checkAnagram3(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;
    vector<char> res(256);
    for (int i = 0; i < str1.length(); i++)
    {
        res[str1[i]]++;
        res[str2[i]]--;
    }
    for (int i = 0; i < 256; i++)
    {
        if (res[i] != 0)
            return false;
    }
    return true;
}
int leftMostRepeatingChar(string str)
{
    int c_har = 256;
    vector<int> res(c_har);
    for (int i = 0; i < str.length(); i++)
        res[str[i]]++;
    for (int i = 0; i < str.length(); i++)
    {
        if (res[str[i]] > 1)
            return i;
    }
    return -1;
}
int leftMostRepeatingChareff(string str)
{
    int c_har = 256;
    vector<int> res(c_har, -1);
    int mn = INT_MAX;
    for (int i = 0; i < str.length(); i++)
    {
        if (res[str[i]] == -1)
            res[str[i]] = i;
        else
            min(res[str[i]], mn);
    }
    return mn == INT_MAX ? -1 : mn;
}
int leftMostRepeatingChareffcient(string str)
{
    int c_har = 256;
    vector<bool> res(c_har, false);
    int result = -1;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (res[str[i]] == false)
            res[str[i]] = true;
        else
            result = i;
    }
    return result;
}
int leftMostNon_repeatingChar(string str)
{
    int c_har = 256;
    vector<int> res(c_har, -1);
    int result = INT_MAX;
    for (int i = 0; i < str.length(); i++)
    {
        if (res[str[i]] == -1)
            res[str[i]] = i;
        else
            res[str[i]] = -2;
    }
    for (int i = 0; i < c_har; i++)
    {
        if (res[i] >= 0)
            result = min(res[i], result);
    }
    return result == INT_MAX ? -1 : result;
}
string reverseWord(string str)
{
    string temp;
    vector<string> res;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            res.push_back(temp);
            temp = "";
        }
        else
            temp += str[i];
    }
    res.push_back(temp);
    str = "";
    for (int i = res.size() - 1; i >= 0; i--)
    {
        str += res[i];
        if (i > 0)
            str += ' ';
    }
    return str;
}
string inPlaceReverseWord(string str)
{
    int start = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            reverse(str.begin() + start, str.begin() + i);
            start = i + 1;
        }
    }
    reverse(str.begin() + start, str.end());
    reverse(str.begin(), str.end());
    return str;
}
void NaivePatternSearching(string str, string pattern)
{
    for (int i = 0; i <= str.length() - pattern.length(); i++)
    {
        int j = i;
        int k = 0;
        while (str[j] == pattern[k] && j < str.length() && k < pattern.length())
        {
            j++;
            k++;
        }
        if (k == pattern.length())
            cout << i << " ";
    }
}
void NaivePatternSearchingDistinct(string str, string pattern)
{
    for (int i = 0; i <= str.length() - pattern.length();)
    {
        int k = 0;
        while (str[i + k] == pattern[k] && k < pattern.length())
        {
            k++;
        }
        if (k == pattern.length())
        {
            cout << i << " ";
        }
        k == 0 ? i++ : i += k;
    }
}
//rabin Karp algorithm
//p->hashvalue of pattern
//t->hashvalue of current window of text
//spurious hit
// m->pattern size
void rkPatternSearch(string txt, string pat, int n, int m)
{
    const int d = 256;
    const int q = 101;
    int h = 1;
    //Compute (d^(M-1))%q
    for (int i = 1; i <= m - 1; i++)
        h = (h * d) % q;
    // complute p and t;
    int p, t;
    p = t = 0;
    for (int i = 0; i < m; i++)
    {
        p = (p * d + pat[i]) % q;
        t = (t * d + txt[i]) % q;
    }
    for (int i = 0; i <= n - m; i++)
    {
        //chceck for hit
        if (p == t)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
                if (txt[i + j] != pat[j])
                {
                    flag = false;
                    break;
                }
            if (flag == true)
                cout << i << " ";
        }
        //implement rolling hash
        if (i < n - m)
        {
            t = ((d * (t - txt[i] * h)) + txt[i + m]) % q;
            if (t < 0)
                t = t + q;
        }
    }
}
// abacabad
// 0 0 1 0 1 0 6 0
// abbabb
// 0 0 0 1  2 0
int longestPrefSuff(string str, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        bool flag = true;
        for (int j = 0; j < i; j++)
            if (str[j] != str[n - i + j])
                flag = false;
        if (flag == true)
            return i;
    }
    return 0;
}
vector<int> naiveLps(string str)
{
    vector<int> res(str.length());
    for (int i = 0; i < str.length(); i++)
        res[i] = longestPrefSuff(str, i + 1);
    return res;
}
// }
vector<int> lps(string str)
{
    int len = 0;
    vector<int> res(str.length(), 0);
    int i = 1;
    while (i < str.length())
    {
        if (str[i] == str[len])
        {
            len++;
            res[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                res[i] = 0;
                i++;
            }
            else
                len = res[len - 1];
        }
    }
    return res;
}
//len=lps value of index i-1
// ababacab
void kmpPatternMatching(string str, string pattern)
{
    int n = str.length();
    int m = pattern.length();
    vector<int> LPS = lps(m);
    int i = 0, j = 0;
    while (i < n)
    {
        if (str[i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << i - j << " ";
            j = LPS[j - 1];
        }
        else
        {
            if (j == 0)
                i++;
            else
                j = LPS[j - 1];
        }
    }
}
bool checkRotation(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;
    int i = 0;
    int n = str1.length();
    while (i < n)
    {
        if (str1[0] == str2[i])
            break;
        i++;
    }
    if (i == n)
        return false;
    int count = 0;
    int j = 0;
    while (j < n)
    {
        if (str1[i] == str2[j])
        {
            j++;
            i = (i + 1) % n;
            count++;
        }
        else
            break;
    }
    if (count == n)
        return true;
    return false;
}
bool stlCheckRotation(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;
    return ((str1 + str1).find(str2) != string::npos);
}
bool anagramSearch(string str, string pat)
{
    if (str.length() < pat.length())
        return false;
    vector<int> n(256), m(256);
    int i;
    for (int i = 0; i < pat.length(); i++)
    {
        n[pat[i]]++;
        m[str[i]]++;
    }
    while (i < str.length())
    {
        if (n == m)
            return true;
        m[str[i]]++;
        m[str[i - pat.length()]]--;
    }
    return false;
}
int lexographicRank(string str)
{
    string temp = str;
    sort(temp.begin(), temp.end());
    int count = 1;
    do
    {
        if (temp == str)
            return count;
        count++;
    } while (next_permutation(temp.begin(), temp.end()));
    return 0;
}
int fact(int n)
{
    int factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial *= i;
    return factorial;
}
int lexographic_rank(string str)
{
    // string str;
    int res = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int j = i + 1;
        int count_smaller = 0;
        while (j < str.length())
        {
            if (str[j] < str[i])
                count_smaller++;
            j++;
        }
        res = res + fact(str.length() - i - 1) * count_smaller;
    }
    return res + 1;
}
int efficient_lexographic_rank(string str)
{
    int n = str.length();
    int res = 1;
    vector<int> count(256);
    int mul = fact(n);
    for (int i = 0; i < n; i++)
        count[str[i]]++;
    for (int i = 1; i < 256; i++)
        count[i] += count[i - 1];
    for (int i = 0; i < n - 1; i++)
    {
        mul = mul / (n - i);
        res += (mul * count[str[i] - 1]);
        for (int j = str[i]; j < 256; j++)
            count[j]--;
    }
    return res;
}
int longestDistinctChar_Substring(string str)
{    
    vector<int> prev(256, -1);
    int n = str.length();
    int initial_index = 0;
    int res = 0;
    for (int j = 0; j < n; j++)
    {
        initial_index = max(initial_index, prev[str[j]] + 1);
        int maxEnd = j - initial_index + 1;
        res = max(res, maxEnd);
        prev[str[j]] = j;
    }
    return res;
}
// abcdabc
// int longestDist
main()
{
    cout << palindromeCheck("abca") << endl;
    cout << checkSubsequence("abcd", "da") << endl;
    cout << checkSubsequence("abcd", "da", 4, 2) << endl;
    cout << checkAnagram3("aabca", "abcaa") << endl;
    cout << leftMostRepeatingChar("absd") << endl;
    cout << leftMostNon_repeatingChar("eekks") << endl;
    cout << reverseWord("I Love Coading") << endl;
    cout << inPlaceReverseWord("I love Coading") << endl;
    NaivePatternSearching("AAAAA", "AAA");
    cout << endl;
    NaivePatternSearchingDistinct("GEEKSFORGEEKS", "EKS");
    rkPatternSearch("GEEKSFORGEEKS", "EKS", 13, 3);
    cout << endl;
    vector<int> res = naiveLps("ababacab");
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    res = lps("ababacab");
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    cout << checkRotation("abab", "abba") << endl;
    cout << lexographicRank("STRING") << endl;
    cout << lexographic_rank("STRING") << endl;
    cout << efficient_lexographic_rank("vsrtkjpre") << endl;
    cout << longestDistinctChar_Substring("abac") << endl;
}