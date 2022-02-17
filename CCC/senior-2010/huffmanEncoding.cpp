// Arnav Kumar
// Huffman Encoding CCC 2010 senior

#include <bits/stdc++.h>
using namespace std;


int k;
char c_temp, i_temp;
string ans;

struct tree_node {
    tree_node* left;
    tree_node* right;
    char value;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    tree_node *root = new tree_node(), *current_node;

    cin >> k;
    while (k--) {
        cin >> c_temp;

        current_node = root;
        while (cin.get(i_temp), i_temp != '\n') {
            if (i_temp == '0') {
                if (current_node->left) {
                    current_node = current_node->left;
                } else {
                    current_node->left = new tree_node();
                    current_node = current_node->left;
                }
            } else if (i_temp == '1') {
                if (current_node->right) {
                    current_node = current_node->right;
                } else {
                    current_node->right = new tree_node();
                    current_node = current_node->right;
                }
            }
        }

        current_node->value = c_temp;
    }

    current_node = root;
    while (cin >> c_temp) {
        if (c_temp == '0') {
            current_node = current_node->left;
        } else if (c_temp == '1') {
            current_node = current_node->right;
        }

        if (current_node->value) {
            ans += current_node->value;
            current_node = root;
        }
    }

    cout << ans << endl;

    return 0;
}