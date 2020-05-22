#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"intal.h"



static char* reverse(char *str,int n)
{
	char string1;
	for(int i=0;i<n/2;i++)
	{
		string1=str[i];
		str[i]=str[n-i-1];
		str[n-i-1]=string1;
	}
    	str[n]='\0';
	return str;
}	



static int min(int x,int y)
{
	if(x>y)
		return y;
	else
		return x;
}

static char* zeropruning(char*str)
{
    int n=strlen(str);
    int count,i;
    count=0;
    for(i=0;i<n;i++)
    {
        if(str[i]=='0')
            count++;
        else
            break;
    }
    if(count==0)
        return str;
    else if(count==n)
    {
        char *str1=(char*)malloc(sizeof(char)*2);
        str1[0]='0';
        str1[1]='\0';
        free(str);
        return str1;
    }
    else
    {

        
        char*str1=(char*)malloc(sizeof(char)*(10001));
        int  j=0;
        while(str[count]!='\0')
            str1[j++]=str[count++];
        str1[j]='\0';
        free(str);
        return str1;
    }
}


char* intal_add(const char* intal1, const char* intal2)
{

	char *string1,*string2,*answer;
	string1=(char*)malloc(sizeof(char)*(strlen(intal1)+1));
    string2=(char*)malloc(sizeof(char)*(strlen(intal2)+1));
    strcpy(string1,intal1);
    strcpy(string2,intal2);
 
    int length1=strlen(intal1);
    int length2=strlen(intal2);
    string1=reverse(string1,length1);
    string2=reverse(string2,length2);

    if(length1 > length2)
    {
    	answer=(char*)malloc(sizeof(char)*(length1+2));
    }
    else
    {
    	answer=(char*)malloc(sizeof(char)*(length2+2));
    }
    int sum,carry,j,max,i,min;
    carry=0;
    j=0;
    i=0;
    if(length1<length2)
    {
        max=length2;
        min=length1;
    }
    else
    {
        max=length1;
        min=length2;
    }
    
    
    while(i<min)
    {
        if(i==0)
        {
            sum=string1[i]-'0' + string2[i]-'0';
            carry=sum/10;
            sum=sum%10;
        }
        else
        {
            sum=string1[i]-'0' + string2[i]-'0' +carry;
            carry=sum/10;
            sum=sum%10;
        }
        answer[j++]=sum+'0';
        i=i+1;
        
    }
    
    if(max==length1)
    {
        while(i<length1)
        {
            sum=string1[i]-'0'+carry;
            carry=sum/10;
            sum=sum%10;
            i=i+1;
            answer[j++]=sum+'0';
        }
    }
    else if(max==length2)
    {
        while(i<length2)
        {
            sum=string2[i]-'0'+carry;
            carry=sum/10;
            sum=sum%10;
            i=i+1;
            answer[j++]=sum+'0';
        }
    }
    if(carry!=0)
    {
        answer[j++]=carry+'0';
    }
    answer[j]='\0';
    answer=reverse(answer,strlen(answer));
    answer=zeropruning(answer);
    free(string1);
    free(string2);
    return answer;


}





char* intal_diff(const char* intal1, const char* intal2)
{
	char*final;
    
    char*str1=(char*)malloc(sizeof(char)*(strlen(intal1)+1));
    char*str2=(char*)malloc(sizeof(char)*(strlen(intal2)+1));
    strcpy(str1,intal1);
    strcpy(str2,intal2);
    
    int cmp=intal_compare(str1,str2);
    if(cmp==-1)
    {
        char*temp=(char*)malloc(sizeof(char)*(strlen(str1)+1));
        char*temp1=(char*)malloc(sizeof(char)*(strlen(str2)+1));
        strcpy(temp,str1);
        strcpy(temp1,str2);
        str1=(char*)realloc(str1,strlen(str2)+1);
        str2=(char*)realloc(str2,strlen(str1)+1);
        strcpy(str1,temp1);
        strcpy(str2,temp);
        free(temp);
        free(temp1);

    }
    
    str1=reverse(str1,strlen(str1));
    str2=reverse(str2,strlen(str2));
  
    
    long long int l1=strlen(str1);
    long long int l2=strlen(str2);
    
    long long int k=0;
    long long int carry=0;
    final=(char*)malloc(sizeof(char)*(l1+1));
    for(long long int i=0;i<l2;i++)
    {
        
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
        if (sub < 0) 
            { 
                    sub = sub + 10; 
                    carry = 1; 
            } 
             else
        {
                carry = 0; 
        }
        final[k++]=sub+'0';
    }
    
    for(long long int i=l2;i<l1;i++)
    {
        long long int sub = ((str1[i]-'0') - carry); 
        if (sub < 0) 
             { 
            sub = sub + 10; 
            carry = 1; 
             } 
            else
        {
                    carry = 0; 
        }
        final[k++]=sub+'0';
    
        
    }
    final[k]='\0';
    
    final=reverse(final,strlen(final));
    
    final=zeropruning(final);
   
   	free(str1);
   	free(str2);
    return final;
}






char* intal_multiply(const char* intal1, const char* intal2)
{

	
   	long long int length1=strlen(intal1);
    long long int length2=strlen(intal2);
    
    char*string1,*string2;
    if(length1>length2)
    {
        length1=length1+length2;
        length2=length1-length2;
        length1=length1-length2;
        string1=(char*)malloc(sizeof(char)*(strlen(intal2)+1));
        string2=(char*)malloc(sizeof(char)*(strlen(intal1)+1));
       	strcpy(string1,intal2);
       	strcpy(string2,intal1);
    }
    else
    {
    	string1=(char*)malloc(sizeof(char)*(strlen(intal1)+1));
        string2=(char*)malloc(sizeof(char)*(strlen(intal2)+1));
       	strcpy(string1,intal1);
       	strcpy(string2,intal2);
    }
    
    long long int i,j,totallen,carry,product;
    totallen=length1+length2;
    char*answer=(char*)malloc(sizeof(char)*(totallen+1));
    carry=0;
    for(i=0;i<totallen;i++)
    {
        answer[i]='0';
    }
    answer[totallen]='\0';
    for(i=length2-1;i>=0;i--)
    {
        totallen=(length1+length2-1)-((length2-1)-i);
        for(j=length1-1;j>=0;j--)
        {
            product=(((int)*(string1+j)) - '0') * (((int)*(string2+i))-'0');
        
            carry = carry+product+((int)*(answer+totallen)-'0');
            *(answer+totallen)=(char)('0'+(carry%10));
                totallen--;
            carry=carry/10;
        }
        *(answer+totallen)=(char)('0'+((int)*(answer+totallen)-'0')+carry);
            carry = 0;  
    }
   	free(string1);
   	free(string2);
    
    answer=zeropruning(answer);
    return answer;

   

}


int intal_compare(const char* intal1, const char* intal2)
{

    int length1=strlen(intal1);
    int length2=strlen(intal2);
    //int length3=0;
    if(length1<length2)
    {
        return -1;
    }
    else if(length1>length2)
    {
        return 1;
    }
    else if(length1==length2)
    {
        for(int i=0;i<length1;i++)
        {
            if(intal1[i]-'0' > intal2[i]-'0')
            {
                return 1;
            }
            else if(intal1[i]-'0' < intal2[i]-'0')
            {
                return -1;
            }
            else
            {
                continue;
            }
        }
    }
    return 0;

}




static char * helper_pow(char *x1,unsigned int y)
{

	char *res=(char*)malloc(sizeof(char)*10001);
	char *x=(char*)malloc(sizeof(char)*10001);
	strcpy(x,x1);
    char *ppp=intal_add("0","1");
	strcpy(res,ppp);
    free(ppp);
	while(y>0)
	{
		if(y&1)
		{
            char*ok=intal_multiply(res,x);
            strcpy(res,ok);
            free(ok);
			//res=intal_multiply(res,x);
		}
		y=y>>1;
        char*temp=intal_multiply(x,x);
        strcpy(x,temp);
		//x=intal_multiply(x,x);
        free(temp);
	}
	free(x);
	return(res);
}


char* intal_pow(const char* intal1, unsigned int n)
{
	char *str=(char*)malloc(sizeof(char)*(strlen(intal1)+1));
	strcpy(str,intal1);
	char *ans=(char*)malloc(sizeof(char)*10001);
    char*ok=helper_pow(str,n);
	strcpy(ans,ok);
	free(str);
    free(ok);
	return ans;

}





char* intal_mod(const char* intal1, const char* intal2){

    
    int flag=0;
    char* res=(char*)malloc(sizeof(char)*10001);
    strcpy(res, intal1);
    char*str2=(char*)malloc(sizeof(char)*10001);
    strcpy(str2,intal2);
    char* temp= (char*)malloc(sizeof(char)*10001);
    while(intal_compare(res, str2)>=0)
    {
       
        strcpy(temp,str2);
        while (intal_compare(temp, res)==-1)
        {
            char *ok=intal_multiply(temp,"2");
            strcpy(temp,ok);
            free(ok);  
           
        }
        char*diffget=intal_diff(temp,res);
        strcpy(res,diffget);
        free(diffget);
        flag= (flag+1)%2;
    }
    char*ans=(char*)malloc(sizeof(char)*1001);
    if(intal_compare(res,"0")==0)
    {
        char*ok=intal_add("0","0");
        strcpy(ans,ok);
        free(ok);
    }
    else if(flag%2==1)
    {
        char*ok=intal_diff(intal2,res);
    	strcpy(ans,ok);
        free(ok);
    }
    else
    {
    	strcpy(ans,res);
    }
    free(res);
    free(temp);
    free(str2);
    return ans;
}





static char *gcd(char *a,char*b)
{
	if(intal_compare(a,"0")==0)
    {
        char*ok=(char*)malloc(sizeof(char)*10001);
        strcpy(ok,b);
		return ok;
    }
    char*temp1=(char*)malloc(sizeof(char)*10001);
    char*temp2=(char*)malloc(sizeof(char)*10001);
    strcpy(temp2,b);
    strcpy(temp1,a);
    char*reqmod=intal_mod(temp2,temp1);
    char*answer=gcd(reqmod,temp1);
    free(temp1);
    free(temp2);
    free(reqmod);
    return answer;
	//return gcd(intal_mod(b,a),a);

}



char* intal_gcd(const char* intal1, const char* intal2)
{
	char*str1=(char*)malloc(sizeof(char)*10001);
	char*str2=(char*)malloc(sizeof(char)*10001);
	strcpy(str1,intal1);
	strcpy(str2,intal2);
	char*answer=(char*)malloc(sizeof(char)*10001);
	if(intal_compare(str1,"0")==0 && intal_compare(str2,"0")==0)
	{
		char*ok=intal_add("0","0");
		strcpy(answer,ok);
        free(ok);
	}
	else
	{
		
        char*ok=gcd(str1,str2);
        strcpy(answer,ok);
        free(ok);

	}
	free(str1);
	free(str2);
	return answer;

}






char* intal_factorial(unsigned int n)
{
	char*answer=(char*)malloc(sizeof(char)*10011);
	char *tomultiply=(char*)malloc(sizeof(char)*10011);
	char *toadd=(char*)malloc(sizeof(char)*10011);

	answer[0]='1';
	answer[1]='\0';
	tomultiply[0]='1';
	tomultiply[1]='\0';
	toadd[0]='1';
	toadd[1]='\0';
	
	if(n==0)
	{
		answer[0]='1';
		answer[1]='\0';
		
	}
	else
	{
		
		for(long long int i=2;i<=n;i++)
		{
            char*temp=intal_add(tomultiply,toadd);
            strcpy(tomultiply,temp);
            char*temp1=intal_multiply(answer,tomultiply);
            strcpy(answer,temp1);
			free(temp);
            free(temp1);
            
		}

	}
	free(tomultiply);
	free(toadd);
	
	return answer;

}





char* intal_fibonacci(unsigned int n)
{
	char *temp1=(char*) malloc(10000 * sizeof(char));
	char *temp2=(char*) malloc(10000 * sizeof(char));
	char *temp3;
    char *a=intal_add("0","0");
    char *b=intal_add("0","1");
	strcpy(temp1,a);
    strcpy(temp2,b);
    free(a);
    free(b);
	char*ans=(char*) malloc(10011 * sizeof(char));
	
	if(n==0)
	{
		temp3=(char*) malloc(10000 * sizeof(char));
		strcpy(temp3,temp1);
		
	}
	if(n==1)
	{
		temp3=(char*) malloc(10000 * sizeof(char));
		strcpy(temp3,temp2);
	}

	for(long long int i=2;i<=n;i++)
	{
		temp3=intal_add(temp1,temp2);
        free(temp1);
		temp1=temp2;
		temp2=temp3;
		
	}
	
	strcpy(ans,temp3);
	free(temp1);
	free(temp2);
	return ans;

}



char* intal_bincoeff(unsigned int n, unsigned int k)
{
    if(k>n)
    {
        char *ans = (char *)malloc(sizeof(char)*2);
        ans[0]='0';
        ans[1]='\0';
        return ans;
    }
    if(k==0)
    {
        char* ans = (char*)malloc(sizeof(char)*2);
        ans[0]='1';
        ans[1]='\0';
        return ans;
    }
    if(n==k)
    {
        char* ans = (char*)malloc(sizeof(char)*2);
        ans[0]='1';
        ans[1]='\0';
        return ans;
    }
    if(n-k<k)
    {
        k=n-k;
    }
    char** dp=malloc(sizeof(char*)*(k+1));
    char *ok=malloc(sizeof(char)*1001);
    //int i=0;
    //while(i<=k)
    for(int i=0;i<=k;i++)
    {
        dp[i]=malloc(sizeof(char)*1001);
        dp[i][0]='0';
        dp[i][1]='\0';
       
    }   
    dp[0][0]='1';
    dp[0][1]='\0';
    char* temp;
    
    for(int i=1;i<=n;i++)
    { 
    
        for (int j = min(i, k); j > 0; j--) 
        {
            temp = intal_add(dp[j],dp[j-1]); 
            strcpy(dp[j],temp);
            free(temp);
            
        }
        
            
    } 
    strcpy(ok,dp[k]);
   
    for(int i=0;i<=k;i++)
    {
        if(dp[i]!=NULL)
            free(dp[i]);
    }
    free(dp);
    return ok;
}
  






  




int intal_min(char **arr, int n)
{
	int index=0;
	char *str1=(char*)malloc(sizeof(char)*10001);
	char *str2=(char*)malloc(sizeof(char)*10001);

	strcpy(str1,arr[0]);

	for(int i=1;i<n;i++)
	{
		strcpy(str2,arr[i]);

		if(intal_compare(str2,str1)==-1)
		{
			strcpy(str1,arr[i]);
			index=i;
		}
		
	}
	free(str1);
	free(str2);
	return index;
}



int intal_max(char **arr, int n)
{
	int index=0;
	char *str1=(char*)malloc(sizeof(char)*10001);
	char *str2=(char*)malloc(sizeof(char)*10001);

	strcpy(str1,arr[0]);

	for(int i=1;i<n;i++)
	{
		strcpy(str2,arr[i]);

		if(intal_compare(str2,str1)==1)
		{
			strcpy(str1,arr[i]);
			index=i;
		}
		
	}
	free(str1);
	free(str2);
	return index;

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






static void merge(char **arr, int l, int m, int r) 
{
	int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
   
   	char **L = (char**) malloc((n1+1) * sizeof(char*));
	for(int p = 0; p <= n1; p++) {
		L[p] = (char*) malloc(10001 * sizeof(char));

	}

	char **R = (char**) malloc((n2+1) * sizeof(char*));
	for(int p = 0; p <= n2; p++) {
		R[p] = (char*) malloc(10001 * sizeof(char));
	}


    //char L[n1][10001],R[n2][10001] ;
    for (i = 0; i < n1; i++) 
    {
        strcpy(L[i],arr[l + i]); 
    }
    for (j = 0; j < n2; j++) 
    {
        strcpy(R[j],arr[m + 1+ j]); 
    }

    i = 0; 
    j = 0;  
    k = l;
    while (i < n1 && j < n2) 
    { 
        
        if((intal_compare(L[i],R[j])==-1) || (intal_compare(L[i],R[j])==0) )
        {
        	strcpy(arr[k],L[i]);
        	i++;
        }
        else
        { 
           	strcpy(arr[k],R[j]);
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        strcpy(arr[k],L[i]); 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        strcpy(arr[k],R[j]); 
        j++; 
        k++; 
    } 

    for(int p=0;p<=n1;p++)
    {
    	if(L[p]!=NULL)
    		free(L[p]);
    }
    for(int p=0;p<=n2;p++)
    {
    	if(R[p]!=NULL)
    		free(R[p]);
    }
    free(L);
    free(R);


}






static void mergeSort(char**arr, int l, int r) 
{if (l < r) 
    { 
        
        int m = (l+r)/2;
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 

}


void intal_sort(char **arr, int n)
{
	mergeSort(arr,0,n-1);
	
}







static int searchbinary(char **arr, int l,int r, const char* key)
{
	if(r>=l)
	{
		int mid=(l+r)/2;
		
		if(intal_compare(arr[mid],key)==0)
		{
			
			int ans=mid;
			while(mid>=0 && intal_compare(arr[mid],key)==0)
			{
				
				ans=mid;
				mid--;
			}
			return ans;
		}
		else if(intal_compare(arr[mid],key)==1)
		{
			return searchbinary(arr,l,mid-1,key);
		}
		else
		{
			return searchbinary(arr,mid+1,r,key);
		}
	}
	return -1;
}






int intal_binsearch(char **arr, int n, const char* key)
{
	
	return searchbinary(arr,0,n,key);
}









char* coin_row_problem(char **arr, int n)
{

	char*temp1=(char*)malloc(sizeof(char)*10001);
	char*temp2=(char*)malloc(sizeof(char)*10001);
	char*old=(char*)malloc(sizeof(char)*10001);
	if(n==0)
	{
		return intal_add("0","0");
	}
	if(n==1)
	{
		return arr[1];
	}
	strcpy(temp1,"0");
	strcpy(temp2,"0");
	for(int i=0;i<n;i++)
	{
		strcpy(old,temp2);
		if(intal_compare(temp1,temp2)==1)
		{
			strcpy(temp2,temp1);
		}
        char*ok=intal_add(arr[i],old);
        strcpy(temp1,ok);
        free(ok);
		//strcpy(temp1,intal_add(arr[i],old));
	}
	if(intal_compare(temp1,temp2)==1)
	{
		free(temp2);
        free(old);
		return temp1;
	}
	else
	{
		free(temp1);
        free(old);
		return temp2;
	}


}