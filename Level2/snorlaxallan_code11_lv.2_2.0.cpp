#include <iostream>
#include <vector>
using namespace std;
int h, n, K, C, num;
int count = 0;
int sum = 0;
vector<int>zero_and_one, code, decode_;    
vector<vector<int>>type_in, decode;
vector<vector<int>>code11 = {{1, 0, 0, 0, 0}, {1, 0, 0, 1, 0}, {0, 0, 0, 1, 1}, 
                             {1, 0, 1, 0, 0}, {0, 1, 1, 0, 0}, {1, 1, 0, 0, 0},
                             {0, 0, 1, 0, 1}, {0, 1, 0, 0, 1}, {1, 0, 0, 0, 1},
                             {0, 0, 0, 0, 1}, {0, 0, 1, 0, 0}, {0, 0, 1, 1, 0}};
bool gate = true;
bool code_type_or_not = false;
bool reverse = false;

int type();
int start_end_check();
int decoding();
int K_C_check();

int main() {
    while (cin >> h) {
        if (h == 0) {
            break;
        }
        type_in.clear();
        code_type_or_not = false;
        reverse = false;
        n = (h + 1) / 6;
        type();
        start_end_check();
        if (code_type_or_not) {
            continue;        
        }
        decoding();
        if (gate) {
            continue;
        } else {
            K_C_check();
        }
    }
    for (int i = 0; i < code.size(); i++) {
        if (code[i] == -1) {
            cout << "Case " << i + 1 << ": " << "bad code";
        } else if (code[i] == -2) {
            cout << "Case " << i + 1 << ": " << "bad C";
        } else if (code[i] == -3) {
            cout << "Case " << i + 1 << ": " << "bad K";
        } else {
            cout << "Case " << i + 1 << ": ";
            for (int j = 0; j < decode[code[i]].size() - 2; j++) {
                if (decode[code[i]][j] == 10) {
                    cout << "-";
                } else {
                    cout << decode[code[i]][j];
                } 
            }       
        } 
        cout << endl;
    }
}
int type(){
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cin >> num;
            for (int j = 0 ; j < 5; j++) {
                cin >> num;
                zero_and_one.push_back(num);
            }
        } else {
            for (int k = 0 ; k < 5; k++) {
                cin >> num;
                zero_and_one.push_back(num);
            }
        }
        type_in.push_back(zero_and_one);
        zero_and_one.clear();
    }
    return 0;
}

int start_end_check(){
    for (int i = 0; i < 5; i++) { 
        if (type_in[0][i] != code11[11][i]) {
            reverse = true;
            break;
        }
    }
    for (int i = 0; i < 5; i++) { 
        if (type_in[n - 1][i] != code11[11][i] && reverse == false) {
            reverse = true;
            break;
        }
    }
    if (reverse == true) {
        for (int i = 4; i > -1; i--) { 
            if (type_in[0][i] != code11[11][4 - i]) {
                code.push_back(-1);
                code_type_or_not = true;
                break;
            }
        }
        for (int i = 4; i > -1; i--) { 
            if (type_in[n - 1][i] != code11[11][4 - i] && code_type_or_not == false) {
                code.push_back(-1);
                code_type_or_not = true;
                break;
            }
        }
    }
    return 0;
}

int decoding() {
    if (reverse == true) {
        for (int i = n - 2; i > 0 ; i--) {
            gate = true;
            for (int k = 0; k < 11; k++) {
                for (int j = 4; j > -1; j--) {
                    if (type_in[i][j] != code11[k][4 - j]) {
                        break;
                    }
                    if (j == 0) {
                        decode_.push_back(k);
                        gate = false;
                    } 
                }
            }
            if (gate) {
                code.push_back(-1);
                decode_.clear();
                break;
            } 
        }
    } else {
        for (int i = 1; i < n - 1; i++) {
            gate = true;
            for (int k = 0; k < 11; k++) {
                for (int j = 0; j < 5; j++) {
                    if (type_in[i][j] != code11[k][j]) {
                        break;
                    }
                    if (j == 4) {
                        decode_.push_back(k);
                        gate = false;
                    }
                }
            }
            if (gate) {
                decode_.clear();
                break;
            }
        }
    }
    return 0;
}

int K_C_check() {
    for (int i = 0; i < n - 4; i++) {
        sum += ((n - i - 5) % 10 + 1) * decode_[i];
    }
    C = sum % 11;
    sum = 0;
    for (int i = 0; i < n - 3; i++) {
        sum += ((n - i - 4) % 9 + 1) * decode_[i];
    }
    K = sum % 11;
    sum = 0;
    if (C != decode_[n - 4]) {
        code.push_back(-2);
    } else if (K != decode_[n - 3]) {
        code.push_back(-3);
    } else {
        decode.push_back(decode_);
        decode_.clear();
        code.push_back(count);
        count++;
    }
    return 0;
}
