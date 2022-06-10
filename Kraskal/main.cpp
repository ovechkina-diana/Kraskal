//
//  main.cpp
//  Kraskal
//
//  Created by Diana Ovechkina on 10.05.2022.
//

#include <iostream>
#include <vector>
using namespace std;

struct graphNode {
    int begin;
    int end;
    int power;
    
    graphNode(int begin, int end, int power) {
        this->begin = begin;
        this->end = end;
        this->power = power;
    }
};

vector <graphNode> createGraph(int N) {
    vector <graphNode> graph;
   
    int power;
    int begin;
    int end;
    
    for (int i = 0; i < N ; i++) {
        cout << "Введите номер первой вершины: "; cin >> begin;
        cout << "Введите номер второй вершины: "; cin >> end;
        cout << "Введите мощность ребра " << begin << " - " << end << ": "; cin >> power;
        cout << endl;
        graph.push_back(graphNode(begin, end, power));
    }
    
    return graph;
};

bool compare(graphNode a, graphNode b) {
    return a.power < b.power;
}

vector <graphNode> sortGraph(int E) {
    vector <graphNode> sortGraph = createGraph(E);
    sort(sortGraph.begin(), sortGraph.end(), compare);
    return sortGraph;
}

void printGraph(vector <graphNode> graph) {
    vector <graphNode>::iterator i;
    for(i = graph.begin(); i != graph.end(); i++) {
        cout << i->begin << " " << i->end <<" " << i->power << endl;
    }
};


void Kraskal(vector <graphNode> &graph, vector <bool> &visited, int N) {
    int minWeight = 0;
    
    for (int i = 0; i < N; i++) {
        if (!visited[graph[i].begin] || !visited[graph[i].end]) {
            cout << graph[i].begin << " - " << graph[i].end << " мощность: " << graph[i].power << endl;
            
            visited[graph[i].begin] = true;
            visited[graph[i].end] = true;
            minWeight += graph[i].power;
        }
    }
    
    cout << endl << "Минимальный вес: " << minWeight << endl << endl;
};


int main(int argc, const char * argv[]) {
    int V;
    int E;
    cout << "Введите количество вершин: "; cin >> V;
    cout << "Введите количество ребер: "; cin >> E;
    cout << endl;

    vector <graphNode> graph = sortGraph(E);
    vector <bool> visited(V);
// printGraph(graph);
    Kraskal(graph, visited, V);
}
