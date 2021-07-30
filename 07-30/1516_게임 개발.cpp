#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int cost[501]; // �ش� �ǹ��� ���µ� ��� �ð�
int ans[501]; // ���������� ������ϴ� �ǹ��� ���� �ð��� ������ �ǹ��� ���µ� ��� �ð�
int indegree[501]; // ���� ����
vector<int> vec[501]; // ���� �ǹ� ����Ʈ

void bfs() {

    queue<int> q;
    for (int n = 1; n <= N; n++) {
        if (indegree[n] == 0) {
            q.push(n);
            ans[n] = cost[n];
        } // ���� ������ ���� �ǹ��� ���� ���´�.
    }

    while (!q.empty()) {
        int nedge = q.front();
        q.pop();
        for (int m = 0; m < vec[nedge].size(); m++) {
            int e = vec[nedge][m];
            ans[e] = max(ans[e], ans[nedge] + cost[e]);
            if (--indegree[e] == 0) {
                q.push(e);
            }
        }
    }
}

int main() {

    cin >> N;
    for (int n = 1; n <= N; n++) {
        int edge; // ���� �ǹ��� �Է¹��� ����
        cin >> cost[n];
        while (cin >> edge, edge != -1) {
            vec[edge].push_back(n);
            indegree[n]++;    //��������
        }
    }
    bfs();
    for (int n = 1; n <= N; n++){
        cout << ans[n] << endl;
    }


    return 0;

}
