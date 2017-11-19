#include <stdio.h>

#include<string.h>
#include<math.h>


int Hash( char* String, int Size )
{
    int i = 0;
    int HashValue = 0;

    for ( i=0; i<Size; i++ )
    {
        HashValue = String[i] + ( HashValue * 2 );
    }

    return HashValue;
}

int ReHash( char* String, int Start, int Size, int HashPrev, int Coefficient )
{
    if ( Start == 0 )
        return HashPrev;
    
    return String[ Start + Size - 1] + 
           ( (HashPrev - Coefficient * String [Start-1] ) * 2 );
}
int KarpRabin(char* Text,  char* Pattern )
{
    int i = 0;
    int j = 0;

	int Start=0;
	int PatternSize=strlen(Pattern);
	int TextSize=strlen(Text);
    int Coefficient = pow( 2.0, PatternSize - 1 );

    int HashText    = Hash( Text,    PatternSize );
    int HashPattern = Hash( Pattern, PatternSize );

    for ( i=Start; i<=TextSize - PatternSize; i++ )
    {
        HashText = ReHash( Text, i, PatternSize , HashText, Coefficient);
        
        if ( HashPattern == HashText )
        {
            for ( j=0; j<PatternSize; j++ )
            {
                if ( Text[i+j] != Pattern[j] )
                    break;
            }

            if ( j >= PatternSize )
                return i;
        }
    }

    return -1;
}



void main()
{
	char text[100]="VISION QUESTION ONION CAPTION GRADUATION EDUCATION";
	char pattern[50]="ATION";
	//char text[100]="aaabfdsfjv hgfk jfhdgsa    hhgggkfiutyr  aaab oig baaab";
	//char pattern[50]="aaab";

	int M, N, pos, previous=0, i=0;
	
	M=strlen(pattern);
	N=strlen(text);

	while(1){
		pos=KarpRabin(text+i, pattern);
		pos+=previous;
		i=pos+M;
		if(i<=N)
				printf("패턴이 발생한 위치:%d\n", pos);
		
		else break;


		previous=i;
	}
	printf("탐색 종료\n");

	
}
	
	