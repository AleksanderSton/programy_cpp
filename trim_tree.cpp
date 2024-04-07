#include <iostream>
#include <stack>
#include <unordered_set>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node*& root, int data) {
    if (root == nullptr)
        return createNode(data);
    if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void findPair(Node* root, int k) {
    if (root == nullptr) return;

    stack<Node*> st;
    unordered_set<int> visited;

    Node* current = root;

    while (current != nullptr || !st.empty()) {
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();

        int complement = k - current->data;
        if (visited.find(complement) != visited.end()) {
            cout << complement << ' ' << current->data << '\n';
            return;
        }

        visited.insert(current->data);

        current = current->right;
    }

    cout << "NIE ZNALEZIONO\n";
}


Node* trimTree(Node* root, int a, int b) {
    if (root == nullptr)
        return nullptr;

    if (root->data < a)
        return trimTree(root->right, a, b);
    else if (root->data > b)
        return trimTree(root->left, a, b);
    else {
        root->left = trimTree(root->left, a, b);
        root->right = trimTree(root->right, a, b);
        return root;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, a, b, k;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int influence;
        cin >> influence;
        root = insert(root, influence);
    }

    cin >> a >> b >> k;
    Node* new_root = trimTree(root, a, b);

    findPair(new_root,k);

    return 0;
}