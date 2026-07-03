#include<bits/stdc++.h>
using namespace std;

int count(int n){
    int c=0;
    while(n>0){
        c+=1;
        n=n-(n%10);
        n=n/10;
    }
    return c;
    
}

int reverse(int n){
    int rev=0;
    while(n>0){
        int p=(n%10) ;
        rev = rev*10 + p;
        n=(n-p)/10;
    }
    return rev;  
}

bool pallindrome(int n){
    if (n == reverse(n)){
        return true;
    }
    else{
        return false;
    }

}

bool Armstrong(int n){
    int check=n;
    int sum=0;
    while(n>0){
        int r=n%10;
        sum+=r*r*r;
        n=n/10;
    }
    return sum==check;
    
}

int divisor(int n){
    vector<int> ls;

    for( int i =1 ; i<=sqrt(n) ; i++){
        if (n%i == 0){
            ls.push_back(i);
            if (n/i != i){
                ls.push_back(n/i);
            }
        }
    }
    sort(ls.begin() , ls.end());
    for(auto it : ls) cout << it << " ";
}

int prime(int n){
    for(int i=2; i<=sqrt(n) ; i++){
        if(n%i == 0){
            return false;
        }
        else return true;
    }
}

int GCD(int N1, int N2){
    int GCD=1;
    for(int i=1 ; i<=min(N1,N2) ; i++){
        if(N1%i == 0 && N2%i == 0){
            GCD=i;
        }
    }
    return GCD;
}

void printName(string name,int c=0){
    if(c==5) return;
    cout << name;
    c+=1;
    printName(name,c);
}

void printNum(int i,int n){
    if(i>n) return;
    cout << i << " ";
    printNum(i+1,n);
}

void PrintR(int n){
    if(n<=0) return;
    cout << n << " ";
    PrintR(n-1);
}

void PrintNumBack(int i,int N){
    // 1-->N
    if (i<1) return;
    PrintNumBack(i-1,N);
    cout << i << " ";

}

void PNBack(int i,int N){
    // N --> 1
    if (i>N) return;
    PNBack(i+1,N);
    cout << i << " ";
}

void Sum(int sum,int n){
    //parametrised
    if(n<0){
        cout << sum;
        return;
    }
    Sum(sum+n,n-1);
}

int SUMF(int n){
    if (n==0) return 0;
    return n+SUMF(n-1);
}

int Factorial(int n){
    if (n==0) return 1;
    return n*Factorial(n-1);
}
 
void REVERSE_S(int l, int r, int arr[]){
    if (l>=r) return;
    swap(arr[l],arr[r]);
    REVERSE_S(l+1,r-1,arr);
}

//single pointer reverse
void S_R(int i, int arr[],int n){
    if(i>=(n-i-1)) return;
    swap(arr[i],arr[n-i-1]);
    S_R(i+1,arr,n);
}

string rev_s(string s){
    string ch="";
    int n;
    n=s.size();
    for(int i=n-1 ; i>=0 ; i--){
        ch+=s[i];
    }
    return ch;
}

int fibonacci(int n){
    //O(2^n)
    if(n<=0) return 0;
    if(n==1) return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}


int main(){
    int n;
    cin >> n;
    cout << fibonacci(n);
    
    return 0;
}