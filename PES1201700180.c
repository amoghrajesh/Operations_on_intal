#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define lld long long int
#define atoa(x) #x

static char* reverse(char *str,int n)
{
	char s1;
	for(int i=0;i<n/2;i++)
	{
		s1=str[i];
		str[i]=str[n-i-1];
		str[n-i-1]=s1;
	}
   	str[n]='\0';
	return str;
}





char* intal_add(const char* intal1, const char* intal2){
	
	int n1 = strlen(intal1);
	int n2 = strlen(intal2);
	char* s3;
	int difference=0;
	int min=0;
	int max=0;
	int i=0;
	int j=0;
	int sum=0;
	int carry=0;
	int bigger=0;
	
	if(n1>n2){
		s3=(char*)malloc(sizeof(char)*(n1+1));
		difference = n1-n2;
		min = n2;
		max = n1;
		bigger=1;
	}
	else if(n1<n2){
		s3=(char*)malloc(sizeof(char)*(n2+1));
		difference = n2-n1;
		min = n1;
		max = n2;
		bigger=2;
	}
	else{
		s3=(char*)malloc(sizeof(char)*(n2+2));
		min = n1;
	}
	
	char* s1 = (char*)malloc(sizeof(char)*(n1+1));
	strcpy(s1,intal1);
	char* s2 = (char*)malloc(sizeof(char)*(n2+1));
	strcpy(s2,intal2);
	s1 = reverse(s1,n1);
	s2 = reverse(s2,n2);
	
	while(i<min)
	{
		sum = (s1[i] - '0') + (s2[i] - '0') + carry;
		s3[j++]= sum % 10 + '0';
		carry = sum / 10;
		i++;
		
	}
	
	if(bigger!=0){
		if(bigger==1){
			while(i<max){
				sum = s1[i] - '0' + carry;
				s3[j++]=sum%10 + '0';
				carry=sum/10;
				i++;
			}
		}
		else{
			while(i<max){
				sum = s2[i] - '0' + carry;
				s3[j++]=sum % 10 + '0';
				carry=sum / 10;
				i++;
			}
		}
	}
	
	if(carry!=0){
		s3[j++]=carry + '0';
	}
	
	s3[j]='\0';
	reverse(s3,strlen(s3));
	free(s1);
	free(s2);
	return s3;

}

// Returns the comparison value of two intals.
// Returns 0 when both are equal.
// Returns +1 when intal1 is greater, and -1 when intal2 is greater.
int intal_compare(const char* intal1, const char* intal2)
{
	int n1=strlen(intal1);
	int n2=strlen(intal2);
	int diff=0;
	
	if(n1<n2){
		return -1;
	}
	else if(n1>n2){
		return 1;
	}
	else{
		
		for(int i=0;i<n1;i++){
			diff = (intal1[i]-'0')-(intal2[i]-'0');
			if(diff<0){
				return -1;
			}
			else if(diff>0){
				return 1;
			}
		}
		return 0;
		
	}

}

//returns absolute difference of both
char* intal_diff(const char* intal1, const char* intal2)
{
	int n1 = strlen(intal1);
	int n2 = strlen(intal2);
	char* s3;
	int diff=0;
	int carry=0;
	int i=0;
	int j=0;
	char* s1 = (char*)malloc(sizeof(char)*(n1+1));
	strcpy(s1,intal1);
	char* s2 = (char*)malloc(sizeof(char)*(n2+1));
	strcpy(s2,intal2);
	n1=strlen(s1);
	n2=strlen(s2);
	int compare=intal_compare(intal1,intal2);
	

	//second one is bigger
	if(compare ==-1){
        char*temp=(char*)malloc(sizeof(char)*strlen(s1));
        char*temp1=(char*)malloc(sizeof(char)*strlen(s2));
        strcpy(temp,s1);
        strcpy(temp1,s2);
        s1=(char*)realloc(s1,strlen(s2));
        s2=(char*)realloc(s2,strlen(s1));
        strcpy(s1,temp1);
        strcpy(s2,temp);
	}
	s1=reverse(s1,strlen(s1));
    s2=reverse(s2,strlen(s2));
	n1=strlen(s1);
	n2=strlen(s2);
	s3=(char*)malloc(sizeof(char)*(n1+1));
	
	//first one is supposed to be the bigger one now
	for(int i=0;i<n2;i++)
    {
        
        int sub = ((s1[i]-'0')-(s2[i]-'0')-carry); 
        if (sub < 0) 
            { 
                    sub = sub + 10; 
                    carry = 1; 
            } 
             else
        {
                carry = 0; 
        }
        s3[j++]=sub+'0';
    }
    
    for(int i=n2;i<n1;i++)
    {
        int sub = ((s1[i]-'0') - carry); 
        if (sub < 0) 
             { 
            sub = sub + 10; 
            carry = 1; 
             } 
            else
        {
                    carry = 0; 
        }
        s3[j++]=sub+'0';
    
        
    }
    s3[j]='\0';
    s3=reverse(s3,strlen(s3));
	int n3=strlen(s3);
	char* s4=(char*)malloc(sizeof(char)*(n3+1));
	i=0;
	while(s3[i]=='0'){
		i++;
	}
	j=0;
	while(i<n3){
		s4[j++]=s3[i++];		
	}
	s4[j]='\0';
	return s4;

}

char* intal_multiply(const char* intal1, const char* intal2){
	

   	int n1=strlen(intal1);
    int n2=strlen(intal2);
	int temp;
    
    char*s1,*s2;
	//making sure first one is bigger one
    if(n1>n2)
    {
		temp=n1;
		n1=n2;
		n2=temp;
        s1=intal2;
        s2=intal1;
    }
    else
    {
        s1=intal1;
        s2=intal2;
    }
	
	
    
   	int total= n1 + n2;
	int carry=0;
	int product=0;
    char* s3=(char*)malloc(sizeof(char)*(total+1));
    for(int i=0;i<total;i++)
    {
        s3[i]='0';
    }
	
	
    s3[total]='\0';
	
    for(int i=n2-1;i>=0;i--)
    {
        total=(n1 + n2 - 1)-((n2-1)-i);
        for(int j=n1-1;j>=0;j--)
        {
            product=(((int)*(s1+j)) - 48) * (((int)*(s2+i))-48);
        
            carry = carry+product+((int)*(s3+total)-48);
            *(s3+total)=(char)(48+(carry%10));
            total--;
            carry = carry/10;
        }
        *(s3+total)=(char)(48+((int)*(s3+total)-48)+carry);
        carry = 0;  
    }
	
	int n3=strlen(s3);
	char* s4=(char*)malloc(sizeof(char)*(n3+1));
	int i=0;
	while(s3[i]=='0'){
		i++;
	}
	int j=0;
	while(i<n3){
		s4[j++]=s3[i++];		
	}
	s4[j]='\0';
	return s4;
}


void swap(char* str1,char* str2){
	char *temp = str1; 
  	str1 = str2; 
  	str2 = temp;
}


void intal_sort(char **arr, int n)
{
	int min=0;
	for(int i=0;i<n-1;i++){
   		min= i; 
        for (int j = i+1; j < n; j++){
			if(intal_compare(arr[i],arr[j])==-1){
				min=j;
			} 
		}
		swap(arr[i],arr[min]);
          
	}
}

int intal_min(char **arr, int n){
	int min=0;
	for(int i=1;i<n;i++){
		
		if(intal_compare(arr[i],arr[min])==-1){
			min=i;
		}
	}
	return min;
}

int intal_max(char **arr, int n){
	
	int max=0;
	for(int i=1;i<n;i++){
		if(intal_compare(arr[i],arr[max])==1){
			max=i;
		}
	}
	return max;
	
}
//generates fibonacci
char* intal_fibonacci(unsigned int n)
{
	
	char* a=(char*)malloc(sizeof(char)*1001);
	char* b=(char*)malloc(sizeof(char)*1001);
	char* c=(char*)malloc(sizeof(char)*1001);
	
	strcpy(a,"0");
	strcpy(b,"1");
	if(n==0){
		return a;
	}
	if(n==1){
		return b;
	}
	if(n==2){
		return "2";
	}
	
	int i=3;
	while(i<=n){
		c=intal_add(a,b);
		a=b;
		b=c;
		i++;
	}
	c=intal_add(a,b);
	free(a);
	free(b);
	return c;
	
	
	
}


int intal_search(char **arr, int n, const char* key)
{
	int i=0;
	while(i<n){
		if(intal_compare(arr[i],key)==0){
			return i;
		}
		i++;
	}
	return -1;
}


//arr is sorted
int intal_binsearch(char **arr, int n, const char* key)
{
	
	int l=0;
	int r=n-1;
	int mid=0;
	int compare=0;
	while(l<r){
		mid = l +(r-l)/2;
		compare=intal_compare(arr[mid],key);
		if(compare==0){
			return mid;
		}
		else if(compare>0){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
		
	}
	return -1;
	
}

char* intal_factorial(unsigned int n){

	char* f =(char*)malloc(sizeof(char)*1001);
	itoa(n,f,10);
	
	char* res=(char*)malloc(sizeof(char)*1001);
	strcpy(res,"1");
	
	while(atoi(f)!=1){
		res = intal_multiply(res,f);
		f=intal_diff(f,"1");		
	}
	free(f);
	return res;

}


//return intal^n
char* intal_pow(const char* intal1, unsigned int n)
{
	
	if(strcmp(intal1,"0")==0){
		return "0";
	}
	int half1=0;
	int half2=0;
	if(n%2==0){
		half1 = n/2;
		half2=0;
	}
	else{
		half1 = n/2;
		half2 = 1;
	}
	
	char* s1 =(char*)malloc(sizeof(char)*1001);
	strcpy(s1,intal1);
	
	char* temp=(char*)malloc(sizeof(char)*1001);;
	strcpy(temp,"1");


	for(int i=0;i<half1;i++){
		temp = intal_multiply(s1,temp);
		temp = intal_multiply(s1,temp);
	}
	
	if(half2){
		temp = intal_multiply(s1,temp);
	}
	
	
	free(s1);
	return temp;
		
	
	
}

char* intal_mod(const char* intal1, const char* intal2)
{
	char* n =(char*)malloc(sizeof(char)*1001);
	char* m =(char*)malloc(sizeof(char)*1001);
	strcpy(n,intal1);
	strcpy(m,intal2);
	
	int flag=0;
	char* res =(char*)malloc(sizeof(char)*1001);
	strcpy(res,intal1);
	char* temp =(char*)malloc(sizeof(char)*1001);

	while(intal_compare(res,m)!=-1){
		strcpy(temp,m);
		while(intal_compare(temp,res)==-1){
			temp=intal_multiply(temp,"2");
		}
		res = intal_diff(temp,res);
		flag+=1;
		flag=flag%2;
	}
	
	if(intal_compare(res,"0")==0){
		return 0;
	}
	if(flag==1){
		return intal_diff(m,res);
	}
	free(n);
	free(m);
	free(temp);
	return res;
	
	
}

char* intal_gcd(const char* intal1, const char* intal2)
{
	
	char* a =(char*)malloc(sizeof(char)*1001);
	strcpy(a,intal1);
	
	char* b =(char*)malloc(sizeof(char)*1001);
	strcpy(b,intal2);
	
	char* c =(char*)malloc(sizeof(char)*1001);
	//euclid's algorithm
	while(atoi(b)!=0){
		c = intal_mod(a,b);
		a=b;
		b=c;
	}
	free(b);
	free(c);
	return a;
	
	
}




int main()
{
	int n = 12;
	char **a = (char**) malloc(n * sizeof(char*));
	for(int i = 0; i < n; i++) {
		a[i] = (char*) malloc(1001 * sizeof(char));
	}
	
	strcpy(a[0], "1234512345123451234512345");
	strcpy(a[1], "543215432154321543215432154321");
	strcpy(a[2], "0");
	strcpy(a[3], "1234512345123451234512345");
	strcpy(a[4], "1234512345123451234512344");
	strcpy(a[5], "12");
	strcpy(a[6], "265252859812191058636308480000000");
	strcpy(a[7], "265252859812191058636308480000000");
	strcpy(a[8], "5432154321543215432154321");
	strcpy(a[9], "3");
	strcpy(a[10], "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
	strcpy(a[11], "1230231922161117176931558813276752514640713895736833715766118029160058800614672948775360067838593459582429649254051804908512884180898236823585082482065348331234959350355845017413023320111360666922624728239756880416434478315693675013413090757208690376793296658810662941824493488451726505303712916005346747908623702673480919353936813105736620402352744776903840477883651100322409301983488363802930540482487909763484098253940728685132044408863734754271212592471778643949486688511721051561970432780747454823776808464180697103083861812184348565522740195796682622205511845512080552010310050255801589349645928001133745474220715013683413907542779063759833876101354235184245096670042160720629411581502371248008430447184842098610320580417992206662247328722122088513643683907670360209162653670641130936997002170500675501374723998766005827579300723253474890612250135171889174899079911291512399773872178519018229989376");
	char *result1;
	int index1;

	result1 = intal_add(a[0], a[1]);
	if(!result1) {
		printf("Test intal_add FAILED.\n");
	} else {
		if(0 == strcmp(result1, "543216666666666666666666666666")) {
			printf("Test intal_add PASSED\n");
		} else {
			printf("Test intal_add FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "543216666666666666666666666666");
		}
		free(result1);
	}

	index1 = intal_compare(a[0], a[1]);
	if(-1 == index1) {
		printf("Test intal_compare PASSED\n");
	} else {
		printf("Test intal_compare FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, -1);
	}

	result1 = intal_diff(a[0], a[1]);
	if(!result1) {
		printf("Test intal_diff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "543214197641976419764197641976")) {
			printf("Test intal_diff PASSED\n");
		} else {
			printf("Test intal_diff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "543214197641976419764197641976");
		}
		free(result1);
	}

	result1 = intal_multiply(a[8], a[5]);
	if(!result1) {
		printf("Test intal_multiply FAILED.\n");
	} else {
		if(0 == strcmp(result1, "65185851858518585185851852")) {
			printf("Test intal_multiply PASSED\n");
		} else {
			printf("Test intal_multiply FAILED.\n.Your answer: %s\nExpected answer: %s\n", result1, "65185851858518585185851852");
		}
		free(result1);
	}
	index1 = intal_max(a, 10);
	if(6 == index1) {
		printf("Test intal_max PASSED\n");
	} else {
		printf("Test intal_max FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 6);
	}

	index1 = intal_min(a, 10);
	if(2 == index1) {
		printf("Test intal_min PASSED\n");
	} else {
		printf("Test intal_min FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 2);
	}

	index1 = intal_search(a, 10, a[7]);
	if(6 == index1) {
		printf("Test intal_search PASSED\n");
	} else {
		printf("Test intal_search FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 6);
	}
	
	result1 = intal_fibonacci(3);
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "2")) {
			printf("Test intal_fibonacci PASSED\n");
		} else {
			printf("Test intal_fibonacci FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "2");
		}
		free(result1);
	}

	result1 = intal_fibonacci(1000);
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875")) {
			printf("Test intal_fibonacci PASSED\n");
		} else {
			printf("Test intal_fibonacci FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875");
		}
		free(result1);
	}
	
result1 = intal_factorial(30);
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, a[6])) {
			printf("Test intal_factorial PASSED\n");
		} else {
			printf("Test intal_factorial FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[6]);
		}
		free(result1);
	}

	result1 = intal_factorial(100);
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000")) {
			printf("Test intal_factorial PASSED\n");
		} else {
			printf("Test intal_factorial FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000");
		}
		free(result1);
	}
	
	result1 = intal_pow(a[5], 3);
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1728")) {
			printf("Test intal_pow PASSED\n");
		} else {
			printf("Test intal_pow FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1728");
		}
		free(result1);
	}

	result1 = intal_pow("10", 999);
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, a[10])) {
			printf("Test intal_pow PASSED\n");
		} else {
			printf("Test intal_pow FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[10]);
		}
		free(result1);
	}

	result1 = intal_pow("2", 3000);
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, a[11])) {
			printf("Test intal_pow PASSED\n");
		} else {
			printf("Test intal_pow FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[11]);
		}
		free(result1);
	}
	
	result1 = intal_mod(a[3], a[4]);
	if(!result1) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Test intal_mod PASSED\n");
		} else {
			printf("Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
		}
		free(result1);
	}

	result1 = intal_mod("978", "5");
	if(!result1) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result1, "3")) {
			printf("Test intal_mod PASSED\n");
		} else {
			printf("Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "3");
		}
		free(result1);
	}

	result1 = intal_mod(a[0], a[5]);
	if(!result1) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result1, "9")) {
			printf("Test intal_mod PASSED\n");
		} else {
			printf("Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "9");
		}
		free(result1);
	}

		result1 = intal_gcd(a[0], a[5]);
	if(!result1) {
		printf("Test intal_gcd FAILED.\n");
	} else {
		if(0 == strcmp(result1, "3")) {
			printf("Test intal_gcd PASSED\n");
		} else {
			printf("Test intal_gcd FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "3");
		}
		free(result1);
	}
	
	
	
	

	
	
	
	
}