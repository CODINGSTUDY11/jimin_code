#include <iostream>
#include <queue>
#include <vector>
#include<algorithm>

using namespace std;

void insert(vector<pair<int, pair<int, int>>> &photoCase, int fNum) {
	bool check = true;
	int pSize = photoCase.size();
	for (int i = 0; i < pSize; i++) {
		if (photoCase.at(i).first == fNum) { // ã�� ����� ��� ��õ�� �ø���
			photoCase.at(i).second.first++;
			check = false;
		}
		photoCase.at(i).second.second++; // �ð� �ø���
	}
	if (check) { // ���� ã�� ����� ��õ �������� �����ٸ� �߰�
		photoCase.push_back(make_pair(fNum, make_pair(1, 1)));
	}
}

void pop(vector<pair<int, pair<int, int>>>& photoCase) {
	pair<int, int> ch1 = make_pair(-1, 100001); // ��� / ��õ�� or ��� / �ð�
	int pSize = photoCase.size();
	int index = 0;
	vector< pair<int,pair<int, int>>> a; // �ε��� /��� / �ð� �ߺ��Ǵ� ��� ����
	for (int i = 0; i < pSize - 1; i++) { 
		// ����� �ϳ� ���� ������ �̸� �ְ� pop�ϴ� ������ �ڵ带 ¥�� ���� ���꿡 ���� ���� ����� ������ ���� �ʰ� �ϱ� ���ؼ���.
		if (photoCase.at(i).second.first < ch1.second) {
			ch1.first = photoCase.at(i).first;
			ch1.second = photoCase.at(i).second.first;
			index = i;
			if (!a.empty()) {
				a.clear();
			}
			a.push_back(make_pair(i, ch1)); 
		}
		else if (photoCase.at(i).second.first == ch1.second) {
			a.push_back(make_pair(i, make_pair(photoCase.at(i).first, photoCase.at(i).second.first)));
		} // ��õ���� �������� �ִ� ���
	}
	if (a.size() > 1) {
		ch1 = make_pair(-1, -1);
		for (int i = 0; i < a.size(); i++) {
			if (a.at(i).second.second > ch1.second ) {
				ch1.first = photoCase.at(i).first;
				ch1.second = photoCase.at(i).second.second;
				index = i;
			}
		} //�����Ǹ� ����°�
		for (int i = a.at(index).first; i < pSize - 1; i++) {
			pair<int, pair<int, int>> temp = photoCase.at(i);
			photoCase.at(i) = photoCase.at(i + 1);
			photoCase.at(i + 1) = temp;
		} // ������ erase ������ ������ �� ���� ������ �� ����� �ٽ� �����ϴ� ������ erase ����� ���� ����� �̸� �� �ڷ� ���� �����Ͽ� ������ ������带 �ٿ���
	}
	else {
		for (int i = index; i < pSize - 1; i++) {
			pair<int, pair<int, int>> temp = photoCase.at(i);
			photoCase.at(i) = photoCase.at(i + 1);
			photoCase.at(i + 1) = temp;
		}
	}
	photoCase.erase(photoCase.begin() + pSize - 1);
}

int main(void) {
	int n, stdNum;
	cin >> n >> stdNum;
	vector<pair<int, pair<int, int>>> photoCase; // �л� ��ȣ,  ��õ��, case�ȿ� �ִ� �ð�
	int Idx = 0;
	for (int i = 0; i < stdNum; i++) {
		int temp;
		cin >> temp;
		insert(photoCase, temp);
		if (photoCase.size() > n) {
			pop(photoCase);
		}
	}
	sort(photoCase.begin(), photoCase.end());
	for (int i = 0; i < photoCase.size(); i++) {
		cout << photoCase.at(i).first << " ";
	}
}