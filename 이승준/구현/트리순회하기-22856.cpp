#include <iostream>
#include <vector>

using namespace std;
const int MAX = 100005;

int n, lastNode, cnt;

struct Node {
    int left;
    int right;
};

vector<Node> edge(MAX);

void inorder_traversal(int node) {
    if (edge[node].left != -1)inorder_traversal(edge[node].left);
    lastNode = node;
    if (edge[node].right != -1)inorder_traversal(edge[node].right);
}


void simmilar_inorder_traversal(int node) {
    Node cur = edge[node];
    if (cur.left != -1) {
        cnt++;
        simmilar_inorder_traversal(cur.left);
    }
    if (cur.right != -1) {
        cnt++;
        simmilar_inorder_traversal(cur.right);
    }
    if (node == lastNode) {
        cout << cnt;
        exit(0);
    }
    cnt++;
    return;
}

int main() {
    cin >> n;
    int idx;
    for (int i = 0; i < n; i++) {
        Node newNode = Node();
        cin >> idx >> newNode.left >> newNode.right;
        edge[idx] = newNode;
    }
    inorder_traversal(1);
    simmilar_inorder_traversal(1);
}