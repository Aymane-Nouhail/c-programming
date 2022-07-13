#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include "liste_simple.h" //for a singly linked list
#include "strsplit.h" //for string cleaning and manipulation

struct graph
{
    int row;
    int column;
    int ** head;
};
typedef struct graph graph;

/******** Prototypes ***********/
graph createGraph(int);
void freeGraph(graph *);
void printGraph(graph);
void addEdge(graph *, int, int);
liste node_neighbors(int, graph);



graph createGraph(int n)
{
    graph M={0,0,NULL};
    M.row=n;
    M.column=n;
    M.head=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<M.row;i++)
        M.head[i]=(int *)malloc(n*sizeof(double));
    for(int i=0;i<M.row;i++){
        for(int j=0;j<M.column;j++)
            M.head[i][j] = 0;
    }
    return M;
}


void freeGraph(graph *M)
{
    if(M->head!=NULL)
    {
        for(int i=0;i<M->row;i++)
        {
            if(M->head[i]!=NULL)
                free(M->head[i]);
        }
        free(M->head);
    }
    return;
}


void printGraph(graph M)
{
    if(M.head==NULL)
    {
        printf("|  |\n");
        return;
    }
    printf("     S    ");
    for(int i=1;i<M.column-1;i++)
        printf("c%d   ",i);
    printf("E\n");
    for(int i=0;i<M.row;i++)
    {
        if(i==0) printf("S ");
        if(i==M.column-1) printf("E ");
        if(i>0 && i<M.column-1) printf("c%d",i);
        printf(" | ");
        for(int j=0;j<M.column-1;j++)
            printf("%d    ",M.head[i][j]);
        printf("%d |\n\n",M.head[i][M.column-1]);
    }
    printf("\n");
    return;
}

void addEdge(graph *M, int i, int j) {
    M->head[i][j] = 1;
    M->head[j][i] = 1;
}

//returns a list of all nodes that touch input node
liste node_neighbors(int node, graph M){
    liste neighbors = NULL;
    for(int i=0;i<M.column;i++){
        if(M.head[i][node] ==  1) ajoutFin(i,&neighbors);
    }
    return neighbors;
}


int* solve(graph G,int s,int size){
    liste Q = NULL; ajoutFin(s,&Q);
    bool visited[size];
    for(int i=0;i<size;i++) visited[i] = false;
    visited[s] = true;
    int* prev = (int*)malloc(size*sizeof(int));
    for(int i=0;i<size;i++) prev[i] = -1; 
    int node;
    while(Q!=NULL){
        node = Q->element; suppressionDebut(&Q);
        liste neighbors = node_neighbors(node,G);
        while(neighbors != NULL){
            int next = neighbors->element;
            if(visited[next] == false){
                ajoutFin(next,&Q);
                visited[next] = true;
                prev[next] = node;
            }
            neighbors = neighbors->suivant;
        }
    }
    return prev;
}

liste reconstructPath(int s, int e, int* prev){
    liste path = NULL; int count = 0;
    for(int at=e;at!=-1;at=prev[at]){
        ajoutDebut(at,&path);
        count++;
    }
    ajoutDebut(count,&path);
    if (path->suivant->element == 0) return path;
    return NULL;
}
liste shortestPath(graph G, int s, int e, int size){
    int * prev = solve(G,s,size);
    liste res = reconstructPath(s,e,prev);
    printf("The shortest path is %d steps long.\n",res->element);
    suppressionDebut(&res);
    return res;
}

int main(int argc, char *argv[]){
    //taking the txt file and putting it in one string.
    FILE    *textfile;
    char    *text;
    long    numbytes;
    textfile = fopen(argv[1], "r");
    if(textfile == NULL)
        return 1;
    fseek(textfile, 0L, SEEK_END);
    numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);  
    text = (char*)calloc(numbytes, sizeof(char));   
    if(text == NULL)
        return 1;
    fread(text, sizeof(char), numbytes, textfile); //the contents of our file go to the string "text".
    fclose(textfile);
    //cleaning the string "text" we obtained.
    char * cleaned1 = str_replace(text,"-","\n");
    char * cleaned2 = str_replace(cleaned1,"c","\n");
    char* cleaned = removeSpaces(cleaned2);
    char ** result = strsplit(cleaned,'\n').str;
    //done cleaning, now we extract what we want from the string.
    int trains = atoi(result[0]);
    int cities = atoi(result[1]);
    graph M = createGraph(cities);
    //We consider : S <- 0, ci <- i, and E <- cities-1;
    for(int i=2;i<strsplit(cleaned,'\n').num;i+=2){
        int from, to;
        if(result[i][0] == 'S') from = 0; else from = (int)atoi(result[i]);
        if(result[i][0] == 'E') from = cities-1; else from = (int)atoi(result[i]);
        if(result[i+1][0] == 'S') to = 0; else to = (int)atoi(result[i+1]);
        if(result[i+1][0] == 'E') to = cities-1; else to = (int)atoi(result[i+1]);
        addEdge(&M,from,to);
    }
    //input of the graph is done, now initializing our algorithm
    printGraph(M);
    affichageListe(shortestPath(M,0,cities-1,cities));
    return 0;
}