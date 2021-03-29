#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
const int NMAX = 50;
long long C[51][51]; 


void comb_table(int N) {
    for(int i=0;i<=N;++i){
        for(int j=0;j<=i;++j){
            if(j==0 or j==i){
                C[i][j]=1LL;
            } else {   
                C[i][j]=(C[i-1][j-1]+C[i-1][j]);    
            }
        }
    }
}


int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<long long> V;
    for (int i = 0; i < N; i++) {
        long long v; cin >> v;
        V.push_back(v);
    }

    // 降順でソート
    sort(V.begin(), V.end(), greater<long long>());

    long long cnt = 0;
    double max_avg = 0;
    long long max_count = 0;
    int cum_sum = 0;
    for (int i = 0; i < (int)V.size(); i++) {
        cnt += 1;
        cum_sum += V[i];
        if (cnt >= A && cnt <= B) {
            double cur_avg = cum_sum / (double)cnt;
            max_avg = max(max_avg, cur_avg);
        }
    }

    // maxの求め方は正解. 後は数え上げだけ.
    

    std::cout << fixed << setprecision(6) << max_avg << endl;
    std::cout << max_count << endl;



    return 0;
}