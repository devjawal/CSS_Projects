#include<iostream>
#include<string>
using namespace std;
string* checksum(string str){
    int n=str.length();
    int div=n/2;
    int k=n/div;int r=n%div;
    string* arr=new string[k+1];int j=0;int i=0;
    for(i=0;i<k;i++){
        arr[i]=str.substr(j,div);
        j+=div;
    }
    if(r>0){
        arr[i]=string(div-r,'0')+str.substr(j,r);
        
    }else{
        arr[i]="";
    }
    cout<<"Array elements:"<<endl;
   for(int j=0;j<i;j++){
    cout<<arr[j]<<endl;
   }cout<<endl;
    return arr;
}
string add_binary(string a,string b)
{
    int a_len=a.length();
    int b_len=b.length();
    string ans="";
    int carry=0;
    int i=0;
    while(i<a_len || i<b_len || carry!=0)
    {
        int x=0;
        if(i<a_len && (a[a_len-1-i]=='1')){
            x=1;
        }
        int y=0;
        if(i<b_len && b[b_len-1-i]=='1'){
            y=1;
        }
        ans=to_string((x+y+carry)%2)+ans;
        carry=(x+y+carry)/2;
        i+=1;
    }
    
    return ans;
}

int main(){
    string str;
    cin>>str;
    int n=str.length();
    int div=n/2;
    int k=n/div;
    string*p;
    p=checksum(str);
    string check="";int i=0;
    for(i=0;i<k;i=i+2){
        check=add_binary(check,add_binary(p[i],p[i+1]));
    }
    for(int j=0;j<check.length();j++){
        if(check[j]=='1'){
            check[j]='0';
        }else{
            check[j]='1';
        }
    }
    str=str+check;
    cout<<check<<endl;
    cout<<str<<" is the transmitted data"<<endl;

    return 0;
}