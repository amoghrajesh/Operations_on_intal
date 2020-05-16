#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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


//char* intal_add(const char* intal1, const char* intal2)
//{
//
//	char *str1,*str2,*s3;
//	str1=(char*)malloc(sizeof(char)*(strlen(intal1)+1));
//    str2=(char*)malloc(sizeof(char)*(strlen(intal2)+1));
//    strcpy(str1,intal1);
//    strcpy(str2,intal2);
// 
//    lld length1=strlen(intal1);
//    lld length2=strlen(intal2);
//    str1=reverse(str1,length1);
//    str2=reverse(str2,length2);
//
//
//    if(length1 > length2)
//    {
//    	s3=(char*)malloc(sizeof(char)*(length1+2));
//    }
//    else
//    {
//    	s3=(char*)malloc(sizeof(char)*(length2+2));
//    }
//    lld sum,carry,j,max,i,min;
//    carry=0;
//    j=0;
//    i=0;
//    if(length1<length2)
//    {
//        max=length2;
//        min=length1;
//    }
//    else
//    {
//        max=length1;
//        min=length2;
//    }
//    
//    
//    while(i<min)
//    {
//        if(i==0)
//        {
//            sum=str1[i]-'0' + str2[i]-'0';
//            carry=sum/10;
//            sum=sum%10;
//        }
//        else
//        {
//            sum=str1[i]-'0' + str2[i]-'0' +carry;
//            carry=sum/10;
//            sum=sum%10;
//        }
//        s3[j++]=sum+'0';
//        i=i+1;
//        
//    }
//    
//    if(max==length1)
//    {
//        while(i<length1)
//        {
//            sum=str1[i]-'0'+carry;
//            carry=sum/10;
//            sum=sum%10;
//            i=i+1;
//            s3[j++]=sum+'0';
//        }
//    }
//    else if(max==length2)
//    {
//        while(i<length2)
//        {
//            sum=str2[i]-'0'+carry;
//            carry=sum/10;
//            sum=sum%10;
//            i=i+1;
//            s3[j++]=sum+'0';
//        }
//    }
//    if(carry!=0)
//    {
//        s3[j++]=carry+'0';
//    }
//    s3[j]='\0';
//    s3=reverse(s3,strlen(s3));
//    //s3=removeleadingzeros(s3);
//    free(str1);
//    free(str2);
//    return s3;
//
//}


char* intal_add(const char* intal1, const char* intal2){
	//char* intal_add(const char* intal1, const char* intal2)
//{
//
//	char *str1,*str2,*s3;
//	str1=(char*)malloc(sizeof(char)*(strlen(intal1)+1));
//    str2=(char*)malloc(sizeof(char)*(strlen(intal2)+1));
//    strcpy(str1,intal1);
//    strcpy(str2,intal2);
// 
//    lld length1=strlen(intal1);
//    lld length2=strlen(intal2);
//    str1=reverse(str1,length1);
//    str2=reverse(str2,length2);
//
//
//    if(length1 > length2)
//    {
//    	s3=(char*)malloc(sizeof(char)*(length1+2));
//    }
//    else
//    {
//    	s3=(char*)malloc(sizeof(char)*(length2+2));
//    }
//    lld sum,carry,j,max,i,min;
//    carry=0;
//    j=0;
//    i=0;
//    if(length1<length2)
//    {
//        max=length2;
//        min=length1;
//    }
//    else
//    {
//        max=length1;
//        min=length2;
//    }
//    
//    
//    while(i<min)
//    {
//        if(i==0)
//        {
//            sum=str1[i]-'0' + str2[i]-'0';
//            carry=sum/10;
//            sum=sum%10;
//        }
//        else
//        {
//            sum=str1[i]-'0' + str2[i]-'0' +carry;
//            carry=sum/10;
//            sum=sum%10;
//        }
//        s3[j++]=sum+'0';
//        i=i+1;
//        
//    }
//    
//    if(max==length1)
//    {
//        while(i<length1)
//        {
//            sum=str1[i]-'0'+carry;
//            carry=sum/10;
//            sum=sum%10;
//            i=i+1;
//            s3[j++]=sum+'0';
//        }
//    }
//    else if(max==length2)
//    {
//        while(i<length2)
//        {
//            sum=str2[i]-'0'+carry;
//            carry=sum/10;
//            sum=sum%10;
//            i=i+1;
//            s3[j++]=sum+'0';
//        }
//    }
//    if(carry!=0)
//    {
//        s3[j++]=carry+'0';
//    }
//    s3[j]='\0';
//    s3=reverse(s3,strlen(s3));
//    //s3=removeleadingzeros(s3);
//    free(str1);
//    free(str2);
//    return s3;
//
//}
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
    
    for(long int i=n2;i<n1;i++)
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
	return s3;
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



int main()
{int n = 12;
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
 	printf("addition = %s \n",intal_add("9999","1"));
//	result1 = intal_add(a[0], a[1]);
//	if(!result1) {
//		printf("Test intal_add FAILED.\n");
//	} else {
//		if(0 == strcmp(result1, "543216666666666666666666666666")) {
//			printf("Test intal_add PASSED\n");
//		} else {
//			printf("Test intal_add FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "543216666666666666666666666666");
//		}
//		free(result1);
//	}
//
//	index1 = intal_compare(a[0], a[1]);
//	if(-1 == index1) {
//		printf("Test intal_compare PASSED\n");
//	} else {
//		printf("Test intal_compare FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, -1);
//	}
//
//	result1 = intal_diff(a[0], a[1]);
//	if(!result1) {
//		printf("Test intal_diff FAILED.\n");
//	} else {
//		if(0 == strcmp(result1, "543214197641976419764197641976")) {
//			printf("Test intal_diff PASSED\n");
//		} else {
//			printf("Test intal_diff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "543214197641976419764197641976");
//		}
//		free(result1);
//	}
//
//	result1 = intal_multiply(a[8], a[5]);
//	if(!result1) {
//		printf("Test intal_multiply FAILED.\n");
//	} else {
//		if(0 == strcmp(result1, "65185851858518585185851852")) {
//			printf("Test intal_multiply PASSED\n");
//		} else {
//			printf("Test intal_multiply FAILED.\n.Your answer: %s\nExpected answer: %s\n", result1, "65185851858518585185851852");
//		}
//		free(result1);
//	}
}