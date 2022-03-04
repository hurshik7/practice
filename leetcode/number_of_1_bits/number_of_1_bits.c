int hammingWeight(uint32_t n) {
    uint32_t mask = 1;
    int numOfone = 0;
    for (int i = 0; i < 32; i++) {
        if ((mask & n) != 0) {
            numOfone++;
        } 
        mask = mask << 1;
    }
    return numOfone;
}
