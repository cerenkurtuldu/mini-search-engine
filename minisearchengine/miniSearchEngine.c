#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void search (char A[500][25], int b,  char *S, int count);

int main()
{
    FILE* ignore;
    FILE* text;
    int i=0,j=0,k=0,counter,a,b,count1=0,count2=0;
    char temp[20],line[100];
    char IGNORE[213][20];
    char delim[]= " ";
    char *fileDelim;
    char TEXT[500][25];
    FILE* word;
    char alp[500][25];
    char tempVar[20];
    char str[20];
    
    ignore = fopen ( "ignoreList.txt", "r" );
    
    a=0;
        while(b != EOF){ 
            b = fscanf(ignore,"%s",temp); 
            strcpy(IGNORE[a],temp);
            a++;
        }
        fclose(ignore);
  
    printf ("enter a file name: ");
    scanf ("%s", &temp);
    text = fopen (temp, "r");
    if (NULL== text){
    	printf ("file cant be opened \n");
	}
	
   while(fgets(line,sizeof(line),text)){
        fileDelim = strlwr(strtok(line, delim));
        while(fileDelim != NULL){
            a=0;
            for(i=0;i<213;i++){
                
                if(strcmp(fileDelim,IGNORE[i])==0|| strcmp(fileDelim, ".")==0 || strcmp(fileDelim, ",")==0 || strcmp(fileDelim, " ")==0 ){
                    a++;    
                }
                if(a>0) break;
            }     
                if(a==0){
                    strcpy(TEXT[j], fileDelim);
                    j++;
                    count1++;            
                }
            
            fileDelim = strtok (NULL, delim);
        }
    }
    fclose(text);
   
    
    i=0,j=1,counter=1;
    int FREQ[200];
    
    word= fopen("word.txt", "w");
    
       for(i=0;i<count1;i++)
    {    counter=1;
        for(j=i+1;j<count1;j++)
        {    
            if (strcmp(TEXT[i],TEXT[j])==0)
            { 
                counter++;
            }    
        }
        
        a=0;
        for(k=0;k<i;k++)
        {    if (strcmp(TEXT[i],TEXT[k])==0 || strcmp(TEXT[k],"\0")==0 || strcmp(TEXT[k]," ")==0)
            {    a++;
            }
        }
        if(a==0){
            if(strcmp(TEXT[i], "") !=0){
            	 fprintf(word,"%s,%d\n",TEXT[i],counter); 
            	 printf ("%s,%d\n",TEXT[i],counter);
			}  
			            
        }       
    } 
    
    fclose(word);
       
         
      for(i = 0; i <count1; i++){
        a=0;
        for(j=0;j<i;j++)
        {    if (strcmp(TEXT[j],TEXT[i])==0 || strcmp(TEXT[j],"")==0)
            {    a++;
            }
        }
        if(a==0)
        {    if(TEXT[i]!= NULL){
            strcpy (alp[i],TEXT[i]);
            count2++;
            } 
           }
    }
    
	
    for(i = 0; i < count1; i++){
		for(j = i+1; j < count1; j++){
			if(strcmp(alp[i], alp[j]) > 0){
				strcpy(tempVar, alp[i]);
				strcpy(alp[i], alp[j]);
				strcpy(alp[j], tempVar);
			}
		}
	}

      
    while(1==1){
        printf ("(Enter 0 to end) Enter a search string: ");
        scanf ("%s",&str);
        if(strcmp(str,"0")==0 ) break;
         search(alp,0,str,count2);
    }
  
    printf("--End--"); 
      
}

void search(char A[500][25],int b,char *S,int count)
{    
    
    if(strcmp(A[b],S)==0)
    {    printf("%s is in the list\n", S);
        return b;
    }
    if(b== count)
    {    printf("%s is not in the list\n",S);
        return (-1);    
    }
    else 
    {    search(A,b+1,S,count);
    }
}

