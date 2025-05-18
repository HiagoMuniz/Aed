bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int i = 0, j = 0, k = 0, controle = 0, diferenca = 0;

    int tamanho = strlen(word);

    for (i = 1; i < boardSize-1; i++){    
            for (j = 1; j < *boardColSize-1; j++ ){
            if ( board[i][j] == word[k] && (board[i+1][j] == word[k+1] || (board[i][j+1] == word[k+1]))){
                controle++;
                diferenca = 0;
                if (controle == tamanho){
                    return true;
            }
                
        }
    }
    diferenca++;
    if (diferenca >= 2){
        controle = 0;
    }
}

    return false;

}



/* 
        for (i = 1; i < boardSize-1; i++){
            controle= 0;
            for (j = 1; j <boardColSize-1; j++ ){
                if ( board[i][j] == word[k] ){
                    if ( board[i+1][j] == word[k+1] || board[i][j+1] == word[k+1]){
                         controle++;
                         k++;
                    }                
                    if (controle == tamanho-1){
                        return true;
                    }
                }
        }
    }
*/