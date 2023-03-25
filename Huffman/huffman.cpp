#include <bits/stdc++.h>

using namespace std;

struct Node {
    int freq;
    char data;
    Node *left;
    Node *right;
};

struct compare {
    bool operator()(Node *l, Node *r) {
        return l->freq > r->freq;
    }
};

void print_codes(struct Node *root, string str) {
    if (!root)
        return;

    if (root->data != '$')
        cout << root->data << ": " << str << " ";

    print_codes(root->left, str + "0");
    print_codes(root->right, str + "1");
}

void huffman_codes(char data[], int freq[], int size) {
    struct Node *left, *right, *top;

    priority_queue<Node *, vector<Node *>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new Node{freq[i], data[i], nullptr, nullptr});

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new Node{left->freq + right->freq, '$', left, right};

        minHeap.push(top);
    }

    print_codes(minHeap.top(), "");
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Variable length codes: " << endl;
    huffman_codes(arr, freq, size);
    
    return 0;
}