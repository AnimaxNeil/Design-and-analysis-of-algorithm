// Write a program to determine the LCS of two given sequences

#include <iostream>
#include <cstring>
using namespace std;

void printLCS(char *sqnc1, char *sqnc2)
{
    int size1 = strlen(sqnc1), size2 = strlen(sqnc2);
    int *table = new int[(size1 + 1) * (size2 + 1)];

    for (int i = 0; i <= size1; i++)
    {
        for (int j = 0; j <= size2; j++)
        {
            if (i == 0 || j == 0)
            {
                table[i * (size2 + 1) + j] = 0;
            }
            else if (sqnc1[i - 1] == sqnc2[j - 1])
            {
                table[i * (size2 + 1) + j] = table[(i - 1) * (size2 + 1) + (j - 1)] + 1;
            }
            else
            {
                table[i * (size2 + 1) + j] = max(table[(i - 1) * (size2 + 1) + j], table[i * (size2 + 1) + (j - 1)]);
            }
        }
    }

    int size3 = table[size1 * (size2 + 1) + size2];
    char *sqnc3 = new char[size3 + 1];
    int i = size1, j = size2, k = size3;
    sqnc3[k] = '\0';
    while (i > 0 && j > 0)
    {
        if (sqnc1[i - 1] == sqnc2[j - 1])
        {
            sqnc3[k - 1] = sqnc1[i - 1];
            i--;
            j--;
            k--;
        }
        else if (table[(i - 1) * (size2 + 1) + j] > table[i * (size2 + 1) + (j - 1)])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << "Sequence 1 :\t" << sqnc1 << "\nSequence 2 :\t" << sqnc2 << "\nLowest Common Subsequence :\t" << sqnc3 << "\t(length=" << size3 << ")\n";
}

int main()
{
    char sqnc1[] = "LGHBGCDFAAXCD", sqnc2[] = "KLAGCDBXAC";
    printLCS(sqnc1, sqnc2);
    cin.get();
    return 0;
}
