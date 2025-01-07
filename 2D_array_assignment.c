#include<stdio.h>
#include<string.h>
#define MAX_NAME_LENGTH 50
#define MAX_ROWS 10
#define MAX_COLS 101

int start_with_vowel(char *matrix)
{
    char first=matrix[0];
    return (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u' || first == 'A' || first == 'E' || first == 'I' || first == 'O' || first == 'U');
}

int main()
{
    int rows,cols;
    int vowel_count=0;
    char longest_name[MAX_NAME_LENGTH];
    printf("Enter number of rows:");
    scanf("%d",&rows);

     if (rows < 1 || rows > MAX_ROWS) {
        printf("Invalid number of rows.\n");
        return 0;
    }

    printf("Enter number of columns:");
    scanf("%d",&cols);

    if (cols < 1 || cols > MAX_COLS) {
        printf("Invalid number of columns.\n");
        return 0;
    }

    char matrix[rows][cols][MAX_NAME_LENGTH];
    printf("Enter the name:\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("Name at(%d,%d):",i,j);
            scanf("%s",matrix[i][j]);
            if(start_with_vowel(matrix[i][j]))
            {
                vowel_count++;
            }
            if(strlen(matrix[i][j])>strlen(longest_name))
            {
                strcpy(longest_name,matrix[i][j]);
            }
        }
    }

    printf("\nThe 2D array of names is:\n");
     for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%s ",matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nNumber of names starting wuth a vowel:%d\n",vowel_count);
    printf("\nThe longest name:%s\n",longest_name);
    return 0;
}