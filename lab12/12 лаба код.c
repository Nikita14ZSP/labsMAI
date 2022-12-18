#include <stdio.h>
#include <assert.h>
#include <ctype.h>

int powFunc(int num, int power) {
    if (power == 0) {
        return 1;
    }
    int res = 1;
    while (power > 0) {
        res *= num;
        --power;
    }
    return res;
}

int getNewPair(int digit1, int digit2, int pairsDone, int isReversed)  {
    if (isReversed == 1 ? digit1 >= digit2 : digit1 <= digit2) {
        return digit1 * powFunc(10, pairsDone * 2) + digit2 * powFunc(10, pairsDone * 2 + 1);
    } else {
        return digit2 * powFunc(10, pairsDone * 2) + digit1 * powFunc(10, pairsDone * 2 + 1);
    }
}

int reverseNum(int num, int pairsDone, int isOdd) {
    int counter = isOdd == 1 ? 0 : -1;
    int res = 0;

    while (num > 0) {
        res += num % 10 * powFunc(10, pairsDone * 2 - counter++);
        num /= 10;
    }

    return res;
}

void test_powFunc() {
    assert(powFunc(10, 0) == 1);
    assert(powFunc(1, 100) == 1);
    assert(powFunc(10, 2) == 100);
    assert(powFunc(2, 9) == 512);
    assert(powFunc(0, 9) == 0);
}

void test_getNewPair() {
    assert(getNewPair('4' - '0', '1' - '0', 0, 0) == 41);
    assert(getNewPair('1' - '0', '4' - '0', 0, 0) == 41);
    assert(getNewPair('9' - '0', '9' - '0', 0, 0) == 99);
}

void test_reverseNum() {
    assert(reverseNum(123456, 2, 0) == 654321);
    assert(reverseNum(654321, 2, 0) == 123456);
    assert(reverseNum(5454545, 3, 1) == 5454545);
}

void execTests() {
    test_powFunc();
    test_getNewPair();
    test_reverseNum();
}

int main() {
    execTests();

    // попарно по возрастанию
    // 1234 =
    // = 1 * 10**3 + 2 * 10**2 + 3 * 10**1 + 4 * 10**0
    int c;
    int digit1 = -1;
    int digit2 = -1;
    int isOdd = 0;
    int resNum = 0;
    int pairsDone = 0;

    while ((c = getchar()) != 'a') {
        if (isdigit(c) == 0){
            if (resNum == 0) {
                if (digit1 == -1 && digit2 == -1) {
                    continue;
                }

                if (digit1 != -1) {
                    printf("%d ", digit1);
                } else {
                    printf("%d ", digit2);
                }

                digit1 = -1;
                digit2 = -1;
                continue;
            }

            if (digit1 != -1 || digit2 != -1) {
                if (digit1 != -1 && digit2 == -1) {
                    resNum += digit1 * powFunc(10, pairsDone * 2);
                    isOdd = 1;
                } else resNum += getNewPair(digit1, digit2, pairsDone, 0);
            }
            printf("%d ", reverseNum(resNum, pairsDone, isOdd));
            resNum = 0;

            digit1 = -1;
            digit2 = -1;
            isOdd = 0;
            pairsDone = 0;

            continue;
        }

        if (digit1 == -1 || digit2 == -1) {
            if (digit1 == -1) digit1 = c - '0';
            else digit2 = c - '0';
        } else {
            resNum += getNewPair(digit1, digit2, pairsDone, 0);

            digit1 = c - '0';
            digit2 = -1;

            pairsDone++;
        }
    }

    if (digit1 != -1 && digit2 != -1) {
        resNum += getNewPair(digit1, digit2, pairsDone, 0);
        printf("%d", resNum);
    } else if (digit1 != -1) {
        printf("%d", digit1);
    }
    else if (digit2 != -1) {
        printf("%d", digit2);
    }
}
