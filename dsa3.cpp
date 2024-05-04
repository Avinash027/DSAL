#include <iostream>
using namespace std;

// Structure declaration
struct Node {
    int data;
    Node* right;
    Node* left;
};

// Function to create a new node
Node* create(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a node
void insert(Node* &root, int data) {
    if (root == NULL) {
        root = create(data);
    } else if (root->data > data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

// Preorder traversal
void displayPre(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        displayPre(root->left);
        displayPre(root->right);
    }
}

// Inorder traversal
void displayIn(Node* root) {
    if (root != NULL) {
        displayIn(root->left);
        cout << root->data << " ";
        displayIn(root->right);
    }
}

// Postorder traversal
void displayPost(Node* root) {
    if (root != NULL) {
        displayPost(root->left);
        displayPost(root->right);
        cout << root->data << " ";
    }
}

// Function to calculate the height of the tree
int height(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int l_h = height(root->left);
        int r_h = height(root->right);
        return max(l_h, r_h) + 1;
    }
}

// Function to search for a value in the tree
void search(Node* root, int value) {
    if (root != NULL) {
        if (root->data > value) {
            search(root->left, value);
        } else if (root->data < value) {
            search(root->right, value);
        } else if (root->data == value) {
            cout << "\nElement FOUND";
        }
    } else {
        cout << "\nElement NOT found";
    }
}

// Function to find the smallest element
void smallest(Node* root) {
    if (root->left != NULL) {
        smallest(root->left);
    } else {
        cout << "Smallest :: " << root->data;
    }
}

// Function to find the largest element
void largest(Node* root) {
    if (root->right != NULL) {
        largest(root->right);
    } else {
        cout << "\nLargest :: " << root->data;
    }
}

// Function to mirror the tree
void mirror(Node* root) {
    if (root == NULL) {
        return;
    }
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

int main() {
    bool loop = true;
    Node* root = NULL;
    int ch, n, num;

    cout << "\n-----MENU-----\n"
         << "1. Create BST\n"
         << "2. Preorder\n"
         << "3. Inorder\n"
         << "4. Postorder\n"
         << "5. Height\n"
         << "6. Search\n"
         << "7. Smallest\n"
         << "8. Largest\n"
         << "9. Mirror\n"
         << "10. Exit\n";

    while (loop) {
        cout << "ENTER :: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                cout << "---------------------------\n";
                cout << "Enter the number of elements :: ";
                cin >> n;
                cout << "Enter the numbers :: ";
                for (int i = 0; i < n; i++) {
                    cin >> num;
                    insert(root, num);
                }
                cout << "\n---------------------------\n";
                break;
            }
            case 2: {
                cout << "---------------------------\n";
                cout << "PRE ORDER : ";
                displayPre(root);
                cout << "\n---------------------------\n";
                break;
            }
            case 3: {
                cout << "---------------------------\n";
                cout << "IN ORDER : ";
                displayIn(root);
                cout << "\n---------------------------\n";
                break;
            }
            case 4: {
                cout << "---------------------------\n";
                cout << "POST ORDER : ";
                displayPost(root);
                cout << "\n---------------------------\n";
                break;
            }
            case 5: {
                cout << "---------------------------\n";
                int h = height(root);
                cout << "Height of BST :: " << h;
                cout << "\n---------------------------\n";
                break;
            }
            case 6: {
                cout << "---------------------------\n";
                int value;
                cout << "Enter the element to search :: ";
                cin >> value;
                search(root, value);
                cout << "\n---------------------------\n";
                break;
            }
            case 7: {
                cout << "---------------------------\n";
                smallest(root);
                cout << "\n---------------------------\n";
                break;
            }
            case 8: {
                cout << "---------------------------\n";
                largest(root);
                cout << "\n---------------------------\n";
                break;
            }
            case 9: {
                cout << "---------------------------\n";
                cout << "BEFORE MIRROR\nInorder :: ";
                displayIn(root);
                mirror(root);
                cout << "\nAFTER MIRROR\nInorder :: ";
                displayIn(root);
                cout << "\n---------------------------\n";
                break;
            }
            case 10: {
                loop = false;
                break;
            }
            default: {
                cout << "Invalid choice\n";
                break;
            }
        }
    }

    return 0;
}








