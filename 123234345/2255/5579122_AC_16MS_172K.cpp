#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string post;
void postorder(string a,string b)
{
     if(b.length()==1)  post+=b;
     else
     {
         int k=a.find(b.substr(0,1));
         if(k>0) postorder(a.substr(0,k),b.substr(1,k));
         if(k<a.length()-1)
             postorder(a.substr(k+1,a.length()-k-1),
                       b.substr(k+1,b.length()-k-1));
         post+=a[k];
     }
}
int main()
{
    string pre,in;
    while(cin>>pre>>in)
    {
        postorder(in,pre);
        cout<<post<<endl;
        post.clear();
    }
    return 0;
}