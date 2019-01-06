using namespace std;

int reductionCost(vector<int> num){
    int v_size = num.size(), offset = 0, totalSum = 0;
    int sumArr[v_size];
    memset(sumArr, 0, v_size);
    sort(num.begin(), num.end());

    while(true){
        sumArr[offset] = num[0] + num[1];

        if(num.size() > 2){
            num.erase(num.begin(), num.begin() + 2);
            num.push_back(sumArr[offset++]);
            sort(num.begin(), num.end());
        }
        else{
            break;
        }
    }
    while(offset >= 0){
        totalSum += sumArr[offset--];
    }
    return totalSum;
}

int main()
{
    vector<int> v{1, 3, 2, 5, 2, 6};
    cout<<reductionCost(v);
    return 0;
}
