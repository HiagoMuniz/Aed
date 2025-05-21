int maxRepeating(char* sequence, char* word) {
    int i = 0;
    int len = strlen(word);

    char wordVault[len +1];
    strcpy(wordVault, word);

    char *growingWord = (char *) malloc(strlen(sequence) + strlen(word) + 1 );
    strcpy(growingWord, word);

    while (strstr(sequence, growingWord)){
        i++;
        strcat(growingWord, wordVault);
    }

    free(growingWord);

    return i;
}