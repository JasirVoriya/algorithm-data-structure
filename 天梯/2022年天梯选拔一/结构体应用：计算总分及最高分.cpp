#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
struct student {
    int id;
    string name;
    double score[3];
    int sum;
};
int main(void)
{
    int n;
    cin >> n;
    student arr[MAX_N], stu;
    double avg = 0, max_score = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].id >> arr[i].name >> arr[i].score[0] >> arr[i].score[1] >> arr[i].score[2];
        arr[i].sum = arr[i].score[0] + arr[i].score[1] + arr[i].score[2];
        cout << arr[i].id << " " << arr[i].name << " " << arr[i].score[0] << " " << arr[i].score[1] << " " << arr[i].score[2] << " " << arr[i].sum << endl;
        avg += arr[i].sum;
        if (arr[i].sum > max_score) {
            max_score = arr[i].sum;
            stu = arr[i];
        }
    }
    printf("总平均分=%lf\n", avg / n / 3);
    cout << stu.id << " " << stu.name << " " << stu.score[0] << " " << stu.score[1] << " " << stu.score[2] << " " << stu.sum;
    return 0;
}