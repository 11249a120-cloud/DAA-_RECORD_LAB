#include <stdio.h> 
#define MAXN 15 

// Used to initialize minCost to a very large value. 
// Since all travel costs are non-negative, any valid cost 
// will be less than INF and replace it. 
#define INF 999999 

int n; 
int d[MAXN][MAXN]; 
// Bitwise AND checks whether that city's bit is set in S. 
// S will have 2n possible combinations of cities, so the size of it should be 2^MAXN that 1<< MAXN 
int dp[MAXN][1 << MAXN]; 

// g(i,S) 
// Returns the minimum cost of visiting all cities in set S starting from city i 
int g(int i, int S) 
{ 
    // Base case: If S is empty, return the cost to return to the starting city (A) 
    if (S == 0) 
        return d[i][0]; //g(i,{}) = d[i][0] - Cost to return to starting city A from city i 

    //If the g(i,S) has already been computed, return the stored value 
    if (dp[i][S] != -1)  
        return dp[i][S];       

    int S = 0; 
    for (int i = 1; i < n; i++) 
        S |= (1 << i); 

    int result = g(0, S); 

    printf("Given Cost Matrix\n"); 
    for (int i = 0; i < n; i++) 
    { 
        printf("|"); 
        for (int j = 0; j < n; j++) 
            printf(" %d ", d[i][j]); 
        printf("|\n"); 
    } 
    printf("Minimum travelling cost: %d\n", result); 

    return 0; 
}
int S = 0; 
for (int i = 1; i < n; i++) 
    S |= (1 << i); 

int result = g(0, S); 

printf("Given Cost Matrix\n"); 
for (int i = 0; i < n; i++) 
{ 
    printf("|"); 
    for (int j = 0; j < n; j++) 
        printf(" %d ", d[i][j]); 
    printf("|\n"); 
} 

printf("Minimum travelling cost: %d\n", result); 

return 0; 
}
