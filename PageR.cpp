#include<bits/stdc++.h>
using namespace std;
// upation 1) can use switch for fifo lru and optimal options;
bool ispresent(int n,int m,int frame[]){
    for(int i=0;i<m;i++){
        if(frame[i]==n) return true;
    }
    return false;
}
int long_future_index(int page[],int n,int curr,int id){
    for(int i=0;i<n;++i){
        if(page[i]==id && i>curr){
            return i;
        }
    }
    return -1;
}
int optimal_frame_index(int page[],int frame[],int index,int n,int m){
    int max = INT_MIN;
    for(int i=0;i<m;++i){
        int m = long_future_index(page,n,index,frame[i]);
        if(m==-1) return i;
        if(m>max){
            max = i;
        } 
    }
    for(int i=0;i<m;++i){
        if(page[max]==frame[i]){
            return i;
        }
    }
}
pair<int,int>optimal(int n,int m,int page[],int frame[]){
    int hit=0 ,fault=m;
    for(int i=0;i<m;++i){
        frame[i]=page[i];
    }
    for(int i=m;i<n;++i){
        if(!ispresent(page[i],m,frame)){
            frame[optimal_frame_index(page,frame,i,n,m)]=page[i];
            fault++;
        }else{
            hit++;
        }
    }
    return(make_pair(hit,fault));
}
int nearby_back_index(int pages[],int n,int id){
    while(n--){
        if(pages[n]==id){
            return n;
        }
    }return -1;
}
int least_back_frame_index(int pages[],int frame[],int l,int m){
    int min = INT_MAX;
    for(int i=0;i<m;++i){
        if(nearby_back_index(pages,l,frame[i])<min){
            min = i;
        }
    }
    for(int i=0;i<m;++i) if(frame[i]==pages[min]) 
    return i;
}
pair<int,int>lru(int n,int m,int page[],int frame[]){
    // memset(frame,NULL,m);//clear the frame not mandatory
    int hit=0,fault=m;
    for(int i=0;i<m;++i) frame[i]=page[i];
    for(int i=m;i<n;++i){
        if(!ispresent(page[i],m,frame)){
            frame[least_back_frame_index(page,frame,i,m)]=page[i];
            fault++;
        }else{
            hit++;
        }
    }
    return make_pair(hit,fault);
}
pair<int,int>fifo(int n,int m,int page[],int frame[]){
    // memset(frame,NULL,m);
    int top = 0,fault = m,hit=0;
    for(int i=0;i<m;++i){
        frame[i]=page[i];
    }
    for(int i=m;i<n;++i){
        if(!ispresent(page[i],m,frame)){
            if(top>=m) top=0;
            frame[top]=page[i];
            fault++;
            top++;
        }else{
            hit++;
        }
    }
    return make_pair(hit,fault);
}
int main(){
    cout<<"enter no of pages ";
    int n,m;
    cin>>n;
    cout<<"enter frame size ";
    cin>>m;
    int page[n],frame[m];
    cout<<"enter pages "<<endl;
    for(int i=0;i<n;++i){
        cin>>page[i];
    }
    // cout<<"hits for fifo ";
    // cout<<fifo(n,m,page,frame).first<<endl;
    // cout<<"faults for fifo ";
    // cout<<fifo(n,m,page,frame).second<<endl;
    cout<<"hits for lru ";
    cout<<lru(n,m,page,frame).first<<endl;
    cout<<"faults for lru ";
    cout<<lru(n,m,page,frame).second<<endl;
    // cout<<"hits for optimal ";
    // cout<<optimal(n,m,page,frame).first<<endl;
    // cout<<"faults for optimal ";
    // cout<<optimal(n,m,page,frame).second<<endl;
    return 0;
}
