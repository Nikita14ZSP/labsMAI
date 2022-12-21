#include <stdio.h>
#include <ctype.h>

unsigned int VOWELS = (
        1u << ('e' - 'a') | 1u << ('y' - 'a') | 1u << ('u' - 'a') | 1u << ('o' - 'a') |
        1u << ('a' - 'a') | 1u << ('i' - 'a')
);

int main() {
    char c;
    unsigned int w1 = 0, w2 = 0, num, in_word = 0;

    while ((c = tolower(getchar())) != '1') {
        if (!(isalpha(c) || isspace(c)))
            continue;

        if (in_word == 0 && isalpha(c)) {
            in_word = 1;
            w2 = 0;
        }

        if (in_word && isspace(c)) {

            if ((w1 & w2) == 0 && w1 != 0 && w2 != 0) {
                printf("YES\n");
                return 0;
            }
            in_word = 0;
            w1 = w2;
            w2 = 0;
            continue;
        }

        if (in_word) {
            num = 1u << (c - 'a');

            if ((num | VOWELS) == VOWELS) {
                w2 |= num;
            }
        }


    }
    printf("NO\n");
}




