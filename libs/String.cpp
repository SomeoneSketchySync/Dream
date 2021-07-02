#include <iostream>
#include <string>
#include <algorithm>

void getZarr(std::string str, int Z[]) {
    int n = str.length();
    int k;
    int L = 0;
    int R = 0;
    for (int i = 1; i < n; ++i) {
        if (i > R) {
            L = R = i;
            while (R < n && str[R - L] == str[R]) {
                R++;
            }
            Z[i] = R - L;
            R--;
        } else {
            k = i - L;
            if (Z[k] < R - i + 1) {
                Z[i] = Z[k];
            } else {
                L = i;
                while (R < n && str[R - L] == str[R]) {
                    R++;
                }
                Z[i] = R - L;
                R--;
            }
        }
    }
}

std::string goodStr(std::string str, std::string word) {
    std::string concat = word + "$" + str;
    int l = concat.length();
    int Z[l];
    getZarr(concat, Z);
    std::string res;
    int pSize = word.size();
    for (int i = 0; i < l; ++i) {
        if (i + pSize < l - 1 && Z[i + pSize + 1] == pSize) {
            i += pSize - 1;
        } else if (i < str.length()) {
            res += str[i];
        }
    }
    return res;
}

std::string go(std::string i) {
    int fpp = i.find_first_of('(') + 1;
    int lpp = i.find_last_of(')');
    return i.substr(fpp, lpp - fpp);
}

std::string deep(int i, std::string q) {
    std::string last = q;
    for (int e = 0; e < i; e++) {
        last = go(last);
    }
    return last;
}

int count(std::string s, char ch) {
	int count = std::count_if (s.begin(), s.end(),
                            [&ch](char c) {
                                return c == ch;
                            });
	return count;
}

int depth(std::string i) {
		return (count(i,'(') + count(i,')'))/2;
}