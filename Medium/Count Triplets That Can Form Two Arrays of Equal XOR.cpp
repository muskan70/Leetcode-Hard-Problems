//Count Triplets That Can Form Two Arrays of Equal XOR : https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
//Method1 : Brute Force --- O(n^4)

//Method2 : O(n^3)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans=0,sum1=0,sum2=0;
        for(int i=0;i<arr.size()-1;i++){
            sum1=0;
            for(int j=i;j<arr.size();j++){
                sum1=sum1^arr[j];
                sum2=0;
                for(int k=j+1;k<arr.size();k++){
                    sum2=sum2^arr[k];
                    if(sum1==sum2){
                        ans++;
                        //cout<<i<<" "<<j<<" "<<k<<"\n";
                    }

                }
            }
        }
        return ans;
    }
};

//Method 3: prefix XOR -O(n^2)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        arr.insert(arr.begin(),0);
        int ans=0,n=arr.size();

        for(int i=1;i<n;i++)
            arr[i]=arr[i-1]^arr[i];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]==arr[j])
                    ans+=(j-i-1);
            }
        }    
        return ans;
    }
};

//Method 4: time: O(n),space :O(n)
int countTriplets(vector<int>& A) {
        A.insert(A.begin(), 0);
        int n = A.size(), res = 0;
        for (int i = 1; i < n; ++i)
            A[i] ^= A[i - 1];
        unordered_map<int, int> count, total;
        for (int i = 0; i < n; ++i) {
            res += count[A[i]]++ * (i - 1) - total[A[i]];
            total[A[i]] += i;
        }
        return res;
    }

//Method 5: single pass O(n)time
int countTriplets(vector<int>& A) {
        int n = A.size(), res = 0, prefix = 0;
        unordered_map<int, int> count = {{0, 1}}, total;
        for (int i = 0; i < n; ++i) {
            prefix ^= A[i];
            res += count[prefix]++ * i - total[prefix];
            total[prefix] += i + 1;
        }
        return res;
    }
    