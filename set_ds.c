//?. Bit vector representation of set
//?. Union, Insertion, Complement, Set Difference
//Universal set char[26] to store letters 'a' -> 'z'
//char set1[26], char set2[26], take input from user.
//set1 = [a,b,c], set2 = [c,d,e]

//func bitVector(set1) => set1_bit if set1[i] present in U then 1 else, otherwise
//if(set[i] == u[i] => set1_bit = 1;

//functions for set ops(menu driven ofcourse);
//UNION -> union(set1_bit,set2_bit) : for(condtn) => set1_bit | set2_bit;
//COMPLEMENT -> Flip bits
//DIFFERENCE -> (set1_bit) & (set2_bit complement)

#include <stdio.h>
#include <ctype.h>

int main()
{
	char Universal_set[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char set1[26], set2[26];
	int set1_size, set2_size;
	printf("Enter size of Set 1");
	scanf("%d",&set1_size);
	printf("Enter elements for Set 1");
	for(int i = 0; i < set1_size; i++)
	{		
		scanf(" %c",set1[i]);
		set1[i] = tolower(set1[i]);
	}
	set1[set1_size] = '\0';
	printf("Enter size of Set 2");
	scanf("%d",&set1_size);
	printf("Enter elements for Set 2");
	for(int i = 0; i < set2_size; i++)
	{		
		scanf(" %c",set2[i]);
		set2[i] = tolower(set2[i]);
	} 
	set2[set1_size] = '\0';
	
	return(0);
}
