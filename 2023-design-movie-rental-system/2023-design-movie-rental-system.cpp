class MovieRentingSystem {
public:

    typedef pair<int,int>P;

    unordered_map<int,set<P>>available;//movie->set<{price,shop}>
    unordered_map<int,set<P>>movieToShopPrice;//movie->set<{shop,price}>
    set<tuple<int,int,int>>rented;//{price,shop,movie}

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &entry:entries){
            int shop=entry[0];
            int movie=entry[1];
            int price=entry[2];

            available[movie].insert({price,shop}); //O(logn)
            movieToShopPrice[movie].insert({shop,price}); //O(logn)
        }
    }
    
    vector<int> search(int movie) {
        vector<int>result;
        int count=0;
        if(available.count(movie)){//O(1)
            for(auto &[price,shop]:available[movie]){//At most O(5)
                result.push_back(shop);
                count++;
                if(count>=5)break;
            }
        }
        return result;
    }
    
    void rent(int shop, int movie) {
        auto it=movieToShopPrice[movie].lower_bound({shop,INT_MIN}); //O(logn)
        int price=it->second;

        available[movie].erase({price,shop}); //O(logn)
        rented.insert({price,shop,movie}); //O(logn)
    }
    
    void drop(int shop, int movie) {
        auto it=movieToShopPrice[movie].lower_bound({shop,INT_MIN});//O(logn)
        int price=it->second;
        available[movie].insert({price,shop});//O(logn)
        rented.erase({price,shop,movie});//O(logn)
    }
    
    vector<vector<int>> report() {
        
        vector<vector<int>>result;
        int count=0;

        for(auto &[price,shop,movie]:rented){//O(5)
            result.push_back({shop,movie});
            count++;
            if(count>=5)break;
        }
        return result;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */