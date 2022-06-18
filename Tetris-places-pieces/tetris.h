#include<stdio.h>
#include<stdlib.h>

/*****structs*****/
struct map
{
    unsigned row;
    unsigned column;
    int ** head;
};
typedef struct map map;

struct piece
{
    unsigned row;
    unsigned column;
    int ** head;
};
typedef struct piece piece;

/*****Prototypes*****/
map createMap(unsigned);
piece createPiece(unsigned,unsigned);
void libererMap(map);
void libererPiece(piece);
void copyMap(map, map*);
void scanPiece(piece*);
void printMap(map);
void printPiece(piece);
piece fullPiece(int, int);
/********************/

map createMap(unsigned n)
{
    map M={0,0,NULL};
    M.row=n;
    M.column=n;
    M.head=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<M.row;i++)
        M.head[i]=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        M.head[i][j] = 0; 
    }
    return M;
}

piece createPiece(unsigned r,unsigned c)
{
    piece M={0,0,NULL};
    M.row=r;
    M.column=c;
    M.head=(int **)malloc(r*sizeof(int *));
    for(int i=0;i<M.row;i++)
        M.head[i]=(int *)malloc(c*sizeof(int));
    return M;
}

void libererMap(map M)
{
    if(M.head!=NULL)
    {
        for(int i=0;i<M.row;i++)
        {
            if(M.head[i]!=NULL)
                free(M.head[i]);
        }
        free(M.head);
    }
    return;
}

void libererPiece(piece M)
{
    if(M.head!=NULL)
    {
        for(int i=0;i<M.row;i++)
        {
            if(M.head[i]!=NULL)
                free(M.head[i]);
        }
        free(M.head);
    }
    return;
}

void scanPiece(piece * M)
{
    printf("---------------\n");
    if(M->head==NULL)
        return;
    for(int i=0;i<M->row;i++)
    {
        for(int j=0;j<M->column;j++)
            scanf("%d",M->head[i]+j);
    }
    return;
}
void printMap(map M)
{
    if(M.head==NULL)
    {
        printf("|  |\n");
        return;
    }
    for(int i=0;i<M.row;i++)
    {
        printf("| ");
        for(int j=0;j<M.column-1;j++)
            printf("%d ",M.head[i][j]);
        printf("%d |\n\n",M.head[i][M.column-1]);
    }
    printf("\n");
    return;
}
void printPiece(piece M)
{
    if(M.head==NULL)
    {
        printf("|  |\n");
        return;
    }
    for(int i=0;i<M.row;i++)
    {
        printf("| ");
        for(int j=0;j<M.column-1;j++)
            printf("%d ",M.head[i][j]);
        printf("%d |\n\n",M.head[i][M.column-1]);
    }
    printf("\n");
    return;
}

piece fullPiece(int n, int m){
    piece P = createPiece(n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            P.head[i][j] = 1;
        }
    }
    return P;
}

void copyMap(map M, map * N){
    int n = M.column;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            N->head[i][j] = M.head[i][j];
    }
    return;
}


piece removeRow(piece P, int k){
    piece res = createPiece(P.row-1,P.column);
    for(int i=0;i<P.row;i++){
        for(int j=0;j<P.column;j++){
            if(i != k) res.head[i][j] = P.head[i][j];
        }
    }
    return res;
}
piece cleanPieceRowTop(piece P){
    int count = 0; piece res;
    for(int k=0;k<P.row;k++){
        for(int i=0;i<P.column;i++){
            if(P.head[0][i] == 0) count++;
        }
        if(count == P.column){
            res = createPiece(P.row-1,P.column);
            for(int i=0;i<P.row-1;i++){
                for(int j=0;j<P.column;j++){
                    res.head[i][j] = P.head[i+1][j];
                    //libererPiece(P);
                }
            }
        }
        count = 0;
        P = res;
    }
    return P;
}
piece cleanPieceRowBottom(piece P){
    int count = 0; piece res;
    for(int k=0;k<P.row;k++){
        for(int i=0;i<P.column;i++){
            if(P.head[P.row-1][i] == 0) count++;
        }
        if(count == P.column){
            res = createPiece(P.row-1,P.column);
            for(int i=0;i<P.row-1;i++){
                for(int j=0;j<P.column;j++){
                    res.head[i][j] = P.head[i][j];
                    //libererPiece(P);
                }
            }
        }
        count = 0;
        P = res;
    }
    return P;
}

piece cleanPieceRow(piece P){
    P = cleanPieceRowTop(P);
    P = cleanPieceRowBottom(P);
    return P;
}

piece TransposePiece(piece P){
    piece R = createPiece(P.column,P.row);
    for(int i=0;i<P.column;i++){
        for(int j=0;j<P.row;j++)
            R.head[i][j] = P.head[j][i];
    }
    return R;
}

piece cleanPiece(piece P){
    P = cleanPieceRowTop(P);
    P = cleanPieceRowBottom(P);
    piece R = TransposePiece(P);
    R = cleanPieceRowTop(R);
    R = cleanPieceRowBottom(R);
    piece T = TransposePiece(R);
    return T;
}



piece cleanPieceColumn(piece P){
    piece R = TransposePiece(P);
    R = cleanPieceRow(R);
    R = TransposePiece(R);
    return R;
}


/*void placePieceSmart(piece P, map* M){
    int x=0, y=0;
    int n=M->column-P.row, m=M->column-P.column;
    start: ;
    //printf("Enter x and y : "); scanf("%d",&x); scanf("%d",&y);
    //printf("(x,y) = (%d,%d) and (max,max) = (%d , %d) \n",x,y,n,m);
    map backup = *M;
    for(int i=0;i<P.row;i++){
        for(int j=0;j<P.column;j++){
            if(M->head[x+i][y+j] == 0 || (M->head[x+i][y+j] != 0 && P.head[i][j] == 0))
                M->head[x+i][y+j] += P.head[i][j];
            else{
                *M = backup;
                if(x<n){x++;}
                else{if(x==n){x=0; y++;}}
                if(y>m){printf("Impossible\n");exit(EXIT_FAILURE);}
                goto start;
            }
        }
    }
    return;
}*/