int maximumPopulation(int** logs, int logsSize, int* logsColSize) {
    int vector[logsSize][2];

    for ( int i = 0; i < logsSize; i++ ){
        vector[i][0] = logs[i][0];
        vector[i][1] = 1;
    }

    for ( int i = 0; i < logsSize; i++ ){
        for (int j = 0; j < logsSize; j++){
            if ( logs[j][0] <= vector[i][0] && vector[i][0] < logs[j][1] ){
                vector[i][1] += 1;

            }
        }
    }

    int maior = vector[0][1];
    int index = 0;

    for ( int i = 1; i < logsSize; i++ ){
        if ( vector[i][1] > maior || (vector[i][1] == maior && vector[i][0] < vector[index][0]) ){
            maior = vector[i][1];
            index = i;
        }
    }

    return vector[index][0];

}

/* 
        for ( int j = 0 ; j < logsColSize[i] ; j++ ){

*/