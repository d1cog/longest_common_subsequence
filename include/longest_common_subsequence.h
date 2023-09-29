#ifndef LONGEST_COMMON_SUBSEQUENCE
#define LONGEST_COMMON_SUBSEQUENCE
#include <stddef.h>

size_t longest_common_subsequence(const char *word_to_check, const char *word_to_compare);

size_t **allocate2DSizeTArray(size_t height, size_t width);

size_t max(size_t a, size_t b);
#endif // LONGEST_COMMON_SUBSEQUENCE