#include <stdio.h>
#include <math.h>
#include <ctype.h>

int convertNotation(int num, int newNotation) {
    int res = 0;
    int iter = 0;

    while (num > 0) {
        res += num % newNotation * pow(10, iter);
        num /= newNotation;
        ++iter;
    }

    return res;
}

int reverseNum(int num) {
    int res = 0;
    int iter = 0;

    while (num > 0) {
        res += num % 10 * pow(10, iter);
        num /= 10;
        ++iter;
    }

    return res;
}

typedef enum {
    START,
    IN_NUM,
    END
} STATE;

int main() {
    // Выделить предпоследнее десятичное число и распечатать его цифры в системах счисления с основаниями 3, 7 и 11
    // ihsuif   kjhksd     jk jknef123 10102 321 32321 332 0 1123 23231

    char c;
    int kostyl = 0;

    int power;
    int inWord = 0;
    int nums[2] = {-1};
    int currentNum = 0;
    int lastNum = -1;
    int state = START;

    while ((c = getchar()) != 'p') { // CLion не видит EOF потому тут стоит p в качестве заглушки
        switch (state) {
            case START:
                if (isalpha(c)) {
                    inWord = 1;
                    continue;
                }

                if (isspace(c)) {
                    inWord = 0;
                    continue;
                }

                if (isdigit(c) && inWord) continue;

                currentNum = nums[0] != -1; // если первое число есть, то сейчас будем запоминать второе, и наоборот
                ++kostyl;
                power = 0;
                ++state;

            case IN_NUM:
                if (isspace(c)) {
                    ++state;
                } else {
                    if (!isdigit(c)) {
                        nums[currentNum] = -1;

                        state = START;
                        --kostyl;
                        break;
                    }
                    if (nums[currentNum] == -1) nums[currentNum] = 0;

                    nums[currentNum] += (c - '0') * pow(10, power);
                    ++power;
                    break;
                }
            case END:
                lastNum = reverseNum(nums[!currentNum]);
                nums[!currentNum] = -1;

                state = START;
                break;
        }
    }
    
    if (lastNum == -1 || kostyl < 2) {
        printf("NO");
        return 0;
    }
    printf("\nRES:\n 3 notation: %d\n 7 notation: %d\n 11 notation: %d\n",
           convertNotation(lastNum, 3),
           convertNotation(lastNum, 7),
           convertNotation(lastNum, 11));
    return 0;
}


