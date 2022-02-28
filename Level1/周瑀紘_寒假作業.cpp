#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
    ifstream num;
    num.open("test.txt");

    int total;
    num >> total;

    string nums[total];
    for (int i = 0; i < total; i++) {
        num >> nums[i];
    }

    if (nums[0] == "0" && nums[1] == "1" && nums[2] ==        "1" && nums[3] == "0" && nums[4] == "0") {
        reverse(nums, nums + total);
    }

    for (int i = 5; i < total; i += 6) {
        nums[i] = "z";
    }

    int j = 5, spacecount = 1;
    for (int i = 0; i < total; i++) {
        if (i == j) {
            j += 6;
            spacecount++;
            continue;
        }
    }
    
    string a[spacecount];
    int x = 0;
    for (int j = 0; j < total; j++) {
        if (nums[j] == "z") {
            x++;
            continue;
        }
        a[x] += nums[j];
    }
    for (int i = 0; i < spacecount; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    string code[11] = {
        "10000",
        "10010",
        "00011",
        "10100",
        "01100",
        "11000",
        "00101",
        "01001",
        "10001",
        "00001",
        "00100",
    };
    vector <int> ans;
    for (int i = 0; i < spacecount; i++) {
        for (int j = 0; j < 11; j++) {
            if (a[i] == code[j]) {
                ans.push_back(j);
            }
        }
    }
    for (int i = 0; i < ans.size() - 2; i++) {
        if (ans[i] == 10) {
            cout << "-";
            continue;
        }
        cout << ans[i];
    }
    
}
