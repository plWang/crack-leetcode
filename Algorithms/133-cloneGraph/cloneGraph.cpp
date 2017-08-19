#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x): label(x) {};
};


// Solution 1: BFS
UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
    if (node == NULL) return NULL;
    queue<UndirectedGraphNode*> toVisit;
    toVisit.push(node);
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;   //使用一个哈希表存储原图各节点与复制图中节点的对应关系
    map[node] = new UndirectedGraphNode(node->val);
    while (!toVisit.empty()) {
        UndirectedGraphNode* p = toVisit.front();
        toVisit.pop();
        // 遍历当前节点的所有邻居节点
        for (int i=0; i<p->neighbors.size(); i++) {
            UndirectedGraphNode* q;
            if (map.find(p->neighbors[i]) == map.end()) {   // not found
                q = new UndirectedGraphNode(p->neighbors[i]->label);
                map[p->neighbors[i]] = q;
                toVisit.push(p->neighbors[i]);
            }
            map[p]->neighbors.push_back(map[p->neighbors[i]]);
        }

    }

    return map[node];
    
}


// Solution 2: DFS
unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
    if (node == NULL) return NULL;
    if (map.find(node) == map.end()) {
        map[node] = new UndirectedGraphNode(node->label);
    
        for (UndirectedGraphNode* nei : node->neighbors) {
            map[node]->neighbors.push_back(cloneGraph(nei));
        }
    }

    return map[node];
}

int main() {
    UndirectedGraphNode* node0 = new UndirectedGraphNode(0);
    UndirectedGraphNode* node1 = new UndirectedGraphNode(1);
    UndirectedGraphNode* node2 = new UndirectedGraphNode(2);
    node0->neighbors.push_back(node1);
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node2);

    UndirectedGraphNode* node = cloneGraph(node0);
    return 0;
}