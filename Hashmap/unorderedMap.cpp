#include <iostream>
#include<vector>
#include <unordered_map>

using namespace std;

void display(unordered_map<char, int> map)
{
    for (auto keyValue : map)
    {
        char key = keyValue.first;
        int value = keyValue.second;
        cout << key << " " << value << endl;
    }
}

void freqMap(string &str)
{
    unordered_map<char, int> map;
    for (char ch : str)
    {
        map[ch]++;
    }
    
    for (auto keyValue : map)
    {
        char key = keyValue.first;
        int value = keyValue.second;
        cout << key << " " << value << endl;
    }
    return;
}

void freqMap_pos(string &str){
    unordered_map<char, vector<int>> map;

    for(int i=0;i<str.length();i++){
        char ch = str[i];
        map[ch].push_back(i);
    }
    
    for (auto keyValue : map)
    {
        cout<<keyValue.first<< "->";
        for(int ele : keyValue.second){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return;
}

//leetcode 771
  int numJewelsInStones(string j, string s) {
        unordered_map<char, int>map;
        int ans = 0;
        for(int i=0; i<j.length();i++){
            map[j[i]] = 1;
        }

        for(int i=0;i<s.length();i++){
            if(map.find(s[i]) != map.end()){
                ans++;
            }
        }

    return ans;
    }

    // leetcode 1832
      bool checkIfPangram(string s) {
        unordered_map<char, int>map;

        for(int i=0;i<s.length();i++){
            char ch = s[i];
            map[ch]++;
        }

        return map.size() == 26;
    }

int main()
{

    // unordered_map<string, int> map;

    // map.insert({"N", 1});
    // map.insert({"I", 1});
    // map.insert({"S", 1});
    // map.insert({"H", 2});
    // map.insert({"T", 1});
    // map.insert({"A", 1});

    // // another way of inserting
    // map["G"];
    // map["O"] = 1;

    // // change the values
    // map["N"] = 2;

    // // return value for the specified key
    // cout << map["H"] << endl;
    // cout << map.at("N") << endl;

    // // remove elements
    // map.erase("G");
    string str = "aabbbbgghthtyjjhuhrgcdgcdjcfxffdtdt";
    // freqMap(str);
    freqMap_pos(str);

   
}