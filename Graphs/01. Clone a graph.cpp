/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, Node* copy, unordered_map<Node*, Node*> &map) {
        map[node] = copy;
        for(auto cur : node->neighbors) {
            if(map[cur] == NULL) {
                Node* newNode = new Node(cur->val);
                (copy->neighbors).push_back(newNode);
                dfs(cur, newNode, map);
            } else {
                (copy->neighbors).push_back(map[cur]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)    return NULL;
        
        unordered_map<Node*, Node*> map;
        Node* copy = new Node(node->val);
        dfs(node, copy, map);
        return copy;
    }
};