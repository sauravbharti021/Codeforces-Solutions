   vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
    /*    for(int i=0; i<V; i++){
            cout<<i<<" : ";
            for(int j=0;j<adj[i].size(); j++){
            cout<<'{'<<adj[i][j][0]<<", "<<adj[i][j][1]<<" }, ";
            cout<<endl;
            }
        }  */
        
        set<pair<int,int>> s;
        
        vector<int> dis(V+1, 1e7);
        dis[S]=0;
        
        s.insert(make_pair(0, S));
        
        while(!s.empty() ){
            
            pair<int,int> p =*s.begin();
            s.erase(p);
            
            int d=p.first;
            int prev=p.second;
            
            for(int i=0; i< adj[prev].size();i++){
                if(d+adj[prev][i][1]< dis[adj[prev][i][0]] ){
                    dis[adj[prev][i][0]]=   d+adj[prev][i][1];
                    
                    s.insert(make_pair(dis[adj[prev][i][0]], adj[prev][i][0] ) );
                }
            }
            
        }
     
      return dis;
        }  
     return 0;
      }

Here, we take the weight of the adjacent vertices from the source and keep on updating them to the best of the result.
  
  We use set because the goal is to have minimum weight attached to the source.
