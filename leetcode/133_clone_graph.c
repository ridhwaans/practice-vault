#include <stdlib.h>

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

#define MAX_NODES 100

struct Node* visit(struct Node *s, struct Node* graph[], int visited[]){
    if (!s) return NULL;

    if (visited[s->val]){
        return graph[s->val];
    }

    visited[s->val] = 1;

    struct Node* clone = malloc(sizeof(struct Node));
    clone->val = s->val;
    clone->numNeighbors = s->numNeighbors;
    clone->neighbors = malloc(sizeof(struct Node*) * s->numNeighbors);
    
    // building graph. Index corresponds to the node because of 1-indexed constraint
    graph[s->val] = clone;

    for (int i = 0; i < clone->numNeighbors; i++){
        clone->neighbors[i] = visit(s->neighbors[i], graph, visited);
    }
    return clone;
}

struct Node *cloneGraph(struct Node *s) {
    if (!s) return NULL;

    // mass initialize
    struct Node* graph[MAX_NODES + 1] = {0};    
    int visited[MAX_NODES + 1] = {0};

    return visit(s, graph, visited);
}
