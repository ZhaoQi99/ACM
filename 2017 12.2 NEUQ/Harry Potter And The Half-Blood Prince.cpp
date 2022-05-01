#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int k, b;
    while(cin >> k >> b)
    {
        char s[2000];
        char ans[2000];
        memset(s,'\0',sizeof(s));
        memset(ans,'\0',sizeof(ans));
        getchar();
        gets(s);
        for(int i = 0; i < strlen(s); i++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
            {
                int y;
                int x = (int)s[i] - 65;
                y = (k * x + b) % 26;
                ans[i] = 'A'+y;
            }
            else if(s[i] >= 'a' && s[i] <= 'z')
            {
                //小写字母
                int y;
                int x = (int)s[i] - 97;
                y = (k * x + b) % 26;
                ans[i] = 'a'+y;
            }
            else
                ans[i]=s[i];
        }
        cout << ans<<endl;
    }
    return 0;
}
