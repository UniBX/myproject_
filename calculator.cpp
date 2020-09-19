#include<bits/stdc++.h> 
using namespace std;
char a[1000],b[1000];		//全局变量 
int  check(char a[]){		//这个函数的作用是我来判断输入的确保在'0'~'9'
	int j=1;
	for(int i=0;i<strlen(a);i++){
		if(a[i]>='0'&&a[i]<='9'){			
		continue;
		}		
		else {		
			j=0;
		}					
	}
	if(j==0)cout<<"error"<<endl;//如果出现了不是'0'~'9'之间的，就报错 
	return j;
}
int change(string a){			//字符串转成数
	int len=a.size();
	int ans=0;
	for(int i=0;i<len;i++){
		if(a[i]>'9'||a[i]<'0'){
			return 100;
		}
		ans*=10;
		ans+=a[i]-'0';
	}
	return ans;
}
void add(){						//加法 
	cout<<"请输入第一个数字:	"; 	
	cin>>a; 
	if(check(a)==0){
		return;	
	}					
	cout<<"请输入第二个数字:	";
	cin>>b;
	if(check(b)==0)
		return;
	int c[1000]={0},d[1000]={0};	//char []->int [] 
	int alen,blen,maxlen;	
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
			for(int j=blen;j<=alen;j++){	//位数补齐了 
				d[j]=0;
			}
			c[alen]=0;
		}
		else if(alen<blen){
			for(int j=alen;j<=blen;j++){	//位数补齐了 
			c[j]=0;
			}	
			d[blen]=0;		
		}
		else {
			c[alen]=0;
			d[blen]=0;
		}			
		maxlen=(alen>=blen)?alen:blen;	//取出大的那个 
		for(int j=0;j<=maxlen;j++){
			c[j]+=d[j];					
			if(c[j]>=10){			//>=10就进位 
				c[j]-=10;
				c[j+1]+=1;
			}	
		}	
		cout<<" = ";
		if(c[maxlen]==0){			//看最后那个有没有要进位的 
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
	cout<<"请输入第一个数字:	"; 
	cin>>a; 
	if(check(a)==0){
		return;	
	}					
	cout<<"请输入第二个数字:	";
	cin>>b;
	if(check(b)==0)
		return;
	if(strcmp(a,b)==0){
		cout<<" = 0"<<endl;
		return;
	}
	char tmp[1000];
	int c[1001]={0},d[1001]={0},e[1001]={0}; 		//e数组来存放结果 
    int alen,blen;
    alen=strlen(a);
    blen=strlen(b);
    cout<<" = ";
    if((alen<blen)||(alen==blen&&strcmp(a,b)<0)){	//被减数比较小时 
    	cout<<"-";
    	strcpy(tmp,a);
    	strcpy(a,b);
    	strcpy(b,tmp);
    	alen=strlen(a);
    	blen=strlen(b);  	
	}

	for(int i=0;i<alen;i++)
		c[i]=a[alen-i-1]-'0';		//倒着来 
	for(int i=0;i<blen;i++)
		d[i]=b[blen-i-1]-'0';

		
	for(int i=0;i<alen;i++){
		if(c[i]<d[i]){
			c[i+1]--;
			c[i]=c[i]+10;
		}
		e[i]=c[i]-d[i];
	}
	for(int i=alen-1;i>=0;i--){		//消零 
		if(e[i]==0&&alen>1)
			alen--;
		else break;
	}
	for(int i=alen-1;i>=0;i--){		//倒着输出 
		cout<<e[i];
	}
	cout<<endl<<endl;	
    }
void mul(){
	cout<<"请输入第一个数字:	"; 
	cin>>a; 
	if(check(a)==0){
		return;	
	}					
	cout<<"请输入第二个数字:	";
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
	for(i=alen-1;i>=0;i--)
		c[j++]=a[i]-'0';
		j=0;
	for(i=blen-1;i>=0;i--)
		d[j++]=b[i]-'0';
	for(i=0;i<alen;i++)
		for(j=0;j<blen;j++)
			mul[i+j]+=c[i]*d[j];
	for(i=0;i<2001;i++)
		if(mul[i]>=10){ 		
			int re=mul[i]/10;
			mul[i]%=10;
			mul[i+1]+=re;
		}
	bool f=false;
	cout<<" = ";
	for (i=2000;i>=0;i--){ 	
		if(mul[i]!=0){		//清除零 
			f=true;
		}
		if(f){		
			cout<<mul[i];
		}
	}
	if (!f)
		cout<<"0";
		cout<<endl<<endl;
}
void div(){
	cout<<"请输入第一个数字:	"; 
	cin>>a; 
	if(check(a)==0){
		return;	
	}					
	cout<<"请输入第二个数字:	";
	cin>>b;
	if(check(b)==0)
		return;
	if(a[0]=='0'){
		cout<<" = 0"<<endl;
		return;
	}
	int alen,blen;
    int s[1000] ={0};
    int i, j, k;  
    alen=strlen(a);  
    blen= strlen(b); 
    char c[1000],d[1000];
    for(int n=0;n<strlen(a);n++) 
		c[n]=a[n];
    for(int n=0;n<strlen(b);n++) 
    	d[n]=b[n];
    if(alen<blen||alen==blen&&strncmp(a,b,blen)<0)  
//>0	第一个不匹配的字符在str1中的值比在str2中的值高
//0	相等
//<0	第一个不匹配的字符在str1中的值比在str2中的值低
    	cout<<"0";  
    else{
    	i=0;
		while(1){
			while(strncmp(a,b,blen)>=0){
				int m,n;  
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
           i++;            //商的位数，0是个位，1是十位…… 
           if(alen==blen)  
               break;  
           for(j=blen-1;j>=0;j--)  
               b[j+1]=b[j];  
			b[0]='0';  
            blen++;  
            b[blen]=='\0';//将减数最后添一个0 =乘以10 
		}  
       k=0;  
       while(1){
       	if(s[k]==0)  
            k++;  
        else  
            break;
	   }   
	   cout<<" = ";
       for(;k<i;k++){
       	 cout<<s[k];  
	   }
	}   
	cout<<endl;    
}  
void logarithm(){
	char loga[1000];	
	cout<<"请输入数字:	"; 
	cin>>loga;
	for(int i=0;i<strlen(loga);i++){
		if(loga[i]<'0'||loga[i]>'9'){
			cout<<"error"<<endl;
			return; 
		}
	}
	double d=strtod(loga,NULL);//这个可以把char 型数转换成double 
	cout<<" = "; 
	cout<<log(d)<<endl<<endl; 
}
void tangent(){
	char tang[1000];
	cout<<"请输入数字:	"; 
	cin>>tang;
	int j=1;
	if(tang[0]=='-'){
		for(int i=1;i<strlen(tang);i++){
			if(tang[i]<'0'||tang[i]>'9'){
				j=0;
			}
		}
	}
	
	else{
		for(int i=0;i<strlen(tang);i++){
			if(tang[i]<'0'||tang[i]>'9'){
				j=0;
			}
		}
	}
	if(j==0){
		cout<<"error"<<endl;
		return;
	}
	double d=strtod(tang,NULL);;	
	cout<<" = ";
	cout<<tan(d)<<endl<<endl;
}
void sine(){
	char sin_[1000];	
	cout<<"请输入数字:	"; 
	cin>>sin_;
	int j=1;
	if(sin_[0]=='-'){
		for(int i=1;i<strlen(sin_);i++){
			if(sin_[i]<'0'||sin_[i]>'9'){
				j=0;
			}
		}
	}
	
	else{
		for(int i=0;i<strlen(sin_);i++){
			if(sin_[i]<'0'||sin_[i]>'9'){
				j=0;
			}
		}
	}
	if(j==0){
		cout<<"error"<<endl;
		return;
	}
	double d=strtod(sin_,NULL);
	cout<<" = ";
	cout<<sin(d)<<endl<<endl;
}
void cosine(){
	char cosi[1000];	
	cout<<"请输入数字:	"; 
	cin>>cosi;
	int j=1;
	if(cosi[0]=='-'){
		for(int i=1;i<strlen(cosi);i++){
			if(cosi[i]<'0'||cosi[i]>'9'){
				j=0;
			}
		}
	}
	
	else{
		for(int i=0;i<strlen(cosi);i++){
			if(cosi[i]<'0'||cosi[i]>'9'){
				j=0;
			}
		}
	}
	if(j==0){
		cout<<"error"<<endl;
		return;
	}
	double d=strtod(cosi,NULL);
	cout<<" = ";
	cout<<cos(d)<<endl<<endl;
}
void powerfunction(){
	char dishu[1000],mi[1000];
	cout<<"请输入底数:	";
	cin>>dishu;
	int j=1;
	if(dishu[0]=='-'){
		for(int i=1;i<strlen(dishu);i++){
			if(dishu[i]<'0'||dishu[i]>'9'){
				j=0;
			}
		}
	}
	
	else{
		for(int i=0;i<strlen(dishu);i++){
			if(dishu[i]<'0'||dishu[i]>'9'){
				j=0;
			}
		}
	}
	if(j==0){
		cout<<"error"<<endl;
		return;
	}
	cout<<"请输入幂:	";
	cin>>mi;	
	if(mi[0]=='-'){
		for(int i=1;i<strlen(mi);i++){
			if(mi[i]<'0'||mi[i]>'9'){
				j=0;
			}
		}
	}
	
	else{
		for(int i=0;i<strlen(mi);i++){
			if(mi[i]<'0'||mi[i]>'9'){
				j=0;
			}
		}
	}
	if(j==0){
		cout<<"error"<<endl;
		return;
	}
	float a=strtod(dishu,NULL);
	float b=strtod(mi,NULL);
	cout<<" = ";
	cout<<pow(a,b)<<endl<<endl;	 
}
void multiples_divisors(){
	int j=1;
	int a,b;
	string a1,b1;
	cout<<"请输入第一个数字:	";
	cin>>a1;
	a=change(a1);
	if(a==100){
		cout<<"error"<<endl;
		return;
	}
	cout<<"请输入第二个数字:	";
	cin>>b1;
	b=change(b1);
	if(b==100){
		cout<<"error"<<endl;
		return;
	}
	if((a!=0)&&(b!=0))
	{
	int big=0; 		// 最大公约数; 
	int small=a*b; // 最小公倍数; 
	while(a!=b){
		if(a>b){
		a-=b;
		}
		else{
		b-=a;
		}
	}	 
	big=a;
	small=small/big;
	cout<<"最大公约数是:	"; 	
	cout<<big<<endl;
	cout<<"最小公倍数是:	"; 
	cout<<small<<endl<<endl;
	}
}
void yiyuanyici(){
	char m[1000],n[1000];
	int j=1;
	cout<<"请为ax+b=0输入系数a,b"<<endl;
	cout<<"请输入a= ";
	cin>>m;
	if(m[0]=='-'){
		for(int i=1;i<strlen(m);i++){
			if(m[i]<'0'||m[i]>'9'){
				j=0;
			}
		}
	}
	else{
		for(int i=0;i<strlen(m);i++){
			if(m[i]<'0'||m[i]>'9'){
				j=0;
			}
		}
	}
	if(j==0){
		cout<<"error"<<endl;
		return;
	}
	double m1=strtod(m,NULL);
	cout<<"请输入b= ";
	cin>>n;
	if(n[0]=='-'){
		for(int i=1;i<strlen(n);i++){
			if(n[i]<'0'||n[i]>'9'){
				j=0;
			}
		}
	}
	else{
		for(int i=0;i<strlen(n);i++){
			if(n[i]<'0'||n[i]>'9'){
				j=0;
			}
		}
	}
	if(j==0){
		cout<<"error"<<endl;
		return;
	}
	double n1=strtod(n,NULL);
	double d=(-n1)/m1;
	if((m1==0&&n1!=0)||(m1==0&&n1==0))cout<<"这个方程没有根"<<endl;
	else 
		cout<<"这个方程有根为： x= "<<d<<endl;
	
}
void yiyuanerci(){
char c[1000];
	double d,x,y;
	int j=1;
	cout<<"请为ax^2+bx+c=0输入系数a,b,c"<<endl;
	cout<<"请输入a= "; 
	cin>>a;
	if(a[0]=='-'){
		for(int i=1;i<strlen(a);i++){
			if(a[i]<'0'||a[i]>'9'){
				j=0;
			}
		}
	}
	else{
		for(int i=0;i<strlen(a);i++){
			if(a[i]<'0'||a[i]>'9'){
				j=0;
			}
		}
	}
	if(j==0){
		cout<<"error"<<endl;
		return;
	}
	cout<<"请输入b= "; 
	cin>>b;
	if(b[0]=='-'){
		for(int i=1;i<strlen(b);i++){
			if(b[i]<'0'||b[i]>'9'){
				j=0;
			}
		}
	}
	else{
		for(int i=0;i<strlen(b);i++){
			if(b[i]<'0'||b[i]>'9'){
				j=0;
			}
		}
	}
	if(j==0){
		cout<<"error"<<endl;
		return;
	}
	cout<<"请输入c= "; 
	cin>>c;
	if(c[0]=='-'){
		for(int i=1;i<strlen(c);i++){
			if(c[i]<'0'||c[i]>'9'){
				j=0;
			}
		}
	}
	else{
		for(int i=0;i<strlen(c);i++){
			if(c[i]<'0'||c[i]>'9'){
				j=0;
			}
		}
	}
	if(j==0){
		cout<<"error"<<endl;
		return;
	}
	double a1=strtod(a,NULL);
	double b1=strtod(b,NULL);
	double c1=strtod(c,NULL);
	if((a1==0&&b1==0&&c1==0)||(a1==0&&b1==0&&c1!=0)){
		cout<<"这个方程没有实数根"<<endl;
		return;
	}
	if(a1==0){
		d=(-c1)/b1;
		cout<<"方程有一个实数根 x= "<<d<<endl;
		return;
	}	
	d=b1*b1-4*a1*c1;
	if(d>=0)
	{
		if(d>0)
	    {
		    x=((-b1)+sqrt(d))/(2*a1);
	        y=((-b1)-sqrt(d))/(2*a1);	  
	        cout<<"方程有两个实数根"<<"x= "<<x<<" "<<"x= "<<y<<endl;  
	    }
		else
		{
		     x=((-b1)+sqrt(d))/(2*a1);
		     cout<<"方程有一个实数根 x= "<<x<<endl;
		}
    }
	else 
		cout<<"这个方程没有实数根"<<endl;
		
}
void nextone(){
cout<<"          请选择需要的计算"<<endl<<endl;
cout<<"   输入0将退出"<<endl<<endl;
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
	cout<<"   计算一元一次方程请按11"<<endl<<endl; 
	cout<<"   计算一元二次方程请按12"<<endl<<endl; 
	 
} 
int main(){
	cout<<"--------------------------------------"<<endl;
	cout<<"|          欢迎使用整数计算器        |"<<endl;
	cout<<"--------------------------------------"<<endl;
	nextone();
	string choose;	
	while(cin>>choose){
		int j=change(choose);		
		if(j==1){
			cout<<"你选择了加法"<<endl;	
			add();
		}
		else if(j==2){
			cout<<"你选择了减法"<<endl;
			sub();
		}
		else if(j==3){
			cout<<"你选择了乘法"<<endl;
			mul();	
		}
		else if(j==4){
			cout<<"你选择了除法"<<endl;		
			div();
		}			
		else if(j==5){
			cout<<"你选择了ln计算"<<endl;
			logarithm();
		}	
		else if(j==6){
			cout<<"你选择了tan计算"<<endl;
			tangent();
		}
		else if(j==7){
			cout<<"你选择了sin计算"<<endl;
			sine();
		}
		else if(j==8){
			cout<<"你选择了cos计算"<<endl;
			cosine();
		}
		else if(j==9){
			cout<<"你选择了幂函数计算"<<endl;
			powerfunction();
		}
		else if(j==10){
			cout<<"你选择了最大公约数和最小公倍数计算"<<endl; 
			multiples_divisors();
		}
		else if(j==11){
			cout<<"你选择了一元一次方程计算"<<endl; 
			yiyuanyici();
		} 
		else if(j==12){
			cout<<"你选择了一元二次方程计算"<<endl; 
			yiyuanerci();
		} 
		else if(j==0){
			cout<<"欢迎下次使用"<<endl; 
			return 0;
		}
		else{
			cout<<"error"<<endl; 
		}
		memset(a,'0',sizeof(a));
		memset(b,'0',sizeof(b));
		cout<<"请继续选择你需要的计算"<<endl<<endl; 
	}
}
