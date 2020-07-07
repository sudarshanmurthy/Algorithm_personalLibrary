#include<string.h>
#include<stdlib.h>
#include<stdio.h>


static char** create_array(int a){
    char **p=malloc(sizeof(char *)*a);
    return p;
}

static int bigger(const char *a,const char *b){
for(int i=0;i<strlen(b);i++){
if(b[i]>a[i]){return 0;}
else if(a[i]>b[i]){return 1;}
}
return 1;}


static int same(const char *a,const char *b){
    if(strlen(a)!=strlen(b)){return 0;}
    int v=strlen(b);
    for(int i=0;i<v;i++){
        if(a[i]!=b[i]){
            return 0;
        }
    }
    return 1;
}

static char *copy(const char *a){
    int b=strlen(a);
    char *p=malloc(sizeof(char)*(b+1));
    for(int i=0;i<=b;i++){
        p[i]=a[i];
    }
    return p;
}


static void reverseStr(char *a) 
{ 
    int n = strlen(a); 
    for (int i = 0; i < n / 2; i++) {
        char b=a[i];
	a[i]=a[n-i-1];
	a[n-i-1]=b;
} 
} 

static char* ctostr(int unsigned n){
char *res;
int c=0;
int m=n;
while(m){
c++;
m/=10;}
res=malloc(sizeof(char)*(c+1));
res[c--]='\0';
while(n){
res[c--]=48+n%10;
n/=10;}
return res;}

int intal_compare(const char* intal1, const char* intal2){
if(strlen(intal1)>strlen(intal2)){
return 1;}
else if(strlen(intal1)<strlen(intal2)){
return -1;}
else{
for(int i=0;i<strlen(intal1);i++){
if(intal1[i]>intal2[i]){return 1;}
else if(intal1[i]<intal2[i]){return -1;}
}
return 0;
}
}

char* intal_diff(const char* intal1, const char* intal2){
char *intal11=copy(intal1);
char *intal22=copy(intal2);
int com=intal_compare(intal22,intal11);
if(com==0){
char *res=malloc(sizeof(char)*2);
res[0]=48;
res[1]='\0';
return res;}
if(com==1){
char *l=intal11;
intal11=intal22;
intal22=l;}
int a=strlen(intal11);
int b=strlen(intal22);
char *res;

int n=a>b?a:b;

int min=(n==a)?b:a;
res=(char *)malloc(sizeof(char)*(n+2));
reverseStr(intal11);
reverseStr(intal22);
int carry=0;
int m=0;
for (int i=0; i<min; i++) 
    { 
        int sum = (intal11[i]-'0')-(intal22[i]-'0')-carry;
	if(sum<0){
		sum+=10; 
		carry=1;}
	    
	else{
		carry=0;}
		res[m++]=48+sum;
    } 
  
    for (int i=min; i<n; i++) 
    { 
     int sum = (intal11[i]-'0')-carry;
	if(sum<0){
		sum+=10; 
		carry=1;}
	else{
		carry=0;}
        res[m++]=48+sum;  
    }
m--;
while(res[m]==48){
m--;}
m++;
res[m]='\0';
  
    reverseStr(res);
free(intal11);
free(intal22);
    
    return res; 
}


char* intal_mod(const char *a,const char *b){
if(intal_compare(a,b)==-1){char *l=copy(a);return l;}
int diffbits=strlen(a)-strlen(b);
int remobit=(bigger(a,b)==1)?0:1;
diffbits-=remobit;
if(diffbits>0){
char *extended=malloc(sizeof(char)*(strlen(b)+diffbits+1));
for(int i=0;i<strlen(b);i++){
extended[i]=b[i];}
int m=strlen(b);
for(int i=0;i<diffbits;i++){
extended[i+m]=48;}
extended[diffbits+m]='\0';
extended=intal_diff(a,extended);
return intal_mod(extended,b);}
return intal_mod(intal_diff(a,b),b);
}


char* intal_multiply(const char* intal1, const char* intal2){
if(intal1[0]==48||intal2[0]==48){
char *res=(char*)malloc(sizeof(char)*2);
res[0]=48;
res[1]='\0';
return res;}
int a=strlen(intal1);
int b=strlen(intal2);
    char *result = malloc(sizeof(char)*(a+b+2));  
    int i_n1 = 0;  
    int i_n2 = 0;  
    int i;
    for(int i=0;i<a+b+2;i++){
		result[i]=48;}
    for (i = a - 1; i >= 0; i--)  
    {  
        int carry = 0;  
        int n1 = intal1[i] - '0';
        i_n2 = 0;            
        for (int j = b - 1; j >= 0; j--)  
        {  
            int n2 = intal2[j] - '0';  
  
            int sum = n1 * n2 + (result[i_n1 + i_n2]-'0') + carry;  
            carry = sum / 10;  
            result[i_n1 + i_n2] = 48+(sum % 10);  
  
            i_n2++;  
        }  
  
        if (carry > 0)  
            result[i_n1 + i_n2] = 48+result[i_n1+i_n2]-'0'+carry;  
  
        i_n1++;  
    }
int v=i_n1+i_n2;
v--;
while(result[v]==48){
v--;}

    result[v+1]='\0';
     
  reverseStr(result);
    return result;}








char* intal_add(const char* intal1, const char* intal2){
char *intal11=copy(intal1);
char *intal22=copy(intal2);
int a=strlen(intal11);
int b=strlen(intal22);
char *res;
int n=a>b?a:b;
if(intal_compare(intal22,intal11)==1){
char *l=intal11;
intal11=intal22;
intal22=l;}
int min=(n==a)?b:a;
res=(char *)malloc(sizeof(char)*(n+2));
reverseStr(intal11);
reverseStr(intal22);
int carry=0;
int m=0;
for (int i=0; i<min; i++) 
    { 
        int sum = (intal11[i]-'0')+(intal22[i]-'0')+carry; 
        res[m++]=48+sum%10;
        carry = sum/10; 
    } 
  
    for (int i=min; i<n; i++) 
    { 
     int sum = (intal11[i]-'0')+carry; 
        res[m++]=48+sum%10;
        carry = sum/10;  
    } 
  
 
    if (carry){ 
        res[m++]=48+carry;} 
res[m]='\0';
  
    reverseStr(res);
free(intal11);
free(intal22);
    return res; 
}

char* intal_fibonacci(unsigned int n){
if(n==0||n==1){
char *v=malloc(sizeof(char)*2);
v[1]='\0';
if(n==1){v[0]=48;return v;}
if(n==2){v[0]=49;return v;}
}
char *res;
char *first;
char *second;
first=malloc(sizeof(char)*2);
second=malloc(sizeof(char)*2);
first[0]=48;
second[0]=49;
first[1]='\0';
second[1]='\0';
while(n-1){
res=intal_add(first,second);
first=second;
second=res;
n--;}
return res;}

char* intal_factorial(unsigned int n){
if(n==1||n==0){
char *v=malloc(sizeof(char)*2);
v[1]='\0';
v[0]=49;
return v;}
return intal_multiply(ctostr(n),intal_factorial(n-1));
}

char* intal_bincoeff(unsigned int n, unsigned int k)
{	
    char** dp=malloc(sizeof(char* ) * (k+1));
    for(int i=0;i<=k;++i)
    	dp[i]="0";
    dp[0]="1";
    for(int i=1;i<=n;++i)
    {
		int range=i>k?k:i;
    	for(int j=range;j>0;--j)
    	{ 
			dp[j]=intal_add(dp[j],dp[j-1]);
        }
	}
    char *result=malloc(sizeof(char)*strlen(dp[k]));
    strcpy(result,dp[k]);
	for(int i=1;i<k+1;i++){
		free(dp[i]);}
	free(dp);
    return result;
}

char * intal_pow(const char *intal1,unsigned int n)
{ 
    if (n == 0){ 
               char *v=malloc(sizeof(char)*2);
v[1]='\0';
v[0]=49;
return v;} 
    else if (n%2 == 0){ 
        return intal_multiply(intal_pow(intal1, n/2),intal_pow(intal1, n/2));} 
    else{
        return intal_multiply(intal1,intal_multiply(intal_pow(intal1, n/2),intal_pow(intal1, n/2)));} 
} 






char* intal_gcd(const char *intal1, const char *intal2){
if(intal1[0]==48 && intal2[0]==48){char *res=malloc(sizeof(char)*2);
res[1]='\0';
res[0]=48;
return res;}

if(intal2[0]==48){ char *res=copy(intal1);return res;}

else{ return intal_gcd(intal2,intal_mod(intal1,intal2));}

}
int intal_max(char **arr, int n){
    char *res=arr[0];
    int index=0;
    for(int i=1;i<n;i++){
        if(intal_compare(arr[i],res)==1){
            index=i;
            res=arr[i];
        }
    }
    return index;
}
int intal_min(char **arr, int n){
    char *res=arr[0];
    int index=0;
    for(int i=1;i<n;i++){
        if(intal_compare(arr[i],res)==-1){
            index=i;
            res=arr[i];
        }
    }
    return index;
}

int intal_search(char **arr, int n, char* key){
    int ans=-1;
    for(int i=0;i<n;i++){
        if(same(arr[i],key)==1){
            ans=i;
            return ans;
        }
    }

    return ans;
}

static int intal_binsearch1(char **arr, int l, int r, char *key) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        
        if (intal_compare(arr[mid],key)==0){ 
            return mid; }
  
        if (intal_compare(arr[mid],key)==1){ 
            return intal_binsearch1(arr, l, mid - 1, key);} 
  
        return intal_binsearch1(arr, mid + 1, r, key); 
    } 
  
    return -1; 
} 
int intal_binsearch(char **arr, int n, char* key){
    return intal_binsearch1(arr,0,n-1,key);
}

static void merge(char** arr, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    char** L=create_array(n1);
    char** R=create_array(n2); 
    for (i = 0; i < n1; i++){
        L[i] = copy(arr[l + i]);} 
    for (j = 0; j < n2; j++){
        R[j] = copy(arr[m + 1+ j]);} 
  
    i = 0;  
    j = 0; 
    k = l;  
    while (i < n1 && j < n2) 
    { 
        if (intal_compare(L[i],R[j])<=0) 
        { 
            arr[k] = copy(L[i]); 
            i++; 
        } 
        else
        { 
            arr[k] = copy(R[j]); 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = copy(L[i]); 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = copy(R[j]); 
        j++; 
        k++; 
    } 
for(int i=0;i<n1;i++){
free(L[i]);}
for(int i=0;i<n2;i++){
free(R[i]);}
free(L);
free(R);
	
}







static void mergeSort(char** arr, int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 

} 

void intal_sort(char **a, int n){

    mergeSort(a,0,n-1);
}

static char* max(const char *a,const char *b){
char *l=copy(a);
char *m=copy(b);
    if(intal_compare(l,m)==1){
        return l;
    }
    else{
        return m;
    }
}

static char* coin_row(char** arr,int index,int n)
{
    if (index==n)
        return "0";
    if (index==n-1)
        return arr[index];
    if (index==n-2)
        return max(arr[index],arr[index+1]);
    return max(intal_add(arr[index],coin_row(arr,index+2,n)),coin_row(arr,index+1,n));
}

char* coin_row_problem(char **arr, int n)
{
    return coin_row(arr,0,n);
}

