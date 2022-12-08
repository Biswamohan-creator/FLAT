#include<stdio.h>
int main() 
{
    char t_table[100][100];
    char c_sym, c_state;
    int i, j, n_sym, n_state;
    printf("Enter the no. of symbols in alphabet set: ");
    scanf("%d", &n_sym);
    printf("Enter the no. of states: ");
    scanf("%d", &n_state);
    printf("Enter transition table: ");
    scanf("\n");
    for(i=0; i<n_state+1;i++)
    {
        for(j=0; j<n_sym+2;j++)
            scanf("%c", &t_table[i][j]);
    }
    for(i=0; i<n_state+1;i++)
    {
        for(j=0; j<n_sym+2;j++)
            printf("%c ", t_table[i][j]);
        printf("\n");
    }
    printf("Enter string: ");
    scanf("\n");
    c_state = t_table[1][0];
    while((c_sym=getchar())!='\n')
    {
        printf("On %c state applying symbol %c", c_state, c_sym);
        i=1;
        while(c_state!=t_table[i][0])
            i++;
        j=1;
        while(c_sym!=t_table[0][j])
            j++;
        c_state=t_table[i][j];
        printf("goes to %c\n", c_state);
    }
    i=1;
    while(c_state!=t_table[i][0])
        i++;
    if(t_table[i][n_sym+1]=='F')
        printf("\nAccepted\n");
    else
        printf("\nNot accepted\n");
    return 0;
}
