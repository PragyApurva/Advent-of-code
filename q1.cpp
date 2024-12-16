#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void solve()
{
    
    ifstream file("file1.txt"); //open the file
    
    int count=0;
    if(file)
    {
        string line;
        int f,s;
        vector<vector<int>>v;
        while(getline(file, line)) //read the file line by line
        {
            // cout << line << endl; //print the line
            int pmax,pmin;
            string s;
            vector<int>v2;
            int prev=0;
            for(int i=0;i<=line.size();i++)
            {
                if(line[i]==' '|| i==line.size())
                {
                    f=stoi(line.substr(prev,i-prev+1));
                    v2.push_back(f);
                    prev=i;
                }
            }
            // cout<<endl;
            v.push_back(v2);
        }
        for(int i=0;i<v.size();i++)
        {
            int prev=v[i][0];
            // if(v[i][1]-prev>0)
            int flag=0;
            int initsec=0;
            int sec=0;
            for(int j=1;j<v[i].size();j++)
            {
                // cout<<v[i][j]<<" ";
                if(initsec==0)
                {
                    if( v[i][j]-prev < 0)
                        initsec=-1;
                    else if(v[i][j]-prev > 0)
                        initsec=1;
                }
                if( v[i][j]-prev < 0)
                    sec=-1;
                else if(v[i][j]-prev > 0)
                    sec=1;
                if(abs(v[i][j]-prev)<1 || abs(v[i][j]-prev)>3 || sec!=initsec || sec==0)
                {
                    flag++;
                    // break;
                }
                if(flag==1)
                    continue;
                prev=v[i][j];
            }
            if(flag<2){
            count ++;
            cout<<count<<endl;}
        }
        cout<<count<<endl;
    }
    else
    {
        cout << "Error opening file" << endl;
    }

    return ;
}
int main(){
    solve();
    return 0;
}