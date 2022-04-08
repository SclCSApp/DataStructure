#include<iostream>
#define max 11000
using namespace std;


int L1[max]={0};
int L2[max]={0};
int add[max]={0};
int mul[max]={0};

int main()
{
    int n,m;
    int coef,expn;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>coef>>expn;
        L1[expn]=coef;
    }

    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>coef>>expn;
        L2[expn]=coef;
    }

    for(int i=0;i<max;i++)
        if(L1[i]||L2[i])
            add[i]=L1[i]+L2[i];

    for(int i=0;i<max;i++)
        for(int j=0;j<max;j++)
            if(L1[i]&&L2[j])
                mul[i+j]=L1[i]*L2[j]+mul[i+j];

    int flag=0;
    for(int i=10100;i>=0;i--)
        if(mul[i])
        {
            if(flag==0) cout<<mul[i]<<" "<<i;
            else cout<<" "<<mul[i]<<" "<<i;
            flag++;
        }
        if(!flag) cout<<"0 0";
    cout<<endl;


    flag=0;
    for(int i=10999;i>=0;i--)
        if(add[i])
        {
            if(flag==0) cout<<add[i]<<" "<<i;
            else cout<<" "<<add[i]<<" "<<i;
            flag++;
        }
    if(!flag) cout<<"0 0";

    return 0;

}

