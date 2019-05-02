#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud Noeud;
struct Noeud
{
    int coef;
    int puiss;
    Noeud *suiv;
};

//Prototypes

void inserer(Noeud **poly, int coef, int puiss);
void afficher(Noeud *poly);
void inserer_debut(Noeud **poly, int coef, int puiss);
void inserer_milieu(Noeud *poly, int coef, int puiss);

int main()
{
    Noeud *poly = NULL;
    inserer(&poly, 2, 5);
    inserer(&poly, 3, 3);
    inserer(&poly, 8, 1);
    inserer(&poly, 5, 2);
    inserer(&poly, 2, 6);
    inserer(&poly, 4, 6);
    inserer(&poly, 4, 9);
    
    afficher(poly);

    return 0;
}

Noeud *nouveau(int coef, int puiss)
{
    Noeud *p = malloc(sizeof(Noeud));
    p->coef = coef;
    p->puiss = puiss;
    p->suiv = NULL;
    return p;
}

void inserer(Noeud **poly, int coef, int puiss)
{

    Noeud *poly1 = *poly;
    if (poly1 != NULL && poly1->puiss == puiss)
    {
        poly1->coef += coef;
    }
    else if (poly1 == NULL || poly1->puiss > puiss)
    {
        inserer_debut(poly, coef, puiss);
    }
    else
    {
        while (poly1->suiv != NULL && poly1->suiv->puiss < puiss)
        {
            poly1 = poly1->suiv;
        }
        if(poly1->suiv != NULL && poly1->suiv->puiss == puiss){
            poly1->suiv->coef += coef;
        } else {
inserer_milieu(poly1, coef, puiss);
        }
        
    }
}

void inserer_debut(Noeud **poly, int coef, int puiss)
{
    Noeud *p = nouveau(coef, puiss);
    p->suiv = *poly;
    *poly = p;
}
void inserer_milieu(Noeud *poly, int coef, int puiss)
{
    Noeud *p = nouveau(coef, puiss);
    if (poly->suiv == NULL)
    {
        poly->suiv = p;
    }
    else
    {
        p->suiv = poly->suiv;
        poly->suiv = p;
    }
}

void afficher(Noeud *poly)
{
    if (poly != NULL)
    {
        printf("%d %d -> ", poly->coef, poly->puiss);
        afficher(poly->suiv);
    }
    else
    {
        printf("NULL");
    }
}
