
// Best Time to Buy and Sell Stock with Cooldown


class Solution {
public:
    vector<vector<vector<int>>> memo;
int dp(int i,vector<int>& arr,bool bought,bool cooldown)
{
	if(i>=arr.size())
		return 0;
	else if(memo[i][bought][cooldown]!=-1)
		return memo[i][bought][cooldown];
	else
	{
		int not_taken=dp(i+1,arr,bought,false),taken=0;// when you skip the current day, you will anyways be out of cooldown period.
		if(bought)
			taken=arr[i]+dp(i+1,arr,false,true);
		else
			if(cooldown==false)
				taken=-arr[i]+dp(i+1,arr,true,false);
		return memo[i][bought][cooldown]=max(taken,not_taken);
	}
}
int maxProfit(vector<int>& prices) 
{
	memo.resize(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
	return dp(0,prices,false,false);
}
};
