#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix_Utility.h"

typedef struct
{
    tMatrix *grid;
    tMatrix *pattern;
}tTestCase;

tTestCase aubTestCase[MAX_TC];
int nbtestCase=0;


int main()
{
int i=0;
int j=0;
char aubMatrix[MAX_ROWS][MAX_COLUMN];
scanf("%i",&nbtestCase);

for (i=0;i<nbtestCase;i++)
{
    aubTestCase[i].pattern=(tMatrix*)calloc(1,sizeof(tMatrix));
    aubTestCase[i].grid=(tMatrix*)calloc(1,sizeof(tMatrix));

    //Initialisation of Pattern Matrix
    scanf("%i",&aubTestCase[i].pattern->nbRows);
    scanf("%i",&aubTestCase[i].pattern->nbColumn);
    for (j=0;j<aubTestCase[i].pattern->nbRows;j++)
    {
        memset(aubMatrix[j],0,MAX_COLUMN);
        scanf("%s",aubMatrix[j]);
    }
    aubTestCase[i].pattern=initMatrix(aubTestCase[i].pattern->nbRows,aubTestCase[i].pattern->nbColumn,aubMatrix);

    //Initialisation of Grid Matrix
    scanf("%i",&aubTestCase[i].grid->nbRows);
    scanf("%i",&aubTestCase[i].grid->nbColumn);
    for (j=0;j<aubTestCase[i].grid->nbRows;j++)
    {
        memset(aubMatrix[j],0,MAX_COLUMN);
        scanf("%s",aubMatrix[j]);
    }
    aubTestCase[i].grid=initMatrix(aubTestCase[i].grid->nbRows,aubTestCase[i].grid->nbColumn,aubMatrix);

}

for (i=0;i<nbtestCase;i++)
{
    if (find_Matrix(aubTestCase[i].pattern,aubTestCase[i].grid)==1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

        free(aubTestCase[i].pattern);
        free(aubTestCase[i].grid);
}
    return 0;
}
