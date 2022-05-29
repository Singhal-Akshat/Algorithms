#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
    return a.first > b.first;
}
void job_sequence(vector<pair<int,int>> job)
{   
    int count =0 ;
    int maxProfit = 0;
    sort(job.begin(),job.end(),compare);

    int maxEndtime = 0;

    for(int i=0;i<job.size();i++)
    {
        if(job[i].second > maxEndtime)
            maxEndtime = job[i].second;
    }

    vector<int> time(maxEndtime,-1);

    for(int i=0;i<job.size();i++)
    {
        int j = job[i].second - 1;

        // while(j>=0 && time[j] != -1)
        // {
        //     j--;
        // }

        // if(j>=0 && time[j] == -1)
        // {
        //     time[j] = i;
        //     count++;
        //     maxProfit += job[i].first;
        // }

        if(time[j] == -1)
        {
            time[j] = i;
            count++;
            maxProfit += job[i].first;
        }
        else
        {
            for(int k = j-1; k>=0;k--)
            {
                if(time[k] == -1)
                {
                    time[k] = i;
                    count++;
                    maxProfit += job[i].first;
                    break;
                }
                
            }
        }
    }

    cout<<count<<" "<<maxProfit<<endl;
}

int main()
{
    vector<pair<int, int>> job;

    int profit, deadline;

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>profit>>deadline;
        job.push_back(make_pair(profit,deadline));
    }

    job_sequence(job);
}