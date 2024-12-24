#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// ######### Fonctions Prototype
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // 1. Prompt the user the text to trait
    string text = get_string("Text: ");

    // printf("%s\n",text);

    // 2. Count the number of letters in the text
    // To do so consider the string as table and coutn only uppercase and lowercase letter, not special characters or punctuation

    int letters = count_letters(text);

    // printf("nbrLetters: %d\n",letters);

    // 3. Count the number of words in the text
    int words = count_words(text);
    // printf("nbrWords: %d\n",words);

    // 4. Count the number of of sentence in the text
    int sentences = count_sentences(text);
    // printf("nbrSentence: %d\n",sentences);

    // 5. calculate S and L:

    // L = (letters/words) * 100;
    float L = ((float)letters / words) * 100;

    // S = (letters/words) * 100;
    float S = ((float)sentences / words) * 100;

    // printf("L= %f, S= %f\n", L, S);

    int index = round((0.0588 * L) - (0.296 * S) - 15.8);

    // printf("index= %d\n", index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

// ########### Count_letters() function #############
int count_letters(string text)
{
    int i = 0, letters = 0;
    for (i = 0; text[i] != '\0'; i++)
    { // ici au lieu de faire (i < length , faire text[i] != '\0' c'est mieux)
        if (isalpha(text[i]))
        { // car les fonctions de <ctype.h> ne prennent en argument qu'un seul caracter a la fois
            letters++;
        }
    }
    return letters;
}
// ########### Count_words() function #############
int count_words(string text)
{
    int space = 0, words = 0; // knowing that the number of words is the number of space +1 (words=space+1)
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]))
        {
            space++;
        }
    }
    words = space + 1;
    return words;
}
// ########### Count_sentences() function #############
int count_sentences(string text)
{
    // To do so count the number of punctuation in the text.
    int punctuation = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        // if(ispunct(text[i])){ // can't use "ispunct()" it's consider all of them as punctuation (! " # $ % & ' ( ) * +, - . / : ;  ? @ [ \ ] ^ _ ` { | } ~)
        //     punctuation++;
        // }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            punctuation++;
        }
    }
    return punctuation;
}
