#include<bits/stdc++.h> 
using namespace std;
char a[1000],b[1000];		//ȫ�ֱ��� 
int  check(char a[]){		//��������������������ж������ȷ����'0'~'9'
	int j=1;
	for(int i=0;i<strlen(a);i++){
		if(a[i]>='0'&&a[i]<='9'){			
		continue;
		}		
		else {		
			j=0;
		}					
	}
	if(j==0)cout<<"error"<<endl;//��������˲���'0'~'9'֮��ģ��ͱ��� 
	return j;
}
int change(string a){			//�ַ���ת����
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
void add(){						//�ӷ� 
	cout<<"�������һ������:	"; 	
	cin>>a; 
	if(check(a)==0){
		return;	
	}					
	cout<<"������ڶ�������:	";
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
			for(int j=blen;j<=alen;j++){	//λ�������� 
				d[j]=0;
			}
			c[alen]=0;
		}
		else if(alen<blen){
			for(int j=alen;j<=blen;j++){	//λ�������� 
			c[j]=0;
			}	
			d[blen]=0;		
		}
		else {
			c[alen]=0;
			d[blen]=0;
		}			
		maxlen=(alen>=blen)?alen:blen;	//ȡ������Ǹ� 
		for(int j=0;j<=maxlen;j++){
			c[j]+=d[j];					
			if(c[j]>=10){			//>=10�ͽ�λ 
				c[j]-=10;
				c[j+1]+=1;
			}	
		}	
		cout<<" = ";
		if(c[maxlen]==0){			//������Ǹ���û��Ҫ��λ�� 
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
	int c[1001]={0},d[1001]={0},e[1001]={0}; 		//e��������Ž�� 
    int alen,blen;
    alen=strlen(a);
    blen=strlen(b);
    cout<<" = ";
    if((alen<blen)||(alen==blen&&strcmp(a,b)<0)){	//�������Ƚ�Сʱ 
    	cout<<"-";
    	strcpy(tmp,a);
    	strcpy(a,b);
    	strcpy(b,tmp);
    	alen=strlen(a);
    	blen=strlen(b);  	
	}

	for(int i=0;i<alen;i++)
		c[i]=a[alen-i-1]-'0';		//������ 
	for(int i=0;i<blen;i++)
		d[i]=b[blen-i-1]-'0';

		
	for(int i=0;i<alen;i++){
		if(c[i]<d[i]){
			c[i+1]--;
			c[i]=c[i]+10;
		}
		e[i]=c[i]-d[i];
	}
	for(int i=alen-1;i>=0;i--){		//���� 
		if(e[i]==0&&alen>1)
			alen--;
		else break;
	}
	for(int i=alen-1;i>=0;i--){		//������� 
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
		if(mul[i]!=0){		//����� 
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
           i++;            //�̵�λ����0�Ǹ�λ��1��ʮλ���� 
           if(alen==blen)  
               break;  
           for(j=blen-1;j>=0;j--)  
               b[j+1]=b[j];  
			b[0]='0';  
            blen++;  
            b[blen]=='\0';//�����������һ��0 =����10 
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
	cout<<"����������:	"; 
	cin>>loga;
	for(int i=0;i<strlen(loga);i++){
		if(loga[i]<'0'||loga[i]>'9'){
			cout<<"error"<<endl;
			return; 
		}
	}
	double d=strtod(loga,NULL);//������԰�char ����ת����double 
	cout<<" = "; 
	cout<<log(d)<<endl<<endl; 
}
void tangent(){
	char tang[1000];
	cout<<"����������:	"; 
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
	cout<<"����������:	"; 
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
	cout<<"����������:	"; 
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
	cout<<"���������:	";
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
	cout<<"��������:	";
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
	cout<<"�������һ������:	";
	cin>>a1;
	a=change(a1);
	if(a==100){
		cout<<"error"<<endl;
		return;
	}
	cout<<"������ڶ�������:	";
	cin>>b1;
	b=change(b1);
	if(b==100){
		cout<<"error"<<endl;
		return;
	}
	if((a!=0)&&(b!=0))
	{
	int big=0; 		// ���Լ��; 
	int small=a*b; // ��С������; 
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
	cout<<"������b= ";
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
	cout<<"������b= "; 
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
	cout<<"������c= "; 
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
cout<<"          ��ѡ����Ҫ�ļ���"<<endl<<endl;
cout<<"   ����0���˳�"<<endl<<endl;
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
	 
} 
int main(){
	cout<<"--------------------------------------"<<endl;
	cout<<"|          ��ӭʹ������������        |"<<endl;
	cout<<"--------------------------------------"<<endl;
	nextone();
	string choose;	
	while(cin>>choose){
		int j=change(choose);		
		if(j==1){
			cout<<"��ѡ���˼ӷ�"<<endl;	
			add();
		}
		else if(j==2){
			cout<<"��ѡ���˼���"<<endl;
			sub();
		}
		else if(j==3){
			cout<<"��ѡ���˳˷�"<<endl;
			mul();	
		}
		else if(j==4){
			cout<<"��ѡ���˳���"<<endl;		
			div();
		}			
		else if(j==5){
			cout<<"��ѡ����ln����"<<endl;
			logarithm();
		}	
		else if(j==6){
			cout<<"��ѡ����tan����"<<endl;
			tangent();
		}
		else if(j==7){
			cout<<"��ѡ����sin����"<<endl;
			sine();
		}
		else if(j==8){
			cout<<"��ѡ����cos����"<<endl;
			cosine();
		}
		else if(j==9){
			cout<<"��ѡ�����ݺ�������"<<endl;
			powerfunction();
		}
		else if(j==10){
			cout<<"��ѡ�������Լ������С����������"<<endl; 
			multiples_divisors();
		}
		else if(j==11){
			cout<<"��ѡ����һԪһ�η��̼���"<<endl; 
			yiyuanyici();
		} 
		else if(j==12){
			cout<<"��ѡ����һԪ���η��̼���"<<endl; 
			yiyuanerci();
		} 
		else if(j==0){
			cout<<"��ӭ�´�ʹ��"<<endl; 
			return 0;
		}
		else{
			cout<<"error"<<endl; 
		}
		memset(a,'0',sizeof(a));
		memset(b,'0',sizeof(b));
		cout<<"�����ѡ������Ҫ�ļ���"<<endl<<endl; 
	}
}
