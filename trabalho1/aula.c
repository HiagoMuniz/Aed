char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int i = 0, j = 0, l = 0;
    char **goodWord = NULL;
    int count = 0;

    int tamanhoPlate = strlen(licensePlate);

    for ( i = 0; i < tamanhoPlate; i++ ){
        tolower(licensePlate[i]);
        for (j = 0; j < 10; j++){
            if (licensePlate[i] == j){
                licensePlate[i] = '$';
            }
        }
    }

    for ( i = 0; i < wordsSize; i++){
        for (j = 0; j < strlen(words[i]); j++){
            for (int k = 0; k < tamanhoPlate; k++){
                if (licensePlate[k] == '$'){
                    break;
                } else if (licensePlate[k] == words[i][j]){
                    count++;
                }
            }
        }
        if (count >= tamanhoPlate){
            goodWord = (char **) realloc(goodWord, (sizeof(char*) * (l+1)));
            goodWord[l] = (char *) realloc(goodWord[l], sizeof(char) * (strlen(words[i]) + 1));
            strcpy(goodWord[l], words[i]);
            l++;
        }

    }

    char *menorWord = (char*) malloc(sizeof(char) * strlen(goodWord[0]) + 2 );
    menorWord = goodWord[0];

    for ( i = 1; i < l; i++){
        if (strlen(goodWord[i]) < strlen(menorWord)){
            menorWord = (char*) realloc(menorWord, sizeof(char) * strlen(goodWord[i]) + 1 );
            menorWord = goodWord[i];
        }
    }

    return menorWord;

}

/*
            for (int k = 0; k < tamanhoPlate; k++){
                if (licensePlate[k] == words[i][j] || licensePlate[k] == '$'){
                    count++;
                }
            }
*/