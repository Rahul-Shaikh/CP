#include <iostream>
#include <string>

using namespace std;

string addBin(string s1, string s2)
{
    string ans = "";
    int carry = 0, i = 0;
    reverse(s1.begin(), s1.end()), reverse(s2.begin(), s2.end());
    while (i < s1.size() || i < s2.size() || carry == 1)
    {
        int sum = 0;
        if (i < s1.size())
        {
            sum += (s1[i] - '0');
        }
        if (i < s2.size())
        {
            sum += (s2[i] - '0');
        }

        sum += carry;
        carry = sum / 2;
        ans += to_string(sum % 2);
        i++;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(void)
{
    string s1, s2;
    cout << "Enter 1st number: ";
    cin >> s1;
    cout << "Enter 2nd number: ";
    cin >> s2;

    cout << addBin(s1, s2) << endl;
}