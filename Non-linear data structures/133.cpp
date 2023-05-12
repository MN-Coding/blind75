/*
Problem: 133. Clone Graph
Time Complexity: O(n)
Space Complexity: O(n)
*/

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
    Node *clone(Node* node, map<Node*, Node*>& visited) {
        Node* newNode = new Node(node->val);
        visited[node] = newNode;
        for (auto x: node->neighbors) {
            if (visited.find(x) != visited.end()) {
                newNode->neighbors.emplace_back(visited[x]);
            } else {
                newNode->neighbors.emplace_back(clone(x, visited));
            }
        }
        return newNode;
    }

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (!node->neighbors.size()) return new Node(node->val);
        map<Node*, Node*> visited;
        return clone(node, visited);
    }
};
