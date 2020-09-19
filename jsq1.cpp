#include<bits/stdc++.h> 
using namespace std;
#define N 200
int  check(char a[]){
	int j=1;
	for(int i=0;i<strlen(a);i++){
		if(a[i]>='0'&&a[i]<='9'){			
		continue;
		}		
		else {
			cout<<"error"<<endl;
			j=0;
		}					
	} 
	return j;
}
void add(){
	char a[1000],b[1000];
	int c[1001],d[1001];
	int alen,blen,maxlen;
		cout<<"请输入第一个数字"; 
		cin>>a; 
		//cout<<"check="<<check(a)<<endl;
		if(check(a)==0){
			//cout<<"return";
			return;	
		}
					
		cout<<"请输入第二个数字";
		cin>>b;
		if(check(b)==0)
			return;
		alen=strlen(a);
		blen=strlen(b);
		int tmp=0;
		for(int j=alen-1;j>=0;j--){
			c[tmp++]=a[j]-'0';
			}
		
		tmp=0;
		for(int k=blen-1;k>=0;k--){
		d[tmp++]=b[k]-'0';
		}
			
		if(alen>blen){
			for(int j=blen;j<=alen;j++)
			{	d[j]=0;
			}
			c[alen]=0;
		}
		else if(alen<blen){
			for(int j=alen;j<=blen;j++)
			{c[j]=0;
			}	
			d[blen]=0;
			
		}
		else {c[alen]=0;
			d[blen]=0;
		}
			
		maxlen=(alen>=blen)?alen:blen;
		for(int j=0;j<=maxlen;j++){
			c[j]+=d[j];
			if(c[j]>=10){
				c[j]-=10;
				c[j+1]+=1;
			}	
		}
	
		cout<<"=";
		if(c[maxlen]==0){
			for(int j=maxlen-1;j>=0;j--)
				cout<<c[j];	
		}
		else {
			for(int j=maxlen;j>=0;j--)
				cout<<c[j];
		}
		cout<<endl<<endl;
	
}
void sub(){
	char a[1000],b[1000];
	int c[1001],d[1001],h[1001]; 
    cout<<"请输入第一个数字"; 
    cin>>a;
    if(check(a)==0)
		return;
    cout<<"请输入第二个数字"; 
    cin>>b;
    if(check(b)==0)
		return;
    int alen,blen,i,f=0,l=0;
    alen=strlen(a);
    blen=strlen(b);   
    for(i=0;i<alen;i++) 
		c[i]=a[i]-'0';
    for(i=0;i<blen;i++) 
		d[i]=b[i]-'0';
	for(i=0;i<alen/2;i++) 
		swap(a[i],a[alen-1-i]);
    for(i=0;i<blen/2;i++) 
		swap(b[i],b[blen-1-i]);
    if(blen>alen)
    {
        for(i=0;i<blen;i++) swap(c[i],d[i]);
        f=1; 
    }
    if(alen>blen) swap(alen,blen); 
    for(i=0;i<blen;i++) 
		h[i]=c[i]-d[i];  
    for(i=0;i<blen;i++) 
    {
         if(h[i]<0)
         { 
             h[i]=10+h[i];
             h[i+1]--; 
         } 
   }    
   	cout<<"=";
    if(f==1) cout<<"-"; 
    for(i=blen-1;i>=0;i--)
   {    if(l==0) 
        {
            if(h[i]!=0) 
            {
                 l=1;
                 cout<<h[i];
                 continue;
            } 
        }
        if(l!=0)
        {
             cout<<h[i];
        }
    }
    cout<<endl<<endl; 
} 
void mul(){
	char a[1000],b[1000];	
	cout<<"请输入第一个数字"; 
	cin>>a;
	if(check(a)==0)
		return;
	cout<<"请输入第二个数字";
	cin>>b;
	if(check(b)==0)
		return;
	int c[1001],d[1001];
	int mul[2001];
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	memset(mul,0,sizeof(mul));
	int i,j=0;
	int alen=strlen(a);
	int blen=strlen(b);
	for (i=alen-1;i>=0;i--)
		c[j++]=a[i]-'0';
	j=0;
	for (i=blen-1;i>=0;i--)
		d[j++]=b[i]-'0';
	for (i=0;i<alen;i++)
		for (j=0;j<blen;j++)
			mul[i+j]+=c[i]*d[j];
 
	for (i=0;i<2001;i++)
		if (mul[i]>=10) 
		{
			int re=mul[i]/10;
			mul[i]%=10;
			mul[i+1]+=re;
		}
	bool f=false;
	cout<<"=";
	for (i=2000;i>=0;i--) 
	{
		if(mul[i]!=0)
		{
			f=true;
		}
		if(f)
		{
			cout<<mul[i];
		}
	}
	if (!f)
		cout<<"0";
		cout<<endl<<endl;
}
int Substract(int a[],int b[],int alen,int blen)
{
int i;
  if(alen<blen)return -1;
  if(alen==blen)for(i=alen-1;i>=0;i--)
  if(a[i]>b[i])break;
  else if(a[i]<b[i])
  return -1;
  for(i=0;i<alen;i++)
  {
      a[i]-=b[i];
      if(a[i]<0)
      {
          a[i]+=10;
          a[i+1]--;
      }
  }
  for(i=alen-1;i>=0;i--)
   if(a[i]>0)
   return i+1;
return 0;
 
}
void logarithm(){
	double a;
	cout<<"请输入数字"; 
	cin>>a;
	cout<<log(a)<<endl<<endl; 
}
void tangent(){
	double a;
	cout<<"请输入数字"; 
	cin>>a;
	cout<<tan(a)<<endl<<endl;
}
void sine(){
	double a;
	cout<<"请输入数字"; 
	cin>>a;
	cout<<sin(a)<<endl<<endl;
}
void cosine(){
	double a;
	cout<<"请输入数字"; 
	cin>>a;
	cout<<cos(a)<<endl<<endl;
}
void powerfunction(){
	float a,b;
	cout<<"请输入底数";
	cin>>a;
	cout<<"请输入幂";
	cin>>b;
	cout<<pow(a,b)<<endl<<endl;	 
}
void multiples_divisors(){
	int a,b;
	cout<<"请输入第一个数字";
	cin>>a;
	cout<<"请输入第二个数字";
	cin>>b; 
	if((a!=0)&&(b!=0))
	{
	int big=0; // 最大公约数; 
	int small=a*b; // 最小公倍数; 
	while(a!=b){
	if(a>b){a-=b;}else{b-=a;}
	}	 
	big=a;
	small=small/big;
	cout<<"最大公约数是："; 
	cout<<big<<endl;
	cout<<"最小公倍数是："; 
	cout<<small<<endl<<endl;
	}
}
void nextone(){
//	cout<<"继续选择需要的计算"<<endl; 
cout<<"          请选择需要的计算"<<endl<<endl;
//	cout<<"十六进制按a,八进制按b,十进制按c"<<endl<<endl;
	cout<<"   加法请按1"<<endl<<endl; 
	cout<<"   减法请按2"<<endl<<endl; 
	cout<<"   乘法请按3"<<endl<<endl; 
	cout<<"   除法请按4"<<endl<<endl;
	cout<<"   计算ln请按5"<<endl<<endl; 
	cout<<"   计算tan请按6"<<endl<<endl;
	cout<<"   计算sin请按7"<<endl<<endl;
	cout<<"   计算cos请按8"<<endl<<endl; 
	cout<<"   计算幂函数请按9"<<endl<<endl; 
	cout<<"   计算最大公约数和最小公倍数请按10"<<endl<<endl; 
	cout<<"   退出请按0"<<endl; 
} 
int main(){
	cout<<"--------------------------------------"<<endl;
	cout<<"|          欢迎使用整数计算器        |"<<endl;
	cout<<"--------------------------------------"<<endl;
	nextone();
	int choose;
	while(cin>>choose&&choose!=0){
		if(choose==1){
			add();
		//	nextone();	//实现加法 
		}
		else if(choose==2){
			sub();
		//	nextone();		//实现减法 
		}
		else if(choose==3){
			mul();		//实现乘法 
		//	nextone();
		}
		else if(choose==4){
			int i,e,j;		//实现除法 
    		char a[N+10],b[N+10];
   		    int num1[N+10],num2[N+10],num[N+10],alen,blen,n,flag,t;
    		cout<<"请输入第一个数字"; 
   			cin>>a;
   			if(check(a)==0){
   				cout<<"error\n";
   				continue;
			   }
			
   			cout<<"请输入第二个数字"; 
    		cin>>b;
			if(check(b)==0){
   				cout<<"error\n";
   				continue;
			   }
      	    memset(num1,0,sizeof(num1));
       	    memset(num,0,sizeof(num));
            memset(num2,0,sizeof(num2));
            alen=strlen(a);
            blen=strlen(b);     
            for(i=alen-1,e=0;i>=0;i--)
       			num1[e++]=a[i]-'0';
       		for(i=blen-1,e=0;i>=0;i--)
        		num2[e++]=b[i]-'0';
       		t=alen-blen;
      		if(t>0)
    	   {
            for(i=alen-1;i>=t;i--)
            	num2[i]=num2[i-t];
          	for(;i>=0;i--)
            	num2[i]=0;//将位数少的第二组数整体右移，在右边与第一组数字对 
            	blen=alen;
      		}
       		for(i=0;i<=t;i++)
      		{
            while((flag=(Substract(num1,num2+i,alen,blen-i)))>= 0)
            {
               alen=flag;
               num[t-i]++;
            }
            }
            cout<<"=";
     		for(i=N;i>=0&&num[i]==0;i--);
        	if(i==-1)
        		cout<<endl;
       		else
            {
				for(;i>=0;i--)
            	cout<<num[i];
            }
        	cout<<endl;
        //	nextone();
			}
				
			else if(choose==5){
				logarithm();
				//nextone();
			}
			
			else if(choose==6){
				tangent();
				//nextone();
			}
			else if(choose==7){
				sine();
				//nextone();
			}
			else if(choose==8){
				cosine();
				//nextone();
			}
			else if(choose==9){
				powerfunction();
				//nextone();
			}
			else if(choose==10){
				multiples_divisors();
				//nextone();
			}
			else if(choose==0){
			return 0;
		    }
	}
}

