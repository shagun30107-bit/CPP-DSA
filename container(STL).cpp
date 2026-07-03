#include<bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;

void explainPair(){
    pair<int,int> p = {1,3};
    cout << p.first << " " << p.second;

    pair<int, pair<int,int>> k = {1, {2,3}};
    cout << k.first << " " << k.second.second << " " << k.second.second;
    
    pair<int,int> arr[] = { {1,2} , {3,4} , {5,6}};
    cout << arr[1].second ; //4
}

void explainvector(){
    vector<int> v; //create empty vector
    
    v.push_back(1);     //{1}
    v.emplace_back(2); //work faster than push_back    {1,2}

    vector<pair<int,int>> vec;
    vec.push_back({1,2});      // {{1,2}}
    vec.emplace_back(1,2);  //assume it as a pair   //{{1,2},{1,2}}

    vector<int> v(5,100);  //{100,100,100,100,100}
    vector<int> v(5); //after this line u can inc it's size still

    vector<int> v1(5,20);   //{20,20,20,20,20}
    vector<int> v2(v1);     //create copy of v1

    vector<int>::iterator it=v.begin();
    it++;
    cout << *(it) << " ";

    it=it+2;
    cout << *(it) << " ";

    vector<int>::iterator it= v.end(); //start from right of the last element
    // NEVER USED--
    // vector<int>::iterator it= v.rend();
    // vector<int>::iterator it= v.rbegin();

    cout << v[0] << " " << v.at(0);
    cout << v.back() << " ";

    for (vector<int>::iterator it=v.begin(); it != v.end(); it++ ){
        cout << *(it) << " ";
    }

    for (auto it = v.begin(); it !=v.end() ; it++){
        cout << *(it) << " ";
    }

    for (auto it:v){
        cout << it << " ";
    }

    //{10,11,20,30}
    v.erase(v.begin()+1); //{10,20,30}

    v.erase(v.begin()+2 , v.begin()+4); //here end is excluded

    //Insert function
    vector<int>v(3,100); //{100,100,100}
    v.insert(v.begin(),300);    //{300,100,100}

    v.insert(v.begin()+1,2,10);     //{300,10,10,100,100}

    vector<int> copy(2,50);     //{50,50}
    v.insert(v.begin(),copy.begin(),copy.end()); //{50,50,300,10,10,100,100}

    //{10,20}
    cout << v.size();   //2

    v.pop_back();   //{10}

    // v1 -> {10,20}
    // v2 -> {30,40}
    v1.swap(v2);    //v1->v2 and v2 become v1

    v.clear(); //erases the entire vector

    cout << v.empty();

}

void explainlist(){
    list<int> ls;

    ls.push_back(2);    //{2}
    ls.emplace_back(4); //{2,4}

    ls.push_front(5);   //{5,2,4}
    ls.emplace_front(); //{2,4}; //doubt

    // rest functions same as vector
    // begin,end,rbegin,rend,clear,insert(costly),size,swap

}

void explaiDeques(){

    deque<int>dq;
    dq.push_back(1);    //{1}
    dq.emplace_back(2); //{1,2}
    dq.push_front(4); //{4,1,2}
    dq.emplace_front(3);    //{3,4,1,2}

    dq.pop_back();  //{3,4,1}
    dq.pop_front();     //{4,1}

    dq.back();

    dq.front();

    // rest funtions same as vector
}

void explainStack(){

    //LIFO
    stack<int> st;
    st.push(1);     //{1}
    st.push(2);     //{2,1}
    st.push(3);     //{3,2,1}
    st.push(3);     //{3,3,2,1}
    st.emplace(5);  //{5,3,3,2,1}

    cout << st.top();   //prints 5 "**st[2] is invalid"

    st.pop();   //{3,3,2,1}

    cout << st.top();   //3 it's still in stack

    cout << st.size();  //4
    cout << st.empty();     //False

    stack<int>st1,st2;
    st1.swap(st2);
}

void explainQueue(){

    //FIFO
    queue<int>q;
    q.push(1);  //{1}
    q.push(2);  //{1,2}
    q.emplace(4);   //{1,2,4}

    q.back() +=5;

    cout << q.back() ;   //9

    cout << q.front();  //1
    q.pop();    //{2,9}
    cout << q.front();  //2

    // size,swap,empty,swap same as stack 

}

void explaiPQ(){
    //MAX HEAP
    priority_queue<int>pq;

    pq.push(5); //{5}
    pq.push(2); //{5,2}
    pq.push(8); //{8,5,2}
    pq.emplace(10); //{10,8,5,2} --> order it in decresing 

    cout << pq.top();   //10

    pq.pop();   // {8,5,2}

    cout << pq.top();   //prints 8

    // size swap empty functions same as others

    //MINIMUM HEAP
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);     //{5}
    pq.push(2);     //{2,5} 
    pq.push(8);     //{2,5,8}
    pq.emplace(10);     //{2,5,8,10}

    cout << pq.top();

    //TIME COMPLEXITY-
    //Push,Pop- log(n)
    //top- O(1)

}

void explainSet(){
    //Sorted & unique
    set<int>st;
    st.insert(1);   //{1}
    st.emplace(2);  //{1,2}
    st.insert(2);   //{1,2}
    st.insert(4);   //{1,2,4}
    st.insert(3);   //{1,2,3,4}

    // begin,end,rbegin,rend,size,empty & swap same as other

    //{1,2,3,4,5}
    auto it=st.find(3); //return iterate-2

    //{1,2,3,4,5}
    auto it=st.find(6);     //if it's not in this it's return st.end()-5

    //{1,4,5}
    st.erase(5); //erases 5 takes logathmic time

    //{1,2,3,4,5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1,it2);      //{1,4,5}

    int cnt=st.count(1);

    auto it = st.find(3);
    st.erase(it);

    auto it= st.lower_bound(2);
    auto it = st.upper_bound(3);
 
    // everything happens in log
}

void explaiMultiSet(){
    //everything same as set
    // only store duplicate element as well

    multiset<int>ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1); //{1,1,1}

    ms.erase(1);    // all 1's erased

    // only single 1 erased
    ms.erase(ms.find(1));

    // ms.erase(ms.find(1), ms.find(1) + 2);

    //Rest all same as set

}

void explainUset(){
    unordered_set<int> st;
    // uniques & not sorted 
    //O(1)
    //worst case-O(N)
    //lower and upper bound function not work here
    // rest all functions are same
}

void explainMap(){
    // key-value
    //map store unique keys in sorted order
    map<int,int> mpp;
    map<int, pair<int,int>> mpp;
    map< pair<int,int>,int> mpp;

    mpp[1] =2;
    mpp.emplace(3,1);
    mpp.insert({2,4});
    mpp[(2,3)] =10;

    // {
    //     {1,2}
    //     {2,4}
    //     {3,1}
    // }

    for(auto it:mpp){
        cout << it.first << " " << it.second << endl;
    }

    cout << mpp[1]; //2
    cout << mpp[5]; //0

    // auto it = mpp.find(3);
    // cout << *(it).second ;

    auto it=mpp.find(5);    //return mpp.end()

    auto it=mpp.lower_bound(2);
    auto it=mpp.upper_bound(3);

    //erse,swap,size,empty are same as above

}

void explainMultimap(){
    //duplicate keys allowed
    // everything same as map, only it can store multiple keys
    // only mpp[key] cannot be used here

}

void explainUnorderMap(){
    //uniques and not sorted
    // same as set & unordered_set difference
    //O(1)
    //worst case-O(N)
}


bool comp(pair<int,int>p1,pair<int,int> p2){
    if (p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    // they are same

    if(p1.first > p2.first) return true;
    return false;
}
void explainExtra(){
    pair<int,int> a[]={{1,2},{2,1},{4,1}};
    int n=3;
    vector<int> v={};
    sort(a,a+n);
    sort(v.begin(), v.end());

    sort(a+2,a+4); //a+4 is excluded
    sort(a,a+n, greater<int>());       //sort in descending manner

    pair<int,int> a[]={{1,2},{2,1},{4,1}};
    //sort it according to second element
    //if second element is same then sort
    //it according to first element but in ascending

    sort(a,a+n,comp);
    //{4,1},{2,1},{1,2}

    string s="123";
    sort(s.begin(),s.end());
    do{
        cout << s << endl;
    } while(next_permutation(s.begin() , s.end()));

    // int a[] = {4, 8, 2, 10, 5};
    // int n=5;
    // int maxi = *max_element(a,a + n);
    // cout << maxi;

}

int main() {


    return 0;
}
