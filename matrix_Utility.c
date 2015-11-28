#include "matrix_Utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
function: affichageMatrix
description: Print the content of a matrix
input :matrix to print
************************************************/
void affichageMatrix(tMatrix *m)
{
    int i=0;
    int j=0;

    printf ("\n");
    for (i=0;i<m->nbRows;i++)
    {
        printf ("\n");
        for (j=0;j<m->nbColumn;j++)
        {
          printf ("%c",m->matrix[i][j]);
        }
    }
    printf ("\n");
}

tMatrix* extractMatrix(tMatrix* original,int rowIndex,int ColIndex,int nbColmun,int nbRow)
{
    int i=0;
    tMatrix* extractedMatrix;
    extractedMatrix =(tMatrix*)calloc(1,sizeof(tMatrix));

    extractedMatrix->nbColumn=nbColmun;
    extractedMatrix->nbRows=nbRow;
    extractedMatrix->columnIndex=0;
    extractedMatrix->rowIndex=0;

    for (i=0;i<nbRow;i++)
    {
        memcpy(extractedMatrix->matrix[i],&original->matrix[rowIndex+i][ColIndex],nbColmun*sizeof(char));
    }
    return extractedMatrix;
}
int getCurrentRow (tMatrix *m)
{
    return m->rowIndex;
}
int getCurrentColumn(tMatrix *m)
{
    return m->columnIndex;
}
int nextIndex(tMatrix *matrix )
{
    matrix->columnIndex++;

    matrix->rowIndex   = matrix->rowIndex + matrix->columnIndex / matrix->nbColumn;
    matrix->columnIndex= matrix->columnIndex % matrix->nbColumn;

   if (matrix->rowIndex>=matrix->nbRows)
        return -1;
    else
        return 1;
}
void matrixRestartIndex(tMatrix *m)
{
    m->columnIndex=0;
    m->rowIndex=0;
}
int endMatrix (tMatrix *m)
{
    if (m->rowIndex>=m->nbRows)
        return 1;
    else
        return -1;
}
int matrixCurrentValue(tMatrix *m)
{
    return m->matrix[m->rowIndex][m->columnIndex];
}
int matrixCompare(tMatrix* m1,tMatrix* m2,int nbRows,int nbColumn)
{
    int result=0;
    int i=0;

    for (i=0;i<nbRows;i++)
    {
        result=memcmp(m1->matrix[i],m2->matrix[i],nbColumn*sizeof(char));
        if (result!=0)
        {
            return -1;
        }
    }
    return 1;
}
int find_Matrix(tMatrix *original,tMatrix *pattern)
{
    tMatrix* extractedMatrix;
    int compareMatrixResult=0;
    extractedMatrix=(tMatrix*)calloc(1,sizeof(tMatrix));

    while (endMatrix(original)==-1)
    {
        if (matrixCurrentValue(original)==matrixCurrentValue(pattern))
        {
            extractedMatrix=extractMatrix(original,getCurrentRow(original),getCurrentColumn(original),pattern->nbColumn,pattern->nbRows);
            compareMatrixResult=matrixCompare(pattern,extractedMatrix,pattern->nbRows,pattern->nbColumn);
            if (compareMatrixResult==1)
            {
                return 1;
            }

        }
        nextIndex(original);
        matrixRestartIndex(pattern);
    }
    return -1;
}
tMatrix* initMatrix(int nbRows,int nbColumn,char pmatrix[MAX_ROWS][MAX_COLUMN])
{
    int i=0;
    tMatrix* pMatrix;

    pMatrix=(tMatrix*)calloc (1,sizeof(tMatrix));
    pMatrix->columnIndex=0;
    pMatrix->rowIndex =0;
    pMatrix->nbColumn=nbColumn;
    pMatrix->nbRows = nbRows;

    for (i=0;i<nbRows;i++)
    {
        memcpy(pMatrix->matrix[i],pmatrix[i],nbColumn*sizeof(char));
    }
    return (pMatrix);
}
