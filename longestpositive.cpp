#include <vector>
using namespace std;

vector<int> lgpm(vector<int> nums){
    
    // split the vector with 0
    vector<vector<int>> sp_nums = {{-1,0,0,0,0}};

    for (int i = 0, k = 0; i < nums.size(); ++i)
    {
        if (nums[i]>0)
        {
            sp_nums[k][4]=i+1;
        }
        else if(nums[i]==0){
            // break
            sp_nums[k][4]=i;
            while(nums[i]==0){
                ++i;
            }
            --i;
            sp_nums.push_back({-1,0,0,i+1,0}); // first neg, last neg, num neg, start, end
            k += 1;
        }
        else if(nums[i]<0){
            if (sp_nums[k][0]<0){
                sp_nums[k][0]=i;
                sp_nums[k][1]=i;
            }else{
                sp_nums[k][1]=i;
            }
            sp_nums[k][2] += 1;
            sp_nums[k][4] = i+1;
        }
    }

    auto length_max = 0, k_max = 0;

    for (int k = 0,length_k = 0; k < sp_nums.size(); ++k)
    {
        if (sp_nums[k][2]%2==0)
        {
            length_k = sp_nums[k][4] - sp_nums[k][3];
        }
        else
        {
            length_k = sp_nums[k][4] - sp_nums[k][0] > sp_nums[k][1]-sp_nums[k][3] ? sp_nums[k][4] - sp_nums[k][0] : sp_nums[k][1]-sp_nums[k][3];
        }
        
        if (length_k>length_max)
        {
            length_max = length_k;
            k_max = k;
        }
    }
    
    return sp_nums[k_max];
    
    // // split the vector with 0 and -
    // int sp_start = 0, sp_end = 1, break_mark = 0, sp_start_mark = sp_end_mark=0;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (nums[i]>0){
    //         ++sp_end;
    //     }
    //     else if(nums[i]==0){
    //         // break
    //         break_mark = 0;
    //         if (sp_end-sp_start>sp_end_mark-sp_start_mark)
    //         {
    //             sp_start_mark = sp_start;
    //             sp_end_mark = sp_end;
    //         }
            
    //         sp_start = i+1;
    //         sp_end = sp_start + 1;
    //     }
    //     else if(break_mark==1){
    //         --break_mark;
    //         sp_end = i+1;
    //     }
    //     else if(break_mark==0){
    //         ++break_mark;
    //         sp_end = i;
    //     }
    // }
    
} 

int main(){
    auto re = lgpm({-1,-2,-3,0,1});
    return 0;
}