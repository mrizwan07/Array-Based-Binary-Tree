#include <iostream>
#include <cmath>
using namespace std;

template<typename T>
class ArrayBinaryTree {
    int maxHeight;
    int maxNodes;
    T* data;
    bool* nodeStatus;
    void VLR(int i) {
        cout << data[i] << ":";
        if (nodeStatus[2 * i + 1] == true && 2 * i + 1 < maxNodes)
            VLR(2 * i + 1);
        if (nodeStatus[2 * i + 2] == true && 2 * i + 2 < maxNodes)
            VLR(2 * i + 2);
    }
    void LRV(int i) {
        if (nodeStatus[2 * i + 1] == true && 2 * i + 1 < maxNodes)
            LRV(2 * i + 1);
        if (nodeStatus[2 * i + 2] == true && 2 * i + 2 < maxNodes)
            LRV(2 * i + 2);
        cout << data[i] << ":";
    }
    void LVR(int i) {
        if (nodeStatus[2 * i + 1] == true && 2 * i + 1 < maxNodes)
            LVR(2 * i + 1);
        cout << data[i] << ":";
        if (nodeStatus[2 * i + 2] == true && 2 * i + 2 < maxNodes)
            LVR(2 * i + 2);
    }
    int search(T key, int i) {
        int res = -1;
        if (data[i] == key)
            res = i;
        if (res == -1 && nodeStatus[2 * i + 1] == true && 2 * i + 1 < maxNodes)
            res = search(key, 2 * i + 1);
        if (res == -1 && nodeStatus[2 * i + 2] == true && 2 * i + 2 < maxNodes)
            res = search(key, 2 * i + 2);
        return res;
    }
    int getHeight(int index) {
        int left, right;
        left = right = 0;
        if (index >= maxHeight)
            return 1;
        if (index * 2 + 1 < maxHeight && nodeStatus[index * 2 + 1])
            left = getHeight(index * 2 + 1);
        if (index * 2 + 2 < maxHeight && nodeStatus[index * 2 + 2])
            right = getHeight(index * 2 + 2);
        if (left > right)
            return left + 1;
        return right + 1;
    }
public:
    ArrayBinaryTree(int h) {
        maxHeight = h;
        maxNodes = pow(2, maxHeight) - 1;
        data = new T[maxNodes];
        nodeStatus = new bool[maxNodes];
        for (int i = 0; i < maxNodes; i++) {
            nodeStatus[i] = false;
        }
    }
    ~ArrayBinaryTree() {
        delete[] data;
        delete[] nodeStatus;
    }
    void setRoot(T par) {
        data[0] = par;
        nodeStatus[0] = true;
    }
    void setLeftChild(T par, T ch) {
        int index = search(par, 0);
        if (index == -1)
            return;
        if (2 * index + 1 < maxNodes) {
            data[2 * index + 1] = ch;
            nodeStatus[2 * index + 1] = true;
        }
    }
    void setRightChild(T par, T ch) {
        int index = search(par, 0);
        if (index == -1)
            return;
        if (2 * index + 2 < maxNodes) {
            data[2 * index + 2] = ch;
            nodeStatus[2 * index + 2] = true;
        }
    }
    void preOrder() {
        VLR(0);
    }
    void postOrder() {
        LRV(0);
    }
    void inOrder() {
        LVR(0);
    }
    T getRoot() {
        if (nodeStatus[0])
            return data[0];
        else {
            cout << "\nNO ROOT!!!\n";
            exit(0);
        }
    }
    T getParent(T node) {
        int index = search(node, 0);
        if (index == -1) {
            cout << "\nGiven Node Not Found!!!\n";
            exit(0);
        }
        if (index == 0) {
            cout << "\nGiven Node is Root!!\n";
            exit(0);
        }
        else
            return data[(index - 1) / 2];
    }
    void remove(T node) {
        int index = search(node, 0);
        if (index == -1) {
            cout << "\nGiven Node Not Found\n";
            exit(0);
        }
        else {
            nodeStatus[index] = false;
        }
    }
    void displayAncestors(T node) {
        int index = search(node, 0);
        if (index == -1) {
            cout << "\nGiven Node Not Found!!\n";
            return;
        }
        if (index == 0) {
            cout << "\nGiven Node is Root!!\n";
            return;
        }
        else {
            int parentIndex = (index - 1) / 2;
            while (parentIndex != 0) {
                cout << data[parentIndex] << ":";
                parentIndex = (parentIndex - 1) / 2;
            }
            cout << data[0];
        }
    }
    void displayDescendents(T node) {
        int index = search(node, 0);
        if (index == -1) {
            cout << "\nGiven Node Not Found\n";
            return;
        }
        VLR(index);
    }
    int heightOfTree() {
        return getHeight(0);
    }
    void displayLevel(int levelNo) {
        if (levelNo < 0)
            return;
        if (levelNo == 0)
            cout << data[0] << ":";
        else if (levelNo > 0) {
            displayLevelUtil(0, levelNo, 0);
        }
    }

    void displayLevelUtil(int index, int targetLevel, int currentLevel) {
        if (index >= maxNodes)
            return;

        if (currentLevel == targetLevel)
            cout << data[index] << ":";

        displayLevelUtil(2 * index + 1, targetLevel, currentLevel + 1);
        displayLevelUtil(2 * index + 2, targetLevel, currentLevel + 1);
    }

};

int main() {
    ArrayBinaryTree<char> bt(4);
    //bt.setRoot('a');
    bt.setLeftChild('a', 'b');
    bt.setRightChild('a', 'c');
    bt.setLeftChild('b', 'd');
    bt.setRightChild('b', 'e');
    bt.preOrder();
    cout << endl;
    bt.postOrder();
    cout << endl;
    bt.inOrder();
    cout << endl;
    bt.displayAncestors('d');
    cout << endl;
    bt.displayDescendents('b');
    return 0;
}
