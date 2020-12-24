#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define IN 1
#define OUT 0
#define MAX_WORDS 20            // at most MAX_WORDS can be found in the test input string
#define MAX_WORD_LENGTH 50      // no individual word can exceed this length
#define EXCESSIVE_LENGTH_WORD     -1
#define EXCESSIVE_NUMBER_OF_WORDS -2

// results structure
typedef struct word_count_word {
   char text[MAX_WORD_LENGTH + 1];      // allow for the string to be null-terminated
   int count;
} word_count_word_t;

char * parse_string_to_array(char *array_ptr[], char *input_text, int *arraylen,
                             int *err_too_long)
{
    char input_copy[(MAX_WORD_LENGTH * 20) + 1];
    char *temp_word_ptr;
    int state, orig_index, offset, counter, current_word, malloc_ctr, free_ctr;
    orig_index = offset = counter = current_word = malloc_ctr = free_ctr = 0;
    
    // copy to temp array
    strcpy(input_copy, input_text);
    state = OUT;
    // Handle the 'raw' string array until it terminates
    while (input_copy[orig_index] != '\0') {

        // Handle leading single or double quoted word
        if ((orig_index == 0 && input_copy[orig_index] == '\'')
            || (orig_index == 0 && input_copy[orig_index] == '\"')) {
            ++offset;
            --counter;
        }
        else {
            ++orig_index;
            ++counter;
        }
        switch (input_copy[orig_index]) {
            case '\'':
                switch (input_copy[orig_index + 1]) {
                    case 't':
                        continue;
                    case ' ':
                        break;
                    default:
                        break;
                }
            case '!': case ':': case '&': case '@': case '$': case '%': case '^':
            case '.':
                --counter;
                break;
            case ',':
                switch (input_copy[orig_index + 1]) {
                    case '\n': case ' ':
                        orig_index++;
                        break;
                }
            case ' ' : case '\0':
                switch (input_copy[orig_index + 1]) {
                    case '\'': // Handle leading quote after a space
                        ++orig_index;
                    default:
                        if (counter > 50) {
                            *err_too_long = EXCESSIVE_LENGTH_WORD;
                            break;
                        }
                        else {
                            array_ptr[current_word] = malloc((MAX_WORD_LENGTH + 1) * sizeof(char));
                            strncpy(array_ptr[current_word], input_copy + offset, counter);
                            ++malloc_ctr;
                            printf("malloc_ctr is %d\n", malloc_ctr);
                            state = OUT;
                            offset = orig_index;
                            ++offset;
                            ++current_word;
                            ++*arraylen;
                            counter = -1;
                            break;
                        }
                }
            default:
                ;
        }
        if (state == OUT)
            state = IN;

    }
    return *array_ptr;
}

char * convert_to_lower_case(char *array_ptr[], int *arraylen)
{
    // Convert the array of parsed words to lower case
    for (int i = 0; i < *arraylen; ++i) {
        for (int j = 0; j < MAX_WORD_LENGTH + 1; ++j)
            array_ptr[i][j] = tolower(array_ptr[i][j]);
    }
    return *array_ptr;
}

/* Check that if a word already exists in an word_count_word_t array */
int check_exists(word_count_word_t words[], char *search_word_ptr) {
 for (int i = 0; i < MAX_WORDS; ++i) {
        if (strcmp(words[i].text, search_word_ptr) == 0) {
            return 1;
        }
    }
    return 0;
}

word_count_word_t * add_words_to_struct(char *array_ptr[], word_count_word_t *words,
                                        int *arraylen, int *err_excess_wds)
{
    // Add words to word_count_word_t in order of appearance, eliminate duplicates
    int offset, i, j;
    offset = i = j = 0;
    for (i = 0; i < *arraylen; ++i) {
        // check if words struct is full
        if ( (i - offset) >= 20 && (words[i].count > 0) )
            *err_excess_wds = EXCESSIVE_NUMBER_OF_WORDS;
        // if word does not exist, add the word to words struct
        else if (check_exists(words, array_ptr[i]) == 0) {
            strcpy(words[i - offset].text, array_ptr[i]);
        }
        else
            ++offset;
    }
    // Set count property on word struct
    int count;
    for (i = 0; i < MAX_WORDS; ++i) {
        count = 0;
        for (j = 0; j < *arraylen; ++j)
            if (strcmp(words[i].text, array_ptr[j]) == 0)
                count++;
            words[i].count = count;
    }
    return words;
}

int get_unique_words(word_count_word_t words[], int *unique_words)
{
/* Get total unique words in struct */
    for (int i = 0; i < MAX_WORDS; ++i) {
        if (words[i].count > 0)
            unique_words++;
    }
    return *unique_words;
}

int main()
{
    /* Function copies parsed input strings by copying to an array referenced by
     array_ptr. This array is further parsed for duplicates and casing before
     word text and count properties are added to word_count_word_t words */
    
    char *input_text = "one fish two fish red fish blue fish BIG FISH";
    word_count_word_t *words = malloc( (MAX_WORDS + 1) * sizeof(struct word_count_word));
    char **parsed_array_ptr = malloc( (MAX_WORDS + 10) * (MAX_WORD_LENGTH) * sizeof(char) );
    
    int err_too_long, err_excess_wds;
    err_too_long = err_excess_wds = 0;
    
    int arraylen, unique_words;
    arraylen = unique_words = 0;
    
    parse_string_to_array(parsed_array_ptr, input_text, &arraylen, &err_too_long);
    convert_to_lower_case(parsed_array_ptr, &arraylen);
    add_words_to_struct(parsed_array_ptr, words, &arraylen, &err_excess_wds);
    get_unique_words(words, &unique_words);
    
    for (int i = 0; i < arraylen; ++i) {
        free(parsed_array_ptr[i]);
        printf("free_ctr is %d\n", i);
    }
    
    free(parsed_array_ptr);
    free(words);

    for (int i = 0; i < MAX_WORDS; ++i)
        printf("%s %d\n", words[i].text, words[i].count);

    // Return found error codes or final word count
    if (err_too_long == EXCESSIVE_LENGTH_WORD)
        return err_too_long;
    else if (err_excess_wds == EXCESSIVE_NUMBER_OF_WORDS)
        return err_excess_wds;
    else
        return unique_words;
    return 0;
}
