#include<iostream>
#include<vector>
using namespace std;

 int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count=0;
        for(int i=0;i<items.size();i++)
        {
            
                if(ruleKey=="type" && items[i][0]==ruleValue)
                {
                    count++;
                    continue;
                }
                else if(ruleKey=="color" && items[i][1]==ruleValue)
                {
                    count++;
                    continue;
                }
                else if(ruleKey=="name" && items[i][2]==ruleValue)
                {
                    count++;
                    continue;
                }
            
        }
        return count;
        
    }
    int main()
    {
        
        return 0;
    }