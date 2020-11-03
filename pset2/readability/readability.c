#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct WordsAndSentencesAndLetters
{
    int words;
    int sentences;
    int letters;
};


/* Using touples to return multiple values: https://stackoverflow.com/questions/2620146/how-do-i-return-multiple-values-from-a-function-in-c */
struct WordsAndSentencesAndLetters CountWordsAndSentencesAndLetters(string text)
{
    int whites = 0;
    int sentences = 0;
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        /*   printf("%i ", text[i]); */

        /*Whitespace =32*/
        if (text[i] == 32)
        {
            whites += 1;
        }

        /* Pontuations to end a sentence: "!" = 33, "?" = 63, "." = 46*/
        if (text[i] == 33 || text[i] == 63 || text[i] == 46)
        {
            sentences += 1;
        }

        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            letters += 1;
        }

    }
    if (whites == 0)
    {
        struct WordsAndSentencesAndLetters r = {whites, sentences, letters};
        return r;
    }
    else
    {
        struct WordsAndSentencesAndLetters r = {whites + 1, sentences, letters};
        return r;
    }
}


int main(void)
{
    string text = get_string("Text: ");
    struct WordsAndSentencesAndLetters counted = CountWordsAndSentencesAndLetters(text);

    /*printf("Total words: %d\n", counted.words);
    printf("Total sentences: %d\n", counted.sentences);
    printf("Total letters: %d\n", counted.letters);*/

    float WordsAvg = (float)(counted.letters * 100) / counted.words;
    float SentencesAvg = (float)(counted.sentences * 100) / counted.words;

    /* printf("Words average: %f\n", WordsAvg);
    printf("Sentences average: %f\n", SentencesAvg);*/

    float index = (0.0588 * WordsAvg) - (0.296 * SentencesAvg) - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    if ((index > 0) && (index < 16))
    {
        int grade = round(index);
        printf("Grade %d\n", grade);
    }
    if (index > 15)
    {
        printf("Grade 16+\n");
    }



}


