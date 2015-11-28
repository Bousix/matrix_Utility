#ifndef MATRIX_UTILITY_H_INCLUDED
#define MATRIX_UTILITY_H_INCLUDED

#define MAX_ROWS 100
#define MAX_COLUMN 100
#define MAX_TC 100

typedef struct
{
   int nbRows;
   int nbColumn;
   int rowIndex;
   int columnIndex;
   char matrix[MAX_ROWS][MAX_COLUMN];
}tMatrix;

extern void affichageMatrix(tMatrix *m);
extern tMatrix* extractMatrix(tMatrix* original,int rowIndex,int ColIndex,int nbColmun,int nbRow);
extern int getCurrentRow (tMatrix *m);
extern int getCurrentColumn(tMatrix *m);
extern int nextIndex(tMatrix *matrix );
extern void matrixRestartIndex(tMatrix *m);
extern int endMatrix (tMatrix *m);
extern int matrixCurrentValue(tMatrix *m);
extern int matrixCompare(tMatrix* m1,tMatrix* m2,int nbRows,int nbColumn);
extern int find_Matrix(tMatrix *original,tMatrix *pattern);
extern tMatrix* initMatrix(int nbRows,int nbColumn,char pmatrix[MAX_ROWS][MAX_COLUMN]);
#endif // MATRIX_UTILITY_H_INCLUDED
