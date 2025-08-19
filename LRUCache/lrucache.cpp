#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
class LruCache
{   
    private:
        list<pair<int,int>> dll;
        unordered_map<int,list<pair<int,int>>::iterator> _map;
        int capacity;
    public:
        LruCache(int capacity)
        {
            this->capacity=capacity;
        }
        int get(int key)
        {
            if(_map.find(key)==_map.end())
            {
                return -1;
            }
            auto it=_map[key];
            int val=it->second;
            dll.erase(it);
            dll.push_front({key,val});
            _map[key]=dll.begin();
            return val;
        }
        void put(int key,int val)
        {
            if(_map.find(key)==_map.end())
            {
                if(dll.size()==this->capacity)
                {
                    auto it=dll.back();
                    _map.erase(it.first);
                    dll.pop_back();
                }
                dll.push_back({key,val});
                _map[key]=dll.begin();
            }
            else
            {
                auto it=_map[key];
                dll.erase(it);
                dll.push_back({key,val});
                _map[key]=dll.begin();
            }
        }
};
int main()
{
    LruCache cache(2);
    cache.put(1,1);
    cache.get(1);
    return 0;
}