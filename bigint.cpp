#include <iostream>

using namespace std;

string add_two_str(string n_1, string n_2);
string sub_two_str(string n_1, string n_2);

int main(void)
{
    string n_1, n_2;
    
    cout << "First number   >> ";
    cin >> n_1;
    cout << "Second number  >> ";
    cin >> n_2;
    cout << "Sum            >> " << add_two_str(n_1, n_2) << endl;
    cout << "Sub            >> " << sub_two_str(n_1, n_2) << endl;

    return 0; 
}

string add_two_str(string n_1, string n_2)
{
    if (n_1.length() < n_2.length())
    {
        while (n_1.length() != n_2.length())
        {
            n_1 = '0' + n_1;
        }
    } else
    {
        while (n_1.length() != n_2.length())
        {
            n_2 = '0' + n_2;
        }
    }
    
    int sum, carry = 0;
    string result = "";
    for (size_t i = n_1.length(); 0 < i; i--)
    {
        sum = (n_1[i - 1] - '0') + (n_2[i - 1] - '0') + carry;

        if (10 <= sum)
        {
            sum -= 10;
            carry = 1;
        } else
        {
            carry = 0;
        }

        result = to_string(sum) + result;
    }

    if (carry == 1)
    {
        result = '1' + result;
    }
    
    return result;
}

string sub_two_str(string n_1, string n_2)
{
    bool negative_result = false;
    if (n_1.length() < n_2.length())
    {
        while (n_1.length() != n_2.length())
        {
            n_1 = '0' + n_1;
        }
        swap(n_1, n_2);
        negative_result = true;
    } else
    {
        while (n_1.length() != n_2.length())
        {
            n_2 = '0' + n_2;
        }
        for (size_t i = 0; i < n_1.length(); i++)
        {
            if (n_1[i] - '0' < n_2[i] - '0')
            {
                swap(n_1, n_2);
                negative_result = true;
            } else
            {
                break;
            }
        }
    }

    string result = "";
    int sub, borrow = 0;
    for (size_t i = n_1.length(); 0 < i; i--)
    {
        sub = (n_1[i - 1] - n_2[i - 1] - borrow);

        if (sub < 0)
        {
            sub += 10;
            borrow = 1;
        } else
        {
            borrow = 0;
        }

        result = to_string(sub) + result;
    }
    
    while (result[0] == '0' && result.length() != 1)
    {
        result.erase(0, 1);
    }

    if (negative_result == true)
    {
        result = '-' + result;
    }

    return result;
}
