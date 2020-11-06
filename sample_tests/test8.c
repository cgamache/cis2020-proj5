int vin[17];

int checkvin() {
	int w[17];
    int productSum;
	int checkDigit;
	int value;
	int weight;
    int index;
	int v[92];
    int c[92];
    int i;
    int cc;

    productSum = 0;
    checkDigit = -1;

    w[0] = 8;
    w[1] = 7;
    w[2] = 6;
    w[3] = 5;
    w[4] = 4;
    w[5] = 3;
    w[6] = 2;
    w[7] = 10;
    w[8] = -1;
    w[9] = 9;
    w[10] = 8;
    w[11] = 7;
    w[12] = 6;
    w[13] = 5;
    w[14] = 4;
    w[15] = 3;
    w[16] = 2;

    for (i = 0; i < 90; i += 1) { 
        v[i] = -1;
    }
    v[48] = 0;
    v[49] = 1;
    v[50] = 2;
    v[51] = 3;
    v[52] = 4;
    v[53] = 5;
    v[54] = 6;
    v[55] = 7;
    v[56] = 8;
    v[57] = 9;
    v[65] = 1;
    v[66] = 2;
    v[67] = 3;
    v[68] = 4;
    v[69] = 5;
    v[70] = 6;
    v[71] = 7;
    v[72] = 8;
    v[74] = 1;
    v[75] = 2;
    v[76] = 3;
    v[77] = 4;
    v[78] = 5;
    v[80] = 7;
    v[82] = 9;
    v[83] = 2;
    v[84] = 3;
    v[85] = 4;
    v[86] = 5;
    v[87] = 6;
    v[88] = 7;
    v[89] = 8;

    for (i = 0; i < 90; i += 1) { 
        c[i] = -1;
    }
    c[48] = 0;
    c[49] = 1;
    c[50] = 2;
    c[51] = 3;
    c[52] = 4;
    c[53] = 5;
    c[54] = 6;
    c[55] = 7;
    c[56] = 8;
    c[57] = 9;
    c[88] = 10;
	i = -1;

	for (index = 0; index < 17; index += 1) {		
        cc = vin[index];
		i += 1;
		weight = w[i];
    	if (weight == -1) {
            checkDigit = c[cc];
            if (checkDigit == -1) {
                return 0;                
            }
		} else {
			value = v[cc];
			if (value < 0) {
				return 0;
			} else {
				productSum += value * weight;
			}
        }
    }
    if (productSum % 11 == checkDigit) {
        return 1;
    } 
    return 0;
}

main() {
    int rv;
    int i;
    /* 1G6DC5EG0A0150593 */
    vin[0] = 49;
    vin[1] = 71;
    vin[2] = 54;
    vin[3] = 68;
    vin[4] = 67;
    vin[5] = 53;
    vin[6] = 69;
    vin[7] = 71;
    vin[8] = 48;
    vin[9] = 65;
    vin[10] = 48;
    vin[11] = 49;
    vin[12] = 53;
    vin[13] = 48;
    vin[14] = 53;
    vin[15] = 57;
    vin[16] = 51;

    rv = checkvin();
    if (rv == 1) {
        printf("checkdigit ok\n", rv);
    } else {
        printf("fails checkdigit\n", rv);
    }
}
