#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include "union_find.hpp"
using namespace std;

int findMinDoorCost(const string & filename){
    ifstream infile(filename);
    if(!infile.is_open()){
        cerr<<"Error opening file"<<filename<<endl;
        return -1;
    }
    vector<Edge> edges;
    unordered_map<string, int> roomToIndex;
    int roomCount = 0;

    string room1, room2;
    int cost;
    while(infile >> room1>>room2>>cost){
        if (!roomToIndex.count(room1)) roomToIndex[room1] = roomCount++;
        if (!roomToIndex.count(room2)) roomToIndex[room2] = roomCount++;
        edges.emplace_back(roomToIndex[room1], roomToIndex[room2], cost);
    }

    infile.close();

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){
        return a.cost < b.cost;
    });


    UnionFind uf(roomCount);
    int totalCost = 0;
    int edgesUsed = 0;

    for(const Edge& e : edges){
        if (uf.union_sets(e.u, e.v)){
            totalCost += e.cost;
            edgesUsed++;
        }
    }

    if(edgesUsed != roomCount -1){
        cerr <<"Graph is not connected"<<endl;
        return -1;
    }

    return totalCost;


}

int main(int argc, char* argv[]){
    if (argc != 2){
        cerr<<"Usage: "<<argv[0] << " <input_file>"<<endl;
        return 1;
    }

    int result = findMinDoorCost(argv[1]);
    if (result >= 0){
        cout<<result<<endl;
    }

    return 0;
}