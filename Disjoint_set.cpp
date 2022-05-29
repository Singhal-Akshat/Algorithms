
#include<vector>
#include<iostream>
using namespace std;

class disjoint_set
{
    int find(int u, vector<int> &parent)
    {
        if(parent[u]<0)
        return u;
        else
        return find(parent[u],parent);
    }

    void unionByWeight(int u, int v, vector<int> &parent)
    {
        int pu = find(u, parent), pv = find(v, parent);

        if(pu!=pv)
        {
            if(parent[pu]<parent[pv])
            {
                parent[pu]+=parent[pv];
                parent[pv] = pu;
            }
            else
            {
                parent[pv] += parent[pu];
                parent[pu] = pv;
            }
        }
    }
};
int main()
{   
    int v;
    cin>>v; // vertices in the graph
    
    vector<int> parent(v,-1) ; // make a parent array for all vertices in the graph;
                            // initilize all ements with -1
                            // in the end a index having -n value represent n vertices below it
                            // and index having k value represents 'k' as root of that index
                        

    // if parent of two elements matches then it show that if we join them then cycle will form


}