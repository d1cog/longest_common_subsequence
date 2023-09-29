#include <stdio.h>
#include <stdlib.h>
#include "longest_common_subsequence.h"

int main()
{
    const char *word_to_check = "Fosh";
    const char *word_to_compare = "Fort";
    const size_t result = longest_common_subsequence(word_to_check, word_to_compare);
    printf("%zu\n", result);
}