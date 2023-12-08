#include "cs50.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float calculate_letter_average(int letter_count, int word_count);
float calculate_sentence_average(int sentence_count, int word_count);
int calculate_grade(float letter_average, float sentence_average);

int main(void)
{
    string text = get_string("Text: ");

    printf("%i letters\n", count_letters(text));
    printf("%i words\n", count_words(text));
    printf("%i sentences\n", count_sentences(text));
    printf("%.2f letter average\n", calculate_letter_average(count_letters(text), count_words(text)));
    printf("%.2f sentence average\n", calculate_sentence_average(count_sentences(text), count_words(text)));
    int grade_level = calculate_grade(calculate_letter_average(count_letters(text), count_words(text)), calculate_sentence_average(count_sentences(text), count_words(text)));

    if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade_level);
    }
}

int count_letters(string text)
{
    int letter_count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            letter_count++;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            letter_count++;
        }
    }
    return letter_count;
}

int count_words(string text)
{
    int word_count = 1;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            word_count++;
        }
    }
    return word_count;
}

int count_sentences(string text)
{
    int sentence_count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;
        }
    }
    return sentence_count;
}

float calculate_letter_average(int letter_count, int word_count)
{
    float letter_average = ((float)letter_count / word_count) * 100;
    return letter_average;
}

float calculate_sentence_average(int sentence_count, int word_count)
{
    float sentence_average = ((float)sentence_count / word_count) * 100;
    return sentence_average;
}

int calculate_grade(float letter_average, float sentence_average)
{
    float grade = (0.0588 * letter_average - 0.296 * sentence_average - 15.8);
    grade = round(grade);
    return grade;
}
