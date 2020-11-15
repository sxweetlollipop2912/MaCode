// AC, Author: Lam
#include <bits/stdc++.h>
using namespace std;
int test, d;
string mon;
int main()
{
    cin>>test;
    while (test--){
        cin>>d>>mon;
        if (mon=="May"){
            if (d<=20) cout<<"Taurus\n";
            else cout<<"Gemini\n";
            continue;
        }
        if (mon=="Jun"){
            if (d<=21) cout<<"Gemini\n";
            else cout<<"Cancer\n";
            continue;
        }
        if (mon=="Jul"){
            if (d<=22) cout<<"Cancer\n";
            else cout<<"Leo\n";
            continue;
        }
        if (mon=="Aug"){
            if (d<=22) cout<<"Leo\n";
            else cout<<"Virgo\n";
            continue;
        }
        if (mon=="Sep"){
            if (d<=21) cout<<"Virgo\n";
            else cout<<"Libra\n";
            continue;
        }
        if (mon=="Oct"){
            if (d<=22) cout<<"Libra\n";
            else cout<<"Scorpio\n";
            continue;
        }
        if (mon=="Nov"){
            if (d<=22) cout<<"Scorpio\n";
            else cout<<"Sagittarius\n";
            continue;
        }
        if (mon=="Dec"){
            if (d<=21) cout<<"Sagittarius\n";
            else cout<<"Capricorn\n";
            continue;
        }
        if (mon=="Jan"){
            if (d<=20) cout<<"Capricorn\n";
            else cout<<"Aquarius\n";
            continue;
        }
        if (mon=="Feb"){
            if (d<=19) cout<<"Aquarius\n";
            else cout<<"Pisces\n";
            continue;
        }

        if (mon=="Mar"){
            if (d<=20) cout<<"Pisces\n";
            else cout<<"Aries\n";
            continue;
        }
        if (mon=="Apr"){
            if (d<=20) cout<<"Aries\n";
            else cout<<"Taurus\n";
            continue;
        }

    }
    return 0;
}