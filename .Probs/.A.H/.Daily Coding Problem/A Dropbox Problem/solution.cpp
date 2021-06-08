/*This problem was asked by Dropbox.

Given a string s and a list of words words, where each word is the same length, find all starting indices of substrings in s that is a concatenation of every word in words exactly once.

For example, given s = "dogcatcatcodecatdog" and words = ["cat", "dog"], return [0, 13], since "dogcat" starts at index 0 and "catdog" starts at index 13.

Given s = "barfoobazbitbyte" and words = ["dog", "cat"], return [] since there are no substrings composed of "dog" and "cat" in s.

The order of the indices does not matter. All characters are lower-case. */

#include <iostream>
#include <algorithm>
#include <string>

#define maxN 100002

typedef long maxn;
typedef long long maxh;
typedef std::string str;

const maxn N = 1e5;
const maxh MOD[2] = { 1e9 + 2277,1e9 + 8277 }, BASE[2] = { 59,67 };

maxn nW, Len;
str w[maxN], s;
maxh hash[2][maxN], pow[2][maxN];


void Prepare() {
    nW = 4, Len = 3;
    w[0] = "hii";
    w[1] = "hel";
    w[2] = "dog";
    w[3] = "cat";
    s = "catdoghiicatheldog";

    pow[0][0] = pow[1][0] = 1;
    for(maxn i = 1; i <= N; i++) for(int p = 0; p < 2; p++) pow[p][i] = (pow[p][i - 1] * BASE[p]) % MOD[p];
}


void Hash(const str &s, maxh hash[2][maxN]) {
    hash[0][0] = hash[1][0] = 0;
    for(maxn i = 1; i <= s.size(); i++) for(int p = 0; p < 2; p++) {
        hash[p][i] = (hash[p][i - 1] * BASE[p] + s[i - 1] - 'a' + 1) % MOD[p];
    }
}


