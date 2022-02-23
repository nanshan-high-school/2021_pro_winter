#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    vector<string> result;

    while (cin >> num) {
        if (num == 0) {
            break;
        }

        if ((num + 1) % 6 != 0) {
            result.push_back("bad code");
            continue;
        }

        int code[num]; 
        for (int i = 0; i < num; i++) {
            cin >> code[i];
        }

        bool correctDirect = 1; 
        if (code[1] == 1) {
            correctDirect = 0;
        }

        if (!correctDirect) {
            int codeChange[num];
            for (int i = 0; i < num; i++) {
                codeChange[i] = code[i];
            }

            int j = num - 1;
            for (int i = 0; i < num; i++) {
                code[i] = codeChange[j];
                j--;
            }
        }

        vector<char> translate;
        bool continueTF = 1;
        for (int i = 0; i < num; i += 6) {
            if (code[i] == 0) {
                if (code[i + 1] == 0) {
                    if (code[i + 2] == 0) {
                        if (code[i + 3] == 0) {
                            if (code[i + 4] == 1) {
                                translate.push_back('9');
                            } else {
                                result.push_back("bad code");
                                continueTF = 0;
                                break;
                            }
                        } else if (code[i + 3] == 1) {
                            if (code[i + 4] == 1) {
                                translate.push_back('2');
                            } else {
                                result.push_back("bad code");
                                continueTF = 0;
                                break;
                            }
                        }
                    } else if (code[i + 2] == 1) {
                        if (code[i + 3] == 1) {
                            if (code[i + 4] == 0) {
                                translate.push_back('s');
                            } else {
                                result.push_back("bad code");
                                continueTF = 0;
                                break;
                            }
                        } else if (code[i + 3] == 0) {
                            if (code[i + 4] == 0) {
                                translate.push_back('-');
                            } else if (code[i + 4] == 1) {
                                translate.push_back('6');
                            } else {
                                result.push_back("bad code");
                                continueTF = 0;
                                break;
                            }
                        }
                    }
                } else if (code[i + 1] == 1) {
                    if (code[i + 2] == 0) {
                        if (code[i + 3] == 0) {
                            if (code[i + 4] == 1) {
                                translate.push_back('7');
                            } else {
                                result.push_back("bad code");
                                continueTF = 0;
                                break;
                            }
                        } else {
                            result.push_back("bad code");
                            continueTF = 0;
                            break;
                        }
                    } else if (code[i + 2] == 1) {
                        if (code[i + 3] == 0) {
                            if (code[i + 4] == 0) {
                                translate.push_back('4');
                            } else {
                                result.push_back("bad code");
                                continueTF = 0;
                                break;
                            }
                        } else {
                            result.push_back("bad code");
                            continueTF = 0;
                            break;
                        }
                    }
                }
            } else if (code[i] == 1) {
                if (code[i + 1] == 1) {
                    if (code[i + 2] == 0) {
                        if (code[i + 3] == 0) {
                            if (code[i + 4] == 0) {
                                translate.push_back('5');
                            } else {
                                result.push_back("bad code");
                                continueTF = 0;
                                break;
                            }
                        } else {
                            result.push_back("bad code");
                            continueTF = 0;
                            break;
                        }
                    } else {
                        result.push_back("bad code");
                        continueTF = 0;
                        break;
                    }
                } else if (code[i + 1] == 0) {
                    if (code[i + 2] == 1) {
                        if (code[i + 3] == 0) {
                            if (code[i + 4] == 0) {
                                translate.push_back('3');
                            } else {
                                result.push_back("bad code");
                                continueTF = 0;
                                break;
                            }
                        } else {
                            result.push_back("bad code");
                            continueTF = 0;
                            break;
                        }
                    } else if (code[i + 2] == 0) {
                        if (code[i + 3] == 1) {
                            if (code[i + 4] == 0) {
                                translate.push_back('1');
                            } else {
                                result.push_back("bad code");
                                continueTF = 0;
                                break;
                            }
                        } else if (code[i + 3] == 0) {
                            if (code[i + 4] == 0) {
                                translate.push_back('0');
                            } else if (code[i + 4] == 1) {
                                translate.push_back('8');
                            } else {
                                result.push_back("bad code");
                                continueTF = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }
        
        if (continueTF == 0) {
        	continue;
		}
		
		int space = 0;
        for (int i = 1; i < translate.size() - 3; i++) {
        	if (translate[i] == '-') {
        		space += ((translate.size() - 4 - i) % 10 + 1) * 10;
			} else {
				space += ((translate.size() - 4 - i) % 10 + 1) * (translate[i] - '0');
			}
		}
		int C = space % 11;
		if (C != (translate[translate.size() - 3] - '0')) {
			result.push_back("bad C");
			continue;
		}
		
		space = 0;
		for (int i = 1; i < translate.size() - 2; i++) {
			if (translate[i] == '-') {
				space += ((translate.size() - 4 - i + 1) % 9 + 1) * 10;
			} else {
				space += ((translate.size() - 4 - i + 1) % 9 + 1) * (translate[i] - '0');
			}
		}
		int K = space % 11;
		if (K != (translate[translate.size() - 2] - '0')) {
			result.push_back("bad K");
			continue;
		}
		
		char correctCode[translate.size() - 4];
		for (int i = 1; i < translate.size() - 3; i++) {
			correctCode[i - 1] = translate[i];
		}

        result.push_back(correctCode);

        cout << endl;
    }
    
    for (int i = 0; i < result.size(); i++) {
        cout << "Case " << i + 1 << ": " << result[i] << endl;
    }
} 
