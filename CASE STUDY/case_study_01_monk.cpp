/*
PROBLEM STATEMENT:
A monk came to Martin's college. Martin had arranged Manavadhana for the monk
before students. Manavadhana means attention to N things at the same time.
N students want to participate in the event and ask questions to Monk and
prove him wrong.
Martin explained the process of Manavadhana as follows:
The monk imagines a clockwise rotating wheel that has alphabets written
from 'a' to 'z' in alphabetical order. He creates a sequence of characters.
Students will ask N questions in the form:
1) START n c
2) REVERSE n

START n c:
Indicates how many times character 'c' occurred when the first 'n' characters
are read in the sequence.
REVERSE n:
Indicates that after reading 'n' characters, the monk starts reading
all characters in reverse order.
For every START n c query, the student expects an immediate answer.

INPUT FORMAT:
- The first line contains integer N (number of students' questions).
- The next N lines contain queries of the form:
"START n x" or "REVERSE n"
- Queries are given chronologically.
- Values of n are strictly increasing.
- x is a lowercase English alphabet.

CONSTRAINTS:
1 ≤ N ≤ 100000
1 ≤ n ≤ 10^9

OUTPUT FORMAT:
For each query of the form "START n x", print the total number of times
the letter 'x' occurs in the first 'n' spoken letters.
Print each result on a new line in the order of queries.

SAMPLE INPUT 1:
5
START 3 c
START 4 b
REVERSE 5
START 7 c
START 12 y

SAMPLE OUTPUT 1:
1
1
2
1

EXPLANATION:
START 3 c  -> a b c      -> c occurs 1 time
START 4 b  -> a b c d    -> b occurs 1 time
REVERSE 5  -> direction reversed after abcde
START 7 c  -> a b c d e d c -> c occurs 2 times
START 12 y -> a b c d e d c b a z y x -> y occurs 1 time

SAMPLE INPUT 2:
3
START 2 z
REVERSE 2
START 5 a

SAMPLE OUTPUT 2:
0
2
*/

/*
WHAT I UNDERSTOOD:
The monk continuously speaks letters in alphabetical order from a to z. 
When a REVERSE query appears, he continues speaking the same letters 
but in reverse alphabetical order. 
For START queries, we count how many times a given letter has appeared so far.
*/

#include <bits/stdc++.h>
using namespace std;
//simple simulation approach
int main()
{
    int Q;
    cout << "Enter number of queries: ";
    cin >> Q;
    bool forward = true;        // true = a to z, false = z to a
    char curr = 'a';            // current letter
    long long spoken = 0;       // total letters spoken
    map<char, long long> freq;  // stores count of each letter
    while(Q--)
    {
        string type;
        cout << "\nEnter query type (START or REVERSE): ";
        cin >> type;
        if(type == "START")
        {
            long long n;
            char c;
            cout << "Enter value of n (total letters to be spoken): ";
            cin >> n;
            cout << "Enter character c (letter to be counted): ";
            cin >> c;
            // Speak letters until total spoken becomes n
            while(spoken < n)
            {
                freq[curr]++;   // count current letter
                spoken++;       // increase spoken count
                // move to next letter
                if(forward)
                {
                    if(curr == 'z') curr = 'a';
                    else curr++;
                }
                else
                {
                    if(curr == 'a') curr = 'z';
                    else curr--;
                }
            }
            cout << "Count of letter '" << c << "' is: "<< freq[c] << endl;
        }
        else if(type == "REVERSE")
        {
            long long n;
            cout << "Enter value of n (after which direction changes): ";
            cin >> n;
            // Speak letters until total spoken becomes n
            while(spoken < n)
            {
                freq[curr]++;
                spoken++;
                if(forward)
                {
                    if(curr == 'z') curr = 'a';
                    else curr++;
                }
                else
                {
                    if(curr == 'a') curr = 'z';
                    else curr--;
                }
            }
            forward = !forward;   // reverse direction
            cout << "Direction reversed!\n";
        }
        else
        {
            cout << "Invalid query type!\n";
        }
    }
    return 0;
}
