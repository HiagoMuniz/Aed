int fillCups(int* amount, int amountSize) {
    int i = 0;

    while ( amount[0] > 0 || amount[1] > 0 || amount[2] > 0){
        
        if ( amount[0] >= amount[1] && amount[0] >= amount[2]){
            amount[0]--;
            if (amount[1] >= amount[2]){
                amount[1]--;
            }else{
                amount[2]--;
            }
        } else if ( amount[1] >= amount[0] && amount[1] >= amount[2]){
            amount[1]--;
            if (amount[0] >= amount[2]){
                amount[0]--;
            }else{
                amount[2]--;
            }
        }else{
            amount[2]--;
            if (amount[0] >= amount[1]){
                amount[0]--;
            }else{
                amount[1]--;
            }
        }

        i++;
    }

    return i;
}

