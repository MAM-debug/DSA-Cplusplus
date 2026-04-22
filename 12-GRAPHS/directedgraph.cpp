#include <iostream>
using namespace std;

struct Node{
    int vertex;
    Node* next;
    Node(int v){
        vertex = v;
        next = nullptr;
    }
};
struct Graph{
    int V;
    Node** adjList;
    Graph(int v){
        V = v;
        adjList = new Node*[V];
        for(int i=0; i<V; i++){
            adjList[i] = nullptr;
        }
    }
    void addEdgedirected(int source, int destination){//directed graph
        Node* newNode = new Node(destination);
        newNode->next = adjList[source];
        adjList[source] = newNode;
    }
    void addedgeundirected(int source , int destination){
        addEdgedirected(source, destination);
        addEdgedirected(destination, source);   
    }
    void removeEdgedirected(int source, int destination){
        Node* temp=adjList[source];
        Node* prev=nullptr;
        while(temp){
            if(temp->vertex==destination){
                if(prev){
                    prev->next=temp->next;
                }else{
                    adjList[source]=temp->next;
                }
                delete temp;
                return;
            }
            prev=temp;
            temp=temp->next;
        }
    }
    void removeedgeundirected(int source, int destination){
        removeEdgedirected(source, destination);
        removeEdgedirected(destination, source);
    }
    int degree(int vertex){
        int count=0;
        Node* temp=adjList[vertex];
        while(temp){
            count++;
            temp=temp->next;
        }
        return count;
    }
    int indegree(int vertex){
        int count=0;
        for(int i=0; i<V; i++){
            Node* temp=adjList[i];
            while(temp){
                if(temp->vertex==vertex){
                    count++;
                }
                temp=temp->next;
            }
        }
        return count;
    }
    int outdegree(int vertex){
        return degree(vertex);
    }
    int totaldegree(int vertex){
        return indegree(vertex)+outdegree(vertex);
    }
    
    void printGraph(){
        for(int i=0; i<V; i++){
            Node* temp = adjList[i];
            cout<<"Vertex "<<i<<": ";
            while(temp){
                cout<<temp->vertex<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    };
};
