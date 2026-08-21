class Solution {
public:
    long long gcd(long long a, long long b)
    {
        while(b != 0)
        {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a,long long b)
    {
        return a / gcd(a,b) * b;
    }
    long long countValid(long long amount, vector<int>&coins)
    {
        int n = coins.size();
        long long validCount = 0;

        for(int mask = 1; mask <(1 << n); mask++)
        {
            long long currLCM = 1;
            int selectedCoins = 0;

            for(int i = 0; i < n; i++)
            {
                if(mask & (1 << i))
                {
                    selectedCoins++;

                    currLCM = lcm(currLCM,coins[i]);

                    if(currLCM > amount)
                    {
                        break;
                    }
                }
            }
            if(currLCM > amount)
            {
                continue;
            }
            if(selectedCoins % 2 == 1)
            {
                validCount += amount / currLCM;
            }
            else
            {
                validCount -= amount / currLCM;
            }
        }
        return validCount;
    }

    long long findKthSmallest(vector<int>& coins, int k) 
    {
        long long low = 1;
        long long high = 1LL * k * (*min_element(coins.begin(),coins.end()));
     
        while(low < high)
        {
            long long middle = low + (high - low) / 2;

            if(countValid(middle,coins) >= k)
            {
                high = middle;
            }
            else
            {
                low = middle + 1;
            }
        }
        return low;
    }
};