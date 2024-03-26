#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

string getString(string input_str) {
    int n = input_str.length();

    vector<int> last_occurrence(26, -1);
    unordered_set<char> used_characters;

    for (int i = n - 1; i >= 0; --i) {
        char current_char = input_str[i];

        if (used_characters.find(current_char) == used_characters.end() && last_occurrence[current_char - 'a'] != -1) {
            used_characters.insert(current_char);
            i = last_occurrence[current_char - 'a'];
        }
    }

    string result = "";
    for (int i = 0; i < n; ++i) {
        if (used_characters.find(input_str[i]) == used_characters.end()) {
            result += input_str[i];
            used_characters.insert(input_str[i]);
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string input_str = "abaaa";
    string result = getString(input_str);

    cout << "Result: " << result << endl;

    return 0;
}
