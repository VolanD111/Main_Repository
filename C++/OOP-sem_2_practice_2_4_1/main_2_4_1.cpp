#include "newClass_2_4_1.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    int size;
    vector<string> words;
    string name, line, word;
    cin >> name >> size;
    newClass_2_4_1 obj(name, size);
    cout.width(15);
    cout.setf(ios::left);
    cout << obj.get_name() << " " << obj.size << endl;
    getline(cin, line);
    istringstream stream(line);
    while (stream >> word)
    {
        words.push_back(word);
    }
    for (int i = 0; i < words.size(); i++)
    {
        if (obj.add(stoi(words[i])) == false || stoi(words[i]) == 0)
        {
            break;
        }
    }
    cin >> name >> size;
    newClass_2_4_1 obj_2(name, size);
    cout.width(15);
    cout.setf(ios::left);
    cout << obj_2.get_name() << " " << obj_2.size << endl;
    words.clear();
    getline(cin, line);
    istringstream stream2(line);
    while (stream2 >> word)
    {
        words.push_back(word);
    }
    for (int i = 0; i < words.size(); i++)
    {
        if (obj_2.add(stoi(words[i])) == false || stoi(words[i]) == 0)
        {
            break;
        }
    }
    int a = 1, b = 1;
    while (a != 0 || b != 0)
    {
        cout.width(15);
        cout.setf(ios::right);
        cout << a << "\t" << b << endl;
        a = obj.remove();
        b = obj_2.remove();
    }
}