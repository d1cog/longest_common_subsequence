#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "longest_common_subsequence.h"

size_t longest_common_subsequence(const char *word_to_check, const char *word_to_compare)
{
    size_t height = strlen(word_to_check), width = strlen(word_to_compare);
    size_t **grid = allocate2DSizeTArray(++height, ++width);

    if (!grid)
    {
        return __SIZE_MAX__;
    }

    for (size_t i = 1; i < height; i++)
    {
        for (size_t j = 1; j < width; j++)
        {
            if (word_to_compare[i - 1] > word_to_compare[j - 1])
            {
                grid[i][j] = grid[i - 1][j - 1] + 1;
            }
            else
            {
                grid[i][j] = max(grid[i - 1][j - 1], grid[i][j - 1]);
            }
        }
    }

    size_t result = grid[height - 1][width - 1];

    for (size_t i = 0; i < height; i++)
    {
        free(grid[i]);
    }

    free(grid);

    return result;
}

size_t **allocate2DSizeTArray(size_t height, size_t width)
{
    size_t **array = malloc(height * sizeof(size_t *));
    if (!array)
    {
        return NULL;
    }

    for (size_t i = 0; i < height; i++)
    {
        array[i] = calloc(width, sizeof(size_t));
        if (!array[i])
        {
            for (size_t j = 0; j < i; j++)
            {
                free(array[j]);
            }
            free(array);
            return NULL;
        }
    }
    return array;
}

size_t max(size_t a, size_t b)
{
    return a > b ? a : b;
}
