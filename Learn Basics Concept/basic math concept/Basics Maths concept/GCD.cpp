
// GDC 
void gdc(int n,int m){
    int k=abs(n-m);
    int greatest;
    for(int i=1;i<k;k++){
        if(n%i==0 && m%i==0) greatest=i;
    }
    cout<< "GDC =" << greatest;
}
int main(){
    int n;
    cout <<  "enter the number:";
    cin >>n;
    gdc(n);
    return 0;
}
