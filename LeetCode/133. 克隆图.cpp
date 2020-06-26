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
    Node* visited[101] = {nullptr};
    
    Node* cloneGraph(Node* node) {
        if(node==nullptr)return nullptr;
        int size = node->neighbors.size();
        Node *root = new Node(node->val, vector<Node*> {});
        visited[node->val] = root;
        for (int i = 0; i < size; i++) {
            if (!visited[node->neighbors[i]->val])
                root->neighbors.push_back(cloneGraph(node->neighbors[i]));
            else
                root->neighbors.push_back(visited[node->neighbors[i]->val]);
        }
        return root;
    }
};