#include<iostream>
#include<vector>
using namespace std ;    
	void resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<long long>>dp(n,vector<long long>(k,0));
        dp[0][nums[0]%k]++;
        for(int i=1;i<n;i++){
       long long rem=(dp[i][nums[i-1]%k]*nums[i])%k;
        dp[i][rem]++;
        }
        for(auto& it : dp){
        	for(int val : it ){
        		cout<<val<<" ";
			}
			cout<<endl;
		}
		return ;
    }
int main(){
	vector<int>arr={1,2,3,4,5};
	resultArray(arr,3);
	return 0;
}