bool isValidSerialization(char* preorder) {
    int slots = 1;
    int i = 0;
    int size = strlen(preorder);

    while (i < size) {
        if (slots == 0) return false; // ran out of slots before end

        if (preorder[i] == '#') {
            slots--;    // null node consumes a slot
            i++;        // move to next char
        } else {
            // process a full number (skip all its digits)
            while (i < size && preorder[i] != ',' ) {
                i++;
            }
            slots--;    // this number consumes one slot
            slots += 2; // but adds two slots for its children
        }

        // skip comma if present
        if (i < size && preorder[i] == ',') {
            i++;
        }
    }

    return slots == 0;
}