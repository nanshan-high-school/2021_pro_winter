#include <bits/stdc++.h>
using namespace std;

int checkc(string decoded){
    int n;
    n = decoded.length() - 2;
    int c = 0;
    for(int i = 1; i <= n; i++){
        int cn;
        switch (decoded[i - 1]){
            case '0':
                cn = 0;
                break;
            case '1':
                cn = 1;
                break;
            case '2':
                cn = 2;
                break;
            case '3':
                cn = 3;
                break;
            case '4':
                cn = 4;
                break;
            case '5':
                cn = 5;
                break;
            case '6':
                cn = 6;
                break;
            case '7':
                cn = 7;
                break;
            case '8':
                cn = 8;
                break;
            case '9':
                cn = 9;
                break;
            case '-':
                cn = 10;
                break;
            default:
                break;
        }
        c += (((n - i) % 10 + 1) * cn);
    }
    c %= 11;
    return c;
}

int checkk(string decoded){
    int n;
    n = decoded.length() - 2;
    int k = 0;
    for(int i = 1; i <= n + 1; i++){
        int cn;
        switch (decoded[i - 1]){
            case '0':
                cn = 0;
                break;
            case '1':
                cn = 1;
                break;
            case '2':
                cn = 2;
                break;
            case '3':
                cn = 3;
                break;
            case '4':
                cn = 4;
                break;
            case '5':
                cn = 5;
                break;
            case '6':
                cn = 6;
                break;
            case '7':
                cn = 7;
                break;
            case '8':
                cn = 8;
                break;
            case '9':
                cn = 9;
                break;
            case '-':
                cn = 10;
                break;
            default:
                break;
        }
        k += (((n - i + 1) % 9 + 1) * cn);
    }
    k %= 11;
    return k;
}

void check(int z, int a, string str, bool rvs){
    if(rvs) reverse(str.begin(), str.end());
    if((a - 5) % 6 != 0){
        cout << "Case " << z << ": bad code\n";
        return;
    }
    for(int i = 5; i < a; i += 6){
        if(str[i] == '1'){
            cout << "Case " << z << ": bad code\n";
            return;
        }
    }
    string strouo;
    strouo = str.substr(a - 5, 5);
    if(strouo != "00110"){
        cout << "Case " << z << ": bad code\n";
        return;
    }
    string decoded = "";
    for(int i = 6; i <= (a - 11); i += 6){
        string str2;
        str2 = str.substr(i, 5);
        if(str2 == "10000") decoded += "0";
        else if(str2 == "10010") decoded += "1";
        else if(str2 == "00011") decoded += "2";
        else if(str2 == "10100") decoded += "3";
        else if(str2 == "01100") decoded += "4";
        else if(str2 == "11000") decoded += "5";
        else if(str2 == "00101") decoded += "6";
        else if(str2 == "01001") decoded += "7";
        else if(str2 == "10001") decoded += "8";
        else if(str2 == "00001") decoded += "9";
        else if(str2 == "00100") decoded += "-";
        else{
            cout << "Case " << z << ": bad code\n";
            return;
        }
    }
    int n = decoded.length();
    int c;
    c = checkc(decoded);
    if(((int)(decoded[n - 2] - '0') != c && c != 10) || (c == 10 && decoded[n - 2] != '-')){
        cout << "Case " << z << ": bad C\n";
        return;
    }
    int k;
    k = checkk(decoded);
    if(((int)(decoded[n - 1] - '0') != k && k != 10) || (k == 10 && decoded[n - 1] != '-')){
        cout << "Case " << z << ": bad K\n";
        return;
    }
    cout << "Case " << z << ": ";
    for(int i = 0; i < n - 2; i++){
        cout << decoded[i];
    }
    cout << "\n";
}

int main(){
    int z = 1;
    while(1){
        int a;
        cin >> a;
        if(a == 0) break;
        else {
            double b[a];
            double min1 = 9999, max1 = -1;
            string str = "";
            for(int i = 0; i < a; i++){
                cin >> b[i];
            }
            for(int i = 0; i < a; i++){
                min1 = min(min1, b[i]);
                max1 = max(max1, b[i]);
            }
            double min2, max2;
            min2 = round((min1 + max1) / 3);
            max2 = 2 * min2;
            bool wrong = 0;
            for(int i = 0; i < a; i++){
                if(b[i] >= min2 * 0.95 && b[i] <= min2 * 1.05){
                    str += "0";
                }
                else if(b[i] >= max2 * 0.95 && b[i] <= max2 * 1.05){
                    str += "1";
                }
                else{
                    wrong = 1;
                    cout << "Case " << z << ": bad code\n";
                    break;
                }
            }
            bool rvs;
            if(!wrong){
                if(str.substr(0, 5) == "00110"){
                    rvs = 0;
                    check(z, a, str, rvs);
                }
                else if(str.substr(0, 5) == "01100"){
                    rvs = 1;
                    check(z, a, str, rvs);
                }
                else if (!wrong){
                    cout << "Case " << z << ": bad code\n";
                }
            }
        }
    z++;
    }
}
