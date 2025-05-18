bool continua(char** board, int boardSize, int* boardColSize, char* word, int col, int lin, int wordLetter);

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int i = 0, j = 0;

    for (i = 0; i < boardSize; i++){    
        for (j = 0; j < boardColSize[i] ; j++ ){
            if (board[i][j] == word[0]){
                if (continua(board, boardSize, boardColSize, word, i, j, 0))
                    return true;
            }
                
        }
    }
    return false;
}

bool continua(char** board, int boardSize, int* boardColSize, char* word, int lin, int col, int wordLetter){
   
   if (lin < 0 || lin >= boardSize || col < 0 || col >= boardColSize[lin] || board[lin][col] != word[wordLetter])
        return false; // AJUDA

    if (word[wordLetter+1] == '\0')
        return true;

    char mark = board[lin][col];
    board[lin][col] = '#'; // AJUDA

    if ( // AJUDA
        continua(board, boardSize, boardColSize, word, lin + 1, col, wordLetter+1) ||
        continua(board, boardSize, boardColSize, word, lin - 1, col, wordLetter+1) ||
        continua(board, boardSize, boardColSize, word, lin, col + 1, wordLetter+1) ||
        continua(board, boardSize, boardColSize, word, lin, col - 1, wordLetter+1)
    ){
        board[lin][col] = mark;
        return true;
    }

    board[lin][col] = mark;
    return false;

}



/* 

    else if ( col == 0 && lin == 0){
        if (  board[lin+1][col] == word[wordLetter] || board[lin][col+1] == word[wordLetter] )
            return continua(board, boardSize, boardColSize, word, lin, col, wordLetter);

    }else if (col == boardSize -1 && lin == boardColSize[lin] -1){
        if (  board[lin-1][col] == word[wordLetter] || board[lin][col-1] == word[wordLetter] )
            return continua(board, boardSize, boardColSize, word, lin, col, wordLetter);
    } 




///////////////////////
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