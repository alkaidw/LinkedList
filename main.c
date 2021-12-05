
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
