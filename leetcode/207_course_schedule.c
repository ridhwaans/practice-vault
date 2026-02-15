#include <stdlib.h>
#include <stdbool.h>

// cpp-like references (&) dont exist in C. C doesnt like things hidden; have to pass by pointers
bool cycleExists(int** adjacencyList, int* valueListIndexes, bool* visited, bool* stackPath, int course){ 
    stackPath[course] = true;
    visited[course] = true;
    for (int i = 0; i < valueListIndexes[course]; i++){
        int neighborCourse = adjacencyList[course][i];
        if (!visited[neighborCourse] && cycleExists(adjacencyList, valueListIndexes, visited, stackPath, neighborCourse)){
            return true;
        }
        if (stackPath[neighborCourse]) { return true;}
    }
    stackPath[course] = false;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int** adjacencyList = malloc(numCourses * sizeof(int*));
    int* prereqs = calloc(numCourses, sizeof(int));

    for (int i=0;i < prerequisitesSize;i++){
       int course = prerequisites[i][0];
       int prereq = prerequisites[i][1];

       prereqs[prereq]++; 
    }
    for (int i=0; i < numCourses;i++){
        adjacencyList[i] = malloc(prereqs[i] * sizeof(int));
    }
    int* valueListIndexes = calloc(numCourses, sizeof(int));

    // span all courses by iterating first col of prerequisites 
    // adjacencyList for directed graphs is node -> list of outdegree nodes (or prereq->course(s))
    for (int i =0;i < prerequisitesSize;i++){
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];
        int valueListIndex = valueListIndexes[prereq];
        adjacencyList[prereq][valueListIndex] = course;
        valueListIndexes[prereq]++;
    }

    bool* visited = malloc(numCourses * sizeof(bool));
    bool* stackPath = malloc(numCourses * sizeof(bool));

    // alternatively initialize with calloc
    for (int i = 0; i< numCourses;i++){
        visited[i] = false;
        stackPath[i] = false;
    }

    for (int i = 0; i < numCourses;i++){
        /*
        int prereq = adjacencyList[i][0]; doesnt work because
        1) some courses have 0 prereqs result in malloc & bounds exception
        2) array access is index-based
        */
        if (!visited[i] && cycleExists(adjacencyList, valueListIndexes, visited, stackPath, i)){
            return false;
        }
    }

    return true;
}
