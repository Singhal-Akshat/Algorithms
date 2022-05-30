/*
Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also given that every job takes a single unit of time, so the minimum possible deadline for any job is 1. How to maximize total profit if only one job can be scheduled at a time.

Input: Four Jobs with following deadlines and profits

JobID  Deadline  Profit
  a      4        20   
  b      1        10
  c      1        40  
  d      1        30
Output: Following is maximum profit sequence of jobs
        c, a => 60  


Input:  Five Jobs with following deadlines and profits
JobID   Deadline  Profit
  a       2        100
  b       1        19
  c       2        27
  d       1        25
  e       3        15
Output: Following is maximum profit sequence of jobs
        c, a, e => 147
*/

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
    sort(job.begin(),job.end(),compare); // sorting in descending order w.r.t profit

    int maxEndtime = 0;

    for(int i=0;i<job.size();i++)
    {
        if(job[i].second > maxEndtime)
            maxEndtime = job[i].second; // getting maxtime to create a time array
    }

    vector<int> time(maxEndtime,-1); // intiallizng all values with -1

    for(int i=0;i<job.size();i++)
    { 
        int j = job[i].second - 1;  // getting the time of current job

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

        if(time[j] == -1)  // if time is free then we can directly allocate this block to current job
        {
            time[j] = i;
            count++;
            maxProfit += job[i].first; // adding profit to total profit
        }
        else // otherwise we will check if any free space is there before the current time
        {
            for(int k = j-1; k>=0;k--)
            {
                if(time[k] == -1)
                {
                    time[k] = i;
                    count++; // keeping count of total jobs we can do
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
        job.push_back(make_pair(profit,deadline)); // inserting deadline and profit to our job vector
    }

    job_sequence(job);
}