#define lld long long int
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"intal.h"


static lld min(lld a,lld b)
{
	if(a>b)
		return b;
	return a;
}

/////////////////////////zero////////////////////////////////////
static char* removeleadingzeros(char*str)
{

	long long int n=strlen(str);
	long long int count,i;
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
		
		return str1;
	}
	else
	{

		char*str1=(char*)malloc(sizeof(char)*(n+1-count));
		long long int j=0;
		while(str[count]!='\0')
			str1[j++]=str[count++];
		str1[j]='\0';

		return str1;
	}
}


///////////reverse///
static char* string_reverse(char *str,int n)
{
	char s1;
	for(long int i=0;i<n/2;i++)
	{
		s1=str[i];
		str[i]=str[n-i-1];
		str[n-i-1]=s1;
	}
    	str[n]='\0';
	return str;
}	


///////////////////comapre///////////////////

int intal_compare(const char* intal1, const char* intal2)
{

    lld length1=strlen(intal1);
    lld length2=strlen(intal2);
    lld length3=0;
    if(length1>length2)
    {
        return 1;
    }
    else if(length1<length2)
    {
        return -1;
    }
    else if(length1==length2)
    {
        for(lld i=0;i<length1;i++)
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
                length3=length3+1;
            }
        }
    }
    return 0;

}



///////////////multilpy//////////////////////////////////

char* intal_multiply(const char* intal1, const char* intal2)
{

	
   	lld length1=strlen(intal1);
    lld length2=strlen(intal2);
    
    char*s1,*s2;
    if(length1>length2)
    {
        length1=length1+length2;
        length2=length1-length2;
        length1=length1-length2;
        s1=(char*)malloc(sizeof(char)*(strlen(intal2)+1));
        s2=(char*)malloc(sizeof(char)*(strlen(intal1)+1));
       	strcpy(s1,intal2);
       	strcpy(s2,intal1);
    }
    else
    {
    	s1=(char*)malloc(sizeof(char)*(strlen(intal1)+1));
        s2=(char*)malloc(sizeof(char)*(strlen(intal2)+1));
       	strcpy(s1,intal1);
       	strcpy(s2,intal2);
    }
    
    lld i,j,totallen,carry,product;
    totallen=length1+length2;
    char*s3=(char*)malloc(sizeof(char)*(totallen+1));
    carry=0;
    for(i=0;i<totallen;i++)
    {
        s3[i]='0';
    }
    s3[totallen]='\0';
    for(i=length2-1;i>=0;i--)
    {
        totallen=(length1+length2-1)-((length2-1)-i);
        for(j=length1-1;j>=0;j--)
        {
            product=(((int)*(s1+j)) - 48) * (((int)*(s2+i))-48);
        
            carry = carry+product+((int)*(s3+totallen)-48);
            *(s3+totallen)=(char)(48+(carry%10));
                totallen--;
            carry=carry/10;
        }
        *(s3+totallen)=(char)(48+((int)*(s3+totallen)-48)+carry);
            carry = 0;  
    }
   	free(s1);
   	free(s2);
    s3=removeleadingzeros(s3);
    return s3;

}


////////////////////////diff///////////
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
        str1=(char*)realloc(str1,strlen(str2));
        str2=(char*)realloc(str2,strlen(str1));
        strcpy(str1,temp1);
        strcpy(str2,temp);
    }
    
    str1=string_reverse(str1,strlen(str1));
    str2=string_reverse(str2,strlen(str2));
    
    lld l1=strlen(str1);
    lld l2=strlen(str2);
    
    lld k=0;
    lld carry=0;
    final=(char*)malloc(sizeof(char)*(l1+1));
    for(lld i=0;i<l2;i++)
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
    
    for(lld i=l2;i<l1;i++)
    {
        lld sub = ((str1[i]-'0') - carry); 
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
    
    final=string_reverse(final,strlen(final));
    final=removeleadingzeros(final);
   	//printf("%s\n",final ); 
   	free(str1);
   	free(str2);
    return final;
}




////////////////////////add/////////////////
char* intal_add(const char* intal1, const char* intal2)
{

	char *str1,*str2,*s3;
	str1=(char*)malloc(sizeof(char)*(strlen(intal1)+1));
    str2=(char*)malloc(sizeof(char)*(strlen(intal2)+1));
    strcpy(str1,intal1);
    strcpy(str2,intal2);
 
    lld length1=strlen(intal1);
    lld length2=strlen(intal2);
    str1=string_reverse(str1,length1);
    str2=string_reverse(str2,length2);


    if(length1 > length2)
    {
    	s3=(char*)malloc(sizeof(char)*(length1+2));
    }
    else
    {
    	s3=(char*)malloc(sizeof(char)*(length2+2));
    }
    lld sum,carry,j,max,i,min;
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
            sum=str1[i]-'0' + str2[i]-'0';
            carry=sum/10;
            sum=sum%10;
        }
        else
        {
            sum=str1[i]-'0' + str2[i]-'0' +carry;
            carry=sum/10;
            sum=sum%10;
        }
        s3[j++]=sum+'0';
        i=i+1;
        
    }
    
    if(max==length1)
    {
        while(i<length1)
        {
            sum=str1[i]-'0'+carry;
            carry=sum/10;
            sum=sum%10;
            i=i+1;
            s3[j++]=sum+'0';
        }
    }
    else if(max==length2)
    {
        while(i<length2)
        {
            sum=str2[i]-'0'+carry;
            carry=sum/10;
            sum=sum%10;
            i=i+1;
            s3[j++]=sum+'0';
        }
    }
    if(carry!=0)
    {
        s3[j++]=carry+'0';
    }
    s3[j]='\0';
    s3=string_reverse(s3,strlen(s3));
    s3=removeleadingzeros(s3);
    free(str1);
    free(str2);
    return s3;

}






 ////////////factorial/////////
char* intal_factorial(unsigned int n)
{
	char *str=intal_add("0","1");
	char *tomultiply=intal_add("0","1");
	//printf("%s %s\n",str,tomultiply);
	char *add=intal_add("0","1");
	if(n==0)
		return "0";
	else
	{
		
		for(long long int i=2;i<=n;i++)
		{
			tomultiply=intal_add(tomultiply,add);
			str=intal_multiply(str,tomultiply);
		}

	}
	//printf("%s\n",str );
	return str;

}


///////////////fibonacci/////////////////////
char* intal_fibonacci(unsigned int n)
{
	char *a=(char*) malloc(1001 * sizeof(char));
	char *b=(char*) malloc(1001 * sizeof(char));
	char *c=(char*) malloc(1001 * sizeof(char));
	a=intal_add("0","1");
	b=intal_add("0","1");
	c=intal_add("0","2");
	if(n==0 || n==1)
		return a;
	if(n==2)
		return c;

	for(long long int i=2;i<=n;i++)
	{
		c=intal_add(a,b);
		a=b;
		b=c;
	}
	free(b);
	return a;

}





/////////////////////////binomial coefficient////////////////////////////
char* intal_bincoeff(unsigned int n, unsigned int k)
{

	char dp[n+1][k+1][10001];

	lld i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0; j<=min(i,k);j++)
		{
			if(j==0 || j==i)
			{
				strcpy(dp[i][j],"1");
			}
			else
			{
				strcpy(dp[i][j],intal_add(dp[i-1][j-1],dp[i-1][j]));
			}
		}
	}
	char *ans=(char*)malloc(sizeof(char)*(strlen(dp[n][k])+1));
	strcpy(ans,dp[n][k]);
	return ans;


}


////////////////////////intal_max//////////////////////////

int intal_max(char **arr, int n)
{
	int index=-1;
	char *str1=(char*)malloc(sizeof(char)*1001);
	char *str2=(char*)malloc(sizeof(char)*1001);

	strcpy(str1,"0");

	for(int i=0;i<n;i++)
	{
		strcpy(str2,arr[i]);

		if(intal_compare(str2,str1)==1)
		{
			strcpy(str1,arr[i]);
			index=i;
		}
		else if(intal_compare(str2,str1)==0)
		{
			if(index==-1)
				index=i;
		}
	}
	free(str1);
	free(str2);
	return index;

}


//////////////////////intal_ min////////////

int intal_min(char **arr, int n)
{
	int index=-1;
	char *str1=(char*)malloc(sizeof(char)*1001);
	char *str2=(char*)malloc(sizeof(char)*1001);

	strcpy(str1,"0");

	for(int i=0;i<n;i++)
	{
		strcpy(str2,arr[i]);

		if(intal_compare(str2,str1)==-1)
		{
			strcpy(str1,arr[i]);
			index=i;
		}
		else if(intal_compare(str2,str1)==0)
		{
			if(index==-1)
				index=i;
		}
	}
	free(str1);
	free(str2);
	return index;
}




///////////////intal_search//////////////
int intal_search(char **arr, int n, const char* key)
{
	char *str1=(char*)malloc(sizeof(char)*1001);

	for(int i=0;i<n;i++)
	{
		strcpy(str1,arr[i]);
		if(intal_compare(str1,key)==0)
			return i;
	}
	return -1;
}




////////////////sort///////////////////////
static void merge(char **arr, int l, int m, int r) 
{
	int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
   
	//to store all the strin
    char L[n1][10001],R[n2][10001];
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



}






static void mergeSort(char**arr, int l, int r) 
{if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = (l+r)/2;
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 

}


void intal_sort(char **arr, int n)
{
	mergeSort(arr,0,n+1);
	
}



static int binarysearch(char **arr, int l,int r, const char* key)
{
	if(r>=l)
	{
		int mid=(l+r)/2;
		
		if(intal_compare(arr[mid],key)==0)
		{
			return mid;
			int last=mid;
			while(intal_compare(arr[mid],key)==0)
			{
				
				last=mid;
				mid--;
			}
			return last;
		}
		else if(intal_compare(arr[mid],key)==1)
		{
			return binarysearch(arr,l,mid-1,key);
		}
		else
		{
			return binarysearch(arr,mid+1,r,key);
		}
	}
	return -1;
}





////////////////binarysearch/////////////
int intal_binsearch(char **arr, int n, const char* key)
{
	/*for(int i=0;i<=n;i++)
	{
		printf("%s\n",arr[i] );
	}*/
	return binarysearch(arr,0,n,key);
}



////////////coin-row////////////
char* coin_row_problem(char **arr, int n)
{

	char*sum1=(char*)malloc(sizeof(char)*10001);
	char*sum2=(char*)malloc(sizeof(char)*10001);
	char*old=(char*)malloc(sizeof(char)*10001);
	if(n==0)
		return "0";
	if(n==1)
		return arr[1];
	strcpy(sum1,"0");
	strcpy(sum2,"0");
	for(lld i=0;i<n;i++)
	{
		strcpy(old,sum2);
		if(intal_compare(sum1,sum2)==1)
		{
			strcpy(sum2,sum1);
		}
		strcpy(sum1,intal_add(arr[i],old));
	}
	if(intal_compare(sum1,sum2)==1)
	{
		free(sum2);
		return sum1;
	}
	else
	{
		free(sum1);
		return sum2;
	}


}





////////////////////////mod//////////////////////////////

char* intal_mod(const char* intal1, const char* intal2)
{
	char*str1=(char*)malloc(sizeof(char)*10001);
	char*str2=(char*)malloc(sizeof(char)*10001);
	strcpy(str1,intal1);
	strcpy(str2,intal2);
	
	lld flag=0;
	
	char *temp=(char*)malloc(sizeof(char)*10001);
	while(intal_compare(str1,str2)==1 || intal_compare(str1,str2)==0)
	{
		strcpy(temp,str2);
		while(intal_compare(temp,str1)==-1)
		{
			temp=intal_multiply(temp,"2");

		}
		str1=intal_diff(temp,str1);
		flag=(flag+1)%2;

	}
	free(temp);
	if(intal_compare(str1,"0")==0)
	{
		free(str1);
		free(str2);
		return "0";
	}

	if(flag==1)
	{
		char *ans=intal_diff(str2,str1);
		free(str1);
		free(str2);
		return ans;
	}
	free(str2);
	return str1;

}





////////////////gcd////////////

static char *gcd_helper(char *a,char*b)
{
	if(intal_compare(a,"0")==0)
		return b;

	return gcd_helper(intal_mod(b,a),a);

}

char* intal_gcd(const char* intal1, const char* intal2)
{
	char*str1=(char*)malloc(sizeof(char)*10001);
	char*str2=(char*)malloc(sizeof(char)*10001);
	strcpy(str1,intal1);
	strcpy(str2,intal2);
	if(intal_compare(str1,"0")==0 && intal_compare(str2,"0")==0)
	{
		return "0";
	}
	
	char *ans=gcd_helper(str1,str2);	
	free(str1);
	free(str2);
	return ans;

}


//////////////////pow////////////////////////////////////////

char* intal_pow(const char* intal1, unsigned int n)
{
	char *str=(char*)malloc(sizeof(char)*(strlen(intal1)+1));
	strcpy(str,intal1);

	if(n==0)
		return "0";
	if(intal_compare(str,"0")==0)
		return "0";

	char *ans=intal_add("0","1");

	for(lld i=1;i<=n;i++)
	{
		ans=intal_multiply(ans,str);
	}
	return ans;
}

















