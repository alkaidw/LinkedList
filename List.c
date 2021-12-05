#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    double value;
    struct node* prev;
    struct node* next;
};

typedef struct node* Node;

struct list{
    char *name;
    int size;
    Node first;
    Node last;
};

typedef struct list* List;

Node newNode(double n);
void freeNode(Node node);
List newList(char name[]);
void freeList(List l);
int isEmptyList(List l);
Node addToList(List l, double value);
Node insertToList(List l, int pos, double value);
int removeFromList(List l, double value);
void popFromList(List l);
void emptyList(List l);
void printList(List l);
int sizeList(List l);
Node searchInList(List l, double value);
int sortList(List l);
double* list2vector(List l);
List vector2list(double *v, int size);
void showInfos(List l);
Node _searchInList(List l, double value); //TROCA O NOME DA FUNCAO
Node maxInList(List l);
Node getFromIndex(List l, int index);
Node getLast(List l);
void imprime_vetor(double* arr, int n);
double sumList(List l);



/*
int main (void){
    List d = newList("Lista");
    Node no;
    int i;

    addToList(d, 0);
    addToList(d, 5);
    addToList(d, 7);
    addToList(d, 0);
    addToList(d, 9);
    addToList(d, 100);
    addToList(d, 4);

    printList(d);
    no = getFromIndex(d, 5);
    //no = maxInList(d);
    printf("%d", no->value);

    return 0;
}



/*
    puts("lista vazia");
    printList(d);

    puts("adicionando 9-0");
    for(i=9; i>=0; --i)
        addToList(d, i);
    printList(d);

    puts("ordenada");
    sortList(d);
    printList(d);

    puts("esvaziando");
    emptyList(d);
    printList(d);
    puts("adicionado 0");
    addToList(d, 0);

    printList(d);


    puts("adicionando 9-0");
    for(i=0; i<10; ++i)
        addToList(d, i);
    printList(d);
    removeFromList(d, 6);
    removeFromList(d, 3);
    removeFromList(d, 0);
    removeFromList(d, 1);
    printList(d);

    insertToList(d, 5, 50);
    printList(d);
    popFromList(d);
    popFromList(d);
    popFromList(d);
    popFromList(d);
    popFromList(d);
    popFromList(d);
    //popFromList(d);
    //popFromList(d);
    printList(d);
    return 0;
}

*/


Node newNode(double value){
    Node node = malloc(sizeof(struct node));
    if(node == NULL)
        return NULL;
    node->value = value;
    node->prev = node->next = NULL;
    return node;
}

void freeNode(Node node){
    free(node);
}

List newList(char name[]){

    List l = malloc(sizeof(struct list));

    if(l == NULL)
        return NULL;
    l->name = malloc(sizeof(strlen(name)+1));


    if(l->name == NULL){
        free(l);
        return NULL;
    }

    strcpy(l->name, name);
    l->size = 0;
    l->first = l->last = NULL;

    return l;
}

void freeList(List l){
    if(l == NULL)
        return;
    emptyList(l);
    free(l);
}

Node addToList(List l, double value){

    Node node = newNode(value);

    if(node == NULL)
        return NULL;

    if(l->size == 0)
        l->first = l->last = node;

    else{
        l->last->next = node;
        node->prev = l->last;
        l->last = node;
    }

    l->size++;

    return node;
}

Node getFromIndex(List l, int index){
    Node cur = l->first;
    int i;
    //Node prev, next;

    if(l->size == 0 || l->size < index)
        return NULL;

    i = 0;
    while(i < index){
        cur = cur->next;
        i++;
    }
    return cur;
}


Node insertToList(List l, int pos, double value){
    Node node = newNode(value);
    Node cur = l->first;
    int i;

    if(node == NULL)
        return NULL;

    if(l->size == 0)
        l->first = l->last = node;

    else if(pos == 0){
        node->next = l->first;
        l->first->prev = node;
        l->first = node;
    }
    else if(pos > l->size){
        l->last->next = node;
        node->prev = l->last;
        l->last = node;
    }

    else{
        for(i=0; i<l->size && i<pos; ++i){
            cur = cur->next;
        }
        cur->prev->next = node;
        node->prev = cur->prev;
        cur->prev = node;
        node->next = cur;
    }

    return node;

}

int removeFromList(List l, double value){
    Node cur = l->first;
    Node prev, next;

    if(l->size == 0)
        return 0;

    while(cur != NULL && cur->value != value)
        cur = cur->next;

    if(cur == NULL)
        return 0;

    if(l->size == 1){
        l->first = NULL;
        l->last = NULL;
    }
    else if(cur == l->first){
        l->first = cur->next;
        cur->next->prev = l->first;
    }
    else if(cur == l->last){
        l->last = cur->prev;
        l->last->next = NULL;
    }else{
        prev = cur->prev;
        next = cur->next;
        prev->next = next;
        next->prev = prev;
    }

    l->size--;
    freeNode(cur);
    return 1;
}

void popFromList(List l){
    Node prev;
    if(l->size == 0){
        return;
    }
    if(l->size == 1){
        freeNode(l->first);
        l->first = NULL;
        l->last = NULL;
        l->size--;
        return;
    }
    prev = l->last->prev;
    freeNode(l->last);

    l->last = prev;
    prev->next = NULL;
    l->size--;
}

void emptyList(List l){
    Node cur = l->first;
    Node deleted;

    while(cur != NULL){
        deleted = cur;
        cur = cur->next;
        freeNode(deleted);
    }
    l->size = 0;
}

Node _searchInList(List l, double value){
    Node cur = l->first;
    double tmp;

    if(l->size == 0)
        return NULL;

    while(cur != NULL){
        if(cur->value >= value){
            tmp = value;
            return cur;
        }
        cur = cur->next;
    }
    if(cur == NULL)
        return NULL;

    return cur;
}

Node maxInList(List l){
    Node cur = l->first;
    Node max = NULL;
    int max_value = 0;

    if(l->size == 0)
        return NULL;

    while(cur != NULL){
        if(cur->value > max_value){
            max_value = cur->value;
            max = cur;
        }
        cur = cur->next;
    }
    return max;
}

Node searchInList(List l, double value){
    Node cur = l->first;

    if(l->size == 0)
        return NULL;

    while(cur != NULL && cur->value != value)
        cur = cur->next;

    if(cur == NULL)
        return NULL;

    return cur;
}

int sortList(List l){

    int crescente (const void * a, const void * b) {
        return ( *(double*)a - *(double*)b );
    };

    double *vet = list2vector(l);
    List lSorted;

    if(vet == NULL)
        return 0;

    qsort(vet, l->size, sizeof(double), crescente);
    lSorted = vector2list(vet, l->size);

    if(lSorted == NULL){
        free(vet);
        return 0;
    }

    emptyList(l);
    l->first = lSorted->first;
    l->last = lSorted->last;
    l->size = lSorted->size;
    free(lSorted);
    free(vet);

    return 1;
}

double* list2vector(List l){
    Node cur = l->first;
    int i;
    double *v = malloc(sizeof(double)*l->size);


    if(v == NULL)
        return NULL;

    i = 0;

    while(cur != NULL){
        v[i++] = cur->value;
        cur = cur->next;
    }
    return v;
}



List vector2list(double *v, int size){
    List l = newList("vector");
    int i;
    if(l == NULL)
        return NULL;

    for(i=0; i<size; ++i)
        if(addToList(l, v[i]) == NULL){
            freeList(l);
            return NULL;
        }
    return l;
}

void printList(List l){
    Node cur = l->first;

    printf("%s: ", l->name);
    if(l->size == 0){
        puts("[]");
        return;
    }

    putchar('[');
    while(cur != NULL){
        printf("%.2lf", cur->value);

        cur = cur->next;
        if(cur != NULL)
            printf(", ");
    }
    puts("]");
}
int isEmptyList(List l){
    return l->size == 0;
}
void showInfos(List l){
    printf("at: %p\n", l);
    printf("size: %d\n", l->size);
    printf("first: %p\n", l->first);
    printf("last: %p\n\n", l->last);
}


void imprime_vetor(double* arr, int n){
    int i;
    for(i=0; i<n; ++i){
        printf("%.2lf ", arr[i]);
    }
    putchar('\n');

}

int sizeList(List l){
    return l->size;
}


Node getLast(List l){
    return l->last;
}


double sumList(List l){
    double s = 0.0;
    Node cur = l->first;

    while(cur != NULL){
        s += cur->value;
        cur = cur->next;
    }
    return s;
}
