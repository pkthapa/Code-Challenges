#include <bits/stdc++.h>

using namespace std;

int CalculateMaxHourGlass(vector<vector<int>> v){
    int max_sum = -100, temp_sum = 0, hgcount = 0;
    vector<int> vr = v[0];

    if((v.size() < 3) || (vr.size() < 3)){return 0;}

    for(int i = 0; i < vr.size() - 2; i++){
        for(int j = 0; j < v.size() - 2; j++){
            temp_sum = 0;
            vr = v[i];
            temp_sum += vr[j] + vr[j + 1] + vr[j + 2];

            vr = v[i + 1];
            temp_sum += vr[j + 1];

            vr = v[i + 2];
            temp_sum += vr[j] + vr[j + 1] + vr[j + 2];

            max_sum = max(max_sum, temp_sum);
        }
    }
    return max_sum;
}

int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << CalculateMaxHourGlass(arr);
    return 0;
}