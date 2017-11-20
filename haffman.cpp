#include "haffman.h"
#include "priority_queue.h"
#include <functional>
#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <QTextStream>
#include <cstring>
#include <stdlib.h>

CodeTree* haffman(const Symbol* symbols, int len){
   //QTextStream out(stdout);
  //  out << "1";
    PriorityQueue<CodeTree*>* queue = create_pq<CodeTree*>(len);
    for(int i = 0; i < len; ++i)
        push(queue, symbols[i].weight, make_leaf(symbols[i]));
   // return 0;
    while(size(queue) > 1) {

        CodeTree* ltree = pop(queue);
        CodeTree* rtree = pop(queue);
        int weight = ltree->s.weight + rtree->s.weight;
        CodeTree* node = make_node(weight, ltree, rtree);
        ltree->parent = node;
        rtree->parent = node;
        push(queue, weight, node);
    }
    CodeTree* result = pop(queue);
    destroy_pq(queue);
   return result;
}

CodeTree* haffman(/*const*/ char* message) {
    if (*message == '\0') return 0;
    Symbol symbols[UCHAR_MAX];
    for(int i = 0; i < UCHAR_MAX; ++i) {
        symbols[i].c = i + CHAR_MIN;

        symbols[i].weight = 0;
    }
    int size = strlen(message);
    for(int i = 0; i < size; ++i)
        symbols[message[i] - CHAR_MIN].weight++;
    std::sort(symbols, symbols + UCHAR_MAX, symbol_greater);
    int len = 0;
    while(symbols[len].weight > 0 && len < UCHAR_MAX) len++;
    return haffman(symbols, len);
    //return 0;
}
CodeTree* haffman1(/*const*/ char* message) {
    QTextStream out(stdout);
    out << "1";
}
typedef CodeTree * Codeptr;
CodeTree *haffman_demo(std::vector<CodeTree*> &trees, const Symbol* symbols, int len){

    PriorityQueue<CodeTree*>* queue = create_pq<CodeTree*>(len);
    for(int i = 0; i < len; ++i)
        push(queue, symbols[i].weight, make_leaf(symbols[i]));
   // return 0;
 QTextStream out(stdout);
    //out << size(queue);
    while(size(queue) > 1) {


        Codeptr tmp[size(queue)];
        CodeTree *tree;
        int k = size(queue);
        //out << size(queue);
        while (size(queue) > 0){
            tree = pop(queue);
            trees.push_back(tree);


            //out<<tree->s.weight<<" ";
            tmp[size(queue)] = tree;
        }
          //out<<size(queue);
           // out<<endl;


        for (int i = 0;i<k;i++){
            push(queue, tmp[i]->s.weight, tmp[i]);
            //out << tmp[i]->s.weight << " ";
            }//out << size(queue);
        out<<endl;
        CodeTree* ltree = pop(queue);
        CodeTree* rtree = pop(queue);
        int weight = ltree->s.weight + rtree->s.weight;
        //out << tmp[i].weight;
        CodeTree* node = make_node(weight, ltree, rtree);
        //char *str2="1",*str1="2";
        //strcat(str1,str2);
        //node->str = strcat(ltree->str,rtree->str);//+ltree->s.c+rtree->s.c;
            //    node->str = strcat(node->str,(char*)ltree->s.c);
             //   node->str = strcat(node->str,(char*)rtree->s.c);
              //  out << node->str;
        ltree->parent = node;
        rtree->parent = node;
        push(queue, weight, node);
}

    CodeTree* result = pop(queue);
    trees.push_back(result);
    destroy_pq(queue);
   return result;

}
CodeTree* haffman_demo(std::vector<CodeTree*> &trees, char* message) {
    trees.clear();
    trees.push_back(new CodeTree);
    if (*message == '\0') return 0;
    Symbol symbols[UCHAR_MAX];
    for(int i = 0; i < UCHAR_MAX; ++i) {
        symbols[i].c = i + CHAR_MIN;

        symbols[i].weight = 0;
    }
    int size = strlen(message);
    for(int i = 0; i < size; ++i)
        symbols[message[i] - CHAR_MIN].weight++;
    std::sort(symbols, symbols + UCHAR_MAX, symbol_greater);
    int len = 0;
    while(symbols[len].weight > 0 && len < UCHAR_MAX) len++;
    return haffman_demo(trees,symbols, len);
    //return 0;
}
