/**
 * @file Implement_DfsBfs.cpp
 * @author evan (evan20010126@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-12-22
 * 雙向圖
 *
 **/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct node *nodeptr;

struct node {
    /* data */
    nodeptr next;
    int data;
    node() : next(nullptr), data(0){};
    node(int i) : next(nullptr), data(i){};
};

void add_node(nodeptr *adjacency_list, int idx, int data) {
    if (*(adjacency_list + idx) == nullptr) {
        *(adjacency_list + idx) = new node(data);
    } else {
        nodeptr tmp;
        for (tmp = *(adjacency_list + idx); tmp->next != nullptr; tmp = tmp->next)
            ;
        tmp->next = new node(data);
    }
}
void bfs(nodeptr *adjacency_list, int max, int start) {
    /* init */
    queue<int> qu;
    int *visited = new int[max + 1];
    for (int i = 0; i < max + 1; ++i) {
        *(visited + i) = 0;
    }

    /* Step 1 */
    qu.push(start);
    visited[start] = 1;
    cout << start << " ";

    /* Step 2 */
    while (qu.size() > 0) {
        int target = qu.front();
        qu.pop();
        nodeptr tmp;
        // if (adjacency_list[idx] != nullptr)
        for (tmp = *(adjacency_list + target); tmp != nullptr; tmp = tmp->next)
            if (visited[tmp->data] == 0) {
                cout << tmp->data << " ";
                qu.push(tmp->data); // 還沒進入queue過
                visited[tmp->data] = 1;
            }
    }
}

int main() {
    int in1, in2;
    vector<pair<int, int>> vec;
    int max = -1;
    while (cin >> in1 >> in2) {
        vec.push_back({in1, in2});
        if (in1 > max)
            max = in1;
        if (in2 > max)
            max = in2;
    }
    nodeptr *adjacency_list = new nodeptr[max + 1];
    for (int i = 0; i < max + 1; ++i) {
        *(adjacency_list + i) = nullptr;
    }

    // for (auto &[f, s] : vec) {
    for (auto p : vec) {
        add_node(adjacency_list, p.first, p.second);
        add_node(adjacency_list, p.second, p.first);
    }

    nodeptr tmp;
    // for (int idx = 0; idx < max + 1; idx++) {
    //     cout << idx << ":";
    //     for (tmp = *(adjacency_list + idx); tmp->next != nullptr; tmp = tmp->next)
    //         cout << tmp->data << " ";
    //     cout << tmp->data << " ";
    //     cout << endl;
    // }
    bfs(adjacency_list, max, 0);

    return 0;
}