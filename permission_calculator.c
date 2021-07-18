#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void) {

    int ch;
    char * ifp;
    char * ofp;
    FILE * ifile;
    FILE * ofile;
    char USER[3];
    char GROUP[3];
    char OTHERS[3];
    int usersum;
    int groupsum;
    int othersum;

    ifp = "/dev/stdin";
    ofp = "/dev/stdout";

    ifile = fopen(ifp, "r");
    if (ifile == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    ofile = fopen(ofp, "w");
    if (ofile == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    int counter = 0;
    int notfirst = 0;
    while ((ch = fgetc(ifile)) != EOF) {
        if (notfirst) {
            if (counter < 4) {
                USER[counter - 1] = ch;
                //printf("USER[%d]: %d\n", (counter-1), USER[counter - 1]);
            } else if ((counter > 3) && (counter < 7)) {
                GROUP[counter - 4] = ch;
                //printf("GROUP[%d]: %d\n", (counter-4), GROUP[counter - 4]);
            } else if (counter > 6) {
                OTHERS[counter - 7] = ch;
                //printf("OTHERS[%d]: %d\n", (counter-7), OTHERS[counter - 7]);

            } else {
                printf("What the Fuck? counter: %d, ch (int): %d, ch (char): %c\n", counter, ch, ch);
            }
        } else if (counter == 0) {
            notfirst = 1;
        }
        counter = counter + 1;
    }

    for (int i = 0; i < 3; i++) {
        if (USER[i] == 45) {
            USER[i] = 0;
        } else {
            USER[i] = 1;
        }

        if (GROUP[i] == 45) {
        
            GROUP[i] = 0;
        } else {
            GROUP[i] = 1;
        }

        if (OTHERS[i] == 45) {
            OTHERS[i] = 0;
        } else {
            OTHERS[i] = 1;
        }

    }

    usersum = 0;
    groupsum = 0;
    othersum = 0;
    for (int i = 0; i < 3; i++) {
        usersum = usersum + (USER[i] * pow(2, (2 - i)));
        groupsum = groupsum  + (GROUP[i] * pow(2, (2 - i)));
        othersum = othersum + (OTHERS[i] * pow(2, (2 - i)));
    }
    //printf("%d %d %d\n",USER[0],USER[1],USER[2]);
    //printf("%d %d %d\n",OTHERS[0],OTHERS[1],OTHERS[2]);
    //printf("%d %d %d\n",GROUP[0],GROUP[1],GROUP[2]);
    printf("%d%d%d\n",usersum,groupsum,othersum);


    fclose(ifile);
    fclose(ofile);
    return EXIT_SUCCESS;
}

