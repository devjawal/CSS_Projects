#include<iostream>
using namespace std;
string even_parity(string msg){
    int l=msg.length();
    int count=0;
    for(int i=0;i<l;i++){
        if(msg[i]=='1'){
            count++;
        }
    }
    if(count%2==0){
        msg=msg+'0';
    }
    else{
        msg=msg+'1';
    }
    cout<<"Sending msg in even parity: "<<msg<<endl;
    return msg;
}
string odd_parity(string msg){
    int l=msg.length();
    int count=0;
    for(int i=0;i<l;i++){
        if(msg[i]=='1'){
            count++;
        }
    }
    if(count%2==0){
        msg=msg+'1';
    }
    else{
        msg=msg+'0';
    }
    cout<<"Sending msg in odd parity: "<<msg<<endl;
    return msg;

}
void reciever(string r,string msg){
    if(r==msg){
        cout<<"Message recieved correctly. \n"<<endl;

    }
    else{
        cout<<"Incorrect message recieved! \n "<<endl;
    }
}
int main(){
    string msg,r;
    cout<<"\nName: Devkaran Jawal\n Reg No: 22BCE3048\n"<<endl;
    cout<<"Enter data bits: "<<endl;
    cin>>msg;
    string ans=even_parity(msg);
    
    cout<<"Enter msg recieved for even parity: "<<endl;
    cin>>r;
    reciever(r,ans);
    ans=odd_parity(msg);
    cout<<"Enter msg recieved for odd parity: "<<endl;
    cin>>r;
    reciever(r,ans);
    return 0;
}