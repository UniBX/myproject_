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
		
			j=0;
		}					
	}
	if(j==0)cout<<"error"<<endl;
	return j;
}
void add(){
	cout<<"�������һ������:	"; 
	cin>>a; 
	if(check(a)==0){
		return;	
	}					
	cout<<"������ڶ�������:	";
	cin>>b;
	if(check(b)==0)
		return;
	int c[1001],d[1001];
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
	
		cout<<" = ";
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
cout<<"�������һ������:	"; 
	cin>>a; 
	if(check(a)==0){
		return;	
	}					
	cout<<"������ڶ�������:	";
	cin>>b;
	if(check(b)==0)
		return;
	if(strcmp(a,b)==0){
		cout<<" = 0"<<endl;
		return;
	}
	char tmp[1000];
	int c[1001],d[1001],e[1001]; 
    int alen,blen;
    alen=strlen(a);
    blen=strlen(b);
    cout<<" = ";
    if((alen<blen)||(alen==blen&&strcmp(a,b)<0)){
    	cout<<" -";
    	strcpy(tmp,a);
    	strcpy(a,b);
    	strcpy(b,tmp);
    	alen=strlen(a);
    	blen=strlen(b);
	}
	for(int i=0;i<alen;i++)
		c[i]=a[alen-i-1]-'0';
	for(int i=0;i<blen;i++)
		d[i]=b[blen-i-1]-'0';
	for(int i=0;i<alen;i++){
		if(c[i]<d[i]){
			c[i+1]--;
			c[i]=c[i]+10;
		}
		e[i]=c[i]-d[i];
	}
	for(int i=alen-1;i>=0;i--){
		if(e[i]==0&&alen>1)
			alen--;
		else break;
	}
	for(int i=alen-1;i>=0;i--){
		cout<<e[i];
	}
	cout<<endl<<endl;
    }
void mul(){
	cout<<"�������һ������:	"; 
	cin>>a; 
	if(check(a)==0){
		return;	
	}					
	cout<<"������ڶ�������:	";
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
	cout<<" = ";
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
	cout<<"�������һ������:	"; 
	cin>>a; 
	if(check(a)==0){
		return;	
	}					
	cout<<"������ڶ�������:	";
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
//>0	��һ����ƥ����ַ���str1�е�ֵ����str2�е�ֵ��
//0	���
//<0	��һ����ƥ����ַ���str1�е�ֵ����str2�е�ֵ��
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
           i++;            //�̵�λ����0�Ǹ�λ��1��ʮλ���Դ�����  
           if(alen==blen)  
               break;  
           for(j=blen-1;j>=0;j--)  
               b[j+1]=b[j];  
			b[0]='0';  
            blen++;  
            b[blen]=='\0';//�����������һ��0���൱�ڳ���10 
		}  
       k=0;  
       while(1) {
       	if(s[k] == 0)  
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
	cout<<"����������:	"; 
	cin>>loga;
	for(int i=0;i<strlen(loga);i++){
		if(loga[i]<'0'||loga[i]>'9'){
			cout<<"error"<<endl;
			return; 
		}
	}
	double d=strtod(loga,NULL);//������԰�char ����ת����double 
	cout<<"="; 
	cout<<log(d)<<endl<<endl; 
}
void tangent(){
	char tang[1000];
	cout<<"����������:	"; 
	cin>>tang;
	for(int i=0;i<strlen(tang);i++){
		if(tang[i]<'0'||tang[i]>'9'){
			cout<<"error"<<endl;
			return; 
		}
	}
	double d=strtod(tang,NULL);;
	
	cout<<"=";
	cout<<tan(d)<<endl<<endl;
}
void sine(){
	char sin_[1000];	
	cout<<"����������:	"; 
	cin>>sin_;
	for(int i=0;i<strlen(sin_);i++){
		if(sin_[i]<'0'||sin_[i]>'9'){
			cout<<"error"<<endl;
			return; 
		}
	}
	double d=strtod(sin_,NULL);
	cout<<"=";
	cout<<sin(d)<<endl<<endl;
}
void cosine(){
	char cosi[1000];	
	cout<<"����������:	"; 
	cin>>cosi;
	for(int i=0;i<strlen(cosi);i++){
		if(cosi[i]<'0'||cosi[i]>'9'){
			cout<<"error"<<endl;
			return; 
		}
	}
	double d=strtod(cosi,NULL);
	cout<<"=";
	cout<<cos(d)<<endl<<endl;
}
void powerfunction(){
	char dishu[1000],mi[1000];
	int j=1;
	cout<<"���������:	";
	cin>>dishu;
	for(int i=0;i<strlen(dishu);i++){
		if(dishu[i]<'0'||dishu[i]>'9'){
			j=0;
		}
	}
	if(j==0){
		cout<<"error"<<endl;
		return;
	}
	cout<<"��������:	";
	cin>>mi;
	
	
	for(int i=0;i<strlen(mi);i++){
		if(mi[i]<'0'||mi[i]>'9'){
			j=0; 
		}
	}
	if(j==0){
		cout<<"error"<<endl;
		return;}
	float a=strtod(dishu,NULL);
	float b=strtod(mi,NULL);
	cout<<"=";
	cout<<pow(a,b)<<endl<<endl;	 
}
void multiples_divisors(){
	int a,b;
	cout<<"�������һ������:	";
	cin>>a;
	
	cout<<"������ڶ�������:	";
	cin>>b; 
	if((a!=0)&&(b!=0))
	{
	int big=0; // ���Լ��; 
	int small=a*b; // ��С������; 
	while(a!=b){
	if(a>b){a-=b;}else{b-=a;}
	}	 
	big=a;
	small=small/big;
	cout<<"���Լ����:	"; 
	
	cout<<big<<endl;
	cout<<"��С��������:	"; 
	cout<<small<<endl<<endl;
	}
}
void yiyuanyici(){
	char m[1000],n[1000];
	int j=1;
	cout<<"��Ϊax+b=0����ϵ��a,b"<<endl;
	cout<<"������a= ";
	cin>>m;
	for(int i=0;i<strlen(m);i++){
		if(m[i]<'0'||m[i]>'9'){
			j=0;
		}
	}
	if(j==0){
		cout<<"error"<<endl;
		return;
	}
	double m1=strtod(m,NULL);
	cout<<"������b= ";
	cin>>n;
	for(int i=0;i<strlen(n);i++){
		if(n[i]<'0'||n[i]>'9'){
			j=0;
		}
	}
	if(j==0){
		cout<<"error"<<endl;
		return;
	}
	double n1=strtod(n,NULL);
	double d=(-n1)/m1;
	if((m1==0&&n1!=0)||(m1==0&&n1==0))cout<<"�������û�и�"<<endl;
	else 
		cout<<"��������и�Ϊ�� x= "<<d<<endl;
	
}
void yiyuanerci(){
	char c[1000];
	double d,x,y;
	int j=1;
	cout<<"��Ϊax^2+bx+c=0����ϵ��a,b,c"<<endl;
	cout<<"������a= "; 
	cin>>a;
	for(int i=0;i<strlen(a);i++){
		if(a[i]<'0'||a[i]>'9'){
			j=0;
		}
	}
	if(j==0){
		cout<<"error"<<endl;
		return;
	}
	cout<<"������b= "; 
	cin>>b;
	for(int i=0;i<strlen(b);i++){
		if(b[i]<'0'||b[i]>'9'){
			j=0;
		}
	}
	if(j==0){
		cout<<"error"<<endl;
		return;
	}
	cout<<"������c= "; 
	cin>>c;
	for(int i=0;i<strlen(c);i++){
		if(c[i]<'0'||c[i]>'9'){
			j=0;
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
		cout<<"�������û��ʵ����"<<endl;
		return;
	}
	if(a1==0){
		d=(-c1)/b1;
		cout<<"������һ��ʵ���� x= "<<d<<endl;
		return;
	}	
	d=b1*b1-4*a1*c1;
	if(d>=0)
	{
		if(d>0)
	    {
		    x=((-b1)+sqrt(d))/(2*a1);
	        y=((-b1)-sqrt(d))/(2*a1);	  
	        cout<<"����������ʵ����"<<"x= "<<x<<" "<<"x= "<<y<<endl;  
	    }
		else
		{
		     x=((-b1)+sqrt(d))/(2*a1);
		     cout<<"������һ��ʵ���� x= "<<x<<endl;
		}
    }
	else 
		cout<<"�������û��ʵ����"<<endl;
	
}
void nextone(){
//	cout<<"����ѡ����Ҫ�ļ���"<<endl; 
cout<<"          ��ѡ����Ҫ�ļ���"<<endl<<endl;
//	cout<<"ʮ�����ư�a,�˽��ư�b,ʮ���ư�c"<<endl<<endl;
	cout<<"   �ӷ��밴1"<<endl<<endl; 
	cout<<"   �����밴2"<<endl<<endl; 
	cout<<"   �˷��밴3"<<endl<<endl; 
	cout<<"   �����밴4"<<endl<<endl;
	cout<<"   ����ln�밴5"<<endl<<endl; 
	cout<<"   ����tan�밴6"<<endl<<endl;
	cout<<"   ����sin�밴7"<<endl<<endl;
	cout<<"   ����cos�밴8"<<endl<<endl; 
	cout<<"   �����ݺ����밴9"<<endl<<endl; 
	cout<<"   �������Լ������С�������밴10"<<endl<<endl; 
	cout<<"   ����һԪһ�η����밴11"<<endl<<endl; 
	cout<<"   ����һԪ���η����밴12"<<endl<<endl; 
	cout<<"   �˳��밴0"<<endl; 
} 
int main(){
	cout<<"--------------------------------------"<<endl;
	cout<<"|          ��ӭʹ������������        |"<<endl;
	cout<<"--------------------------------------"<<endl;
	nextone();
	int choose;	
	while(cin>>choose&&choose!=0){
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
			yiyuanyici();
		} 
		else if(choose==12){
			yiyuanerci();
		} 
		else if(choose==0){
			exit(0); 
		}
		else {
			cout<<"�޴�ѡ��"; 
			exit(0);
		}
		memset(a,'0',sizeof(a));
		memset(b,'0',sizeof(b));
		cout<<"�����ѡ������Ҫ�ļ���"<<endl; 
	}
}

