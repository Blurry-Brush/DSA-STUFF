#include <bits/stdc++.h>

using namespace std;

int main()
{

    int x = 0;
    int y = 0;
    char route[100];

    cin.getline(route, 100);

    for (int i = 0; route[i] != '\0'; i++)
    {
        switch (route[i])
        {
        case 'N':
            y++;

            break;

        case 'S':

            y--;

            break;

        case 'E':
            x++;

            break;

        case 'W':
            x--;

            break;
        }
    }
    string ans = (0);

    if (x >= 0 and y >= 0)
    {
        while (x >= 0)
        {
            cout << 'E';
            x--;
        }
        while (y >= 0)
        {
            cout << 'N';
            y--;
        }
    }

    //2nd question-find out the  largest sentence

    int n;
    cin >> n;

    //after n,backslash n is also consumed by getline,use cin.get to consume that

    cin.get();
    int largest_len = 0;

    char sentence[1000];
    char largest[1000];
    while (n--)
    {
        cin.getline(sentence, 1000, '\n');

        int cur = strlen(sentence);
        if (cur > largest_len)
        {
            largest_len = cur;

            strcpy(largest, sentence);
        }
    }
    cout << largest << endl;

    //3-string encoding
    //leetcode

    int compress(vector<char> & chars)
    {
        int n = chars.size();
        string temp;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 1;

            while (i < n - 1 and chars[i + 1] == chars[i])
            {
                count++;
                i++;
            }

            chars.push_back(chars[i]);
            //ans++;
            if (count > 1)
            {
                temp = to_string(count);
                for (int k = 0; k < temp.size(); k++)
                {
                    chars.push_back(temp[k]);
                }
            }
        }

        chars.erase(chars.begin(), chars.begin() + n);
        /*for (auto value : chars) {
        cout << value << " ";
    }*/

        return (chars.size());

        return 0;
    }