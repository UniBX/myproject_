#include<bits/stdc++.h> 
using namespace std;
char a[1000],b[1000];
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
void charin(){
	cout<<"请输入第一个数字:	"; 
	cin>>a; 
	if(check(a)==0){
		return;	
	}					
	cout<<"请输入第二个数字:	";
	cin>>b;
	if(check(b)==0)
		return;
}
void add(){
	int c[1001],d[1001];
	int alen,blen,maxlen;
	charin();
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
	
		cout<<a<<" + "<<b<<" = ";
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
	
	int c[1001],d[1001],h[1001]; 
    charin();

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
   	cout<<a<<" - "<<b<<" = ";
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
	charin();

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
	cout<<a<<" * "<<b<<"=";
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
void div(){
	int alen,blen;
    int s[1000] ={0};
    int i, j, k;  
	charin();
    alen=strlen(a);  
    blen= strlen(b); 
    char c[1000],d[1000];
    for(int n=0;n<strlen(a);n++) 
		c[n]=a[n];
    for(int n=0;n<strlen(b);n++) 
    	d[n]=b[n];
    if(alen<blen||alen==blen&&strncmp(a,b,blen)<0)  
    	cout<<"0";  
    else{
    	i=0;
		while(1){
			while(strncmp(a,b,blen)>=0){
				int m, n;  
  			 	for(m=0;a[m]=='0';m++);  
      				n=m;  
  			 	for(;m<blen;m++)  
      				a[m]-=b[m]-'0';  
  			 	for(m=blen-1;m>n;m--)  
      		 	if(a[m]<'0'){
      		 		a[m]+=10;  
         		 	a[m-1]--; 
			    } 
                s[i]++;		    
           }  
           i++;            //商的位数，0是个位，1是十位，以此类推  
           if(alen==blen)  
               break;  
           for(j=blen-1;j>=0;j--)  
               b[j+1]=b[j];  
			b[0]='0';  
            blen++;  
            b[blen]=='\0';//将减数最后添一个0，相当于乘以10 
		}  
       k=0;  
       while(1) {
       	if(s[k] == 0)  
            k++;  
        else  
            break;
	   }   
	   cout<<c<<" / "<<d<<" = ";
       for(;k<i;k++){
       	 cout<<s[k];  
	   }
	}       
}  
void logarithm(){
	double a;
	cout<<"请输入数字:	"; 
	cin>>a;
	cout<<"="; 
	cout<<log(a)<<endl<<endl; 
}
void tangent(){
	double a;
	cout<<"请输入数字:	"; 
	cin>>a;
	cout<<"=";
	cout<<tan(a)<<endl<<endl;
}
void sine(){
	double a;
	cout<<"请输入数字"; 
	cin>>a;
	cout<<"=";
	cout<<sin(a)<<endl<<endl;
}
void cosine(){
	double a;
	cout<<"请输入数字:	"; 
	cin>>a;
	cout<<"=";
	cout<<cos(a)<<endl<<endl;
}
void powerfunction(){
	float a,b;
	cout<<"请输入底数:	";
	cin>>a;
	cout<<"请输入幂:	";
	cin>>b;
	cout<<"=";
	cout<<pow(a,b)<<endl<<endl;	 
}
void multiples_divisors(){
	int a,b;
	cout<<"请输入第一个数字:	";
	cin>>a;
	cout<<"请输入第二个数字:	";
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
	cout<<"最大公约数是:	"; 
	
	cout<<big<<endl;
	cout<<"最小公倍数是:	"; 
	cout<<small<<endl<<endl;
	}
}
void yiyuanerci(){
	double a,b,c,d,x,y;
	cout<<"请为ax^2+bx+c=0输入系数a,b,c"<<endl;
	cin>>a>>b>>c;
	d=b*b-4*a*c;
	if(d>=0)
	{
		if(d>0)
	    {
		    x=((-b)+sqrt(d))/(2*a);
	        y=((-b)-sqrt(d))/(2*a);	  
	        cout<<"方程有两个实数根"<<"x="<<x<<" "<<"x="<<x<<endl;  
	    }
		else
		{
		     x=((-b)+sqrt(d))/(2*a);
		     cout<<"方程有一个实数根="<<x<<endl;
		}
    }
	else 
		cout<<"这个方程没有实数根"<<endl;
	
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
	cout<<"   计算一元二次方程请按11"<<endl<<endl; 
	cout<<"   退出请按0"<<endl; 
} 
int main(){
	cout<<"--------------------------------------"<<endl;
	cout<<"|          欢迎使用整数计算器        |"<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"请选择需要的进制"<<endl;
	cout<<"十六进制请按C"<<endl;
	char p;
	cin>>p;
	if(p=='C'){
		
	} 
	nextone();
	int choose;
	
	while(cin>>choose&&choose!=0){
		memset(a,'0',sizeof(a));
		memset(b,'0',sizeof(b));
		
		if(choose==1){
			add();
		}
		else if(choose==2){
			sub();
		}
		else if(choose==3){
			mul();	
		}
		else if(choose==4){
			div();
		}			
		else if(choose==5){
			logarithm();
		}	
		else if(choose==6){
			tangent();
		}
		else if(choose==7){
			sine();
		}
		else if(choose==8){
			cosine();
		}
		else if(choose==9){
			powerfunction();
		}
		else if(choose==10){
			multiples_divisors();
		}
		else if(choose==11){
			yiyuanerci();
		} 
		else if(choose==0){
		return 0;
		}
	}
}

