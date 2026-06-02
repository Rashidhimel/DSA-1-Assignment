#include <iostream>
#include <queue>
using namespace std;

const int MAX_STACK = 100;

int stack[MAX_STACK];
int top = -1;

void push(int value) {
    if (top < MAX_STACK - 1) {
        top++;
        stack[top] = value;
    }
}

void printStack() {
    cout << "Stack after inorder traversal: [";
    for (int i = 0; i <= top; i++) {
        cout << stack[i];
        if (i != top) cout << ", ";
    }
    cout << "]" << endl;
}

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int value) {
    TreeNode* node = new TreeNode();
    node->val = value;
    node->left = node->right = nullptr;
    return node;
}

void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    push(root->val);
    inorder(root->right);
}

const int MAX_NODES = 100;
int adj[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];
int parent[MAX_NODES];

void bfs(int start, int dest, int nodes) {
    queue<int> q;
    for (int i = 0; i < nodes; i++) {
        visited[i] = false;
        parent[i] = -1;
    }

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < nodes; i++) {
            if (adj[curr][i] && !visited[i]) {
                visited[i] = true;
                parent[i] = curr;
                q.push(i);
            }
        }
    }

    int path[MAX_NODES];
    int pathLen = 0;
    int current = dest;

    while (current != -1) {
        path[pathLen++] = current;
        current = parent[current];
    }

    cout << "BFS path to treasure: [";
    for (int i = pathLen - 1; i >= 0; i--) {
        cout << path[i];
        if (i != 0) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {

    TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(1);
    root->left->right = createNode(3);

    inorder(root);
    printStack();

    int nodes = 4;
    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[1][3] = adj[3][1] = 1;

    int start = 0, dest = 3;
    bfs(start, dest, nodes);

    return 0;
}
