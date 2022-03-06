# Level 4
jackie(檢查碼fail)

#include <iostream>
#include <cstring>
using namespace std;

char start[6] = {'0', '0', '1', '1', '0'};
char startr[6] = {'0', '1', '1', '0', '0'};

char zero[6] = {'1', '0', '0', '0', '0'};
char one[6] = {'1', '0', '0', '1', '0'};
char two[6] = {'0', '0', '0', '1', '1'};
char three[6] = {'1', '0', '1', '0', '0'};
char four[6] = {'0', '1', '1', '0', '0'};
char five[6] = {'1', '1', '0', '0', '0'};
char six[6] = {'0', '0', '1', '0', '1'};
char seven[6] = {'0', '1', '0', '0', '1'};
char eight[6] = {'1', '0', '0', '0', '1'};
char nine[6] = {'0', '0', '0', '0', '1'};
char desh[6] = {'0', '0', '1', '0', '0'};

char zeror[6] = {'0', '0', '0', '0', '1'};
char oner[6] = {'0', '1', '0', '0', '1'};
char twor[6] = {'1', '1', '0','0', '0'};
char threer[6] = {'0', '0', '1','0', '1'};
char fourr[6] = {'0', '0', '1','1', '0'};
char fiver[6] = {'0', '0', '0','1', '1'};
char sixr[6] = {'1', '0', '1','0', '0'};
char sevenr[6] = {'1', '0', '0','1', '0'};
char eightr[6] = {'1', '0', '0','0', '1'};
char niner[6] = {'1', '0', '0','0', '0'};
char deshr[6] = {'0', '0', '1','0', '0'};

char stop[6] = {'0', '0', '1', '1', '0'};
char stopr[6] = {'0', '1', '1', '0', '0'};


char cmp(char arr[]);
char cmpr(char arr[]);

int main() {
    int number = 0;
    int count = 0;
    while(cin >> number){
        count++;
        int n = (number + 1) / 6;
        int c[n][6];
        char code[n][6];
        int narrow = 0;//窄
        float maxn = 0, minn = 0;//窄
        int broad = 0;//寬
        float maxb = 0, minb = 0;//寬
        for (int i = 0; i < n; i++){
            for (int j = 0; j < 6; j++){
                code[i][j] = 0;
                cin >> c[i][j];

                if (i == 0){
                    narrow = c[0][0];
                    broad = narrow * 2;
                    maxn = narrow * 1.05;
                    maxb = broad * 1.05;
                    minn = narrow * 0.95;
                    minb = broad * 0.95;
                }//窄邊與寬邊的長度
                
                if (c[i][j] <= maxn && c[i][j] >= minn){
                    code[i][j] = '0';
                }else if (c[i][j] <= maxb && c[i][j] >= minb){
                    code[i][j] = '1';
                }else{
                    cout << "Case " << count << ": " << "bad code\n";
                    continue;
                }//轉為0和1
                if (i + 1 == n && j + 1 == 5)break;
            }
        }//輸入

        bool r;
        if (memcmp(code[0], start, 5) == 0){
            r = 0;//正
        }else if (memcmp(code[0], stopr, 5) == 0){
            r = 1;//反
        }else{
            cout << "Case " << count << ": " << "bad code\n";
            continue;
        }//正OR反
        //使用memcmp比較兩個陣列
        //memcmp(a, b, 5) ==> 是的時候是0 ==> 錯的時候是 != 0 (疑似是差值)
        
        string num;
        if (r == 0){
            if (cmp(code[0]) != 's' && cmp(code[n - 1]) != 'e'){
                cout << "Case " << count << ": " << "bad code\n";
                continue;
            }else{
                for (int i = 1; i < n - 1; i++){
                    if (cmp(code[i]) != 's' && cmp(code[i]) != 'e' && cmp(code[i]) != 'w'){
                        num += cmp(code[i]);
                    }else {
                        cout << "Case " << count << ": " << "bad code\n";
                        number = 0;
                        break;
                    }
                }
            }
        }else {
            if (cmpr(code[0]) != 's' && cmpr(code[n - 1]) != 'e'){
                cout << "Case " << count << ": " << "bad code\n";
                continue;
            }else{
                for (int i = 1; i < n - 1; i++){
                    if (cmpr(code[i]) != 's' && cmpr(code[i]) != 'e' && cmpr(code[i]) != 'w'){
                        num += cmpr(code[i]);
                    }else {
                        cout << "Case " << count << ": " << "bad code\n";
                        number = 0;
                        break;
                    }
                }
            }
        }//轉換成數字代碼
        
        if (r == 0){
            for (int i = 1; i <= n - 3; i++){
                cout << num[i];
            }
        }else{
            for (int i = n - 1; i >= 2; i--){
                cout << num[i];
            }
        }
        cout << "\n";
        
        int cnum = 0;
        if (r == 0){
            for(int i = 1; i <= n; i++){//剩下檢查碼
                
                if (num[i] != '-')cnum += ((n - i) % 10 + 1) * (num[i] - '0');
                else cnum += ((n - i) % 10 + 1) * 10;
            }
            cnum %= 11;
            char cnumber = cnum + '0';
            if (cnumber != num[n]){
                cout << "Case " << count << ": " << "bad C\n";
                break;
            }
    
            int knum = 0;
            for (int i = 1; i <= n + 1; i++){
                if (num[i] != '-')knum += ((n - i + 1) % 9 + 1) * (num[i] - '0');
                else knum += ((n - i + 1) % 9 + 1) * 10;
            }
            knum %= 11;
            char knumber = knum + '0';
            if (knumber != num[n + 1]){
                cout << "Case " << count << ": " << "bad K\n";
                break;
            }
        }else{
            cnum = 0;
            for(int i = n + 1; i > 1; i--){//剩下檢查碼
                int k = 1;
                if (num[i] != '-') cnum += ((n - k) % 10 + 1) * (num[i] - '0');
                else cnum += ((n - k) % 10 + 1) * 10;
                k++;
            }
            cnum %= 11;
            char cnumber = cnum + '0';
            if (cnumber != num[1]){
                cout << "Case " << count << ": " << "bad C\n" << "C : " << cnum << "\n";
                break;
            }
    
            int knum = 0;
            for (int i = n + 1; i > 0; i--){
                int k = 1;
                if (num[i] != '-') knum += ((n - i + 1) % 9 + 1) * (num[i] - '0');
                else knum += ((n - i + 1) % 9 + 1) * 10;
                k++;
            }
            knum %= 11;
            char knumber = knum + '0';
            if (knumber != num[0]){
                cout << "Case " << count << ": " << "bad K\n";
                break;
            }
        }

        if (r == 0){
            for (int i = 1; i <= n - 4; i++){
                cout << num[i];
            }
        }else{
            for (int i = n - 1; i >= 3; i++){
                cout << num[i];
            }
        }

        if (number == 0)break;//結束

        
    }
} 

char cmp(char arr[]){
    if (memcmp(arr, zero, 5) == 0)return '0';
    else if (memcmp(arr, one, 5) == 0)return '1';
    else if (memcmp(arr, two, 5) == 0)return '2';
    else if (memcmp(arr, three, 5) == 0)return '3';
    else if (memcmp(arr, four, 5) == 0)return '4';
    else if (memcmp(arr, five, 5) == 0)return '5';
    else if (memcmp(arr, six, 5) == 0)return '6';
    else if (memcmp(arr, seven, 5) == 0)return '7';
    else if (memcmp(arr, eight, 5) == 0)return '8';
    else if (memcmp(arr, nine, 5) == 0)return '9';
    else if (memcmp(arr, desh, 5) == 0)return '-';
    else if (memcmp(arr, start, 5) == 0)return 's';
    else if (memcmp(arr, stop, 5) == 0)return 'e';
    else return 'w';
}

char cmpr(char arr[]){
    if (memcmp(arr, zero, 5) == 0)return '0';
    else if (memcmp(arr, oner, 5) == 0)return '1';
    else if (memcmp(arr, twor, 5) == 0)return '2';
    else if (memcmp(arr, threer, 5) == 0)return '3';
    else if (memcmp(arr, fourr, 5) == 0)return '4';
    else if (memcmp(arr, fiver, 5) == 0)return '5';
    else if (memcmp(arr, sixr, 5) == 0)return '6';
    else if (memcmp(arr, sevenr, 5) == 0)return '7';
    else if (memcmp(arr, eightr, 5) == 0)return '8';
    else if (memcmp(arr, niner, 5) == 0)return '9';
    else if (memcmp(arr, deshr, 5) == 0)return '-';
    else if (memcmp(arr, startr, 5) == 0)return 's';
    else if (memcmp(arr, stopr, 5) == 0)return 'e';
    else return 'w';
}

## 結果

