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

char* intal_bincoeff(unsigned int n, unsigned int k)
{
	
	//k
	char** C=(char**) malloc((k+1) * sizeof(char*));
	for(int i=0;i<=k;i++){
		C[i] = (char*) malloc(1001 * sizeof(char));
		strcpy(C[i],"0");
	}
	
	//nC0=1
    strcpy(C[0],"1"); 
  
    for (int i = 1; i <= n; i++) 
    { 
        for (int j = min(i, k); j > 0; j--) 
            C[j] = intal_add(C[j],C[j-1]);
    } 
    return C[k]; 
	
}

char* coin_row_problem(char **arr, int n)
{
	
	char** DP=(char**) malloc((n+1) * sizeof(char*));
	for(int i = 0; i < n; i++) {
		DP[i] = (char*) malloc(1001 * sizeof(char));
	}
	if(n==0){
		return "0";
	}
	if(n==1){
		return arr[0];
	}
	
	strcpy(DP[0],"0");
	strcpy(DP[1],arr[0]);
	int compare = intal_compare(arr[0],arr[1]);
	if(compare==1){

		DP[2]=arr[0];
	}
	else{
		DP[2]=arr[1];
	}
	
	
	
	char* alternate= (char*) malloc(1001 * sizeof(char));
	char* last=(char*) malloc(1001 * sizeof(char));
	for(int i=3;i<=n;i++){
		alternate = intal_add(DP[i],DP[i-2]);
		strcpy(last,DP[i-1]);
		compare = intal_compare(alternate,last);
		if(compare==1){
			strcpy(DP[i],alternate);
		}
		else{
			strcpy(DP[i],last);
		}
	}
	return DP[n];
	
	
}




